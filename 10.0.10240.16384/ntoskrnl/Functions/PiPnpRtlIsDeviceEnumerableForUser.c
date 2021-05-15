// PiPnpRtlIsDeviceEnumerableForUser 
 
int __fastcall PiPnpRtlIsDeviceEnumerableForUser(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int v5; // r0
  unsigned int v6; // r6
  int v8; // [sp+4h] [bp-44h]
  unsigned int v9; // [sp+20h] [bp-28h] BYREF
  _DWORD v10[9]; // [sp+24h] [bp-24h] BYREF

  v10[1] = 131073;
  v10[2] = 0x20000;
  v10[3] = 0x20000;
  v10[4] = 983041;
  v9 = 0;
  v10[0] = 0;
  *a5 = 0;
  v5 = PnpGetObjectProperty(1198550608, 512, a2, 1, a3, v8, (int)DEVPKEY_Device_RestrictedSD, (int)v10, &v9, 0, 0);
  v6 = v9;
  if ( v5 != -1073741275 )
    return sub_7C7478();
  *a5 = 1;
  if ( v6 )
    ExFreePoolWithTag(v6);
  return 0;
}
