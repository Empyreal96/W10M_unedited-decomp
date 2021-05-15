// -SmStDirectReadComplete@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@PAU_ST_WORK_ITEM@-$ST_STORE@USM_TRAITS@@@@J@Z 
 
int SMKM_STORE<SM_TRAITS>::SmStDirectReadComplete(int a1, int a2, ...)
{
  va_list varg_r2; // [sp+18h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  return SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFree(a1, a1, a2, (int *)varg_r2);
}
