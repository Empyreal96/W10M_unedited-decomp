// ViGenericCleanup 
 
int __fastcall ViGenericCleanup(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, pXdvIRP_MJ_CLEANUP, 18);
}
