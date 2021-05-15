// IovBuildDeviceIoControlRequest 
 
int __fastcall IovBuildDeviceIoControlRequest(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9)
{
  int v9; // r4

  v9 = ((int (__fastcall *)(int, int, int, int, int, int, _DWORD, int, int))pXdvIoBuildDeviceIoControlRequest)(
         a1,
         a2,
         a3,
         a4,
         a5,
         a6,
         a7,
         a8,
         a9);
  if ( v9 )
    VfSetIoBuildRequest();
  return v9;
}
