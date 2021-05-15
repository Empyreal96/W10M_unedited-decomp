// PnpWaitForEmptyDeviceActionQueue 
 
int PnpWaitForEmptyDeviceActionQueue()
{
  return KeWaitForSingleObject((unsigned int)&PnpEnumerationLock, 0, 0, 0, 0);
}
