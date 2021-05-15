// VfShutdownScheduleWatchdog 
 
int VfShutdownScheduleWatchdog()
{
  int result; // r0

  if ( ViVerifierEnabled )
    result = ViShutdownScheduleWatchdog();
  return result;
}
