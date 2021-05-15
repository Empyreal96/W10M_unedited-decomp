// ViGenericCreateMailslot 
 
int __fastcall ViGenericCreateMailslot(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, pXdvIRP_MJ_CREATE_MAILSLOT, 19);
}
