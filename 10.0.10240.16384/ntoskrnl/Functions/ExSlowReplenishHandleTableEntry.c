// ExSlowReplenishHandleTableEntry 
 
int __fastcall ExSlowReplenishHandleTableEntry(int a1)
{
  unsigned int v2; // r2
  int result; // r0

  v2 = *(_DWORD *)(a1 + 4);
  if ( (v2 & 0xF8000000) >= 0xF8000000 )
    return 0;
  result = 31 - (v2 >> 27);
  *(_DWORD *)(a1 + 4) = v2 | 0xF8000000;
  return result;
}
