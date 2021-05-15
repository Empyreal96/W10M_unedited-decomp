// CcUnmapFileOffsetFromSystemCache 
 
int __fastcall CcUnmapFileOffsetFromSystemCache(int a1, unsigned int *a2, unsigned int a3)
{
  int v3; // r0

  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  if ( !*(_DWORD *)(v3 + 4) )
    sub_528E2C();
  return CcUnmapVacbArray(v3, a2, a3, 0, 0);
}
