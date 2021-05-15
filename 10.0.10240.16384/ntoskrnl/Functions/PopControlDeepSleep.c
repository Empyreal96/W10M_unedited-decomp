// PopControlDeepSleep 
 
int __fastcall PopControlDeepSleep(int a1, int a2)
{
  char v2; // r5
  BOOL v3; // r4

  v2 = a1;
  v3 = PopDeepSleepEnforced != 0;
  if ( a1 )
  {
    if ( !KeMaximumIncrement )
      __brkdiv0();
    PopDiagTraceIdleResiliencyStart(0x1Eu / KeMaximumIncrement, 0x1Eu % KeMaximumIncrement, v3 | 2);
  }
  else
  {
    PopDiagTraceIdleResiliencyEnd(0, a2, v3 | 2);
  }
  PpmAcquireLock(&PopFxSystemLatencyLock);
  PopDeepSleepIsEngaged = v2;
  PoFxSendSystemLatencyUpdate();
  return PpmReleaseLock((int *)&PopFxSystemLatencyLock);
}
