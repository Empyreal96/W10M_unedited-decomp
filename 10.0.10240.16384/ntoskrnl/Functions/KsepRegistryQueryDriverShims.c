// KsepRegistryQueryDriverShims 
 
int __fastcall KsepRegistryQueryDriverShims(int a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r4
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = 0;
  if ( !a1 || !a2 )
    return -1073741811;
  v6 = KsepRegistryOpenKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Driver", a1, v8);
  if ( v6 >= 0 )
    v6 = KsepRegistryQuerySZ(v8[0], L"Shims", 7, a2, 0x800u, a4);
  if ( v6 == -1073741772 )
    v6 = -1073741275;
  KsepRegistryCloseKey(v8[0]);
  return v6;
}
