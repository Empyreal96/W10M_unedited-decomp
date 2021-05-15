// sub_7DEB08 
 
void sub_7DEB08(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  PnpLockMountableDevice(v6);
  PnpMarkDeviceForRemove(v6, 1, (int *)va);
  PnpUnlockMountableDevice(v6);
  JUMPOUT(0x774CA0);
}
