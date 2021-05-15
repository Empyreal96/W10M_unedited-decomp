// VfDevObjInit 
 
int VfDevObjInit()
{
  int result; // r0
  unsigned int v1; // r2
  unsigned int v2; // r2

  result = VfAvlInitializeTree(ViDevObjAvl, 184, 12, (int)ViRemLockDelayFreeAvlNode);
  __dmb(0xBu);
  if ( result < 0 )
  {
    do
      v2 = __ldrex(&ViDevObjAllocationFailures);
    while ( __strex(1u, &ViDevObjAllocationFailures) );
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&ViDevObjInitialized);
    while ( __strex(1u, (unsigned int *)&ViDevObjInitialized) );
  }
  __dmb(0xBu);
  return result;
}
