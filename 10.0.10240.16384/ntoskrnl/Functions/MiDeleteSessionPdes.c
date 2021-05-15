// MiDeleteSessionPdes 
 
unsigned int __fastcall MiDeleteSessionPdes(unsigned int a1, unsigned int a2)
{
  unsigned int v3; // r5
  unsigned int v4; // r9
  int v5; // r8
  int v6; // r3
  unsigned int *v7; // r4
  int v8; // r10
  unsigned int v9; // r1
  int v10; // r3
  unsigned int v11; // r4
  unsigned __int8 *v13; // r3
  unsigned int v14; // r0
  int v15; // [sp+8h] [bp-D0h] BYREF
  int v16[3]; // [sp+10h] [bp-C8h] BYREF
  int v17; // [sp+1Ch] [bp-BCh]
  int v18; // [sp+20h] [bp-B8h] BYREF
  char v19; // [sp+24h] [bp-B4h]
  char v20; // [sp+25h] [bp-B3h]
  int v21; // [sp+28h] [bp-B0h]
  int v22; // [sp+2Ch] [bp-ACh]
  int v23; // [sp+30h] [bp-A8h]
  int v24; // [sp+34h] [bp-A4h]

  v16[0] = 0;
  v16[1] = 0;
  v16[2] = 0;
  v17 = 0;
  v3 = a1;
  v4 = a1 << 10;
  v5 = 0;
  v6 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v15 = 0;
  v7 = (unsigned int *)(v6 + 3248);
  v22 = 0;
  v18 = 2;
  v19 = 0;
  v20 = 0;
  v23 = 0;
  v21 = 33;
  v24 = 0;
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
  }
  else
  {
    v13 = (unsigned __int8 *)v7 + 3;
    do
      v9 = __ldrex(v13);
    while ( __strex(v9 | 0x80, v13) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v7);
    while ( 1 )
    {
      v14 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v14 & 0x40000000) == 0 )
      {
        do
          v9 = __ldrex(v7);
        while ( v9 == v14 && __strex(v14 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v3 <= a2 )
  {
    do
    {
      MiDeleteValidSystemPte((_DWORD *)v3, v3 << 10, (int)v7, (int)&v18, &v15);
      v3 += 4;
    }
    while ( v3 <= a2 );
    v5 = v15;
  }
  MiFlushTbList((unsigned int)&v18, v9);
  MiUnlockWorkingSetExclusive((int)v7, v8);
  MiReplicatePteChange(v4, a2 << 10);
  MiFreeUnmappedPageTables(v5, v16);
  MiReturnResidentAvailable(v16[0]);
  v10 = v16[0];
  do
    v11 = __ldrex(&dword_634A2C[6]);
  while ( __strex(v11 + v10, &dword_634A2C[6]) );
  return MiReturnCommit((int)MiSystemPartition, v17);
}
