// ExpUpdateTimerResolution 
 
int ExpUpdateTimerResolution(int a1, ...)
{
  unsigned int v1; // r1
  int v3; // r8
  int result; // r0
  unsigned int v5; // r2
  int *i; // r2
  int v7; // r6
  int varg_r1; // [sp+24h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+24h] [bp+Ch]
  unsigned __int8 *varg_r2; // [sp+28h] [bp+10h]
  va_list varg_r3; // [sp+2Ch] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, _DWORD);
  v1 = varg_r1;
  varg_r2 = va_arg(varg_r3, unsigned __int8 *);
  if ( varg_r2 )
  {
    v3 = *varg_r2;
  }
  else
  {
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_524D38();
    do
      v5 = __ldrex((unsigned int *)&ExpKernelResolutionLock);
    while ( __strex(1u, (unsigned int *)&ExpKernelResolutionLock) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire(&ExpKernelResolutionLock);
    v1 = varg_r1;
  }
  if ( a1 )
  {
    if ( v1 >= ExpLastRequestedTime || KeMaximumIncrement <= v1 )
      goto LABEL_10;
  }
  else
  {
    v1 = KeMaximumIncrement;
    varg_r1 = KeMaximumIncrement;
    if ( ExpKernelResolutionCount && ExpKernelRequestedTimerResolution < (unsigned int)KeMaximumIncrement )
    {
      v1 = ExpKernelRequestedTimerResolution;
      varg_r1 = ExpKernelRequestedTimerResolution;
    }
    for ( i = (int *)ExpTimerResolutionListHead; i != &ExpTimerResolutionListHead; i = (int *)*i )
    {
      if ( (*(i - 120) & 0x1000) != 0 && i[3] < v1 )
      {
        v1 = i[3];
        varg_r1 = v1;
      }
    }
  }
  if ( v1 < KeMinimumIncrement )
  {
    v1 = KeMinimumIncrement;
    varg_r1 = KeMinimumIncrement;
  }
  if ( v1 != ExpLastRequestedTime )
  {
    v7 = KeTimeIncrement;
    ExpLastRequestedTime = v1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&ExpKernelResolutionLock);
    }
    else
    {
      __dmb(0xBu);
      ExpKernelResolutionLock = 0;
    }
    KfLowerIrql(v3);
    ExpUpdateTimerConfiguration((int *)varg_r1a, 0, 0);
    result = varg_r1;
    if ( v7 != varg_r1 )
    {
      PoTraceSystemTimerResolutionUpdate(KeTimeIncrement);
      result = varg_r1;
    }
    return result;
  }
LABEL_10:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ExpKernelResolutionLock);
  }
  else
  {
    __dmb(0xBu);
    ExpKernelResolutionLock = 0;
  }
  KfLowerIrql(v3);
  return KeTimeIncrement;
}
