// ViGenericWrite 
 
int __fastcall ViGenericWrite(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_WRITE, 4);
}
