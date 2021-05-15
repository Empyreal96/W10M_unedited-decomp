// ExpRefreshTimeZoneInformation 
 
int ExpRefreshTimeZoneInformation()
{
  __int64 v1; // kr00_8
  int v2; // r9
  int v3; // r8
  int v4; // r7
  int v5; // r3
  int v6; // r6
  int v7; // r6
  unsigned int v8; // r2
  int v9; // r2
  int v10; // r2
  int v11; // r2
  unsigned int v12; // r2
  __int64 v13; // [sp+10h] [bp-220h] BYREF
  __int64 v14; // [sp+18h] [bp-218h] BYREF
  __int64 v15; // [sp+20h] [bp-210h] BYREF
  int v16; // [sp+28h] [bp-208h]
  int v17; // [sp+2Ch] [bp-204h]
  int v18; // [sp+30h] [bp-200h]
  int v19; // [sp+34h] [bp-1FCh]
  __int64 v20; // [sp+38h] [bp-1F8h] BYREF
  __int64 v21; // [sp+40h] [bp-1F0h] BYREF
  __int64 v22; // [sp+48h] [bp-1E8h] BYREF
  __int16 v23[8]; // [sp+50h] [bp-1E0h] BYREF
  int v24[17]; // [sp+60h] [bp-1D0h] BYREF
  char v25[2]; // [sp+A4h] [bp-18Ch] BYREF
  __int16 v26; // [sp+A6h] [bp-18Ah]
  int v27; // [sp+B4h] [bp-17Ch]
  char v28[2]; // [sp+F8h] [bp-138h] BYREF
  __int16 v29; // [sp+FAh] [bp-136h]
  int v30; // [sp+108h] [bp-128h]
  unsigned __int16 v31; // [sp+10Ch] [bp-124h]
  char v32; // [sp+20Ch] [bp-24h]

  if ( !dword_61A2E8 )
  {
    ExInitializeTimeRefresh();
    KeInitializeDpc((int)&ExpTimeZoneDpc, (int)ExpTimeZoneDpcRoutine, (int)&ExpOkToTimeZoneRefresh);
    dword_61A2E8 = (int)ExpTimeZoneWork;
    dword_61A2EC = 0;
    ExpTimeZoneWorkItem = 0;
    KeInitializeTimerEx(ExpTimeZoneTimer, 0);
    KeInitializeDpc((int)&ExpNextYearDpc, (int)ExpNextYearDpcRoutine, (int)&ExpOkToTimeZoneRefresh);
    dword_61A328 = (int)ExpTimeZoneWork;
    dword_61A32C = 0;
    ExpNextYearWorkItem = 0;
    KeInitializeTimerEx(ExpNextYearTimer, 0);
    KeInitializeDpc((int)&ExpCenturyDpc, (int)ExpCenturyDpcRoutine, (int)&ExpOkToTimeZoneRefresh);
    dword_61A2D8 = (int)ExpTimeZoneWork;
    dword_61A2DC = 0;
    ExpCenturyWorkItem = 0;
    KeInitializeTimerEx(ExpCenturyTimer, 0);
    ExpNextCenturyTimeFieldsInLocalTime = 0x10000;
    ExpNextYearTimeFieldsInLocalTime = 0x10000;
    dword_92758C = 1;
    dword_9275A4 = 1;
    dword_927590 = 0;
    dword_9275A8 = 0;
    dword_927594 = 1;
    dword_9275AC = 1;
  }
  if ( RtlpQueryTimeZoneInformationWorker((int)v24, 0x1B0u) >= 0 )
  {
    KeQuerySystemTime(&v20);
    v19 = v20;
    v1 = v20 - ExpTimeZoneBias;
    v18 = HIDWORD(v20);
    v14 = v20 - ExpTimeZoneBias;
    if ( !v32 )
    {
      if ( v31 )
      {
        RtlTimeToTimeFields((int)&v14, v23, SHIDWORD(v20), v31);
        if ( RtlpCheckDynamicTimeZoneInformation(v24, v23[0]) )
          RtlpSetTimeZoneInformationWorker(v24, 432);
      }
    }
    v2 = v24[0];
    if ( !v26 || !v29 )
    {
      KeCancelTimer((int)ExpTimeZoneTimer);
      v6 = 0;
      v4 = 0;
      v13 = 0i64;
      v3 = 0;
LABEL_40:
      ExpCurrentTimeZoneId = v6;
      if ( ExpLastTimeZoneBias != v2 )
      {
        v17 = -1;
        v16 &= 0xFFC000u;
        ZwUpdateWnfStateData();
        v6 = ExpCurrentTimeZoneId;
      }
      ExpLastTimeZoneBias = v2;
      ExpTimeZoneBias = 60 * v2 * (__int64)(int)dword_989680;
      memmove((int)&ExpTimeZoneInformation, (int)v24, 0x1B0u);
      ExpSystemIsInCmosMode = 0;
      MEMORY[0xFFFF9240] = v6;
      RtlTimeToTimeFields((int)&v14, v23, 0, -28096);
      if ( v4 | v3 )
      {
        ExLocalTimeToSystemTime(&v13, &ExpNextSystemCutoverInUTC);
        KiSetTimerEx(
          (int)ExpTimeZoneTimer,
          (unsigned int)&ExpTimeZoneDpc,
          *(__int64 *)&ExpNextSystemCutoverInUTC,
          0,
          0,
          (int)&ExpTimeZoneDpc);
      }
      v7 = v23[0];
      LOWORD(ExpNextCenturyTimeFieldsInLocalTime) = 100 * (v23[0] / 100 + 1);
      RtlTimeFieldsToTime((__int16 *)&ExpNextCenturyTimeFieldsInLocalTime, &v15);
      ExLocalTimeToSystemTime(&v15, &ExpNextCenturyTimeInUTC);
      KiSetTimerEx(
        (int)ExpCenturyTimer,
        (unsigned int)&ExpCenturyDpc,
        ExpNextCenturyTimeInUTC,
        0,
        0,
        (int)&ExpCenturyDpc);
      LOWORD(ExpNextYearTimeFieldsInLocalTime) = v7 + 1;
      RtlTimeFieldsToTime((__int16 *)&ExpNextYearTimeFieldsInLocalTime, &v15);
      ExLocalTimeToSystemTime(&v15, &ExpNextYearTimeInUTC);
      KiSetTimerEx(
        (int)ExpNextYearTimer,
        (unsigned int)&ExpNextYearDpc,
        ExpNextYearTimeInUTC,
        0,
        0,
        (int)&ExpNextYearDpc);
      __dmb(0xBu);
      do
        v8 = __ldrex((unsigned int *)0xFFFF925C);
      while ( __strex(v8 + 1, (unsigned int *)0xFFFF925C) );
      __dmb(0xBu);
      v9 = HIDWORD(ExpTimeZoneBias);
      __dmb(0xBu);
      MEMORY[0xFFFF9028] = v9;
      v10 = ExpTimeZoneBias;
      __dmb(0xBu);
      MEMORY[0xFFFF9020] = v10;
      v11 = HIDWORD(ExpTimeZoneBias);
      __dmb(0xBu);
      MEMORY[0xFFFF9024] = v11;
      MEMORY[0xFFFF93C8] = v19;
      MEMORY[0xFFFF93CC] = v18;
      if ( v4 | v3 )
      {
        MEMORY[0xFFFF93D0] = ExpNextSystemCutoverInUTC;
        MEMORY[0xFFFF93D4] = dword_927584;
      }
      else
      {
        MEMORY[0xFFFF93D0] = ExpNextYearTimeInUTC - 10000;
      }
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)0xFFFF925C);
      while ( __strex(v12 + 1, (unsigned int *)0xFFFF925C) );
      __dmb(0xBu);
      if ( !ExpRealTimeIsUniversal )
        RtlSetActiveTimeBias(ExpLastTimeZoneBias);
      if ( v7 != ExpLastDynamicTimeZoneYear && RtlpUpdateDynamicTimeZones(v7) )
        ExpLastDynamicTimeZoneYear = v7;
      JUMPOUT(0x790138);
    }
    if ( !RtlCutoverTimeToSystemTime(v25, &v21, &v14) || !RtlCutoverTimeToSystemTime(v28, &v22, &v14) )
      return sub_80B97C();
    if ( v1 >= v22 && v1 >= v21 )
    {
      v4 = 0;
      v13 = 0i64;
      v3 = 0;
      if ( v21 <= v22 )
        goto LABEL_19;
    }
    else
    {
      if ( v22 >= v21 )
      {
        if ( v1 < v21 || v1 >= v22 )
          goto LABEL_18;
      }
      else if ( v1 >= v22 && v1 < v21 )
      {
LABEL_18:
        v13 = v21;
        v3 = HIDWORD(v21);
        v4 = v21;
LABEL_19:
        v5 = v30;
        v6 = 2;
LABEL_20:
        v2 += v5;
        goto LABEL_40;
      }
      v13 = v22;
      v3 = HIDWORD(v22);
      v4 = v22;
    }
    v5 = v27;
    v6 = 1;
    goto LABEL_20;
  }
  return sub_80B97C();
}
