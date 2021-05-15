// PpDevCfgCheckDeviceNeedsUpdate 
 
int __fastcall PpDevCfgCheckDeviceNeedsUpdate(int a1, int a2, int *a3)
{
  int v6; // r4
  int v8; // [sp+0h] [bp-30h] BYREF
  char v9[32]; // [sp+4h] [bp-2Ch] BYREF

  v8 = 0;
  memset(v9, 0, sizeof(v9));
  v6 = PiDevCfgInitDeviceContext(a1, a2, (int)&v8);
  if ( v6 >= 0 )
    v6 = PiDevCfgCheckDeviceNeedsUpdate((int)&v8, a3);
  PiDevCfgFreeDeviceContext(&v8);
  return v6;
}
