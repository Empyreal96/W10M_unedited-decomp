// ViGenericSetInformation 
 
int __fastcall ViGenericSetInformation(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_SET_INFORMATION, 6);
}
