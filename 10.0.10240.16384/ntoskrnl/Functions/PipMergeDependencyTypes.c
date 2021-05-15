// PipMergeDependencyTypes 
 
int __fastcall PipMergeDependencyTypes(int a1, int a2)
{
  int v4; // r6
  unsigned int v6; // r2

  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_550B78();
  do
    v6 = __ldrex((unsigned int *)&PiDependencyEdgeWriteLock);
  while ( __strex(1u, (unsigned int *)&PiDependencyEdgeWriteLock) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&PiDependencyEdgeWriteLock);
  *(_DWORD *)(a1 + 24) |= a2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PiDependencyEdgeWriteLock);
  }
  else
  {
    __dmb(0xBu);
    PiDependencyEdgeWriteLock = 0;
  }
  return KfLowerIrql(v4);
}
