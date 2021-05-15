// PopCoalescingActivate 
 
int __fastcall PopCoalescingActivate(int result)
{
  int v1; // r5
  int v2; // r3
  __int64 v3; // r0
  int v4; // r0
  int v5; // r1
  int v6; // r0

  v1 = result;
  if ( result )
  {
    if ( PopCoalescingState )
      return result;
    if ( PopCoalescingEnforced )
      v2 = PopEnforcedCoalescingSpindownTimeout;
    else
      v2 = PopDppeCoalescingSpindownTimeout;
    PopCurrentCoalescingSpindownTimeout = v2;
    LODWORD(v3) = KeQueryInterruptTime();
    PopCoalescingLastFlushTime = v3;
    PopCoalescingState = 1;
    v4 = PopCoalescingSetTimer();
  }
  else
  {
    if ( !PopCoalescingState )
      return result;
    PopCurrentCoalescingSpindownTimeout = 0;
    PopCoalescingState = 0;
    v6 = KeCancelTimer((int)&PopCoalescingTimer);
    v4 = PopCheckResiliencyScenarios(v6);
  }
  PopUpdateDiskIdleTimeoutSetting(v4);
  if ( v1 )
  {
    PopDiagTraceIoCoalescingOn(
      PopCurrentCoalescingSpindownTimeout,
      PopCoalescingTimerInterval,
      PopCoalescingFlushInterval,
      PopCoalescingEnforced == 0);
  }
  else
  {
    PopPrintEx(3);
    PopDiagTraceEventNoPayload((int)POP_ETW_IO_COALESCING_OFF);
  }
  if ( v1 )
    v5 = 1;
  else
    v5 = 2;
  return PoIssueCoalescingNotification(PopCoalescingRegistration, v5);
}
