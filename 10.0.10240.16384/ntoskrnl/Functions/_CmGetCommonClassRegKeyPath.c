// _CmGetCommonClassRegKeyPath 
 
int __fastcall CmGetCommonClassRegKeyPath(int a1, unsigned __int16 *a2, __int16 a3, int a4, int a5, int a6, unsigned int a7, unsigned int *a8)
{
  int v10; // r5
  int result; // r0
  __int16 *v12; // r5
  unsigned int v13; // r6

  if ( (a3 & 0x60) == 96 )
    return -1073741811;
  if ( (unsigned __int8)a3 == 32 )
  {
    v10 = 2;
    result = CmValidateInstallerClassName();
    goto LABEL_4;
  }
  if ( (unsigned __int8)a3 != 64 )
    return -1073741811;
  v10 = 4;
  result = CmValidateInstallerClassName();
LABEL_4:
  if ( result >= 0 )
  {
    if ( v10 == 2 )
      v12 = L"System\\CurrentControlSet\\Control\\Class";
    else
      v12 = L"System\\CurrentControlSet\\Control\\DeviceClasses";
    if ( (a3 & 0x200) != 0 )
    {
      result = sub_7C71A0();
    }
    else
    {
      v13 = wcslen((unsigned __int16 *)v12) + 1;
      if ( a2 )
        v13 += wcslen(a2) + 1;
      if ( a8 )
        *a8 = v13;
      if ( v13 > a7 )
      {
        result = -1073741789;
      }
      else if ( a2 )
      {
        result = RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"%s\\%s");
      }
      else
      {
        result = RtlStringCchPrintfExW(a6, a7, 0, 0, 2048, L"%s");
      }
    }
  }
  return result;
}
