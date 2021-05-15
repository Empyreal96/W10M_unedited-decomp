// PpmSetExitLatencySamplingPercentage 
 
int __fastcall PpmSetExitLatencySamplingPercentage(int *a1)
{
  int v2; // r4
  int v3; // r4
  int v4; // r3

  v2 = 0;
  PpmAcquireLock(&PopFxSystemLatencyLock);
  if ( PpmExitLatencySamplingPercentageSet )
  {
    v3 = -1073741823;
  }
  else
  {
    v4 = *a1;
    if ( (unsigned int)*a1 > 0x64 )
      v4 = 100;
    if ( !v4 || !PpmExitLatencySamplingPercentage )
      v2 = 1;
    PpmExitLatencySamplingPercentageSet = 1;
    PpmExitLatencySamplingPercentage = v4;
    if ( v2 )
    {
      __dmb(0xFu);
      KeFlushProcessWriteBuffers(1);
    }
    v3 = 0;
  }
  PpmReleaseLock((int *)&PopFxSystemLatencyLock);
  return v3;
}
