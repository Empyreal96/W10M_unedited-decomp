// MiInitializeForkMaps 
 
BOOL __fastcall MiInitializeForkMaps(int a1, int a2)
{
  int v4; // r6
  int v5; // r0
  BOOL result; // r0
  int v7; // r0

  memset((_BYTE *)a2, 0, 32);
  *(_DWORD *)a2 = a1;
  *(_DWORD *)(a2 + 4) = -1;
  v4 = *(_DWORD *)(a1 + 248);
  v5 = MiMapSinglePage(0, v4, 1073741856);
  *(_DWORD *)(a2 + 20) = v5;
  result = 0;
  if ( v5 )
  {
    v7 = MiMapSinglePage(0, v4, 1073741856);
    *(_DWORD *)(a2 + 28) = v7;
    if ( v7 )
      result = 1;
  }
  return result;
}
