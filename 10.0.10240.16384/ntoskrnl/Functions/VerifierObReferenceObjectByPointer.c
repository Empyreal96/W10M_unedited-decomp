// VerifierObReferenceObjectByPointer 
 
int __fastcall VerifierObReferenceObjectByPointer(unsigned int a1, int a2, int a3, char a4)
{
  int v5; // r6

  v5 = a4;
  if ( a1 < MmHighestUserAddress || a1 + 8 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 8, 0);
  if ( !*(_DWORD *)(a1 - 24) )
    VerifierBugCheckIfAppropriate(196, 63, a1, 1, 0);
  return pXdvObReferenceObjectByPointer(a1, a2, a3, v5);
}
