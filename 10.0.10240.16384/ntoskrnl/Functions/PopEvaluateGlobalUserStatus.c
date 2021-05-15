// PopEvaluateGlobalUserStatus 
 
void __fastcall PopEvaluateGlobalUserStatus(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // [sp+0h] [bp-8h] BYREF

  v5 = a4;
  if ( PopUserPresentOverrideCount || !PopMaximumConnectionSessions || RtlNumberOfSetBits(&PopConnectionBitmap) )
    v4 = 0;
  else
    v4 = 2;
  if ( v4 != PopGlobalUserPresenceState )
  {
    v5 = v4;
    PopGlobalUserPresenceState = v4;
    PopPrintUserActivityPresence(v4);
    PopPrintEx(3);
    PopDiagTraceSessionState(POP_ETW_ADPM_GLOBAL_INPUT_STATE, -1, v4);
    PopSetPowerSettingValueAcDc(&GUID_GLOBAL_USER_PRESENCE, 4, &v5);
  }
}
