// _CmGetDeviceLogConfKeyPath 
 
int __fastcall CmGetDeviceLogConfKeyPath(int a1, unsigned __int16 *a2, int a3, int a4, int a5, int a6, unsigned int a7, unsigned int *a8)
{
  unsigned int v8; // r3
  int result; // r0

  if ( (a3 & 0xFFFFFFEB) != 0 )
    return -1073741811;
  v8 = wcslen(a2) + 39;
  if ( a8 )
    *a8 = v8;
  if ( v8 > a7 )
    result = -1073741789;
  else
    result = RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"%s\\%s\\%s");
  return result;
}
