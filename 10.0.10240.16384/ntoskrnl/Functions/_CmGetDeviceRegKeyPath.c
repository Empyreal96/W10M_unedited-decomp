// _CmGetDeviceRegKeyPath 
 
int __fastcall CmGetDeviceRegKeyPath(int a1, int a2, int a3, int a4, unsigned __int8 a5, int a6, int a7, int a8)
{
  int result; // r0

  if ( !a3 || (a3 & 0xFFFFFCE8) != 0 )
    return -1073741811;
  result = CmValidateDeviceName();
  if ( result < 0 )
    return result;
  if ( (unsigned __int8)a3 != 16 )
  {
    switch ( (unsigned __int8)a3 )
    {
      case 0x12u:
        return CmGetDeviceSoftwareKeyPath(a1, a2, a3, a4, a5, a6, a7, a8);
      case 0x11u:
        return CmGetDeviceHardwareKeyPath();
      case 0x13u:
        return CmGetDeviceControlKeyPath();
      case 0x14u:
        return CmGetDeviceLogConfKeyPath();
    }
    return -1073741811;
  }
  return CmGetDeviceInstanceKeyPath();
}
