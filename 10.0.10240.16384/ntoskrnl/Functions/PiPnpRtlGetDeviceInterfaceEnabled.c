// PiPnpRtlGetDeviceInterfaceEnabled 
 
int __fastcall PiPnpRtlGetDeviceInterfaceEnabled(int a1, int a2, _BYTE *a3)
{
  int result; // r0

  result = ZwPlugPlayControl();
  *a3 = 0;
  return result;
}
