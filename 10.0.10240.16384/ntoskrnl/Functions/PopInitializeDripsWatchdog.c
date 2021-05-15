// PopInitializeDripsWatchdog 
 
int PopInitializeDripsWatchdog()
{
  char v0; // r5
  int result; // r0

  if ( PopPlatformAoAc )
  {
    v0 = PopDripsWatchdogAction;
    if ( PopPlatformAoAcOverride == -1 )
    {
      ExInitializeResourceLite((int)&byte_637480[24]);
      byte_637444 = v0;
      PopDripsWatchdog = PopDripsWatchdogTimeout;
      result = PopInitializeTimer(
                 &byte_637480[80],
                 (int)PopDripsWatchdogTimerCallbackRoutine,
                 (int)&PopDripsWatchdog,
                 (int)PopDripsWatchdogWorkerRoutine,
                 (int)&PopDripsWatchdog);
    }
    else
    {
      result = sub_966AC0();
    }
  }
  return result;
}
