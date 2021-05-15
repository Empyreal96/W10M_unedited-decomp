// PiDevCfgConfigureDeviceDriverConfiguration 
 
int __fastcall PiDevCfgConfigureDeviceDriverConfiguration(int a1, int a2, int a3, int a4, int a5)
{
  int result; // r0

  if ( (a4 & 1) == 0
    || (result = PiDevCfgCopyObjectProperties(PiPnpRtlCtx, a2, a3, a3, *(_DWORD *)(a1 + 24), 1, *(_DWORD *)(a2 + 8)),
        result >= 0) )
  {
    result = PiDevCfgConfigureDeviceKeys(a1, a2, a3, a4, a5);
  }
  return result;
}
