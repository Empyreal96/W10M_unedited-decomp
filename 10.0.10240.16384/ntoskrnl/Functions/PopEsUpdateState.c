// PopEsUpdateState 
 
unsigned int __fastcall PopEsUpdateState(int a1)
{
  int v2; // r1
  int v3; // r9
  unsigned int result; // r0
  int v5; // r5
  int v6; // r6
  unsigned int v7; // lr
  unsigned int v8; // r2
  unsigned int v9; // r8
  unsigned __int64 v10; // kr08_8
  unsigned __int64 v11; // kr10_8
  int v12; // r8
  unsigned __int64 v13; // kr18_8
  int v14; // lr
  int v15; // [sp+18h] [bp-50h]
  char v16; // [sp+28h] [bp-40h] BYREF
  unsigned __int8 v17; // [sp+29h] [bp-3Fh]
  unsigned int v18; // [sp+30h] [bp-38h]
  int v19; // [sp+34h] [bp-34h]

  PopCurrentPowerState(&v16);
  v2 = PopEsState;
  v3 = v19;
  result = v17;
  v5 = 0;
  v6 = 0;
  if ( PopEsMode == 1 )
    return sub_7F2968(v17);
  if ( PopEsMode == 2 )
  {
    if ( dword_61EC50 )
    {
      if ( v17 )
      {
        result = v18;
        if ( v18 )
        {
          result = 100 * v19 / v18;
          v2 = PopEsState;
          if ( result <= dword_61EC50 )
          {
            v5 = 1;
            v6 = 2;
          }
        }
      }
    }
  }
  if ( a1 || v5 != v2 || v6 != PopEsReason )
  {
    PopDiagTraceEsState((int)&PopEsState, PopEsReason);
    v7 = MEMORY[0xFFFF9004];
    while ( 1 )
    {
      v8 = MEMORY[0xFFFF9324];
      __dmb(0xBu);
      v9 = MEMORY[0xFFFF9320];
      __dmb(0xBu);
      if ( v8 == MEMORY[0xFFFF9328] )
        break;
      __dmb(0xAu);
      __yield();
    }
    v10 = v8 * (unsigned __int64)v7;
    v11 = v9 * (unsigned __int64)v7;
    v12 = 0;
    v13 = (v11 >> 24) + (v10 << 8);
    v15 = HIDWORD(v13);
    v14 = v13;
    if ( v17 )
      v12 = v3;
    result = (unsigned int)&PopEsLastBatteryCharge;
    if ( PopEsLastStateChangeTimeStamp )
    {
      PopTraceEsState(
        PopEsReason,
        (int)&PopEsReason,
        v13 - PopEsLastStateChangeTimeStamp,
        (v13 - PopEsLastStateChangeTimeStamp) >> 32,
        v12 - PopEsLastBatteryCharge,
        PopEsAcOnline,
        PopEsMode,
        PopEsLastBatteryThreshold,
        PopEsLastUserAwaySetting);
      v14 = (v11 >> 24) + ((_DWORD)v10 << 8);
      result = (unsigned int)&PopEsLastBatteryCharge;
    }
    LODWORD(PopEsLastStateChangeTimeStamp) = v14;
    HIDWORD(PopEsLastStateChangeTimeStamp) = HIDWORD(v13);
    PopEsLastBatteryCharge = v12;
    PopEsAcOnline = v16;
    PopEsLastBatteryThreshold = dword_61EC50;
    PopEsLastUserAwaySetting = byte_61EC54;
    if ( v5 != PopEsState )
    {
      PopEsState = v5;
      ZwUpdateWnfStateData();
      result = PopSetPowerSettingValueAcDc((int *)&GUID_POWER_SAVING_STATUS, 4u, (int)&PopEsState);
    }
    PopEsReason = v6;
  }
  return result;
}
