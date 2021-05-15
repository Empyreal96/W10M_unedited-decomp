// PopDiagTraceProcessorThrottleDurationPerfTrack 
 
int __fastcall PopDiagTraceProcessorThrottleDurationPerfTrack(int a1, int a2)
{
  int result; // r0
  __int16 v3; // [sp+10h] [bp-70h] BYREF
  int v4[13]; // [sp+14h] [bp-6Ch] BYREF
  char var38[60]; // [sp+48h] [bp-38h] BYREF
  _DWORD vars8[2]; // [sp+88h] [bp+8h] BYREF

  vars8[0] = a1;
  vars8[1] = a2;
  result = memmove((int)var38, (int)L"Processor 9999999999", 0x2Au);
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_DURATION_PERFTRACK);
    if ( result )
    {
      result = RtlStringCchPrintfExW((int)var38, 21, 0, v4, 0, L"Processor %u");
      if ( result >= 0 )
      {
        v4[1] = (int)vars8;
        v4[2] = 0;
        v4[3] = 4;
        v4[4] = 0;
        v4[5] = (int)&v3;
        v4[6] = 0;
        v4[7] = 2;
        v4[8] = 0;
        v4[9] = (int)var38;
        v4[10] = 0;
        v4[11] = 2 * (unsigned __int16)(21 - LOWORD(v4[0]));
        v4[12] = 0;
        v3 = 21 - LOWORD(v4[0]);
        result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_DURATION_PERFTRACK, 0);
      }
    }
  }
  return result;
}
