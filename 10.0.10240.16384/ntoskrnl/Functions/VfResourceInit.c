// VfResourceInit 
 
int VfResourceInit()
{
  int result; // r0
  unsigned int v1; // r2
  unsigned int v2; // r2

  result = VfAvlInitializeTree(ViResourceAvl, 56, 0, (int)ViRemLockDelayFreeAvlNode);
  __dmb(0xBu);
  if ( result < 0 )
  {
    do
      v2 = __ldrex((unsigned int *)&ViResourceNotTracked);
    while ( __strex(1u, (unsigned int *)&ViResourceNotTracked) );
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&ViResourceInitialized);
    while ( __strex(1u, (unsigned int *)&ViResourceInitialized) );
  }
  __dmb(0xBu);
  return result;
}
