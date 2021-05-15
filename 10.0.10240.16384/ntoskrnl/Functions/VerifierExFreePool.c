// VerifierExFreePool 
 
unsigned int __fastcall VerifierExFreePool(unsigned int a1)
{
  unsigned int result; // r0

  if ( (MiFlags & 2) != 0 )
    result = ExFreePoolWithTag(a1);
  else
    result = VerifierExFreePoolWithTag(a1, 0);
  return result;
}
