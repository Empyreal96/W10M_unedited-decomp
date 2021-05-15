// PiDevCfgEnforceDevicePolicy 
 
int PiDevCfgEnforceDevicePolicy()
{
  int result; // r0
  __int16 v1[2]; // [sp+28h] [bp-40h] BYREF
  const __int16 *v2; // [sp+2Ch] [bp-3Ch]
  int v3; // [sp+30h] [bp-38h]
  int v4; // [sp+34h] [bp-34h]
  __int16 *v5; // [sp+38h] [bp-30h]
  int v6; // [sp+3Ch] [bp-2Ch]
  int v7; // [sp+40h] [bp-28h]
  int v8; // [sp+44h] [bp-24h]

  v1[1] = 136;
  v1[0] = 134;
  v2 = L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\DeviceInstall";
  v3 = 24;
  v4 = 0;
  v5 = v1;
  v7 = 0;
  v8 = 0;
  v6 = 576;
  if ( ZwOpenKey() != -1073741772 )
    JUMPOUT(0x7E3EB0);
  if ( PnpBootMode )
    result = sub_7E3E7C();
  else
    result = 0;
  return result;
}
