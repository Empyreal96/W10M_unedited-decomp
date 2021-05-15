// PiDevCfgLogDeviceStarted 
 
unsigned int PiDevCfgLogDeviceStarted()
{
  _DWORD v1[2]; // [sp+1Ch] [bp-C8h] BYREF
  _DWORD v2[2]; // [sp+24h] [bp-C0h] BYREF
  _DWORD v3[2]; // [sp+2Ch] [bp-B8h] BYREF
  _DWORD v4[44]; // [sp+34h] [bp-B0h] BYREF

  v3[0] = 0;
  v3[1] = 0;
  v4[0] = 0;
  v4[1] = 0;
  v1[0] = 0;
  v1[1] = 0;
  v2[0] = 0;
  v2[1] = 0;
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x180000) == 1572864 )
    return sub_7F05F8();
  RtlFreeAnsiString(v3);
  RtlFreeAnsiString(v4);
  RtlFreeAnsiString(v1);
  return RtlFreeAnsiString(v2);
}
