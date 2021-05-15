// _CmGetDeviceSoftwareKeyPath 
 
int __fastcall CmGetDeviceSoftwareKeyPath(int a1, int a2, __int16 a3, int a4, int a5, int a6, unsigned int a7, unsigned int *a8)
{
  int result; // r0
  unsigned int v10; // r3
  unsigned __int16 v11[56]; // [sp+18h] [bp-70h] BYREF

  result = CmGetDeviceSoftwareKey(a1, a2, v11);
  if ( result >= 0 )
  {
    if ( (a3 & 0x200) != 0 )
    {
      result = sub_7EF138();
    }
    else
    {
      v10 = wcslen(v11) + 40;
      if ( a8 )
        *a8 = v10;
      if ( v10 > a7 )
        result = -1073741789;
      else
        result = RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"%s\\%s");
    }
  }
  return result;
}
