// -StDmEtaQueueRefresh@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmEtaQueueRefresh(int a1)
{
  unsigned int *v2; // r0
  unsigned int *v3; // r4

  v2 = (unsigned int *)ExAllocatePoolWithTag(512, 24);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  memset(v2, 0, 24);
  *v3 = *v3 & 0xFFFFFFF8 | 6;
  v3[1] = 2;
  SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(*(_DWORD *)(a1 + 92), (int)v3, 4);
  return 0;
}
