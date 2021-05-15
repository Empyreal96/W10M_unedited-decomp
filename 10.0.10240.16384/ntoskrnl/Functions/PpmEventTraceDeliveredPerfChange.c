// PpmEventTraceDeliveredPerfChange 
 
int __fastcall PpmEventTraceDeliveredPerfChange(int result, int a2)
{
  int _54; // [sp+54h] [bp+8h]

  _54 = result;
  if ( PpmEtwRegistered )
  {
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_DELIVERED_PERF_CHANGE);
    if ( result )
      result = sub_522250();
  }
  return result;
}
