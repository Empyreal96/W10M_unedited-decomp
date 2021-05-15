// VerifierIoFreeMdl 
 
int __fastcall VerifierIoFreeMdl(unsigned int a1)
{
  __int16 v2; // r3

  if ( a1 < MmHighestUserAddress || *(unsigned __int16 *)(a1 + 4) + a1 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1);
  v2 = *(_WORD *)(a1 + 6);
  if ( (v2 & 0x10) == 0 && (v2 & 1) != 0 )
    VerifierBugCheckIfAppropriate(196, 184, a1);
  return pXdvIoFreeMdl(a1);
}
