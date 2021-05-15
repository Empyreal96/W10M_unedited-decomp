// -StGetStats@-$ST_STORE@USM_TRAITS@@@@SAJPAU1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StGetStats(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r0
  int result; // r0
  int v9; // r1
  int v10; // [sp+0h] [bp-10h] BYREF
  int v11; // [sp+4h] [bp-Ch]

  v10 = a3;
  v11 = a4;
  v6 = *(_DWORD *)(a2 + 12);
  if ( v6 )
  {
    v7 = SmMapPage(v6, &v10);
    if ( !v7 )
      return -1073741670;
  }
  else
  {
    v7 = 0;
  }
  v9 = *(_DWORD *)(a2 + 4);
  if ( v9 != -1 )
    return ST_STORE<SM_TRAITS>::StGetStatsWorker(a1, v9, v7, a2 + 8, v10, v11);
  ST_STORE<SM_TRAITS>::StDmEtwRegionRundown(a1 + 56);
  ST_STORE<SM_TRAITS>::StDmEtwRegionRundown(a1 + 824);
  result = ST_STORE<SM_TRAITS>::StDmEtwPageRundown(a1 + 56);
  if ( result >= 0 )
    result = ST_STORE<SM_TRAITS>::StDmEtwPageRundown(a1 + 824);
  return result;
}
