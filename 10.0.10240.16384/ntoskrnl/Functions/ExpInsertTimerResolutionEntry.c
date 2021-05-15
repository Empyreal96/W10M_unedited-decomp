// ExpInsertTimerResolutionEntry 
 
int __fastcall ExpInsertTimerResolutionEntry(int a1)
{
  int v2; // r5
  unsigned int v4; // r2
  int v5; // r2
  unsigned __int64 v6; // r0
  int v7; // r3

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_524D78();
  do
    v4 = __ldrex((unsigned int *)&ExpKernelResolutionLock);
  while ( __strex(1u, (unsigned int *)&ExpKernelResolutionLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire(&ExpKernelResolutionLock);
  v5 = a1 + 672;
  v6 = __PAIR64__(&ExpTimerResolutionListHead, ExpTimerResolutionListHead);
  *(_QWORD *)(a1 + 672) = __PAIR64__(&ExpTimerResolutionListHead, ExpTimerResolutionListHead);
  if ( *(_DWORD *)(v6 + 4) != HIDWORD(v6) )
    __fastfail(3u);
  *(_DWORD *)(v6 + 4) = v5;
  v7 = dword_682604;
  *(_DWORD *)HIDWORD(v6) = v5;
  if ( (v7 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ExpKernelResolutionLock);
  }
  else
  {
    __dmb(0xBu);
    ExpKernelResolutionLock = 0;
  }
  return KfLowerIrql(v2);
}
