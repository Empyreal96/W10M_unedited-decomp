// _CmDeleteDeviceInterfaceMappedPropertyFromRegValue 
 
int __fastcall CmDeleteDeviceInterfaceMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, int a3, unsigned int a4)
{
  unsigned int v4; // r4
  int v5; // r6
  int v8; // r5
  int v9; // r2
  int (**v10)[6]; // r5
  unsigned int v11; // r4
  int (**v12)[6]; // r10
  unsigned int v13; // r1
  int (*v14)[6]; // t1
  int *v15; // r10
  int v16; // r4
  int v17; // r0
  int v19; // [sp+14h] [bp-34h] BYREF
  int *v20; // [sp+18h] [bp-30h]
  int v21; // [sp+1Ch] [bp-2Ch]
  unsigned __int16 *v22; // [sp+20h] [bp-28h] BYREF

  v4 = *(_DWORD *)(a4 + 16);
  v5 = 0;
  v22 = a2;
  v19 = 0;
  v20 = a1;
  if ( v4 < 2 )
    return -1073741264;
  v9 = *(_DWORD *)(a4 + 16);
  v10 = &off_8C94F0;
  v11 = 0;
  v21 = v9;
  do
  {
    v12 = v10;
    v14 = *v10;
    v10 += 2;
    v13 = (unsigned int)v14;
    if ( v9 == (*v14)[4] )
    {
      if ( !memcmp(a4, v13, 16) )
        break;
      v9 = v21;
    }
    ++v11;
    v12 = 0;
  }
  while ( v11 < 3 );
  v8 = 0;
  if ( !v12 )
    return -1073741264;
  v15 = v20;
  if ( !a3 )
  {
    v8 = CmOpenDeviceInterfaceRegKey(v20, v22, 48, 1, 1, 0, (int)&v19, 0);
    if ( v8 < 0 )
      goto LABEL_20;
    v5 = v19;
  }
  v16 = *(_DWORD *)(a4 + 16);
  if ( v16 != 2 || memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_FriendlyName, 16) )
  {
    if ( v16 == 3 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_Enabled, 16)
      || v16 == 4 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_ClassGuid, 16)
      || v16 == 256 && !memcmp(a4, (unsigned int)DEVPKEY_Device_InstanceId, 16) )
    {
      v8 = -1073741790;
    }
    else
    {
      v8 = -1073741264;
    }
    goto LABEL_35;
  }
  if ( !a3 )
    a3 = v5;
  v17 = PnpCtxRegOpenKey(v15, a3, (int)L"Device Parameters", 0);
  if ( v17 != -1073741772 && v17 != -1073741444 )
  {
    if ( v17 < 0 )
      goto LABEL_19;
    v17 = RtlInitUnicodeStringEx((int)&v22, L"FriendlyName");
    if ( v17 >= 0 )
      v17 = ZwDeleteValueKey();
    if ( v17 != -1073741772 && v17 != -1073741444 && v17 < 0 )
LABEL_19:
      v8 = v17;
  }
LABEL_20:
  v5 = v19;
LABEL_35:
  if ( v5 )
    ZwClose();
  return v8;
}
