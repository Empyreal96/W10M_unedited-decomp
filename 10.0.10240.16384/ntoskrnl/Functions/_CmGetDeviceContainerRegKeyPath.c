// _CmGetDeviceContainerRegKeyPath 
 
int __fastcall CmGetDeviceContainerRegKeyPath(int a1, unsigned __int16 *a2, int a3, int a4, int a5, int a6, unsigned int a7, unsigned int *a8)
{
  int result; // r0
  unsigned int v10; // r3

  if ( !a3 || (a3 & 0xFFFFFEAF) != 0 )
    return -1073741811;
  result = CmValidateDeviceContainerName();
  if ( result >= 0 )
  {
    v10 = wcslen(a2) + 51;
    if ( a8 )
      *a8 = v10;
    if ( v10 > a7 )
      result = -1073741789;
    else
      result = RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"System\\CurrentControlSet\\Control\\DeviceContainers\\%s");
  }
  return result;
}
