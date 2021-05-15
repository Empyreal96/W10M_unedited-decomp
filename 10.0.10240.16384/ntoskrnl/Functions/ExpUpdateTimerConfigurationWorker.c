// ExpUpdateTimerConfigurationWorker 
 
int __fastcall ExpUpdateTimerConfigurationWorker(int a1, _DWORD *a2)
{
  int v3; // r8
  unsigned int v5; // r2
  _DWORD *v6; // r3
  int v7; // r4
  _DWORD *v8; // r3
  char *v9; // r3

  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_552AD4();
  do
    v5 = __ldrex((unsigned int *)&ExpKernelResolutionLock);
  while ( __strex(1u, (unsigned int *)&ExpKernelResolutionLock) );
  __dmb(0xBu);
  if ( v5 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&ExpKernelResolutionLock);
  KfRaiseIrql(15);
  v6 = (_DWORD *)*a2;
  a2[3] = 0;
  if ( v6 )
  {
    v7 = KiSetClockInterval(ExpLastRequestedTime, &ExpClockIntervalRequest);
    KiSendClockInterruptToClockOwner(v7);
    *(_DWORD *)*a2 = v7;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ExpKernelResolutionLock);
  }
  else
  {
    __dmb(0xBu);
    ExpKernelResolutionLock = 0;
  }
  KfLowerIrql(15);
  v8 = (_DWORD *)a2[1];
  if ( v8 )
    a2[3] = KeSetTimeAdjustment(*v8);
  v9 = (char *)a2[2];
  if ( v9 )
    KeTimeSynchronization = *v9;
  return KfLowerIrql(v3);
}
