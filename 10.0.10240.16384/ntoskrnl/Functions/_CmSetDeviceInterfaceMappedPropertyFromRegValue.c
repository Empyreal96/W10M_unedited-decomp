// _CmSetDeviceInterfaceMappedPropertyFromRegValue 
 
int __fastcall CmSetDeviceInterfaceMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, int a3, unsigned int a4, int (*a5)[6], int a6, int a7)
{
  unsigned int v7; // r4
  int v8; // r6
  int v9; // r7
  int v11; // r8
  int v12; // r2
  int (**v13)[6]; // r5
  unsigned int v14; // r10
  int (**v15)[6]; // r4
  unsigned int v16; // r1
  int (*v17)[6]; // t1
  int v18; // r5
  int v20; // r10
  int v21; // r4
  int v22; // r0
  int v23; // r0
  int v24; // [sp+10h] [bp-38h] BYREF
  int v25; // [sp+14h] [bp-34h] BYREF
  int v26; // [sp+18h] [bp-30h] BYREF
  int *v27; // [sp+1Ch] [bp-2Ch]
  unsigned __int16 *v28; // [sp+20h] [bp-28h]
  int v29; // [sp+24h] [bp-24h]
  int v30; // [sp+28h] [bp-20h]

  v7 = *(_DWORD *)(a4 + 16);
  v8 = 0;
  v9 = 0;
  v30 = a3;
  v27 = a1;
  v28 = a2;
  v24 = 0;
  v25 = 0;
  v11 = 0;
  v26 = 0;
  if ( v7 < 2 )
    return -1073741264;
  v12 = v7;
  v13 = &off_8C94F0;
  v29 = v7;
  v14 = 0;
  while ( 1 )
  {
    v15 = v13;
    v17 = *v13;
    v13 += 2;
    v16 = (unsigned int)v17;
    if ( v12 == (*v17)[4] )
      break;
LABEL_4:
    ++v14;
    v15 = 0;
    if ( v14 >= 3 )
      goto LABEL_7;
  }
  if ( memcmp(a4, v16, 16) )
  {
    v12 = v29;
    goto LABEL_4;
  }
LABEL_7:
  v18 = 0;
  if ( !v15 )
    return -1073741264;
  if ( a5 != v15[1] )
    return sub_7EFC38();
  v20 = v30;
  if ( !v30 )
  {
    v18 = CmOpenDeviceInterfaceRegKey(v27, v28, 48, 1, 1, 0, (int)&v25, 0);
    if ( v18 >= 0 )
    {
      v9 = v24;
      v8 = v25;
      v11 = v26;
      goto LABEL_11;
    }
    goto LABEL_17;
  }
LABEL_11:
  v21 = *(_DWORD *)(a4 + 16);
  if ( v21 != 2 || memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_FriendlyName, 16) )
  {
    if ( v21 != 256 || memcmp(a4, (unsigned int)DEVPKEY_Device_InstanceId, 16) )
    {
      if ( v21 == 3 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_Enabled, 16)
        || v21 == 4 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_ClassGuid, 16) )
      {
        v18 = -1073741790;
      }
      else
      {
        v18 = -1073741264;
      }
      goto LABEL_18;
    }
    v22 = CmOpenDeviceInterfaceRegKey(v27, v28, 49, 2, 2, 0, (int)&v26, 0);
    v18 = v22;
    if ( v22 < 0 )
      goto LABEL_17;
    v23 = PnpCtxRegSetValue(v22, v26, (int)L"DeviceInstance", 1, a6, a7);
    if ( v23 != -1073741444 )
      goto LABEL_16;
LABEL_27:
    v18 = -1073741772;
    goto LABEL_17;
  }
  if ( !v20 )
    v20 = v8;
  v23 = PnpCtxRegCreateKey(v27, v20, L"Device Parameters", 2, 2, 0, (int)&v24, 0);
  if ( v23 == -1073741444 )
    goto LABEL_27;
  if ( v23 < 0 )
    goto LABEL_28;
  v23 = PnpCtxRegSetValue(v23, v24, (int)L"FriendlyName", 1, a6, a7);
  if ( v23 == -1073741444 )
    goto LABEL_27;
LABEL_16:
  if ( v23 >= 0 )
    goto LABEL_17;
LABEL_28:
  v18 = v23;
LABEL_17:
  v9 = v24;
  v8 = v25;
  v11 = v26;
LABEL_18:
  if ( v11 )
  {
    ZwClose();
    v9 = v24;
    v8 = v25;
  }
  if ( v9 )
  {
    ZwClose();
    v8 = v25;
  }
  if ( v8 )
    ZwClose();
  return v18;
}
