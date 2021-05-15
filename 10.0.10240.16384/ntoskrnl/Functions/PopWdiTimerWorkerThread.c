// PopWdiTimerWorkerThread 
 
int PopWdiTimerWorkerThread()
{
  int v0; // r0
  int v1; // r0

  v0 = KeWaitForSingleObject(&PopWdiTimerMutex, 0, 0);
  v1 = PopDiagTraceSleepStudyStop(v0);
  if ( PopWdiNewScenarioWaiting )
    return sub_50FAFC(v1);
  PopWdiTimerQueued = 0;
  return KeReleaseMutant(&PopWdiTimerMutex, 1);
}
