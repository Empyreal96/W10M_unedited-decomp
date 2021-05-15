// VerifierObfDereferenceObject 
 
int __fastcall VerifierObfDereferenceObject(unsigned int a1)
{
  if ( a1 < MmHighestUserAddress || a1 + 8 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 8, 0);
  return pXdvObfDereferenceObject(a1);
}
