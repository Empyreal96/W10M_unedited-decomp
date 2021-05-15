// -SmEvictKeys@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAT_SM_PAGE_KEY@@KPAU-$SMKM_STORE@USM_TRAITS@@@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmEvictKeys(int a1, int *a2, int a3, int a4)
{
  int v4; // r3
  int v6[2]; // [sp+0h] [bp-8h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  v4 = *(_DWORD *)(a4 + 3512);
  v6[0] = *a2;
  return ((int (__fastcall *)(_DWORD *, int *, int, int))SMKM_STORE_MGR<SM_TRAITS>::SmFeStoreEvictKeys)(
           SmGlobals,
           v6,
           a3,
           v4 & 0x1F);
}
