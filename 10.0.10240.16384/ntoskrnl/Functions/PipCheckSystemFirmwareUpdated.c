// PipCheckSystemFirmwareUpdated 
 
int __fastcall PipCheckSystemFirmwareUpdated(_BYTE *a1)
{
  unsigned int v1; // r5
  unsigned int v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r2
  int v6; // [sp+8h] [bp-28h] BYREF
  _DWORD *v7; // [sp+Ch] [bp-24h] BYREF
  int v8; // [sp+10h] [bp-20h] BYREF
  _DWORD *v9; // [sp+14h] [bp-1Ch] BYREF
  __int16 v10; // [sp+18h] [bp-18h]
  __int16 v11; // [sp+1Ah] [bp-16h]
  const __int16 *v12; // [sp+1Ch] [bp-14h]

  v6 = 0;
  v8 = 0;
  *a1 = 0;
  v1 = 0;
  v2 = 0;
  v9 = 0;
  v7 = 0;
  if ( IopOpenRegistryKeyEx(&v8) >= 0 )
  {
    if ( IopGetRegistryValue(v8, L"SystemBiosVersion", 0, (int *)&v7) < 0
      || (v11 = 96,
          v10 = 94,
          v12 = L"\\Registry\\Machine\\System\\HardwareConfig\\Current",
          IopOpenRegistryKeyEx(&v6) < 0) )
    {
      v2 = (unsigned int)v7;
    }
    else
    {
      v3 = IopGetRegistryValue(v6, L"SystemBiosVersion", 0, (int *)&v9);
      v1 = (unsigned int)v9;
      v2 = (unsigned int)v7;
      if ( v3 == -1073741772 )
        return sub_968910();
      if ( v3 >= 0 )
      {
        if ( v7[1] != v9[1] )
          return sub_968910();
        v5 = v7[3];
        if ( v5 != v9[3] || memcmp((unsigned int)v7 + v7[2], (unsigned int)v9 + v9[2], v5) )
          return sub_968910();
      }
    }
  }
  if ( v6 )
    ZwClose();
  result = v8;
  if ( v8 )
    result = ZwClose();
  if ( v2 )
    result = ExFreePoolWithTag(v2);
  if ( v1 )
    result = ExFreePoolWithTag(v1);
  return result;
}
