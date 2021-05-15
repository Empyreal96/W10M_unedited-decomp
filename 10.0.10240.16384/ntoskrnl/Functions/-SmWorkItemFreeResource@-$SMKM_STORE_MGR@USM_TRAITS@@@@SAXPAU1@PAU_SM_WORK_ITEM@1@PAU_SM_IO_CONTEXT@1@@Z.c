// -SmWorkItemFreeResource@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAU_SM_WORK_ITEM@1@PAU_SM_IO_CONTEXT@1@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFreeResource(int a1, _DWORD *a2, int a3)
{
  int v3; // r3
  int v5; // r3

  v3 = *a2 & 7;
  if ( v3 == 1 )
  {
    v5 = 5656;
  }
  else
  {
    if ( v3 != 2 )
      return ExFreePoolWithTag(a2);
    v5 = 5720;
  }
  return SmFpFree(a1 + v5, 1, a3, a2);
}
