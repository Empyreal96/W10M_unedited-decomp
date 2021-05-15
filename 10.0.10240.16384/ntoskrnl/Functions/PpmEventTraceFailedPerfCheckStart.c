// PpmEventTraceFailedPerfCheckStart 
 
int __fastcall PpmEventTraceFailedPerfCheckStart(int result, int a2)
{
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( PpmEtwRegistered )
  {
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_PERF_CHECK_FAILED_START);
    if ( result )
      result = sub_527140();
  }
  return result;
}
