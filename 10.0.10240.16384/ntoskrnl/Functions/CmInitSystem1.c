// CmInitSystem1 
 
int __fastcall CmInitSystem1(int a1)
{
  _BYTE *v2; // r0
  int v4; // r0
  _BYTE *v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r1
  int v9; // r0
  __int16 **v10; // r4
  int v11; // r8
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r1
  _BYTE *v18; // r4
  int v19; // r9
  int v20; // r9
  int v21; // r8
  int v22; // r0
  int v23; // r8
  int v24; // r8
  int v25; // r0
  int v26; // r0
  int v27; // r0
  int v28; // r0
  int v29; // r0
  _DWORD *v30; // r2
  int v31; // r3
  int v32; // r6
  _BYTE *v33; // r0
  int v34; // r4
  unsigned int v35; // r6
  int v36; // r0
  int v37; // r1
  int *v38; // r4
  int i; // r3
  int v40; // t1
  int v41; // r0
  int v42[2]; // [sp+20h] [bp-1B8h] BYREF
  int v43; // [sp+28h] [bp-1B0h] BYREF
  int v44; // [sp+2Ch] [bp-1ACh]
  unsigned __int16 *v45; // [sp+30h] [bp-1A8h]
  int v46; // [sp+34h] [bp-1A4h]
  _BYTE *v47; // [sp+38h] [bp-1A0h]
  int v48; // [sp+3Ch] [bp-19Ch]
  int v49[2]; // [sp+40h] [bp-198h] BYREF
  int v50; // [sp+48h] [bp-190h] BYREF
  char v51[76]; // [sp+4Ch] [bp-18Ch] BYREF
  int v52[80]; // [sp+98h] [bp-140h] BYREF

  v50 = 0;
  memset(v51, 0, sizeof(v51));
  v52[0] = 0;
  v2 = memset(&v52[1], 0, 284);
  CmIoFileObjectType = (int)&IoFileObjectType;
  if ( InitIsWinPEMode )
    return sub_966CBC(v2);
  if ( CmpVolatileBoot )
    CmpShareSystemHives = 1;
  v4 = CmpInitializeRegistryNames();
  CmpInitGlobalQuotaAllowed(v4);
  off_92078C = &CmpHiveListHead;
  CmpHiveListHead = &CmpHiveListHead;
  off_920784 = &CmpFailedUnloadListHead;
  CmpFailedUnloadListHead = (int)&CmpFailedUnloadListHead;
  CmpHiveListHeadLock = 0;
  CmpLoadHiveLock = 0;
  CmpShutdownLock = 0;
  CmpShutdownRundown = 0;
  CmpActiveHiveRundownEvent = 0;
  CmpActiveAppHiveUnloadEvent = 0;
  CmpAppHiveLoadListLock = 0;
  CmpAppHiveLoadList = (int)&CmpAppHiveLoadList;
  dword_63246C = (int)&CmpAppHiveLoadList;
  ExInitializeResourceLite((int)&CmpRegistryLock);
  CmpPostLock = 1;
  dword_632444 = 0;
  unk_632448 = 0;
  byte_63244C = 1;
  byte_63244D = 0;
  byte_63244E = 4;
  dword_632450 = 0;
  dword_632458 = (int)&dword_632454;
  dword_632454 = (int)&dword_632454;
  off_920020 = &CmpAsyncKernelPostList;
  CmpAsyncKernelPostList = (int)&CmpAsyncKernelPostList;
  dword_632488 = (int)CmpWorkerEngineWorker;
  dword_63248C = 0;
  CmpWorkerEngineWorkItem = 0;
  KeInitializeGuardedMutex((int)&CmpWorkerEngineLock);
  CmpWorkerEngineListHead = &CmpWorkerEngineListHead;
  dword_6324C4 = (int)&CmpWorkerEngineListHead;
  CmpWorkerEngineFinishedEvent = 0;
  v5 = CmpInitializeNameCache();
  CmpInitCmPrivateAlloc(v5);
  v6 = CmpInitSIDToHiveMapping();
  CmpInitializeTrustedInstallerSid(v6);
  CmpInitializeDelayedCloseTable();
  CmpInitDelayDerefKCBEngine();
  CmpInitCallbacks();
  CmpInitializeFreezeThaw();
  v7 = HvInitializeHashLibrary();
  v9 = CmpValidateGlobalFlushControlFlags(v7, v8);
  CmpInitializeTransactions(v9);
  v10 = &CmpBootLoadControl;
  v11 = 7;
  CmpSystemProcess = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  do
  {
    RtlInitUnicodeString((unsigned int)v49, (unsigned __int16 *)*v10);
    v10[2] = (__int16 *)CmpComputeHashKey(0, (unsigned __int16 *)v49);
    v10 += 5;
    --v11;
  }
  while ( v11 );
  CmpLockRegistryExclusive();
  v12 = CmpInitializePreloadedHives(a1, 0);
  v13 = CmpCreateObjectTypes(v12);
  if ( v13 < 0 )
    KeBugCheckEx(103, 1, 1, v13, 0);
  v14 = CmpParseCacheInit();
  if ( v14 < 0 )
    KeBugCheckEx(103, 1, 7, v14, 0);
  v15 = CmpInitializeHive((int)&CmpMasterHive, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, v52);
  if ( v15 < 0 )
    KeBugCheckEx(103, 1, 2, v15, (int)v52);
  v16 = CmpInitializeKcbCache(CmpMasterHive, 0x80u);
  if ( v16 < 0 )
    KeBugCheckEx(103, 1, 3, v16, 0);
  if ( !CmpCreateRegistryRoot(v16, v17) )
    KeBugCheckEx(103, 1, 4, 0, 0);
  v43 = 24;
  v44 = 0;
  v46 = 64;
  v45 = CmRegistryMachineName;
  v48 = 0;
  v18 = CmpHiveRootSecurityDescriptor();
  v47 = v18;
  v19 = NtCreateKey((int)v42, 131103, (int)&v43, 0, (int)nullclass);
  if ( v19 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v18);
    KeBugCheckEx(103, 1, 5, v19, 0);
  }
  NtClose();
  v43 = 24;
  v44 = 0;
  v46 = 64;
  v47 = v18;
  v45 = (unsigned __int16 *)&CmRegistryUserName;
  v48 = 0;
  v20 = NtCreateKey((int)v42, 131103, (int)&v43, 0, (int)nullclass);
  if ( v20 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v18);
    KeBugCheckEx(103, 1, 6, v20, 0);
  }
  NtClose();
  v43 = 24;
  v44 = 0;
  v46 = 64;
  v47 = v18;
  v45 = (unsigned __int16 *)&CmRegistryAppName;
  v48 = 0;
  v50 = 65;
  v21 = ObOpenObjectByName((int)&v43, (int)CmKeyObjectType, 0, 0, 131103, (int)&v50, v42);
  if ( v21 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v18);
    KeBugCheckEx(103, 1, 7, v21, 0);
  }
  NtClose();
  if ( !CmpInitializeSystemHive(a1) )
  {
    ExFreePoolWithTag((unsigned int)v18);
    KeBugCheckEx(103, 1, 11, 0, 0);
  }
  v22 = CmpCreateControlSet(a1);
  if ( v22 < 0 )
    KeBugCheckEx(103, 1, 12, v22, 0);
  if ( CmpLKGEnabled )
    MEMORY[0xFFFF92F0] |= 0x10u;
  memset(v52, 0, 288);
  v23 = CmpInitializeHive((int)v49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, v52);
  if ( v23 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v18);
    KeBugCheckEx(103, 1, 15, v23, (int)v52);
  }
  v24 = v49[0];
  v25 = CmpLinkHiveToMaster(CmRegistryMachineHardwareName, 0, v49[0], 1, dword_60E790, 0, 0, (int)v18, 1);
  if ( v25 )
    KeBugCheckEx(103, 1, 16, v25, 0);
  CmpAddToHiveFileList(v24);
  ExFreePoolWithTag((unsigned int)v18);
  dword_60E784 = v24;
  v26 = CmpInitializeHardwareConfiguration(a1);
  if ( v26 < 0 )
    KeBugCheckEx(103, 1, 17, v26, 0);
  CmpNoMasterCreates = 1;
  v27 = CmpInitializePreloadedHives(a1, 1);
  if ( v27 < 0 )
    KeBugCheckEx(103, 1, 18, v27, 0);
  if ( CmRegistryLockTableLength == 4 && CmRegistryLockTableType == 4 )
  {
    v31 = CmRegistryLockTablePages;
    if ( CmRegistryLockTablePages )
    {
      if ( (unsigned int)CmRegistryLockTablePages <= 0x14 )
      {
        if ( (unsigned int)CmRegistryLockTablePages < 8 )
          v31 = 8;
      }
      else
      {
        v31 = 20;
      }
      v32 = v31 << 12;
      v33 = (_BYTE *)ExAllocatePoolWithTag(512, v31 << 12, 1951157571);
      v34 = (int)v33;
      CmpLockTable = (int)v33;
      if ( !v33 )
        KeBugCheckEx(103, 1, 19, -1073741670, 0);
      memset(v33, 0, v32);
      v35 = (unsigned int)(v32 - 16) >> 3;
      *(_DWORD *)(v34 + 8) = v35;
      *(_DWORD *)(v34 + 12) = 0;
      *(_DWORD *)v34 = 0;
      *(_DWORD *)(v34 + 4) = 0;
      if ( v35 )
      {
        while ( 1 )
        {
          RtlpInterlockedPushEntrySList((unsigned __int64 *)v34, (_DWORD *)(v34 + 8 * (v35-- + 1)));
          if ( !v35 )
            break;
          v34 = CmpLockTable;
        }
      }
      v36 = 0;
      while ( 1 )
      {
        v36 = CmpGetNextActiveHive(v36);
        if ( !v36 )
          break;
        v37 = *(_DWORD *)(v36 + 1848);
        if ( v37 )
        {
          v38 = (int *)(*(_DWORD *)(v36 + 1844) + 8);
          do
          {
            v40 = *v38;
            v38 += 3;
            for ( i = v40; i; i = *(_DWORD *)(i + 4) )
              *(_DWORD *)(i - 8) |= 0x100000u;
            --v37;
          }
          while ( v37 );
        }
      }
      CmpLockTablePresent = 1;
    }
  }
  CmSetInitMachineConfig_0();
  CmpUnlockRegistry();
  CmpMarkCurrentProfileDirty();
  v28 = CmpInitializeMachineDependentConfiguration(a1);
  if ( v28 < 0 )
    KeBugCheckEx(103, 1, 20, v28, 0);
  v29 = CmpSetSystemValues(a1);
  if ( v29 < 0 )
    KeBugCheckEx(103, 1, 21, v29, 0);
  CmpMigrateOOBELanguageToInstallationLanguage();
  ExFreePoolWithTag(dword_98223C);
  v30 = *(_DWORD **)(a1 + 132);
  if ( *v30 >= 0x34u && v30[12] )
  {
    v41 = CmpSetNetworkValue();
    if ( v41 < 0 )
      KeBugCheckEx(103, 1, 22, v41, 0);
  }
  return 1;
}
