// KiResetClockInterval 
 
int KiResetClockInterval()
{
  int v0; // r0

  v0 = RtlRbRemoveNode(&KiClockIntervalRequests, KiHighResolutionTimerClockIntervalRequest);
  byte_624E2C = 0;
  return KiSetClockIntervalToMinimumRequested(v0);
}
