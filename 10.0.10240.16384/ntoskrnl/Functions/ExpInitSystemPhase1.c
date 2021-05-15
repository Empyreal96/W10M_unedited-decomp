// ExpInitSystemPhase1 
 
int __fastcall ExpInitSystemPhase1(int a1, int a2)
{
  int v2; // r4
  unsigned int v4; // r7
  int *v5; // r6
  int v6; // t1
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r0
  int v11; // r0

  v2 = 1;
  if ( (unsigned int)KeQueryMaximumProcessorCountEx(0xFFFFu, a2) <= 1 )
    return sub_96C570();
  ExpSpinCount = 128;
  ExpHostListLock = 0;
  off_9203A8 = &ExpHostList;
  ExpHostList = &ExpHostList;
  ExpKeyManipLock = 0;
  ExpPlatformBinaryLock = 0;
  if ( ExpWorkerInitialization() < 0 )
    v2 = 0;
  v4 = 0;
  if ( KeNumberProcessors_0 )
  {
    v5 = (int *)&KiProcessorBlock;
    do
    {
      v6 = *v5++;
      ExInitializeProcessor(v6, 0);
      ++v4;
    }
    while ( v4 < KeNumberProcessors_0 );
  }
  if ( !ExpEventInitialization() )
    v2 = 0;
  if ( !ExpMutantInitialization() )
    v2 = 0;
  if ( !ExpAeThresholdInitialization() )
    v2 = 0;
  if ( !ExpInitializeCallbacks() )
    v2 = 0;
  if ( !ExpSemaphoreInitialization() )
    v2 = 0;
  if ( !ExpTimerInitialization() )
    v2 = 0;
  if ( !ExpProfileInitialization() )
    v2 = 0;
  ExpUuidLock = 0;
  KeQuerySystemTime(&ExpUuidLastTimeAllocated);
  if ( ExpKeyedEventInitialization() < 0 )
    v2 = 0;
  if ( !ExpWnfAllocateDispatcher() || !ExpWnfInitServerSilo() )
    v2 = 0;
  if ( !ExpWin32Initialization() )
    v2 = 0;
  if ( ExpWorkerFactoryInitialization() < 0 )
    v2 = 0;
  if ( !ExpSaInitialize() )
    v2 = 0;
  v10 = ExpUpdateProductSuiteType(1, v7, v8, v9);
  v11 = ExpInitializePcw(v10);
  ExpInitializeSvm(v11);
  return v2;
}
