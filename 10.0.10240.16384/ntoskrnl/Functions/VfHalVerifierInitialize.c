// VfHalVerifierInitialize 
 
int VfHalVerifierInitialize()
{
  int v0; // r0

  dword_908C58 = 0;
  dword_908C54 = (int)&ViAdapterList;
  ViAdapterList = (int)&ViAdapterList;
  *(_DWORD *)algn_908C44 = &ViDomainCommonBufferList;
  dword_908C48 = 0;
  ViDomainCommonBufferList = (int)&ViDomainCommonBufferList;
  v0 = pXdvExInitializeNPagedLookasideList(
         &ViHalWaitBlockLookaside,
         0,
         VfUtilFreePoolCheckIRQL,
         512,
         84,
         1449943368,
         16,
         VfInitializedWithoutReboot,
         ExInitializeNPagedLookasideListInternal);
  return ViHalApplySettings(v0);
}
