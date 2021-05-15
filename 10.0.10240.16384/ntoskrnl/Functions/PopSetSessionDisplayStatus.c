// PopSetSessionDisplayStatus 
 
int PopSetSessionDisplayStatus(int a1, ...)
{
  int varg_r1; // [sp+24h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+24h] [bp+Ch]
  va_list varg_r2; // [sp+28h] [bp+10h] BYREF

  va_start(varg_r2, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r2, _DWORD);
  PopDiagTraceSessionState(POP_ETW_ADPM_SESSION_DISPLAY_STATE, a1, varg_r1);
  PopPrintEx(3);
  PopSetPowerSettingValue((int *)&GUID_SESSION_DISPLAY_STATUS, a1, 0, 4u, (int)varg_r1a);
  return PopSetPowerSettingValue((int *)&GUID_SESSION_DISPLAY_STATUS, a1, 1, 4u, (int)varg_r1a);
}
