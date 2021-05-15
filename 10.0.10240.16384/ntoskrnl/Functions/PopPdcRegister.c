// PopPdcRegister 
 
int __fastcall PopPdcRegister(int a1, int (__fastcall **a2)(int a1, int a2, int a3, int a4))
{
  int v4; // r5

  if ( !a2 )
    return -1073741811;
  v4 = 0;
  PopAcquirePolicyLock();
  memmove((int)&PoPdcCallbacks, a1 + 4, 0x34u);
  *a2 = PdcPoResiliencyClient;
  a2[1] = PdcPoLowPower;
  a2[2] = (int (__fastcall *)(int, int, int, int))PdcPoSetPowerAction;
  a2[3] = (int (__fastcall *)(int, int, int, int))PdcPoReportButton;
  a2[4] = (int (__fastcall *)(int, int, int, int))PdcPoReportLidState;
  a2[5] = (int (__fastcall *)(int, int, int, int))PdcPoRecordButton;
  a2[6] = (int (__fastcall *)(int, int, int, int))PdcPoVerifyActionPolicy;
  a2[7] = (int (__fastcall *)(int, int, int, int))PdcPoVerifyPowerState;
  a2[8] = (int (__fastcall *)(int, int, int, int))PdcPoBlockSessionSwitch;
  a2[9] = (int (__fastcall *)(int, int, int, int))PdcPoControlMonitor;
  a2[10] = (int (__fastcall *)(int, int, int, int))PdcPoCurrentPdcPhase;
  a2[11] = (int (__fastcall *)(int, int, int, int))PdcPoControlInput;
  a2[12] = (int (__fastcall *)(int, int, int, int))PdcPoVerifyProcessIntegrity;
  a2[13] = (int (__fastcall *)(int, int, int, int))PdcPoIdleScanEnabled;
  a2[14] = (int (__fastcall *)(int, int, int, int))PdcPoPerfOverride;
  a2[15] = (int (__fastcall *)(int, int, int, int))PdcPoCsEnterExitReason;
  a2[16] = (int (__fastcall *)(int, int, int, int))PdcPoSetPowerSettingValue;
  a2[17] = (int (__fastcall *)(int, int, int, int))PdcPoPpmRegisterProfiles;
  a2[18] = (int (__fastcall *)(int, int, int, int))PdcPoPpmApplyProfile;
  a2[19] = (int (__fastcall *)(int, int, int, int))PdcPoPpmResetProfile;
  PopReleasePolicyLock();
  return v4;
}
