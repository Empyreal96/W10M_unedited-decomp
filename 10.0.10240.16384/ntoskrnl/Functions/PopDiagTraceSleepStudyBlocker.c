// PopDiagTraceSleepStudyBlocker 
 
int PopDiagTraceSleepStudyBlocker()
{
  __int64 v0; // kr00_8
  int result; // r0

  if ( PopDiagSleepStudyHandleRegistered )
  {
    v0 = *(_QWORD *)&PopDiagSleepStudyHandle;
    result = EtwEventEnabled(PopDiagSleepStudyHandle, unk_61E24C, (int)SLEEPSTUDY_EVT_SCENARIO_BLOCKER);
    if ( result )
      result = EtwWrite(v0, SHIDWORD(v0), (int)SLEEPSTUDY_EVT_SCENARIO_BLOCKER, 0);
  }
  return result;
}
