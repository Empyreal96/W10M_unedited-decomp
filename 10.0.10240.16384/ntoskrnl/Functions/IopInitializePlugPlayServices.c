// IopInitializePlugPlayServices 
 
int __fastcall IopInitializePlugPlayServices(int a1, int a2)
{
  int v3; // r0
  int v5; // r4
  int v6; // r0
  int v7; // r0
  int v8; // r1
  _DWORD *v9; // r3
  int v10; // r2
  int v11; // r0
  int v12; // r1
  int v13; // r0
  int v14; // r0
  _DWORD *v15; // r7
  int v16; // r0
  int v17; // r2
  int v18; // r0
  __int64 v19; // r2
  int v20; // r2
  __int64 v21; // r4
  _DWORD *v22; // [sp+10h] [bp-98h] BYREF
  int v23; // [sp+14h] [bp-94h] BYREF
  char v24[8]; // [sp+18h] [bp-90h] BYREF
  int v25; // [sp+20h] [bp-88h] BYREF
  const __int16 *v26; // [sp+24h] [bp-84h]
  int v27; // [sp+28h] [bp-80h] BYREF
  const __int16 *v28; // [sp+2Ch] [bp-7Ch]
  int v29; // [sp+30h] [bp-78h]
  int v30[11]; // [sp+34h] [bp-74h] BYREF
  char v31[8]; // [sp+60h] [bp-48h] BYREF
  int v32; // [sp+68h] [bp-40h]
  int v33; // [sp+6Ch] [bp-3Ch]
  int v34; // [sp+70h] [bp-38h]
  int v35; // [sp+74h] [bp-34h]
  int v36; // [sp+78h] [bp-30h]
  int v37; // [sp+7Ch] [bp-2Ch]
  int v38; // [sp+80h] [bp-28h]
  int v39; // [sp+84h] [bp-24h]

  v25 = 0;
  v24[0] = 0;
  if ( a2 )
  {
    if ( a2 != 1 )
      return -1073741584;
    v5 = PnpDiagInitialize();
    if ( v5 >= 0 )
    {
      LODWORD(v19) = 0;
      TraceLoggingRegisterEx((int)&dword_6174F0, v19);
      v5 = PiDcInit(1);
      if ( v5 >= 0 )
      {
        v5 = PiUEventInit(1);
        if ( v5 >= 0 )
        {
          v20 = *(_DWORD *)(a1 + 132);
          v32 = *(_DWORD *)(v20 + 72);
          v33 = 0;
          v34 = 8;
          v35 = 0;
          v36 = *(_DWORD *)(v20 + 72) + 8;
          v37 = 0;
          v38 = 8;
          v39 = 0;
          v21 = PnpEtwHandle;
          if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_OsLoader_Time) )
            EtwWrite(v21, SHIDWORD(v21), (int)KMPnPEvt_OsLoader_Time, 0);
          v5 = PiPnpRtlInit(1);
          if ( v5 >= 0 )
          {
            PnpRequestDeviceAction(*(int **)(IopRootDeviceNode + 16), 10, 0, 0, 0, 0);
            PnpShutdownEvent = 0;
            byte_630871 = 0;
            byte_630872 = 4;
            dword_630874 = 0;
            dword_63087C = (int)&dword_630878;
            dword_630878 = (int)&dword_630878;
            PpInitializeBootDDB(a1, 1);
            v5 = 0;
          }
        }
      }
    }
    return v5;
  }
  PnPInitialized = 0;
  PnpSystemHiveLimits = 80;
  dword_637698 = 90;
  CmRegisterSystemHiveLimitCallback(a1, 0, (int)&PnpSystemHiveLimits);
  PnpSystemHiveTooLarge = 0;
  v30[1] = 24;
  v30[2] = 0;
  v30[4] = 576;
  v30[3] = (int)CmRegistryMachineHardwareDescriptionSystemName;
  v30[5] = 0;
  v30[6] = 0;
  v3 = ZwCreateKey();
  if ( v3 >= 0 )
  {
    if ( IopGetRegistryValue(v29, L"OldSystemBiosDate", 0, (int *)&v22) >= 0 )
      return sub_96595C();
    v3 = ZwClose();
  }
  v5 = PnpDeviceCompletionQueueInitialize(v3);
  if ( v5 >= 0 )
  {
    PiInitFirmwareResources(a1);
    v6 = PpInitializeBootDDB(a1, 0);
    v7 = PipInitDeviceOverrideCache(v6);
    PnpSystemDeviceEnumerationComplete = 0;
    byte_630DF1 = 0;
    byte_630DF2 = 4;
    dword_630DF4 = 0;
    dword_630DFC = (int)&dword_630DF8;
    dword_630DF8 = (int)&dword_630DF8;
    v5 = PiInitCacheGroupInformation(v7);
    if ( v5 >= 0 )
    {
      PpRegistrySemaphore = 5;
      byte_630722 = 5;
      dword_630724 = 1;
      dword_63072C = (int)&dword_630728;
      dword_630728 = (int)&dword_630728;
      dword_630730 = 1;
      v9 = &IopLegacyBusInformationTable;
      v10 = 18;
      do
      {
        *v9 = v9;
        v9[1] = v9;
        v9 += 2;
        --v10;
      }
      while ( v10 );
      IopInitializeResourceMap(a1, v8, 0, v9, 0, 0, v31);
      IopInitReservedResourceList = 0;
      IopAllocateBootResourcesRoutine = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))IopReportBootResources;
      PnpDefaultInterfaceType = 1;
      ArbInitializeOsInaccessibleRange(dword_633808);
      v11 = IopPortInitialize();
      v5 = v11;
      if ( v11 >= 0 )
      {
        v5 = IopMemInitialize(v11, v12);
        if ( v5 >= 0 )
        {
          v5 = IopDmaInitialize();
          if ( v5 >= 0 )
          {
            v5 = IopIrqInitialize();
            if ( v5 >= 0 )
            {
              v5 = IopBusNumberInitialize();
              if ( v5 >= 0 )
              {
                v5 = PiPnpRtlInit(0);
                if ( v5 >= 0 )
                {
                  v13 = PipMigratePnpState();
                  v5 = PiDmInit(v13);
                  if ( v5 >= 0 )
                  {
                    v5 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, &v25);
                    if ( v5 >= 0 )
                    {
                      v27 = 1572886;
                      v28 = L"Control\\Pnp";
                      if ( IopCreateRegistryKeyEx(&v23, v25, (int)&v27, 983103, 0, 0) >= 0 )
                      {
                        if ( IopGetRegistryValue(v23, L"AsynchronousOptions", 0, &v25) >= 0 )
                        {
                          if ( *(_DWORD *)(v25 + 4) == 4 && *(_DWORD *)(v25 + 12) == 4 )
                            PnpAsyncOptions = *(_DWORD *)(*(_DWORD *)(v25 + 8) + v25);
                          ExFreePoolWithTag(v25);
                        }
                        if ( IopGetRegistryValue(v23, L"DisableRebalance", 0, &v25) >= 0 )
                        {
                          if ( *(_DWORD *)(v25 + 4) == 4 && *(_DWORD *)(v25 + 12) == 4 )
                            PnpDisableRebalance = *(_DWORD *)(v25 + *(_DWORD *)(v25 + 8));
                          ExFreePoolWithTag(v25);
                        }
                        if ( IopGetRegistryValue(v23, L"BootOptions", 0, &v25) >= 0 )
                        {
                          if ( *(_DWORD *)(v25 + 4) == 4 && *(_DWORD *)(v25 + 12) == 4 )
                            PnpBootOptions = *(_DWORD *)(*(_DWORD *)(v25 + 8) + v25);
                          ExFreePoolWithTag(v25);
                        }
                        if ( IopGetRegistryValue(v23, L"FindBestConfigurationTimeout", 0, &v25) >= 0 )
                        {
                          if ( *(_DWORD *)(v25 + 4) == 4 && *(_DWORD *)(v25 + 12) == 4 )
                            PnpFindBestConfigurationTimeout = *(_DWORD *)(*(_DWORD *)(v25 + 8) + v25);
                          ExFreePoolWithTag(v25);
                        }
                        IopQueryDeviceResetRegistrySettings(v23);
                        ZwClose();
                      }
                      v27 = 4063292;
                      v28 = L"\\Registry\\Machine\\System\\Setup";
                      if ( IopOpenRegistryKeyEx(&v23) >= 0 )
                      {
                        if ( IopGetRegistryValue(v23, L"SystemSetupInProgress", 0, (int *)&v22) >= 0 )
                        {
                          if ( v22[1] == 4 && v22[3] == 4 && *(_DWORD *)((char *)v22 + v22[2]) )
                            PnpSetupInProgress = 1;
                          ExFreePoolWithTag((unsigned int)v22);
                        }
                        if ( IopGetRegistryValue(v23, L"SetupPhase", 0, (int *)&v22) >= 0 )
                        {
                          if ( v22[1] == 4 && v22[3] == 4 && *(_DWORD *)((char *)v22 + v22[2]) )
                            PnpSetupPhaseInProgress = 1;
                          ExFreePoolWithTag((unsigned int)v22);
                        }
                        if ( IopGetRegistryValue(v23, L"SetupType", 0, (int *)&v22) >= 0 )
                        {
                          if ( v22[1] == 4 && v22[3] == 4 && *(_DWORD *)((char *)v22 + v22[2]) )
                            PnpSetupTypeInProgress = 1;
                          ExFreePoolWithTag((unsigned int)v22);
                        }
                        if ( IopGetRegistryValue(v23, L"OOBEInProgress", 0, (int *)&v22) >= 0 )
                        {
                          if ( v22[1] == 4 && v22[3] == 4 && *(_DWORD *)((char *)v22 + v22[2]) )
                            PnpSetupOOBEInProgress = 1;
                          ExFreePoolWithTag((unsigned int)v22);
                        }
                        if ( IopGetRegistryValue(v23, L"Upgrade", 0, (int *)&v22) >= 0 )
                        {
                          if ( v22[1] == 4 && v22[3] == 4 && *(_DWORD *)((char *)v22 + v22[2]) )
                            PnpSetupUpgradeInProgress = 1;
                          ExFreePoolWithTag((unsigned int)v22);
                        }
                        if ( IopGetRegistryValue(v23, L"RollbackActive", 0, (int *)&v22) >= 0 )
                        {
                          if ( v22[1] == 4 && v22[3] == 4 && *(_DWORD *)((char *)v22 + v22[2]) )
                            PnpSetupRollbackActiveInProgress = 1;
                          ExFreePoolWithTag((unsigned int)v22);
                        }
                        ZwClose();
                      }
                      v5 = PipHardwareConfigInit(*(_DWORD *)(a1 + 132) + 2120);
                      if ( v5 >= 0 )
                      {
                        PipCheckSystemFirmwareUpdated(v24);
                        v5 = PiDcInit(0);
                        if ( v5 >= 0 )
                        {
                          v5 = PiAuCreateSecurityObjects();
                          if ( v5 >= 0 )
                          {
                            v5 = PiDqInit();
                            if ( v5 >= 0 )
                            {
                              v5 = PpDevCfgInit();
                              if ( v5 >= 0 )
                              {
                                v5 = CmCreateDevice(PiPnpRtlCtx, (int)L"HTREE\\ROOT\\0", 983103, &v22, 0, 0);
                                if ( v5 >= 0 )
                                {
                                  CmSetDeviceRegProp(
                                    PiPnpRtlCtx,
                                    (int)L"HTREE\\ROOT\\0",
                                    (int)v22,
                                    37,
                                    1,
                                    (int)L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}",
                                    78,
                                    0);
                                  v30[0] = 0;
                                  CmSetDeviceRegProp(
                                    PiPnpRtlCtx,
                                    (int)L"HTREE\\ROOT\\0",
                                    (int)v22,
                                    11,
                                    4,
                                    (int)v30,
                                    4,
                                    0);
                                  ZwClose();
                                  IopPendingEjects = (int)&IopPendingEjects;
                                  dword_63073C = (int)&IopPendingEjects;
                                  IopPendingSurpriseRemovals = (int)&IopPendingSurpriseRemovals;
                                  dword_630744 = (int)&IopPendingSurpriseRemovals;
                                  ExInitializeResourceLite((int)&IopDeviceTreeLock);
                                  ExInitializeResourceLite((int)&IopSurpriseRemoveListLock);
                                  ExInitializeResourceLite((int)&PnpDevicePropertyLock);
                                  ExInitializeResourceLite((int)&PiEngineLock);
                                  PnpSpinLock = 0;
                                  v14 = KeInitializeGuardedMutex((int)&PiResourceListLock);
                                  v5 = PiDeviceDependencyInit(v14);
                                  if ( v5 >= 0 )
                                  {
                                    v5 = PnpInitializeDeviceActions();
                                    if ( v5 >= 0 )
                                    {
                                      PpProfileInit();
                                      IopWarmEjectPdo = 0;
                                      IopWarmEjectLock = 1;
                                      byte_630851 = 0;
                                      byte_630852 = 4;
                                      dword_630854 = 1;
                                      dword_63085C = (int)&dword_630858;
                                      dword_630858 = (int)&dword_630858;
                                      v27 = 2490404;
                                      v28 = L"\\Driver\\PnpManager";
                                      v5 = IoCreateDriver(&v27, (int (__fastcall *)(_BYTE *, _DWORD))PipPnPDriverEntry);
                                      if ( v5 >= 0 )
                                      {
                                        v5 = IoCreateDevice(PnpDriverObject, 0, 0, 4u, 0, 0, &v25);
                                        if ( v5 >= 0 )
                                        {
                                          v15 = (_DWORD *)v25;
                                          v16 = v25;
                                          *(_DWORD *)(v25 + 28) |= 0x1000u;
                                          v5 = PipAllocateDeviceNode(v16, &IopRootDeviceNode);
                                          if ( !IopRootDeviceNode )
                                          {
                                            IoDeleteDevice(v15);
                                            PsDereferencePrimaryToken(PnpDriverObject);
                                            goto LABEL_65;
                                          }
                                          PipSetDevNodeFlags(IopRootDeviceNode, 305);
                                          PipSetDevNodeUserFlags(IopRootDeviceNode, 10);
                                          *(_DWORD *)(IopRootDeviceNode + 420) = -2;
                                          v5 = PnpAllocateDeviceInstancePath(IopRootDeviceNode, 26);
                                          if ( v5 >= 0 )
                                          {
                                            v25 = 1703960;
                                            v26 = L"HTREE\\ROOT\\0";
                                            PnpCopyDeviceInstancePath(IopRootDeviceNode, (unsigned __int16 *)&v25);
                                            v5 = PnpMapDeviceObjectToDeviceInstance(
                                                   *(_DWORD *)(IopRootDeviceNode + 16),
                                                   IopRootDeviceNode + 20,
                                                   v17,
                                                   IopRootDeviceNode);
                                            if ( v5 >= 0 )
                                            {
                                              v25 = 5111884;
                                              v26 = L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}";
                                              RtlGUIDFromString(
                                                (unsigned __int16 *)&v25,
                                                (_BYTE *)(IopRootDeviceNode + 424));
                                              PnpQueryAndSaveDeviceNodeCapabilities((_DWORD *)IopRootDeviceNode);
                                              PipSetDevNodeState((_DWORD *)IopRootDeviceNode, 776);
LABEL_65:
                                              if ( v5 >= 0 )
                                              {
                                                v5 = CmAddDeviceToContainer(
                                                       PiPnpRtlCtx,
                                                       (int)L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}",
                                                       (int)L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}",
                                                       (int)L"HTREE\\ROOT\\0",
                                                       0);
                                                if ( v5 >= 0 )
                                                {
                                                  if ( v24[0] )
                                                    PiDcHandleSystemFirmwareUpdate();
                                                  v5 = PnpInitializeDeviceEvents();
                                                  if ( v5 >= 0 )
                                                  {
                                                    v18 = PnpInitializeNotification();
                                                    v5 = PnpBusTypeGuidInitialize(v18);
                                                    if ( v5 >= 0 )
                                                    {
                                                      PnpReplaceEvent = 1;
                                                      byte_62FAE1 = 0;
                                                      byte_62FAE2 = 4;
                                                      dword_62FAE4 = 1;
                                                      dword_62FAEC = (int)&dword_62FAE8;
                                                      dword_62FAE8 = (int)&dword_62FAE8;
                                                      v5 = PiSwInit();
                                                      if ( v5 >= 0 )
                                                      {
                                                        v5 = PiUEventInit(0);
                                                        if ( v5 >= 0 )
                                                        {
                                                          v5 = PiDaInit();
                                                          if ( v5 >= 0 )
                                                          {
                                                            if ( PipProcessPendingServices() >= 0 )
                                                              PipProcessPendingOsExtensionResources();
                                                            PnpRequestDeviceAction(
                                                              *(int **)(IopRootDeviceNode + 16),
                                                              10,
                                                              0,
                                                              0,
                                                              0,
                                                              0);
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                              return v5;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return v5;
}
