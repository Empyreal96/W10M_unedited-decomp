// CcPrepareDelayedFlushTimers 
 
void CcPrepareDelayedFlushTimers()
{
  __int64 v0; // r0
  char v1; // r3
  __int64 v2; // r0
  char v3; // r3
  __int64 v4; // r0
  char v5; // r3
  __int64 v6; // r0
  char v7; // r3
  __int64 v8; // r0
  char v9; // r3
  char v10; // r3
  __int64 v11; // r0
  char v12; // r3
  __int64 v13; // r0
  char v14; // r3
  __int64 v15; // r0
  char v16; // r3
  _BYTE *v17; // r0
  int v18; // r8
  unsigned int v19; // r3
  unsigned int v20; // r6
  int v21; // r3
  __int64 v22; // kr00_8
  __int64 v23; // kr08_8
  unsigned int v24; // r1
  int v25; // r3
  unsigned __int64 v26; // r2
  unsigned __int64 v27; // r2
  void *v28; // r3
  int v29; // r5
  int v30; // r3
  int *v31; // r0
  __int64 v32; // kr30_8
  int *v33; // r4
  unsigned int v34; // r3
  char *v35; // r6
  unsigned int v36; // r2
  int v37; // t1
  unsigned int v38; // r3
  int v39; // r4
  unsigned int v40; // r3
  unsigned int v41; // r5
  int v42; // r3
  __int64 v43; // kr38_8
  __int64 v44; // kr40_8
  unsigned int v45; // r1
  int v46; // r3
  unsigned __int64 v47; // r2
  unsigned __int64 v48; // r2
  unsigned int v49; // r3
  unsigned int v50; // r5
  int v51; // r3
  __int64 v52; // kr58_8
  __int64 v53; // kr60_8
  unsigned int v54; // r1
  int v55; // r3
  unsigned __int64 v56; // r2
  __int64 v57; // r0
  int v58; // r2
  int v59; // r3
  char v60; // r2
  __int64 v61; // r0
  int v62; // r3
  int v63; // r3
  __int64 v64; // r0
  __int64 v65; // r0
  __int64 v66; // r0
  __int64 v67; // r0
  __int64 v68; // r0
  int v69; // r3
  __int64 v70; // r0
  __int64 v71; // r0
  __int64 v72; // r0
  unsigned int v73; // r3
  unsigned int v74; // r5
  __int64 v75; // kr78_8
  unsigned __int64 v76; // r2
  unsigned int v77; // r4
  __int64 v78; // r0
  int v79; // r7
  __int64 v80; // r0
  int v81; // r6
  __int64 v82; // r0
  int v83; // r0
  int v84; // r8
  unsigned int v85; // r3
  unsigned int v86; // r6
  int v87; // r3
  __int64 v88; // kr88_8
  int v89; // r5
  unsigned int v90; // r2
  unsigned int v91; // r3
  unsigned int v92; // r3
  unsigned int v93; // r5
  int v94; // r3
  __int64 v95; // krA8_8
  __int64 v96; // krB0_8
  unsigned int v97; // r1
  int v98; // r3
  unsigned __int64 v99; // r2
  int v100; // r7
  unsigned int v101; // r5
  __int64 v102; // krC8_8
  int v103; // r4
  unsigned int v104; // r1
  unsigned __int64 v105; // r2
  int v106; // r2
  char *v107; // lr
  int v108; // r2
  unsigned int v109; // r3
  _DWORD *v110; // r6
  int v111; // r3
  char v112; // r4
  unsigned int v113; // r9
  __int64 v114; // r0
  char *v115; // r3
  char v116; // r3
  unsigned int v117; // r10
  char v118; // r7
  char v119; // lr
  char v120; // r8
  char v121; // r4
  unsigned int v122; // r9
  unsigned int v123; // r5
  int v124; // r3
  unsigned int v125; // r1
  int v126; // r0
  char v127; // r7
  char v128; // r10
  unsigned int v129; // lr
  char v130; // r9
  char v131; // r8
  unsigned int v132; // t1
  __int64 v133; // r2
  char *i; // r3
  unsigned int v135; // r6
  unsigned int v136; // r3
  unsigned int v137; // r4
  int v138; // r3
  unsigned int v139; // r3
  unsigned int v140; // r5
  int v141; // r3
  __int64 v142; // krE8_8
  __int64 v143; // krF0_8
  unsigned int v144; // r1
  int v145; // r3
  unsigned __int64 v146; // r2
  __int64 v147; // kr108_8
  unsigned int v148; // r3
  unsigned int v149; // r5
  int v150; // r3
  __int64 v151; // kr110_8
  unsigned int v152; // r0
  unsigned int v153; // r1
  unsigned int v154; // r4
  unsigned __int64 v155; // r2
  __int64 v156; // r0
  __int64 v157; // r0
  int v158; // r0
  unsigned int v159; // [sp+4h] [bp-A4h]
  int v160; // [sp+10h] [bp-98h]
  unsigned int v161; // [sp+14h] [bp-94h]
  char v162; // [sp+18h] [bp-90h]
  char *v163; // [sp+1Ch] [bp-8Ch]
  unsigned int v164; // [sp+1Ch] [bp-8Ch]
  char v165; // [sp+20h] [bp-88h]
  char *v166; // [sp+24h] [bp-84h]
  char *v167; // [sp+24h] [bp-84h]
  char v168[12]; // [sp+68h] [bp-40h] BYREF
  int v169; // [sp+74h] [bp-34h]
  int v170; // [sp+7Ch] [bp-2Ch]
  unsigned int v171; // [sp+80h] [bp-28h] BYREF
  int v172[9]; // [sp+84h] [bp-24h] BYREF

  if ( (MEMORY[0xFFFF92D4] & 0xFE) == 0 )
  {
    v0 = FsRtlRemovePerStreamContextEx(3i64, 0x353Bui64);
    if ( v0 )
      v1 = v0 == 1 ? (unsigned __int8)__ROR4__(2656, 5) : (unsigned __int8)__ROR4__(-1744830462, 27);
    else
      v1 = __ROR4__(696254464, 23);
    v168[0] = v1;
    v2 = FsRtlRemovePerStreamContextEx(3i64, 0x353Cui64);
    if ( v2 )
      v3 = v2 == 1 ? (unsigned __int8)__ROR4__(1040, 4) : (unsigned __int8)__ROR4__(268435460, 28);
    else
      v3 = __ROR4__(67108865, 26);
    v168[1] = v3;
    v4 = FsRtlRemovePerStreamContextEx(3i64, 0x353Dui64);
    if ( v4 && v4 == 1 )
      v5 = __ROR4__(560, 3);
    else
      v5 = __ROR4__(-1073741816, 29);
    v168[2] = v5;
    v6 = FsRtlRemovePerStreamContextEx(3i64, 0x353Eui64);
    if ( v6 )
      v7 = v6 == 1 ? (unsigned __int8)__ROR4__(276, 2) : (unsigned __int8)__ROR4__(1073741841, 30);
    else
      v7 = 69;
    v168[3] = v7;
    v8 = FsRtlRemovePerStreamContextEx(3i64, 0x353Fui64);
    if ( v8 )
      v9 = v8 == 1 ? (unsigned __int8)__ROR4__(132, 1) : (unsigned __int8)__ROR4__(33, 31);
    else
      v9 = __ROR4__(528, 3);
    v168[4] = v9;
    v10 = FsRtlRemovePerStreamContextEx(3i64, 0x3540ui64) ? 79 : (unsigned __int8)__ROR4__(5056, 6);
    v168[5] = v10;
    v11 = FsRtlRemovePerStreamContextEx(3i64, 0x3541ui64);
    if ( v11 )
      v12 = v11 == 1 ? (unsigned __int8)__ROR4__(-2147483609, 31) : (unsigned __int8)__ROR4__(158, 1);
    else
      v12 = __ROR4__(40448, 9);
    v168[6] = v12;
    v13 = FsRtlRemovePerStreamContextEx(3i64, 0x3542ui64);
    if ( v13 )
      v14 = v13 == 1 ? (unsigned __int8)__ROR4__(21, 30) : (unsigned __int8)__ROR4__(336, 2);
    else
      v14 = __ROR4__(344064, 12);
    v168[7] = v14;
    v15 = FsRtlRemovePerStreamContextEx(3i64, 0x3543ui64);
    if ( v15 )
      v16 = v15 == 1 ? (unsigned __int8)__ROR4__(1073741831, 29) : (unsigned __int8)__ROR4__(464, 3);
    else
      v16 = __ROR4__(1900544, 15);
    v168[8] = v16;
    v168[9] = 0;
    v17 = (_BYTE *)KiGetLoadOptions();
    if ( !strstr(v17, v168) )
    {
      v18 = RtlImageNtHeader(0x400000);
      v19 = __mrc(15, 0, 9, 13, 0);
      v20 = v19 << 29;
      v21 = v19 ^ (v19 >> 3);
      v22 = 67117057i64 * (unsigned int)v21;
      v23 = 67117057i64 * v20 + 1880096896i64 * (unsigned int)v21;
      v24 = (1880096896i64 * v20 + (unsigned __int64)HIDWORD(v23)) >> 32;
      v25 = 1880096896 * v20 + HIDWORD(v23);
      if ( (unsigned int)(v23 + HIDWORD(v22)) < HIDWORD(v22) )
        v24 = (__PAIR64__(v24, v25++) + 1) >> 32;
      LODWORD(v26) = v22 ^ v25;
      HIDWORD(v26) = (v23 + HIDWORD(v22)) ^ v24;
      _rt_udiv64(100i64, v26);
      if ( v27 >= 0x32 )
      {
        v169 = 1;
        v28 = sub_6A2000;
      }
      else
      {
        v28 = CcDelayedFlushTimer;
        v169 = 0;
      }
      v29 = RtlSectionTableFromVirtualAddress(v18, 0x400000, (unsigned int)v28 - 0x400000);
      v31 = (int *)RtlLookupFunctionTable(v29, v172, &v171, v30);
      if ( !v31 || v171 < 8 )
      {
        v39 = -1073741701;
LABEL_161:
        v157 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
        if ( v157 )
        {
          if ( v157 == 1 )
            v158 = __ROR4__(-2147483490, 31);
          else
            v158 = __ROR4__(634, 1);
        }
        else
        {
          v158 = __ROR4__(162304, 9);
        }
        KeBugCheckEx(v158, 6, v29, v39, 0);
      }
      v32 = *(_QWORD *)(v29 + 8);
      v33 = &v31[2 * (v171 >> 3)];
      v34 = *(_DWORD *)(v29 + 16);
      v35 = 0;
      if ( v34 <= (unsigned int)v32 )
        v34 = *(_DWORD *)(v29 + 8);
      v36 = v34 + HIDWORD(v32);
      v163 = 0;
      do
      {
        v37 = *v31;
        v31 += 2;
        v38 = v37 & 0xFFFFFFFE;
        if ( (v37 & 0xFFFFFFFE) >= HIDWORD(v32) )
        {
          if ( v38 >= v36 )
            break;
          if ( !v35 )
            v35 = (char *)(v31 - 2);
          v163 = (char *)(v31 - 2);
        }
      }
      while ( v38 < v36 && v31 != v33 );
      v166 = v35;
      if ( !v35 )
      {
        v39 = -1073741569;
        goto LABEL_161;
      }
      v40 = __mrc(15, 0, 9, 13, 0);
      v41 = v40 << 29;
      v42 = v40 ^ (v40 >> 3);
      v43 = 67117057i64 * (unsigned int)v42;
      v44 = 1880096896i64 * (unsigned int)v42 + 67117057i64 * v41;
      v45 = (1880096896i64 * v41 + (unsigned __int64)HIDWORD(v44)) >> 32;
      v46 = 1880096896 * v41 + HIDWORD(v44);
      if ( (unsigned int)(v44 + HIDWORD(v43)) < HIDWORD(v43) )
        v45 = (__PAIR64__(v45, v46++) + 1) >> 32;
      LODWORD(v47) = v43 ^ v46;
      HIDWORD(v47) = (v44 + HIDWORD(v43)) ^ v45;
      _rt_udiv64(10i64, v47);
      if ( v48 < 5 )
      {
        v49 = __mrc(15, 0, 9, 13, 0);
        v50 = v49 << 29;
        v51 = v49 ^ (v49 >> 3);
        v52 = 67117057i64 * (unsigned int)v51;
        v53 = 1880096896i64 * (unsigned int)v51 + 67117057i64 * v50;
        v54 = (1880096896i64 * v50 + (unsigned __int64)HIDWORD(v53)) >> 32;
        v55 = 1880096896 * v50 + HIDWORD(v53);
        if ( (unsigned int)(v53 + HIDWORD(v52)) < HIDWORD(v52) )
          v54 = (__PAIR64__(v54, v55++) + 1) >> 32;
        LODWORD(v56) = v52 ^ v55;
        HIDWORD(v56) = (v53 + HIDWORD(v52)) ^ v54;
        v57 = FsRtlRemovePerStreamContextEx(11i64, v56);
        v170 = HIDWORD(v57);
        switch ( (int)v57 )
        {
          case 0:
            if ( !FsRtlRemovePerStreamContextEx(3i64, 0i64) )
            {
              v59 = -795291432;
              goto LABEL_73;
            }
            v58 = 1665295171;
            goto LABEL_128;
          case 1:
            v61 = FsRtlRemovePerStreamContextEx(3i64, 1ui64);
            if ( !v61 )
            {
              v63 = -1262057782;
              goto LABEL_80;
            }
            if ( v61 == 1 )
            {
              v60 = 31;
              v59 = -1297272415;
              goto LABEL_74;
            }
            v62 = -894122362;
            goto LABEL_124;
          case 2:
            v64 = FsRtlRemovePerStreamContextEx(3i64, 2ui64);
            if ( !v64 )
            {
              v58 = __ROR4__(-700172778, 12);
              goto LABEL_128;
            }
            if ( v64 == 1 )
            {
              v59 = -665102064;
              goto LABEL_118;
            }
            v60 = 2;
            v59 = -2051698419;
            goto LABEL_74;
          case 3:
            v65 = FsRtlRemovePerStreamContextEx(3i64, 3ui64);
            if ( !v65 )
            {
              v58 = __ROR4__(-1474152133, 15);
              goto LABEL_128;
            }
            if ( v65 == 1 )
            {
              v60 = 29;
              v59 = -1907430904;
            }
            else
            {
              v60 = 3;
              v59 = -1816493533;
            }
            goto LABEL_74;
          case 4:
            v66 = FsRtlRemovePerStreamContextEx(3i64, 4ui64);
            if ( !v66 )
            {
              v58 = __ROR4__(622445017, 18);
              goto LABEL_128;
            }
            if ( v66 == 1 )
            {
              v58 = __ROR4__(1728537748, 28);
              goto LABEL_128;
            }
            v60 = 4;
            v59 = 124032103;
            goto LABEL_74;
          case 5:
            v67 = FsRtlRemovePerStreamContextEx(3i64, 5ui64);
            if ( v67 )
            {
              if ( v67 == 1 )
              {
                v59 = 2068456210;
                goto LABEL_112;
              }
              v60 = 5;
              v59 = 680282605;
            }
            else
            {
              v60 = 21;
              v59 = 1240279180;
            }
            goto LABEL_74;
          case 6:
            v68 = FsRtlRemovePerStreamContextEx(3i64, 6ui64);
            if ( !v68 )
            {
              v69 = 1314342516;
              goto LABEL_106;
            }
            if ( v68 == 1 )
            {
              v58 = __ROR4__(962402769, 26);
              goto LABEL_128;
            }
            v59 = -778234987;
LABEL_73:
            v60 = 6;
            goto LABEL_74;
          case 7:
            v70 = FsRtlRemovePerStreamContextEx(3i64, 7ui64);
            if ( v70 )
            {
              if ( v70 == 1 )
                v58 = __ROR4__(-2100910376, 25);
              else
                v58 = __ROR4__(-1447681871, 7);
              goto LABEL_128;
            }
            v59 = 186293090;
LABEL_112:
            v60 = 27;
            goto LABEL_74;
          case 8:
            v71 = FsRtlRemovePerStreamContextEx(3i64, 8ui64);
            if ( v71 )
            {
              if ( v71 == 1 )
              {
                v69 = 1094870118;
LABEL_106:
                v58 = __ROR4__(v69, 24);
              }
              else
              {
                v58 = __ROR4__(1684422978, 8);
              }
            }
            else
            {
              v59 = 1352210832;
LABEL_118:
              v60 = 30;
LABEL_74:
              v58 = __ROR4__(v59, v60);
            }
LABEL_128:
            v83 = ExAllocatePoolWithTag(512, 136, v58);
            v84 = v83;
            v160 = v83;
            if ( v83 )
            {
              KeInitializeTimer(v83 + 32);
              *(_BYTE *)v84 = 19;
              *(_BYTE *)(v84 + 1) = 1;
              *(_WORD *)(v84 + 2) = 0;
              *(_DWORD *)(v84 + 12) = CcDelayedFlushTimer;
              *(_DWORD *)(v84 + 16) = v84;
              *(_DWORD *)(v84 + 28) = 0;
              *(_DWORD *)(v84 + 8) = 0;
              v85 = __mrc(15, 0, 9, 13, 0);
              v86 = v85 << 29;
              v87 = v85 ^ (v85 >> 3);
              v88 = 67117057i64 * (unsigned int)v87;
              v89 = 67117057 * v86 + 1880096896 * v87;
              v90 = (1880096896i64 * v86 + ((67117057i64 * v86 + 1880096896 * (unsigned __int64)(unsigned int)v87) >> 32)) >> 32;
              v91 = 1880096896 * v86 + ((67117057i64 * v86 + 1880096896 * (unsigned __int64)(unsigned int)v87) >> 32);
              if ( (unsigned int)(v89 + HIDWORD(v88)) < HIDWORD(v88) )
                v90 = (__PAIR64__(v90, v91++) + 1) >> 32;
              *(_DWORD *)(v84 + 104) = v91 ^ v88;
              *(_DWORD *)(v84 + 108) = v90 ^ (v89 + HIDWORD(v88));
              v92 = __mrc(15, 0, 9, 13, 0);
              v93 = v92 << 29;
              v94 = v92 ^ (v92 >> 3);
              v95 = 67117057i64 * (unsigned int)v94;
              v96 = 67117057i64 * v93 + 1880096896i64 * (unsigned int)v94;
              v97 = (1880096896i64 * v93 + (unsigned __int64)HIDWORD(v96)) >> 32;
              v98 = 1880096896 * v93 + HIDWORD(v96);
              if ( (unsigned int)(v96 + HIDWORD(v95)) < HIDWORD(v95) )
                v97 = (__PAIR64__(v97, v98++) + 1) >> 32;
              LODWORD(v99) = v95 ^ v98;
              HIDWORD(v99) = (v96 + HIDWORD(v95)) ^ v97;
              _rt_udiv64(63i64, v99);
              *(_BYTE *)(v84 + 112) = v105 + 1;
              v100 = v163 - v166;
              HIDWORD(v105) = __mrc(15, 0, 9, 13, 0);
              v101 = HIDWORD(v105) << 29;
              HIDWORD(v105) ^= HIDWORD(v105) >> 3;
              v102 = 67117057i64 * HIDWORD(v105);
              v103 = 67117057 * v101 + 1880096896 * HIDWORD(v105);
              v104 = (1880096896i64 * v101 + ((67117057i64 * v101 + 1880096896 * (unsigned __int64)HIDWORD(v105)) >> 32)) >> 32;
              HIDWORD(v105) = 1880096896 * v101
                            + ((67117057i64 * v101 + 1880096896 * (unsigned __int64)HIDWORD(v105)) >> 32);
              if ( (unsigned int)(v103 + HIDWORD(v102)) < HIDWORD(v102) )
              {
                v104 = (__PAIR64__(v104, HIDWORD(v105)) + 1) >> 32;
                ++HIDWORD(v105);
              }
              LODWORD(v105) = v102 ^ HIDWORD(v105);
              if ( !(v100 >> 3) )
                __brkdiv0();
              HIDWORD(v105) = (v103 + HIDWORD(v102)) ^ v104;
              _rt_udiv64((unsigned int)(v100 >> 3), v105);
              v107 = &v166[8 * v106];
              *(_DWORD *)(v84 + 80) = v107;
              *(_DWORD *)(v84 + 84) = 0x400000;
              v108 = *(_DWORD *)v107;
              v109 = *((_DWORD *)v107 + 1);
              v167 = v107;
              v110 = (_DWORD *)((*(_DWORD *)v107 & 0xFFFFFFFE) + 0x400000);
              if ( (v109 & 3) != 0 )
                v111 = (v109 >> 2) & 0x7FF;
              else
                v111 = *(_DWORD *)(v109 + 0x400000) & 0x3FFFF;
              v112 = *(_BYTE *)(v84 + 112);
              v113 = ((v108 + 2 * v111) & 0xFFFFFFFE) - (v108 & 0xFFFFFFFE);
              v114 = *(_QWORD *)(v84 + 104);
              v161 = v113;
              v165 = v112;
              v115 = (char *)((v108 & 0xFFFFFFFE) + 0x400000);
              if ( v110 < (_DWORD *)((char *)v110 + v113) )
              {
                do
                {
                  __pld(v115);
                  v115 += 128;
                }
                while ( v115 < (char *)v110 + v113 );
              }
              v116 = *(_BYTE *)(v84 + 112);
              v162 = v116;
              v164 = v113;
              v117 = v113;
              if ( v113 >= 8 )
              {
                v118 = v112 & 0x3F;
                v119 = 64 - (v112 & 0x3F);
                v120 = (v112 & 0x3F) - 32;
                v121 = 32 - (v112 & 0x3F);
                v122 = v113 >> 3;
                do
                {
                  v117 -= 8;
                  v123 = v114 ^ *v110;
                  v124 = v110[1];
                  v110 += 2;
                  v125 = HIDWORD(v114) ^ v124;
                  v126 = (v123 >> v119) | (v125 << v120) | (v125 >> v121);
                  HIDWORD(v114) = (v125 >> v119) | (__PAIR64__(v125, v123) << v118 >> 32);
                  LODWORD(v114) = v126 | (v123 << v118);
                  v121 = v119 - 32;
                  --v122;
                }
                while ( v122 );
                v84 = v160;
                v113 = v161;
                v107 = v167;
                v116 = v162;
                v164 = v117;
              }
              if ( v117 )
              {
                v127 = v116 & 0x3F;
                v128 = 64 - (v116 & 0x3F);
                v129 = v164;
                v130 = (v116 & 0x3F) - 32;
                v131 = 32 - (v116 & 0x3F);
                do
                {
                  v132 = *(unsigned __int8 *)v110;
                  v110 = (_DWORD *)((char *)v110 + 1);
                  v133 = (v114 ^ v132) << v127;
                  LODWORD(v114) = ((v132 ^ (unsigned int)v114) >> v128) | (HIDWORD(v114) << v130) | (HIDWORD(v114) >> v131) | ((v132 ^ (unsigned int)v114) << v127);
                  HIDWORD(v114) = (HIDWORD(v114) >> v128) | HIDWORD(v133);
                  --v129;
                }
                while ( v129 );
                v84 = v160;
                v113 = v161;
                v107 = v167;
              }
              *(_QWORD *)(v84 + 96) = v114;
              for ( i = v107; i < v107 + 8; i += 128 )
                __pld(i);
              v135 = v114 ^ *(_DWORD *)v107;
              v136 = *((_DWORD *)v107 + 1);
              *(_DWORD *)(v84 + 88) = v113;
              v137 = (v135 >> (64 - (v165 & 0x3F))) | ((HIDWORD(v114) ^ v136) << ((v165 & 0x3F) - 32)) | ((HIDWORD(v114) ^ v136) >> (32 - (v165 & 0x3F)));
              *(_DWORD *)(v84 + 100) = (v135 << ((v165 & 0x3F) - 32)) | ((HIDWORD(v114) ^ v136) << (v165 & 0x3F)) | (v135 >> (32 - (v165 & 0x3F))) | ((HIDWORD(v114) ^ v136) >> (64 - (v165 & 0x3F)));
              v138 = v169;
              *(_DWORD *)(v84 + 116) = v169;
              *(_DWORD *)(v84 + 96) = (v135 << (v165 & 0x3F)) | v137;
              if ( v138 )
              {
                *(_DWORD *)(v84 + 128) = sub_6A2000;
                *(_DWORD *)(v84 + 132) = v84;
                *(_DWORD *)(v84 + 120) = 0;
              }
              v139 = __mrc(15, 0, 9, 13, 0);
              v140 = v139 << 29;
              v141 = v139 ^ (v139 >> 3);
              v142 = 67117057i64 * (unsigned int)v141;
              v143 = 1880096896i64 * (unsigned int)v141 + 67117057i64 * v140;
              v144 = (1880096896i64 * v140 + (unsigned __int64)HIDWORD(v143)) >> 32;
              v145 = 1880096896 * v140 + HIDWORD(v143);
              if ( (unsigned int)(v143 + HIDWORD(v142)) < HIDWORD(v142) )
                v144 = (__PAIR64__(v144, v145++) + 1) >> 32;
              LODWORD(v146) = v142 ^ v145;
              HIDWORD(v146) = (v143 + HIDWORD(v142)) ^ v144;
              v147 = -6000000000i64 - FsRtlRemovePerStreamContextEx(100000000i64, v146);
              v148 = __mrc(15, 0, 9, 13, 0);
              v149 = v148 << 29;
              v150 = v148 ^ (v148 >> 3);
              v151 = 67117057i64 * (unsigned int)v150;
              v152 = (1880096896i64 * v149
                    + ((1880096896i64 * (unsigned int)v150 + 67117057 * (unsigned __int64)v149) >> 32)) >> 32;
              v153 = 1880096896 * v149
                   + ((1880096896i64 * (unsigned int)v150 + 67117057 * (unsigned __int64)v149) >> 32);
              v154 = (0x7010008004002001i64 * __PAIR64__(v149, v150)) >> 32;
              if ( v154 < HIDWORD(v151) )
                v152 = (__PAIR64__(v152, v153++) + 1) >> 32;
              LODWORD(v155) = v151 ^ v153;
              HIDWORD(v155) = v154 ^ v152;
              v156 = FsRtlRemovePerStreamContextEx(60000i64, v155);
              v159 = v156;
              LODWORD(v156) = v84 + 32;
              v170 = HIDWORD(v156);
              KeSetCoalescableTimer(v156, v147, 0, v159, v84);
            }
            break;
          case 9:
            v72 = FsRtlRemovePerStreamContextEx(3i64, 9ui64);
            if ( v72 )
            {
              if ( v72 == 1 )
              {
                v58 = __ROR4__(-1557388889, 23);
              }
              else
              {
                v63 = -2036429648;
LABEL_80:
                v58 = __ROR4__(v63, 9);
              }
            }
            else
            {
              v62 = -1333354868;
LABEL_124:
              v58 = __ROR4__(v62, 1);
            }
            goto LABEL_128;
          case 10:
            v73 = __mrc(15, 0, 9, 13, 0);
            v74 = v73 << 29;
            HIDWORD(v76) = v73 ^ (v73 >> 3);
            v75 = 67117057i64 * HIDWORD(v76);
            LODWORD(v76) = 1880096896 * v74 + ((67117057i64 * v74 + 1880096896 * (unsigned __int64)HIDWORD(v76)) >> 32);
            if ( (0x7010008004002001i64 * __PAIR64__(v74, HIDWORD(v76))) >> 32 < HIDWORD(v75) )
            {
              v76 = 1880096896i64 * v74 + ((67117057i64 * v74 + 1880096896 * (unsigned __int64)HIDWORD(v76)) >> 32) + 1;
              v170 = HIDWORD(v76);
            }
            v77 = v75 ^ v76;
            v78 = FsRtlRemovePerStreamContextEx(26i64, (unsigned int)v75 ^ (unsigned __int64)(unsigned int)v76);
            v77 >>= 5;
            v170 = HIDWORD(v78);
            v79 = v78;
            v80 = FsRtlRemovePerStreamContextEx(26i64, v77);
            v77 >>= 5;
            v170 = HIDWORD(v80);
            v81 = v80;
            v82 = FsRtlRemovePerStreamContextEx(26i64, v77);
            v170 = HIDWORD(v82);
            v58 = (FsRtlRemovePerStreamContextEx(26i64, v77 >> 5) + 65) | (((_DWORD)v82 + 97) << 8) | ((v79 + 97) << 24) | ((v81 + 65) << 16);
            goto LABEL_128;
        }
      }
    }
  }
}
