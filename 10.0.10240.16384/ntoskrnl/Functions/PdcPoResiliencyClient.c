// PdcPoResiliencyClient 
 
int __fastcall PdcPoResiliencyClient(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r4
  int v9; // r0
  __int64 v10; // r2
  int v11; // r0
  __int64 v12; // r2
  __int64 v13; // r0
  char v14; // r3
  char v15; // r3
  int v16[4]; // [sp+0h] [bp-10h] BYREF

  v16[0] = a4;
  v6 = PopAcquirePolicyLock();
  if ( a1 )
  {
    if ( a1 != 1 )
    {
      v7 = -1073741811;
      goto LABEL_5;
    }
    PopPdcIoCoalescing = a2;
    PopCheckResiliencyScenarios(v6);
  }
  else
  {
    PopPdcIdleResiliency = a2;
    v16[0] = a2;
    v9 = PopSetPowerSettingValueAcDc(&GUID_PDC_IDLE_RESILIENCY_ENGAGED, 4, v16);
    PopCheckResiliencyScenarios(v9);
    LODWORD(v10) = &dword_6353F0;
    v11 = PopAccumulateNonActivatedCpuTime(__SPAIR64__(&dword_6353E8, a2), v10);
    v13 = PpmQueryTime(v11, v12);
    if ( a2 )
    {
      qword_6353B8 = v13;
      v14 = PopFxDeviceAccountingLevel;
      __dmb(0xBu);
      if ( (v14 & 4) != 0 )
        PopFxResumeDeviceAccounting();
      PopSetDripsWatchdog();
    }
    else
    {
      qword_6353C0 = qword_6353C0 - qword_6353B8 + v13;
      v15 = PopFxDeviceAccountingLevel;
      __dmb(0xBu);
      if ( (v15 & 4) != 0 )
        PopFxPauseDeviceAccounting();
      PopCancelDripsWatchdog();
    }
  }
  v7 = 0;
LABEL_5:
  PopReleasePolicyLock();
  return v7;
}
