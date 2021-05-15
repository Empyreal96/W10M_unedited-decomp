// PpmEventTraceLatencySensitivityHint 
 
int __fastcall PpmEventTraceLatencySensitivityHint(int result, int a2)
{
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( PpmEtwRegistered )
  {
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_LATENCY_SENSITIVITY_HINT);
    if ( result )
      result = sub_525AD0();
  }
  return result;
}
