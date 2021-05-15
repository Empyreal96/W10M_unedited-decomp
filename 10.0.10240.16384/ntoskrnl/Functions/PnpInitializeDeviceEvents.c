// PnpInitializeDeviceEvents 
 
int PnpInitializeDeviceEvents()
{
  int result; // r0

  PnpDeviceEventList = ExAllocatePoolWithTag(512, 76, 1248882256);
  if ( PnpDeviceEventList )
    result = sub_9705D8();
  else
    result = -1073741670;
  return result;
}
