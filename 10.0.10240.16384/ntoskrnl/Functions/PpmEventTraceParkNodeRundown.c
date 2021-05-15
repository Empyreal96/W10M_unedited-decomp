// PpmEventTraceParkNodeRundown 
 
int PpmEventTraceParkNodeRundown()
{
  __int64 v0; // kr00_8
  int result; // r0

  if ( PpmEtwRegistered )
  {
    v0 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PARK_NODE_RUNDOWN);
    if ( result )
      result = EtwWrite(v0, SHIDWORD(v0), (int)PPM_ETW_PARK_NODE_RUNDOWN, 0);
  }
  return result;
}
