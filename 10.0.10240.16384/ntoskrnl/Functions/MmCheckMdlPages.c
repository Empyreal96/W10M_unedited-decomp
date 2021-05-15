// MmCheckMdlPages 
 
int __fastcall MmCheckMdlPages(int a1)
{
  unsigned int *v2; // r4
  __int16 v3; // r9
  unsigned int v4; // r7
  int result; // r0

  v2 = (unsigned int *)(a1 + 28);
  v3 = *(_WORD *)(a1 + 6);
  v4 = a1
     + 28
     + 4
     * ((*(_DWORD *)(a1 + 20)
       + (((unsigned __int16)*(_DWORD *)(a1 + 24) + (unsigned __int16)*(_DWORD *)(a1 + 16)) & 0xFFFu)
       + 4095) >> 12);
  do
  {
    result = MI_IS_PFN(*v2);
    if ( (v3 & 0x800) != 0 )
    {
      if ( result != 1 )
        goto LABEL_8;
    }
    else if ( !result )
    {
      result = VerifierBugCheckIfAppropriate(196, 137, a1);
    }
    if ( !*(_WORD *)(MmPfnDatabase + 24 * *v2 + 16) )
      result = VerifierBugCheckIfAppropriate(196, 133, a1);
LABEL_8:
    ++v2;
  }
  while ( (unsigned int)v2 < v4 );
  return result;
}
