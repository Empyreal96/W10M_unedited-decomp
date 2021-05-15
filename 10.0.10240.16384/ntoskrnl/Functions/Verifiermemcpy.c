// Verifiermemcpy 
 
int __fastcall Verifiermemcpy(unsigned int a1, unsigned int a2, int a3)
{
  if ( (MmVerifierData & 0x800) != 0 && a1 > a2 && a1 < a2 + a3 )
    VerifierBugCheckIfAppropriate(196, 240, a1, a2, a3);
  return pXdvmemcpy(a1, a2, a3);
}
