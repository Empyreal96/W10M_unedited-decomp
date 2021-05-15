// PnpInitializeNotification 
 
void PnpInitializeNotification()
{
  int v0; // r2
  _DWORD *v1; // r3

  v0 = 13;
  v1 = PnpDeviceClassNotifyList;
  do
  {
    *v1 = v1;
    v1[1] = v1;
    v1 += 2;
    --v0;
  }
  while ( v0 );
  off_9209FC = &PnpProfileNotifyList;
  off_9209F4 = &PnpDeferredRegistrationList;
  PnpProfileNotifyList = &PnpProfileNotifyList;
  PnpDeviceClassNotifyLock = 1;
  dword_630D04 = 0;
  unk_630D08 = 0;
  byte_630D0C = 1;
  byte_630D0D = 0;
  byte_630D0E = 4;
  dword_630D10 = 0;
  dword_630D18 = (int)&dword_630D14;
  dword_630D14 = (int)&dword_630D14;
  PnpDeferredRegistrationList = &PnpDeferredRegistrationList;
  PnpTargetDeviceNotifyLock = 1;
  dword_630D24 = 0;
  unk_630D28 = 0;
  byte_630D2C = 1;
  byte_630D2D = 0;
  byte_630D2E = 4;
  dword_630D30 = 0;
  dword_630D38 = (int)&dword_630D34;
  dword_630D34 = (int)&dword_630D34;
  PnpHwProfileNotifyLock = 1;
  dword_630D44 = 0;
  unk_630D48 = 0;
  byte_630D4C = 1;
  byte_630D4D = 0;
  byte_630D4E = 4;
  dword_630D50 = 0;
  dword_630D58 = (int)&dword_630D54;
  dword_630D54 = (int)&dword_630D54;
  PnpDeferredRegistrationLock = 1;
  dword_630D64 = 0;
  unk_630D68 = 0;
  byte_630D6C = 1;
  byte_630D6D = 0;
  byte_630D6E = 4;
  dword_630D70 = 0;
  dword_630D78 = (int)&dword_630D74;
  dword_630D74 = (int)&dword_630D74;
}
