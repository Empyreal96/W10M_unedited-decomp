// -StReleaseReadContext@-$ST_STORE@USM_TRAITS@@@@SAXPAU1@PAX@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StReleaseReadContext(int a1, _DWORD *a2)
{
  int v4; // r0
  int result; // r0

  B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1 + 56, a2[2]);
  v4 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
         a1 + 92,
         a2[3]);
  if ( *(unsigned __int16 *)(a1 + 1668) < 0x10u )
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)(a1 + 1664), a2);
  else
    result = sub_511400(v4);
  return result;
}
