// ViGenericPower 
 
int __fastcall ViGenericPower(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_POWER, 22);
}
