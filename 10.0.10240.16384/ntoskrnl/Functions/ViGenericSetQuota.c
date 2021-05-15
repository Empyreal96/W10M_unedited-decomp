// ViGenericSetQuota 
 
int __fastcall ViGenericSetQuota(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_SET_QUOTA, 26);
}
