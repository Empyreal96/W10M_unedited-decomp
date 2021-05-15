// -SmPrioritizeRegionsStore@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmPrioritizeRegionsStore(int a1, int a2)
{
  int result; // r0

  result = SMKM_STORE<SM_TRAITS>::SmStPrioritizeRegionsStore(a2, 1);
  if ( result >= 0 )
  {
    KiSetTimerEx(a1 + 5792, 0x493E0u, 0i64, 300000, 0, a1 + 5840);
    result = 0;
  }
  return result;
}
