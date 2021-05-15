// VfSessionDataInit 
 
int VfSessionDataInit()
{
  int result; // r0
  unsigned int v1; // r2

  result = pXdvExInitializeNPagedLookasideList(
             &ViSessionDataLookaside,
             0,
             VfUtilFreePoolDispatchLevel,
             512,
             1720,
             1936749129,
             16,
             VfInitializedWithoutReboot,
             ExInitializeNPagedLookasideListInternal);
  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&ViSessionDataInitialized);
  while ( __strex(1u, (unsigned int *)&ViSessionDataInitialized) );
  __dmb(0xBu);
  return result;
}
