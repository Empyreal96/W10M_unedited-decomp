// ViGenericQueryEa 
 
int __fastcall ViGenericQueryEa(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_QUERY_EA, 7);
}
