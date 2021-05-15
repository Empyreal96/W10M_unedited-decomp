// VerifierObfReferenceObject 
 
int __fastcall VerifierObfReferenceObject(unsigned int a1)
{
  int v2; // r5

  if ( a1 < MmHighestUserAddress || a1 + 8 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 8, 0);
  v2 = pXdvObfReferenceObject(a1);
  if ( v2 == 1 )
    VerifierBugCheckIfAppropriate(196, 63, a1, 1, 0);
  return v2;
}
