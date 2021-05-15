// CmpLazyCommitWorker 
 
int CmpLazyCommitWorker()
{
  int v0; // r9
  int v1; // r3
  unsigned int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r1
  int result; // r0
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // r2
  unsigned int v11; // r10
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  int *v15; // r5
  __int64 v16; // r2
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int **v21; // r1
  unsigned int v22; // r1
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v26; // r2
  unsigned int v27; // r9
  int v28; // r0
  int v29; // r5
  unsigned int v30; // r2
  int *v31; // r1
  __int64 v32; // kr00_8
  int **v33; // r2
  unsigned int v34; // r1
  int v35; // r0
  unsigned int v36; // r1
  __int16 v37; // r3
  int v38; // r1
  unsigned int v39; // r0
  unsigned int v40; // r2
  unsigned int v41; // r1
  __int16 v42; // r3
  unsigned int v43; // r4
  unsigned int v44; // r1
  unsigned int v45; // r1
  __int16 v46; // r3
  int v47; // [sp+10h] [bp-30h] BYREF
  int *v48; // [sp+18h] [bp-28h] BYREF
  int **v49; // [sp+1Ch] [bp-24h]

  v47 = 0;
  v49 = &v48;
  v48 = (int *)&v48;
  v0 = 1;
  v1 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v1 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v2 = CmpShutdownRundown & 0xFFFFFFFE;
  v3 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v4 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v4 == v2 && __strex(v3, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v4 == v2 || (result = ExfAcquireRundownProtection(&CmpShutdownRundown)) != 0 )
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = KeAbPreAcquire((unsigned int)&CmpShutdownLock, 0, 0);
    v8 = v7;
    do
      v9 = __ldrex((unsigned int *)&CmpShutdownLock);
    while ( !v9 && __strex(0x11u, (unsigned int *)&CmpShutdownLock) );
    __dmb(0xBu);
    if ( v9 )
      ExfAcquirePushLockSharedEx(&CmpShutdownLock, v7, (unsigned int)&CmpShutdownLock);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    LOCK_HIVE_LOAD();
    while ( 1 )
    {
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v10 + 308);
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v12 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
      v13 = v12;
      do
        v14 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
      while ( __strex(v14 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
      __dmb(0xBu);
      if ( (v14 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v12);
      if ( v13 )
        *(_BYTE *)(v13 + 14) |= 1u;
      v15 = (int *)CmpLazyCommitListHead;
      dword_632184 = v11;
      v16 = *(_QWORD *)CmpLazyCommitListHead;
      if ( *(int **)(CmpLazyCommitListHead + 4) != &CmpLazyCommitListHead
        || *(_DWORD *)(v16 + 4) != CmpLazyCommitListHead )
      {
        __fastfail(3u);
      }
      CmpLazyCommitListHead = *(_DWORD *)CmpLazyCommitListHead;
      *(_DWORD *)(v16 + 4) = &CmpLazyCommitListHead;
      if ( v15 == &CmpLazyCommitListHead )
        break;
      dword_632184 = 0;
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)&CmpTransactionListLock);
      while ( !v17 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
      if ( v17 )
        ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v17);
      v18 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v20 = *(_WORD *)(v19 + 0x134) + 1;
      *(_WORD *)(v19 + 308) = v20;
      if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
        KiCheckForKernelApcDelivery(v18);
      if ( CmpTransMgrCommit(v15[3], v15 - 4, &v47) < 0 )
      {
        v21 = v49;
        *v15 = (int)&v48;
        v15[1] = (int)v21;
        if ( *v21 != (int *)&v48 )
          __fastfail(3u);
        *v21 = v15;
        v49 = (int **)v15;
        v0 = 0;
      }
      else
      {
        CmpCleanupTransactionState(v15[3], v15 - 4, 4, 0);
      }
    }
    CmpLazyCommitWorkItemActive = v0 == 0;
    dword_632184 = 0;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)&CmpTransactionListLock);
    while ( !v22 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
    if ( v22 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v22);
    v23 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
    if ( !v0 )
    {
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v26 + 308);
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v28 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
      v29 = v28;
      do
        v30 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
      while ( __strex(v30 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
      __dmb(0xBu);
      if ( (v30 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v28);
      if ( v29 )
        *(_BYTE *)(v29 + 14) |= 1u;
      dword_632184 = v27;
      while ( 1 )
      {
        v31 = v48;
        v32 = *(_QWORD *)v48;
        if ( (int **)v48[1] != &v48 || *(int **)(v32 + 4) != v48 )
          __fastfail(3u);
        v48 = (int *)*v48;
        *(_DWORD *)(v32 + 4) = &v48;
        if ( v31 == (int *)&v48 )
          break;
        v33 = (int **)dword_6321C4;
        *v31 = (int)&CmpLazyCommitListHead;
        v31[1] = (int)v33;
        if ( *v33 != &CmpLazyCommitListHead )
          __fastfail(3u);
        *v33 = v31;
        dword_6321C4 = (int)v31;
      }
      dword_632184 = 0;
      __dmb(0xBu);
      do
        v34 = __ldrex((unsigned int *)&CmpTransactionListLock);
      while ( !v34 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
      if ( v34 )
        ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v34);
      v35 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
      v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v37 = *(_WORD *)(v36 + 0x134) + 1;
      *(_WORD *)(v36 + 308) = v37;
      if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
        KiCheckForKernelApcDelivery(v35);
      KiSetTimerEx((int)&CmpLazyCommitTimer, 0, -300000000i64, 0, 0, (int)&CmpLazyCommitDpc);
    }
    UNLOCK_HIVE_LOAD();
    __pld(&CmpShutdownLock);
    v38 = CmpShutdownLock;
    v39 = CmpShutdownLock - 16;
    if ( (CmpShutdownLock & 0xFFFFFFF0) <= 0x10 )
      v39 = 0;
    if ( (CmpShutdownLock & 2) != 0 )
      goto LABEL_78;
    __dmb(0xBu);
    do
      v40 = __ldrex((unsigned int *)&CmpShutdownLock);
    while ( v40 == v38 && __strex(v39, (unsigned int *)&CmpShutdownLock) );
    if ( v40 != v38 )
LABEL_78:
      ExfReleasePushLock(&CmpShutdownLock, v38);
    result = KeAbPostRelease((unsigned int)&CmpShutdownLock);
    v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v42 = *(_WORD *)(v41 + 0x134) + 1;
    *(_WORD *)(v41 + 308) = v42;
    if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
      result = KiCheckForKernelApcDelivery(result);
    __pld(&CmpShutdownRundown);
    v43 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v44 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v44 == v43 && __strex(v43 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v44 != v43 )
      result = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  }
  v45 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v46 = *(_WORD *)(v45 + 0x134) + 1;
  *(_WORD *)(v45 + 308) = v46;
  if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
