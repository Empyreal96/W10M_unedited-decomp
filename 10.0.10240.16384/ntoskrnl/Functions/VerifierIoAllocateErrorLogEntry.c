// VerifierIoAllocateErrorLogEntry 
 
int __fastcall VerifierIoAllocateErrorLogEntry(int a1, int a2)
{
  int result; // r0

  if ( VfFaultsInjectResourceFailure(0) )
    result = 0;
  else
    result = pXdvIoAllocateErrorLogEntry(a1, a2);
  return result;
}
