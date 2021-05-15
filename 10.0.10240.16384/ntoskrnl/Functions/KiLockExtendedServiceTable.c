// KiLockExtendedServiceTable 
 
int __fastcall KiLockExtendedServiceTable(unsigned int a1, int a2, unsigned int a3, int a4)
{
  int result; // r0
  unsigned int v6; // r5
  unsigned int v7; // r6
  unsigned int v8; // r2
  unsigned int v9; // r7
  _DWORD *v10; // r9
  char *v11; // r3
  unsigned int v12; // r10
  unsigned int v13; // r2
  char v14; // lr
  char v15; // r8
  char v16; // r0
  char v17; // r4
  unsigned int v18; // r10
  unsigned int v19; // r5
  int v20; // r3
  unsigned int v21; // r0
  char v22; // lr
  char v23; // r8
  char v24; // r10
  char v25; // r1
  int v26; // t1
  int v27; // r3
  _DWORD *v28; // r8
  unsigned int v29; // r2
  unsigned int v30; // r10
  char *v31; // r3
  char v32; // r9
  unsigned int v33; // r7
  char v34; // r6
  char v35; // lr
  unsigned int v36; // r9
  char v37; // r0
  char v38; // r4
  unsigned int v39; // r5
  int v40; // r3
  unsigned int v41; // r0
  char v42; // r6
  char v43; // lr
  char v44; // r9
  char v45; // r1
  int v46; // t1
  int v47; // r3
  unsigned int v48; // r5
  unsigned int v49; // r7
  int v50; // r0
  int v51; // r0
  int v52; // r9
  _DWORD *v53; // r7
  int v54; // r3
  int v55; // r2
  char v56; // r0
  char v57; // r4
  int v58; // r8
  int v59; // r3
  char *v60; // r0
  char *v61; // r5
  char *v62; // r6
  char *v63; // lr
  unsigned int v64; // r1
  int *v65; // r4
  int v66; // r2
  int v67; // t1
  int v68; // t1
  int v69; // r2
  int v70; // t1
  int v71; // t1
  unsigned int v72; // r1
  int *v73; // r0
  int v74; // r2
  int v75; // t1
  int v76; // t1
  int v77; // r2
  int v78; // t1
  int v79; // t1
  unsigned int v80; // r1
  int *v81; // r0
  int v82; // r2
  int v83; // t1
  int v84; // t1
  int v85; // r2
  int v86; // t1
  int v87; // t1
  unsigned int v88; // r1
  int *v89; // r0
  int v90; // r2
  int v91; // t1
  int v92; // t1
  int v93; // r2
  int v94; // t1
  int v95; // t1
  unsigned int v96; // r6
  _DWORD *v97; // lr
  char *v98; // r3
  unsigned int v99; // r8
  unsigned int v100; // r5
  int v101; // r3
  unsigned int v102; // r0
  int v103; // t1
  int v104; // r3
  unsigned int v105; // r3
  int v106; // r2
  unsigned int v107; // r6
  int i; // r4
  int v109; // r3
  unsigned int v110; // r5
  int v111; // r3
  unsigned int v112; // r3
  int *v113; // r0
  int v114; // r2
  int v115; // t1
  unsigned int v116; // r8
  unsigned int v117; // r5
  int v118; // r7
  unsigned int v119; // r2
  unsigned int v120; // r9
  unsigned int v121; // r0
  int *v122; // r1
  __int64 v123; // r2
  _DWORD *v124; // lr
  unsigned int v125; // r6
  char *v126; // r3
  unsigned int v127; // r9
  unsigned __int64 v128; // r4
  int v129; // r3
  int v130; // r3
  char v131; // r10
  int v132; // t1
  unsigned int v133; // r4
  unsigned int v134; // r3
  int v135; // r2
  __int64 v136; // kr18_8
  __int64 v137; // kr20_8
  unsigned int v138; // r1
  int v139; // r3
  __int64 v140; // r2
  char v141; // [sp+8h] [bp-80h]
  unsigned int v142; // [sp+8h] [bp-80h]
  unsigned int v143; // [sp+Ch] [bp-7Ch]
  unsigned int v144; // [sp+10h] [bp-78h] BYREF
  int v145; // [sp+14h] [bp-74h] BYREF
  int v146; // [sp+18h] [bp-70h]
  int v147; // [sp+1Ch] [bp-6Ch]
  _DWORD *v148; // [sp+20h] [bp-68h]
  unsigned int v149; // [sp+24h] [bp-64h]
  unsigned int v150; // [sp+28h] [bp-60h]
  __int64 *v151; // [sp+2Ch] [bp-5Ch] BYREF
  unsigned int v152; // [sp+30h] [bp-58h]
  _DWORD *v153; // [sp+34h] [bp-54h]
  unsigned int v154; // [sp+38h] [bp-50h]
  int v155; // [sp+3Ch] [bp-4Ch]
  unsigned int v156; // [sp+40h] [bp-48h]
  int v157; // [sp+44h] [bp-44h]
  int v158[3]; // [sp+48h] [bp-40h] BYREF
  int v159[2]; // [sp+54h] [bp-34h] BYREF
  unsigned int v160; // [sp+5Ch] [bp-2Ch]
  int *v161; // [sp+60h] [bp-28h]
  int v162; // [sp+64h] [bp-24h] BYREF
  int v163[8]; // [sp+68h] [bp-20h] BYREF

  v153 = (_DWORD *)a2;
  v144 = a1;
  v149 = a3;
  if ( a4 )
  {
    __dmb(0xBu);
    result = 1;
    do
      v6 = __ldrex((unsigned int *)&unk_618DC8);
    while ( !v6 && __strex(1u, (unsigned int *)&unk_618DC8) );
    __dmb(0xBu);
    if ( !v6 )
    {
      v7 = 4 * a3;
      v8 = 4 * a3 + a1;
      v9 = 0;
      v10 = (_DWORD *)a1;
      v11 = (char *)a1;
      if ( a1 < v8 )
      {
        do
        {
          __pld(v11);
          v11 += 128;
        }
        while ( (unsigned int)v11 < v8 );
      }
      v12 = (unsigned int)&qword_618DC0 & 0x3F;
      v13 = (unsigned int)&qword_618DC0;
      if ( v7 >= 8 )
      {
        v14 = v12 & 0x3F;
        v15 = 64 - (v12 & 0x3F);
        v16 = (v12 & 0x3F) - 32;
        v17 = 32 - (v12 & 0x3F);
        v18 = v7 >> 3;
        do
        {
          v7 -= 8;
          v19 = *v10 ^ v13;
          v20 = v10[1];
          v10 += 2;
          v21 = (v19 >> v15) | ((v20 ^ v9) << v16) | ((v20 ^ v9) >> v17);
          v9 = ((v20 ^ v9) >> v15) | (__PAIR64__(v20 ^ v9, v19) << v14 >> 32);
          v13 = (v19 << v14) | v21;
          v17 = v15 - 32;
          --v18;
          v16 = 32 - v15;
        }
        while ( v18 );
        LOBYTE(v12) = (unsigned int)&qword_618DC0 & 0x3F;
      }
      if ( v7 )
      {
        v22 = v12 & 0x3F;
        v23 = 64 - (v12 & 0x3F);
        v24 = (v12 & 0x3F) - 32;
        v25 = v23 - 32;
        do
        {
          v26 = *(unsigned __int8 *)v10;
          v10 = (_DWORD *)((char *)v10 + 1);
          v27 = __PAIR64__(v9, v26 ^ v13) << v22 >> 32;
          v13 = ((v26 ^ v13) << v22) | ((v26 ^ v13) >> v23) | (v9 << v24) | (v9 >> v25);
          v9 = (v9 >> v23) | v27;
          --v7;
          v25 = v23 - 32;
        }
        while ( v7 );
      }
      v28 = v153;
      v29 = v13 ^ qword_618DC0;
      v30 = HIDWORD(qword_618DC0) ^ v9;
      v31 = (char *)v153;
      if ( v153 < (_DWORD *)((char *)v153 + v149) )
      {
        do
        {
          __pld(v31);
          v31 += 128;
        }
        while ( v31 < (char *)v153 + v149 );
      }
      v32 = v29 & 0x3F;
      v141 = v29 & 0x3F;
      v33 = v149;
      if ( v149 >= 8 )
      {
        v34 = v29 & 0x3F;
        v35 = 64 - (v29 & 0x3F);
        v36 = v149 >> 3;
        v37 = (v29 & 0x3F) - 32;
        v38 = 32 - (v29 & 0x3F);
        do
        {
          v33 -= 8;
          v39 = *v28 ^ v29;
          v40 = v28[1];
          v28 += 2;
          v41 = (v39 >> v35) | ((v40 ^ v30) << v37) | ((v40 ^ v30) >> v38);
          v30 = ((v40 ^ v30) >> v35) | (__PAIR64__(v40 ^ v30, v39) << v34 >> 32);
          v29 = (v39 << v34) | v41;
          v38 = v35 - 32;
          --v36;
          v37 = 32 - v35;
        }
        while ( v36 );
        v32 = v141;
      }
      if ( v33 )
      {
        v42 = v32 & 0x3F;
        v43 = 64 - (v32 & 0x3F);
        v44 = (v32 & 0x3F) - 32;
        v45 = v43 - 32;
        do
        {
          v46 = *(unsigned __int8 *)v28;
          v28 = (_DWORD *)((char *)v28 + 1);
          v47 = __PAIR64__(v30, v46 ^ v29) << v42 >> 32;
          v29 = ((v46 ^ v29) << v42) | ((v46 ^ v29) >> v43) | (v30 << v44) | (v30 >> v45);
          v30 = (v30 >> v43) | v47;
          --v33;
          v45 = v43 - 32;
        }
        while ( v33 );
      }
      v48 = v144 ^ v149 ^ v29;
      v143 = v48;
      if ( !RtlLookupFunctionTable(v144, v158, &v162, v144 ^ v149) )
        KeBugCheckEx(67, v144, v153);
      v49 = 0;
      dword_618DD8[0] = v158[0];
      v142 = 0;
      while ( 1 )
      {
        v50 = dword_618DD8[v49];
        v145 = v50;
        if ( !v50 )
          break;
        v51 = RtlImageNtHeader(v50);
        v151 = (__int64 *)v51;
        if ( !v51 )
          KeBugCheckEx(67, v144, v153);
        v52 = v145;
        v53 = (_DWORD *)(*(unsigned __int16 *)(v51 + 20) + v51 + 24);
        v54 = *(unsigned __int16 *)(v51 + 6);
        v148 = v53;
        v146 = v145;
        v156 = (unsigned int)&v53[10 * v54];
        v55 = v48 & 0x3F;
        v157 = v55;
        v56 = v55 - 32;
        v57 = 32 - v55;
        v147 = v55 - 32;
        v154 = 64 - v55;
        v155 = 32 - v55;
        v150 = 64 - v55;
        v152 = v55;
        do
        {
          v58 = 0;
          if ( (v53[9] & 0x2000000) != 0
            || *v53 == 1414090313 && v53[1] == 1195525195
            || *v53 == 1162297680
            && ((v59 = *((unsigned __int16 *)v53 + 2), v59 == 30839) || v59 == 29303 || v59 == 30583) )
          {
LABEL_64:
            v58 = 1;
          }
          else
          {
            v61 = off_61887C[0];
            v60 = VfExcludeSections[0];
            v62 = off_618880[0];
            v63 = off_618884;
            v64 = 7;
            v65 = v53;
            while ( 1 )
            {
              v67 = *v65++;
              v66 = v67;
              v68 = *(_DWORD *)v60;
              v60 += 4;
              if ( v66 != v68 )
                break;
              v64 -= 4;
              if ( v64 < 4 )
              {
                if ( !v64 )
                {
LABEL_63:
                  v52 = v145;
                  v48 = v143;
                  v56 = v147;
                  v57 = v155;
                  v146 = v145;
                  goto LABEL_64;
                }
                while ( 1 )
                {
                  v70 = *(char *)v65;
                  v65 = (int *)((char *)v65 + 1);
                  v69 = v70;
                  v71 = *v60++;
                  if ( v69 != v71 )
                    goto LABEL_43;
                  if ( !--v64 )
                    goto LABEL_63;
                }
              }
            }
LABEL_43:
            v72 = 8;
            v73 = v53;
            while ( 1 )
            {
              v75 = *v73++;
              v74 = v75;
              v76 = *(_DWORD *)v61;
              v61 += 4;
              if ( v74 != v76 )
                break;
              v72 -= 4;
              if ( v72 < 4 )
              {
                if ( !v72 )
                  goto LABEL_63;
                while ( 1 )
                {
                  v78 = *(char *)v73;
                  v73 = (int *)((char *)v73 + 1);
                  v77 = v78;
                  v79 = *v61++;
                  if ( v77 != v79 )
                    goto LABEL_50;
                  if ( !--v72 )
                    goto LABEL_63;
                }
              }
            }
LABEL_50:
            v80 = 4;
            v81 = v53;
            while ( 1 )
            {
              v83 = *v81++;
              v82 = v83;
              v84 = *(_DWORD *)v62;
              v62 += 4;
              if ( v82 != v84 )
                break;
              v80 -= 4;
              if ( v80 < 4 )
              {
                if ( !v80 )
                  goto LABEL_63;
                while ( 1 )
                {
                  v86 = *(char *)v81;
                  v81 = (int *)((char *)v81 + 1);
                  v85 = v86;
                  v87 = *v62++;
                  if ( v85 != v87 )
                    goto LABEL_57;
                  if ( !--v80 )
                    goto LABEL_63;
                }
              }
            }
LABEL_57:
            v88 = 6;
            v89 = v53;
            while ( 1 )
            {
              v91 = *v89++;
              v90 = v91;
              v92 = *(_DWORD *)v63;
              v63 += 4;
              if ( v90 != v92 )
                break;
              v88 -= 4;
              if ( v88 < 4 )
              {
                if ( !v88 )
                  goto LABEL_63;
                while ( 1 )
                {
                  v94 = *(char *)v89;
                  v89 = (int *)((char *)v89 + 1);
                  v93 = v94;
                  v95 = *v63++;
                  if ( v93 != v95 )
                    goto LABEL_83;
                  if ( !--v88 )
                    goto LABEL_63;
                }
              }
            }
LABEL_83:
            v52 = v145;
            v48 = v143;
            v56 = v147;
            v57 = v155;
            v146 = v145;
          }
          if ( (int)v53[9] < 0 )
            v58 = 1;
          v96 = v53[4];
          if ( v96 <= v53[2] )
            v96 = v53[2];
          if ( !v58 )
          {
            v97 = (_DWORD *)(v53[3] + v52);
            v98 = (char *)v97;
            if ( v97 < (_DWORD *)((char *)v97 + v96) )
            {
              do
              {
                __pld(v98);
                v98 += 128;
              }
              while ( v98 < (char *)v97 + v96 );
            }
            v143 = v48;
            if ( v96 >= 8 )
            {
              v99 = v96 >> 3;
              do
              {
                v96 -= 8;
                v100 = v48 ^ *v97;
                v101 = v97[1];
                v97 += 2;
                v102 = (v100 >> v150) | ((v101 ^ v30) << v56) | ((v101 ^ v30) >> v57);
                v30 = ((v101 ^ v30) >> v150) | (__PAIR64__(v101 ^ v30, v100) << v157 >> 32);
                v48 = v102 | (v100 << v157);
                v57 = v150 - 32;
                --v99;
                v56 = 32 - v150;
              }
              while ( v99 );
              v53 = v148;
              v52 = v146;
              v143 = v48;
            }
            if ( v96 )
            {
              do
              {
                v103 = *(unsigned __int8 *)v97;
                v97 = (_DWORD *)((char *)v97 + 1);
                v104 = __PAIR64__(v30, v103 ^ v48) >> v154;
                v30 = (__PAIR64__(v30, v103 ^ v48) << v152 >> 32) | (v30 >> v154);
                v48 = ((v103 ^ v48) << v152) | v104;
                --v96;
              }
              while ( v96 );
              v53 = v148;
              v52 = v146;
              v143 = v48;
            }
          }
          v57 = v155;
          v53 += 10;
          v56 = v147;
          v148 = v53;
        }
        while ( v53 != (_DWORD *)v156 );
        if ( !v142 )
        {
          v105 = *((_DWORD *)v151 + 33);
          if ( v105 >= 0x14 )
          {
            v106 = *((_DWORD *)v151 + 32);
            v107 = v105 + v106 + v52;
            for ( i = v106 + v52; i != v107; i += 20 )
            {
              if ( !*(_DWORD *)(i + 12) )
                break;
              v109 = *(_DWORD *)(i + 16);
              if ( !v109 )
                break;
              v110 = *(_DWORD *)(v109 + v52);
              if ( v110
                && MmIsSessionAddress(*(_DWORD *)(v109 + v52))
                && RtlLookupFunctionTable(v110, &v145, v163, v111) )
              {
                v112 = 0;
                v113 = dword_618DD8;
                do
                {
                  v115 = *v113++;
                  v114 = v115;
                  if ( v115 == v145 )
                    break;
                  if ( !v114 )
                  {
                    dword_618DD8[v112] = v145;
                    break;
                  }
                  ++v112;
                }
                while ( v112 < 0x10 );
                if ( v112 == 16 )
                  goto LABEL_99;
              }
            }
          }
        }
        v49 = v142 + 1;
        v48 = v143;
        v142 = v49;
        if ( v49 >= 0x10 )
        {
LABEL_99:
          v48 = v143;
          break;
        }
      }
      result = (int)memset(dword_618DD8, 0, 64);
      if ( __PAIR64__(v30, v48) == qword_618DC0 || !(v48 | v30) )
      {
        v30 = ~v30;
        v48 ^= 0x43D5D824u;
      }
      __dmb(0xFu);
      LODWORD(qword_618DC0) = v48;
      HIDWORD(qword_618DC0) = v30;
    }
  }
  else
  {
    v116 = (unsigned int)&dword_618DD0;
    v117 = (int)&dword_618DD0 >> 31;
    RtlImageNtHeader(0x400000);
    RtlCaptureImageExceptionValues(0x400000, v159, (int)&v144);
    v118 = v159[0];
    v159[1] = 0x400000;
    v144 >>= 3;
    v119 = v159[0] + 8 * v144;
    v120 = (unsigned int)&dword_618DD0 & 0x3F;
    v156 = (unsigned int)&dword_618DD0 & 0x3F;
    v121 = ((unsigned int)&dword_618DD0 & 0x3F) - 32;
    v122 = (int *)&v151;
    v150 = v121;
    v160 = v119;
    v161 = (int *)&v151;
    v154 = 64 - ((unsigned int)&dword_618DD0 & 0x3F);
    v152 = (unsigned int)&dword_618DD0 & 0x3F;
    while ( v118 && v118 != v119 )
    {
      *v122 = v118;
      v118 = v159[0] + 8;
      v159[0] += 8;
      v123 = *v151;
      v124 = (_DWORD *)((*(_DWORD *)v151 & 0xFFFFFFFE) + 0x400000);
      if ( (*((_DWORD *)v151 + 1) & 3) != 0 )
        HIDWORD(v123) = (HIDWORD(v123) >> 2) & 0x7FF;
      else
        HIDWORD(v123) = *(_DWORD *)(HIDWORD(v123) + 0x400000) & 0x3FFFF;
      v125 = ((v123 + 2 * HIDWORD(v123)) & 0xFFFFFFFE) - (v123 & 0xFFFFFFFE);
      v126 = (char *)((*(_DWORD *)v151 & 0xFFFFFFFE) + 0x400000);
      if ( v124 < (_DWORD *)((char *)v124 + v125) )
      {
        do
        {
          __pld(v126);
          v126 += 128;
        }
        while ( v126 < (char *)v124 + v125 );
      }
      if ( v125 >= 8 )
      {
        v127 = v125 >> 3;
        do
        {
          v125 -= 8;
          LODWORD(v128) = *v124 ^ v116;
          v129 = v124[1];
          v124 += 2;
          HIDWORD(v128) = v117 ^ v129;
          v130 = v128 >> v154;
          v117 = (v128 << v156 >> 32) | (HIDWORD(v128) >> v154);
          v116 = ((_DWORD)v128 << v156) | v130;
          --v127;
        }
        while ( v127 );
        LOBYTE(v120) = v152;
        LOBYTE(v121) = v150;
      }
      if ( v125 )
      {
        v131 = 64 - v120;
        do
        {
          v132 = *(unsigned __int8 *)v124;
          v124 = (_DWORD *)((char *)v124 + 1);
          v133 = (v117 << v120) | ((v132 ^ v116) >> (32 - v120)) | ((v132 ^ v116) << v121);
          v116 = ((v132 ^ v116) << v120) | (__PAIR64__(v117, v132 ^ v116) >> v131);
          v117 = v133 | (v117 >> v131);
          LOBYTE(v121) = v120 - 32;
          --v125;
        }
        while ( v125 );
      }
      v119 = v160;
      v122 = v161;
      LOBYTE(v121) = v120 - 32;
    }
    dword_618DD0 = v116;
    dword_618DD4 = v117;
    if ( qword_618DC0 )
      KeBugCheckEx(49, -1073741823, 0);
    v134 = __mrc(15, 0, 9, 13, 0);
    v135 = v134 ^ (v134 >> 3);
    v136 = 67117057i64 * (unsigned int)v135;
    v137 = 67117057i64 * (v134 << 29) + 1880096896i64 * (unsigned int)v135;
    v138 = (1880096896i64 * (v134 << 29) + (unsigned __int64)HIDWORD(v137)) >> 32;
    v139 = HIDWORD(v137);
    result = v137 + HIDWORD(v136);
    if ( (unsigned int)(v137 + HIDWORD(v136)) < HIDWORD(v136) )
    {
      v138 = (__PAIR64__(v138, HIDWORD(v137)) + 1) >> 32;
      v139 = HIDWORD(v137) + 1;
    }
    LODWORD(v140) = v136 ^ v139;
    HIDWORD(v140) = result ^ v138;
    qword_618DC0 = v140;
    if ( !(result ^ v138 | (unsigned int)v140) )
      qword_618DC0 = -3156879324i64;
  }
  return result;
}
