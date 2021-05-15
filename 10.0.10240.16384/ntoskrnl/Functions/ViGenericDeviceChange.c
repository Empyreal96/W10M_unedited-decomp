// ViGenericDeviceChange 
 
int __fastcall ViGenericDeviceChange(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, pXdvIRP_MJ_DEVICE_CHANGE, 24);
}
