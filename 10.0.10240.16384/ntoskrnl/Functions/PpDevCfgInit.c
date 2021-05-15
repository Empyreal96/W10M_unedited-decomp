// PpDevCfgInit 
 
int PpDevCfgInit()
{
  int v0; // r5
  int v2; // r2
  int v3; // [sp+4h] [bp-9Ch]
  char v4; // [sp+20h] [bp-80h] BYREF
  int v5; // [sp+24h] [bp-7Ch] BYREF
  int v6; // [sp+28h] [bp-78h] BYREF
  __int16 v7[2]; // [sp+30h] [bp-70h] BYREF
  const __int16 *v8; // [sp+34h] [bp-6Ch]
  int v9; // [sp+38h] [bp-68h] BYREF
  int v10[24]; // [sp+40h] [bp-60h] BYREF

  memset(v10, 0, 72);
  v10[0] = (int)DEVPKEY_DriverDatabase_ConfigMode;
  v10[1] = 7;
  v10[2] = (int)&v5;
  v10[3] = 4;
  v10[6] = (int)DEVPKEY_DriverDatabase_ConfigOptions;
  v10[7] = 7;
  v10[8] = (int)&v6;
  v10[9] = 4;
  v10[12] = (int)DEVPKEY_DriverDatabase_Updated;
  v10[13] = 17;
  v10[14] = (int)&v4;
  v10[15] = 1;
  v0 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, (int)L"SYSTEM", 6, 0, v10, 3u);
  if ( v0 >= 0 )
  {
    if ( v10[5] >= 0 )
      return sub_96F4AC();
    v5 = 3;
    if ( v10[11] < 0 )
      v6 = 0;
    if ( v10[17] < 0 )
      v4 = 0;
    v7[1] = 28;
    v7[0] = 26;
    v8 = L"DeviceInstall";
    if ( PipOpenServiceEnumKeys((int)v7, 131097, &v9, 0, 0) >= 0 )
    {
      ZwClose();
      v2 = PiDevCfgFlags | 2;
      PiDevCfgFlags |= 2u;
    }
    else
    {
      v2 = PiDevCfgFlags;
    }
    PiDevCfgOptions = v6;
    PiDevCfgMode = v5;
    if ( v4 == -1 )
    {
      v2 |= 1u;
      PiDevCfgFlags = v2;
    }
    if ( v5 && (v2 & 1) != 0 )
    {
      v0 = PiDmEnumObjectsWithCallback(
             1,
             (int (__fastcall *)(unsigned int *, int, char *))PiDevCfgInitDeviceCallback,
             0);
      if ( v0 >= 0 )
        PiDevCfgSetObjectProperty(
          PiPnpRtlCtx,
          0,
          (int)L"SYSTEM",
          6,
          0,
          v3,
          (int)DEVPKEY_DriverDatabase_Updated,
          0,
          0,
          0);
    }
  }
  return v0;
}
