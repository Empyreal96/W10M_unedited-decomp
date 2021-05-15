// ViGenericFileSystemControl 
 
int __fastcall ViGenericFileSystemControl(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_FILE_SYSTEM_CONTROL, 13);
}
