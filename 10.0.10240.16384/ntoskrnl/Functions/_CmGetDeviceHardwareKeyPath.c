// _CmGetDeviceHardwareKeyPath 
 
int __fastcall CmGetDeviceHardwareKeyPath(int a1, unsigned __int16 *a2, __int16 a3, int a4, int a5, int a6, unsigned int a7, unsigned int *a8)
{
  unsigned int v9; // r3
  unsigned int v10; // r3

  if ( (a3 & 0x200) != 0 )
    return sub_7E8C74();
  if ( (a3 & 0x100) == 0 )
  {
    v9 = wcslen(a2) + 49;
    if ( a8 )
      *a8 = v9;
    if ( v9 <= a7 )
      return RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"%s\\%s\\%s");
    return -1073741789;
  }
  v10 = wcslen(a2) + 31;
  if ( a8 )
    *a8 = v10;
  if ( v10 > a7 )
    return -1073741789;
  return RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"%s\\%s");
}
