// VfRemLockInit 
 
int VfRemLockInit()
{
  int v0; // r0
  int result; // r0
  unsigned int v2; // r1
  unsigned int v3; // r2

  v0 = VfAvlInitializeTree(ViRemLockAvl, 24, 96, (int)ViRemLockDelayFreeAvlNode);
  __dmb(0xBu);
  if ( v0 < 0 )
  {
    result = 1;
    do
      v3 = __ldrex(&ViRemLockAllocationFailures);
    while ( __strex(1u, &ViRemLockAllocationFailures) );
  }
  else
  {
    result = 1;
    do
      v2 = __ldrex((unsigned int *)&ViRemLockInitialized);
    while ( __strex(1u, (unsigned int *)&ViRemLockInitialized) );
  }
  __dmb(0xBu);
  return result;
}
