// ViGenericSetSecurity 
 
int __fastcall ViGenericSetSecurity(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_SET_SECURITY, 21);
}
