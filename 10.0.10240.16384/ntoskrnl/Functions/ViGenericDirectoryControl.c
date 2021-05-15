// ViGenericDirectoryControl 
 
int __fastcall ViGenericDirectoryControl(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, pXdvIRP_MJ_DIRECTORY_CONTROL, 12);
}
