// PpDevCfgProcessDeviceReset 
 
int __fastcall PpDevCfgProcessDeviceReset(int a1)
{
  int v2; // r4
  int v3; // r8
  int v4; // r1
  int *v5; // r2
  int v6; // r6
  _DWORD *v7; // r2
  int v8; // r3
  int v10[2]; // [sp+10h] [bp-90h] BYREF
  int v11; // [sp+18h] [bp-88h] BYREF
  int v12; // [sp+1Ch] [bp-84h]
  int v13; // [sp+20h] [bp-80h] BYREF
  int v14; // [sp+24h] [bp-7Ch] BYREF
  int v15; // [sp+28h] [bp-78h] BYREF
  int v16; // [sp+2Ch] [bp-74h] BYREF
  int v17[6]; // [sp+30h] [bp-70h] BYREF
  int v18; // [sp+48h] [bp-58h] BYREF
  int v19[8]; // [sp+4Ch] [bp-54h] BYREF
  _DWORD v20[12]; // [sp+70h] [bp-30h] BYREF

  v18 = 0;
  memset(v19, 0, sizeof(v19));
  v15 = 0;
  v16 = 0;
  v11 = 0;
  v12 = 0;
  v10[0] = 0;
  v14 = 1;
  v13 = 0;
  if ( !PiDevCfgMode )
  {
    v2 = 0;
    goto LABEL_28;
  }
  if ( !*(_DWORD *)(a1 + 24) )
  {
    v2 = -1073741808;
    goto LABEL_28;
  }
  v2 = PiDevCfgInitDeviceContext(*(_DWORD *)(a1 + 24), 0, (int)&v18);
  if ( v2 >= 0 )
  {
    v3 = v19[1];
    memset(v17, 0, sizeof(v17));
    v4 = *(_DWORD *)(a1 + 24);
    v17[0] = (int)DEVPKEY_Device_ClassGuid;
    v17[1] = 13;
    v17[2] = (int)v20;
    v17[3] = 16;
    v2 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v4, 1, v19[1], v17, 1u);
    if ( v2 >= 0 )
    {
      if ( v17[5] >= 0 )
      {
        v2 = RtlStringFromGUIDEx((int)v20, (int)&v11, 1);
        if ( v2 < 0 )
          goto LABEL_28;
        if ( PnpOpenObjectRegKey(PiPnpRtlCtx, v12, 2, 131097, 0, (int)&v15, 0, 0) >= 0 )
          goto LABEL_12;
        RtlFreeAnsiString(&v11);
      }
      v20[2] = 0;
      v20[3] = 0;
      v20[0] = 0;
      v20[1] = 0;
LABEL_12:
      if ( v12 )
        v5 = &v11;
      else
        v5 = 0;
      if ( PiDevCfgMigrateDevice(a1, (int)&v18, (int)v5, 0, &v16, 0) >= 0 )
        v6 = v16;
      else
        v6 = 0;
      if ( v12 )
        v7 = v20;
      else
        v7 = 0;
      PiDevCfgResetDeviceDriverSettings(a1, &v18, (unsigned int)v7, v15, 0);
      PnpCtxRegDeleteTree((int *)PiPnpRtlCtx, v3, L"Devices");
      if ( v6 )
      {
        v13 = 4;
        if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3, 11, (int)&v14, (int)v10, (int)&v13) >= 0
          && v14 == 4
          && v13 == 4 )
        {
          v8 = v10[0];
        }
        else
        {
          v8 = 0;
        }
        v10[0] = v8 | v6;
        PiDevCfgSetDeviceRegProp(PiPnpRtlCtx, &v18, 11, 4, (int)v10, 4);
      }
      goto LABEL_28;
    }
  }
LABEL_28:
  RtlFreeAnsiString(&v11);
  PiDevCfgFreeDeviceContext(&v18);
  return v2;
}
