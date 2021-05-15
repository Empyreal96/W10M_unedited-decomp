// PiDevCfgFindDeviceMigrationNode 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiDevCfgFindDeviceMigrationNode(int a1, int a2, int a3, int a4, int a5)
{
  int *v5; // r10
  int *v6; // r6
  int v7; // r5
  int *v8; // r0
  int *v9; // r1 OVERLAPPED
  int v10; // r4
  unsigned __int16 *v11; // r0
  int v12; // r7
  int v13; // r0
  int v14; // r1
  int v15; // r3
  int v16; // r7
  int v18; // r7
  int v19; // r3
  int v20; // r0
  int *v21; // r4
  int **v22; // r1
  unsigned __int16 *v23; // r0
  int *v24; // r2
  int v25; // r1
  int v26; // r8
  unsigned __int16 *v27; // r10
  unsigned __int16 *v28; // r4
  int v29; // r6
  unsigned int v30; // r7
  unsigned __int16 *v31; // r9
  int v32; // r10
  int v33; // r3
  unsigned __int16 *v34; // r5
  unsigned __int16 *v35; // r10
  unsigned __int16 *v36; // r5
  int v37; // r6
  int v38; // r4
  int v39; // r3
  bool v40; // zf
  unsigned __int16 *v41; // r5
  char *v42; // r10
  unsigned __int16 *v43; // r7
  int v44; // r7
  int v45; // r1
  int v46; // r1
  int v47; // r10
  int v48; // r3
  int v49; // r0
  int *v50; // r2
  unsigned int v51; // r3
  unsigned int v52; // r2
  unsigned int v53; // r3
  __int64 v54; // kr00_8
  __int64 v55; // kr08_8
  __int64 v56; // kr10_8
  __int64 v57; // kr18_8
  __int64 v58; // kr20_8
  int v59; // r7
  unsigned int v60; // r1 OVERLAPPED
  unsigned int v61; // r2 OVERLAPPED
  unsigned int v62; // r3 OVERLAPPED
  unsigned int v63; // r4 OVERLAPPED
  bool v64; // zf
  int *v65; // r4
  unsigned int v66; // r0
  BOOL v67; // r3
  int *v68; // r1 OVERLAPPED
  int **v69; // r2 OVERLAPPED
  int **v70; // r3
  int v72; // [sp+8h] [bp-138h]
  int v73; // [sp+8h] [bp-138h]
  int *v74; // [sp+10h] [bp-130h] BYREF
  int **v75; // [sp+14h] [bp-12Ch]
  int v76; // [sp+18h] [bp-128h]
  int v77; // [sp+1Ch] [bp-124h]
  int v78; // [sp+20h] [bp-120h]
  unsigned __int16 *v79; // [sp+24h] [bp-11Ch]
  int *v80; // [sp+28h] [bp-118h] BYREF
  unsigned __int16 v81; // [sp+2Ch] [bp-114h] BYREF
  unsigned __int16 v82; // [sp+2Eh] [bp-112h]
  int v83; // [sp+30h] [bp-110h] BYREF
  int v84; // [sp+34h] [bp-10Ch]
  int v85; // [sp+38h] [bp-108h] BYREF
  int *v86; // [sp+3Ch] [bp-104h]
  int v87; // [sp+40h] [bp-100h] BYREF
  int v88; // [sp+44h] [bp-FCh]
  char *v89; // [sp+48h] [bp-F8h]
  int *v90; // [sp+4Ch] [bp-F4h]
  int v91; // [sp+50h] [bp-F0h]
  _DWORD *v92; // [sp+54h] [bp-ECh] BYREF
  int v93; // [sp+58h] [bp-E8h] BYREF
  int v94; // [sp+5Ch] [bp-E4h]
  int v95; // [sp+60h] [bp-E0h]
  int v96; // [sp+64h] [bp-DCh]
  int v97; // [sp+68h] [bp-D8h] BYREF
  int v98; // [sp+6Ch] [bp-D4h]
  int *v99; // [sp+70h] [bp-D0h]
  int v100; // [sp+74h] [bp-CCh] BYREF
  int v101; // [sp+78h] [bp-C8h] BYREF
  int v102; // [sp+7Ch] [bp-C4h]
  int v103[12]; // [sp+80h] [bp-C0h] BYREF
  unsigned __int16 *v104; // [sp+B0h] [bp-90h]
  int j; // [sp+B4h] [bp-8Ch]
  __int16 v106; // [sp+B8h] [bp-88h]
  __int16 v107; // [sp+BAh] [bp-86h]
  const __int16 *v108; // [sp+BCh] [bp-84h]
  unsigned __int16 *v109; // [sp+C0h] [bp-80h]
  int v110; // [sp+C4h] [bp-7Ch]
  int **v111; // [sp+C8h] [bp-78h]
  int v112; // [sp+CCh] [bp-74h]
  int i; // [sp+D0h] [bp-70h]
  int v114; // [sp+D4h] [bp-6Ch]
  unsigned __int16 v115[4]; // [sp+D8h] [bp-68h] BYREF
  unsigned __int16 v116[4]; // [sp+E0h] [bp-60h] BYREF
  _DWORD v117[4]; // [sp+E8h] [bp-58h] BYREF
  char v118[20]; // [sp+F8h] [bp-48h] BYREF
  int v119; // [sp+10Ch] [bp-34h]
  int v120; // [sp+110h] [bp-30h]
  int v121; // [sp+114h] [bp-2Ch]

  v110 = a4;
  v114 = a3;
  v111 = (int **)a5;
  v80 = 0;
  v81 = 0;
  v82 = 0;
  v100 = 0;
  v83 = 0;
  v84 = 0;
  v93 = 0;
  v94 = 0;
  v95 = 0;
  v97 = 0;
  v98 = 0;
  v101 = 0;
  v102 = 0;
  v87 = 0;
  v88 = 0;
  v89 = (char *)a2;
  v75 = &v74;
  v74 = (int *)&v74;
  v5 = (int *)a1;
  v90 = (int *)a1;
  v6 = 0;
  v77 = 0;
  v7 = NtQueryKey(a3, 4, v118, 0x28u, &v85);
  if ( v7 < 0 )
    goto LABEL_4;
  if ( !v119 )
  {
    v7 = -1073741275;
    goto LABEL_4;
  }
  v91 = v121 + 2 * (v120 + 13);
  v10 = ExAllocatePoolWithTag(1, v91, 1667526736);
  v76 = v10;
  v92 = (_DWORD *)v10;
  if ( !v10 )
  {
LABEL_10:
    v7 = -1073741670;
    goto LABEL_4;
  }
  v11 = (unsigned __int16 *)v5[5];
  if ( v11 )
  {
    v7 = RtlGUIDFromString(v11, v117);
    if ( v7 < 0 )
      goto LABEL_4;
  }
  else
  {
    v117[0] = 0;
    v117[1] = 0;
    v117[2] = 0;
    v117[3] = 0;
  }
  v12 = 0;
  v78 = 0;
  v13 = ZwEnumerateValueKey();
  v15 = -2147483622;
  for ( i = -2147483622; ; v15 = i )
  {
    v7 = v13;
    v72 = v13;
    if ( v13 == v15 )
    {
      v7 = 0;
      v72 = 0;
      goto LABEL_157;
    }
    if ( v13 != -2147483643 )
      break;
    ExFreePoolWithTag(v10);
    v91 = v85 + 2;
    v10 = ExAllocatePoolWithTag(1, v85 + 2, 1667526736);
    v76 = v10;
    v92 = (_DWORD *)v10;
    if ( !v10 )
      goto LABEL_10;
    v16 = v12 - 1;
LABEL_152:
    v12 = v16 + 1;
    v78 = v12;
    v13 = ZwEnumerateValueKey();
  }
  if ( v13 < 0 )
    goto LABEL_157;
  if ( *(_DWORD *)(v10 + 4) == 4 && *(_DWORD *)(v10 + 12) == 4 )
    v18 = *(_DWORD *)(*(_DWORD *)(v10 + 8) + v10);
  else
    v18 = v110;
  v19 = v10 + 2 * (*(_DWORD *)(v10 + 16) >> 1);
  *(_WORD *)(v19 + 20) = 0;
  if ( CmIsRootEnumeratedDevice((unsigned __int16 *)(v10 + 20), v14, 0, v19) )
  {
LABEL_151:
    v16 = v78;
    goto LABEL_152;
  }
  v20 = PiDevCfgQueryDeviceMigrationNode(v5, v10 + 20, &v80);
  v7 = v20;
  v72 = v20;
  if ( v20 == -1073741772 )
  {
    v80 = 0;
    PiDevCfgClearDeviceMigrationNode(v5, (unsigned __int16 *)(v10 + 20));
    goto LABEL_151;
  }
  if ( v20 < 0 )
    goto LABEL_157;
  v21 = v80;
  v80[25] = v18;
  v22 = v75;
  *v21 = (int)&v74;
  v21[1] = (int)v22;
  if ( *v22 != (int *)&v74 )
    __fastfail(3u);
  *v22 = v21;
  v23 = &v81;
  v86 = dword_8C6D98;
  v24 = v21;
  v75 = (int **)v21;
  v25 = v89 - (char *)v21;
  v96 = 2;
  v26 = 0;
  v79 = &v81;
  v99 = v21;
  v112 = v89 - (char *)v21;
  while ( 2 )
  {
    v27 = *(unsigned __int16 **)((char *)v24 + v25 + 16);
    v28 = (unsigned __int16 *)v24[7];
    v29 = 0;
    v104 = v27;
    v109 = v28;
    if ( !v28 || !v27 || (v30 = 0x4000, v31 = v27, !*v27) )
    {
LABEL_58:
      v37 = 0xFFFF;
      goto LABEL_59;
    }
    v32 = 0;
    do
    {
      v33 = *v28;
      v34 = v28;
      while ( v33 )
      {
        if ( !wcsicmp((int)v34, v31) )
        {
          v29 = 1;
          break;
        }
        v34 += wcslen(v34) + 1;
        v33 = *v34;
      }
      if ( !*v34 )
        v32 = (unsigned __int16)(v30 | v32);
      if ( v30 > 2 )
        v30 = (unsigned __int16)(v30 >> 1);
      v31 += wcslen(v31) + 1;
    }
    while ( *v31 );
    v73 = v32;
    v35 = v104;
    if ( !v29 )
    {
      v23 = v79;
      goto LABEL_58;
    }
    v36 = v109;
    v37 = v73;
    if ( wcsicmp((int)v109, v104) )
      v37 = (unsigned __int16)v73 | 0x8000;
    while ( v36[wcslen(v36) + 1] )
      v36 += wcslen(v36) + 1;
    while ( v35[wcslen(v35) + 1] )
      v35 += wcslen(v35) + 1;
    v40 = wcsicmp((int)v36, v35) == 0;
    v23 = v79;
    if ( !v40 )
      v37 = (unsigned __int16)v37 | 1;
LABEL_59:
    *v23++ = v37;
    v79 = v23;
    if ( v37 != 0xFFFF )
      v26 |= *v86;
    ++v86;
    v24 = v99 + 2;
    v99 += 2;
    v40 = v96-- == 1;
    v25 = v112;
    if ( !v40 )
      continue;
    break;
  }
  v38 = (int)v80;
  v6 = 0;
  v39 = v80[25];
  if ( (v39 & 0x10000) != 0 )
  {
    if ( (v26 & 0x10000) != 0 )
    {
      if ( (v39 & 0x1000) != 0 )
      {
        v40 = (v26 & 0x11000) == 0;
        goto LABEL_69;
      }
      goto LABEL_72;
    }
LABEL_71:
    v80[2] |= 1u;
    goto LABEL_72;
  }
  if ( (v39 & 0x1000) != 0 )
  {
    v40 = (v26 & 0x1000) == 0;
LABEL_69:
    if ( v40 )
      goto LABEL_71;
  }
LABEL_72:
  v41 = *(unsigned __int16 **)(v38 + 80);
  v42 = v89;
  if ( v41 && *((_DWORD *)v89 + 8) )
  {
LABEL_80:
    if ( *v41 )
    {
      v43 = (unsigned __int16 *)*((_DWORD *)v42 + 8);
      RtlInitUnicodeString((unsigned int)v116, v41);
      while ( 1 )
      {
        if ( !*v43 )
        {
          v41 += wcslen(v41) + 1;
          goto LABEL_80;
        }
        RtlInitUnicodeString((unsigned int)v115, v43);
        if ( RtlEqualUnicodeString(v116, v115, 1) )
          break;
        v43 += (v115[0] >> 1) + 1;
      }
      LOWORD(v26) = v26 | 0x200;
      *(_DWORD *)(v38 + 84) = v41;
    }
  }
  if ( (*(_DWORD *)(v38 + 100) & 0x200) != 0 && (v26 & 0x200) == 0 )
    *(_DWORD *)(v38 + 8) |= 1u;
  v44 = v77;
  if ( !*(_DWORD *)(v38 + 72) )
    goto LABEL_95;
  if ( (v77 & 0x100) != 0 )
    goto LABEL_92;
  memset(v103, 0, sizeof(v103));
  v45 = *((_DWORD *)v42 + 1);
  v103[0] = (int)DEVPKEY_Device_LocationInfo;
  v103[1] = 18;
  v103[2] = (int)&v93;
  v103[4] = 6;
  v7 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v45, 1, *((_DWORD *)v42 + 2), v103, 1u);
  v72 = v7;
  if ( v7 < 0 )
    goto LABEL_156;
  if ( v103[5] < 0 )
    RtlInitUnicodeString((unsigned int)&v93, 0);
  v44 |= 0x100u;
  v77 = v44;
LABEL_92:
  if ( v94 && !RtlCompareUnicodeString((unsigned __int16 *)(v38 + 68), (unsigned __int16 *)&v93, 1) )
    LOWORD(v26) = v26 | 0x100;
LABEL_95:
  if ( (*(_DWORD *)(v38 + 100) & 0x100) != 0 && (v26 & 0x300) == 0 )
    *(_DWORD *)(v38 + 8) |= 1u;
  if ( (v44 & 0x30) != 0 )
  {
LABEL_103:
    if ( ((v100 ^ *(_DWORD *)(v38 + 56)) & 0x10) != 0 )
    {
      if ( (*(_DWORD *)(v38 + 100) & 0x10) != 0 )
        *(_DWORD *)(v38 + 8) |= 1u;
    }
    else
    {
      LOWORD(v26) = v26 | 0x10;
    }
    if ( *(_DWORD *)(v38 + 64) )
    {
      if ( !v84 || RtlCompareUnicodeString((unsigned __int16 *)(v38 + 60), (unsigned __int16 *)&v83, 1) )
        goto LABEL_108;
    }
    else if ( v84 )
    {
      goto LABEL_108;
    }
    LOWORD(v26) = v26 | 0x20;
LABEL_108:
    if ( (*(_DWORD *)(v38 + 100) & 0x20) != 0 && (v26 & 0x20) == 0 )
      *(_DWORD *)(v38 + 8) |= 1u;
    if ( *(_DWORD *)(v38 + 92) )
    {
      if ( (v44 & 2) == 0 )
      {
        v47 = (int)v90;
        v48 = v90[6];
        if ( v48 )
        {
          v49 = *(_DWORD *)(v48 + 4);
          if ( v49 )
          {
            if ( PiDevCfgGetDriverPackageId(v49, (int)&v97) >= 0 )
            {
              memset(v103, 0, sizeof(v103));
              v103[0] = (int)DEVPKEY_DriverPackage_OriginalInfName;
              v103[1] = 18;
              v103[2] = (int)&v87;
              v103[4] = 6;
              v7 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v98, 7, 0, v103, 1u);
              v72 = v7;
              if ( v7 < 0 )
                goto LABEL_156;
              if ( v103[5] < 0 )
                RtlInitUnicodeString((unsigned int)&v87, 0);
            }
            if ( v88 )
              v50 = &v87;
            else
              v50 = *(int **)(v47 + 24);
            v101 = *v50;
            v95 = v50[1];
            v102 = v95;
          }
        }
        v77 = v44 | 2;
      }
      if ( v95 && !RtlCompareUnicodeString((unsigned __int16 *)(v38 + 88), (unsigned __int16 *)&v101, 1) )
        LOWORD(v26) = v26 | 2;
    }
    if ( (*(_DWORD *)(v38 + 100) & 2) != 0 && (v26 & 2) == 0 )
      *(_DWORD *)(v38 + 8) |= 1u;
    if ( !memcmp(v38 + 40, (unsigned int)v117, 16) )
    {
      LOWORD(v26) = v26 | 1;
    }
    else if ( (*(_DWORD *)(v38 + 100) & 1) != 0 )
    {
      *(_DWORD *)(v38 + 8) |= 1u;
    }
    v51 = v82 | ((v81 | 0xF0000000) << 16);
    v52 = HIWORD(v51) | 0xF0000000;
    v53 = v51 << 16;
    *(_DWORD *)(v38 + 104) = v53;
    *(_DWORD *)(v38 + 108) = v52;
    if ( (v26 & 0x200) == 0 )
    {
      *(_DWORD *)(v38 + 104) = v53 | 0xF000;
      *(_DWORD *)(v38 + 108) = v52;
    }
    if ( (v26 & 0x100) == 0 )
    {
      v54 = *(_QWORD *)(v38 + 104);
      *(_DWORD *)(v38 + 104) = v54 | 0x100;
      *(_DWORD *)(v38 + 108) = HIDWORD(v54);
    }
    if ( (v26 & 0x20) == 0 )
    {
      v55 = *(_QWORD *)(v38 + 104);
      *(_DWORD *)(v38 + 104) = v55 | 0x20;
      *(_DWORD *)(v38 + 108) = HIDWORD(v55);
    }
    if ( (v26 & 0x10) == 0 )
    {
      v56 = *(_QWORD *)(v38 + 104);
      *(_DWORD *)(v38 + 104) = v56 | 0x10;
      *(_DWORD *)(v38 + 108) = HIDWORD(v56);
    }
    if ( (v26 & 2) == 0 )
    {
      v57 = *(_QWORD *)(v38 + 104);
      *(_DWORD *)(v38 + 104) = v57 | 2;
      *(_DWORD *)(v38 + 108) = HIDWORD(v57);
    }
    v5 = v90;
    if ( (v26 & 1) == 0 )
    {
      v58 = *(_QWORD *)(v38 + 104);
      *(_DWORD *)(v38 + 104) = v58 | 1;
      *(_DWORD *)(v38 + 108) = HIDWORD(v58);
    }
    v10 = v76;
    goto LABEL_151;
  }
  memset(v103, 0, sizeof(v103));
  v46 = *((_DWORD *)v42 + 1);
  v103[0] = (int)DEVPKEY_Device_Capabilities;
  v103[1] = 7;
  v103[2] = (int)&v100;
  v103[3] = 4;
  v103[6] = (int)DEVPKEY_Device_BusReportedDeviceDesc;
  v103[7] = 18;
  v103[8] = (int)&v83;
  v103[10] = 6;
  v7 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v46, 1, *((_DWORD *)v42 + 2), v103, 2u);
  v72 = v7;
  if ( v7 >= 0 )
  {
    if ( v103[11] < 0 )
      RtlInitUnicodeString((unsigned int)&v83, 0);
    v44 |= 0x30u;
    v77 = v44;
    goto LABEL_103;
  }
LABEL_156:
  v10 = v76;
LABEL_157:
  ExFreePoolWithTag(v10);
  if ( v7 >= 0 )
  {
    v8 = v74;
    if ( v74 == (int *)&v74 )
      goto LABEL_197;
    v59 = (unsigned __int8)PnpSetupInProgress;
    while ( 1 )
    {
      *(_QWORD *)&v60 = *((_QWORD *)v8 + 13);
      if ( (v60 & v61) != -1 )
        break;
LABEL_166:
      v8 = (int *)*v8;
      if ( v8 == (int *)&v74 )
      {
        v7 = v72;
        if ( v6 )
        {
          if ( (v6[2] & 2) != 0 )
          {
            v65 = v74;
            for ( j = 1; v65 != (int *)&v74; v65 = (int *)*v65 )
            {
              if ( (v65[2] & 2) != 0 && *((_QWORD *)v65 + 13) == *((_QWORD *)v6 + 13) )
              {
                v107 = 20;
                v106 = 18;
                v108 = L"Duplicate";
                ZwSetValueKey();
              }
            }
          }
          else if ( IopGetRegistryValue(v6[5], L"Duplicate", 0, (int *)&v92) >= 0 )
          {
            v66 = (unsigned int)v92;
            v67 = v92[1] == 4 && v92[3] == 4;
            if ( v67 && *(_DWORD *)((char *)v92 + v92[2]) )
              v6[2] |= 2u;
            ExFreePoolWithTag(v66);
          }
          *(_QWORD *)&v68 = *(_QWORD *)v6;
          if ( *(int **)(*v6 + 4) != v6 || *v69 != v6 )
            __fastfail(3u);
          v70 = v111;
          *v69 = v68;
          v68[1] = (int)v69;
          *v70 = v6;
          goto LABEL_4;
        }
        v8 = v74;
LABEL_197:
        v7 = -1073741275;
        goto LABEL_5;
      }
    }
    if ( v6 )
    {
      *(_QWORD *)&v62 = *((_QWORD *)v6 + 13);
      if ( v63 < v61 )
      {
        v64 = v62 == v60;
      }
      else
      {
        if ( v63 > v61 )
          goto LABEL_165;
        v64 = v62 == v60;
        if ( v62 > v60 )
          goto LABEL_165;
      }
      if ( !v64 || v63 != v61 )
        goto LABEL_166;
      if ( !v59 || !v8[24] || v6[24] )
      {
        v6[2] |= 2u;
        v8[2] |= 2u;
        goto LABEL_166;
      }
    }
LABEL_165:
    v6 = v8;
    goto LABEL_166;
  }
LABEL_4:
  while ( 1 )
  {
    v8 = v74;
LABEL_5:
    if ( v8 == (int *)&v74 )
      break;
    *(_QWORD *)&v9 = *(_QWORD *)v8;
    if ( (int **)v8[1] != &v74 || (int *)v9[1] != v8 )
      __fastfail(3u);
    v74 = v9;
    v9[1] = (int)&v74;
    PiDevCfgFreeDeviceMigrationNode(v8, v9);
  }
  RtlFreeAnsiString(&v83);
  RtlFreeAnsiString(&v93);
  RtlFreeAnsiString(&v97);
  RtlFreeAnsiString(&v87);
  return v7;
}
