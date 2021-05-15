// ExProtectPool 
 
int __fastcall ExProtectPool(unsigned int a1, int a2, int a3)
{
  int v7; // r4
  unsigned int v8; // r3
  int v9; // r5
  unsigned int *v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // t1
  int v14; // r3
  __int64 v15; // kr00_8
  unsigned int v16; // r1
  unsigned int v17; // r2
  int v18; // [sp+0h] [bp-28h]
  int v19; // [sp+4h] [bp-24h]

  if ( MmIsSpecialPoolAddress(a1, a2) )
    return sub_5493CC();
  if ( (a1 & 0xFFF) != 0 || (MmDeterminePoolType(a1) & 0x20) != 0 )
    JUMPOUT(0x5494D4);
  v19 = 0;
  v18 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    JUMPOUT(0x5493E2);
  v7 = ExpLargePoolTableLock & 0x7FFFFFFF;
  do
    v8 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
  while ( v8 == v7 && __strex(v7 + 1, (unsigned int *)&ExpLargePoolTableLock) );
  __dmb(0xBu);
  if ( v8 != v7 )
    JUMPOUT(0x5493F4);
  v9 = (PoolBigPageTableSize - 1) & ((int)(162172
                                         * ((a1 >> 12 >> 16) ^ (4
                                                              * ((unsigned __int8)(a1 >> 20) ^ (4
                                                                                              * (unsigned __int8)(a1 >> 12)))))) >> 2);
  if ( !PoolBigPageTable )
    JUMPOUT(0x549406);
  v10 = (unsigned int *)(PoolBigPageTable + 16 * v9);
  v11 = PoolBigPageTable + 16 * PoolBigPageTableSize;
  while ( 1 )
  {
    v13 = *v10;
    v10 += 4;
    v12 = v13;
    if ( (v13 & 1) == 0 && a1 >= v12 )
    {
      v14 = *(v10 - 1);
      if ( a1 + a2 - 1 < v14 + v12 )
        break;
    }
    if ( (unsigned int)v10 >= v11 )
    {
      if ( v19 == 1 )
        JUMPOUT(0x549486);
      v10 = (unsigned int *)PoolBigPageTable;
      v19 = 1;
      v11 = PoolBigPageTable + 16 * v9;
    }
  }
  if ( (v14 & 0xFFF) != 0 )
    JUMPOUT(0x549442);
  v15 = *((_QWORD *)v10 - 1);
  if ( (dword_682604 & 0x10000) != 0 )
    JUMPOUT(0x54945C);
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
  while ( __strex(v16 & 0xBFFFFFFF, (unsigned int *)&ExpLargePoolTableLock) );
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
  while ( __strex(v17 - 1, (unsigned int *)&ExpLargePoolTableLock) );
  KfLowerIrql(v18);
  if ( a3 == -1 )
    JUMPOUT(0x549468);
  if ( (v15 & 0xFFF00000000i64) != 0 )
    JUMPOUT(0x549478);
  return MiProtectPool(a1, a2, a3);
}
