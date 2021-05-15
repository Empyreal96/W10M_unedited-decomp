// sub_969044 
 
void sub_969044(int a1, int a2, int a3, int a4, ...)
{
  int (*v4)(int); // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  int (*v6)(int); // [sp+4h] [bp+4h]
  int v7; // [sp+8h] [bp+8h]
  int v8; // [sp+Ch] [bp+Ch]
  va_list va1; // [sp+10h] [bp+10h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v4 = va_arg(va1, int (*)(int));
  v6 = va_arg(va1, int (*)(int));
  v7 = va_arg(va1, _DWORD);
  v8 = va_arg(va1, _DWORD);
  v7 = a2;
  v8 = a3;
  v4 = PnpEarlyLaunchImageNotificationPreProcess;
  v6 = PnpEarlyLaunchImageNotificationPostProcess;
  ExNotifyWithProcessing(PnpBootDriverCallbackObject, 1, (int)va1, (int)va);
  JUMPOUT(0x951408);
}
