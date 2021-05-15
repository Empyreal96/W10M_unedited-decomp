// ExTraceTimerResolution 
 
int ExTraceTimerResolution()
{
  int *i; // r4
  int result; // r0
  unsigned int v2; // r1
  __int16 v3; // r3

  ExAcquireTimeRefreshLock(1);
  PoRundownSystemTimer(KeTimeIncrement, KeMinimumIncrement, KeMaximumIncrement, ExpKernelResolutionCount);
  for ( i = (int *)ExpTimerResolutionListHead; i != &ExpTimerResolutionListHead; i = (int *)*i )
    PoTraceSystemTimerResolution(1, i - 168);
  result = ExReleaseResourceLite((int)&ExpTimeRefreshLock);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_WORD *)(v2 + 0x134) + 1;
  *(_WORD *)(v2 + 308) = v3;
  if ( !v3 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
