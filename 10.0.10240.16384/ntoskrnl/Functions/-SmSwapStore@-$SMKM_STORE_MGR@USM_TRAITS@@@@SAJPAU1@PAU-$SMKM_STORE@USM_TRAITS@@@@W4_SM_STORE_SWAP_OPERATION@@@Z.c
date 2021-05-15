// -SmSwapStore@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@W4_SM_STORE_SWAP_OPERATION@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmSwapStore(int a1, _DWORD *a2, int a3)
{
  int result; // r0

  if ( (*a2 & 0x40000) == 0 )
    return -1073741637;
  if ( a3 != 1 && a3
    || (result = SMKM_STORE_MGR<SM_TRAITS>::SmPerformStoreMaintenance(a1, (int)a2, 1), result >= 0)
    && (a3 || (result = SMKM_STORE_MGR<SM_TRAITS>::SmPerformStoreMaintenance(a1, (int)a2, 2), result >= 0)) )
  {
    result = SMKM_STORE<SM_TRAITS>::SmStSwapStore(a2, a3);
    if ( result >= 0 )
    {
      if ( a3 == 2 )
        SMKM_STORE_MGR<SM_TRAITS>::SmPerformStoreMaintenance(a1, (int)a2, 3);
      result = 0;
    }
  }
  return result;
}
