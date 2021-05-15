// ViGenericPnp 
 
int __fastcall ViGenericPnp(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_PNP, 27);
}
