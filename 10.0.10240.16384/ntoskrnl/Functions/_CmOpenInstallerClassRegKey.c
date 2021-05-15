// _CmOpenInstallerClassRegKey 
 
int __fastcall CmOpenInstallerClassRegKey(int *a1, unsigned __int16 *a2, int a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  return CmOpenCommonClassRegKey(a1, a2, 32, 0, a5, a6, a7, a8);
}
