// LdrpGetMappingFromCacheEntry 
 
int __fastcall LdrpGetMappingFromCacheEntry(unsigned int a1, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // r0
  int v5; // r5
  int v6; // r4

  if ( !a2 )
    return 0;
  if ( !a3 )
    return 0;
  if ( a1 >= AlternateResourceModuleCount )
    return 0;
  v4 = AlternateResourceModules + 40 * a1;
  v5 = *(_DWORD *)(v4 + 16);
  v6 = *(_DWORD *)(v4 + 24);
  if ( !v5 || v5 == -1 )
    return 0;
  if ( !v6 )
    return sub_54DCBC();
  if ( a2 < (v5 & 0xFFFFFFFC) || a2 >= (v5 & 0xFFFFFFFC) + v6 )
    return 0;
  *a3 = v5;
  *a4 = v6;
  return 1;
}
