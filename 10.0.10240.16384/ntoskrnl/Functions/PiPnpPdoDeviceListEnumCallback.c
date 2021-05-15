// PiPnpPdoDeviceListEnumCallback 
 
int __fastcall PiPnpPdoDeviceListEnumCallback(int a1, int *a2)
{
  int v2; // r5
  int v3; // r4

  v2 = *(_DWORD *)(a1 + 16);
  v3 = PiPnpAddDeviceToPdoDeviceListEnumContext(a2, v2);
  if ( v3 >= 0 )
    ObfReferenceObject(v2);
  return v3;
}
