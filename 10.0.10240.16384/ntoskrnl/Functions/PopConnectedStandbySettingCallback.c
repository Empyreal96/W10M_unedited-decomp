// PopConnectedStandbySettingCallback 
 
int __fastcall PopConnectedStandbySettingCallback(unsigned int a1, int *a2, int a3)
{
  int v5; // r5
  int v7; // r8
  int v8; // r10
  int v9; // r1
  int v10; // r9
  unsigned int v11; // r0
  int v12; // r1
  int v13; // r6
  unsigned int v14; // r0
  unsigned int v15; // r0
  int v16; // r0
  unsigned __int64 v17; // kr00_8
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r0
  int v28; // r1
  int v29; // r1
  int v30; // [sp+0h] [bp-D8h]
  char v31; // [sp+0h] [bp-D8h]
  int v32; // [sp+4h] [bp-D4h]
  int v33; // [sp+4h] [bp-D4h]
  int v34; // [sp+8h] [bp-D0h] BYREF
  int v35; // [sp+Ch] [bp-CCh]
  int v36; // [sp+10h] [bp-C8h] BYREF
  int v37; // [sp+14h] [bp-C4h]
  __int64 v38; // [sp+18h] [bp-C0h] BYREF
  __int64 v39; // [sp+20h] [bp-B8h]
  int v40; // [sp+28h] [bp-B0h]
  char v41[168]; // [sp+30h] [bp-A8h] BYREF

  if ( !memcmp((unsigned int)&GUID_CONSOLE_DISPLAY_STATE, a1, 16) && a3 == 4 && a2 )
  {
    v5 = *a2;
    if ( !PopPlatformAoAc )
      return sub_7F2684();
    if ( PopMonitorOffDueToSleep )
    {
      PopMonitorOffDueToSleep = 0;
      if ( !v5 )
      {
LABEL_9:
        PopBatteryUpdateCurrentState();
        PopAcquirePolicyLock();
        v7 = dword_61ED88;
        v8 = KeQueryInterruptTime();
        v10 = v9;
        v11 = dword_635500;
        __dmb(0xBu);
        v30 = PpmQueryPlatformStateResidency(v11);
        v32 = v12;
        if ( v5 )
        {
          if ( v5 == 1 && qword_635388 )
          {
            v13 = 2;
            PopCalculateCsSummary((int)v41, 17);
            PopFxStopDeviceAccounting();
            PpmSnapDripsAccountingSnapshot();
            PopDiagTraceCsConsumption((int)v41, v21, v22, v23, v30, v32);
            PopDiagTraceCsExitReason(
              (int)v41,
              v24,
              v25,
              v26,
              v31,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              SBYTE4(v38),
              v39,
              SHIDWORD(v39));
            PopTransitionTelemetryOsState();
            PopThermalCsExit();
            __dmb(0xBu);
            if ( PopFxLookupSocSubsystemsByPlatformIdleState() )
            {
              v28 = dword_635500;
              __dmb(0xBu);
              PopFxLogSocSubsystemBlockingTimes((unsigned __int8)PopWdiCurrentScenarioInstanceId, v28);
              v29 = dword_635500;
              __dmb(0xBu);
              PopFxLogSocSubsystemMetadata((unsigned __int8)PopWdiCurrentScenarioInstanceId, v29);
            }
          }
          else
          {
            v13 = 0;
          }
        }
        else
        {
          v13 = 1;
          PopCalculateIdleInformation((int)&v38);
          v14 = dword_635500;
          __dmb(0xBu);
          v15 = PpmGetPlatformSelectionVetoCounts(v14, &v34, &v36);
          LODWORD(qword_635388) = v8;
          HIDWORD(qword_635388) = v10;
          PopCsConsumption = v7;
          qword_635390 = v39;
          dword_6353A0 = v40;
          qword_635398 = v38;
          qword_6353C0 = 0i64;
          qword_6353A8 = 0i64;
          dword_6353B0 = 0;
          unk_6353B4 = 0;
          qword_6353D0 = 0i64;
          qword_6353E0 = 0i64;
          dword_6353F0 = 0;
          unk_6353F4 = 0;
          dword_6353F8 = v30;
          dword_6353FC = v32;
          dword_635400 = v34;
          dword_635404 = v35;
          dword_635408 = v36;
          dword_63540C = v37;
          byte_635410 ^= ((dword_61EC0C == 0) ^ byte_635410) & 1;
          byte_635411 ^= (PopConnectedStandbyCompliantNic(v15) ^ byte_635411) & 1;
          byte_635411 ^= (byte_635411 ^ (2 * PopDisconnectedStandbyEnabled(0))) & 2;
          v16 = 0;
          do
            v17 = __ldrexd((unsigned __int64 *)&algn_635412[110]);
          while ( __strexd(0i64, (unsigned __int64 *)&algn_635412[110]) );
          if ( PopPdcLastCsEnterReason == 23 )
            v16 = 1;
          PopThermalCsEntry(v16);
          __dmb(0xBu);
          if ( PopFxLookupSocSubsystemsByPlatformIdleState() )
          {
            v27 = dword_635500;
            __dmb(0xBu);
            PopFxResetSocSubsystemAccounting(v27);
          }
          PopTransitionTelemetryOsState();
          PopFxStartDeviceAccounting();
          PpmResetDripsAccountingSnapshot();
          PopDiagTraceCsEnterReason(
            PopPdcLastCsEnterReason,
            v18,
            v19,
            v20,
            v30,
            v32,
            v34,
            v35,
            v36,
            v37,
            v38,
            SHIDWORD(v38),
            v39);
        }
        PopReleasePolicyLock();
        PopFanUpdateCsState(v5 != 0);
        if ( v13 == 1 )
        {
          PopDiagNextSleepStudySession((int)&GUID_SPM_LOW_POWER_CS, 0);
          PopCsBatterySaverWdiSession = PopWdiCurrentScenarioInstanceId;
        }
        else if ( v13 == 2 )
        {
          PopDiagNextSleepStudySession((int)&NullGuid, (int)v41);
        }
        return 0;
      }
    }
    else
    {
      if ( !dword_61EC64 && !PopHiberBootForceMonitorOff )
        goto LABEL_9;
      PopMonitorOffDueToSleep = 1;
    }
  }
  return 0;
}
