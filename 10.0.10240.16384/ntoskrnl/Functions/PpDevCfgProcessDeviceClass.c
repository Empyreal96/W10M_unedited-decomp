// PpDevCfgProcessDeviceClass 
 
int __fastcall PpDevCfgProcessDeviceClass(int a1)
{
  int v2; // r7
  int v3; // r4
  int v4; // r10
  int v5; // r1
  int v6; // r0
  int v7; // r0
  int v8; // r6
  int v9; // r3
  int v11; // [sp+10h] [bp-98h] BYREF
  int v12; // [sp+14h] [bp-94h]
  int v13; // [sp+18h] [bp-90h] BYREF
  int v14; // [sp+1Ch] [bp-8Ch] BYREF
  int v15; // [sp+20h] [bp-88h] BYREF
  int v16; // [sp+28h] [bp-80h] BYREF
  int v17; // [sp+2Ch] [bp-7Ch]
  int v18[6]; // [sp+30h] [bp-78h] BYREF
  __int16 v19[2]; // [sp+48h] [bp-60h] BYREF
  const __int16 *v20; // [sp+4Ch] [bp-5Ch]
  int v21; // [sp+50h] [bp-58h] BYREF
  int v22[8]; // [sp+54h] [bp-54h] BYREF
  char v23[48]; // [sp+78h] [bp-30h] BYREF

  v21 = 0;
  memset(v22, 0, sizeof(v22));
  v12 = 0;
  v13 = 0;
  v16 = 0;
  v17 = 0;
  v11 = 0;
  v15 = 1;
  v14 = 0;
  v2 = 0;
  if ( !PiDevCfgMode )
  {
    v3 = 0;
    goto LABEL_25;
  }
  if ( !*(_DWORD *)(a1 + 24) )
  {
    v3 = -1073741808;
    goto LABEL_25;
  }
  v3 = PiDevCfgInitDeviceContext(*(_DWORD *)(a1 + 24), 0, (int)&v21);
  if ( v3 >= 0 )
  {
    v4 = v22[1];
    memset(v18, 0, sizeof(v18));
    v5 = *(_DWORD *)(a1 + 24);
    v18[0] = (int)DEVPKEY_Device_ClassGuid;
    v18[1] = 13;
    v18[2] = (int)v23;
    v18[3] = 16;
    v3 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v5, 1, v22[1], v18, 1u);
    if ( v3 >= 0 )
    {
      if ( v18[5] >= 0 )
      {
        v3 = RtlStringFromGUIDEx((int)v23, (int)&v16, 1);
        if ( v3 < 0 )
          goto LABEL_25;
        v6 = PnpOpenObjectRegKey(PiPnpRtlCtx, v17, 2, 131097, 0, (int)&v13, 0, 0);
        v3 = v6;
        if ( v6 == -1073741772 )
        {
          v13 = 0;
LABEL_17:
          v3 = PiDevCfgConfigureDeviceLocation(a1, (int)&v21, &v11, 0);
          if ( v3 >= 0 )
          {
            v8 = v2 | v11;
            if ( v2 | v11 )
            {
              v14 = 4;
              if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v4, 11, (int)&v15, (int)&v11, (int)&v14) >= 0
                && v15 == 4
                && v14 == 4 )
              {
                v9 = v11;
              }
              else
              {
                v9 = 0;
              }
              v11 = v9 | v8;
              PiDevCfgSetDeviceRegProp(PiPnpRtlCtx, &v21, 11, 4, (int)&v11, 4);
            }
          }
          goto LABEL_25;
        }
        if ( v6 < 0 )
          goto LABEL_25;
      }
      if ( v13 )
      {
        v19[1] = 28;
        v19[0] = 26;
        v18[1] = v13;
        v20 = L"Configuration";
        v12 = 0;
        v18[0] = 24;
        v18[3] = 576;
        v18[2] = (int)v19;
        v18[4] = 0;
        v18[5] = 0;
        v7 = ZwOpenKey();
        v3 = v7;
        if ( v7 != -1073741772 )
        {
          if ( v7 < 0 )
            goto LABEL_25;
          v3 = PiDevCfgConfigureDeviceKeys(a1, (int)&v21, v12, -1, &v11, 0);
          if ( v3 < 0 )
            goto LABEL_25;
          v2 = v11;
        }
      }
      goto LABEL_17;
    }
  }
LABEL_25:
  RtlFreeAnsiString(&v16);
  if ( v12 )
    ZwClose();
  if ( v13 )
    ZwClose();
  PiDevCfgFreeDeviceContext(&v21);
  return v3;
}
