// PiDevCfgCheckDeviceNeedsUpdate 
 
int __fastcall PiDevCfgCheckDeviceNeedsUpdate(int a1, int *a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r8
  unsigned int v6; // r4
  int v7; // r1
  unsigned __int64 v8; // r6
  int v9; // r0
  unsigned int v10; // r10
  int v11; // r9
  int v12; // r0
  __int64 v13; // r2
  unsigned int v15; // [sp+10h] [bp-A0h] BYREF
  unsigned int v16; // [sp+18h] [bp-98h] BYREF
  unsigned int v17; // [sp+1Ch] [bp-94h]
  int v18; // [sp+20h] [bp-90h] BYREF
  int v19; // [sp+24h] [bp-8Ch]
  int v20; // [sp+28h] [bp-88h] BYREF
  int v21; // [sp+2Ch] [bp-84h] BYREF
  unsigned int v22; // [sp+30h] [bp-80h] BYREF
  unsigned int v23; // [sp+34h] [bp-7Ch] BYREF
  int v24; // [sp+38h] [bp-78h] BYREF
  unsigned __int16 *v25; // [sp+3Ch] [bp-74h]
  int v26; // [sp+40h] [bp-70h] BYREF
  int *v27; // [sp+44h] [bp-6Ch]
  int v28[26]; // [sp+48h] [bp-68h] BYREF

  v21 = 0;
  v18 = 0;
  v19 = 0;
  v24 = 0;
  v25 = 0;
  v15 = 0;
  v26 = 1;
  v27 = a2;
  v20 = 0;
  *a2 = 0;
  v3 = 0;
  v4 = PiDevCfgFindDeviceDriver(a1, 0, (int *)&v15);
  v5 = v4;
  v6 = v15;
  if ( v4 == -1073741772 || v4 >= 0 )
  {
    v20 = 4;
    if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 4), *(_DWORD *)(a1 + 8), 11, (int)&v26, (int)&v21, (int)&v20) < 0
      || v26 != 4
      || v20 != 4 )
    {
      v21 = 0;
    }
    memset(v28, 0, 72);
    v7 = *(_DWORD *)(a1 + 4);
    v28[0] = (int)DEVPKEY_Device_DriverInfPath;
    v28[1] = 18;
    v28[2] = (int)&v18;
    v28[4] = 6;
    v28[6] = (int)DEVPKEY_Device_DriverDate;
    v28[7] = 16;
    v28[8] = (int)&v16;
    v28[9] = 8;
    v28[12] = (int)DEVPKEY_Device_DriverVersion;
    v28[13] = 18;
    v28[14] = (int)&v24;
    v28[16] = 6;
    v5 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v7, 1, *(_DWORD *)(a1 + 8), v28, 3u);
    if ( v5 >= 0 )
    {
      if ( v28[5] < 0 )
        RtlInitUnicodeString((unsigned int)&v18, 0);
      if ( v28[11] >= 0 )
      {
        v8 = __PAIR64__(v16, v17);
      }
      else
      {
        v8 = 0i64;
        v16 = 0;
        v17 = 0;
      }
      if ( v28[17] < 0 )
      {
        RtlInitUnicodeString((unsigned int)&v24, 0);
        v8 = __PAIR64__(v16, v17);
      }
      if ( v25
        && (v9 = swscanf_s(v25, (int)L"%hu.%hu.%hu.%hu", (char *)&v23 + 2, &v23, (char *)&v22 + 2, &v22),
            v8 = __PAIR64__(v16, v17),
            v9 == 4) )
      {
        v10 = v23;
        v15 = v22;
      }
      else
      {
        v15 = 0;
        v22 = 0;
        v23 = 0;
        v10 = 0;
      }
      v11 = (unsigned __int8)PnpBootMode;
      if ( (v21 & 0x40) != 0 || !v19 )
      {
        if ( !v6 )
        {
LABEL_22:
          if ( v11 && v6 && (v3 & 0x20) != 0 )
          {
            v12 = PiDevCfgQueryDriverConfiguration((_DWORD *)v6);
            v5 = v12;
            if ( v12 == -1073741637 )
            {
              v5 = 0;
              v3 = 0x40000;
            }
            else if ( v12 < 0 )
            {
              goto LABEL_39;
            }
          }
          goto LABEL_38;
        }
      }
      else if ( v6 && RtlEqualUnicodeString((unsigned __int16 *)(v6 + 20), (unsigned __int16 *)&v18, 1) )
      {
        LODWORD(v13) = *(_DWORD *)(v6 + 68);
        HIDWORD(v13) = *(_DWORD *)(v6 + 64);
        if ( v13 == v8 && *(_QWORD *)(v6 + 72) == __PAIR64__(v10, v15) )
        {
          if ( !v11 )
          {
LABEL_38:
            *v27 = v3;
            goto LABEL_39;
          }
          goto LABEL_36;
        }
      }
      else if ( v11 && (PiDevCfgFlags & 2) != 0 )
      {
LABEL_36:
        v3 = 0x40000;
        goto LABEL_22;
      }
      v3 = 32;
      goto LABEL_22;
    }
  }
LABEL_39:
  RtlFreeAnsiString(&v18);
  RtlFreeAnsiString(&v24);
  if ( v6 )
    PiDevCfgFreeDriverNode();
  return v5;
}
