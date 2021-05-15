// PpmEventTraceExpectedUtility 
 
void PpmEventTraceExpectedUtility()
{
  if ( PpmEtwRegistered )
  {
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_EXPECTED_UTILITY) )
      sub_53FC0C();
  }
}
