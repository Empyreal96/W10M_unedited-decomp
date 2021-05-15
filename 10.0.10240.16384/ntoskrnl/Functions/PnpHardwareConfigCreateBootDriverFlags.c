// PnpHardwareConfigCreateBootDriverFlags 
 
int __fastcall PnpHardwareConfigCreateBootDriverFlags(int a1, int a2)
{
  int v2; // r0
  int v3; // r4
  int v4; // r6
  unsigned int v6[2]; // [sp+18h] [bp-60h] BYREF
  int v7; // [sp+20h] [bp-58h]
  int v8; // [sp+24h] [bp-54h]
  int v9[4]; // [sp+30h] [bp-48h] BYREF
  int v10[14]; // [sp+40h] [bp-38h] BYREF

  v9[0] = 0;
  v7 = 0;
  v8 = 0;
  v6[0] = 0;
  if ( !a2 )
    return -1073741811;
  v2 = PipHardwareConfigOpenKey(a1, a2, v6);
  v3 = v2;
  v4 = v6[0];
  if ( v2 >= 0 )
  {
    v6[0] = 4;
    v3 = PnpCtxRegQueryValue(v2, v4, L"BootDriverFlags", v10, (int)v9, v6);
    if ( v3 < 0 )
      return sub_80C59C();
  }
  if ( v7 )
    ZwClose();
  if ( v4 )
    ZwClose();
  return v3;
}
