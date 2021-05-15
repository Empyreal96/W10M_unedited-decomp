// sub_9698E4 
 
void sub_9698E4()
{
  int v0; // r5
  int v1; // r0
  _DWORD *v2; // r4
  int v3; // r6
  int v4; // r3
  int v5; // r2

  v1 = NtSetDebugFilterState(0x5Du, 0, 1);
  if ( MmVerifyDriverBufferLength )
    v1 = VfSuspectDriversParseRegistryString(v1);
  if ( VfXdvSuppressDriversBufferLength )
    VfXdvExcludeParseRegistryString(v1);
  VfInitVerifierComponents(MmVerifierData, ViVerifyAllDrivers, KernelVerifier);
  IoVerifierInit(MmVerifierData);
  ViFullyInitialized = 1;
  VfTriageAddDrivers(v0);
  v2 = *(_DWORD **)(v0 + 16);
  v3 = 0;
  if ( v2 == (_DWORD *)(v0 + 16) )
LABEL_12:
    JUMPOUT(0x952C10);
  while ( !v3 )
  {
    v4 = v2[8];
    ViDriverKernelBase = v2[6];
    ViDriverKernelEnd = v4 + ViDriverKernelBase;
    if ( KernelVerifier )
    {
      v5 = 1;
LABEL_10:
      VfDriverLoadImage((int)v2, 0, v5, 0);
    }
    v2 = (_DWORD *)*v2;
    ++v3;
    if ( v2 == (_DWORD *)(v0 + 16) )
      goto LABEL_12;
  }
  v5 = 0;
  goto LABEL_10;
}
