// PfTLocateEntryInfo 
 
unsigned int __fastcall PfTLocateEntryInfo(unsigned int a1, int a2)
{
  int v3; // r4
  unsigned int v4; // r2
  unsigned int result; // r0
  int v6; // r2
  int v7; // r1
  unsigned int v8; // r5

  v3 = *(_DWORD *)(a2 + 8);
  v4 = *(unsigned __int16 *)(v3 + 28);
  if ( a1 >= v4 && a1 < *(_DWORD *)(v3 + 24) + v4 )
    return ((v3 + 35) & 0xFFFFFFFC) + 20 * (a1 - v4) + 4;
  v6 = *(_DWORD *)(a2 + 4);
  v7 = *(_DWORD *)(a2 + 8);
  while ( 1 )
  {
    v7 = *(_DWORD *)(v7 + 4);
    if ( v7 == v6 )
      v7 = *(_DWORD *)(v6 + 4);
    if ( v7 == v3 )
      break;
    v8 = *(unsigned __int16 *)(v7 + 28);
    if ( a1 >= v8 && a1 < *(_DWORD *)(v7 + 24) + v8 )
    {
      result = ((v7 + 35) & 0xFFFFFFFC) + 20 * (a1 - (unsigned __int16)v8) + 4;
      *(_DWORD *)(a2 + 8) = v7;
      return result;
    }
  }
  return 0;
}
