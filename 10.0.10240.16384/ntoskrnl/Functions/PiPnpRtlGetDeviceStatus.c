// PiPnpRtlGetDeviceStatus 
 
int __fastcall PiPnpRtlGetDeviceStatus(int a1, int a2, int a3, int a4, int a5)
{
  return PlugPlayGetDeviceStatus(a2, a3, a4, a5);
}
