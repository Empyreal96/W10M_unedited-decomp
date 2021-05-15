// _CmGetDeviceInstanceKeyPath 
 
int __fastcall CmGetDeviceInstanceKeyPath(int a1, unsigned __int16 *a2, __int16 a3, int a4, int a5, int a6, unsigned int a7, unsigned int *a8)
{
  unsigned int v8; // r3
  unsigned int v10; // r3

  if ( (a3 & 0x200) != 0 )
  {
    if ( a4 )
      return sub_7C6B74();
    v10 = wcslen(a2) + 82;
    if ( a8 )
      *a8 = v10;
    if ( v10 <= a7 )
      return RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"%s\\%s\\%s");
  }
  else
  {
    v8 = wcslen(a2) + 31;
    if ( a8 )
      *a8 = v8;
    if ( v8 <= a7 )
      return RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"%s\\%s");
  }
  return -1073741789;
}
