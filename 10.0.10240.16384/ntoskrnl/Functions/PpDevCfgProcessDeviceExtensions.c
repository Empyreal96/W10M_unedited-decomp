// PpDevCfgProcessDeviceExtensions 
 
int __fastcall PpDevCfgProcessDeviceExtensions(int a1)
{
  int v2; // r7
  int v3; // r4
  int v4; // r8
  unsigned __int16 **v5; // r10
  unsigned __int16 *v6; // r9
  unsigned __int16 *v7; // r5
  int v8; // r0
  unsigned __int16 *v9; // r0
  int v10; // r3
  int v11; // r3
  int v12; // r2
  unsigned int i; // r7
  int v14; // r1
  unsigned __int16 *j; // r7
  int v16; // r7
  int v17; // r3
  int v19; // [sp+4h] [bp-104h]
  int v20; // [sp+4h] [bp-104h]
  int v21; // [sp+4h] [bp-104h]
  int v22[2]; // [sp+20h] [bp-E8h] BYREF
  int v23; // [sp+28h] [bp-E0h] BYREF
  int v24; // [sp+2Ch] [bp-DCh]
  unsigned __int16 **v25; // [sp+30h] [bp-D8h] BYREF
  int v26; // [sp+34h] [bp-D4h]
  int v27; // [sp+38h] [bp-D0h] BYREF
  int v28; // [sp+40h] [bp-C8h] BYREF
  int v29; // [sp+44h] [bp-C4h]
  int v30; // [sp+48h] [bp-C0h] BYREF
  int v31; // [sp+4Ch] [bp-BCh]
  int v32; // [sp+50h] [bp-B8h] BYREF
  int v33; // [sp+54h] [bp-B4h]
  _DWORD v34[2]; // [sp+58h] [bp-B0h] BYREF
  _DWORD v35[2]; // [sp+60h] [bp-A8h] BYREF
  int v36; // [sp+68h] [bp-A0h]
  _DWORD v37[2]; // [sp+70h] [bp-98h] BYREF
  int v38; // [sp+78h] [bp-90h] BYREF
  _DWORD v39[2]; // [sp+80h] [bp-88h] BYREF
  int v40; // [sp+88h] [bp-80h]
  int v41; // [sp+8Ch] [bp-7Ch]
  int v42; // [sp+90h] [bp-78h]
  int v43; // [sp+98h] [bp-70h] BYREF
  int v44[8]; // [sp+9Ch] [bp-6Ch] BYREF
  int v45[6]; // [sp+C0h] [bp-48h] BYREF
  int v46[12]; // [sp+D8h] [bp-30h] BYREF

  v43 = 0;
  memset(v44, 0, sizeof(v44));
  v24 = 0;
  v25 = 0;
  v30 = 0;
  v31 = 0;
  v34[0] = 0;
  v34[1] = 0;
  v35[0] = 0;
  v35[1] = 0;
  v36 = 0;
  v37[0] = 0;
  v37[1] = 0;
  v39[0] = 0;
  v39[1] = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v28 = 0;
  v29 = 0;
  v32 = 0;
  v33 = 0;
  v23 = 0;
  v22[0] = 0;
  v38 = 1;
  v27 = 0;
  v2 = 0;
  v26 = 0;
  if ( !PiDevCfgMode )
  {
    v3 = 0;
    goto LABEL_64;
  }
  if ( !*(_DWORD *)(a1 + 24) )
  {
    v3 = -1073741808;
    goto LABEL_64;
  }
  v3 = PiDevCfgInitDeviceContext(*(_DWORD *)(a1 + 24), 0, (int)&v43);
  if ( v3 < 0 )
    goto LABEL_64;
  v4 = v44[1];
  v3 = PiDevCfgFindDeviceDriver((int)&v43, 0, (int *)&v25);
  v5 = v25;
  if ( v3 >= 0 )
  {
    v6 = (unsigned __int16 *)(v25 + 30);
    if ( v25[30] == (unsigned __int16 *)(v25 + 30) )
    {
      v3 = 0;
      goto LABEL_62;
    }
    v7 = v25[30];
    if ( v7 != v6 )
    {
      while ( 1 )
      {
        v8 = PiDevCfgQueryDriverConfiguration(v7);
        v3 = v8;
        if ( v8 == -1073741637 )
          break;
        if ( v8 < 0 )
          goto LABEL_62;
        if ( !*((_DWORD *)v7 + 43) )
        {
          if ( *((_DWORD *)v7 + 45) )
          {
            v3 = PiDevCfgAppendMultiSz((unsigned __int16 *)v34, 0, v7 + 88, 0);
            if ( v3 < 0 )
              goto LABEL_62;
          }
          if ( *((_DWORD *)v7 + 47) )
          {
            v3 = PiDevCfgAppendMultiSz((unsigned __int16 *)v35, 0, v7 + 92, 0);
            if ( v3 < 0 )
              goto LABEL_62;
          }
          if ( *((_DWORD *)v7 + 49) )
          {
            v3 = PiDevCfgAppendMultiSz((unsigned __int16 *)v37, 0, v7 + 96, 0);
            if ( v3 < 0 )
              goto LABEL_62;
          }
          if ( *((_DWORD *)v7 + 51) )
          {
            v3 = PiDevCfgAppendMultiSz((unsigned __int16 *)v39, 0, v7 + 100, 0);
            if ( v3 < 0 )
              goto LABEL_62;
          }
          v2 |= *((_DWORD *)v7 + 54);
          v26 = v2;
          v3 = PiDevCfgAppendMultiSz((unsigned __int16 *)&v28, v7 + 10, 0, 0);
          if ( v3 < 0 )
            goto LABEL_62;
          v9 = (unsigned __int16 *)&v32;
          v10 = 0;
          goto LABEL_25;
        }
        *((_DWORD *)v7 + 25) &= 0xFFFFFFFE;
LABEL_26:
        v7 = *(unsigned __int16 **)v7;
        if ( v7 == v6 )
        {
          v11 = v31;
          v12 = (unsigned __int16)v30;
          v36 = v29;
          v41 = (unsigned __int16)v28;
          v42 = v33;
          v40 = (unsigned __int16)v32;
          goto LABEL_29;
        }
      }
      v9 = (unsigned __int16 *)&v30;
      v10 = 1;
LABEL_25:
      v3 = PiDevCfgAppendMultiSz(v9, v7 + 112, 0, v10);
      if ( v3 < 0 )
        goto LABEL_62;
      goto LABEL_26;
    }
    v11 = 0;
    v12 = 0;
LABEL_29:
    if ( v3 < 0 )
      goto LABEL_62;
    if ( v11 )
    {
      v3 = PiDevCfgSetObjectProperty(
             PiPnpRtlCtx,
             &v43,
             *(_DWORD *)(a1 + 24),
             1,
             v4,
             v19,
             (int)DEVPKEY_Device_RequestConfigurationIds,
             8210,
             v11,
             v12);
      if ( v3 >= 0 )
        v3 = -1073741637;
      goto LABEL_62;
    }
    v46[0] = (int)v34;
    v46[1] = (int)v35;
    v46[2] = (int)v37;
    v46[3] = (int)v39;
    for ( i = 0; i < 4; ++i )
    {
      v25 = (unsigned __int16 **)v46[i];
      if ( v25[1] )
      {
        memset(v45, 0, sizeof(v45));
        v14 = *(_DWORD *)(a1 + 24);
        v45[0] = (int)off_9200C0[i];
        v45[1] = 8210;
        v45[2] = (int)&v23;
        v45[4] = 6;
        v3 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v14, 1, v4, v45, 1u);
        if ( v3 < 0 )
          goto LABEL_62;
        if ( v45[5] < 0 )
          RtlInitUnicodeString((unsigned int)&v23, 0);
        v3 = PiDevCfgAppendMultiSz((unsigned __int16 *)&v23, 0, (unsigned __int16 *)v25, 0);
        if ( v3 < 0 )
          goto LABEL_62;
        v3 = PiDevCfgSetObjectProperty(
               PiPnpRtlCtx,
               &v43,
               *(_DWORD *)(a1 + 24),
               1,
               v4,
               v20,
               (int)off_9200C0[i],
               8210,
               v24,
               (unsigned __int16)v23);
        if ( v3 < 0 )
          goto LABEL_62;
        RtlFreeAnsiString(&v23);
      }
    }
    for ( j = v5[30]; j != v6; j = *(unsigned __int16 **)j )
    {
      if ( (*((_DWORD *)j + 25) & 1) != 0 )
      {
        v3 = PiDevCfgConfigureDeviceDriver(a1, (int)&v43, (int)j);
        if ( v3 < 0 )
          goto LABEL_62;
        v26 |= v22[0];
      }
    }
    if ( v36 )
    {
      v3 = PiDevCfgSetObjectProperty(
             PiPnpRtlCtx,
             &v43,
             *(_DWORD *)(a1 + 24),
             1,
             v4,
             v19,
             (int)DEVPKEY_Device_DriverExtendedInfs,
             8210,
             v36,
             v41);
      if ( v3 < 0 )
        goto LABEL_62;
    }
    else
    {
      PiDevCfgSetObjectProperty(
        PiPnpRtlCtx,
        &v43,
        *(_DWORD *)(a1 + 24),
        1,
        v4,
        v19,
        (int)DEVPKEY_Device_DriverExtendedInfs,
        0,
        0,
        0);
    }
    if ( !v42 )
    {
      PiDevCfgSetObjectProperty(
        PiPnpRtlCtx,
        &v43,
        *(_DWORD *)(a1 + 24),
        1,
        v4,
        v21,
        (int)DEVPKEY_Device_ExtendedConfigurationIds,
        0,
        0,
        0);
      goto LABEL_55;
    }
    v3 = PiDevCfgSetObjectProperty(
           PiPnpRtlCtx,
           &v43,
           *(_DWORD *)(a1 + 24),
           1,
           v4,
           v21,
           (int)DEVPKEY_Device_ExtendedConfigurationIds,
           8210,
           v42,
           v40);
    if ( v3 >= 0 )
    {
LABEL_55:
      v16 = v26;
      if ( v26 )
      {
        v27 = 4;
        if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v4, 11, (int)&v38, (int)v22, (int)&v27) >= 0
          && v38 == 4
          && v27 == 4 )
        {
          v17 = v22[0];
        }
        else
        {
          v17 = 0;
        }
        v22[0] = v17 | v16;
        PiDevCfgSetDeviceRegProp(PiPnpRtlCtx, &v43, 11, 4, (int)v22, 4);
      }
      goto LABEL_62;
    }
  }
LABEL_62:
  if ( v5 )
    PiDevCfgFreeDriverNode();
LABEL_64:
  RtlFreeAnsiString(v34);
  RtlFreeAnsiString(v35);
  RtlFreeAnsiString(v37);
  RtlFreeAnsiString(v39);
  RtlFreeAnsiString(&v28);
  RtlFreeAnsiString(&v32);
  RtlFreeAnsiString(&v23);
  RtlFreeAnsiString(&v30);
  PiDevCfgFreeDeviceContext(&v43);
  return v3;
}
