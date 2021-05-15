// ViGenericCreateNamedPipe 
 
int __fastcall ViGenericCreateNamedPipe(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, pXdvIRP_MJ_CREATE_NAMED_PIPE, 1);
}
