// VerifierObfDereferenceObjectWithTag 
 
int __fastcall VerifierObfDereferenceObjectWithTag(unsigned int a1, int a2)
{
  if ( a1 < MmHighestUserAddress || a1 + 8 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 8, 0);
  return pXdvObfDereferenceObjectWithTag(a1, a2);
}
