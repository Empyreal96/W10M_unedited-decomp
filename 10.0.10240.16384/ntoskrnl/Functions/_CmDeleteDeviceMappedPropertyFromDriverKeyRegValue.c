// _CmDeleteDeviceMappedPropertyFromDriverKeyRegValue 
 
int __fastcall CmDeleteDeviceMappedPropertyFromDriverKeyRegValue(int a1, int a2, unsigned int a3)
{
  int v3; // r8
  int (**v4)[5]; // r7
  unsigned int i; // r4
  int (**v9)[5]; // r5
  unsigned int v10; // r1
  int (*v11)[5]; // t1
  int v12; // r4
  int v13; // r0
  int v14; // r0
  int v16; // [sp+10h] [bp-30h] BYREF
  char v17[40]; // [sp+18h] [bp-28h] BYREF

  v3 = *(_DWORD *)(a3 + 16);
  v4 = &off_8C97B0;
  v16 = 0;
  for ( i = 0; i < 0xD; ++i )
  {
    v9 = v4;
    v11 = *v4;
    v4 += 4;
    v10 = (unsigned int)v11;
    if ( v3 == (*v11)[4] && !memcmp(a3, v10, 16) )
      break;
    v9 = 0;
  }
  if ( !v9 )
    return -1073741802;
  v13 = CmOpenDeviceRegKey(a1, a2, 18, 0, 2, 0, (int)&v16, 0);
  v12 = v13;
  if ( v13 == -1073741772 )
  {
    v12 = 0;
    goto LABEL_20;
  }
  if ( v13 >= 0 )
  {
    v14 = RtlInitUnicodeStringEx((int)v17, (unsigned __int16 *)v9[2]);
    if ( v14 >= 0 )
      v14 = ZwDeleteValueKey();
    if ( v14 == -1073741772 )
      goto LABEL_18;
    if ( v14 == -1073741444 )
      goto LABEL_20;
    if ( v14 >= 0 )
    {
LABEL_18:
      if ( *(_DWORD *)(a3 + 16) == 2
        && !memcmp(a3, (unsigned int)DEVPKEY_Device_DriverDate, 16)
        && RtlInitUnicodeStringEx((int)v17, L"DriverDate") >= 0 )
      {
        ZwDeleteValueKey();
      }
      goto LABEL_20;
    }
    v12 = v14;
  }
LABEL_20:
  if ( v16 )
    ZwClose();
  return v12;
}
