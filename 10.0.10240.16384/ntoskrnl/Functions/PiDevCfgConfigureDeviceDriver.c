// PiDevCfgConfigureDeviceDriver 
 
int __fastcall PiDevCfgConfigureDeviceDriver(int a1, int a2, int a3)
{
  int result; // r0

  result = PiDevCfgConfigureDeviceDriverConfiguration(a1, a2, *(_DWORD *)(a3 + 16), -1);
  if ( result >= 0 && *(_DWORD *)(a3 + 208) != a3 + 208 )
    result = sub_7E42B0();
  return result;
}
