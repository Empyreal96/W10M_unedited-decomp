// -SmStorePrepare@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStorePrepare(int a1)
{
  int v1; // r2
  int result; // r0
  int v4; // [sp+0h] [bp-18h] BYREF
  int v5; // [sp+4h] [bp-14h]
  _DWORD v6[4]; // [sp+8h] [bp-10h] BYREF

  v4 = 1049089;
  v5 = 20;
  v6[0] = 1048704;
  v6[1] = 1049089;
  v1 = *(_DWORD *)(a1 + 5888);
  if ( (v1 & 2) != 0 )
    v5 = 1048596;
  if ( (v1 & 1) == 0 )
    return sub_50B7B8();
  result = SmFpPreAllocate(a1 + 5720, &v4, 2);
  if ( result >= 0 )
  {
    result = SmFpPreAllocate(a1 + 5656, v6, 2);
    if ( result >= 0 )
      result = 0;
  }
  return result;
}
