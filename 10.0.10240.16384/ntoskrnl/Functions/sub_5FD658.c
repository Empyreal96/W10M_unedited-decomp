// sub_5FD658 
 
_DWORD *__fastcall sub_5FD658(int a1, int a2)
{
  int v2; // r8
  unsigned int v3; // r3
  unsigned int v4; // r6
  int v5; // r3
  __int64 v6; // kr00_8
  __int64 v7; // kr08_8
  unsigned int v8; // r0
  int v9; // r3
  unsigned __int64 v10; // r2
  int v11; // r0
  unsigned int v12; // r3
  unsigned int v13; // r5
  int v14; // r3
  __int64 v15; // kr30_8
  __int64 v16; // kr40_8
  unsigned int v17; // r1
  int v18; // r3
  unsigned __int64 v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r5
  int v22; // r3
  __int64 v23; // kr58_8
  __int64 v24; // kr60_8
  unsigned int v25; // r1
  int v26; // r3
  unsigned __int64 v27; // r2
  unsigned int v28; // r3
  unsigned int v29; // r6
  int v30; // r3
  __int64 v31; // kr78_8
  __int64 v32; // kr80_8
  unsigned int v33; // r1
  int v34; // r3
  unsigned __int64 v35; // r2
  int v36; // r0
  unsigned int v37; // r3
  unsigned int v38; // r6
  int v39; // r3
  __int64 v40; // kr98_8
  __int64 v41; // krA0_8
  unsigned int v42; // r1
  int v43; // r3
  unsigned __int64 v44; // r2
  unsigned int v45; // r9
  int v46; // r0
  unsigned int v47; // r10
  int *v48; // r7
  unsigned int v49; // r9
  unsigned int v50; // r3
  unsigned int v51; // r6
  int v52; // r3
  unsigned int v53; // r5
  int v54; // r4
  unsigned int v55; // r2
  unsigned int v56; // r3
  unsigned int v57; // r3
  unsigned int v58; // r5
  int v59; // r3
  unsigned int v60; // r6
  int v61; // r4
  unsigned int v62; // r2
  unsigned int v63; // r3
  int v64; // r0
  int v65; // r1
  unsigned int v66; // r7
  bool v67; // cf
  unsigned int v68; // r10
  int *v69; // r9
  unsigned int v70; // r10
  unsigned int v71; // r3
  unsigned int v72; // r6
  int v73; // r3
  unsigned int v74; // r5
  int v75; // r4
  unsigned int v76; // r2
  unsigned int v77; // r3
  unsigned int v78; // r3
  unsigned int v79; // r5
  int v80; // r3
  unsigned int v81; // r6
  int v82; // r4
  unsigned int v83; // r2
  unsigned int v84; // r3
  int v85; // r0
  int v86; // r1
  _DWORD *v87; // r5
  int v88; // r3
  int v89; // r1
  _DWORD *v90; // r2
  int v91; // r6
  int v92; // r3
  int v93; // r1
  int v94; // r0
  int v95; // r0
  int v96; // r4
  unsigned int v97; // r9
  int *v98; // r7
  unsigned int v99; // r8
  unsigned int v100; // r3
  unsigned int v101; // r6
  int v102; // r3
  unsigned int v103; // r5
  int v104; // r4
  unsigned int v105; // r2
  unsigned int v106; // r3
  unsigned int v107; // r3
  unsigned int v108; // r5
  int v109; // r3
  unsigned int v110; // r6
  int v111; // r4
  unsigned int v112; // r2
  unsigned int v113; // r3
  int v114; // r0
  int v115; // r1
  unsigned int v116; // r9
  _DWORD *v117; // r7
  int *v118; // r10
  unsigned int v119; // r7
  unsigned int v120; // r3
  unsigned int v121; // r6
  int v122; // r3
  unsigned int v123; // r5
  int v124; // r4
  unsigned int v125; // r2
  unsigned int v126; // r3
  unsigned int v127; // r3
  unsigned int v128; // r5
  int v129; // r3
  unsigned int v130; // r6
  int v131; // r4
  unsigned int v132; // r2
  unsigned int v133; // r3
  int v134; // r0
  int v135; // r1
  unsigned int v136; // r2
  _DWORD *v137; // r1
  unsigned int v138; // r0
  int v139; // t1
  char *v140; // r1
  int v141; // r3
  int v143; // [sp+18h] [bp-48h]
  int v145; // [sp+20h] [bp-40h]
  _DWORD *v146; // [sp+20h] [bp-40h]
  int v147; // [sp+24h] [bp-3Ch]
  unsigned int v148; // [sp+28h] [bp-38h]
  int v149; // [sp+2Ch] [bp-34h]
  int v150; // [sp+2Ch] [bp-34h]
  int v151; // [sp+30h] [bp-30h]
  unsigned int v152; // [sp+30h] [bp-30h]
  int v153; // [sp+30h] [bp-30h]
  _DWORD *v154; // [sp+30h] [bp-30h]
  unsigned int v155; // [sp+38h] [bp-28h]
  int v156; // [sp+38h] [bp-28h]
  int v157; // [sp+38h] [bp-28h]
  int v158; // [sp+38h] [bp-28h]
  int v159; // [sp+38h] [bp-28h]
  int v160; // [sp+38h] [bp-28h]
  int v161; // [sp+38h] [bp-28h]
  int v162; // [sp+38h] [bp-28h]

  v143 = a1;
  v2 = a1;
  v3 = __mrc(15, 0, 9, 13, 0);
  v4 = v3 << 29;
  v5 = v3 ^ (v3 >> 3);
  v6 = 67117057i64 * (unsigned int)v5;
  v7 = 1880096896i64 * (unsigned int)v5 + 67117057i64 * v4;
  v8 = (1880096896i64 * v4 + (unsigned __int64)HIDWORD(v7)) >> 32;
  v9 = 1880096896 * v4 + HIDWORD(v7);
  if ( (unsigned int)(v7 + HIDWORD(v6)) < HIDWORD(v6) )
    v8 = (__PAIR64__(v8, v9++) + 1) >> 32;
  LODWORD(v10) = v6 ^ v9;
  HIDWORD(v10) = (v7 + HIDWORD(v6)) ^ v8;
  v11 = FsRtlRemovePerStreamContextEx(2048i64, v10);
  v149 = v11 + 3;
  v12 = __mrc(15, 0, 9, 13, 0);
  v13 = v12 << 29;
  v14 = v12 ^ (v12 >> 3);
  v15 = 67117057i64 * (unsigned int)v14;
  v16 = 1880096896i64 * (unsigned int)v14 + 67117057i64 * v13;
  v17 = (1880096896i64 * v13 + (unsigned __int64)HIDWORD(v16)) >> 32;
  v18 = 1880096896 * v13 + HIDWORD(v16);
  if ( (unsigned int)(v16 + HIDWORD(v15)) < HIDWORD(v15) )
    v17 = (__PAIR64__(v17, v18++) + 1) >> 32;
  LODWORD(v19) = v15 ^ v18;
  HIDWORD(v19) = (v16 + HIDWORD(v15)) ^ v17;
  v148 = FsRtlRemovePerStreamContextEx((unsigned int)(v11 + 4), v19) & 0xFFFFFFFC;
  v20 = __mrc(15, 0, 9, 13, 0);
  v21 = v20 << 29;
  v22 = v20 ^ (v20 >> 3);
  v23 = 67117057i64 * (unsigned int)v22;
  v24 = 1880096896i64 * (unsigned int)v22 + 67117057i64 * v21;
  v25 = (1880096896i64 * v21 + (unsigned __int64)HIDWORD(v24)) >> 32;
  v26 = 1880096896 * v21 + HIDWORD(v24);
  if ( (unsigned int)(v24 + HIDWORD(v23)) < HIDWORD(v23) )
    v25 = (__PAIR64__(v25, v26++) + 1) >> 32;
  LODWORD(v27) = v23 ^ v26;
  HIDWORD(v27) = (v24 + HIDWORD(v23)) ^ v25;
  v150 = v149 + (((unsigned int)FsRtlRemovePerStreamContextEx(2i64, v27) + 1) << 12);
  v28 = __mrc(15, 0, 9, 13, 0);
  v29 = v28 << 29;
  v30 = v28 ^ (v28 >> 3);
  v31 = 67117057i64 * (unsigned int)v30;
  v32 = 1880096896i64 * (unsigned int)v30 + 67117057i64 * v29;
  v33 = (1880096896i64 * v29 + (unsigned __int64)HIDWORD(v32)) >> 32;
  v34 = 1880096896 * v29 + HIDWORD(v32);
  if ( (unsigned int)(v32 + HIDWORD(v31)) < HIDWORD(v31) )
    v33 = (__PAIR64__(v33, v34++) + 1) >> 32;
  LODWORD(v35) = v31 ^ v34;
  HIDWORD(v35) = (v32 + HIDWORD(v31)) ^ v33;
  v36 = FsRtlRemovePerStreamContextEx(2048i64, v35);
  v145 = v36;
  v37 = __mrc(15, 0, 9, 13, 0);
  v38 = v37 << 29;
  v39 = v37 ^ (v37 >> 3);
  v40 = 67117057i64 * (unsigned int)v39;
  v41 = 1880096896i64 * (unsigned int)v39 + 67117057i64 * v38;
  v42 = (1880096896i64 * v38 + (unsigned __int64)HIDWORD(v41)) >> 32;
  v43 = 1880096896 * v38 + HIDWORD(v41);
  if ( (unsigned int)(v41 + HIDWORD(v40)) < HIDWORD(v40) )
    v42 = (__PAIR64__(v42, v43++) + 1) >> 32;
  LODWORD(v44) = v40 ^ v43;
  HIDWORD(v44) = (v41 + HIDWORD(v40)) ^ v42;
  v155 = FsRtlRemovePerStreamContextEx((unsigned int)(v36 + 1), v44);
  v45 = v155;
  v46 = (*(int (__fastcall **)(int, int, _DWORD))(v2 + 216))(512, v145 + 19, *(_DWORD *)(v2 + 832));
  v147 = v46;
  if ( !v46 )
  {
    ++*(_DWORD *)(v2 + 1056);
LABEL_80:
    ++*(_DWORD *)(v2 + 1056);
    return 0;
  }
  v47 = v155;
  v48 = (int *)v46;
  if ( v155 >= 8 )
  {
    v49 = v155 >> 3;
    do
    {
      v50 = __mrc(15, 0, 9, 13, 0);
      v51 = v50 << 29;
      v52 = v50 ^ (v50 >> 3);
      v53 = (67117057 * (unsigned __int64)(unsigned int)v52) >> 32;
      v151 = 67117057 * v52;
      v54 = 1880096896 * v52 + 67117057 * v51;
      v55 = (1880096896i64 * v51 + ((1880096896i64 * (unsigned int)v52 + 67117057 * (unsigned __int64)v51) >> 32)) >> 32;
      v56 = 1880096896 * v51 + ((1880096896i64 * (unsigned int)v52 + 67117057 * (unsigned __int64)v51) >> 32);
      if ( v54 + v53 < v53 )
        v55 = (__PAIR64__(v55, v56++) + 1) >> 32;
      v48[1] = v55 ^ (v54 + v53);
      *v48 = v56 ^ v151;
      v48 += 2;
      --v49;
      v47 -= 8;
    }
    while ( v49 );
    v2 = v143;
    v45 = v155;
  }
  if ( v47 )
  {
    v57 = __mrc(15, 0, 9, 13, 0);
    v58 = v57 << 29;
    v59 = v57 ^ (v57 >> 3);
    v60 = (67117057 * (unsigned __int64)(unsigned int)v59) >> 32;
    v156 = 67117057 * v59;
    v61 = 1880096896 * v59 + 67117057 * v58;
    v62 = (1880096896i64 * v58 + ((1880096896i64 * (unsigned int)v59 + 67117057 * (unsigned __int64)v58) >> 32)) >> 32;
    v63 = 1880096896 * v58 + ((1880096896i64 * (unsigned int)v59 + 67117057 * (unsigned __int64)v58) >> 32);
    if ( v61 + v60 < v60 )
      v62 = (__PAIR64__(v62, v63++) + 1) >> 32;
    v64 = v156 ^ v63;
    v65 = (v61 + v60) ^ v62;
    do
    {
      *(_BYTE *)v48 = v64;
      v48 = (int *)((char *)v48 + 1);
      v64 = FsRtlPrivateResetHighestLockOffset(v64, v65, 8);
      --v47;
    }
    while ( v47 );
  }
  v66 = v145 - v45;
  v67 = v145 - v45 >= 8;
  v68 = v147 + v45;
  v152 = v147 + v45;
  v69 = (int *)(v147 + v45 + 19);
  if ( v67 )
  {
    v70 = v66 >> 3;
    do
    {
      v71 = __mrc(15, 0, 9, 13, 0);
      v72 = v71 << 29;
      v73 = v71 ^ (v71 >> 3);
      v74 = (67117057 * (unsigned __int64)(unsigned int)v73) >> 32;
      v157 = 67117057 * v73;
      v75 = 1880096896 * v73 + 67117057 * v72;
      v76 = (1880096896i64 * v72 + ((1880096896i64 * (unsigned int)v73 + 67117057 * (unsigned __int64)v72) >> 32)) >> 32;
      v77 = 1880096896 * v72 + ((1880096896i64 * (unsigned int)v73 + 67117057 * (unsigned __int64)v72) >> 32);
      if ( v75 + v74 < v74 )
        v76 = (__PAIR64__(v76, v77++) + 1) >> 32;
      v69[1] = v76 ^ (v75 + v74);
      *v69 = v77 ^ v157;
      v66 -= 8;
      v69 += 2;
      --v70;
    }
    while ( v70 );
    v2 = v143;
    v68 = v152;
  }
  if ( v66 )
  {
    v78 = __mrc(15, 0, 9, 13, 0);
    v79 = v78 << 29;
    v80 = v78 ^ (v78 >> 3);
    v81 = (67117057 * (unsigned __int64)(unsigned int)v80) >> 32;
    v158 = 67117057 * v80;
    v82 = 1880096896 * v80 + 67117057 * v79;
    v83 = (1880096896i64 * v79 + ((1880096896i64 * (unsigned int)v80 + 67117057 * (unsigned __int64)v79) >> 32)) >> 32;
    v84 = 1880096896 * v79 + ((1880096896i64 * (unsigned int)v80 + 67117057 * (unsigned __int64)v79) >> 32);
    if ( v82 + v81 < v81 )
      v83 = (__PAIR64__(v83, v84++) + 1) >> 32;
    v85 = v158 ^ v84;
    v86 = (v82 + v81) ^ v83;
    do
    {
      *(_BYTE *)v69 = v85;
      v69 = (int *)((char *)v69 + 1);
      v85 = FsRtlPrivateResetHighestLockOffset(v85, v86, 8);
      --v66;
    }
    while ( v66 );
  }
  if ( !v68 )
    goto LABEL_80;
  v87 = (_DWORD *)((v68 + 3) & 0xFFFFFFFC);
  v146 = v87;
  if ( !v87 )
    goto LABEL_80;
  v88 = 16;
  v89 = 4;
  v90 = (_DWORD *)((v68 + 3) & 0xFFFFFFFC);
  do
  {
    v88 -= 4;
    --v89;
    *v90++ = 0;
  }
  while ( v89 );
  for ( ; v88; --v88 )
  {
    *(_BYTE *)v90 = 0;
    v90 = (_DWORD *)((char *)v90 + 1);
  }
  v91 = *(_DWORD *)(v2 + 832);
  v87[2] = v91;
  v87[3] = v147;
  v92 = *(_DWORD *)(v2 + 992);
  v93 = 5;
  if ( (v92 & 0x1000000) != 0 )
    v93 = 21;
  else
    *(_DWORD *)(v2 + 992) = v92 | 0x1000000;
  v94 = (*(int (__fastcall **)(_DWORD, _DWORD, int, int, _DWORD, _DWORD, int, int, int))(v2 + 480))(
          0,
          0,
          -1,
          -1,
          0,
          0,
          v150 + a2,
          1,
          v93);
  if ( !v94
    || (*v87 = v94, (v95 = (*(int (__fastcall **)(int, int))(v2 + 484))(v150 + a2, v91)) == 0)
    || (v87[1] = v95, v96 = (*(int (**)(void))(v2 + 488))(), v153 = v96, !(*(int (**)(void))(v2 + 352))()) )
  {
    (*(void (__fastcall **)(unsigned int))(v2 + 496))((v68 + 3) & 0xFFFFFFFC);
    goto LABEL_80;
  }
  v97 = v148;
  v98 = (int *)v96;
  if ( v148 >= 8 )
  {
    v99 = v148 >> 3;
    do
    {
      v100 = __mrc(15, 0, 9, 13, 0);
      v101 = v100 << 29;
      v102 = v100 ^ (v100 >> 3);
      v103 = (67117057 * (unsigned __int64)(unsigned int)v102) >> 32;
      v159 = 67117057 * v102;
      v104 = 67117057 * v101 + 1880096896 * v102;
      v105 = (1880096896i64 * v101 + ((67117057i64 * v101 + 1880096896 * (unsigned __int64)(unsigned int)v102) >> 32)) >> 32;
      v106 = 1880096896 * v101 + ((67117057i64 * v101 + 1880096896 * (unsigned __int64)(unsigned int)v102) >> 32);
      if ( v104 + v103 < v103 )
        v105 = (__PAIR64__(v105, v106++) + 1) >> 32;
      v98[1] = v105 ^ (v104 + v103);
      *v98 = v106 ^ v159;
      v98 += 2;
      --v99;
      v97 -= 8;
    }
    while ( v99 );
    v2 = v143;
  }
  if ( v97 )
  {
    v107 = __mrc(15, 0, 9, 13, 0);
    v108 = v107 << 29;
    v109 = v107 ^ (v107 >> 3);
    v110 = (67117057 * (unsigned __int64)(unsigned int)v109) >> 32;
    v160 = 67117057 * v109;
    v111 = 67117057 * v108 + 1880096896 * v109;
    v112 = (1880096896i64 * v108 + ((67117057i64 * v108 + 1880096896 * (unsigned __int64)(unsigned int)v109) >> 32)) >> 32;
    v113 = 1880096896 * v108 + ((67117057i64 * v108 + 1880096896 * (unsigned __int64)(unsigned int)v109) >> 32);
    if ( v111 + v110 < v110 )
      v112 = (__PAIR64__(v112, v113++) + 1) >> 32;
    v114 = v160 ^ v113;
    v115 = (v111 + v110) ^ v112;
    do
    {
      *(_BYTE *)v98 = v114;
      v98 = (int *)((char *)v98 + 1);
      v114 = FsRtlPrivateResetHighestLockOffset(v114, v115, 8);
      --v97;
    }
    while ( v97 );
  }
  v116 = v150 - v148;
  v117 = (_DWORD *)(v153 + v148);
  v154 = v117;
  v118 = (_DWORD *)((char *)v117 + a2);
  if ( v150 - v148 >= 8 )
  {
    v119 = v116 >> 3;
    do
    {
      v120 = __mrc(15, 0, 9, 13, 0);
      v121 = v120 << 29;
      v122 = v120 ^ (v120 >> 3);
      v123 = (67117057 * (unsigned __int64)(unsigned int)v122) >> 32;
      v161 = 67117057 * v122;
      v124 = 67117057 * v121 + 1880096896 * v122;
      v125 = (1880096896i64 * v121 + ((67117057i64 * v121 + 1880096896 * (unsigned __int64)(unsigned int)v122) >> 32)) >> 32;
      v126 = 1880096896 * v121 + ((67117057i64 * v121 + 1880096896 * (unsigned __int64)(unsigned int)v122) >> 32);
      if ( v124 + v123 < v123 )
        v125 = (__PAIR64__(v125, v126++) + 1) >> 32;
      v118[1] = v125 ^ (v124 + v123);
      *v118 = v126 ^ v161;
      v118 += 2;
      v116 -= 8;
      --v119;
    }
    while ( v119 );
    v2 = v143;
    v117 = v154;
  }
  if ( v116 )
  {
    v127 = __mrc(15, 0, 9, 13, 0);
    v128 = v127 << 29;
    v129 = v127 ^ (v127 >> 3);
    v130 = (67117057 * (unsigned __int64)(unsigned int)v129) >> 32;
    v162 = 67117057 * v129;
    v131 = 1880096896 * v129 + 67117057 * v128;
    v132 = (1880096896i64 * v128 + ((1880096896i64 * (unsigned int)v129 + 67117057 * (unsigned __int64)v128) >> 32)) >> 32;
    v133 = 1880096896 * v128 + ((1880096896i64 * (unsigned int)v129 + 67117057 * (unsigned __int64)v128) >> 32);
    if ( v131 + v130 < v130 )
      v132 = (__PAIR64__(v132, v133++) + 1) >> 32;
    v134 = v162 ^ v133;
    v135 = (v131 + v130) ^ v132;
    do
    {
      *(_BYTE *)v118 = v134;
      v118 = (int *)((char *)v118 + 1);
      v134 = FsRtlPrivateResetHighestLockOffset(v134, v135, 8);
      --v116;
    }
    while ( v116 );
  }
  if ( !v117 )
    return 0;
  v136 = *(_DWORD *)(v2 + 796);
  v137 = v117;
  if ( v136 >= 4 )
  {
    v138 = v136 >> 2;
    do
    {
      v139 = *(_DWORD *)v2;
      v2 += 4;
      v136 -= 4;
      --v138;
      *v137++ = v139;
    }
    while ( v138 );
  }
  if ( v136 )
  {
    v140 = (char *)v137 - v2;
    do
    {
      --v136;
      v140[v2] = *(_BYTE *)v2;
      ++v2;
    }
    while ( v136 );
  }
  v117[199] = a2;
  v117[195] = v146;
  v117[232] = 3;
  v141 = v117[248];
  if ( (v141 & 0x10000000) == 0 )
    v117[248] = v141 | 0x20000000;
  return v117;
}
