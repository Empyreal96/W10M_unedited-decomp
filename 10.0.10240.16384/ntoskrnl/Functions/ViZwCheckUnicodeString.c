// ViZwCheckUnicodeString 
 
unsigned __int16 *__fastcall ViZwCheckUnicodeString(unsigned __int16 *result, int a2)
{
  unsigned __int16 *v2; // r5
  unsigned int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r3
  int v7; // r3

  v2 = result;
  if ( result )
  {
    ViZwCheckVirtualAddress(result);
    v4 = *((_DWORD *)v2 + 1);
    result = (unsigned __int16 *)ViZwCheckVirtualAddress(v4);
    v5 = *v2;
    if ( v5 + v4 < v4 || (v6 = v2[1], v6 < v5) || (v5 & 1) != 0 || (v6 & 1) != 0 )
    {
      v7 = ViZwBreakForIssues;
      __dmb(0xBu);
      if ( v7 )
        result = (unsigned __int16 *)VerifierBugCheckIfAppropriate(196, 228, a2, (int)v2, 0);
    }
  }
  return result;
}
