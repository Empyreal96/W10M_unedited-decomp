// ViThunkIsExportAddressShared 
 
int __fastcall ViThunkIsExportAddressShared(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r5
  unsigned int v5; // r3
  unsigned int v6; // r1

  v3 = *(_DWORD *)(a2 + 20);
  v4 = *(_DWORD *)(a2 + 28) + a1;
  v5 = 0;
  if ( !v3 )
    return 0;
  v6 = 0;
  while ( v6 == a3 || *(_DWORD *)(v4 + 4 * v5) + a1 != *(_DWORD *)(v4 + 4 * a3) + a1 )
  {
    v5 = (unsigned __int16)(v6 + 1);
    v6 = v5;
    if ( v5 >= v3 )
      return 0;
  }
  return 1;
}
