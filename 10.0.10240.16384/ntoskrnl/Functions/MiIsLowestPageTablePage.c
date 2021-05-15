// MiIsLowestPageTablePage 
 
BOOL __fastcall MiIsLowestPageTablePage(int a1)
{
  unsigned int v1; // r1
  BOOL result; // r0

  result = 0;
  if ( (*(_BYTE *)(a1 + 18) & 7) == 6 && (*(_DWORD *)(a1 + 12) & 0x3FFFFFFF) != 0 )
  {
    v1 = *(_DWORD *)(a1 + 4) | 0x80000000;
    if ( v1 + 0x40000000 <= 0x3FFFFF && (v1 << 10) + 0x40000000 <= 0x3FFFFF )
      result = 1;
  }
  return result;
}
