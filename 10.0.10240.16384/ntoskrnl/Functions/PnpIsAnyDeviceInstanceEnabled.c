// PnpIsAnyDeviceInstanceEnabled 
 
int __fastcall PnpIsAnyDeviceInstanceEnabled(int a1)
{
  int v1; // r7
  unsigned int v2; // r5
  int v3; // r6
  int v4; // r3
  int v5; // r4
  int v7; // [sp+8h] [bp-30h] BYREF
  int v8; // [sp+Ch] [bp-2Ch] BYREF
  int v9; // [sp+10h] [bp-28h] BYREF
  _DWORD *v10; // [sp+14h] [bp-24h] BYREF
  unsigned __int16 v11; // [sp+18h] [bp-20h] BYREF
  unsigned int v12; // [sp+1Ch] [bp-1Ch]

  v7 = 0;
  v1 = 0;
  if ( PipOpenServiceEnumKeys(a1, 131097, &v7, &v8, 0) >= 0 )
  {
    v2 = 0;
    if ( IopGetRegistryValue(v8, L"Count", 0, (int *)&v10) >= 0 )
    {
      if ( v10[1] == 4 && v10[3] >= 4u )
        v2 = *(_DWORD *)((char *)v10 + v10[2]);
      ExFreePoolWithTag((unsigned int)v10);
    }
    ZwClose();
    if ( v2 )
    {
      v3 = 0;
      while ( 1 )
      {
        if ( PipServiceInstanceToDeviceInstance(v7, 0, v3, &v11, &v9, 983103) >= 0 )
        {
          v5 = PnpIsDeviceInstanceEnabled(v9, &v11, 1, v4);
          ExFreePoolWithTag(v12);
          ZwClose();
          if ( v5 )
            break;
        }
        if ( ++v3 >= v2 )
          goto LABEL_12;
      }
      v1 = 1;
    }
LABEL_12:
    ZwClose();
  }
  return v1;
}
