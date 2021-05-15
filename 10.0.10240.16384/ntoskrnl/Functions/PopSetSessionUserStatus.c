// PopSetSessionUserStatus 
 
int __fastcall PopSetSessionUserStatus(int a1, int a2, int a3, int a4)
{
  int v7; // [sp+0h] [bp-18h]
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  if ( PopConsoleContext == a1 && a1 != -1 )
    dword_61DE60 = a2;
  v8[0] = a2;
  PopPrintUserActivityPresence(a2);
  PopPrintEx(3);
  PopDiagTraceSessionState(POP_ETW_ADPM_SESSION_INPUT_STATE, a1, a2);
  PopSetPowerSettingValue((int *)&GUID_SESSION_USER_PRESENCE, a1, 0, 4u, (int)v8);
  PopSetPowerSettingValue((int *)&GUID_SESSION_USER_PRESENCE, a1, 1, 4u, (int)v8);
  PopSetGlobalUserStatus(a1, a2);
  return v7;
}
