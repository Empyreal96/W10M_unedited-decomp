// ViDeadlockKernelVerifierLookasideAllocate 
 
int __fastcall ViDeadlockKernelVerifierLookasideAllocate(int a1, int a2, int a3)
{
  int result; // r0

  if ( (ViDeadlockState & 2) != 0 )
    result = 0;
  else
    result = ExAllocatePoolWithTag(a1, a2, a3);
  return result;
}
