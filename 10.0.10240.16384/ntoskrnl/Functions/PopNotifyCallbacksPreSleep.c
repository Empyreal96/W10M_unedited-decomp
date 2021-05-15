// PopNotifyCallbacksPreSleep 
 
int PopNotifyCallbacksPreSleep()
{
  PopDiagTracePreSleepCallbacks(1);
  ExNotifyCallback(ExCbPowerState, 3, 0);
  return PopDiagTracePreSleepCallbacks(0);
}
