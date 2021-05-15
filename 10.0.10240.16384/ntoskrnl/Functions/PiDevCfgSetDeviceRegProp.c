// PiDevCfgSetDeviceRegProp 
 
int __fastcall PiDevCfgSetDeviceRegProp(int a1, _DWORD *a2, int a3, int a4, int a5, int a6)
{
  int v6; // r5

  v6 = 0;
  if ( (*a2 & 1) != 0 )
    v6 = 0x20000;
  return CmSetDeviceRegProp(a1, a2[1], a2[2], a3, a4, a5, a6, v6);
}
