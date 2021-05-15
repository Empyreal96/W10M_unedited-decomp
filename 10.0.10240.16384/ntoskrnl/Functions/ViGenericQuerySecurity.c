// ViGenericQuerySecurity 
 
int __fastcall ViGenericQuerySecurity(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_QUERY_SECURITY, 20);
}
