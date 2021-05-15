// -StDmCurrentRegionSet@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@KK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmCurrentRegionSet(int a1, int a2, int a3)
{
  _DWORD *v3; // r8
  int v6; // r1

  v3 = (_DWORD *)(a1 + 12 * a2);
  if ( a3 != -1 )
    return sub_511830();
  if ( v3[98] != -1 )
  {
    if ( !*(_BYTE *)(a1 + 72) )
      ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(a1);
    v6 = v3[98];
    if ( (*(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v6) & 0x1FFF) == 0 )
      ST_STORE<SM_TRAITS>::StReleaseRegion(a1, v6);
  }
  v3[98] = -1;
  v3[99] = -1;
  v3[100] = 0;
  return 0;
}
