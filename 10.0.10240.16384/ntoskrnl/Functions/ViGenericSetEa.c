// ViGenericSetEa 
 
int __fastcall ViGenericSetEa(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_SET_EA, 8);
}
