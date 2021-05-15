// PiCMFastIoDeviceDispatch 
 
int __fastcall PiCMFastIoDeviceDispatch(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8)
{
  *a8 = PiCMHandleIoctl(a3, a4, a5, a6, a8 + 1, a7, a3, a4);
  return 1;
}
