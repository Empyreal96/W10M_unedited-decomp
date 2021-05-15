// PpmEventTracePpmProfileStatusRundown 
 
void PpmEventTracePpmProfileStatusRundown()
{
  __int64 v0; // kr00_8

  if ( PpmEtwRegistered )
  {
    v0 = *(_QWORD *)&PpmEtwHandle;
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PROCESSOR_PROFILE_STATUS_RUNDOWN) )
      EtwWrite(v0, SHIDWORD(v0), (int)PPM_ETW_PROCESSOR_PROFILE_STATUS_RUNDOWN, 0);
  }
}
