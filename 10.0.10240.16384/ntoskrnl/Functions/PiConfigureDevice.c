// PiConfigureDevice 
 
int __fastcall PiConfigureDevice(int a1)
{
  int v2; // r0
  int v3; // r2
  int v4; // r3

  v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 176) + 20);
  v3 = *(_DWORD *)(v2 + 172);
  if ( v3 == 787 || v3 == 788 )
    return -1073741738;
  if ( v3 != 768 && (v3 <= 781 || v3 > 785) )
  {
    v4 = *(_DWORD *)(a1 + 12);
    switch ( v4 )
    {
      case 21:
        return PpDevCfgProcessDevice();
      case 22:
        return PpDevCfgProcessDeviceClass(v2);
      case 23:
        return PpDevCfgProcessDeviceExtensions(v2);
      case 24:
        return PpDevCfgProcessDeviceReset(v2);
    }
  }
  return -1073741823;
}
