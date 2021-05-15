// MiReAcquireOutSwappedProcessCommit 
 
int __fastcall MiReAcquireOutSwappedProcessCommit(int a1)
{
  int v2; // r5
  int v3; // r10
  int v4; // r4
  int v5; // r0
  int v6; // r7
  int v7; // r4
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  int v11; // r2
  int v13; // r4
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  _DWORD *v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r1
  char v20[16]; // [sp+4h] [bp-38h] BYREF
  int v21; // [sp+14h] [bp-28h]

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) )
    sub_516610();
  KiStackAttachProcess(a1, 1, v20);
  v2 = a1 + 492;
  v3 = __mrc(15, 0, 13, 0, 3);
  if ( (*(_DWORD *)(a1 + 192) & 8) != 0 )
  {
    v4 = 1;
  }
  else
  {
    v4 = 0;
    if ( MiChargeCommit(MiSystemPartition, *(_DWORD *)(a1 + 608), 1) )
    {
      MiLogOutswappedProcessCommitReacquire(a1, *(_DWORD *)(a1 + 608), 0, 0);
      v5 = *(_DWORD *)(a1 + 616);
      *(_DWORD *)(a1 + 608) = 0;
      ExFreePoolWithTag(v5, 0);
      *(_DWORD *)(a1 + 616) = 0;
      v6 = 0;
      goto LABEL_6;
    }
  }
  MiLogOutswappedProcessCommitReacquire(a1, *(_DWORD *)(a1 + 608), 1, v4);
  v13 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 492);
  }
  else
  {
    v14 = (unsigned __int8 *)(a1 + 495);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 | 0x80, v14) );
    __dmb(0xBu);
    if ( v15 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a1 + 492);
    while ( 1 )
    {
      v16 = *(_DWORD *)v2;
      if ( (*(_DWORD *)v2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v16 & 0x40000000) == 0 )
      {
        do
          v18 = __ldrex((unsigned int *)v2);
        while ( v18 == v16 && __strex(v16 | 0x40000000, (unsigned int *)v2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  *(_BYTE *)(a1 + 607) |= 0xC0u;
  MiUnlockWorkingSetExclusive(a1 + 492, v13);
  MiBeginProcessClean(v3 & 0xFFFFFFC0, a1);
  KeFreezeProcess(a1, 0);
  v17 = *(_DWORD **)(a1 + 616);
  ObfReferenceObjectWithTag(a1, 1953261124);
  *v17 = 0;
  v17[1] = 0;
  v17[2] = 0;
  v17[3] = 0;
  v17[2] = MiReAcquireCommitFailWorker;
  v17[3] = a1;
  *v17 = 0;
  ExQueueWorkItem(v17, 0);
  v6 = -1073741523;
LABEL_6:
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
  }
  else
  {
    v8 = (unsigned __int8 *)(v2 + 3);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v2);
    while ( 1 )
    {
      v10 = *(_DWORD *)v2;
      if ( (*(_DWORD *)v2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v19 = __ldrex((unsigned int *)v2);
        while ( v19 == v10 && __strex(v10 | 0x40000000, (unsigned int *)v2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v11 = *(unsigned __int8 *)(v2 + 115);
  if ( (v11 & 0xFFFFFFC0) == 128 )
    *(_BYTE *)(v2 + 115) = v11 & 0x3F | 0x40;
  MiUnlockWorkingSetExclusive(v2, v7);
  v21 = 0;
  KiUnstackDetachProcess(v20, 1);
  return v6;
}
