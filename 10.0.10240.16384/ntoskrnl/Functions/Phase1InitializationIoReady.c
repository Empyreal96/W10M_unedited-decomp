// Phase1InitializationIoReady 
 
_DWORD *__fastcall Phase1InitializationIoReady(int a1, int a2, __int64 a3)
{
  int v5; // r0
  int v6; // r2
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r1
  unsigned int v11; // r6
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  int v17; // r1
  int v18; // r2

  CmpRegisterTraceLoggingProvider(a1, a3);
  if ( EmInitSystem(1, a1) < 0 )
    sub_967028();
  TmInitSystemPhase2();
  InbvSetProgressBarSubset();
  if ( InitSafeBootMode )
    InitSafeBoot(a2);
  v5 = MmInitSystem(2, a1);
  sub_963EC8(v5);
  if ( !PoInitSystem(3, a1, v6) )
    KeBugCheck(160);
  v7 = KeInitializeClock(2, a1);
  v8 = sub_95CAEC(v7);
  if ( !PspInitPhase2(v8) )
    KeBugCheck(107);
  v9 = MmInitSystemDll();
  if ( !SeRmInitPhase1(v9) )
    KeBugCheck(108);
  StartFirstUserProcess();
  ++InitializationPhase;
  ExNotifyCallback(ExCbPhase1InitComplete, 0, 0);
  if ( ViVerifierEnabled )
    VfNotifyVerifierOfEvent(5);
  WerLiveKernelInitSystem_0();
  ExQueryBootEntropyInformation(0, v10);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = KeAbPreAcquire((unsigned int)&KiDynamicProcessorLock, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex((unsigned __int8 *)&KiDynamicProcessorLock);
  while ( __strex(v14 & 0xFE, (unsigned __int8 *)&KiDynamicProcessorLock) );
  __dmb(0xBu);
  if ( (v14 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&KiDynamicProcessorLock, v12);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  dword_624E44 = v11;
  MmFreeLoaderBlock((int)KeLoaderBlock_0);
  KeLoaderBlock_0 = 0;
  dword_624E44 = 0;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&KiDynamicProcessorLock);
  while ( !v15 && __strex(1u, (unsigned int *)&KiDynamicProcessorLock) );
  if ( v15 )
    ExpReleaseFastMutexContended((unsigned int *)&KiDynamicProcessorLock, v15);
  v16 = KeAbPostRelease((unsigned int)&KiDynamicProcessorLock);
  KeEnableWatchdogTimeout = 1;
  return KeFreeInitializationCode(v16, v17, v18, 1u);
}
