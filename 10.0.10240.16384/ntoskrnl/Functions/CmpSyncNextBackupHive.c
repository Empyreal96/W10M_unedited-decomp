// CmpSyncNextBackupHive 
 
int CmpSyncNextBackupHive()
{
  int v0; // r5
  int v1; // r6
  int v2; // r0
  int v3; // r3
  unsigned int v4; // r0
  unsigned int v5; // r2
  unsigned int v6; // r1
  unsigned int v7; // r1
  __int16 v8; // r3
  unsigned int v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r3
  int v13; // r0
  unsigned int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r0
  unsigned int v17; // r1
  int v18; // r0
  __int16 v19; // r3
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  unsigned int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v26; // r4
  unsigned int v27; // r1
  unsigned int v28; // r1
  __int16 v29; // r3
  unsigned int v31; // [sp+10h] [bp-28h]

  v0 = 0;
  v1 = 0;
  v2 = TryLockShutdownShared();
  if ( !v2 )
  {
    v0 = -2147483622;
    goto LABEL_58;
  }
  v3 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v3 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v4 = CmpShutdownRundown & 0xFFFFFFFE;
  v5 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v6 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v6 == v4 && __strex(v5, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v6 == v4 )
  {
    v1 = 1;
  }
  else
  {
    v1 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v1 )
    {
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v8 = *(_WORD *)(v7 + 0x134) + 1;
      *(_WORD *)(v7 + 308) = v8;
      if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
        KiCheckForKernelApcDelivery(0);
    }
  }
  if ( CmpDoIdleProcessing && v1 )
  {
    do
    {
      v9 = CmpPeriodicBackupFlushHiveCount;
      __dmb(0xBu);
      __dmb(0xBu);
      __dmb(0xBu);
      if ( v9 >= 5 )
        v31 = 0;
      else
        v31 = v9 + 1;
      __dmb(0xBu);
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&CmpPeriodicBackupFlushHiveCount);
      while ( v10 == v9 && __strex(v31, (unsigned int *)&CmpPeriodicBackupFlushHiveCount) );
      __dmb(0xBu);
      __dmb(0xBu);
    }
    while ( v10 != v9 );
    v11 = v31;
    __dmb(0xBu);
    if ( ((unsigned int)CmpMachineHiveList[24 * v11 + 4] & 1) == 0 )
    {
      v12 = v31;
      __dmb(0xBu);
      if ( CmpMachineHiveList[24 * v12 + 7] )
      {
        v13 = v31;
        __dmb(0xBu);
        CmpFlushBackupHive(v13);
      }
    }
    v14 = v31;
    __dmb(0xBu);
    if ( v14 == 5 )
    {
      v0 = -2147483622;
      if ( CmpConfigurationManagerKeyObject )
      {
        __dmb(0xBu);
        do
          v15 = __ldrex(&CmpBackupCount);
        while ( __strex(v15 + 1, &CmpBackupCount) );
        __dmb(0xBu);
        __pld(&CmpShutdownRundown);
        v16 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v17 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v17 == v16 && __strex(v16 - 2, (unsigned int *)&CmpShutdownRundown) );
        if ( v17 != v16 )
          ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v19 = *(_WORD *)(v18 + 0x134);
        *(_WORD *)(v18 + 308) = v19 + 1;
        if ( v19 == -1 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
          KiCheckForKernelApcDelivery(v18);
        v1 = 0;
        CmSetValueKey(
          (_DWORD *)CmpConfigurationManagerKeyObject,
          CmpBackupCountValueName,
          4,
          (int)&CmpBackupCount,
          4u,
          0,
          0);
      }
    }
    __pld(&CmpShutdownLock);
    v20 = CmpShutdownLock;
    v21 = CmpShutdownLock - 16;
    if ( (CmpShutdownLock & 0xFFFFFFF0) <= 0x10 )
      v21 = 0;
    if ( (CmpShutdownLock & 2) != 0 )
      goto LABEL_52;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)&CmpShutdownLock);
    while ( v22 == v20 && __strex(v21, (unsigned int *)&CmpShutdownLock) );
  }
  else
  {
    v0 = -1073741431;
    __pld(&CmpShutdownLock);
    v20 = CmpShutdownLock;
    v23 = CmpShutdownLock - 16;
    if ( (CmpShutdownLock & 0xFFFFFFF0) <= 0x10 )
      v23 = 0;
    if ( (CmpShutdownLock & 2) != 0 )
      goto LABEL_52;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)&CmpShutdownLock);
    while ( v22 == v20 && __strex(v23, (unsigned int *)&CmpShutdownLock) );
  }
  if ( v22 != v20 )
LABEL_52:
    ExfReleasePushLock(&CmpShutdownLock, v20);
  v2 = KeAbPostRelease((unsigned int)&CmpShutdownLock);
  v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v25 = *(_WORD *)(v24 + 0x134) + 1;
  *(_WORD *)(v24 + 308) = v25;
  if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
    v2 = KiCheckForKernelApcDelivery(v2);
LABEL_58:
  if ( v1 )
  {
    __pld(&CmpShutdownRundown);
    v26 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v27 == v26 && __strex(v26 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v27 != v26 )
      v2 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = *(_WORD *)(v28 + 0x134) + 1;
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v2);
  }
  return v0;
}
