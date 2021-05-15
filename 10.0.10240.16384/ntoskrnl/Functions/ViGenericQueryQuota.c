// ViGenericQueryQuota 
 
int __fastcall ViGenericQueryQuota(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_QUERY_QUOTA, 25);
}
