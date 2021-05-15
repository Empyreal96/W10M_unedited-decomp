// -StDmpCurrentRegionWrite@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmpCurrentRegionWrite(_DWORD *a1)
{
  int v2; // r3
  int v3; // r0
  int v4; // r2
  unsigned int v5; // r5
  int result; // r0
  int *v7; // r2
  int v8; // t1

  v2 = a1[76];
  v3 = a1[98];
  v4 = a1[26];
  v5 = *(_WORD *)(v2 + 2 * v3) & 0x1FFF;
  if ( v5 >= (unsigned int)(3 * v4) >> 2 || v5 >= v4 - a1[27] + 1 )
  {
    v7 = a1 + 80;
    do
    {
      v8 = *v7;
      v7 += 3;
    }
    while ( v8 != v3 );
    result = ST_STORE<SM_TRAITS>::StStagingRegionIssueIo(a1, v7 - 3);
  }
  else
  {
    result = ST_STORE<SM_TRAITS>::StCompactRegions((int)a1, a1[100], v3, a1[100], v3, 0);
    if ( result >= 0 )
      a1[99] = v5;
  }
  return result;
}
