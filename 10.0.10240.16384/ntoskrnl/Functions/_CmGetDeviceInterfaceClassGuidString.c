// _CmGetDeviceInterfaceClassGuidString 
 
int __fastcall CmGetDeviceInterfaceClassGuidString(int a1, unsigned __int16 *a2, unsigned __int16 *a3)
{
  int result; // r0

  result = CmGetDeviceInterfaceSubkeyPath(a1, a2, 1, a3, 0, 0);
  if ( !result )
    return -1073741595;
  if ( result == -1073741789 )
  {
    a3[38] = 0;
    result = 0;
  }
  return result;
}
