// PopDiagTraceDevicesSuspend 
 
int PopDiagTraceDevicesSuspend(int result, ...)
{
  int v1; // r6
  __int64 v2; // kr00_8
  int var48[19]; // [sp+8h] [bp-48h] BYREF
  int varg_r1; // [sp+5Ch] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+5Ch] [bp+Ch]
  va_list varg_r2; // [sp+60h] [bp+10h] BYREF

  va_start(varg_r2, result);
  va_start(varg_r1a, result);
  varg_r1 = va_arg(varg_r2, _DWORD);
  v1 = result;
  if ( PopDiagHandleRegistered )
  {
    v2 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICESSUSPEND);
    if ( result )
    {
      var48[2] = (int)var48;
      var48[3] = 0;
      var48[4] = 4;
      var48[5] = 0;
      va_copy((va_list)&var48[6], varg_r1a);
      var48[7] = 0;
      var48[8] = 4;
      var48[9] = 0;
      va_copy((va_list)&var48[10], varg_r2);
      var48[11] = 0;
      var48[12] = 4;
      var48[13] = 0;
      var48[0] = v1;
      result = EtwWrite(v2, SHIDWORD(v2), (int)POP_ETW_EVENT_DEVICESSUSPEND, 0);
    }
  }
  return result;
}
