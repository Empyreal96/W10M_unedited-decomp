// MiConvertAndFlushWsleVas 
 
int __fastcall MiConvertAndFlushWsleVas(unsigned int *a1, unsigned int *a2)
{
  unsigned int v4; // r7
  int v5; // r2
  int v6; // r3
  unsigned int v7; // r8
  unsigned int *v8; // r6
  unsigned int *v9; // r9
  unsigned int v10; // r10
  unsigned int v11; // t1
  int v12; // r0
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r1
  int v18; // [sp+0h] [bp-28h]
  int v19; // [sp+4h] [bp-24h]

  v4 = 0;
  v19 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
  }
  else
  {
    v14 = (unsigned __int8 *)a1 + 3;
    do
    {
      v15 = __ldrex(v14);
      v5 = __strex(v15 | 0x80, v14);
    }
    while ( v5 );
    __dmb(0xBu);
    if ( v15 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a1);
    while ( 1 )
    {
      v16 = *a1;
      if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v16 & 0x40000000) == 0 )
      {
        v5 = v16 | 0x40000000;
        do
          v17 = __ldrex(a1);
        while ( v17 == v16 && __strex(v5, a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v6 = *a2;
  v7 = 0;
  if ( *a2 )
  {
    v8 = a2;
    v9 = a2;
    do
    {
      v11 = v9[1];
      ++v9;
      v10 = v11;
      if ( MiIsAddressValid(v11, 0, v5, v6) )
      {
        v18 = MmPfnDatabase + 24 * (*(_DWORD *)(((v10 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
        v12 = MiTryLocateWsle(v10, (int)a1, *(_DWORD *)v18);
        if ( v12 != 0xFFFFF && *(int *)(v18 + 4) < 0 )
        {
          v8[1] = v12;
          ++v4;
          ++v8;
        }
      }
      v6 = *a2;
      ++v7;
    }
    while ( v7 < *a2 );
    if ( v4 )
    {
      *a2 = v4;
      MiFreeWsleList((int)a1, a2, 0);
    }
  }
  return MiUnlockWorkingSetExclusive((int)a1, v19);
}
