// PiDevCfgVerifyDeviceAllowed 
 
int __fastcall PiDevCfgVerifyDeviceAllowed(int a1, int a2)
{
  __int16 v3[2]; // [sp+8h] [bp-40h] BYREF
  const __int16 *v4; // [sp+Ch] [bp-3Ch]
  _DWORD v5[14]; // [sp+10h] [bp-38h] BYREF

  v5[0] = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v3[1] = 14;
  v3[0] = 12;
  v4 = L"Status";
  v5[4] = 24;
  v5[5] = a2;
  v5[7] = 576;
  v5[6] = v3;
  v5[8] = 0;
  v5[9] = 0;
  if ( ZwOpenKey() >= 0 )
    return sub_7E42E4();
  PiDevCfgFreeResolveContext(v5);
  return 0;
}
