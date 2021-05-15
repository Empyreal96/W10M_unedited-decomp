// PipFindDependencyNodePath 
 
int __fastcall PipFindDependencyNodePath(int a1, int a2, int *a3, int a4)
{
  int v8; // r6
  int result; // r0
  unsigned int v10; // r2
  int v11; // r3
  int v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[0] = a4;
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_527178();
  do
    v10 = __ldrex((unsigned int *)&PiDependencyEdgeWriteLock);
  while ( __strex(1u, (unsigned int *)&PiDependencyEdgeWriteLock) );
  __dmb(0xBu);
  if ( v10 )
    KxWaitForSpinLockAndAcquire(&PiDependencyEdgeWriteLock);
  PipDependencyGraphDepthFirstSearch(a1, a2, v12, a4);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PiDependencyEdgeWriteLock);
  }
  else
  {
    __dmb(0xBu);
    PiDependencyEdgeWriteLock = 0;
  }
  result = KfLowerIrql(v8);
  if ( v12[0] )
  {
    if ( v12[0] == 1 )
      v11 = 1;
    else
      v11 = 2;
    *a3 = v11;
  }
  else
  {
    *a3 = 0;
  }
  return result;
}
