// -StStoreWorkItemCleanup@-$ST_STORE@USM_TRAITS@@@@SAXPAU1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StStoreWorkItemCleanup(int result, int a2)
{
  int v2; // r2

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 == 2 )
    return ExFreePoolWithTag(a2);
  if ( v2 == 3 )
    *(_DWORD *)(result + 1800) &= 0xFFFFFFFE;
  return result;
}
