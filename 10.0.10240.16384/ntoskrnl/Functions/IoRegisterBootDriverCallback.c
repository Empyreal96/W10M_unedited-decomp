// IoRegisterBootDriverCallback 
 
int __fastcall IoRegisterBootDriverCallback(int a1, int a2)
{
  int v5; // r0
  _BYTE v6[8]; // [sp+0h] [bp-30h] BYREF
  int v7[10]; // [sp+8h] [bp-28h] BYREF

  if ( PnpBootDriverCallbackRegistrationClosed )
    return 0;
  v5 = PnpBootDriverCallbackObject;
  if ( !PnpBootDriverCallbackObject )
  {
    RtlInitUnicodeString((unsigned int)v6, L"\\Callback\\BootDriver");
    v7[0] = 24;
    v7[1] = 0;
    v7[3] = 576;
    v7[2] = (int)v6;
    v7[4] = 0;
    v7[5] = 0;
    if ( ExCreateCallback(&PnpBootDriverCallbackObject, v7, 1, 1) < 0 )
      return 0;
    v5 = PnpBootDriverCallbackObject;
  }
  return ExRegisterCallback(v5, a1, a2);
}
