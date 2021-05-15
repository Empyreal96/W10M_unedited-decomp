// RtlpValidAttributeInfo 
 
int __fastcall RtlpValidAttributeInfo(int a1, int a2, int a3)
{
  unsigned int v5; // r3
  int v6; // r6
  unsigned int v7; // r5

  if ( a1 )
  {
    if ( *(_WORD *)a1 == 1 && !*(_WORD *)(a1 + 2) )
    {
      v5 = *(_DWORD *)(a1 + 4);
      if ( v5 )
      {
        v6 = *(_DWORD *)(a1 + 8);
        v7 = 0;
        while ( RtlpValidAttribute(v6, a2, a3, v5) )
        {
          v5 = *(_DWORD *)(a1 + 4);
          ++v7;
          v6 += 20;
          if ( v7 >= v5 )
            return 1;
        }
      }
    }
  }
  return 0;
}
