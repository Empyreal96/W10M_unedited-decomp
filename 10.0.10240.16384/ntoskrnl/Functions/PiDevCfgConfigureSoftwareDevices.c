// PiDevCfgConfigureSoftwareDevices 
 
int __fastcall PiDevCfgConfigureSoftwareDevices(int a1, int a2)
{
  int result; // r0
  __int16 v3[2]; // [sp+18h] [bp-40h] BYREF
  const __int16 *v4; // [sp+1Ch] [bp-3Ch]
  int v5; // [sp+20h] [bp-38h]
  int v6; // [sp+24h] [bp-34h]
  __int16 *v7; // [sp+28h] [bp-30h]
  int v8; // [sp+2Ch] [bp-2Ch]
  int v9; // [sp+30h] [bp-28h]
  int v10; // [sp+34h] [bp-24h]

  v3[1] = 16;
  v3[0] = 14;
  v5 = 24;
  v6 = a2;
  v8 = 576;
  v7 = v3;
  v9 = 0;
  v10 = 0;
  v4 = L"Devices";
  if ( ZwOpenKey() == -1073741772 )
    result = 0;
  else
    result = sub_7E4410();
  return result;
}
