// PopDiagNextSleepStudySession 
 
int __fastcall PopDiagNextSleepStudySession(int result, int a2)
{
  GUID *v3; // r5
  int v4; // r0
  GUID *v5; // r1
  char v6; // r2

  v3 = (GUID *)result;
  if ( !PopSleepStudyDisabled )
  {
    v4 = KeWaitForSingleObject((unsigned int)&PopWdiTimerMutex, 0, 0, 0, 0);
    v5 = (GUID *)PopWdiCurrentScenario;
    if ( (GUID *)PopWdiCurrentScenario == &NullGuid && v3 == &NullGuid )
      return sub_7F2124(v4);
    PopWdiCurrentScenario = (int)v3;
    ++PopWdiCurrentScenarioInstanceId;
    if ( v5 == &NullGuid )
    {
      if ( !PopWdiTimerQueued )
      {
        PopDiagTraceSleepStudyStart(v4);
LABEL_7:
        KeReleaseMutex((int)&PopWdiTimerMutex);
        return ZwUpdateWnfStateData();
      }
      v6 = 1;
    }
    else
    {
      if ( !PopWdiTimerQueued )
      {
        if ( a2 )
          memmove((int)&PopWdiScenarioStopEventData, a2, 0x88u);
        KiSetTimerEx(
          (int)&PopWdiTimer,
          (unsigned int)&PopWdiTimerDpc,
          PopWdiTimerTimeoutValue,
          0,
          0,
          (int)&PopWdiTimerDpc);
        PopWdiTimerQueued = 1;
        goto LABEL_7;
      }
      v6 = 0;
    }
    PopWdiNewScenarioWaiting = v6;
    goto LABEL_7;
  }
  return result;
}
