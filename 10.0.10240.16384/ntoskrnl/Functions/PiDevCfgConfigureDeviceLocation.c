// PiDevCfgConfigureDeviceLocation 
 
int __fastcall PiDevCfgConfigureDeviceLocation(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD v5[2]; // [sp+Ch] [bp-90h] BYREF
  int v6; // [sp+14h] [bp-88h]
  int v7; // [sp+24h] [bp-78h]
  int v8; // [sp+2Ch] [bp-70h]
  int v9; // [sp+4Ch] [bp-50h]

  v5[1] = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v5[0] = 0;
  v9 = a1;
  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = 0;
  if ( *(_DWORD *)(a2 + 32) )
    return sub_7E0F04();
  RtlFreeAnsiString(v5);
  if ( v8 )
    ZwClose();
  if ( v7 )
    ZwClose();
  if ( v6 )
    ZwClose();
  return 0;
}
