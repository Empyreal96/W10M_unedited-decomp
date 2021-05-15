// PoUserShutdownInitiated 
 
void PoUserShutdownInitiated()
{
  int v0; // r0
  int v1; // r4

  if ( dword_61EAA4 )
  {
    PopAcquirePolicyLock();
    if ( PopUserShutdownInProgress )
    {
      PopReleasePolicyLock();
    }
    else
    {
      PopUserShutdownInProgress = 1;
      if ( !byte_61F1C4 )
      {
        dword_61F1D8 = (int)PopUserShutdownDelayWorkerCallback;
        dword_61F1DC = 0;
        PopUserShutdownDelayWorker = 0;
        KeInitializeTimerEx(PopUserShutdownDelayTimer, 0);
        KeInitializeDpc((int)&PopUserShutdownDelayDpc, (int)PopUserShutdownDelayDpcCallback, 0);
        byte_61F1C4 = 1;
      }
      v0 = PopReleasePolicyLock();
      v1 = dword_61EAA4(v0);
      KiSetTimerEx((int)PopUserShutdownDelayTimer, 0, -900000000i64, 0, 0, (int)&PopUserShutdownDelayDpc);
      if ( v1 )
        PpmBeginHighPerfRequest();
    }
  }
}
