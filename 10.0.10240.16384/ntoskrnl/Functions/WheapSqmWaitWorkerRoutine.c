// WheapSqmWaitWorkerRoutine 
 
void __spoils<R2,R3,R12> WheapSqmWaitWorkerRoutine()
{
  __int64 v0; // kr00_8
  __int64 v1; // r2
  int v2; // r0

  if ( WheapIsSqmLoggerRunning() )
  {
    WheapSqmCollectWheaPolicyTelemetry();
    WheapSqmCollectPshedPluginTelemetry();
    WheapSqmCollectWheaOscTelemetry();
  }
  else if ( (unsigned int)++WheapSqmWaitRetryCount <= 7 )
  {
    v0 = WheapSqmWaitTimeout;
    v1 = -WheapSqmWaitTimeout;
    v2 = (unsigned __int64)(unsigned int)WheapSqmWaitTimeout >> 31;
    LODWORD(WheapSqmWaitTimeout) = 2 * WheapSqmWaitTimeout;
    HIDWORD(WheapSqmWaitTimeout) = v2 | (2 * HIDWORD(v0));
    KiSetTimerEx((int)WheapSqmWaitTimer, 0, v1, 0, 0, (int)&WheapSqmWaitTimerDpc);
  }
}
