// _CmGetDeviceInterfaceSymbolicLinkName 
 
int __fastcall CmGetDeviceInterfaceSymbolicLinkName(int a1, unsigned __int16 *a2, _WORD *a3, unsigned int a4, unsigned int *a5)
{
  int result; // r0
  unsigned __int16 *v9; // r4
  _WORD *v10; // r0
  unsigned int v11; // r0
  unsigned int v12; // r3

  result = CmValidateDeviceInterfaceName(a1, a2);
  if ( result >= 0 )
  {
    v9 = a2 + 4;
    v10 = wcschr(v9, 92);
    if ( v10 )
      v11 = v10 - v9;
    else
      v11 = wcslen(v9);
    if ( v11 <= 0x27 )
    {
      result = -1073741773;
    }
    else
    {
      v12 = v11 + 1;
      if ( a5 )
        *a5 = v12;
      if ( v12 > a4 )
        result = -1073741789;
      else
        result = RtlStringCchCopyNExW(a3, a4, (int)v9, v11, 0, 0, 2048);
    }
  }
  return result;
}
