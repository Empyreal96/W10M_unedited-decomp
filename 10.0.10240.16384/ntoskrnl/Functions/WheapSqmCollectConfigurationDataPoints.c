// WheapSqmCollectConfigurationDataPoints 
 
int WheapSqmCollectConfigurationDataPoints()
{
  int result; // r0

  result = WheapIsSqmLoggerRegistered();
  if ( result )
  {
    KeInitializeTimerEx(WheapSqmWaitTimer, 0);
    KeInitializeDpc((int)&WheapSqmWaitTimerDpc, (int)WheapSqmWaitDpcRoutine, 0);
    dword_619758 = (int)WheapSqmWaitWorkerRoutine;
    dword_61975C = 0;
    WheapSqmWaitWorkQueueItem = 0;
    result = WheapSqmWaitWorkerRoutine(0);
  }
  return result;
}
