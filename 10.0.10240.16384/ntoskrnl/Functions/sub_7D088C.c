// sub_7D088C 
 
int sub_7D088C(int a1, _DWORD *a2, int a3, int a4, ...)
{
  _DWORD *v5; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r4
  _DWORD v9[8]; // [sp-20h] [bp-20h] BYREF
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( !a2 || (*a2 & 0x6000200) == 0 )
    goto LABEL_10;
  if ( !WmiQueryTraceProviderCount() )
  {
    RtlInitUnicodeString((unsigned int)va, L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FileInfo");
    v7 = ZwLoadDriver();
    if ( v7 < 0 && v7 != -1073741554 )
    {
      v8 = -1073741204;
      return ((int (__fastcall *)(int, _DWORD, _DWORD, _DWORD))v9[7])(v8, v9[0], v9[1], v9[2]);
    }
    *v5 = 1;
    v6 = 1;
  }
  v8 = EtwpUpdateFileInfoDriverRegistration();
  if ( v8 >= 0 )
  {
LABEL_10:
    v8 = 0;
    v6 = 0;
  }
  if ( v6 )
  {
    RtlInitUnicodeString((unsigned int)v9, L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FileInfo");
    ZwUnloadDriver();
    *v5 = 0;
  }
  return ((int (__fastcall *)(int, _DWORD, _DWORD, _DWORD))v9[7])(v8, v9[0], v9[1], v9[2]);
}
