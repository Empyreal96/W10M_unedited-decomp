// ViShutdownScheduleWatchdog 
 
int ViShutdownScheduleWatchdog()
{
  int v0; // r3
  int v1; // r3

  v0 = VfShutdownThread;
  __dmb(0xBu);
  if ( !v0 )
  {
    v1 = __mrc(15, 0, 13, 0, 3);
    __dmb(0xBu);
    VfShutdownThread = v1 & 0xFFFFFFC0;
  }
  KeInitializeDpc((int)&ViShutdownWatchdogDpc, (int)ViShutdownWatchdogExecuteDpc, 0);
  KeInitializeTimerEx(ViShutdownWatchdogTimer, 0);
  return KiSetTimerEx(
           (int)ViShutdownWatchdogTimer,
           (unsigned int)&ViShutdownWatchdogDpc,
           -6000000000i64,
           0,
           0,
           (int)&ViShutdownWatchdogDpc);
}
