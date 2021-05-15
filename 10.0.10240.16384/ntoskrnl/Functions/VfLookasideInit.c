// VfLookasideInit 
 
int VfLookasideInit()
{
  int result; // r0
  unsigned int v1; // r2
  unsigned int v2; // r2

  result = VfAvlInitializeTree(ViLookasideAvl, 72, 0, (int)ViRemLockDelayFreeAvlNode);
  __dmb(0xBu);
  if ( result < 0 )
  {
    do
      v2 = __ldrex((unsigned int *)&ViLookasideAllocationFailures);
    while ( __strex(1u, (unsigned int *)&ViLookasideAllocationFailures) );
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&ViLookasideInitialized);
    while ( __strex(1u, (unsigned int *)&ViLookasideInitialized) );
  }
  __dmb(0xBu);
  return result;
}
