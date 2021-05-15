// PopDiagDeviceRundownWorker 
 
int PopDiagDeviceRundownWorker()
{
  unsigned int v0; // r1

  __dmb(0xBu);
  do
    v0 = __ldrex(&PopDiagDeviceRundownRequests);
  while ( __strex(0, &PopDiagDeviceRundownRequests) );
  __dmb(0xBu);
  return IoDiagTraceDevicesRundown();
}
