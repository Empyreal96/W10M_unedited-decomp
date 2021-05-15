// PopCheckResiliencyScenarios 
 
void PopCheckResiliencyScenarios()
{
  int v0; // r7
  int v1; // r8
  int v2; // r5
  int v3; // r6
  int v4; // r4
  int v5; // r0
  int v6; // r1
  int v7; // r2
  BOOL v8; // r3

  v0 = PopCurrentCoalescingSpindownTimeout != 0;
  if ( !PopDeepSleepEnforced && !PopCoalescingEnforced )
  {
    v1 = (unsigned __int8)byte_61EA54;
    if ( byte_61EA54 )
    {
      v2 = (unsigned __int8)PopPdcIdleResiliency;
      v3 = (unsigned __int8)PopPdcIoCoalescing;
      if ( PopDeepSleepEnabled() )
      {
        sub_7F35EC();
        return;
      }
    }
    else
    {
      v2 = 0;
      v8 = !dword_61E824 && !PopConsoleDisplayState && byte_61EC61 != 3;
      v3 = v8;
    }
    PopDeepSleepEnabled();
    v4 = v3 && PopDppeCoalescingSpindownTimeout;
    v5 = PopDeepSleepPhaseEngaged();
    if ( v7 == v5 )
    {
      if ( v1 && !v6 )
      {
        PpmAcquireLock(&PopFxSystemLatencyLock);
        if ( (unsigned __int8)PopIdleResiliencyIsEngagedWithoutDeepSleep != v2 )
        {
          PopIdleResiliencyIsEngagedWithoutDeepSleep = v2;
          PoFxSendSystemLatencyUpdate();
        }
        PpmReleaseLock((int *)&PopFxSystemLatencyLock);
      }
    }
    else
    {
      PopControlDeepSleep(v7);
    }
    if ( v4 != v0 )
      PopCoalescingActivate(v4);
  }
}
