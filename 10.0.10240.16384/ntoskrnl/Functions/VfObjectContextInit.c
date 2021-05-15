// VfObjectContextInit 
 
int VfObjectContextInit()
{
  int result; // r0
  unsigned int v1; // r2

  result = pXdvExInitializeNPagedLookasideList(
             &ViObjectContextTableLookaside,
             0,
             VfUtilFreePoolCheckIRQL,
             512,
             16,
             1666147926,
             0,
             VfInitializedWithoutReboot,
             ExInitializeNPagedLookasideListInternal);
  __dmb(0xBu);
  do
    v1 = __ldrex(&ViObjectContextInitialized);
  while ( __strex(1u, &ViObjectContextInitialized) );
  __dmb(0xBu);
  return result;
}
