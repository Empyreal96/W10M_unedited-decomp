// PpmClearExitLatencySamplingPercentage 
 
int PpmClearExitLatencySamplingPercentage()
{
  PpmAcquireLock(&PopFxSystemLatencyLock);
  PpmExitLatencySamplingPercentageSet = 0;
  PpmExitLatencySamplingPercentage = 0;
  __dmb(0xFu);
  KeFlushProcessWriteBuffers(1);
  return PpmReleaseLock((int *)&PopFxSystemLatencyLock);
}
