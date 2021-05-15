// _CmGetDeviceInterfaceMappedPropertyFromRegValue 
 
int __fastcall CmGetDeviceInterfaceMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, int a3, unsigned int a4, _DWORD *a5, unsigned __int16 *a6, unsigned int a7, unsigned int *a8)
{
  int v9; // r5
  int v10; // r4
  int v12; // r2
  int (**v13)[6]; // r9
  unsigned int v14; // r7
  int (**v15)[6]; // r10
  unsigned int v16; // r1
  int (*v17)[6]; // t1
  int v18; // r9
  int *v19; // r10
  int v20; // r7
  int v21; // r0
  int v22; // r5
  int v23; // r2
  char v24; // r3
  int v25; // r0
  unsigned __int16 *v26; // r9
  bool v27; // [sp+10h] [bp-48h] BYREF
  char v28[3]; // [sp+11h] [bp-47h] BYREF
  int v29; // [sp+14h] [bp-44h] BYREF
  unsigned int v30; // [sp+18h] [bp-40h] BYREF
  unsigned __int16 *v31; // [sp+1Ch] [bp-3Ch]
  unsigned int v32; // [sp+20h] [bp-38h]
  unsigned __int16 *v33; // [sp+24h] [bp-34h]
  int v34; // [sp+28h] [bp-30h] BYREF
  int *v35; // [sp+2Ch] [bp-2Ch]
  unsigned int v36; // [sp+30h] [bp-28h] BYREF
  int v37; // [sp+34h] [bp-24h]
  int v38[8]; // [sp+38h] [bp-20h] BYREF

  v33 = a2;
  v34 = 0;
  v32 = 0;
  v35 = a1;
  v36 = 0;
  v30 = 0;
  v27 = 0;
  v38[0] = a3;
  *a5 = 0;
  v9 = 0;
  v10 = 0;
  *a8 = 0;
  v29 = 0;
  v31 = a6;
  if ( !a6 )
    return sub_7C887C();
  if ( !a7 )
    v31 = 0;
  if ( *(_DWORD *)(a4 + 16) < 2u )
    return -1073741264;
  v12 = *(_DWORD *)(a4 + 16);
  v13 = &off_8C94F0;
  v37 = v12;
  v14 = 0;
  while ( 1 )
  {
    v15 = v13;
    v17 = *v13;
    v13 += 2;
    v16 = (unsigned int)v17;
    if ( v12 == (*v17)[4] )
      break;
LABEL_8:
    ++v14;
    v15 = 0;
    if ( v14 >= 3 )
      goto LABEL_11;
  }
  if ( memcmp(a4, v16, 16) )
  {
    v12 = v37;
    goto LABEL_8;
  }
LABEL_11:
  if ( !v15 )
    return -1073741264;
  v18 = v38[0];
  v19 = v35;
  if ( v38[0] )
  {
LABEL_15:
    v20 = *(_DWORD *)(a4 + 16);
    if ( v20 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_FriendlyName, 16) )
    {
      if ( !v18 )
        v18 = v9;
      v25 = PnpCtxRegOpenKey(v19, v18, (int)L"Device Parameters", 0);
      if ( v25 != -1073741772 && v25 != -1073741444 )
      {
        if ( v25 < 0 )
        {
          v10 = v25;
          goto LABEL_25;
        }
        v26 = v31;
        v30 = a7;
        v22 = PnpCtxRegQueryValueIndirect((int)v19, v32, (int)L"FriendlyName", &v36, v31, &v30, &v27);
        ZwClose();
        if ( v22 != -1073741772 && v22 != -1073741444 )
        {
          if ( !v22 || v22 == -1073741789 )
          {
            *a8 = v30;
            *a5 = 18;
            if ( v22 || !a7 )
              v10 = -1073741789;
            if ( v27 )
              *a5 = 25;
            if ( RtlStringCbLengthW((int)v26, *a8, v38) >= 0 )
              *a8 = v38[0] + 2;
            goto LABEL_25;
          }
          goto LABEL_58;
        }
      }
    }
    else
    {
      if ( v20 == 3 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_Enabled, 16) )
      {
        *a8 = 1;
        *a5 = 17;
        if ( a7 )
        {
          v10 = CmIsDeviceInterfaceEnabled((int)v19, v33, v23, (int)v28);
          if ( v10 >= 0 )
          {
            if ( v28[0] )
              v24 = -1;
            else
              v24 = 0;
            *(_BYTE *)v31 = v24;
          }
          goto LABEL_25;
        }
        v10 = -1073741789;
        goto LABEL_26;
      }
      if ( v20 != 256 || memcmp(a4, (unsigned int)DEVPKEY_Device_InstanceId, 16) )
      {
        v10 = -1073741264;
        goto LABEL_26;
      }
      v21 = CmOpenDeviceInterfaceRegKey(v19, v33, 49, 1, 1, 0, (int)&v34, 0);
      v10 = v21;
      if ( v21 < 0 )
        goto LABEL_25;
      v30 = a7;
      v22 = PnpCtxRegQueryValue(v21, v34);
      ZwClose();
      if ( v22 != -1073741772 && v22 != -1073741444 )
      {
        if ( !v22 || v22 == -1073741789 )
        {
          *a8 = v30;
          *a5 = 18;
          if ( v22 || !a7 )
            v10 = -1073741789;
          goto LABEL_25;
        }
LABEL_58:
        v10 = v22;
        goto LABEL_25;
      }
    }
    v10 = -1073741275;
    goto LABEL_25;
  }
  v10 = CmOpenDeviceInterfaceRegKey(v35, v33, 48, (int)&v29, 1, 0, (int)&v29, 0);
  if ( v10 >= 0 )
  {
    v9 = v29;
    goto LABEL_15;
  }
LABEL_25:
  v9 = v29;
LABEL_26:
  if ( v9 )
    ZwClose();
  return v10;
}
