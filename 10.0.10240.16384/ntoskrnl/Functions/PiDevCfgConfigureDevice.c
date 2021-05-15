// PiDevCfgConfigureDevice 
 
int __fastcall PiDevCfgConfigureDevice(_DWORD *a1, _DWORD *a2, int a3, int *a4, _DWORD *a5)
{
  int v8; // r8
  int v9; // r10
  int v11; // r4
  int v12; // r1
  _DWORD *v13; // r8
  int v14; // r3
  unsigned __int16 *v15; // r1
  int v16; // r4
  int v17; // r0
  int v18; // r2
  unsigned int v19; // r1
  char v20; // r1
  int v21; // r0
  int v22; // r2
  int v23; // r4
  int v24; // r3
  int v25; // r2
  int v26; // r0
  int v27; // r1
  int *v28; // r2
  _DWORD *v29; // r1
  _DWORD *i; // r8
  _DWORD *v31; // r8
  int *v32; // r2
  int v33; // r3
  unsigned __int16 *v34; // r7
  unsigned __int16 *v35; // r7
  unsigned int v36; // r7
  int v37; // r1
  _DWORD *v38; // r3
  int v39; // r2
  int v40; // r1
  int v41; // r0
  int v42; // r0
  int v43; // r0
  int v44; // r0
  int v45; // r0
  int v46; // r0
  int v47; // r3
  int v48; // r2
  int v49; // r3
  unsigned int v50; // r0
  int v51; // [sp+0h] [bp-1E8h]
  int *v52; // [sp+4h] [bp-1E4h]
  int v53; // [sp+4h] [bp-1E4h]
  int v54; // [sp+4h] [bp-1E4h]
  int v55; // [sp+4h] [bp-1E4h]
  int v56; // [sp+4h] [bp-1E4h]
  int v57; // [sp+4h] [bp-1E4h]
  int v58; // [sp+4h] [bp-1E4h]
  int v59; // [sp+4h] [bp-1E4h]
  int v60; // [sp+4h] [bp-1E4h]
  int v61; // [sp+4h] [bp-1E4h]
  int v62; // [sp+4h] [bp-1E4h]
  int v63; // [sp+4h] [bp-1E4h]
  int v64; // [sp+20h] [bp-1C8h]
  char v65; // [sp+24h] [bp-1C4h] BYREF
  char v66; // [sp+25h] [bp-1C3h] BYREF
  int v67; // [sp+28h] [bp-1C0h] BYREF
  char v68[4]; // [sp+2Ch] [bp-1BCh] BYREF
  int v69; // [sp+30h] [bp-1B8h] BYREF
  int v70; // [sp+34h] [bp-1B4h] BYREF
  int *v71; // [sp+38h] [bp-1B0h]
  unsigned __int16 *v72; // [sp+3Ch] [bp-1ACh]
  int v73; // [sp+40h] [bp-1A8h] BYREF
  const __int16 *v74; // [sp+44h] [bp-1A4h]
  unsigned __int16 *v75; // [sp+48h] [bp-1A0h]
  int v76; // [sp+50h] [bp-198h] BYREF
  int v77; // [sp+54h] [bp-194h]
  unsigned int v78; // [sp+58h] [bp-190h] BYREF
  _DWORD *v79; // [sp+5Ch] [bp-18Ch]
  int v80; // [sp+60h] [bp-188h] BYREF
  unsigned __int16 *v81; // [sp+64h] [bp-184h]
  int v82; // [sp+68h] [bp-180h] BYREF
  unsigned __int16 *v83; // [sp+6Ch] [bp-17Ch]
  int v84; // [sp+70h] [bp-178h] BYREF
  int v85; // [sp+74h] [bp-174h]
  int v86; // [sp+78h] [bp-170h] BYREF
  int v87; // [sp+7Ch] [bp-16Ch]
  int v88; // [sp+80h] [bp-168h]
  int v89; // [sp+84h] [bp-164h]
  int v90; // [sp+88h] [bp-160h]
  int v91; // [sp+8Ch] [bp-15Ch]
  int v92; // [sp+90h] [bp-158h]
  int v93; // [sp+94h] [bp-154h] BYREF
  int v94; // [sp+98h] [bp-150h]
  int v95; // [sp+A0h] [bp-148h] BYREF
  int v96; // [sp+A4h] [bp-144h]
  int v97; // [sp+A8h] [bp-140h] BYREF
  int v98; // [sp+ACh] [bp-13Ch]
  int v99; // [sp+B0h] [bp-138h] BYREF
  int v100; // [sp+B4h] [bp-134h]
  int v101; // [sp+B8h] [bp-130h]
  int v102; // [sp+BCh] [bp-12Ch]
  int v103; // [sp+C0h] [bp-128h]
  int v104; // [sp+C4h] [bp-124h]
  int v105; // [sp+C8h] [bp-120h]
  int v106; // [sp+CCh] [bp-11Ch]
  int v107; // [sp+D0h] [bp-118h] BYREF
  int v108; // [sp+D4h] [bp-114h]
  int v109; // [sp+D8h] [bp-110h] BYREF
  int v110; // [sp+DCh] [bp-10Ch]
  int v111; // [sp+E0h] [bp-108h] BYREF
  int v112; // [sp+E4h] [bp-104h]
  int v113; // [sp+E8h] [bp-100h]
  int v114; // [sp+ECh] [bp-FCh]
  int v115; // [sp+F0h] [bp-F8h] BYREF
  int v116; // [sp+F4h] [bp-F4h]
  unsigned int v117; // [sp+F8h] [bp-F0h]
  int v118; // [sp+FCh] [bp-ECh]
  int v119; // [sp+100h] [bp-E8h]
  int v120; // [sp+104h] [bp-E4h]
  __int16 v121[2]; // [sp+108h] [bp-E0h] BYREF
  int v122; // [sp+10Ch] [bp-DCh]
  int v123; // [sp+110h] [bp-D8h]
  int v124; // [sp+118h] [bp-D0h] BYREF
  int v125; // [sp+11Ch] [bp-CCh]
  int v126; // [sp+120h] [bp-C8h] BYREF
  int v127; // [sp+124h] [bp-C4h]
  int v128[2]; // [sp+128h] [bp-C0h] BYREF
  __int16 v129[2]; // [sp+130h] [bp-B8h] BYREF
  int v130; // [sp+134h] [bp-B4h]
  int v131; // [sp+138h] [bp-B0h] BYREF
  int v132[7]; // [sp+13Ch] [bp-ACh] BYREF
  _DWORD v133[4]; // [sp+158h] [bp-90h] BYREF
  int v134[32]; // [sp+168h] [bp-80h] BYREF

  v71 = a4;
  v78 = 0;
  v79 = a5;
  v92 = 0;
  v93 = 0;
  v87 = 0;
  v88 = 0;
  v113 = 0;
  v114 = 0;
  v124 = 0;
  v90 = 0;
  v91 = 0;
  v125 = 0;
  v126 = 0;
  v101 = 0;
  v102 = 0;
  v80 = 0;
  v72 = 0;
  v81 = 0;
  v104 = 0;
  v105 = 0;
  v82 = 0;
  v75 = 0;
  v83 = 0;
  v86 = 0;
  v84 = 0;
  v89 = 0;
  v85 = 0;
  v119 = 0;
  v120 = 0;
  v111 = 0;
  v112 = 0;
  v123 = 0;
  v109 = 0;
  v117 = 0;
  v118 = 0;
  v110 = 0;
  v106 = 0;
  v8 = 1024;
  v69 = 1024;
  v70 = 0;
  v128[0] = 0;
  v107 = 0;
  v108 = 0;
  v76 = 0;
  v77 = 0;
  v97 = 0;
  v98 = 0;
  v99 = 0;
  v100 = 0;
  v129[0] = 0;
  v129[1] = 0;
  v130 = 0;
  v115 = 0;
  v116 = 0;
  v66 = 0;
  v65 = 0;
  v68[0] = 0;
  v67 = 0;
  LOWORD(v95) = 0;
  *a4 = 1024;
  *a5 = 0;
  v9 = a2[2];
  HIWORD(v95) = 0;
  v96 = 0;
  v121[0] = 0;
  v121[1] = 1040;
  v64 = ExAllocatePoolWithTag(1, 1040, 1667526736);
  v122 = v64;
  if ( !v64 )
    return sub_7E1C34();
  v127 = 131097;
  if ( !a3 )
  {
    v18 = v65;
    v19 = v78;
    goto LABEL_29;
  }
  v11 = PiDevCfgQueryDriverConfiguration((_DWORD *)a3);
  if ( v11 < 0 )
    goto LABEL_134;
  v119 = *(_DWORD *)(a3 + 156);
  if ( *(_DWORD *)(a3 + 172) )
  {
    v41 = ExpAllocateStringRoutine(*(unsigned __int16 *)(a3 + 170));
    v91 = v41;
    v125 = v41;
    if ( !v41 )
      return sub_7E1C34();
    memmove(v41, *(_DWORD *)(a3 + 172), *(unsigned __int16 *)(a3 + 170));
    v114 = *(unsigned __int16 *)(a3 + 168);
    LOWORD(v124) = v114;
    HIWORD(v124) = *(_WORD *)(a3 + 170);
  }
  if ( *(_DWORD *)(a3 + 180) )
  {
    v42 = ExpAllocateStringRoutine(*(unsigned __int16 *)(a3 + 178));
    v72 = (unsigned __int16 *)v42;
    v81 = (unsigned __int16 *)v42;
    if ( !v42 )
      return sub_7E1C34();
    memmove(v42, *(_DWORD *)(a3 + 180), *(unsigned __int16 *)(a3 + 178));
    v101 = *(unsigned __int16 *)(a3 + 176);
    LOWORD(v80) = v101;
    HIWORD(v80) = *(_WORD *)(a3 + 178);
  }
  if ( *(_DWORD *)(a3 + 188) )
  {
    v43 = ExpAllocateStringRoutine(*(unsigned __int16 *)(a3 + 186));
    v75 = (unsigned __int16 *)v43;
    v83 = (unsigned __int16 *)v43;
    if ( !v43 )
      return sub_7E1C34();
    memmove(v43, *(_DWORD *)(a3 + 188), *(unsigned __int16 *)(a3 + 186));
    v105 = *(unsigned __int16 *)(a3 + 184);
    LOWORD(v82) = v105;
    HIWORD(v82) = *(_WORD *)(a3 + 186);
  }
  if ( *(_DWORD *)(a3 + 196) )
  {
    v44 = ExpAllocateStringRoutine(*(unsigned __int16 *)(a3 + 194));
    v92 = v44;
    v87 = v44;
    if ( !v44 )
      return sub_7E1C34();
    memmove(v44, *(_DWORD *)(a3 + 196), *(unsigned __int16 *)(a3 + 194));
    v104 = *(unsigned __int16 *)(a3 + 192);
    LOWORD(v86) = v104;
    HIWORD(v86) = *(_WORD *)(a3 + 194);
  }
  if ( !*(_DWORD *)(a3 + 204) )
    goto LABEL_10;
  v45 = ExpAllocateStringRoutine(*(unsigned __int16 *)(a3 + 202));
  v89 = v45;
  v85 = v45;
  if ( !v45 )
    return sub_7E1C34();
  memmove(v45, *(_DWORD *)(a3 + 204), *(unsigned __int16 *)(a3 + 202));
  v102 = *(unsigned __int16 *)(a3 + 200);
  LOWORD(v84) = v102;
  HIWORD(v84) = *(_WORD *)(a3 + 202);
LABEL_10:
  v12 = *(_DWORD *)(a3 + 100);
  v13 = *(_DWORD **)(a3 + 120);
  v94 = *(_DWORD *)(a3 + 216);
  v69 = v94;
  v14 = *(_DWORD *)(a3 + 220);
  v103 = v12;
  v106 = v14;
  if ( v13 == (_DWORD *)(a3 + 120) )
    goto LABEL_11;
  while ( 1 )
  {
    v46 = PiDevCfgQueryDriverConfiguration(v13);
    v11 = v46;
    if ( v46 >= 0 )
    {
      if ( v13[43] )
      {
        v13[25] &= 0xFFFFFFFE;
      }
      else
      {
        if ( v13[45] )
        {
          v11 = PiDevCfgAppendMultiSz(&v80, 0, v13 + 44, 0);
          if ( v11 < 0 )
            goto LABEL_134;
        }
        if ( v13[47] )
        {
          v11 = PiDevCfgAppendMultiSz(&v82, 0, v13 + 46, 0);
          if ( v11 < 0 )
            goto LABEL_134;
        }
        if ( v13[49] )
        {
          v11 = PiDevCfgAppendMultiSz(&v86, 0, v13 + 48, 0);
          if ( v11 < 0 )
            goto LABEL_134;
        }
        if ( v13[51] )
        {
          v11 = PiDevCfgAppendMultiSz(&v84, 0, v13 + 50, 0);
          if ( v11 < 0 )
            goto LABEL_134;
        }
        v47 = v13[55];
        v94 |= v13[54];
        v69 = v94;
        v48 = v106 | v47;
        v49 = v13[25];
        v106 = v48;
        v103 |= v49;
        v11 = PiDevCfgAppendMultiSz(&v111, v13 + 5, 0, 0);
        if ( v11 < 0 )
          goto LABEL_134;
        v11 = PiDevCfgAppendMultiSz(&v109, v13 + 56, 0, 0);
        if ( v11 < 0 )
          goto LABEL_134;
      }
      goto LABEL_225;
    }
    if ( v46 != -1073741637 )
      break;
    if ( !PnpBootMode )
      goto LABEL_234;
    v11 = 0;
    v94 |= 0x400u;
    v69 = v94;
LABEL_225:
    v13 = (_DWORD *)*v13;
    if ( v13 == (_DWORD *)(a3 + 120) )
    {
      v72 = v81;
      v101 = (unsigned __int16)v80;
      v75 = v83;
      v105 = (unsigned __int16)v82;
      v92 = v87;
      v104 = (unsigned __int16)v86;
      goto LABEL_228;
    }
  }
  v72 = v81;
  v101 = (unsigned __int16)v80;
  v75 = v83;
  v104 = (unsigned __int16)v86;
  v105 = (unsigned __int16)v82;
  v92 = v87;
LABEL_228:
  LOBYTE(v12) = v103;
  v89 = v85;
  v102 = (unsigned __int16)v84;
  v113 = v112;
  v120 = (unsigned __int16)v111;
  v118 = v110;
  v123 = (unsigned __int16)v109;
LABEL_11:
  if ( v11 < 0 )
    goto LABEL_134;
  v8 = v94;
  if ( (v94 & 0x400) != 0
    && (*(_DWORD *)(a3 + 232) & 2) == 0
    && (PiDevCfgOptions & 1) == 0
    && !InitIsWinPEMode
    && !PnpBootMode )
  {
    goto LABEL_233;
  }
  if ( (v12 & 0x40) == 0 || (PiDevCfgOptions & 1) != 0 || (PiDevCfgFlags & 2) == 0 )
  {
LABEL_14:
    memset(v134, 0, 84);
    v134[4] = 0x1000000;
    v134[2] = (int)L"Description";
    v134[3] = (int)&v76;
    v134[11] = 0x1000000;
    v134[8] = 288;
    v134[9] = (int)L"Manufacturer";
    v134[10] = (int)&v97;
    v15 = *(unsigned __int16 **)(a3 + 12);
    v134[1] = 288;
    v11 = RtlpQueryRegistryValues(-1073741824, v15, v134, 0, v51, 1u);
    if ( v11 < 0 )
      goto LABEL_134;
    if ( !(_WORD)v76 && v77 )
      RtlFreeAnsiString(&v76);
    if ( !(_WORD)v97 && v98 )
      RtlFreeAnsiString(&v97);
    v16 = v119;
    if ( v119 && PnpOpenObjectRegKey(PiPnpRtlCtx, v119, 2, v127, 0, (int)&v93, 0, 0) >= 0 )
    {
      memset(v134, 0, 96);
      v134[0] = (int)DEVPKEY_DeviceClass_Configurable;
      v134[1] = 17;
      v134[2] = (int)&v66;
      v134[3] = 1;
      v134[6] = (int)DEVPKEY_DeviceClass_PolicyExempt;
      v134[7] = 17;
      v134[8] = (int)&v65;
      v134[9] = 1;
      v134[12] = (int)DEVPKEY_DeviceClass_DefaultService;
      v134[13] = 18;
      v134[14] = (int)&v107;
      v134[16] = 6;
      v134[18] = (int)DEVPKEY_DeviceClass_CompatibleFeatureScores;
      v134[19] = 4099;
      v134[20] = (int)&v78;
      v134[22] = 2;
      v11 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v16, 2, v93, v134, 4);
      if ( v11 < 0 )
        goto LABEL_134;
      if ( v134[5] < 0 )
      {
        v17 = 0;
        v66 = 0;
      }
      else
      {
        v17 = v66;
      }
      if ( v134[11] >= 0 )
      {
        v18 = v65;
      }
      else
      {
        v18 = 0;
        v65 = 0;
      }
      if ( v134[17] < 0 )
      {
        RtlInitUnicodeString((unsigned int)&v107, 0);
        v17 = v66;
        v18 = v65;
      }
      if ( v134[23] < 0 )
      {
        v19 = 0;
        v78 = 0;
LABEL_28:
        if ( !v17 && (PiDevCfgOptions & 1) == 0 && (PiDevCfgFlags & 2) != 0 )
        {
          if ( !PnpBootMode )
            goto LABEL_233;
          v8 |= 0x400u;
          v69 = v8;
        }
LABEL_29:
        if ( v19 )
        {
          v11 = 0;
          v50 = 0;
          if ( !v117 )
            goto LABEL_258;
          do
          {
            if ( *(unsigned __int8 *)(v50 + v19) == (unsigned __int8)*(_WORD *)(a3 + 58) )
              break;
            ++v50;
          }
          while ( v50 < v117 );
          if ( v50 >= v117 )
LABEL_258:
            v11 = -1073740764;
          if ( v11 < 0 )
            goto LABEL_134;
        }
        if ( (*a2 & 1) == 0 )
        {
          memset(v134, 0, 96);
          v134[0] = (int)DEVPKEY_Device_ClassGuid;
          v134[1] = 13;
          v134[2] = (int)v133;
          v134[3] = 16;
          v37 = a1[6];
          v134[6] = (int)DEVPKEY_Device_InstallFlags;
          v134[7] = 7;
          v134[8] = (int)&v67;
          v134[9] = 4;
          v134[12] = (int)DEVPKEY_Device_DriverNodeStrongName;
          v134[13] = 18;
          v134[14] = (int)&v95;
          v134[16] = 6;
          v11 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v37, 1, v9, v134, 3);
          if ( v11 < 0 )
            goto LABEL_134;
          if ( v134[5] >= 0 )
          {
            v90 = 1;
          }
          else
          {
            v133[0] = 0;
            v133[1] = 0;
            v133[2] = 0;
            v133[3] = 0;
          }
          if ( v134[11] >= 0 )
          {
            v20 = v67;
          }
          else
          {
            v20 = 0;
            v67 = 0;
          }
          if ( v134[17] >= 0 )
          {
            v18 = v65;
LABEL_32:
            if ( !v18 )
            {
              if ( (v20 & 4) != 0 )
              {
                if ( !a3 )
                  goto LABEL_270;
                memset(v134, 0, 96);
                v134[0] = (int)DEVPKEY_Device_DriverInfPath;
                v134[1] = 18;
                v134[2] = (int)&v115;
                v134[4] = 6;
                v11 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, a1[6], 1, v9, v134, 1);
                if ( v11 < 0 )
                  goto LABEL_134;
                if ( v134[5] < 0 )
                  RtlInitUnicodeString((unsigned int)&v115, 0);
                if ( v116 && RtlEqualUnicodeString((unsigned __int16 *)&v115, (unsigned __int16 *)(a3 + 20), 1) )
                {
LABEL_270:
                  v18 = -1;
                  v65 = -1;
                }
                else
                {
                  v18 = v65;
                }
              }
              if ( !v18 )
              {
                v11 = PiDevCfgEnforceDevicePolicy(a1, a2, v119);
                if ( v11 < 0 )
                  goto LABEL_134;
              }
            }
            if ( v93 )
            {
              v73 = 1835034;
              v132[2] = v93;
              v74 = L"Configuration";
              v88 = 0;
              v132[1] = 24;
              v132[4] = 576;
              v132[3] = (int)&v73;
              v132[5] = 0;
              v132[6] = 0;
              v21 = ZwOpenKey();
              v11 = v21;
              if ( v21 != -1073741772 )
              {
                if ( v21 < 0 )
                  goto LABEL_134;
                v11 = PiDevCfgVerifyDeviceAllowed(a1, v88);
                if ( v11 < 0 )
                  goto LABEL_134;
              }
            }
            if ( (*(_DWORD *)(*(_DWORD *)(a1[4] + 8) + 8) & 4) == 0
              || PnpGetObjectProperty(
                   PiPnpRtlCtx,
                   a1[6],
                   1,
                   v9,
                   0,
                   (int)DEVPKEY_Device_Reported,
                   (int)&v131,
                   (int)v68,
                   1,
                   (int)v132,
                   0) >= 0
              && v131 == 17
              && v132[0] == 1 )
            {
              v22 = v68[0];
            }
            else
            {
              v22 = 0;
              v68[0] = 0;
            }
            if ( a3 && !v91 && !v108 && !v22 && (a1[92] & 0x100) == 0 )
              goto LABEL_233;
            if ( (*a2 & 1) == 0 )
            {
              if ( !a3 )
              {
                v23 = v90;
                if ( !v90 || (a1[92] & 0x100) == 0 )
                  CmDeleteDeviceRegKey(PiPnpRtlCtx, a1[6], 17, 0);
                CmDeleteDeviceRegKey(PiPnpRtlCtx, a1[6], 18, 0);
                goto LABEL_164;
              }
              if ( !PnpIsNullGuid((int)v133) && !PnpIsNullGuid(a3 + 136) && memcmp((unsigned int)v133, a3 + 136, 16) )
                CmDeleteDeviceRegKey(PiPnpRtlCtx, a1[6], 18, 0);
            }
            v23 = v90;
            if ( a3 )
            {
              v24 = a3 + 20;
              goto LABEL_48;
            }
LABEL_164:
            v24 = 0;
LABEL_48:
            if ( a3 )
              v25 = a3 + 152;
            else
              v25 = 0;
            v52 = v128;
            if ( PiDevCfgMigrateDevice(a1, a2, v25, v24, &v126) >= 0 )
            {
              v8 |= v126;
              v69 = v8;
              v70 = v128[0];
            }
            if ( (*a2 & 1) == 0 )
            {
              if ( v23 )
                v38 = v133;
              else
                v38 = 0;
              if ( a3 )
                v39 = a3 + 136;
              else
                v39 = 0;
              PiDevCfgResetDeviceDriverSettings(a1, a2, v39, v93, v38, v128);
              PnpCtxRegDeleteTree(PiPnpRtlCtx, v9, L"Devices");
            }
            if ( !a3 || PnpIsNullGuid(a3 + 136) )
            {
              if ( (*a2 & 1) == 0 )
                PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a1[6], 1, v9, v52, DEVPKEY_Device_ClassGuid, 0, 0, 0);
            }
            else
            {
              v11 = PiDevCfgSetObjectProperty(
                      PiPnpRtlCtx,
                      a2,
                      a1[6],
                      1,
                      v9,
                      v52,
                      DEVPKEY_Device_ClassGuid,
                      13,
                      a3 + 136,
                      16);
              if ( v11 < 0 )
                goto LABEL_134;
            }
            if ( v91 )
            {
              if ( v114 )
              {
                v26 = PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_Service,
                        18,
                        v91,
                        v114 + 2);
                goto LABEL_59;
              }
            }
            else if ( v108 && (_WORD)v107 )
            {
              v26 = PiDevCfgSetObjectProperty(
                      PiPnpRtlCtx,
                      a2,
                      a1[6],
                      1,
                      v9,
                      v52,
                      DEVPKEY_Device_Service,
                      18,
                      v108,
                      (unsigned __int16)v107 + 2);
LABEL_59:
              v11 = v26;
              if ( v26 < 0 )
                goto LABEL_134;
LABEL_60:
              if ( v72 )
              {
                v11 = PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_LowerFilters,
                        8210,
                        v72,
                        v101);
                if ( v11 < 0 )
                  goto LABEL_134;
              }
              else if ( (*a2 & 1) == 0 )
              {
                PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a1[6], 1, v9, v52, DEVPKEY_Device_LowerFilters, 0, 0, 0);
              }
              if ( v75 )
              {
                v11 = PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_UpperFilters,
                        8210,
                        v75,
                        v105);
                if ( v11 < 0 )
                  goto LABEL_134;
              }
              else if ( (*a2 & 1) == 0 )
              {
                PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a1[6], 1, v9, v52, DEVPKEY_Device_UpperFilters, 0, 0, 0);
              }
              if ( a3 && v77 )
              {
                v11 = PiDevCfgBuildIndirectString(a3, &v76, &v99, v129);
                if ( v11 < 0 )
                  goto LABEL_134;
                if ( (v8 & 0x400) == 0 || (PiDevCfgOptions & 1) != 0 )
                {
                  v11 = PiDevCfgSetObjectProperty(
                          PiPnpRtlCtx,
                          a2,
                          a1[6],
                          1,
                          v9,
                          v52,
                          DEVPKEY_Device_DeviceDesc,
                          18,
                          v100,
                          (unsigned __int16)v99 + 2);
                  if ( v11 < 0 )
                    goto LABEL_134;
                }
                if ( v130 )
                {
                  v11 = PiDevCfgSetObjectProperty(
                          PiPnpRtlCtx,
                          a2,
                          a1[6],
                          1,
                          v9,
                          v52,
                          DEVPKEY_Device_DriverDesc,
                          18,
                          v130,
                          (unsigned __int16)v129[0] + 2);
                  if ( v11 < 0 )
                    goto LABEL_134;
                }
                else if ( (*a2 & 1) == 0 )
                {
                  PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a1[6], 1, v9, v52, DEVPKEY_Device_DriverDesc, 0, 0, 0);
                }
                RtlFreeAnsiString(&v99);
              }
              else if ( (*a2 & 1) == 0 )
              {
                PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a1[6], 1, v9, v52, DEVPKEY_Device_DriverDesc, 0, 0, 0);
                if ( a3 )
                {
LABEL_75:
                  if ( v98 )
                  {
                    v11 = PiDevCfgBuildIndirectString(a3, &v97, &v99, 0);
                    if ( v11 < 0 )
                      goto LABEL_134;
                    v11 = PiDevCfgSetObjectProperty(
                            PiPnpRtlCtx,
                            a2,
                            a1[6],
                            1,
                            v9,
                            v52,
                            DEVPKEY_Device_Manufacturer,
                            18,
                            v100,
                            (unsigned __int16)v99 + 2);
                    if ( v11 < 0 )
                      goto LABEL_134;
LABEL_78:
                    if ( a3 && *(_DWORD *)(a3 + 164) )
                    {
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v52,
                              DEVPKEY_Device_DriverProvider,
                              18,
                              *(_DWORD *)(a3 + 164),
                              *(unsigned __int16 *)(a3 + 160) + 2);
                      if ( v11 < 0 )
                        goto LABEL_134;
                    }
                    else if ( (*a2 & 1) == 0 )
                    {
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_DriverProvider,
                        0,
                        0,
                        0);
                    }
                    if ( a3 )
                    {
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v52,
                              DEVPKEY_Device_DriverDate,
                              16,
                              a3 + 64,
                              8);
                      if ( v11 < 0 )
                        goto LABEL_134;
                      v121[0] = 0;
                      v53 = *(unsigned __int16 *)(a3 + 72);
                      v51 = *(unsigned __int16 *)(a3 + 74);
                      v11 = RtlUnicodeStringPrintf(
                              v121,
                              (int)L"%u.%u.%u.%u",
                              *(unsigned __int16 *)(a3 + 78),
                              *(unsigned __int16 *)(a3 + 76));
                      if ( v11 < 0 )
                      {
                        v36 = v122;
LABEL_135:
                        if ( v11 != -1073741637 )
                          PiDevCfgLogDeviceConfigured(a2, a3, *v79, v11, v51);
                        goto LABEL_137;
                      }
                      v64 = v122;
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v53,
                              DEVPKEY_Device_DriverVersion,
                              18,
                              v122,
                              (unsigned __int16)v121[0] + 2);
                      if ( v11 < 0 )
                        goto LABEL_134;
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v54,
                              DEVPKEY_Device_DriverInfPath,
                              18,
                              *(_DWORD *)(a3 + 24),
                              *(unsigned __int16 *)(a3 + 20) + 2);
                      if ( v11 < 0 )
                        goto LABEL_134;
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v55,
                              DEVPKEY_Device_DriverInfSection,
                              18,
                              *(_DWORD *)(a3 + 48),
                              *(unsigned __int16 *)(a3 + 44) + 2);
                      if ( v11 < 0 )
                        goto LABEL_134;
                      v11 = PiDevCfgBuildDriverNodeStrongName((unsigned __int16 *)a3, (int)&v97, (int)&v76, &v73);
                      if ( v11 < 0 )
                        goto LABEL_134;
                      if ( v96 && !RtlCompareUnicodeString((unsigned __int16 *)&v95, (unsigned __int16 *)&v73, 1) )
                        RtlFreeAnsiString(&v95);
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v56,
                              DEVPKEY_Device_DriverNodeStrongName,
                              18,
                              v74,
                              (unsigned __int16)v73 + 2);
                      RtlFreeAnsiString(&v73);
                      if ( v11 < 0 )
                        goto LABEL_134;
                    }
                    else if ( (*a2 & 1) == 0 )
                    {
                      PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a1[6], 1, v9, v52, DEVPKEY_Device_DriverDate, 0, 0, 0);
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v59,
                        DEVPKEY_Device_DriverVersion,
                        0,
                        0,
                        0);
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v60,
                        DEVPKEY_Device_DriverInfPath,
                        0,
                        0,
                        0);
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v61,
                        DEVPKEY_Device_DriverInfSection,
                        0,
                        0,
                        0);
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v62,
                        DEVPKEY_Device_DriverNodeStrongName,
                        0,
                        0,
                        0);
                    }
                    v27 = v67;
                    if ( !v96 || (v67 & 8) != 0 || (a1[67] & 0x6000) != 0 )
                    {
                      if ( (*a2 & 1) != 0 )
                        goto LABEL_92;
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_RollbackDriverNode,
                        0,
                        0,
                        0);
                    }
                    else
                    {
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v52,
                              DEVPKEY_Device_RollbackDriverNode,
                              18,
                              v96,
                              (unsigned __int16)v95 + 2);
                      if ( v11 < 0 )
                        goto LABEL_134;
                    }
                    v27 = v67;
LABEL_92:
                    if ( v92 )
                    {
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v52,
                              DEVPKEY_Device_DriverIncludedInfs,
                              8210,
                              v92,
                              v104);
                      if ( v11 < 0 )
                        goto LABEL_134;
                    }
                    else
                    {
                      if ( (*a2 & 1) != 0 )
                        goto LABEL_94;
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_DriverIncludedInfs,
                        0,
                        0,
                        0);
                    }
                    v27 = v67;
LABEL_94:
                    if ( v89 )
                    {
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v52,
                              DEVPKEY_Device_DriverIncludedConfigs,
                              8210,
                              v89,
                              v102);
                      if ( v11 < 0 )
                        goto LABEL_134;
                    }
                    else
                    {
                      if ( (*a2 & 1) != 0 )
                        goto LABEL_96;
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_DriverIncludedConfigs,
                        0,
                        0,
                        0);
                    }
                    v27 = v67;
LABEL_96:
                    if ( v113 )
                    {
                      v11 = PiDevCfgSetObjectProperty(
                              PiPnpRtlCtx,
                              a2,
                              a1[6],
                              1,
                              v9,
                              v52,
                              DEVPKEY_Device_DriverExtendedInfs,
                              8210,
                              v113,
                              v120);
                      if ( v11 < 0 )
                        goto LABEL_134;
                    }
                    else
                    {
                      if ( (*a2 & 1) != 0 )
                      {
LABEL_98:
                        if ( !a3 || *(_DWORD *)(a3 + 56) == -1 )
                        {
                          if ( (*a2 & 1) != 0 )
                          {
LABEL_103:
                            if ( v27 )
                            {
                              PiDevCfgSetObjectProperty(
                                PiPnpRtlCtx,
                                a2,
                                a1[6],
                                1,
                                v9,
                                v52,
                                DEVPKEY_Device_InstallFlags,
                                0,
                                0,
                                0);
                              LOBYTE(v27) = v67;
                            }
                            if ( a3 )
                            {
                              v28 = v71;
                              *v71 = v8;
                              if ( (*(_DWORD *)(a3 + 100) & 8) != 0 && (PiDevCfgFlags & 2) != 0 )
                                *v28 = v8 | 0x400;
                              v11 = PiDevCfgConfigureDeviceDriver(a1, a2, a3, &v69, &v70);
                              if ( v11 < 0 )
                                goto LABEL_134;
                              v29 = v79;
                              *v71 |= v69;
                              *v29 |= v70;
                              for ( i = *(_DWORD **)(a3 + 120); i != (_DWORD *)(a3 + 120); i = (_DWORD *)*i )
                              {
                                if ( (i[25] & 1) != 0 )
                                {
                                  v11 = PiDevCfgConfigureDeviceDriver(a1, a2, i, &v69, &v70);
                                  if ( v11 < 0 )
                                    goto LABEL_134;
                                  *v71 |= v69;
                                  *v79 |= v70;
                                }
                              }
                              v11 = PiDevCfgConfigureDeviceLocation((int)a1, (int)a2, &v69, &v70);
                              if ( v11 < 0 )
                                goto LABEL_134;
                              v31 = v79;
                              *v71 |= v69;
                              *v31 |= v70;
                            }
                            else
                            {
                              if ( (a1[92] & 0x100) != 0 )
                              {
                                v31 = v79;
                                *v71 = 0;
                                goto LABEL_112;
                              }
                              *v71 = 64;
                              PnpDeleteDeviceInterfaces(a1 + 5);
                              v31 = v79;
                            }
                            LOBYTE(v27) = v67;
LABEL_112:
                            if ( v106 && !InitIsWinPEMode && PipIsDevNodeDNStarted((int)a1) || (v27 & 2) != 0 )
                              *v31 |= 2u;
                            if ( v90 )
                              *v31 |= 1u;
                            if ( v88 )
                            {
                              v52 = &v70;
                              v11 = PiDevCfgConfigureDeviceKeys(a1, a2, v88, -1, &v69);
                              if ( v11 < 0 )
                                goto LABEL_134;
                              *v71 |= v69;
                              *v31 |= v70;
                            }
                            if ( a3 )
                            {
                              v32 = *(int **)(a3 + 228);
                              v33 = *(_DWORD *)(a3 + 224);
                            }
                            else
                            {
                              v32 = &dword_8CA6A8;
                              v33 = PiDevCfgEmptyString;
                            }
                            v73 = v33;
                            v74 = (const __int16 *)v32;
                            v11 = PiDevCfgSetObjectProperty(
                                    PiPnpRtlCtx,
                                    a2,
                                    a1[6],
                                    1,
                                    v9,
                                    v52,
                                    DEVPKEY_Device_ConfigurationId,
                                    18,
                                    v32,
                                    (unsigned __int16)v33 + 2);
                            if ( v11 < 0 )
                              goto LABEL_134;
                            if ( v118 )
                            {
                              v11 = PiDevCfgSetObjectProperty(
                                      PiPnpRtlCtx,
                                      a2,
                                      a1[6],
                                      1,
                                      v9,
                                      v58,
                                      DEVPKEY_Device_ExtendedConfigurationIds,
                                      8210,
                                      v118,
                                      v123);
                              if ( v11 < 0 )
                                goto LABEL_134;
                            }
                            else if ( (*a2 & 1) == 0 )
                            {
                              PiDevCfgSetObjectProperty(
                                PiPnpRtlCtx,
                                a2,
                                a1[6],
                                1,
                                v9,
                                v58,
                                DEVPKEY_Device_ExtendedConfigurationIds,
                                0,
                                0,
                                0);
                            }
                            if ( !a3 || !*(_DWORD *)(a3 + 84) )
                            {
                              if ( (*a2 & 1) == 0 )
                                PiDevCfgSetObjectProperty(
                                  PiPnpRtlCtx,
                                  a2,
                                  a1[6],
                                  1,
                                  v9,
                                  v58,
                                  DEVPKEY_Device_MatchingTargetComputerId,
                                  0,
                                  0,
                                  0);
                              goto LABEL_129;
                            }
                            v11 = PiDevCfgSetObjectProperty(
                                    PiPnpRtlCtx,
                                    a2,
                                    a1[6],
                                    1,
                                    v9,
                                    v58,
                                    DEVPKEY_Device_MatchingTargetComputerId,
                                    18,
                                    *(_DWORD *)(a3 + 84),
                                    *(unsigned __int16 *)(a3 + 80) + 2);
                            if ( v11 >= 0 )
                            {
LABEL_129:
                              if ( v91 && v114 )
                                ((void (*)(void))PipHardwareConfigActivateService)();
                              v34 = v72;
                              if ( v72 )
                              {
                                while ( *v34 )
                                {
                                  PipHardwareConfigActivateService(v34);
                                  if ( !PnpBootMode && (*(_DWORD *)(a3 + 100) & 0x10) != 0 )
                                    PiDevCfgMakeServiceBootStart(v34);
                                  v34 += wcslen(v34) + 1;
                                }
                              }
                              v35 = v75;
                              if ( v75 )
                              {
                                while ( *v35 )
                                {
                                  PipHardwareConfigActivateService(v35);
                                  if ( !PnpBootMode && (*(_DWORD *)(a3 + 100) & 0x10) != 0 )
                                    PiDevCfgMakeServiceBootStart(v35);
                                  v35 += wcslen(v35) + 1;
                                }
                              }
                            }
LABEL_134:
                            v36 = v64;
                            goto LABEL_135;
                          }
                          PiDevCfgSetObjectProperty(
                            PiPnpRtlCtx,
                            a2,
                            a1[6],
                            1,
                            v9,
                            v52,
                            DEVPKEY_Device_MatchingDeviceId,
                            0,
                            0,
                            0);
                          PiDevCfgSetObjectProperty(
                            PiPnpRtlCtx,
                            a2,
                            a1[6],
                            1,
                            v9,
                            v63,
                            DEVPKEY_Device_DriverRank,
                            0,
                            0,
                            0);
                        }
                        else
                        {
                          v11 = PiDevCfgSetObjectProperty(
                                  PiPnpRtlCtx,
                                  a2,
                                  a1[6],
                                  1,
                                  v9,
                                  v52,
                                  DEVPKEY_Device_MatchingDeviceId,
                                  18,
                                  *(_DWORD *)(a3 + 40),
                                  *(unsigned __int16 *)(a3 + 36) + 2);
                          if ( v11 < 0 )
                            goto LABEL_134;
                          v11 = PiDevCfgSetObjectProperty(
                                  PiPnpRtlCtx,
                                  a2,
                                  a1[6],
                                  1,
                                  v9,
                                  v57,
                                  DEVPKEY_Device_DriverRank,
                                  7,
                                  a3 + 56,
                                  4);
                          if ( v11 < 0 )
                            goto LABEL_134;
                        }
                        v27 = v67;
                        goto LABEL_103;
                      }
                      PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_DriverExtendedInfs,
                        0,
                        0,
                        0);
                    }
                    v27 = v67;
                    goto LABEL_98;
                  }
LABEL_177:
                  if ( (*a2 & 1) == 0 )
                    PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a1[6], 1, v9, v52, DEVPKEY_Device_Manufacturer, 0, 0, 0);
                  goto LABEL_78;
                }
                memset(v134, 0, 96);
                v40 = a1[6];
                v134[0] = (int)DEVPKEY_Device_BusReportedDeviceDesc;
                v134[1] = 18;
                v134[2] = (int)&v76;
                v134[4] = 6;
                if ( PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v40, 1, v9, v134, 1) < 0 || v134[5] < 0 || !v77 )
                  goto LABEL_177;
                v11 = PiDevCfgSetObjectProperty(
                        PiPnpRtlCtx,
                        a2,
                        a1[6],
                        1,
                        v9,
                        v52,
                        DEVPKEY_Device_DeviceDesc,
                        18,
                        v77,
                        (unsigned __int16)v76 + 2);
                if ( v11 < 0 )
                  goto LABEL_134;
              }
              if ( !a3 )
                goto LABEL_177;
              goto LABEL_75;
            }
            if ( (*a2 & 1) == 0 && (v91 && v108 || !v68[0]) )
              PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a1[6], 1, v9, v52, DEVPKEY_Device_Service, 0, 0, 0);
            goto LABEL_60;
          }
          RtlInitUnicodeString((unsigned int)&v95, 0);
          v18 = v65;
        }
        v20 = v67;
        goto LABEL_32;
      }
      v117 = v134[21];
    }
    else
    {
      v17 = v66;
      v18 = v65;
    }
    v19 = v78;
    goto LABEL_28;
  }
  if ( PnpBootMode )
  {
    v8 = v94 | 0x400;
    v69 = v94 | 0x400;
    goto LABEL_14;
  }
LABEL_233:
  v11 = -1073741637;
LABEL_234:
  v36 = v64;
LABEL_137:
  RtlFreeAnsiString(&v76);
  RtlFreeAnsiString(&v97);
  RtlFreeAnsiString(&v107);
  RtlFreeAnsiString(&v124);
  RtlFreeAnsiString(&v80);
  RtlFreeAnsiString(&v82);
  RtlFreeAnsiString(&v86);
  RtlFreeAnsiString(&v84);
  RtlFreeAnsiString(&v111);
  RtlFreeAnsiString(&v109);
  RtlFreeAnsiString(&v99);
  RtlFreeAnsiString(&v115);
  RtlFreeAnsiString(&v95);
  if ( v36 )
    ExFreePoolWithTag(v36);
  if ( v78 )
    ExFreePoolWithTag(v78);
  if ( v93 )
    ZwClose();
  if ( v88 )
    ZwClose();
  return v11;
}
