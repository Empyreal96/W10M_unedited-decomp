// RawUnload 
 
int RawUnload()
{
  ObfDereferenceObject(RawDeviceTapeObject);
  ObfDereferenceObject(RawDeviceCdRomObject);
  return ObfDereferenceObject(RawDeviceDiskObject);
}
