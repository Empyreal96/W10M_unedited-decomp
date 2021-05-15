// ViGenericClose 
 
int __fastcall ViGenericClose(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, pXdvIRP_MJ_CLOSE, 2);
}
