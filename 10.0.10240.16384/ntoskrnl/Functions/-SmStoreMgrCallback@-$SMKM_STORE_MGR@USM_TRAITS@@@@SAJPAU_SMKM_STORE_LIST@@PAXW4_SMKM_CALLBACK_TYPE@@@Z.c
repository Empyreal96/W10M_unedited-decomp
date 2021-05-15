// -SmStoreMgrCallback@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU_SMKM_STORE_LIST@@PAXW4_SMKM_CALLBACK_TYPE@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStoreMgrCallback(int a1, int a2, int a3)
{
  int (__fastcall *v6)(int, int, int); // r3
  int result; // r0

  switch ( a3 )
  {
    case 1:
      SMKM_STORE<SM_TRAITS>::SmStCleanup(a2);
      ExFreePoolWithTag(a2);
      break;
    case 7:
      *(_BYTE *)(a2 + 3517) |= 2u;
      break;
    case 2:
      SMKM_STORE_MGR<SM_TRAITS>::SmFeStoreDelete(a1, *(_DWORD *)(a2 + 3512) & 0x1F);
      break;
    case 4:
      SMKM_STORE_MGR<SM_TRAITS>::SmFeEmpty(a1);
      break;
  }
  v6 = *(int (__fastcall **)(int, int, int))(a1 + 5892);
  if ( v6 )
    result = v6(a1, a2, a3);
  else
    result = 0;
  return result;
}
