// PipAddDevicesToBootDriverWorker 
 
int __fastcall PipAddDevicesToBootDriverWorker(int a1, int a2)
{
  int v2; // r0
  int v3; // r1
  int v4; // r4

  v2 = PnpDeviceObjectFromDeviceInstance(a2);
  v4 = v2;
  if ( v2 )
  {
    PiProcessAddBootDevices(v2, v3);
    ObfDereferenceObjectWithTag(v4);
  }
  return 1;
}
