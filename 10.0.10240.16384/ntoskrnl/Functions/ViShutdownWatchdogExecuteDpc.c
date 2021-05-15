// ViShutdownWatchdogExecuteDpc 
 
int ViShutdownWatchdogExecuteDpc()
{
  unsigned int v0; // r1
  unsigned int v1; // r0
  int v2; // r2
  int v3; // r2

  v0 = ++ViShutdownTimeoutCount;
  if ( VfZeroAllPagesRunning != 1 || v0 >= 4 )
  {
    if ( !EtwpStopTraceCount || EtwpStopTraceCount == ViEtwLastStopTraceCount )
    {
      if ( v0 <= 1 )
      {
        if ( KdDebuggerEnabled && !KdDebuggerNotPresent )
        {
          v2 = VfShutdownThread;
          __dmb(0xBu);
          VfErrorStoreTriageInformation(196, 277, v2, 0, 0);
          VfUtilDbgPrint((int)"\n"
                              "Driver Verifier detected that this system didn't finish shutting down\n"
                              "in more than 20 minutes. To display information about the thread that is\n"
                              "responsible for shutting down, use these debugger commands:\n"
                              "\n"
                              "dp nt!VfShutdownThread l1;!thread @$p\n"
                              "\n");
          __debugbreak();
        }
        v3 = VfShutdownThread;
        __dmb(0xBu);
        VerifierBugCheckIfAppropriate(196, 277, v3, 0, 0);
      }
      else
      {
        __dmb(0xBu);
        do
          v1 = __ldrex((unsigned int *)&MmVerifierData);
        while ( __strex(v1 & 0xFFFFFFFD, (unsigned int *)&MmVerifierData) );
        __dmb(0xBu);
      }
    }
    else
    {
      ViEtwLastStopTraceCount = EtwpStopTraceCount;
    }
  }
  return ViShutdownScheduleWatchdog();
}
