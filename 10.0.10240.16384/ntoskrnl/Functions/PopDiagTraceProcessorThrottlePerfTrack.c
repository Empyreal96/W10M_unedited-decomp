// PopDiagTraceProcessorThrottlePerfTrack 
 
int __fastcall PopDiagTraceProcessorThrottlePerfTrack(int a1, int a2)
{
  int result; // r0
  __int16 v3; // [sp+10h] [bp-88h] BYREF
  int v4; // [sp+14h] [bp-84h] BYREF
  int v5[18]; // [sp+18h] [bp-80h] BYREF
  char var38[60]; // [sp+60h] [bp-38h] BYREF
  _DWORD vars8[2]; // [sp+A0h] [bp+8h] BYREF

  vars8[0] = a1;
  vars8[1] = a2;
  result = memmove((int)var38, (int)L"Processor 9999999999", 0x2Au);
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_PERFTRACK);
    if ( result )
    {
      result = RtlStringCchPrintfExW((int)var38, 21, 0, v5, 0, L"Processor %u");
      if ( result >= 0 )
      {
        v4 = 0;
        v5[2] = (int)vars8;
        v5[3] = 0;
        v5[4] = 4;
        v5[5] = 0;
        v5[6] = (int)&v4;
        v5[7] = 0;
        v5[8] = 4;
        v5[9] = 0;
        v5[10] = (int)&v3;
        v5[11] = 0;
        v5[12] = 2;
        v5[13] = 0;
        v5[14] = (int)var38;
        v5[15] = 0;
        v5[16] = 2 * (unsigned __int16)(21 - LOWORD(v5[0]));
        v5[17] = 0;
        v3 = 21 - LOWORD(v5[0]);
        result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_PERFTRACK, 0);
      }
    }
  }
  return result;
}
