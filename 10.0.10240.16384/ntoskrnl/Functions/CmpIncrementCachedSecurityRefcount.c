// CmpIncrementCachedSecurityRefcount 
 
int __fastcall CmpIncrementCachedSecurityRefcount(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v7; // [sp+0h] [bp-8h] BYREF

  v7 = a4;
  if ( !CmpFindSecurityCellCacheIndex(a1, a2, &v7) )
    return 0;
  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v7 + 4);
  ++*(_DWORD *)(v5 + 20);
  return 1;
}
