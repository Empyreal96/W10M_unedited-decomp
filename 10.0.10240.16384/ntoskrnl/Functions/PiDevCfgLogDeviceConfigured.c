// PiDevCfgLogDeviceConfigured 
 
unsigned int __fastcall PiDevCfgLogDeviceConfigured(int a1, int a2, int a3)
{
  _DWORD v4[6]; // [sp+3Ch] [bp-A8h] BYREF
  _DWORD v5[36]; // [sp+54h] [bp-90h] BYREF

  v4[4] = a1;
  v4[0] = 0;
  v5[0] = 0;
  v4[1] = 0;
  v4[2] = a3;
  v5[8] = a2;
  v4[3] = 1;
  v5[1] = 0;
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x180000) == 1572864 )
    return sub_7E35C8();
  RtlFreeAnsiString(v4);
  return RtlFreeAnsiString(v5);
}
