// sub_804FC0 
 
int sub_804FC0()
{
  int v0; // r6
  int v2; // r4
  int v3; // r5
  unsigned int v4; // r6
  unsigned int *v5; // r7
  int v6; // r9
  unsigned int v7; // r10
  _DWORD *v8; // r5
  __int64 v9; // r2
  unsigned int v10; // r6
  unsigned int v11; // r1
  int v12; // r5
  int v13; // r8
  unsigned int v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  int (__fastcall *v17)(int); // [sp-4h] [bp-4h]

  ExpAcquireFastMutexContended((int)v5, v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5[7] = v4;
  while ( 1 )
  {
    v8 = (_DWORD *)CmpDelayDerefKCBListHead;
    if ( (int *)CmpDelayDerefKCBListHead == &CmpDelayDerefKCBListHead )
      break;
    if ( v7 >= CmpDelayDerefKCBLimit )
    {
      if ( (int *)CmpDelayDerefKCBListHead != &CmpDelayDerefKCBListHead )
      {
        v6 = 1;
        goto LABEL_24;
      }
      break;
    }
    v9 = *(_QWORD *)CmpDelayDerefKCBListHead;
    if ( *(int **)(CmpDelayDerefKCBListHead + 4) != &CmpDelayDerefKCBListHead
      || *(_DWORD *)(v9 + 4) != CmpDelayDerefKCBListHead )
    {
      __fastfail(3u);
    }
    CmpDelayDerefKCBListHead = *(_DWORD *)CmpDelayDerefKCBListHead;
    *(_DWORD *)(v9 + 4) = &CmpDelayDerefKCBListHead;
    *v8 = v8;
    v8[1] = v8;
    __dmb(0xFu);
    *(v8 - 27) &= 0xFFFFFFFE;
    v5[1] = 0;
    v10 = v5[7];
    __dmb(0xBu);
    do
      v11 = __ldrex(v5);
    while ( !v11 && __strex(1u, v5) );
    if ( v11 )
      ExpReleaseFastMutexContended(v5, v11);
    KfLowerIrql((unsigned __int8)v10);
    KeAbPostRelease((unsigned int)v5);
    v0 = 0;
    if ( (*(v8 - 28) & 0x20000) == 0 )
    {
      v2 = *(v8 - 24);
      if ( *(_BYTE *)(v2 + 2532) == 1 )
        v0 = 1;
    }
    CmpDereferenceKeyControlBlock(v8 - 29);
    if ( v0 == 1 )
      CmpDoQueueLateUnloadWorker(v2);
    ++v7;
    v12 = KeAbPreAcquire((unsigned int)v5, 0, 0);
    v13 = KfRaiseIrql(1);
    do
      v14 = __ldrex((unsigned __int8 *)v5);
    while ( __strex(v14 & 0xFE, (unsigned __int8 *)v5) );
    __dmb(0xBu);
    if ( (v14 & 1) == 0 )
      ExpAcquireFastMutexContended((int)v5, v12);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    v5[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5[7] = v13;
    LOBYTE(v4) = v13;
  }
  CmpDelayDerefKCBWorkItemActive = 0;
LABEL_24:
  v5[1] = 0;
  __dmb(0xBu);
  do
    v15 = __ldrex(v5);
  while ( !v15 && __strex(1u, v5) );
  if ( v15 )
    ExpReleaseFastMutexContended(v5, v15);
  KfLowerIrql((unsigned __int8)v4);
  KeAbPostRelease((unsigned int)v5);
  CmpUnlockRegistry();
  if ( v6 )
    v16 = CmpArmDelayDerefKCBWorker();
  return v17(v16);
}
