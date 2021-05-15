// PiDevCfgConfigureDeviceInterfaceCallback 
 
int __fastcall PiDevCfgConfigureDeviceInterfaceCallback(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r0

  if ( (int)a4[2] >= 0 )
  {
    v5 = PiDevCfgConfigureDeviceInterface(a2, *a4, a4[1]);
    if ( v5 < 0 )
      a4[2] = v5;
  }
  return 0;
}
