// VfTargetDriversGetVerifierData 
 
int __fastcall VfTargetDriversGetVerifierData(unsigned int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0

  if ( ViDriverKernelBase && a1 >= ViDriverKernelBase && a1 < ViDriverKernelEnd )
  {
    v3 = KernelVerifier;
  }
  else
  {
    v3 = dword_61D2B4;
    if ( KernelVerifier )
    {
      if ( dword_61D2B4 < 2 )
        return 0;
      goto LABEL_9;
    }
  }
  if ( !v3 )
    return 0;
LABEL_9:
  v5 = VfTargetDriversGetNode(a1, a2, a3, v3);
  if ( !v5 )
    return 0;
  return *(_DWORD *)(v5 + 24);
}
