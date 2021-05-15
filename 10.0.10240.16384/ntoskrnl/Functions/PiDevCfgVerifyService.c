// PiDevCfgVerifyService 
 
int __fastcall PiDevCfgVerifyService(unsigned __int16 *a1, _BYTE *a2, _DWORD *a3)
{
  int v3; // r4
  int v4; // r5
  int v6; // [sp+8h] [bp-28h] BYREF
  int v7; // [sp+Ch] [bp-24h] BYREF
  char v8[32]; // [sp+10h] [bp-20h] BYREF

  v6 = 0;
  v7 = 0;
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  RtlInitUnicodeString((unsigned int)v8, a1);
  v3 = PipOpenServiceEnumKeys((int)v8, 131097, &v7, 0, 0);
  v4 = v7;
  if ( v3 >= 0 )
  {
    v3 = IopGetRegistryValue(v7, L"Type", 0, &v6);
    if ( v3 >= 0 )
      return sub_7F0CD4();
  }
  if ( v4 )
    ZwClose();
  return v3;
}
