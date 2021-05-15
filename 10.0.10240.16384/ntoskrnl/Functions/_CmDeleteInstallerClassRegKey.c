// _CmDeleteInstallerClassRegKey 
 
int __fastcall CmDeleteInstallerClassRegKey(int a1, int a2, int a3)
{
  int result; // r0

  if ( !a3 || (a3 & 0xFFFFFCDF) != 0 )
    result = -1073741811;
  else
    result = CmDeleteCommonClassRegKey(a1, a2, a3, 0, 1u);
  return result;
}
