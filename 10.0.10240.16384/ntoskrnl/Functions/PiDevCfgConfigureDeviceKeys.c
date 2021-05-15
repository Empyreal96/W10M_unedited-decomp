// PiDevCfgConfigureDeviceKeys 
 
int __fastcall PiDevCfgConfigureDeviceKeys(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v10; // r4
  __int16 v12[2]; // [sp+18h] [bp-50h] BYREF
  const __int16 *v13; // [sp+1Ch] [bp-4Ch]
  _DWORD v14[18]; // [sp+20h] [bp-48h] BYREF

  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  if ( a5 )
    *a5 = 0;
  if ( a6 )
    *a6 = 0;
  v10 = PiDevCfgInitResolveContext(a1, a3, v14);
  if ( v10 >= 0 )
  {
    v10 = PiDevCfgEnumDeviceKeys(a1, a2, a3, a4, 1, PiDevCfgConfigureDeviceKeyCallback, v14);
    if ( v10 >= 0 )
    {
      if ( (a4 & 8) == 0 || (v10 = PiDevCfgConfigureDeviceInterfaces(*(_DWORD *)(a2 + 4), a3, v14), v10 >= 0) )
      {
        if ( (a4 & 0x10) == 0 || (v10 = PiDevCfgConfigureSoftwareDevices(*(_DWORD *)(a2 + 8), a3), v10 >= 0) )
        {
          v12[1] = 14;
          v12[0] = 12;
          v13 = L"Status";
          v14[4] = 24;
          v14[5] = a3;
          v14[7] = 576;
          v14[6] = v12;
          v14[8] = 0;
          v14[9] = 0;
          if ( ZwOpenKey() >= 0 )
            return sub_7E433C();
        }
      }
    }
  }
  PiDevCfgFreeResolveContext(v14);
  return v10;
}
