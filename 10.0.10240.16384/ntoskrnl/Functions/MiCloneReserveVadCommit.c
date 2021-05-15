// MiCloneReserveVadCommit 
 
int __fastcall MiCloneReserveVadCommit(int a1, int a2)
{
  unsigned int *v2; // r4
  unsigned int v3; // r6
  int v4; // r8
  int v5; // r7
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r6
  int v11; // r9
  int v12; // r6
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r1
  int v18; // [sp+8h] [bp-50h]
  int v19; // [sp+Ch] [bp-4Ch]
  int v20; // [sp+10h] [bp-48h]
  int v23; // [sp+1Ch] [bp-3Ch] BYREF
  char v24[56]; // [sp+20h] [bp-38h] BYREF

  v19 = 0;
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_DWORD *)(v20 + 116);
  v2 = (unsigned int *)(v18 + 492);
  v3 = 4 * ((*(_DWORD *)(a1 + 12) & 0xFFFFF) - 0x10000000);
  v4 = (*(_DWORD *)(a1 + 16) & 0xFFFFF) - 0x10000000;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
  }
  else
  {
    v6 = (unsigned __int8 *)(v18 + 495);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v2);
    while ( 1 )
    {
      v8 = *v2;
      if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v8 & 0x40000000) == 0 )
      {
        do
          v9 = __ldrex(v2);
        while ( v9 == v8 && __strex(v8 | 0x40000000, v2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v3 <= 4 * v4 )
  {
    v10 = MiGetNextPageTable(v3, 4 * v4, 0, v5, 1, &v23);
    if ( !v10 )
      break;
    MiUnlockWorkingSetExclusive((int)v2, v5);
    v11 = ((v10 >> 10) & 0x3FFFFC) - 0x40000000;
    KiStackAttachProcess(a2, 0, (int)v24);
    LOCK_PAGE_TABLE_COMMITMENT(v20, v18);
    v12 = MiCommitPageTablesForVad(a1, v10 << 10, v10 << 10);
    v19 = v12;
    UNLOCK_PAGE_TABLE_COMMITMENT(v20, v18);
    KiUnstackDetachProcess((unsigned int)v24, 0);
    if ( v12 < 0 )
      return v12;
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
    }
    else
    {
      v14 = (unsigned __int8 *)(v18 + 495);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      __dmb(0xBu);
      if ( v15 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v2);
      while ( 1 )
      {
        v16 = *v2;
        if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v16 & 0x40000000) == 0 )
        {
          do
            v17 = __ldrex(v2);
          while ( v17 == v16 && __strex(v16 | 0x40000000, v2) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v3 = (v11 + 4) << 10;
  }
  MiUnlockWorkingSetExclusive((int)v2, v5);
  return v19;
}
