// KeSuspendClockTimerSafe 
 
int KeSuspendClockTimerSafe()
{
  BOOL v0; // r0
  unsigned int v1; // r0
  int v2; // r4

  v0 = KeAreInterruptsEnabled();
  if ( v0 )
    v1 = KeGetCurrentIrql(v0);
  else
    v1 = 15;
  if ( v1 >= 0xD )
    return KiSuspendClockTimer();
  v2 = KfRaiseIrql(13);
  KiSuspendClockTimer();
  return KfLowerIrql(v2);
}
