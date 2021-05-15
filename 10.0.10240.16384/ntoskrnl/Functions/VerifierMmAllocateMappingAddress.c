// VerifierMmAllocateMappingAddress 
 
int __fastcall VerifierMmAllocateMappingAddress(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r0

  if ( VfFaultsInjectResourceFailure(0, a2, a3, a4) )
    return 0;
  v7 = pXdvMmAllocateMappingAddress(a1, a2);
  v6 = v7;
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v7, a1);
  return v6;
}
