// PipCallDriverAddDeviceQueryRoutine 
 
int __fastcall PipCallDriverAddDeviceQueryRoutine(int a1, unsigned __int16 *a2, unsigned int a3, _DWORD *a4, int a5)
{
  const __int16 *v6; // r4
  int v7; // r7
  int v8; // r6
  int v9; // r10
  unsigned __int16 *v11; // r1
  int v12; // r8
  int v13; // r2
  int v14; // t1
  int v15; // r2
  int v16; // r4
  unsigned int v17; // r8
  int v18; // r2
  int v19; // r0
  int v20; // r2
  int **v21; // r5
  int *v22; // r0
  int v23; // t1
  int v24; // r2
  unsigned int v25; // r1
  int v26; // r3
  __int64 v27; // r8
  int v28; // r0
  int v29; // r2
  int v30; // r1
  int v31; // r0
  int v32; // r0
  int v33; // r0
  int v34; // r3
  int v35; // [sp+8h] [bp-B0h]
  int v36; // [sp+Ch] [bp-ACh] BYREF
  int v37; // [sp+10h] [bp-A8h] BYREF
  int v38; // [sp+18h] [bp-A0h] BYREF
  unsigned __int16 *v39; // [sp+1Ch] [bp-9Ch]
  int v40[2]; // [sp+20h] [bp-98h] BYREF
  _DWORD v41[2]; // [sp+28h] [bp-90h] BYREF
  int v42; // [sp+30h] [bp-88h] BYREF
  int v43; // [sp+34h] [bp-84h]
  int *v44; // [sp+38h] [bp-80h]
  int v45; // [sp+3Ch] [bp-7Ch]
  int v46; // [sp+40h] [bp-78h]
  int v47; // [sp+44h] [bp-74h]
  int v48; // [sp+48h] [bp-70h]
  int v49; // [sp+4Ch] [bp-6Ch]
  unsigned int v50; // [sp+50h] [bp-68h]
  int v51; // [sp+54h] [bp-64h]
  int *v52; // [sp+58h] [bp-60h]
  int v53; // [sp+5Ch] [bp-5Ch]
  int v54; // [sp+60h] [bp-58h]
  int v55; // [sp+64h] [bp-54h]
  int *v56; // [sp+68h] [bp-50h]
  int v57; // [sp+6Ch] [bp-4Ch]
  int v58; // [sp+70h] [bp-48h]
  int v59; // [sp+74h] [bp-44h]
  int v60; // [sp+78h] [bp-40h]
  int v61; // [sp+7Ch] [bp-3Ch]
  int v62; // [sp+80h] [bp-38h]
  int v63; // [sp+84h] [bp-34h]
  int *v64; // [sp+88h] [bp-30h]
  int v65; // [sp+8Ch] [bp-2Ch]
  int v66; // [sp+90h] [bp-28h]
  int v67; // [sp+94h] [bp-24h]

  v6 = L"\\Driver\\";
  v37 = a5;
  v7 = 0;
  v8 = 0;
  v43 = 0;
  v40[0] = 0;
  v9 = 0;
  v35 = 0;
  v36 = 0;
  if ( a1 != 1 || a3 <= 2 )
    return sub_7CAFD4();
  LOWORD(v38) = 0;
  RtlInitUnicodeString((unsigned int)&v38, a2);
  v11 = v39;
  v12 = 1;
  v13 = 92;
  while ( 1 )
  {
    v14 = *v11++;
    if ( v14 != v13 )
      break;
    v23 = *((unsigned __int16 *)v6++ + 1);
    v13 = v23;
    if ( !v23 )
      goto LABEL_7;
  }
  v12 = 0;
LABEL_7:
  LOWORD(v41[0]) = 0;
  if ( v12 )
  {
    RtlInitUnicodeString((unsigned int)v41, v39);
    goto LABEL_12;
  }
  v15 = *a4;
  if ( *(_WORD *)(*a4 + 28) )
  {
LABEL_9:
    v16 = PipOpenServiceEnumKeys(&v38, 131097, &v36, 0, 0);
    if ( v16 < 0 )
    {
      PipSetDevNodeProblem(*a4, 19, v16);
      v7 = v36;
      goto LABEL_22;
    }
    v7 = v36;
    v16 = IopGetDriverNameFromKeyNode(v36, v41);
    if ( v16 < 0 )
    {
      PipSetDevNodeProblem(*a4, 19, v16);
      goto LABEL_22;
    }
    v35 = 1;
LABEL_12:
    v8 = IopReferenceDriverObjectByName(v41);
    v36 = v8;
    if ( !v8 )
    {
      if ( v12 )
        goto LABEL_20;
      if ( PnpGetServiceStartType(v39, v7, &v42) < 0 )
        v17 = 4;
      else
        v17 = v42;
      if ( v37 == 2 || PnPBootDriversInitialized )
      {
        v18 = a4[1];
        if ( v17 > *(_DWORD *)v18 )
        {
          if ( v17 == 4 && (*(_DWORD *)(*a4 + 268) & 0x6000) == 0 )
            PipSetDevNodeProblem(*a4, 32, 0);
          goto LABEL_20;
        }
        if ( !*(_BYTE *)(v18 + 4) )
        {
          if ( v17 && !PnpCheckPossibleBootStartDriver(v7) )
            *(_BYTE *)(*a4 + 448) = 1;
          goto LABEL_20;
        }
        v19 = IopLoadDriver(v7, 0, (_BYTE *)(v37 != 2), v40);
        v16 = v19;
        v7 = 0;
        v43 = v40[0];
        if ( v19 < 0 )
        {
          if ( v19 == -1073740955 )
          {
            if ( v40[0] == -1073741670 )
              v16 = -1073741670;
          }
          else if ( v19 != -1073741670
                 && v19 != -1073741218
                 && v19 != -1073740914
                 && v19 != -1073740948
                 && v19 != -1073740949
                 && v19 != -1073740961
                 && v19 != -1073740760 )
          {
            v16 = -1073741204;
          }
        }
        if ( PnPInitialized )
          IopCallDriverReinitializationRoutines(0);
        v8 = IopReferenceDriverObjectByName(v41);
        if ( v8 )
          goto LABEL_33;
        if ( !PnpBootMode
          || v16 == -1073740955
          || v16 == -1073740961
          || v16 == -1073740949
          || v16 == -1073740948
          || v16 == -1073740760 )
        {
          goto LABEL_48;
        }
        v16 = -1073741204;
      }
      else
      {
        v32 = PpInitGetGroupOrderIndex(v7);
        v33 = PnpLoadBootFilterDriver(v32, v41, v32, &v36);
        v16 = v33;
        if ( v33 < 0 )
        {
          if ( v33 != -1073740948 && v33 != -1073740949 )
          {
            if ( v17 && !*(_BYTE *)(a4[1] + 4) && !PnpCheckPossibleBootStartDriver(v7) )
              *(_BYTE *)(*a4 + 448) = 1;
            v8 = v36;
            goto LABEL_21;
          }
          v8 = v36;
        }
        else
        {
          v8 = v36;
          if ( !v36 )
            goto LABEL_48;
          ObfReferenceObject(v36);
        }
      }
      if ( !v8 )
      {
LABEL_48:
        v24 = *a4;
        v40[0] = 0;
        v25 = *(unsigned __int16 *)(v24 + 20);
        v42 = v16;
        LOWORD(v37) = v25 >> 1;
        v44 = &v37;
        v45 = 0;
        v46 = 2;
        v47 = 0;
        v26 = *(_DWORD *)(v24 + 24);
        v50 = v25;
        v48 = v26;
        v49 = 0;
        v51 = 0;
        v52 = &v42;
        v53 = 0;
        v54 = 4;
        v55 = 0;
        v56 = &v36;
        v57 = 0;
        v58 = 2;
        v59 = 0;
        LOWORD(v36) = LOWORD(v41[0]) >> 1;
        v60 = v41[1];
        v61 = 0;
        v62 = 2 * (LOWORD(v41[0]) >> 1);
        v63 = 0;
        v64 = v40;
        v65 = 0;
        v66 = 4;
        v67 = 0;
        v27 = PnpEtwHandle;
        if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverLoad_Fail) )
          EtwWrite(v27, SHIDWORD(v27), (int)KMPnPEvt_DriverLoad_Fail, 0);
        v28 = *a4;
        if ( (*(_DWORD *)(*a4 + 268) & 0x6000) != 0 )
          goto LABEL_21;
        if ( v16 <= -1073740955 )
        {
          if ( v16 == -1073740955 )
          {
            v29 = v43;
            v30 = 37;
LABEL_53:
            PipSetDevNodeProblem(v28, v30, v29);
            goto LABEL_21;
          }
          if ( v16 == -1073741670 )
          {
            v29 = -1073741670;
            v30 = 3;
            goto LABEL_53;
          }
          v29 = -1073741472;
          if ( v16 == -1073741472 )
          {
            v30 = 40;
            goto LABEL_53;
          }
          if ( v16 == -1073741411 )
          {
LABEL_101:
            v29 = v16;
            v30 = 39;
            goto LABEL_53;
          }
          v34 = -1073741218;
          if ( v16 != -1073741218 )
          {
            if ( v16 == -1073741204 )
              goto LABEL_101;
LABEL_112:
            v29 = v16;
            v30 = 31;
            goto LABEL_53;
          }
          v30 = 41;
LABEL_104:
          v29 = v34;
          goto LABEL_53;
        }
        if ( v16 == -1073740949 )
        {
          PipSetDevNodeProblem(v28, 48, -1073740949);
          PipSetDevNodeFlags(*a4, 0x100000);
          goto LABEL_21;
        }
        if ( v16 != -1073740948 )
        {
          v34 = -1073740914;
          if ( v16 == -1073740914 )
          {
            v30 = 38;
          }
          else
          {
            v34 = -1073740760;
            if ( v16 != -1073740760 )
              goto LABEL_112;
            v30 = 52;
          }
          goto LABEL_104;
        }
        PipSetDevNodeFlags(v28, 0x100000);
LABEL_114:
        v16 = 0;
        goto LABEL_21;
      }
    }
LABEL_33:
    if ( (*(_DWORD *)(v8 + 8) & 0x10) != 0 )
    {
      if ( PnpIsLegacyDriver(v8) )
      {
        if ( v37 != 2 )
          goto LABEL_114;
        PipSetDevNodeFlags(*a4, 4096);
        PipSetDevNodeState((_DWORD *)*a4, 776);
      }
      else
      {
        v20 = *(_DWORD *)(*a4 + 172);
        if ( v20 == 770 || v20 == 771 )
        {
          v21 = (int **)&a4[v37 + 2];
          v16 = 0;
          v22 = (int *)ExAllocatePoolWithTag(1, 8, 1852141648);
          if ( v22 )
          {
            *v22 = v8;
            v22[1] = 0;
            v8 = 0;
            while ( *v21 )
              v21 = (int **)(*v21 + 1);
            *v21 = v22;
          }
          else
          {
            v16 = -1073741670;
          }
          goto LABEL_21;
        }
      }
    }
LABEL_20:
    v16 = -1073741823;
LABEL_21:
    v9 = v35;
LABEL_22:
    if ( v7 )
      ZwClose();
    if ( v9 )
      RtlFreeAnsiString(v41);
    if ( v8 )
      ObfDereferenceObject(v8);
    return v16;
  }
  *(_DWORD *)(v15 + 28) = v38;
  *(_DWORD *)(v15 + 32) = v39;
  *(_DWORD *)(*a4 + 32) = ExAllocatePoolWithTag(1, HIWORD(v38), 1215327824);
  v31 = *(_DWORD *)(*a4 + 32);
  if ( v31 )
  {
    memmove(v31, (int)v39, HIWORD(v38));
    goto LABEL_9;
  }
  *(_WORD *)(*a4 + 30) = 0;
  v16 = -1073741823;
  *(_WORD *)(*a4 + 28) = 0;
  *(_DWORD *)(*a4 + 32) = 0;
  return v16;
}
