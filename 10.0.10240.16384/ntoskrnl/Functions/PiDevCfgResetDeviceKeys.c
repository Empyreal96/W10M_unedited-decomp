// PiDevCfgResetDeviceKeys 
 
int __fastcall PiDevCfgResetDeviceKeys(int a1, int a2, int a3)
{
  int v5; // r0
  int v6; // r4
  __int16 v8[2]; // [sp+18h] [bp-30h] BYREF
  const __int16 *v9; // [sp+1Ch] [bp-2Ch]
  int v10; // [sp+20h] [bp-28h]
  int v11; // [sp+24h] [bp-24h]
  __int16 *v12; // [sp+28h] [bp-20h]
  int v13; // [sp+2Ch] [bp-1Ch]
  int v14; // [sp+30h] [bp-18h]
  int v15; // [sp+34h] [bp-14h]

  v8[1] = 40;
  v8[0] = 38;
  v9 = L"Configuration\\Reset";
  v10 = 24;
  v11 = a3;
  v13 = 576;
  v12 = v8;
  v14 = 0;
  v15 = 0;
  v5 = ZwOpenKey();
  v6 = v5;
  if ( v5 == -1073741772 )
    return 0;
  if ( v5 >= 0 )
    v6 = PiDevCfgEnumDeviceKeys(
           a1,
           a2,
           0,
           -1,
           0,
           (int (__fastcall *)(int, int, __int16 **, int, int, int))PiDevCfgResetDeviceKeyCallback,
           0);
  return v6;
}
