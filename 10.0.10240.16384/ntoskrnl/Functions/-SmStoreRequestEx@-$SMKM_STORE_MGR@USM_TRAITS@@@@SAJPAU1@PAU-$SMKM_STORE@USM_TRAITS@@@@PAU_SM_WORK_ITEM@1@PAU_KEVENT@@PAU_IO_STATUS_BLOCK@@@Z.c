// -SmStoreRequestEx@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@PAU_SM_WORK_ITEM@1@PAU_KEVENT@@PAU_IO_STATUS_BLOCK@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStoreRequestEx(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v5; // r0

  v5 = a5;
  if ( a5 )
  {
    *a5 = 0;
    a5[1] = 0;
    *a5 = a4;
  }
  else
  {
    v5 = 0;
  }
  *(_DWORD *)(a3 + 24) = v5;
  SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(a2, a3, 0);
  return 259;
}
