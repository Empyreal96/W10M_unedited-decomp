// PiProcessHaltDevice 
 
int __fastcall PiProcessHaltDevice(int a1)
{
  _DWORD *v2; // r0
  int v3; // r1
  int v5; // r2

  v2 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 176) + 20);
  v3 = v2[43];
  if ( v3 == 787 || v3 == 788 )
    return -1073741738;
  if ( (*(_DWORD *)(a1 + 20) & 0xFFFFFFFE) != 0 )
    return -1073741584;
  v5 = v2[67];
  if ( (v5 & 0x1001) != 0 || (v5 & 1) == 0 && v2[97] )
    return -1073741808;
  if ( v3 != 776 )
    return -1073741436;
  PnpRequestDeviceRemoval((int)v2, 0, 44);
  return 0;
}
