// NtInitializeRegistry 
 
int __fastcall NtInitializeRegistry(unsigned int a1)
{
  __int16 v1; // r4
  int v3; // r4
  int v4; // r0
  BOOL v5; // r5
  int v6; // r0
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17[4]; // [sp+10h] [bp-10h] BYREF

  v1 = a1;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1 )
  {
    if ( a1 > 0x3E9 )
      return -1073741811;
    if ( a1 < 2 )
    {
      v5 = a1 == 1;
      if ( CmFirstTime != 1 )
        return -1073741790;
      CmFirstTime = 0;
      EtwpFileSystemReady = 1;
      CmCompleteInitMachineConfig_0();
      CmpInitializeSystemHivesLoad();
      CmpLockRegistryExclusive();
      CmpCmdInit(v5);
      CmpUnlockRegistry();
      if ( !v5 )
      {
        CmpLoadingSystemHivesActive = 1;
        if ( CmpInitRmLogOnLoad || CmpShareSystemHives )
        {
          CmpFinishSystemHivesLoad(1);
        }
        else
        {
          v6 = PsCreateSystemThread((int)v17, 0x1FFFFF, 0);
          if ( v6 < 0 )
            KeBugCheckEx(116, 2, 3, 3, v6);
          ZwClose();
        }
      }
      if ( !CmFastBoot )
      {
        v14 = ExpRefreshSystemTime();
        PsBootPhaseComplete(v14, v15, v16);
      }
      v7 = PnpBootPhaseComplete();
      v11 = PoInitHiberServices(v7, v8, v9, v10);
      v12 = PoClearTransitionMarker(v11);
      NlsLocaleSectionPointer = 1;
      v13 = ExNotifyPlatformBinaryExecuted(v12);
      CmpShareSystemHives = 0;
      if ( !v5 )
        IopCopyBootLogRegistryToFile(v13);
    }
    else if ( !PsIsCurrentThreadInServerSilo() )
    {
      if ( CmBootAcceptFirstTime )
      {
        CmBootAcceptFirstTime = 0;
        v4 = (unsigned __int16)(v1 - 2);
        if ( v1 != 2 )
        {
          v3 = 0;
          if ( CmpLKGEnabled )
          {
            v4 = CmpSaveBootControlSet();
            v3 = v4;
          }
          off_617B9C(v4);
          CmpUpdatePhaseAccessBit();
          return v3;
        }
        return -1073741811;
      }
      return -1073741790;
    }
    return 0;
  }
  if ( a1 == 1002 )
    return sub_810080();
  return ZwInitializeRegistry();
}
