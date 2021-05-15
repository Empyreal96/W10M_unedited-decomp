// PopIssueActionRequest 
 
int __fastcall PopIssueActionRequest(int a1, int a2, int a3, int a4)
{
  int v7; // r10
  int v8; // r4
  int v9; // r4
  BOOL v10; // r8
  BOOL v11; // r9
  int v12; // r5
  const char *v13; // r2
  const char *v14; // r3
  const char *v15; // r1
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r9
  int v20; // r1
  char v21; // r3
  int v22; // r0
  int v23; // r0
  int v24; // r0
  int v26; // [sp+8h] [bp-50h]
  int v27; // [sp+Ch] [bp-4Ch]
  int v28; // [sp+Ch] [bp-4Ch]
  int v29; // [sp+10h] [bp-48h] BYREF
  int v30; // [sp+14h] [bp-44h]
  int v31; // [sp+18h] [bp-40h]
  int v32; // [sp+1Ch] [bp-3Ch]
  char v33[4]; // [sp+20h] [bp-38h] BYREF
  int v34; // [sp+24h] [bp-34h]
  int v35; // [sp+28h] [bp-30h]
  int v36; // [sp+2Ch] [bp-2Ch]
  int v37; // [sp+34h] [bp-24h]

  v26 = a3;
  v31 = 0;
  v32 = a1;
  v7 = a1;
  PopAcquireAwaymodeLock();
  PopReadSystemAwayModePolicy();
  if ( !byte_61EC10 && !byte_61EC11 || a2 != 2 || a3 >= 5 || dword_61EC74 && dword_61EC74 != 4 && dword_61EC74 != 5 )
  {
    PopReleaseAwaymodeLock();
    if ( dword_61EC74 )
    {
      if ( (unsigned int)(dword_61EC74 - 6) > 1 )
        v9 = 20;
      else
        v9 = 21;
    }
    else
    {
      v9 = 1;
    }
    if ( a2 == 8 )
    {
      if ( PopConsoleDisplayState )
        v8 = PopPdcScreenOff(v9);
      else
        v8 = -1073700861;
      return v8;
    }
    v10 = a2 == 5 || a2 == 4 || a2 == 6;
    v11 = !PsWin32CalloutsEstablished || v10;
    if ( a4 >= 0 )
      v12 = a4 | 1;
    else
      v12 = a4 & 0xFFFFFFFE;
    if ( v11 )
      PopAction[0] &= 0xFDu;
    v27 = (unsigned __int8)byte_61ED00;
    if ( (PoDebug & 8) != 0 )
    {
      PopSystemStateString(v26);
      v13 = PopPowerActionString(a2);
      if ( v7 )
        v15 = "Promote, ";
      else
        v15 = (const char *)&word_8D24FA;
      DbgPrint("PowerAction: %s%s, Min=%s, Flags %x\n", v15, v13, v14, v12);
    }
    PopReleasePolicyLock();
    PpmBeginHighPerfRequest();
    v18 = 0;
    PopSleepStats = 0;
    if ( !v7 )
    {
      if ( v10 )
        goto LABEL_50;
      memset(&PopSleepStats, 0, 584);
    }
    if ( !v10 )
      PopSetSleepMarker(1, v16, v17, v18);
    if ( !v7 && !v10 )
    {
      PopDiagTracePowerTransitionStart(dword_61EC74, dword_61EC78);
      KeQueryPerformanceCounter(&v29, 0);
      dword_61EF48 = v29;
      dword_61EF4C = v30;
    }
LABEL_50:
    if ( v11 )
    {
      if ( (PoDebug & 8) != 0 )
        DbgPrint("PowerAction: Setting with direct call\n");
      v19 = v26;
      v8 = ZwSetSystemPowerState();
    }
    else
    {
      v19 = v26;
      v33[0] = v7;
      v34 = a2;
      v35 = v26;
      v36 = v12;
      v37 = v9;
      if ( !v7 )
        v31 = PoBlockConsoleSwitch((int)v33, v16);
      v8 = PoStartPowerStateTasks((int)v33);
      if ( v8 >= 0 && !v7 )
      {
        if ( v12 >= 0 )
          v21 = 0;
        else
          v21 = 2;
        if ( (v12 & 8) != 0 )
          v21 |= 4u;
        PfPowerActionNotify(0, v21, v26);
        __dmb(0xBu);
        PopNoMoreInput = 1;
        __dmb(0xFu);
        if ( !v27 )
        {
          PopSuspendResumePdc(1);
          PopSuspendApps(v33);
          PopSuspendServices(v33);
        }
        if ( (v12 & 8) != 0 )
          EtwShutdown(1);
        PopDispatchSuperfetchNotification(v12, v26);
        v8 = ZwSetSystemPowerState();
        PopAcquirePolicyLock();
        v28 = (unsigned __int8)byte_61ED00;
        v22 = PopReleasePolicyLock();
        if ( (v12 & 8) != 0 )
          PoUserShutdownCancelled(v22);
        __dmb(0xBu);
        PopNoMoreInput = 0;
        __dmb(0xFu);
        if ( !v28 )
        {
          PopResumeServices(v33);
          PopResumeApps(v33);
          PopSuspendResumePdc(0);
        }
        v19 = v26;
        PfPowerActionNotify(7, 0, v26);
        v7 = v32;
      }
      PoEndPowerStateTasks((int)v33);
      if ( v7 )
        goto LABEL_79;
      PoUnblockConsoleSwitch((int)v33, v31);
    }
    if ( !v7 && !v10 )
    {
      if ( v8 >= 0 )
      {
        v23 = KeQueryPerformanceCounter(&v29, 0);
        dword_61EF60 = v29;
        dword_61EF64 = v30;
        v24 = PopDiagTraceHiberStats(v23);
        PopDiagTracePowerTransitionTime(v24);
        PopDiagTracePerfTrackData(v12);
        dword_61F180 = a2;
        unk_61F184 = v19;
        PopShutdownButtonPressTime = 0;
        dword_61F7E4 = 0;
        PopSleepStats = 1;
      }
      PopDiagTracePowerTransitionEnd(v8);
    }
LABEL_79:
    PpmEndHighPerfRequest(2, v20);
    PopAcquirePolicyLock();
    return v8;
  }
  v8 = 0;
  if ( !dword_61EC18 )
  {
    if ( byte_61EC11 )
    {
      if ( (PopSimulate & 0x4000000) != 0 )
        PopSetSystemState(4, 7);
    }
    else
    {
      PopReleasePolicyLock();
      v8 = PopSetSystemAwayMode(1);
      PopAcquirePolicyLock();
    }
  }
  PopReleaseAwaymodeLock();
  return v8;
}
