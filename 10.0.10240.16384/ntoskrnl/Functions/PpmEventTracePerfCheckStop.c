// PpmEventTracePerfCheckStop 
 
void PpmEventTracePerfCheckStop()
{
  if ( PpmEtwRegistered )
  {
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_PERF_CHECK_STOP) )
      sub_5411D4();
  }
}
