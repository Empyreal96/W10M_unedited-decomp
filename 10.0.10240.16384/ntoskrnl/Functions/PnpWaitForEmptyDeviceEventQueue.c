// PnpWaitForEmptyDeviceEventQueue 
 
int PnpWaitForEmptyDeviceEventQueue()
{
  return KeWaitForSingleObject((unsigned int)&PnpEventQueueEmpty, 0, 0, 0, 0);
}
