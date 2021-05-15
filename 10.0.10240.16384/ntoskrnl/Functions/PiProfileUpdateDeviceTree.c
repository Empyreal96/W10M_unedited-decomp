// PiProfileUpdateDeviceTree 
 
int PiProfileUpdateDeviceTree()
{
  _DWORD *v0; // r0

  v0 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 538996816);
  if ( !v0 )
    return -1073741670;
  v0[2] = PiProfileUpdateDeviceTreeWorker;
  v0[3] = v0;
  *v0 = 0;
  ExQueueWorkItem(v0, 0);
  return 0;
}
