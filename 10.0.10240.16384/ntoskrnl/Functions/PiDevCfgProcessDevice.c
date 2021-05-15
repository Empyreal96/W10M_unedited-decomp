// PiDevCfgProcessDevice 
 
int __fastcall PiDevCfgProcessDevice(_DWORD *a1, int a2, char a3)
{
  _BYTE *v5; // r0
  int v6; // r9
  __int64 v8; // kr00_8
  unsigned __int16 *v9; // r10
  int v10; // r7
  _DWORD *v11; // r5
  char v12; // r3
  _DWORD *v13; // r8
  int v14; // r3
  char v15; // r4
  int v16; // r7
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r3
  int v21; // r1
  int v22; // r3
  int v23; // r4
  __int64 v24; // r6
  int v25; // r1
  char v26; // r3
  BOOL v27; // r7
  int v28; // r4
  int v29; // r3
  int v31; // r4
  int v32; // r3
  int *v33; // [sp+4h] [bp-E4h]
  int v34; // [sp+4h] [bp-E4h]
  int v35; // [sp+4h] [bp-E4h]
  int v36; // [sp+4h] [bp-E4h]
  int v37; // [sp+4h] [bp-E4h]
  int v38; // [sp+20h] [bp-C8h] BYREF
  char v39[4]; // [sp+24h] [bp-C4h] BYREF
  int v40; // [sp+28h] [bp-C0h]
  int v41; // [sp+2Ch] [bp-BCh] BYREF
  int v42; // [sp+30h] [bp-B8h] BYREF
  __int16 v43; // [sp+34h] [bp-B4h] BYREF
  int v44; // [sp+38h] [bp-B0h] BYREF
  int v45; // [sp+3Ch] [bp-ACh]
  _DWORD *v46; // [sp+40h] [bp-A8h] BYREF
  int v47; // [sp+44h] [bp-A4h]
  int v48; // [sp+48h] [bp-A0h]
  int v49; // [sp+4Ch] [bp-9Ch] BYREF
  int v50[2]; // [sp+50h] [bp-98h] BYREF
  int v51; // [sp+58h] [bp-90h] BYREF
  int v52; // [sp+5Ch] [bp-8Ch]
  int v53; // [sp+60h] [bp-88h] BYREF
  int v54; // [sp+64h] [bp-84h]
  int v55; // [sp+68h] [bp-80h] BYREF
  int v56[8]; // [sp+6Ch] [bp-7Ch] BYREF
  _DWORD v57[2]; // [sp+90h] [bp-58h] BYREF
  int v58[20]; // [sp+98h] [bp-50h] BYREF

  v47 = a2;
  v55 = 0;
  v5 = memset(v56, 0, sizeof(v56));
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v45 = 0;
  v46 = 0;
  v38 = 0;
  v6 = 0;
  v40 = 0;
  v42 = 0;
  v48 = 0;
  v49 = 0;
  v39[0] = 0;
  v50[0] = 0;
  v44 = 1;
  v41 = 0;
  if ( !a1[6] )
    return sub_7E1A04(v5);
  v8 = PnpEtwHandle;
  v9 = (unsigned __int16 *)(a1 + 5);
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceConfig_Start) )
  {
    v28 = *v9;
    v43 = *v9 >> 1;
    v58[0] = (int)&v43;
    v58[1] = 0;
    v58[2] = 2;
    v58[3] = 0;
    v29 = a1[6];
    v58[6] = v28;
    v58[4] = v29;
    v58[5] = 0;
    v58[7] = 0;
    v33 = v58;
    EtwWrite(v8, SHIDWORD(v8), (int)KMPnPEvt_DeviceConfig_Start, 0);
  }
  v10 = v47;
  v11 = (_DWORD *)PiDevCfgInitDeviceContext(a1[6], v47, &v55);
  if ( (int)v11 >= 0 )
  {
    v12 = v55;
    if ( (a3 & 1) != 0 )
    {
      v12 = v55 | 1;
      v55 |= 1u;
    }
    if ( !v10 )
    {
      v10 = v56[1];
      v47 = v56[1];
    }
    if ( (v12 & 1) != 0 )
    {
LABEL_10:
      v11 = (_DWORD *)PiDevCfgFindDeviceDriver(&v55, v52, &v46);
      v13 = v46;
      if ( (int)v11 < 0 )
        goto LABEL_59;
      if ( !v54 )
      {
        v11 = (_DWORD *)PiDevCfgResolveDriverDependencies(v46, v39);
        if ( (int)v11 >= 0 )
        {
          if ( v39[0] )
          {
            v11 = (_DWORD *)PiDevCfgConfigureDevice(a1, &v55, v13, &v38, &v42, v33);
            if ( (int)v11 >= 0 )
            {
              v6 = v38;
              v48 = 1;
            }
            v40 = v42;
            goto LABEL_17;
          }
          v11 = 0;
        }
LABEL_43:
        if ( v13 )
          PiDevCfgFreeDriverNode();
        goto LABEL_45;
      }
      v11 = (_DWORD *)PiDevCfgRequestDriverConfigurations(&v55, v46);
LABEL_17:
      if ( !v52 )
        goto LABEL_18;
      PiDevCfgSetObjectProperty(PiPnpRtlCtx, &v55, a1[6], 1, v10, v33, DEVPKEY_Device_PendingConfigurationIds, 0, 0, 0);
LABEL_59:
      if ( v52 )
        goto LABEL_21;
LABEL_18:
      if ( !v54 )
      {
        if ( v13 )
        {
          v14 = v13[59];
          if ( !v14 )
            goto LABEL_21;
          v27 = 1;
        }
        else
        {
          if ( v11 != (_DWORD *)-1073741772 || (PiDevCfgMode & 2) == 0 )
            goto LABEL_21;
          if ( !PnpBootMode || (a1[92] & 0x100) != 0 )
          {
            if ( a1[2] == IopRootDeviceNode )
            {
              v41 = 4;
              if ( CmGetDeviceRegProp(PiPnpRtlCtx, a1[6], v10, 11, (int)&v44, (int)&v38, (int)&v41) >= 0
                && v44 == 4
                && v41 == 4 )
              {
                v26 = v38;
              }
              else
              {
                v26 = 0;
                v38 = 0;
              }
              v27 = (v26 & 0x20) != 0;
            }
            else
            {
              v27 = 1;
            }
          }
          else
          {
            v6 = 32;
            v27 = 0;
          }
          if ( a1[2] == IopRootDeviceNode && PiDevCfgOpenDeviceMigrationKey(a1[6]) >= 0 )
          {
            v38 = 0;
            if ( IopGetRegistryValue(v45, L"ConfigFlags", 0, v50) >= 0 )
            {
              if ( *(_DWORD *)(v50[0] + 4) == 4 && *(_DWORD *)(v50[0] + 12) == 4 )
                v38 = *(_DWORD *)(*(_DWORD *)(v50[0] + 8) + v50[0]);
              ExFreePoolWithTag(v50[0]);
            }
            if ( (v38 & 1) != 0 && IopGetRegistryValue(v45, L"DriverInfName", 0, v50) >= 0 )
            {
              ExFreePoolWithTag(v50[0]);
              v38 = 0;
            }
            ZwClose();
            if ( (v38 & 1) != 0 )
            {
              v33 = 0;
              if ( PiDevCfgMigrateDevice(a1, &v55, 0, 0, &v38) >= 0 )
              {
                v6 |= v38;
                if ( (v38 & 1) != 0 )
                {
                  v27 = 0;
                  v6 &= 0xFFFFFFDF;
                }
              }
            }
          }
          v14 = -536870360;
        }
        v49 = v14;
        if ( v27 )
        {
          v11 = (_DWORD *)PiDevCfgConfigureDevice(a1, &v55, 0, &v38, &v42, v33);
          if ( (int)v11 < 0 )
          {
            v15 = v42;
          }
          else
          {
            v48 = 1;
            v6 = v38;
            if ( !v49 || (v38 & 0x40) == 0 )
            {
              v15 = v42;
LABEL_23:
              if ( PnpBootMode )
                v6 |= 0x40000u;
              if ( (v6 & 0x40) == 0 )
                a1[114] |= 1u;
LABEL_27:
              v41 = 4;
              v16 = v47;
              if ( CmGetDeviceRegProp(PiPnpRtlCtx, a1[6], v47, 11, (int)&v44, (int)&v38, (int)&v41) >= 0
                && v44 == 4
                && v41 == 4 )
              {
                v17 = v38;
              }
              else
              {
                v17 = 0;
                v38 = 0;
              }
              if ( (int)v11 < 0 )
              {
LABEL_39:
                v23 = v48;
                if ( v48 || v6 )
                {
                  v38 = v6 | v17;
                  PiDevCfgSetDeviceRegProp(PiPnpRtlCtx, &v55, 11, 4, &v38);
                  if ( v23 )
                  {
                    KeQuerySystemTime(v57);
                    PiDevCfgSetObjectProperty(
                      PiPnpRtlCtx,
                      &v55,
                      a1[6],
                      1,
                      v16,
                      4,
                      DEVPKEY_Device_InstallDate,
                      16,
                      v57,
                      8);
                    if ( PnpGetObjectProperty(
                           PiPnpRtlCtx,
                           a1[6],
                           1,
                           v16,
                           0,
                           (int)DEVPKEY_Device_FirstInstallDate,
                           (int)&v44,
                           0,
                           0,
                           (int)&v41,
                           0) != -1073741789
                      || v41 != 8 )
                    {
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        &v55,
                        a1[6],
                        1,
                        v16,
                        v35,
                        DEVPKEY_Device_FirstInstallDate,
                        16,
                        v57,
                        8);
                    }
                  }
                }
                goto LABEL_43;
              }
              v18 = a1[67];
              v17 &= 0xFFFFFB9F;
              v38 = v17;
              v19 = v18 & 0x2000;
              v6 &= 0xFFFFFFDF;
              if ( (v18 & 0x2000) != 0 && (v20 = a1[69], v20 == 1) || v19 && ((v20 = a1[69], v20 == 28) || v20 == 18) )
              {
                PipClearDevNodeProblem((int)a1, v19, v17, v20);
                v17 = v38;
              }
              v21 = a1[43];
              if ( v21 == 770 || v21 == 786 )
              {
                v22 = a1[67];
                if ( (v22 & 0x6000) == 0 )
                {
                  if ( (v15 & 2) == 0 || (v22 = (unsigned __int8)PnpBootMode, PnpBootMode) )
                  {
                    if ( (v6 & 0x40) == 0 )
                      goto LABEL_37;
                    PipSetDevNodeProblem((int)a1, 28, 0, v22);
                  }
                  else
                  {
                    PipSetDevNodeProblem((int)a1, 14, 0, (unsigned __int8)PnpBootMode);
                    PipSetDevNodeUserFlags(a1, 4);
                  }
                  goto LABEL_85;
                }
                if ( (v22 & 0x2000) != 0 && a1[69] == 14 && (v15 & 2) == 0 )
                {
                  PipClearDevNodeProblem((int)a1, v21, v17, 14);
                  PipClearDevNodeUserFlags((int)a1, 4);
LABEL_85:
                  v17 = v38;
                  goto LABEL_37;
                }
              }
LABEL_37:
              if ( (v55 & 1) == 0 )
              {
                PiDevCfgSetObjectProperty(
                  PiPnpRtlCtx,
                  &v55,
                  a1[6],
                  1,
                  v16,
                  v34,
                  DEVPKEY_Device_FirmwareDependencies,
                  0,
                  0,
                  0);
                PiDevCfgSetObjectProperty(
                  PiPnpRtlCtx,
                  &v55,
                  a1[6],
                  1,
                  v16,
                  v37,
                  DEVPKEY_Device_DependencyBootSession,
                  0,
                  0,
                  0);
                v17 = v38;
              }
              goto LABEL_39;
            }
            PiDevCfgSetObjectProperty(PiPnpRtlCtx, &v55, a1[6], 1, v47, v36, DEVPKEY_Device_InstallError, 23, &v49, 4);
            v15 = v42;
          }
LABEL_22:
          if ( !v48 )
            goto LABEL_27;
          goto LABEL_23;
        }
      }
LABEL_21:
      v15 = v40;
      goto LABEL_22;
    }
    v11 = (_DWORD *)PiDevCfgResolveDeviceDependencies(&v55, v39);
    if ( (int)v11 >= 0 )
    {
      if ( v39[0] )
      {
        if ( PnpBootMode )
          goto LABEL_10;
        memset(v58, 0, 48);
        v58[2] = (int)&v51;
        v58[4] = 6;
        v25 = a1[6];
        v58[6] = (int)DEVPKEY_Device_RequestConfigurationIds;
        v58[8] = (int)&v53;
        v58[10] = 6;
        v58[0] = (int)DEVPKEY_Device_PendingConfigurationIds;
        v58[1] = 8210;
        v58[7] = 8210;
        v11 = (_DWORD *)PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v25, 1, v10, v58, 2);
        if ( (int)v11 >= 0 )
        {
          if ( v58[5] < 0 )
            RtlInitUnicodeString((unsigned int)&v51, 0);
          if ( v58[11] < 0 )
            RtlInitUnicodeString((unsigned int)&v53, 0);
          goto LABEL_10;
        }
      }
      else
      {
        v11 = 0;
      }
    }
  }
LABEL_45:
  RtlFreeAnsiString(&v51);
  RtlFreeAnsiString(&v53);
  PiDevCfgFreeDeviceContext(&v55);
  if ( a1 != (_DWORD *)-20 )
  {
    v24 = PnpEtwHandle;
    v46 = v11;
    if ( PnpEtwHandle )
    {
      if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceConfig_Stop) )
      {
        v31 = *v9;
        v43 = *v9 >> 1;
        v58[0] = (int)&v43;
        v58[1] = 0;
        v58[2] = 2;
        v58[3] = 0;
        v32 = *((_DWORD *)v9 + 1);
        v58[6] = v31;
        v58[4] = v32;
        v58[5] = 0;
        v58[7] = 0;
        v58[8] = (int)&v46;
        v58[9] = 0;
        v58[10] = 4;
        v58[11] = 0;
        EtwWrite(v24, SHIDWORD(v24), (int)KMPnPEvt_DeviceConfig_Stop, 0);
      }
    }
  }
  return (int)v11;
}
