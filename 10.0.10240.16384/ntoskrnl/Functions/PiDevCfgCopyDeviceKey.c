// PiDevCfgCopyDeviceKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiDevCfgCopyDeviceKey(int a1, int a2, int a3, int a4, char a5, int a6, int a7)
{
  int v7; // r6
  int v8; // r5
  unsigned int v9; // r5
  unsigned int v10; // r3
  int v11; // r7
  unsigned int v13; // r8
  int v14; // r9
  int v15; // r0
  int v16; // r5
  int v17; // r7
  unsigned __int16 *v18; // r8
  int v19; // r3
  int v20; // r4
  int v21; // r8
  char v22; // r10
  int v23; // r0
  unsigned __int16 *v24; // r9
  int v25; // r5
  int v26; // r7
  int v27; // r8
  unsigned int v28; // r8
  __int64 v29; // r2
  unsigned int v30; // r8
  unsigned __int16 *v31; // r7
  unsigned int v32; // r10
  unsigned int v33; // r9
  int v34; // r3
  unsigned int v35; // r4
  int v36; // r7
  int v37; // r4
  unsigned __int16 *j; // r4
  unsigned __int16 *v39; // r4
  int v40; // r0
  unsigned __int16 *k; // r4
  unsigned int v42; // r6
  int v43; // r0
  int v44; // r3
  int v45; // r3
  unsigned int v46; // r3
  int v47; // r5
  int v48; // r6
  unsigned __int16 *v49; // r0
  unsigned __int16 *v50; // r4
  int v51; // r5
  int *v52; // r0
  int v53; // r2
  int v55; // r3
  unsigned __int16 *v56; // r0
  int v57; // r2
  int v59; // r3
  int v60; // r0
  int v61; // r3
  int v62; // r3
  int v64; // r3
  int v65; // r3
  unsigned __int16 *v66; // r2 OVERLAPPED
  unsigned int v67; // r1 OVERLAPPED
  unsigned int v68; // r3
  unsigned int v69; // r0
  int v70; // r8
  unsigned int v71; // r6
  int v72; // r0
  int *v73; // r4
  int **v74; // r2
  unsigned int v75; // r3
  int v76; // r0
  int v77; // r2
  int v78; // r3
  int v79; // r4
  int v80; // r0
  unsigned __int16 *i; // r4
  int v82; // r3
  int v83; // r3
  unsigned __int16 *v84; // r4
  int v85; // r0
  unsigned int v86; // r3
  unsigned int v87; // r4
  int v88; // r0
  int v89; // r0
  int v90; // r3
  int v91; // r1 OVERLAPPED
  int *v92; // r2 OVERLAPPED
  int v93; // r0
  int v94; // r3
  int v95; // r1 OVERLAPPED
  int *v96; // r2 OVERLAPPED
  int *v97; // [sp+4h] [bp-15Ch]
  int v99; // [sp+2Ch] [bp-134h]
  unsigned int v100; // [sp+34h] [bp-12Ch] BYREF
  int v101; // [sp+38h] [bp-128h]
  int v102; // [sp+3Ch] [bp-124h]
  int v103; // [sp+40h] [bp-120h]
  unsigned int v104; // [sp+44h] [bp-11Ch] BYREF
  unsigned int *v105; // [sp+48h] [bp-118h] BYREF
  unsigned int v106; // [sp+4Ch] [bp-114h] BYREF
  int v107; // [sp+50h] [bp-110h]
  int v108; // [sp+58h] [bp-108h]
  unsigned __int16 *v109; // [sp+5Ch] [bp-104h]
  int v110; // [sp+60h] [bp-100h] BYREF
  unsigned __int16 *v111; // [sp+64h] [bp-FCh]
  int v112; // [sp+68h] [bp-F8h]
  int v113; // [sp+6Ch] [bp-F4h]
  unsigned __int16 *v114; // [sp+70h] [bp-F0h]
  int v115; // [sp+74h] [bp-ECh]
  unsigned __int16 *v116; // [sp+78h] [bp-E8h]
  int v117; // [sp+7Ch] [bp-E4h] BYREF
  int v118; // [sp+80h] [bp-E0h]
  unsigned int v119; // [sp+84h] [bp-DCh]
  int v120; // [sp+88h] [bp-D8h]
  unsigned int v121; // [sp+8Ch] [bp-D4h] BYREF
  int v122; // [sp+90h] [bp-D0h]
  int v123; // [sp+94h] [bp-CCh]
  int *v124; // [sp+98h] [bp-C8h]
  int v125; // [sp+9Ch] [bp-C4h]
  unsigned int v126; // [sp+A0h] [bp-C0h]
  int v127; // [sp+A4h] [bp-BCh]
  int v128; // [sp+A8h] [bp-B8h] BYREF
  unsigned __int16 *v129; // [sp+ACh] [bp-B4h]
  int v130; // [sp+B0h] [bp-B0h] BYREF
  unsigned __int16 *v131; // [sp+B4h] [bp-ACh]
  int v132; // [sp+B8h] [bp-A8h] BYREF
  int v133; // [sp+BCh] [bp-A4h]
  int v134; // [sp+C0h] [bp-A0h]
  int v135; // [sp+C4h] [bp-9Ch] BYREF
  int v136; // [sp+C8h] [bp-98h]
  int v137; // [sp+CCh] [bp-94h]
  int v138; // [sp+D0h] [bp-90h]
  unsigned __int16 *v139; // [sp+D4h] [bp-8Ch] BYREF
  int v140; // [sp+D8h] [bp-88h]
  unsigned __int16 *v141[3]; // [sp+DCh] [bp-84h] BYREF
  unsigned __int16 v142[2]; // [sp+E8h] [bp-78h] BYREF
  unsigned __int16 *v143; // [sp+ECh] [bp-74h]
  int v144; // [sp+F0h] [bp-70h] BYREF
  unsigned __int16 *v145; // [sp+F4h] [bp-6Ch]
  char v146; // [sp+F8h] [bp-68h] BYREF
  char v147[16]; // [sp+100h] [bp-60h] BYREF
  unsigned int v148; // [sp+110h] [bp-50h]
  int v149; // [sp+128h] [bp-38h] BYREF
  unsigned __int16 *v150; // [sp+12Ch] [bp-34h] BYREF
  int *v151; // [sp+130h] [bp-30h]
  int v152; // [sp+134h] [bp-2Ch]
  int v153; // [sp+138h] [bp-28h]
  int v154; // [sp+13Ch] [bp-24h]

  v140 = a4;
  v101 = a1;
  v120 = a6;
  v7 = a3;
  v118 = a7;
  v112 = a3;
  v107 = 0;
  v117 = 0;
  v119 = 1;
  v8 = IopGetRegistryKeyInformation(a1, &v121);
  if ( v8 < 0 )
    return v8;
  v9 = 2 * (*(_DWORD *)(v121 + 24) + 13);
  v10 = 2 * (*(_DWORD *)(v121 + 36) + 9);
  v104 = v10;
  if ( v10 > v9 )
    v9 = v10;
  ExFreePoolWithTag(v121);
  v11 = ExAllocatePoolWithTag(1, v9, 1667526736);
  v99 = v11;
  if ( v11 )
  {
    v121 = -2147483622;
    v136 = -2147483643;
    v115 = 0x20000;
    v133 = 0x40000;
    v134 = 0x80000;
    v102 = 0x200000;
    v20 = 0;
    v21 = 0x400000;
    v22 = a5;
    v137 = 0x40000000;
    v138 = 131097;
    v113 = 0x400000;
    while ( 1 )
    {
      v97 = (int *)&v104;
      v103 = v20;
      v23 = ZwEnumerateValueKey();
      if ( v23 < 0 )
      {
        if ( v23 != v121 )
          return sub_7E4A50();
        v8 = 0;
        if ( v7 )
        {
LABEL_69:
          v13 = 0;
          goto LABEL_15;
        }
        v13 = 0;
        if ( !v120 )
        {
LABEL_15:
          if ( v99 )
            ExFreePoolWithTag(v99);
          goto LABEL_17;
        }
        v14 = 0;
        while ( 2 )
        {
          v15 = ZwEnumerateKey();
          v8 = v15;
          if ( v15 < 0 )
          {
            if ( v15 == v121 )
            {
              v8 = 0;
              goto LABEL_15;
            }
            if ( v15 != v136 )
              goto LABEL_15;
            ExFreePoolWithTag(v99);
            v99 = ExAllocatePoolWithTag(1, v104, 1667526736);
            if ( v99 )
            {
              --v14;
              goto LABEL_31;
            }
            v8 = -1073741670;
LABEL_17:
            if ( v13 )
              ExFreePoolWithTag(v13);
            return v8;
          }
          *(_WORD *)(v99 + 2 * (*(_DWORD *)(v99 + 12) >> 1) + 16) = 0;
          v8 = RtlInitUnicodeStringEx((int)&v130, (unsigned __int16 *)(v99 + 16));
          if ( v8 < 0 )
            goto LABEL_15;
          v110 = v130;
          v124 = &v130;
          v125 = 576;
          v111 = v131;
          v122 = 24;
          v123 = v101;
          v126 = 0;
          v127 = 0;
          v8 = ZwOpenKey();
          if ( v8 < 0 )
            goto LABEL_15;
          v16 = v118;
          v17 = 0;
          v18 = 0;
          if ( v118 && *(_DWORD *)(v118 + 8) )
          {
            i = 0;
            v17 = 0;
            if ( *v131 == 36 )
            {
              for ( i = v131 + 1; ; ++i )
              {
                v83 = *i;
                if ( !*i )
                  break;
                if ( v83 == 63 )
                {
                  v17 |= 0x10000u;
                }
                else
                {
                  switch ( v83 )
                  {
                    case '!':
                      v82 = v115;
                      break;
                    case '+':
                      v82 = v133;
                      break;
                    case '-':
                      v82 = v134;
                      break;
                    default:
                      if ( *i == 36 )
                        ++i;
                      goto LABEL_247;
                  }
                  v17 |= v82;
                }
              }
            }
LABEL_247:
            RtlInitUnicodeString((unsigned int)&v128, i);
            if ( i )
            {
              v84 = v129;
              v105 = 0;
              v85 = PiDevCfgResolveVariable(v16, v129, &v105);
              if ( v85 < 0 )
              {
                if ( v85 != -1073741772 )
                {
LABEL_253:
                  ZwClose();
                  v13 = v107;
                  goto LABEL_31;
                }
                v110 = v128;
                v111 = v84;
              }
              else
              {
                v86 = v105[4];
                if ( v86 == 1 || v86 == 2 )
                {
                  v111 = (unsigned __int16 *)v105[6];
                  LOWORD(v110) = v105[5] - 2;
                  HIWORD(v110) = v105[5];
                }
                else
                {
                  if ( v86 != 7 )
                    goto LABEL_253;
                  v18 = (unsigned __int16 *)v105[6];
                }
              }
            }
          }
          v8 = PiDevCfgGetKeySecurityDescriptor(0, &v117);
          if ( v8 >= 0 )
          {
            v19 = v117;
          }
          else
          {
            v8 = 0;
            v19 = 0;
            v117 = 0;
          }
          v107 = v19;
          if ( !v18 )
          {
            v122 = 24;
            v125 = 576;
            v126 = v19;
            v123 = a2;
            v124 = &v110;
            v127 = 0;
            v8 = ZwCreateKey();
            if ( v8 >= 0 )
            {
              if ( v141[1] == (unsigned __int16 *)2 && v107 )
                ZwSetSecurityObject();
              v93 = ExAllocatePoolWithTag(1, 20, 1667526736);
              if ( v93 )
              {
                v94 = v137;
                v95 = v120;
                *(_DWORD *)(v93 + 8) = 0;
                *(_DWORD *)(v93 + 12) = 0;
                *(_DWORD *)(v93 + 16) = v94;
                v96 = *(int **)(v95 + 4);
                *(_QWORD *)v93 = *(_QWORD *)&v95;
                if ( *v96 != v95 )
                  __fastfail(3u);
                *v96 = v93;
                *(_DWORD *)(v95 + 4) = v93;
                v8 = 0;
              }
              else
              {
                v8 = -1073741670;
                ZwClose();
              }
            }
            goto LABEL_28;
          }
          if ( !*v18 )
            goto LABEL_28;
LABEL_259:
          RtlInitUnicodeString((unsigned int)&v110, v18);
          v122 = 24;
          v87 = v107;
          v123 = a2;
          v124 = &v110;
          v125 = 576;
          v126 = v107;
          v127 = 0;
          v88 = ZwOpenKey();
          v8 = v88;
          if ( v88 >= 0 )
          {
            if ( v87 )
              ZwSetSecurityObject();
            goto LABEL_266;
          }
          if ( v88 != -1073741772 )
            goto LABEL_28;
          if ( (v17 & 0x10000) != 0 )
          {
            v8 = 0;
          }
          else
          {
            v8 = ZwCreateKey();
            if ( v8 < 0 )
              goto LABEL_28;
LABEL_266:
            v122 = 24;
            v123 = v101;
            v124 = &v130;
            v125 = 576;
            v126 = 0;
            v127 = 0;
            v8 = ZwOpenKey();
            if ( v8 < 0 )
              goto LABEL_273;
            v89 = ExAllocatePoolWithTag(1, 20, 1667526736);
            if ( !v89 )
            {
              v8 = -1073741670;
LABEL_273:
              ZwClose();
LABEL_28:
              v13 = v107;
              if ( v107 )
              {
                ExFreePoolWithTag(v107);
                v13 = 0;
                v107 = 0;
                v117 = 0;
              }
              if ( v8 < 0 )
                goto LABEL_15;
LABEL_31:
              ++v14;
              continue;
            }
            v90 = v137;
            v91 = v120;
            *(_QWORD *)(v89 + 8) = 0i64;
            *(_DWORD *)(v89 + 16) = v90;
            v92 = *(int **)(v91 + 4);
            *(_QWORD *)v89 = *(_QWORD *)&v91;
            if ( *v92 != v91 )
              __fastfail(3u);
            *v92 = v89;
            *(_DWORD *)(v91 + 4) = v89;
            v8 = 0;
          }
          break;
        }
        v18 += wcslen(v18) + 1;
        if ( !*v18 )
          goto LABEL_28;
        goto LABEL_259;
      }
      *(_WORD *)(v11 + 2 * (*(_DWORD *)(v11 + 8) >> 1) + 12) = 0;
      v8 = RtlInitUnicodeStringEx((int)&v144, (unsigned __int16 *)(v11 + 12));
      if ( v8 < 0 )
        goto LABEL_69;
      v24 = v145;
      v25 = v118;
      v26 = 0;
      v108 = v144;
      v109 = v145;
      if ( !v118 || !*(_DWORD *)(v118 + 8) )
        goto LABEL_37;
      j = 0;
      v26 = 0;
      if ( *v145 == 36 )
      {
        for ( j = v145 + 1; ; ++j )
        {
          v45 = *j;
          if ( !*j )
            break;
          if ( v45 == 63 )
          {
            v26 |= 0x10000u;
          }
          else
          {
            switch ( v45 )
            {
              case '!':
                v44 = v115;
                break;
              case '+':
                v44 = v133;
                break;
              case '-':
                v44 = v134;
                break;
              default:
                if ( *j == 36 )
                  ++j;
                goto LABEL_74;
            }
            v26 |= v44;
          }
        }
      }
LABEL_74:
      RtlInitUnicodeString((unsigned int)&v128, j);
      if ( !j )
        goto LABEL_79;
      if ( (v26 & v21) != 0 )
        goto LABEL_86;
      v39 = v129;
      v105 = 0;
      v40 = PiDevCfgResolveVariable(v25, v129, &v105);
      if ( v40 < 0 )
        break;
      v46 = v105[4];
      if ( v46 != 1 && v46 != 2 )
        goto LABEL_86;
      v20 = v103;
      if ( v105[5] <= 0xFFFE )
      {
        v109 = (unsigned __int16 *)v105[6];
        LOWORD(v108) = v105[5] - 2;
        HIWORD(v108) = v105[5];
        goto LABEL_37;
      }
LABEL_63:
      v11 = v99;
      ++v20;
    }
    if ( v40 == -1073741772 )
    {
      v108 = v128;
      v109 = v39;
LABEL_79:
      v20 = v103;
LABEL_37:
      v27 = *(_DWORD *)(v99 + 4);
      *(_WORD *)(v99 + 6) = 0;
      v28 = v27 & 0xFFFF0000;
      if ( (v28 & v113) != 0 )
        goto LABEL_62;
      if ( !v7 )
        goto LABEL_40;
      if ( (unsigned __int16)v108 < 0x50u )
        goto LABEL_138;
      v143 = v109;
      v142[0] = 76;
      v142[1] = HIWORD(v108);
      if ( RtlGUIDFromString(v142, v147) < 0 )
        goto LABEL_138;
      if ( v109[38] != 44 )
        goto LABEL_138;
      v47 = (int)(v109 + 39);
      v48 = ((unsigned __int16)v108 >> 1) - 39;
      if ( v109[v48 + 39] )
        goto LABEL_138;
      v49 = wcschr(v109 + 39, 44);
      v50 = v49;
      if ( v49 )
      {
        v48 = ((int)v49 - v47) >> 1;
        v50 = v49 + 1;
      }
      v51 = RtlStringCchCopyNW(&v149, 0xBu, v47, v48);
      if ( v51 < 0 )
        goto LABEL_138;
      if ( (unsigned __int16)v149 == 48 && (HIWORD(v149) == 120 || HIWORD(v149) == 88) )
      {
        v52 = (int *)&v150;
        v53 = 16;
      }
      else
      {
        v52 = &v149;
        v53 = 10;
      }
      v148 = wcstoul((unsigned __int16 *)v52, v141, v53);
      if ( !v141[0] || *v141[0] )
        goto LABEL_138;
      v119 = 1;
      if ( v50 )
      {
        if ( *v50 == 48 && ((v55 = v50[1], v55 == 120) || v55 == 88) )
        {
          v56 = v50 + 2;
          v57 = 16;
        }
        else
        {
          v57 = 10;
          v56 = v50;
        }
        v119 = wcstoul(v56, &v139, v57);
        if ( !v139 || *v139 )
          v51 = -1073741823;
      }
      if ( v51 >= 0 )
        v59 = 1;
      else
LABEL_138:
        v59 = 0;
      v7 = v112;
      if ( v59 )
      {
LABEL_40:
        if ( (v22 & 1) != 0 && ((v28 | v26) & 0x30000) == 0 )
        {
LABEL_41:
          v100 = 0;
          v116 = 0;
          v114 = 0;
          v8 = IopGetRegistryValue(v101, v24, 0, (int *)&v100);
          if ( v8 < 0 )
            goto LABEL_69;
          v29 = *(_QWORD *)(v100 + 4);
          v30 = *(_DWORD *)(v100 + 12);
          v31 = (unsigned __int16 *)(HIDWORD(v29) + v100);
          v32 = *(_DWORD *)(v100 + 4) & 0xFFFF0000;
          v33 = (unsigned __int16)v29;
          if ( !v118 || !*(_DWORD *)(v118 + 8) || (unsigned __int16)v29 != 1 && (unsigned __int16)v29 != 2 )
            goto LABEL_285;
          if ( v30 < 2 || v31[(v30 >> 1) - 1] )
            goto LABEL_285;
          k = 0;
          v42 = 0;
          if ( *v31 == 36 )
          {
            for ( k = v31 + 1; ; ++k )
            {
              v65 = *k;
              if ( !*k )
                break;
              if ( v65 == 63 )
              {
                v42 |= 0x10000u;
              }
              else
              {
                switch ( v65 )
                {
                  case '!':
                    v64 = v115;
                    break;
                  case '+':
                    v64 = v133;
                    break;
                  case '-':
                    v64 = v134;
                    break;
                  default:
                    if ( *k == 36 )
                      ++k;
                    goto LABEL_81;
                }
                v42 |= v64;
              }
            }
          }
LABEL_81:
          RtlInitUnicodeString((unsigned int)&v128, k);
          if ( k )
          {
            v31 = v129;
            v105 = 0;
            v43 = PiDevCfgResolveVariable(v118, v129, &v105);
            v8 = v43;
            v37 = a2;
            if ( v43 < 0 )
            {
              v34 = v102;
              if ( v43 == -1073741772 )
                v30 = HIWORD(v128);
              else
                v31 = 0;
              v8 = 0;
              goto LABEL_48;
            }
            if ( (v42 & 0xC0000) == 0 )
            {
              v30 = v105[5];
              v31 = (unsigned __int16 *)v105[6];
              v32 |= v105[4] & 0xFFFF0000;
              v33 = (unsigned __int16)*((_QWORD *)v105 + 2);
              goto LABEL_47;
            }
            v68 = v42;
            v97 = (int *)v109;
            *(_QWORD *)&v67 = *(_QWORD *)(v105 + 5);
            v69 = v105[4];
LABEL_179:
            v8 = PiDevCfgResolveMultiSzValue(v69, v67, v66, v68, v37);
            v116 = v114;
            if ( v8 < 0 )
            {
              v31 = 0;
              v8 = 0;
            }
            else
            {
              v30 = v104;
              v33 = 7;
              v31 = v114;
              if ( v104 >= 2 )
              {
                v34 = v102;
                if ( !*v114 )
                  v32 |= v102;
LABEL_48:
                if ( v31 )
                {
                  if ( v33 == 0x8000 )
                  {
                    v7 = v112;
                    if ( v112 )
                      goto LABEL_190;
                    v70 = v120;
                    if ( !v120 )
                      goto LABEL_190;
                    v71 = 0x80000000;
                    if ( (v32 & v115) == 0 )
                      v71 = -2147483647;
                    v72 = ExAllocatePoolWithTag(1, 20, 1667526736);
                    v73 = (int *)v72;
                    if ( v72 )
                    {
                      *(_DWORD *)(v72 + 16) = v71;
                      v149 = 24;
                      v150 = v31;
                      v151 = &PiDevCfgEmptyString;
                      v152 = 512;
                      v153 = 0;
                      v154 = 0;
                      v8 = ZwOpenKey();
                      if ( v8 >= 0 )
                      {
                        v149 = 24;
                        v150 = (unsigned __int16 *)a2;
                        v151 = &PiDevCfgEmptyString;
                        v153 = 0;
                        v154 = 0;
                        v152 = 512;
                        v8 = ZwOpenKey();
                        if ( v8 >= 0 )
                        {
                          v73[4] |= v137;
                          v74 = *(int ***)(v70 + 4);
                          *v73 = v70;
                          v73[1] = (int)v74;
                          if ( *v74 != (int *)v70 )
                            __fastfail(3u);
                          *v74 = v73;
                          *(_DWORD *)(v70 + 4) = v73;
                          v73 = 0;
                        }
                        else
                        {
                          ZwClose();
                        }
                      }
                      if ( v73 )
                        ExFreePoolWithTag((unsigned int)v73);
                    }
                    else
                    {
                      v8 = -1073741670;
                    }
                  }
                  else if ( v33 || (v32 & 0x100000) == 0 )
                  {
                    v7 = v112;
                    if ( !v112 )
                    {
                      if ( (v32 & v34) == 0 )
                      {
                        v35 = v100;
                        v36 = a2;
                        v8 = ZwSetValueKey();
                        goto LABEL_54;
                      }
                      v8 = ZwDeleteValueKey();
                      if ( v8 == -1073741772 )
                        v8 = 0;
LABEL_190:
                      v35 = v100;
                      v36 = a2;
LABEL_54:
                      if ( v116 )
                        ExFreePoolWithTag((unsigned int)v116);
                      if ( !v7 && v33 != 0x8000 && (v32 & 0x100000) != 0 )
                        PnpCtxRegDeleteTree(PiPnpRtlCtx, v36, v109);
                      ExFreePoolWithTag(v35);
                      if ( v8 < 0 )
                        goto LABEL_69;
                      v20 = v103;
                      v22 = a5;
LABEL_62:
                      v21 = v113;
                      goto LABEL_63;
                    }
                    if ( (v32 & v34) != 0 )
                    {
                      v78 = 0;
                      v77 = 0;
                      v79 = 0;
                      v135 = 0;
                      v106 = 0;
                      v132 = 0;
                    }
                    else
                    {
                      if ( v119 == 1 )
                      {
                        if ( !v33 )
                          goto LABEL_211;
                        if ( v33 <= 2 )
                        {
                          v75 = 18;
                        }
                        else
                        {
                          switch ( v33 )
                          {
                            case 4u:
                              v75 = 7;
                              break;
                            case 7u:
                              v75 = 8210;
                              break;
                            case 0xBu:
                              v75 = 9;
                              break;
                            default:
LABEL_211:
                              v75 = 4099;
                              break;
                          }
                        }
                        v106 = v75;
                      }
                      else
                      {
                        v106 = v119;
                      }
                      v97 = &v135;
                      v76 = PiDevCfgConvertPropertyFromValue(v33, v30, v31);
                      v77 = v132;
                      v78 = v106;
                      v79 = v135;
                      v8 = v76;
                    }
                    if ( v8 >= 0 && (v79 || !v78) )
                    {
                      v80 = PiDevCfgSetObjectProperty(PiPnpRtlCtx, 0, v7, v140, a2, (int)v97, (int)v147, v78, v79, v77);
                      v8 = v80;
                      if ( !v106 && v80 == -1073741275 )
                        v8 = 0;
                      if ( v79 )
                      {
                        if ( (unsigned __int16 *)v79 != v31 )
                          ExFreePoolWithTag(v79);
                        v135 = 0;
                      }
                    }
                    goto LABEL_190;
                  }
                }
                v7 = v112;
                goto LABEL_190;
              }
            }
          }
          else
          {
LABEL_285:
            if ( v33 == 1 || v33 == 7 || v33 == 2 )
            {
              v37 = a2;
              if ( (v32 & 0xC0000) != 0 )
              {
                v66 = v31;
                v67 = v30;
                v97 = (int *)v109;
                v68 = v32;
                v69 = v33;
                goto LABEL_179;
              }
            }
          }
LABEL_47:
          v34 = v102;
          goto LABEL_48;
        }
        if ( v7 )
        {
          v60 = PnpGetObjectProperty(PiPnpRtlCtx, v7, v140, a2, 0, (int)v147, (int)&v106, 0, 0, (int)&v132, 0);
          v61 = -1073741789;
          goto LABEL_144;
        }
        v97 = (int *)&v146;
        v60 = ZwQueryValueKey();
        if ( v60 >= 0 )
          goto LABEL_147;
        v61 = v136;
LABEL_144:
        if ( v60 == v61 )
LABEL_147:
          v62 = 1;
        else
          v62 = 0;
        if ( v62 )
        {
          if ( (v22 & 1) != 0 && ((v28 | v26) & v115) == 0 )
            goto LABEL_41;
        }
        else if ( ((v28 | v26) & 0x10000) == 0 )
        {
          goto LABEL_41;
        }
      }
      v20 = v103;
      goto LABEL_62;
    }
LABEL_86:
    v20 = v103;
    goto LABEL_63;
  }
  return -1073741670;
}
