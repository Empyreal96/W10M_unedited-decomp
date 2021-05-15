// ViGenericInternalDeviceControl 
 
int __fastcall ViGenericInternalDeviceControl(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_INTERNAL_DEVICE_CONTROL, 15);
}
