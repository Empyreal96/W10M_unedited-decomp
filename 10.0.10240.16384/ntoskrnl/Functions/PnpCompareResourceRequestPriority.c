// PnpCompareResourceRequestPriority 
 
int __fastcall PnpCompareResourceRequestPriority(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r2
  unsigned int v4; // r3
  unsigned int v5; // r2

  v2 = *(_DWORD *)(a1 + 12);
  v3 = *(_DWORD *)(a2 + 12);
  if ( v2 == v3 )
  {
    v4 = *(_DWORD *)(a1 + 16);
    v5 = *(_DWORD *)(a2 + 16);
    if ( v4 > v5 || v4 >= v5 && a1 >= a2 )
      return 1;
    return -1;
  }
  if ( v2 <= v3 )
    return -1;
  return 1;
}
