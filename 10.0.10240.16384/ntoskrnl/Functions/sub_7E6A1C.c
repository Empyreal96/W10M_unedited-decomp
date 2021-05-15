// sub_7E6A1C 
 
int sub_7E6A1C()
{
  int v0; // r3
  int v1; // r5
  unsigned int v2; // r3
  int v3; // r9
  int v4; // r10
  int v5; // r8
  int v6; // r9
  int v7; // r5
  int v8; // r6
  unsigned int v9; // r2
  _DWORD *v10; // r2
  __int64 v11; // kr00_8
  _DWORD *v12; // r6
  unsigned __int8 v13; // r5
  unsigned int v14; // r1
  int v15; // r8
  int v16; // r5
  int v17; // r8
  unsigned int v18; // r2
  int v19; // r5
  int v20; // r8
  unsigned int v21; // r2
  int v22; // r1
  unsigned __int8 v23; // r5
  unsigned int v24; // r1
  int v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // r0
  char v29[4]; // [sp+8h] [bp-38h] BYREF
  int v30; // [sp+Ch] [bp-34h]
  int v31; // [sp+10h] [bp-30h]
  int v32; // [sp+14h] [bp-2Ch]
  int v33; // [sp+18h] [bp-28h]
  int (__fastcall *v34)(unsigned int); // [sp+3Ch] [bp-4h]

  v7 = KeAbPreAcquire((unsigned int)CmpDelayDerefKCBLock, 0, 0);
  v8 = KfRaiseIrql(1);
  do
    v9 = __ldrex(CmpDelayDerefKCBLock);
  while ( __strex(v9 & 0xFE, CmpDelayDerefKCBLock) );
  __dmb(0xBu);
  if ( (v9 & 1) == 0 )
    ExpAcquireFastMutexContended((int)CmpDelayDerefKCBLock, v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  dword_632324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_63233C = v8;
  while ( 1 )
  {
    v10 = (_DWORD *)CmpDelayDerefKCBListHead;
    if ( (int *)CmpDelayDerefKCBListHead == &CmpDelayDerefKCBListHead )
      break;
    v11 = *(_QWORD *)CmpDelayDerefKCBListHead;
    if ( *(int **)(CmpDelayDerefKCBListHead + 4) != &CmpDelayDerefKCBListHead
      || *(_DWORD *)(v11 + 4) != CmpDelayDerefKCBListHead )
    {
      __fastfail(3u);
    }
    v12 = (_DWORD *)(CmpDelayDerefKCBListHead - 116);
    CmpDelayDerefKCBListHead = *(_DWORD *)CmpDelayDerefKCBListHead;
    *(_DWORD *)(v11 + 4) = &CmpDelayDerefKCBListHead;
    *v10 = v10;
    v10[1] = v10;
    __dmb(0xFu);
    *(v10 - 27) &= 0xFFFFFFFE;
    dword_632324 = 0;
    v13 = dword_63233C;
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)CmpDelayDerefKCBLock);
    while ( !v14 && __strex(1u, (unsigned int *)CmpDelayDerefKCBLock) );
    if ( v14 )
      ExpReleaseFastMutexContended((unsigned int *)CmpDelayDerefKCBLock, v14);
    KfLowerIrql(v13);
    KeAbPostRelease((unsigned int)CmpDelayDerefKCBLock);
    v0 = v12[1];
    v1 = v12[5];
    v32 = 0;
    if ( (v0 & 0x20000) == 0 && *(_BYTE *)(v1 + 2532) == 1 )
      v32 = 1;
    v2 = (v12[3] ^ (v12[3] >> 9)) * v6;
    v3 = v2 ^ (v2 >> 9);
    v4 = *(_DWORD *)(v1 + 1848) - 1;
    if ( v5 )
    {
      CmpDereferenceKeyControlBlockWithLock((int)v12, v5);
    }
    else
    {
      v15 = 0;
      v29[0] = 0;
      if ( !v30 )
        goto LABEL_56;
      if ( !CmpIsLockAllowedByIndex(v30, v31, v1, v3 & v4, v29) )
      {
        v19 = KeAbPreAcquire((unsigned int)CmpDelayDerefKCBLock, 0, 0);
        v20 = KfRaiseIrql(1);
        do
          v21 = __ldrex(CmpDelayDerefKCBLock);
        while ( __strex(v21 & 0xFE, CmpDelayDerefKCBLock) );
        __dmb(0xBu);
        if ( (v21 & 1) == 0 )
          ExpAcquireFastMutexContended((int)CmpDelayDerefKCBLock, v19);
        if ( v19 )
          *(_BYTE *)(v19 + 14) |= 1u;
        dword_632324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        dword_63233C = v20;
        v12[2] |= 1u;
        v22 = CmpDelayDerefKCBListHead;
        v12[29] = CmpDelayDerefKCBListHead;
        v12[30] = &CmpDelayDerefKCBListHead;
        if ( *(int **)(v22 + 4) != &CmpDelayDerefKCBListHead )
          __fastfail(3u);
        *(_DWORD *)(v22 + 4) = v12 + 29;
        dword_632324 = 0;
        v23 = dword_63233C;
        CmpDelayDerefKCBListHead = (int)(v12 + 29);
        __dmb(0xBu);
        do
          v24 = __ldrex((unsigned int *)CmpDelayDerefKCBLock);
        while ( !v24 && __strex(1u, (unsigned int *)CmpDelayDerefKCBLock) );
        if ( v24 )
          ExpReleaseFastMutexContended((unsigned int *)CmpDelayDerefKCBLock, v24);
        v25 = v23;
        goto LABEL_49;
      }
      v15 = (unsigned __int8)v29[0];
      if ( !v29[0] )
LABEL_56:
        CmpLockHashEntryByIndexExclusive(v1, v3 & v4);
      CmpLockKcbExclusive(v12);
      CmpDereferenceKeyControlBlockWithLock((int)v12, 0);
      CmpUnlockKcb(v12);
      if ( !v15 )
        CmpUnlockHashEntryByIndex(v1, v3 & v4);
    }
    if ( v32 == 1 )
      CmpDoQueueLateUnloadWorker(v1);
    v16 = KeAbPreAcquire((unsigned int)CmpDelayDerefKCBLock, 0, 0);
    v17 = KfRaiseIrql(1);
    do
      v18 = __ldrex(CmpDelayDerefKCBLock);
    while ( __strex(v18 & 0xFE, CmpDelayDerefKCBLock) );
    __dmb(0xBu);
    if ( (v18 & 1) == 0 )
      ExpAcquireFastMutexContended((int)CmpDelayDerefKCBLock, v16);
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    dword_632324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = 101027;
    dword_63233C = v17;
    LOBYTE(v8) = v17;
    v5 = v33;
  }
  dword_632324 = 0;
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)CmpDelayDerefKCBLock);
  while ( !v26 && __strex(1u, (unsigned int *)CmpDelayDerefKCBLock) );
  if ( v26 )
    ExpReleaseFastMutexContended((unsigned int *)CmpDelayDerefKCBLock, v26);
  v25 = (unsigned __int8)v8;
LABEL_49:
  KfLowerIrql(v25);
  v27 = KeAbPostRelease((unsigned int)CmpDelayDerefKCBLock);
  return v34(v27);
}
