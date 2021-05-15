// -StDmLazyRemoveStateUpdate@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@PAT_SM_PAGE_KEY@@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmLazyRemoveStateUpdate(int a1, unsigned int *a2, int a3)
{
  unsigned int v3; // r1
  int v5; // r0

  v3 = *a2;
  v5 = a1 + 160;
  if ( !a3 )
    return RtlpSparseBitmapCtxUpdateBitRanges(v5, v3, v3 >> 4, 0);
  RtlpSparseBitmapCtxUpdateBitRanges(v5, v3, v3 >> 4, 0);
  return ST_STORE<SM_TRAITS>::StDmLazyWorkItemQueue(a1, a1 + 216);
}
