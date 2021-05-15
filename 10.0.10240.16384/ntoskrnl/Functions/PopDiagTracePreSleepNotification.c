// PopDiagTracePreSleepNotification 
 
int __fastcall PopDiagTracePreSleepNotification(int result, int a2, int a3, int a4)
{
  __int64 v5; // kr00_8
  int var58[23]; // [sp+8h] [bp-58h] BYREF
  int varg_r0; // [sp+68h] [bp+8h] BYREF
  int varg_r1[2]; // [sp+6Ch] [bp+Ch] BYREF
  int varg_r3; // [sp+74h] [bp+14h] BYREF

  varg_r0 = result;
  varg_r1[0] = a2;
  varg_r1[1] = a3;
  varg_r3 = a4;
  if ( PopDiagHandleRegistered )
  {
    v5 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_PRESLEEP_NOTIFICATION2);
    if ( result )
    {
      var58[2] = (int)&varg_r0;
      var58[3] = 0;
      var58[4] = 4;
      var58[5] = 0;
      var58[6] = (int)varg_r1;
      var58[7] = 0;
      var58[8] = 4;
      var58[9] = 0;
      var58[10] = (int)var58;
      var58[11] = 0;
      var58[12] = 4;
      var58[13] = 0;
      var58[14] = (int)&varg_r3;
      var58[15] = 0;
      var58[16] = 4;
      var58[17] = 0;
      var58[0] = a3;
      result = EtwWrite(v5, SHIDWORD(v5), (int)POP_ETW_EVENT_PRESLEEP_NOTIFICATION2, 0);
    }
  }
  return result;
}
