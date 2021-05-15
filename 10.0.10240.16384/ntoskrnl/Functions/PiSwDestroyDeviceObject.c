// PiSwDestroyDeviceObject 
 
int __fastcall PiSwDestroyDeviceObject(_DWORD *a1)
{
  int v2; // r4

  v2 = a1[10];
  PiSwUnassociateDeviceObject(a1);
  *(_DWORD *)(v2 + 4) |= 0x10u;
  return IoDeleteDevice(a1);
}
