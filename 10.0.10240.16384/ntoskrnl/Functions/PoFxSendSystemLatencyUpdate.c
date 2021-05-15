// PoFxSendSystemLatencyUpdate 
 
int PoFxSendSystemLatencyUpdate()
{
  int result; // r0
  int v1; // r4

  if ( byte_61EA54
    && ((result = PopDeepSleepEnabled()) == 0 && PopPdcIdleResiliency || (result = PopCheckForDeepSleep()) != 0) )
  {
    v1 = dword_68156C;
  }
  else
  {
    result = PopFxGetLatencyLimitWithoutResiliency();
    v1 = result;
  }
  if ( v1 != PopFxSystemLatencyLimit )
  {
    if ( PpmGetExitSamplingCountdown() )
    {
      result = sub_529994();
    }
    else
    {
      PopDiagTraceSystemLatencyUpdate(0, v1);
      PopFxSystemLatencyHint = v1;
      PoFxSystemLatencyNotify(v1, 0);
      result = PpmIdleUsingStateSelection();
      __dmb(0xBu);
      PopFxSystemLatencyLimit = v1;
    }
  }
  return result;
}
