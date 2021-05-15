// ExSetTimerResolution 
 
int __fastcall ExSetTimerResolution(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r4
  int v6; // r9
  unsigned int v8; // r2
  int v9; // r7
  _DWORD v10[8]; // [sp+0h] [bp-20h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v5 = a1;
  if ( !a2 )
    a1 = 0;
  PoTraceSystemTimerResolutionKernel(a1, 1381258053);
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_524D0C();
  do
    v8 = __ldrex((unsigned int *)&ExpKernelResolutionLock);
  while ( __strex(1u, (unsigned int *)&ExpKernelResolutionLock) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForSpinLockAndAcquire(&ExpKernelResolutionLock);
  v9 = KeTimeIncrement;
  LOBYTE(v10[0]) = v6;
  if ( a2 )
  {
    if ( ++ExpKernelResolutionCount == 1 || v5 < ExpKernelRequestedTimerResolution )
      goto LABEL_11;
LABEL_14:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&ExpKernelResolutionLock);
    }
    else
    {
      __dmb(0xBu);
      ExpKernelResolutionLock = 0;
    }
    KfLowerIrql(v6);
    return v9;
  }
  if ( !ExpKernelResolutionCount )
    goto LABEL_14;
  if ( --ExpKernelResolutionCount )
    goto LABEL_14;
  v5 = 0;
LABEL_11:
  ExpKernelRequestedTimerResolution = v5;
  return ExpUpdateTimerResolution(a2, v5, v10);
}
