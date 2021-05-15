// PiDevCfgLogDeviceMigrated 
 
int __fastcall PiDevCfgLogDeviceMigrated(int result, int a2, int a3)
{
  unsigned __int16 *v3; // r4
  unsigned __int16 *v4; // r2

  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x180000) == 1572864 )
  {
    if ( a3 < 0 )
    {
      if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x100000) != 0 )
      {
        v4 = *(unsigned __int16 **)(a2 + 84);
        if ( !v4 )
          v4 = (unsigned __int16 *)&dword_8CA6A8;
        result = Template_zzjzxtq(
                   Microsoft_Windows_Kernel_PnPHandle,
                   dword_649E54,
                   (int)KMPnPEvt_DeviceMigrate_Failure,
                   (int)&Microsoft_Windows_Kernel_PnPHandle,
                   *(unsigned __int16 **)(result + 4),
                   *(unsigned __int16 **)(a2 + 16),
                   a2 + 40,
                   v4);
      }
    }
    else if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x80000) != 0 )
    {
      v3 = *(unsigned __int16 **)(a2 + 84);
      if ( !v3 )
        v3 = (unsigned __int16 *)&dword_8CA6A8;
      result = Template_zzjzxtq(
                 Microsoft_Windows_Kernel_PnPHandle,
                 dword_649E54,
                 (int)KMPnPEvt_DeviceMigrate_Success,
                 (int)&Microsoft_Windows_Kernel_PnPHandle,
                 *(unsigned __int16 **)(result + 4),
                 *(unsigned __int16 **)(a2 + 16),
                 a2 + 40,
                 v3);
    }
  }
  return result;
}
