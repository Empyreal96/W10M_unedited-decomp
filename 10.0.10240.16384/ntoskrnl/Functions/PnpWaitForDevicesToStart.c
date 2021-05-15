// PnpWaitForDevicesToStart 
 
BOOL PnpWaitForDevicesToStart()
{
  return PnpWaitForEmptyDeviceActionQueue() >= 0;
}
