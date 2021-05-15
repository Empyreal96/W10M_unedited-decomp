// ViThunkReplaceAllSharedExports 
 
int __fastcall ViThunkReplaceAllSharedExports(_DWORD *a1, int a2)
{
  int v4; // r0
  int result; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0

  v4 = RtlNumberOfClearBits(VfPoolThunksBitMapHeader);
  result = ViThunkReplaceSharedExports(a1[3], v4);
  if ( !KernelVerifier )
  {
    v6 = RtlNumberOfClearBits(&VfRegularThunksBitMapHeader);
    result = ViThunkReplaceSharedExports(a1[2], v6);
    if ( !a2 )
    {
      v7 = RtlNumberOfClearBits(&VfOrderDependentThunksBitMapHeader);
      ViThunkReplaceSharedExports(a1[4], v7);
      v8 = RtlNumberOfClearBits(&VfXdvThunksBitMapHeader);
      result = ViThunkReplaceSharedExports(a1[5], v8);
    }
  }
  return result;
}
