// -StStagingRegionFind@-$ST_STORE@USM_TRAITS@@@@SAPAU_ST_STAGING_REGION@1@PAU_ST_DATA_MGR@1@K@Z 
 
_DWORD *__fastcall ST_STORE<SM_TRAITS>::StStagingRegionFind(int a1, int a2)
{
  _DWORD *result; // r0
  _DWORD *v3; // r2

  result = (_DWORD *)(a1 + 320);
  v3 = result + 18;
  while ( result < v3 )
  {
    if ( *result == a2 )
      return result;
    result += 3;
  }
  return 0;
}
