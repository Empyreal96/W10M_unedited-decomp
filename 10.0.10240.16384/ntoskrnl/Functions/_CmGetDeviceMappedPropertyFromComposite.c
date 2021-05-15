// _CmGetDeviceMappedPropertyFromComposite 
 
int __fastcall CmGetDeviceMappedPropertyFromComposite(int a1, unsigned __int16 *a2, int a3, unsigned int a4, int *a5, _WORD *a6, unsigned int a7, unsigned int *a8)
{
  unsigned int *v8; // r6
  int v10; // r4
  unsigned int v11; // r10
  unsigned int v13; // r5
  int v14; // r8
  int v15; // r10
  int v16; // r5
  int v17; // r5
  int v18; // r10
  int v19; // r3
  int v20; // r5
  int v21; // r6
  int v22; // r3
  int v23; // r0
  int v24; // r3
  int v25; // r0
  int v26; // r0
  int v27; // r0
  int v28; // r0
  int v29; // r3
  int v30; // r0
  int v31; // r0
  int v32; // r0
  int v33; // r0
  int v34; // r8
  int v35; // r0
  unsigned int v36; // r2
  unsigned int v37; // r3
  int v38; // r2
  int v39; // r3
  int v40; // r0
  int v41; // r3
  int v42; // r0
  int v43; // r2
  unsigned int v44; // [sp+0h] [bp-148h]
  unsigned int v45; // [sp+0h] [bp-148h]
  unsigned int *v46; // [sp+4h] [bp-144h]
  int v47; // [sp+10h] [bp-138h]
  int v50; // [sp+28h] [bp-120h] BYREF
  unsigned int v51; // [sp+2Ch] [bp-11Ch] BYREF
  int v52; // [sp+30h] [bp-118h] BYREF
  int v53; // [sp+34h] [bp-114h] BYREF
  int v54; // [sp+38h] [bp-110h] BYREF
  unsigned __int16 v55[4]; // [sp+40h] [bp-108h] BYREF
  int v56; // [sp+48h] [bp-100h] BYREF
  char v57[4]; // [sp+4Ch] [bp-FCh] BYREF
  int v58; // [sp+50h] [bp-F8h] BYREF
  int v59; // [sp+54h] [bp-F4h] BYREF
  int v60; // [sp+58h] [bp-F0h] BYREF
  int v61; // [sp+5Ch] [bp-ECh] BYREF
  char v62[8]; // [sp+60h] [bp-E8h] BYREF
  char v63[16]; // [sp+68h] [bp-E0h] BYREF
  char v64[16]; // [sp+78h] [bp-D0h] BYREF
  char v65[80]; // [sp+88h] [bp-C0h] BYREF
  unsigned __int16 v66[56]; // [sp+D8h] [bp-70h] BYREF
  int varg_r0; // [sp+150h] [bp+8h]
  unsigned __int16 *varg_r1; // [sp+154h] [bp+Ch]
  int varg_r2; // [sp+158h] [bp+10h]
  unsigned int varg_r3; // [sp+15Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v8 = a8;
  *a5 = 0;
  v10 = 0;
  *v8 = 0;
  v53 = a3;
  v54 = 0;
  if ( a6 )
  {
    v11 = a7;
    if ( !a7 )
      return sub_7C8450();
  }
  else
  {
    v11 = 0;
    a7 = 0;
  }
  v13 = *(_DWORD *)(a4 + 16);
  if ( v13 < 2 )
    return -1073741264;
  if ( v13 != 10 || memcmp(a4, (unsigned int)DEVPKEY_NAME, 16) )
  {
    if ( v13 == 256 && !memcmp(a4, (unsigned int)DEVPKEY_Device_InstanceId, 16) )
    {
      v14 = (int)a2;
      v10 = RtlUnalignedStringCchLengthW(a2, 200, &v53);
      if ( v10 >= 0 )
      {
        *v8 = 2 * (v53 + 1);
        *a5 = 18;
        if ( v11 >= *v8 )
        {
          v10 = RtlStringCbCopyExW(a6, *v8, (__int16 *)a2, 0, 0, 2304);
          v15 = a1;
          if ( v10 < 0 )
          {
            *v8 = 0;
            *a5 = 0;
          }
          goto LABEL_36;
        }
        return -1073741789;
      }
      goto LABEL_198;
    }
    if ( v13 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_Device_DevNodeStatus, 16)
      || v13 == 3 && !memcmp(a4, (unsigned int)DEVPKEY_Device_ProblemCode, 16)
      || v13 == 12 && !memcmp(a4, (unsigned int)DEVPKEY_Device_ProblemStatus, 16) )
    {
      v50 = 0;
      v56 = 0;
      v54 = 0;
      v15 = a1;
      v10 = CmGetDeviceStatus(a1, a2, v53, &v50, &v56, &v54);
      if ( v10 >= 0 )
      {
        v17 = *(_DWORD *)(a4 + 16);
        v18 = v50;
        if ( v17 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_Device_DevNodeStatus, 16)
          || v17 == 3 && !memcmp(a4, (unsigned int)DEVPKEY_Device_ProblemCode, 16) )
        {
          v19 = 7;
          goto LABEL_44;
        }
        if ( (v18 & 0x400) != 0 )
        {
          v19 = 24;
LABEL_44:
          *v8 = 4;
          *a5 = v19;
          if ( a7 < *v8 )
            return -1073741789;
          if ( *(_DWORD *)(a4 + 16) == 12 && !memcmp(a4, (unsigned int)DEVPKEY_Device_ProblemStatus, 16) )
          {
            if ( PnpGetObjectProperty(
                   a1,
                   (int)a2,
                   1,
                   v53,
                   0,
                   (int)DEVPKEY_Device_ProblemStatusOverride,
                   (int)&v58,
                   (int)&v59,
                   4,
                   (int)&v51,
                   0) >= 0
              && v58 == 24
              && v51 == 4 )
            {
              v20 = v59;
              v18 = v50;
              v54 = v59;
LABEL_47:
              v21 = *(_DWORD *)(a4 + 16);
              if ( v21 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_Device_DevNodeStatus, 16) )
              {
                *(_DWORD *)a6 = v18;
              }
              else if ( v21 == 3 && !memcmp(a4, (unsigned int)DEVPKEY_Device_ProblemCode, 16) )
              {
                if ( (v18 & 0x400) != 0 )
                  v29 = v56;
                else
                  v29 = 0;
                *(_DWORD *)a6 = v29;
              }
              else
              {
                *(_DWORD *)a6 = v20;
              }
              v15 = a1;
              v14 = (int)a2;
              goto LABEL_36;
            }
            v18 = v50;
          }
          v20 = v54;
          goto LABEL_47;
        }
        return -1073741275;
      }
LABEL_126:
      v14 = (int)a2;
      goto LABEL_36;
    }
    if ( v13 == 4 && !memcmp(a4, (unsigned int)DEVPKEY_Device_EjectionRelations, 16) )
    {
      v34 = 4;
      goto LABEL_155;
    }
    if ( v13 == 5 && !memcmp(a4, (unsigned int)DEVPKEY_Device_RemovalRelations, 16) )
    {
      v34 = 8;
      goto LABEL_155;
    }
    if ( v13 == 6 && !memcmp(a4, (unsigned int)DEVPKEY_Device_PowerRelations, 16) )
    {
      v34 = 16;
      goto LABEL_155;
    }
    if ( v13 == 7 && !memcmp(a4, (unsigned int)DEVPKEY_Device_BusRelations, 16) )
    {
      v34 = 32;
      goto LABEL_155;
    }
    if ( v13 == 11 && !memcmp(a4, (unsigned int)DEVPKEY_Device_TransportRelations, 16) )
    {
      v34 = 64;
LABEL_155:
      v15 = a1;
      v35 = CmGetDeviceRelationsList(a1, a2, v34, 0, 0, &v52);
      v10 = v35;
      if ( v35 == -1073741772 || !v35 )
        return -1073741275;
      v16 = -1073741789;
      if ( v35 != -1073741789 )
        goto LABEL_126;
      v36 = a7;
      *v8 = 2 * v52;
      *a5 = 8210;
      if ( v36 >= *v8 )
      {
        v37 = v36 >> 1;
        v38 = v34;
        v14 = (int)a2;
        v10 = CmGetDeviceRelationsList(a1, a2, v38, a6, v37, &v52);
        if ( !v10 )
        {
          *v8 = 2 * PnpMultiSzGetLen(a6);
          return v10;
        }
        *v8 = 0;
        *a5 = 0;
        goto LABEL_36;
      }
      return v16;
    }
    if ( v13 == 8 && !memcmp(a4, (unsigned int)DEVPKEY_Device_Parent, 16) )
    {
      v14 = (int)a2;
      v22 = v11 >> 1;
      v15 = a1;
      v52 = v22;
      v23 = CmGetDeviceParent(a1, a2, a6, &v52);
      v10 = v23;
      if ( v23 == -1073741772 )
        goto LABEL_36;
      v16 = -1073741789;
      if ( v23 )
      {
        if ( v23 != -1073741789 )
          goto LABEL_36;
      }
      *v8 = 2 * v52;
      v24 = 18;
      goto LABEL_55;
    }
    if ( v13 == 9 && !memcmp(a4, (unsigned int)DEVPKEY_Device_Children, 16) )
    {
      v14 = (int)a2;
      v39 = v11 >> 1;
      v15 = a1;
      v52 = v39;
      v40 = CmGetDeviceChildren(a1, a2, a6, &v52);
      goto LABEL_164;
    }
    if ( v13 == 10 && !memcmp(a4, (unsigned int)DEVPKEY_Device_Siblings, 16) )
    {
      v14 = (int)a2;
      v41 = v11 >> 1;
      v15 = a1;
      v52 = v41;
      v40 = CmGetDeviceSiblings(a1, a2, a6, &v52);
LABEL_164:
      v10 = v40;
      if ( v40 == -1073741772 )
        goto LABEL_36;
      v16 = -1073741789;
      if ( v40 )
      {
        if ( v40 != -1073741789 )
          goto LABEL_36;
      }
      *v8 = 2 * v52;
      v24 = 8210;
LABEL_55:
      *a5 = v24;
      if ( a7 >= *v8 )
        goto LABEL_36;
      return v16;
    }
    if ( v13 == 2 )
    {
      if ( !memcmp(a4, (unsigned int)DEVPKEY_Device_SafeRemovalRequired, 16) )
      {
        *v8 = 1;
        *a5 = 17;
        if ( v11 >= *v8 )
        {
          if ( CmIsDeviceSafeRemovalRequired(a1, a2, v53) )
            *(_BYTE *)a6 = -1;
          else
            *(_BYTE *)a6 = 0;
          return v10;
        }
        return -1073741789;
      }
      if ( !memcmp(a4, (unsigned int)DEVPKEY_Device_ContainerId, 16) )
      {
        v51 = 78;
        v15 = a1;
        v14 = (int)a2;
        v10 = CmGetDeviceRegProp(a1, (int)a2, v53, 37, (int)v62, (int)v65, (int)&v51);
        if ( v10 < 0 )
          goto LABEL_36;
        if ( !PnpIsNullGuidString(v65) )
        {
          *v8 = 16;
          *a5 = 13;
          if ( a7 >= *v8 )
          {
            v10 = CmGetDeviceContainerIdFromBase(a1, a2, v65, v66);
            if ( v10 >= 0 )
            {
              v10 = RtlInitUnicodeStringEx((int)v55, v66);
              if ( v10 >= 0 )
                v10 = RtlGUIDFromString(v55, a6);
            }
            goto LABEL_36;
          }
          return -1073741789;
        }
        return -1073741275;
      }
    }
    if ( v13 == 5 && !memcmp(a4, (unsigned int)DEVPKEY_Device_IsPresent, 16) )
    {
      *v8 = 1;
      *a5 = 17;
      if ( v11 < *v8 )
        return -1073741789;
      v14 = (int)a2;
      v10 = RtlInitUnicodeStringEx((int)v55, a2);
      v15 = a1;
      if ( v10 < 0 )
        goto LABEL_36;
      *(_BYTE *)a6 = 0;
      v42 = NtPlugPlayGetDeviceStatus(a1, (int)v55, (int)&v50, (int)&v56);
      v10 = v42;
      if ( v42 != -1073741810 )
      {
        v16 = -1073741275;
        if ( v42 < 0 )
          goto LABEL_37;
        goto LABEL_30;
      }
      return 0;
    }
    if ( v13 == 6 && !memcmp(a4, (unsigned int)DEVPKEY_Device_HasProblem, 16) )
    {
      *a5 = 17;
      *v8 = 1;
      if ( !v11 )
        return -1073741789;
      v14 = (int)a2;
      v10 = RtlInitUnicodeStringEx((int)v55, a2);
      v15 = a1;
      if ( v10 < 0 )
        goto LABEL_36;
      *(_BYTE *)a6 = 0;
      v25 = NtPlugPlayGetDeviceStatus(a1, (int)v55, (int)&v50, (int)&v56);
      v10 = v25;
      if ( v25 == -1073741810 )
        return 0;
      if ( v25 >= 0 )
      {
        if ( (v50 & 0x8000) != 0 || (v50 & 0x400) != 0 && v56 != 24 && v56 != 25 && v56 != 22 && v56 != 29 )
        {
LABEL_85:
          *(_BYTE *)a6 = -1;
          goto LABEL_86;
        }
        if ( (v50 & 8) == 0 )
        {
          v26 = PnpGetObjectProperty(
                  a1,
                  (int)a2,
                  1,
                  v53,
                  0,
                  (int)DEVPKEY_Device_Capabilities,
                  (int)&v58,
                  (int)&v60,
                  4,
                  (int)&v51,
                  0);
          v16 = -1073741275;
          v10 = v26;
          if ( v26 == -1073741275 )
            return 0;
          if ( v26 < 0 || (v60 & 0x40) == 0 )
            goto LABEL_37;
LABEL_30:
          *(_BYTE *)a6 = -1;
          goto LABEL_37;
        }
      }
    }
    else if ( v13 == 15 && !memcmp(a4, (unsigned int)DEVPKEY_Device_IsConnected, 16) )
    {
      *a5 = 17;
      *v8 = 1;
      if ( !v11 )
        return -1073741789;
      v14 = (int)a2;
      v10 = RtlInitUnicodeStringEx((int)v55, a2);
      v15 = a1;
      if ( v10 < 0 )
        goto LABEL_36;
      *(_BYTE *)a6 = 0;
      v30 = NtPlugPlayGetDeviceStatus(a1, (int)v55, (int)&v50, (int)&v56);
      v10 = v30;
      if ( v30 == -1073741810 )
        return 0;
      if ( v30 >= 0 && (v50 & 0x2000000) == 0 )
      {
        v31 = PnpGetObjectProperty(
                a1,
                (int)a2,
                1,
                0,
                0,
                (int)DEVPKEY_Device_PresenceNotForDevice,
                (int)&v58,
                (int)v57,
                1,
                (int)&v51,
                0);
        v10 = v31;
        v16 = -1073741275;
        if ( v31 >= 0 )
        {
          if ( v58 == 17 && v57[0] == -1 )
            goto LABEL_37;
        }
        else
        {
          if ( v31 != -1073741275 && v31 != -1073741789 )
            goto LABEL_37;
          v10 = 0;
        }
        *(_BYTE *)a6 = -1;
        goto LABEL_37;
      }
    }
    else
    {
      if ( v13 != 16 || memcmp(a4, (unsigned int)DEVPKEY_Device_IsRebootRequired, 16) )
      {
        if ( v13 == 8 && !memcmp(a4, (unsigned int)DEVPKEY_Device_ReportedDeviceIdsHash, 16) )
        {
          v14 = (int)a2;
          *a5 = 7;
          *v8 = 4;
          v10 = RtlInitUnicodeStringEx((int)v55, a2);
          if ( v10 < 0 )
            goto LABEL_198;
          v46 = &a7;
          v43 = 13;
        }
        else
        {
          if ( v13 == 4 && !memcmp(a4, (unsigned int)DEVPKEY_Device_InLocalMachineContainer, 16) )
          {
            *a5 = 17;
            *v8 = 1;
            v15 = a1;
            v14 = (int)a2;
            v10 = PnpGetObjectProperty(
                    a1,
                    (int)a2,
                    1,
                    v53,
                    0,
                    (int)DEVPKEY_Device_ContainerId,
                    (int)&v58,
                    (int)v63,
                    16,
                    (int)&v51,
                    0);
            if ( v10 < 0 )
              goto LABEL_36;
            v10 = PnpGetObjectProperty(
                    a1,
                    (int)L"HTREE\\ROOT\\0",
                    1,
                    0,
                    0,
                    (int)DEVPKEY_Device_BaseContainerId,
                    (int)&v58,
                    (int)v64,
                    16,
                    (int)&v51,
                    0);
            if ( v10 < 0 )
              goto LABEL_36;
            if ( a7 < *v8 )
              return -1073741789;
            v16 = -1073741275;
            if ( memcmp((unsigned int)v64, (unsigned int)v63, 16) )
            {
              *(_BYTE *)a6 = 0;
              goto LABEL_37;
            }
            goto LABEL_30;
          }
          if ( v13 == 14 && !memcmp(a4, (unsigned int)DEVPKEY_Device_Stack, 16) )
          {
            v14 = (int)a2;
            *a5 = 8210;
            v10 = RtlInitUnicodeStringEx((int)v55, a2);
            if ( v10 < 0 )
              goto LABEL_198;
            v43 = 14;
            v46 = v8;
          }
          else
          {
            if ( v13 != 20 || memcmp(a4, (unsigned int)DEVPKEY_Device_DependencyProviders, 16) )
            {
              if ( v13 != 21 || memcmp(a4, (unsigned int)DEVPKEY_Device_DependencyDependents, 16) )
                return v10;
              v14 = (int)a2;
              *a5 = 8210;
              v10 = RtlInitUnicodeStringEx((int)v55, a2);
              if ( v10 >= 0 )
              {
                v45 = v11;
                v15 = a1;
                v10 = NtPlugPlayGetDeviceProperty(a1, v55, 16, a6, v45, v8);
                v16 = -1073741275;
                if ( v10 == -1073741772 )
                  v10 = -1073741275;
                goto LABEL_37;
              }
              goto LABEL_198;
            }
            v14 = (int)a2;
            *a5 = 8210;
            v10 = RtlInitUnicodeStringEx((int)v55, a2);
            if ( v10 < 0 )
            {
LABEL_198:
              v15 = a1;
              goto LABEL_36;
            }
            v43 = 15;
            v46 = v8;
          }
        }
        v44 = v11;
        v15 = a1;
        v10 = NtPlugPlayGetDeviceProperty(a1, v55, v43, a6, v44, v46);
        if ( v10 != -1073741772 )
          goto LABEL_36;
        return -1073741275;
      }
      *a5 = 17;
      *v8 = 1;
      if ( !v11 )
        return -1073741789;
      v14 = (int)a2;
      v10 = RtlInitUnicodeStringEx((int)v55, a2);
      v15 = a1;
      if ( v10 < 0 )
        goto LABEL_36;
      *(_BYTE *)a6 = 0;
      v32 = NtPlugPlayGetDeviceStatus(a1, (int)v55, (int)&v50, (int)&v56);
      v10 = v32;
      if ( v32 == -1073741810 )
        return 0;
      if ( v32 >= 0 && ((v50 & 0x100) != 0 || (v50 & 0x400) != 0 && v56 == 14) )
        goto LABEL_85;
    }
LABEL_86:
    v16 = -1073741275;
    goto LABEL_37;
  }
  v14 = (int)a2;
  v47 = v11;
  v15 = a1;
  v27 = PnpGetObjectProperty(
          a1,
          (int)a2,
          1,
          v53,
          0,
          (int)DEVPKEY_Device_FriendlyName,
          (int)a5,
          (int)a6,
          v47,
          (int)&v51,
          0);
  v10 = v27;
  if ( !v27 || v27 == -1073741789 )
  {
    *v8 = v51;
    goto LABEL_36;
  }
  if ( v27 != -1073741275 )
  {
LABEL_36:
    v16 = -1073741275;
    goto LABEL_37;
  }
  v28 = PnpGetObjectProperty(a1, (int)a2, 1, v53, 0, (int)DEVPKEY_Device_DeviceDesc, (int)a5, (int)a6, a7, (int)&v51, 0);
  v10 = v28;
  if ( !v28 || v28 == -1073741789 )
  {
    *v8 = v51;
    goto LABEL_36;
  }
  v16 = -1073741275;
  if ( v28 == -1073741275 )
    return v10;
LABEL_37:
  if ( v10 == -1073741810 )
  {
    v33 = CmOpenDeviceRegKey(v15, v14, 16, 0, 1, 0, (int)&v61, 0);
    v10 = v33;
    if ( v33 )
    {
      if ( v33 != -1073741810 && v33 != -1073741632 )
        v10 = -1073741823;
      return v10;
    }
    ZwClose();
    return v16;
  }
  return v10;
}
