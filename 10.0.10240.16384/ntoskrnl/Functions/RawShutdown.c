// RawShutdown 
 
int __fastcall RawShutdown(int a1, int a2)
{
  RawScanDeletedList();
  IoUnregisterFileSystem(RawDeviceDiskObject);
  IoUnregisterFileSystem(RawDeviceCdRomObject);
  IoUnregisterFileSystem(RawDeviceTapeObject);
  IoDeleteDevice((_DWORD *)RawDeviceTapeObject);
  IoDeleteDevice((_DWORD *)RawDeviceCdRomObject);
  IoDeleteDevice((_DWORD *)RawDeviceDiskObject);
  *(_DWORD *)(a2 + 24) = 0;
  IofCompleteRequest(a2, 1);
  return 0;
}
