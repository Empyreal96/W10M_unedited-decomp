// VerifierObReferenceObjectByPointerWithTag 
 
int __fastcall VerifierObReferenceObjectByPointerWithTag(unsigned int a1, int a2, int a3, char a4)
{
  int v5; // r6

  v5 = a4;
  if ( a1 < MmHighestUserAddress || a1 + 8 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 8, 0);
  return pXdvObReferenceObjectByPointerWithTag(a1, a2, a3, v5);
}
