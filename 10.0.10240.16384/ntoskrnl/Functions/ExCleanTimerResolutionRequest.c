// ExCleanTimerResolutionRequest 
 
int ExCleanTimerResolutionRequest()
{
  int v0; // r5
  int result; // r0
  int v2; // r7
  unsigned int v3; // r2
  __int64 v4; // r0
  int v5; // r0
  int v6; // r4

  v0 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( (*(_DWORD *)(v0 + 192) & 0x1000) != 0 )
    return sub_527200();
  ExAcquireTimeRefreshLock(1);
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&ExpKernelResolutionLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&ExpKernelResolutionLock);
    while ( __strex(1u, (unsigned int *)&ExpKernelResolutionLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire(&ExpKernelResolutionLock);
  }
  v4 = *(_QWORD *)(v0 + 672);
  if ( *(_DWORD *)(v4 + 4) != v0 + 672 || *(_DWORD *)HIDWORD(v4) != v0 + 672 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v4) = v4;
  *(_DWORD *)(v4 + 4) = HIDWORD(v4);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ExpKernelResolutionLock);
  }
  else
  {
    __dmb(0xBu);
    ExpKernelResolutionLock = 0;
  }
  v5 = KfLowerIrql(v2);
  v6 = *(_DWORD *)(v0 + 680);
  *(_DWORD *)(v0 + 680) = 0;
  result = ExReleaseTimeRefreshLock(v5);
  if ( v6 )
    result = PoDiagFreeUsermodeStack(v6);
  return result;
}
