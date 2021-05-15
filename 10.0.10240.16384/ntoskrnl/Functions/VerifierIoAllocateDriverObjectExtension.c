// VerifierIoAllocateDriverObjectExtension 
 
int __fastcall VerifierIoAllocateDriverObjectExtension(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // r0

  if ( !VfFaultsInjectResourceFailure(0) )
    return pXdvIoAllocateDriverObjectExtension(a1, a2, a3, a4);
  result = -1073741670;
  *a4 = 0;
  return result;
}
