// PoGetThermalRequestSupport 
 
BOOL __fastcall PoGetThermalRequestSupport(int a1, int a2)
{
  int v2; // r3
  int v3; // r3

  v2 = *(_DWORD *)(a1 + 16);
  if ( !a2 )
  {
    v3 = *(_DWORD *)(v2 + 68);
    return v3 != 0;
  }
  if ( a2 == 1 )
  {
    v3 = *(_DWORD *)(v2 + 64);
    return v3 != 0;
  }
  return 0;
}
