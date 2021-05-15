// ViGenericCreate 
 
int __fastcall ViGenericCreate(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, pXdvIRP_MJ_CREATE, 0);
}
