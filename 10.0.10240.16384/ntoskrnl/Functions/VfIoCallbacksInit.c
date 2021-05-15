// VfIoCallbacksInit 
 
int VfIoCallbacksInit()
{
  int result; // r0
  unsigned int v1; // r1

  pXdvExInitializeNPagedLookasideList(
    &ViIoCallbackStateLookaside,
    0,
    VfUtilFreePoolCheckIRQL,
    512,
    8,
    1330202198,
    16,
    VfInitializedWithoutReboot,
    ExInitializeNPagedLookasideListInternal);
  __dmb(0xBu);
  result = 1;
  do
    v1 = __ldrex((unsigned int *)&ViIoCallbacksInitialized);
  while ( __strex(1u, (unsigned int *)&ViIoCallbacksInitialized) );
  __dmb(0xBu);
  return result;
}
