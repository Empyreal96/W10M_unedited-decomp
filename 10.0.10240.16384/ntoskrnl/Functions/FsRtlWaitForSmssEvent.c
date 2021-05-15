// FsRtlWaitForSmssEvent 
 
int __fastcall FsRtlWaitForSmssEvent(unsigned int a1)
{
  KeWaitForSingleObject(a1, 0, 0, 0, 0);
  FsRtlpVolumeStartupApplicationsComplete = 1;
  return ObfDereferenceObject(a1);
}
