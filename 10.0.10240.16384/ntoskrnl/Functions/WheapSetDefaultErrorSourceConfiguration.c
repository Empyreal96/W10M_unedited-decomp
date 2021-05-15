// WheapSetDefaultErrorSourceConfiguration 
 
int (*WheapSetDefaultErrorSourceConfiguration())()
{
  int *v0; // r3
  int (*result)(); // r0
  int v2; // r2

  v0 = WheapSourceConfiguration;
  result = xHalPciEarlyRestore;
  v2 = 12;
  do
  {
    *v0 = 0;
    __dmb(0xBu);
    v0[3] = (int)xHalTimerWatchdogStop;
    __dmb(0xBu);
    v0[4] = (int)xHalPciEarlyRestore;
    __dmb(0xBu);
    v0[5] = (int)WheapDefaultErrSrcCreateRecord;
    __dmb(0xBu);
    v0[6] = (int)xHalTimerWatchdogStop;
    v0 += 7;
    --v2;
  }
  while ( v2 );
  WheapConfigTableLock = 0;
  return result;
}
