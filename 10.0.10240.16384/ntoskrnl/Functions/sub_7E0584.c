// sub_7E0584 
 
void sub_7E0584(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r6
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  PnpLockMountableDevice(v8);
  PnpMarkDeviceForRemove(v8, 1, (int *)va);
  PnpUnlockMountableDevice(v8);
  JUMPOUT(0x7768F2);
}
