// VerifierObGetObjectSecurity 
 
int __fastcall VerifierObGetObjectSecurity(unsigned int a1, int a2, int a3)
{
  if ( a1 < MmHighestUserAddress || a1 + 8 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 8, 0);
  return pXdvObGetObjectSecurity(a1, a2, a3);
}
