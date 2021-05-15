// PiAuditStartedDevice 
 
int __fastcall PiAuditStartedDevice(int a1)
{
  int v2; // r7
  int v3; // r5
  int v4; // r6
  int v5; // r4
  int v6; // r0
  __int16 v7; // r3
  int v8; // r0
  __int16 v9; // r3
  int v10; // r0
  __int16 v11; // r3
  int v12; // r1
  int v14; // [sp+20h] [bp-68h] BYREF
  int v15; // [sp+24h] [bp-64h] BYREF
  int v16; // [sp+28h] [bp-60h] BYREF
  char v17[4]; // [sp+2Ch] [bp-5Ch] BYREF
  int v18; // [sp+30h] [bp-58h] BYREF
  int v19; // [sp+34h] [bp-54h]
  int v20[2]; // [sp+38h] [bp-50h] BYREF
  __int16 v21[2]; // [sp+40h] [bp-48h] BYREF
  int v22; // [sp+44h] [bp-44h]
  __int16 v23[2]; // [sp+48h] [bp-40h] BYREF
  int v24; // [sp+4Ch] [bp-3Ch]
  __int16 v25[2]; // [sp+50h] [bp-38h] BYREF
  int v26; // [sp+54h] [bp-34h]
  char v27[48]; // [sp+58h] [bp-30h] BYREF

  v19 = a1;
  v20[0] = 1;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = PnpGetObjectProperty(
         PiPnpRtlCtx,
         *(_DWORD *)(a1 + 24),
         1,
         0,
         0,
         (int)DEVPKEY_Device_InLocalMachineContainer,
         (int)&v14,
         (int)v17,
         1,
         (int)v20,
         0);
  if ( v5 < 0 )
    return v5;
  if ( v14 != 17 || v20[0] != 1 )
    goto LABEL_40;
  if ( v17[0] == -1 )
    return v5;
  v15 = 512;
  v4 = ExAllocatePoolWithTag(1, 512, 538996816);
  if ( !v4 )
    return -1073741670;
  while ( 1 )
  {
    v6 = PnpGetObjectProperty(
           PiPnpRtlCtx,
           *(_DWORD *)(a1 + 24),
           1,
           0,
           0,
           (int)DEVPKEY_Device_HardwareIds,
           (int)&v14,
           v4,
           v15,
           (int)&v15,
           0);
    v5 = v6;
    if ( v6 != -1073741789 )
      break;
    ExFreePoolWithTag(v4);
    v4 = ExAllocatePoolWithTag(1, v15, 538996816);
    if ( !v4 )
      return -1073741670;
  }
  if ( v6 == -1073741275 )
  {
    ExFreePoolWithTag(v4);
    v4 = 0;
    v7 = 0;
    v15 = 0;
LABEL_16:
    v23[0] = v7;
    v23[1] = v7;
    v24 = v4;
    v16 = 512;
    v3 = ExAllocatePoolWithTag(1, 512, 538996816);
    if ( !v3 )
    {
LABEL_17:
      v5 = -1073741670;
      goto LABEL_43;
    }
    while ( 1 )
    {
      v8 = PnpGetObjectProperty(
             PiPnpRtlCtx,
             *(_DWORD *)(v19 + 24),
             1,
             0,
             0,
             (int)DEVPKEY_Device_CompatibleIds,
             (int)&v14,
             v3,
             v16,
             (int)&v16,
             0);
      v5 = v8;
      if ( v8 != -1073741789 )
        break;
      ExFreePoolWithTag(v3);
      v3 = ExAllocatePoolWithTag(1, v16, 538996816);
      if ( !v3 )
        goto LABEL_17;
    }
    if ( v8 == -1073741275 )
    {
      ExFreePoolWithTag(v3);
      v3 = 0;
      v9 = 0;
      v16 = 0;
    }
    else
    {
      if ( v8 < 0 )
        goto LABEL_41;
      if ( v14 != 8210 )
        goto LABEL_40;
      v9 = v16;
    }
    v21[0] = v9;
    v21[1] = v9;
    v18 = 64;
    v22 = v3;
    v2 = ExAllocatePoolWithTag(1, 64, 538996816);
    if ( !v2 )
    {
LABEL_27:
      v5 = -1073741670;
      goto LABEL_41;
    }
    while ( 1 )
    {
      v10 = PnpGetObjectProperty(
              PiPnpRtlCtx,
              *(_DWORD *)(v19 + 24),
              1,
              0,
              0,
              (int)DEVPKEY_Device_LocationInfo,
              (int)&v14,
              v2,
              v18,
              (int)&v18,
              0);
      v5 = v10;
      if ( v10 != -1073741789 )
        break;
      ExFreePoolWithTag(v2);
      v2 = ExAllocatePoolWithTag(1, v18, 538996816);
      if ( !v2 )
        goto LABEL_27;
    }
    if ( v10 == -1073741275 )
    {
      ExFreePoolWithTag(v2);
      v2 = 0;
      v11 = 0;
      v18 = 0;
    }
    else
    {
      if ( v10 < 0 )
        goto LABEL_41;
      if ( v14 != 18 )
        goto LABEL_40;
      v11 = v18;
    }
    v25[0] = v11;
    v25[1] = v11;
    v20[0] = 16;
    v12 = *(_DWORD *)(v19 + 24);
    v26 = v2;
    v5 = PnpGetObjectProperty(
           PiPnpRtlCtx,
           v12,
           1,
           0,
           0,
           (int)DEVPKEY_Device_ClassGuid,
           (int)&v14,
           (int)v27,
           16,
           (int)v20,
           0);
    if ( v5 < 0 )
      goto LABEL_41;
    if ( v14 == 13 && v20[0] == 16 )
    {
      SeAuditPlugAndPlay(v23, v21, v25, v27);
      goto LABEL_41;
    }
LABEL_40:
    v5 = -1073741823;
LABEL_41:
    if ( v3 )
      ExFreePoolWithTag(v3);
    goto LABEL_43;
  }
  if ( v6 >= 0 )
  {
    if ( v14 == 8210 )
    {
      v7 = v15;
      goto LABEL_16;
    }
    v5 = -1073741823;
  }
LABEL_43:
  if ( v4 )
    ExFreePoolWithTag(v4);
  if ( v2 )
    ExFreePoolWithTag(v2);
  return v5;
}
