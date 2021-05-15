// CmShutdownSystem 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmShutdownSystem(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r1
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r3
  int v8; // r3
  int i; // r0
  int v10; // r5
  int v11; // r0
  int v12; // r4
  char *v13; // r5
  int v14; // r6
  int v15; // r3
  bool v16; // zf
  unsigned __int64 v17; // r2
  int v18; // r0
  void *v19; // r0
  unsigned __int64 v20; // r2
  int j; // r0
  int v22; // r4
  int v23; // r0
  int k; // r0
  int v25; // r0
  int v26; // r4
  int l; // r0
  int v28; // r5
  int v29; // r1 OVERLAPPED
  _DWORD *v30; // r2 OVERLAPPED
  unsigned int v31; // r2
  int v32; // r0
  int v33; // r4
  int m; // r0
  int v35; // r0
  int v36; // r4
  int v37; // r0
  unsigned int v40[8]; // [sp+8h] [bp-20h] BYREF

  v40[0] = a3;
  v40[1] = a4;
  if ( a1 )
  {
    CmpTraceShutdownStart();
    if ( CmpRegistryRootObject )
      ObfDereferenceObject(CmpRegistryRootObject);
    do
      v4 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( !v4 && __strex(1u, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v4 && v4 != 1 )
      ExfWaitForRundownProtectionRelease((unsigned int *)&CmpShutdownRundown, v4);
    __dmb(0xBu);
    do
      v5 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( __strex(1u, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    v6 = CmpTraceShutdownRundownComplete();
    LockShutdownExclusive(v6);
    LOCK_HIVE_LOAD();
    CmpLockRegistryExclusive();
    v7 = CmpActiveHiveRundownCount;
    v40[0] = CmpActiveHiveRundownCount;
    __dmb(0xBu);
    if ( v7 > 0 )
    {
      CmpUnlockRegistry();
      UNLOCK_HIVE_LOAD();
      do
      {
        ExBlockOnAddressPushLock(
          (int)&CmpActiveHiveRundownEvent,
          (unsigned __int64 *)&CmpActiveHiveRundownCount,
          v40,
          4,
          0);
        v8 = CmpActiveHiveRundownCount;
        v40[0] = CmpActiveHiveRundownCount;
        __dmb(0xBu);
      }
      while ( v8 > 0 );
      LOCK_HIVE_LOAD();
      CmpLockRegistryExclusive();
    }
    for ( i = 0; ; i = v12 )
    {
      v11 = CmpGetNextActiveHive(i);
      v12 = v11;
      if ( !v11 )
        break;
      v10 = CmCloseRmHandle(*(_DWORD *)(v11 + 3256), 1);
      CmCloseTmHandle(*(_DWORD *)(v12 + 3256));
      CmpUnlockRegistry();
      UNLOCK_HIVE_LOAD();
      if ( v10 )
      {
        ZwClose();
        ZwClose();
      }
      LOCK_HIVE_LOAD();
      CmpLockRegistryExclusive();
    }
    if ( !CmFirstTime )
    {
      v13 = (char *)&CmpLazyWriterData;
      v14 = 2;
      do
      {
        KeCancelTimer((int)v13);
        v13 += 128;
        --v14;
      }
      while ( v14 );
    }
    while ( 1 )
    {
      v18 = CmpGetNextActiveHive(v12);
      v12 = v18;
      if ( !v18 )
        break;
      v15 = *(_DWORD *)(v18 + 3256);
      if ( v15 )
      {
        v16 = *(_DWORD *)(v15 + 8) == v15 + 8;
        LODWORD(v17) = *(_DWORD *)(v18 + 32);
        HIDWORD(v17) = *(_DWORD *)(v17 + 144);
        if ( v16 )
          HIDWORD(v17) &= 0xFFFFFFFE;
        else
          HIDWORD(v17) |= 1u;
        *(_DWORD *)(v17 + 144) = HIDWORD(v17);
        HvMarkBaseBlockDirty(v18, v17);
      }
    }
    v19 = off_60E8A4;
    if ( CmRmSystem )
    {
      LODWORD(v20) = *((_DWORD *)off_60E8A4 + 8);
      HIDWORD(v20) = *(_DWORD *)(v20 + 144);
      if ( *(_DWORD *)(CmRmSystem + 8) == CmRmSystem + 8 )
        HIDWORD(v20) &= 0xFFFFFFFE;
      else
        HIDWORD(v20) |= 1u;
      *(_DWORD *)(v20 + 144) = HIDWORD(v20);
      HvMarkBaseBlockDirty((int)v19, v20);
    }
    CmpUnlockRegistry();
    UNLOCK_HIVE_LOAD();
    UnlockShutdown();
    CmpTraceShutdownFlushStart();
    for ( j = CmpGetNextActiveHive(0); ; j = CmpGetNextActiveHive(v22) )
    {
      v22 = j;
      if ( !j )
        break;
      if ( !CmpNoWrite && (*(_DWORD *)(j + 92) & 2) == 0 )
        *(_BYTE *)(j + 3864) = CmpFlushHive(j, 12) >= 0;
    }
    v23 = CmpTraceShutdownFlushStop();
    LockShutdownExclusive(v23);
    LOCK_HIVE_LOAD();
    CmpLockRegistryExclusive();
    for ( k = 0; ; k = v26 )
    {
      v25 = CmpGetNextActiveHive(k);
      v26 = v25;
      if ( !v25 )
        break;
      CmShutdownCmRM(*(_DWORD *)(v25 + 3256), 0);
    }
    for ( l = 0; ; l = v33 )
    {
      v32 = CmpGetNextActiveHive(l);
      v33 = v32;
      if ( !v32 )
        break;
      v28 = v32 + 3232;
      if ( *(_DWORD *)(v32 + 3232) != v32 + 3232 )
      {
        CmpLockHiveListExclusive();
        *(_QWORD *)&v29 = *(_QWORD *)v28;
        if ( *(_DWORD *)(*(_DWORD *)v28 + 4) != v28 || *v30 != v28 )
          __fastfail(3u);
        *v30 = v29;
        *(_DWORD *)(v29 + 4) = v30;
        CmpUnlockHiveList();
      }
      if ( (*(_DWORD *)(v33 + 3228) & 2) != 0 )
        CmpRemoveHiveFromMapping(v33);
      HvViewMapCleanup(v33 + 152, v33, 0);
      *(_BYTE *)(v33 + 72) &= 0xFBu;
      if ( *(_BYTE *)(v33 + 3864) && (*(_DWORD *)(v33 + 92) & 0x8000) == 0 )
      {
        v31 = *(_DWORD *)(v33 + 952) + 4096;
        if ( (__int64)(*(_QWORD *)(v33 + 1944) - v31) > 0x100000 )
          CmpDoFileSetSizeEx(v33, 0, v31, 0, 0);
        CmpCmdHiveClose(v33);
      }
    }
    for ( m = 0; ; m = v36 )
    {
      v35 = CmpGetNextFailedUnloadHive(m);
      v36 = v35;
      if ( !v35 )
        break;
      HvViewMapCleanup(v35 + 152, v35, 0);
    }
    if ( CmpBootDeviceUsageNotificationSent )
    {
      CmpSendBootDeviceUsageNotification(1);
      CmpBootDeviceUsageNotificationSent = 0;
    }
    __dmb(0xBu);
    HvShutdownComplete = 1;
    v37 = CmpParseCacheClose();
    if ( (PopShutdownCleanly & 8) != 0 && !CmFirstTime )
      CmpFreeAllMemory(v37);
    CmpUnlockRegistry();
    UNLOCK_HIVE_LOAD();
    UnlockShutdown();
    CmpTraceShutdownStop();
  }
  else
  {
    CmpDoIdleProcessing = 0;
    CmpNoMoreTx = 1;
  }
  return a1;
}
