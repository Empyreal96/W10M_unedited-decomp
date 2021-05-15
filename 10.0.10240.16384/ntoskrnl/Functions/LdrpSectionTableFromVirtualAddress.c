// LdrpSectionTableFromVirtualAddress 
 
int __fastcall LdrpSectionTableFromVirtualAddress(int a1, int a2, int a3, int a4, unsigned int a5, char a6)
{
  int v8; // r3
  int result; // r0
  int v10; // r4
  int v11; // r1
  unsigned int i; // r5
  unsigned int v13; // r2

  if ( a3 )
  {
    v8 = a3 + *(unsigned __int16 *)(a3 + 20);
    result = v8 + 24;
    if ( v8 != -24 )
    {
      v10 = *(unsigned __int16 *)(a3 + 6);
      v11 = 0;
      if ( *(_WORD *)(a3 + 6) )
      {
        for ( i = v8 + 64; !a6 || i <= (a1 & 0xFFFFFFFC) + a2; i += 40 )
        {
          v13 = *(_DWORD *)(result + 12);
          if ( a5 == v13 || a5 > v13 && a5 < *(_DWORD *)(result + 16) + v13 )
            return result;
          ++v11;
          result += 40;
          if ( v11 >= v10 )
            return 0;
        }
      }
    }
  }
  return 0;
}
