// SepCompareSidValuesBlocks 
 
int __fastcall SepCompareSidValuesBlocks(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v4; // r7
  int v5; // r5
  int v6; // r6

  if ( a1 != a2 )
  {
    if ( !a1 )
      return 0;
    if ( !a2 )
      return 0;
    v2 = *(_DWORD *)(a1 + 8);
    if ( v2 != *(_DWORD *)(a2 + 8) )
      return 0;
    v4 = 0;
    v5 = a1 + 12;
    v6 = a2 + 12;
    if ( v2 )
    {
      while ( RtlEqualSid((unsigned __int16 *)v5, (unsigned __int16 *)v6) )
      {
        ++v4;
        v5 += (4 * *(unsigned __int8 *)(v5 + 1) + 11) & 0xFFFFFFFC;
        v6 += (4 * *(unsigned __int8 *)(v6 + 1) + 11) & 0xFFFFFFFC;
        if ( v4 >= v2 )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}
