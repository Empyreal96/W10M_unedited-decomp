// PiDevCfgConfigureDeviceInterfaces 
 
int __fastcall PiDevCfgConfigureDeviceInterfaces(int a1, int a2)
{
  int result; // r0
  __int16 v3[2]; // [sp+24h] [bp-A0h] BYREF
  const __int16 *v4; // [sp+28h] [bp-9Ch]
  int v5; // [sp+34h] [bp-90h]
  int v6; // [sp+38h] [bp-8Ch]
  __int16 *v7; // [sp+3Ch] [bp-88h]
  int v8; // [sp+40h] [bp-84h]
  int v9; // [sp+44h] [bp-80h]
  int v10; // [sp+48h] [bp-7Ch]
  int v11; // [sp+58h] [bp-6Ch]
  int v12; // [sp+74h] [bp-50h]

  v3[1] = 22;
  v3[0] = 20;
  v4 = L"Interfaces";
  v5 = 24;
  v6 = a2;
  v8 = 576;
  v7 = v3;
  v9 = 0;
  v10 = 0;
  v11 = a1;
  v12 = 131097;
  if ( ZwOpenKey() == -1073741772 )
    result = 0;
  else
    result = sub_7E450C();
  return result;
}
