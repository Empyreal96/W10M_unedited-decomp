// PopWdiTimerWorkerThread 
 
void PopWdiTimerWorkerThread()
{
  KeWaitForSingleObject((unsigned int)&PopWdiTimerMutex, 0, 0, 0, 0);
  PopDiagTraceSleepStudyStop();
  if ( PopWdiNewScenarioWaiting )
  {
    sub_50FAFC();
  }
  else
  {
    PopWdiTimerQueued = 0;
    KeReleaseMutant((unsigned int)&PopWdiTimerMutex, 1, 0, 0);
  }
}
