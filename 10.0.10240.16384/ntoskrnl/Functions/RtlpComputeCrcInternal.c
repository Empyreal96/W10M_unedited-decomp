// RtlpComputeCrcInternal 
 
int __fastcall RtlpComputeCrcInternal(unsigned int a1, unsigned int a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v6; // r1
  _QWORD *v7; // r9
  int v8; // lr
  unsigned int v9; // r6
  unsigned int v10; // r7
  unsigned int v12; // r2
  int v13; // lr
  int v14; // r8
  int v15; // r10
  int v16; // r0
  _QWORD *v17; // r9
  __int64 v18; // t1
  unsigned int v19; // r5
  unsigned int v20; // r7
  unsigned int v21; // r4
  unsigned int v22; // lr
  unsigned int v23; // r6
  unsigned int v24; // r8
  unsigned int v25; // r10
  unsigned int v26; // r9
  _DWORD *v27; // r0
  unsigned int v28; // r5
  unsigned int v29; // r7
  unsigned int v30; // r8
  unsigned int v31; // r10
  int v32; // r2
  unsigned int v33; // r5
  int v34; // r1
  int v35; // r2
  int v36; // r1
  int v37; // r3
  unsigned int v38; // r7
  int v39; // r2
  int v40; // lr
  int v41; // r8
  unsigned int v42; // r9
  int v43; // r1
  int v44; // r10
  int v45; // r2
  unsigned int v46; // r1
  unsigned int v47; // r4
  int v48; // r1
  int v49; // r6
  unsigned int v50; // r7
  unsigned int v51; // r9
  unsigned int v52; // r5
  int v53; // r1
  int v54; // r2
  unsigned int v55; // r4
  __int64 v56; // r1
  int v57; // r5
  int v58; // r6
  int v59; // lr
  int v60; // r8
  __int64 v61; // kr20_8
  int v62; // lr
  int v63; // r3
  int v64; // r3
  int v65; // r0
  int v66; // r3
  int v67; // r3
  __int64 v68; // t1
  int v69; // r5
  unsigned int v70; // r4
  unsigned int v71; // r0
  __int64 v72; // t1
  unsigned int v73; // r0
  unsigned int v74; // r4
  __int64 v75; // kr30_8
  unsigned int v76; // r0
  unsigned int v77; // r4
  int v78; // r1
  unsigned int v79; // r0
  unsigned int v80; // r4
  int v81; // r3
  unsigned int v82; // r0
  unsigned int v83; // r4
  __int64 v84; // kr48_8
  unsigned int v85; // r0
  unsigned int v86; // r4
  int v87; // r1
  unsigned int v88; // r0
  unsigned int v89; // r4
  int v90; // r3
  unsigned int v91; // r0
  unsigned int v92; // r4
  __int64 v93; // kr60_8
  int v94; // r0
  unsigned int v95; // r4
  _DWORD *v96; // r2
  unsigned int v97; // r0
  unsigned int v98; // r4
  __int128 v99; // r1
  unsigned int v100; // r0
  unsigned int v101; // r4
  int v102; // r1
  unsigned int v103; // r0
  unsigned int v104; // r0
  unsigned int v105; // r0
  unsigned int v106; // r0
  unsigned int v107; // r0
  int v108; // r0
  unsigned int v109; // r0
  __int64 v110; // kr80_8
  unsigned int v111; // r0
  unsigned int v112; // r0
  unsigned int v113; // r0
  __int64 v114; // kr98_8
  unsigned int v115; // r0
  unsigned int v116; // r0
  unsigned int v117; // r0
  __int64 v118; // krB0_8
  int v119; // r0
  unsigned int v120; // r0
  unsigned int v121; // r0
  int v122; // r0
  unsigned int v123; // r0
  unsigned int v124; // r0
  unsigned int v125; // r0
  unsigned int v126; // r0
  unsigned int v127; // r0
  unsigned int v128; // r0
  int v129; // r4
  char v130; // r3
  _DWORD *v131; // r1
  int v132; // [sp+0h] [bp-78h]
  unsigned int v133; // [sp+4h] [bp-74h]
  int v134; // [sp+4h] [bp-74h]
  int v135; // [sp+4h] [bp-74h]
  int v136; // [sp+8h] [bp-70h]
  int v137; // [sp+8h] [bp-70h]
  int v138; // [sp+Ch] [bp-6Ch]
  int v139; // [sp+Ch] [bp-6Ch]
  int v140; // [sp+Ch] [bp-6Ch]
  __int64 v141; // [sp+10h] [bp-68h]
  __int64 v142; // [sp+10h] [bp-68h]
  int v143; // [sp+18h] [bp-60h]
  int v144; // [sp+18h] [bp-60h]
  unsigned int v145; // [sp+18h] [bp-60h]
  int v146; // [sp+1Ch] [bp-5Ch]
  int v147; // [sp+1Ch] [bp-5Ch]
  int v148; // [sp+1Ch] [bp-5Ch]
  int v149; // [sp+1Ch] [bp-5Ch]
  int v150; // [sp+20h] [bp-58h]
  int v151; // [sp+20h] [bp-58h]
  int v152; // [sp+24h] [bp-54h]
  unsigned int v153; // [sp+24h] [bp-54h]
  int v154; // [sp+28h] [bp-50h]
  int v155; // [sp+28h] [bp-50h]
  unsigned int v156; // [sp+28h] [bp-50h]
  int v157; // [sp+2Ch] [bp-4Ch]
  unsigned int v158; // [sp+2Ch] [bp-4Ch]
  int v159; // [sp+2Ch] [bp-4Ch]
  unsigned int v160; // [sp+30h] [bp-48h]
  int v161; // [sp+30h] [bp-48h]
  int v162; // [sp+30h] [bp-48h]
  int v163; // [sp+34h] [bp-44h]
  unsigned int v164; // [sp+38h] [bp-40h]
  int v165; // [sp+3Ch] [bp-3Ch]
  int v166; // [sp+3Ch] [bp-3Ch]
  int v167; // [sp+40h] [bp-38h]
  int v168; // [sp+44h] [bp-34h]
  unsigned int v169; // [sp+44h] [bp-34h]
  _QWORD *v170; // [sp+48h] [bp-30h]
  unsigned int v171; // [sp+50h] [bp-28h]

  v6 = a5;
  v7 = (_QWORD *)a1;
  v8 = a5[6];
  v9 = a5[7] ^ a4;
  v10 = v8 ^ a3;
  if ( (-a1 & 7) != 0 )
    return sub_54FEF0();
  v12 = a2 - (a2 & 0x1F);
  if ( v12 >= 0x40 )
  {
    v141 = 0i64;
    v143 = 0;
    v13 = 0;
    v171 = v12 + a1 - 32;
    v14 = 0;
    v15 = 0;
    v167 = a2 & 0x1F;
    if ( a1 < v171 )
    {
      v16 = a5[2];
      v132 = v16;
      do
      {
        __pld(v7 + 32);
        v18 = *v7;
        v17 = v7 + 4;
        v19 = v18 ^ v10;
        v20 = *((_DWORD *)v17 - 6) ^ v13;
        v21 = HIDWORD(v18) ^ v9;
        v22 = HIDWORD(v141) ^ *((_DWORD *)v17 - 3);
        v23 = *((_DWORD *)v17 - 5) ^ v14;
        v24 = *((_DWORD *)v17 - 4) ^ v15;
        v25 = *((_DWORD *)v17 - 2) ^ v141;
        v170 = v17;
        v26 = *((_DWORD *)v17 - 1) ^ v143;
        v27 = (_DWORD *)(v16 + 8 * (unsigned __int8)v19 + 14336);
        v28 = (v21 << 24) | (v19 >> 8);
        v21 >>= 8;
        v157 = *(_DWORD *)(v132 + 8 * (unsigned __int8)v20 + 14336);
        v154 = *(_DWORD *)(v132 + 8 * (unsigned __int8)v20 + 14340);
        v29 = (v23 << 24) | (v20 >> 8);
        v23 >>= 8;
        v144 = *(_DWORD *)(v132 + 8 * (unsigned __int8)v24 + 14340);
        v152 = *(_DWORD *)(v132 + 8 * (unsigned __int8)v24 + 14336);
        v30 = (v22 << 24) | (v24 >> 8);
        v22 >>= 8;
        v142 = *(_QWORD *)(v132 + 8 * (unsigned __int8)v25 + 14336);
        v31 = (v26 << 24) | (v25 >> 8);
        v26 >>= 8;
        v138 = *(_DWORD *)(v132 + 8 * (unsigned __int8)v28 + 12288) ^ *v27;
        v136 = *(_DWORD *)(v132 + 8 * (unsigned __int8)v28 + 12292) ^ v27[1];
        v32 = v132 + 8 * (unsigned __int8)v29;
        v33 = (v21 << 24) | (v28 >> 8);
        v165 = v157 ^ *(_DWORD *)(v32 + 12288);
        v155 = *(_DWORD *)(v32 + 12292) ^ v154;
        v158 = (v23 << 24) | (v29 >> 8);
        v34 = v132 + 8 * (unsigned __int8)v30;
        v168 = v152 ^ *(_DWORD *)(v34 + 12288);
        v150 = *(_DWORD *)(v34 + 12292) ^ v144;
        v153 = (v22 << 24) | (v30 >> 8);
        v164 = v22 >> 8;
        v35 = v132 + 8 * (unsigned __int8)v31;
        v163 = v142 ^ *(_DWORD *)(v35 + 12288);
        v146 = *(_DWORD *)(v35 + 12292) ^ HIDWORD(v142);
        v160 = (v26 << 24) | (v31 >> 8);
        v133 = v26 >> 8;
        v36 = v132 + 8 * (unsigned __int8)v33;
        v139 = v138 ^ *(_DWORD *)(v36 + 10240);
        v37 = *(_DWORD *)(v36 + 10244);
        v38 = HIWORD(v21);
        v145 = (v21 >> 8 << 24) | (v33 >> 8);
        v39 = v132 + 8 * (unsigned __int8)v158;
        v40 = *(_DWORD *)(v39 + 10240) ^ v165;
        v41 = *(_DWORD *)(v39 + 10244) ^ v155;
        v42 = HIWORD(v23);
        LODWORD(v142) = (v23 >> 8 << 24) | (v158 >> 8);
        v43 = v132 + 8 * (unsigned __int8)v153;
        v44 = *(_DWORD *)(v43 + 10240) ^ v168;
        v151 = *(_DWORD *)(v43 + 10244) ^ v150;
        v45 = v132 + 8 * (unsigned __int8)v160;
        v46 = v133;
        v147 = *(_DWORD *)(v45 + 10244) ^ v146;
        v134 = (v133 << 24) | (v160 >> 8);
        v47 = v46 >> 8;
        v48 = v132 + 8 * (unsigned __int8)v145;
        v49 = *(_DWORD *)(v48 + 0x2000) ^ v139;
        v161 = *(_DWORD *)(v48 + 8196) ^ v37 ^ v136;
        v50 = (v38 << 24) | (v145 >> 8);
        v51 = (v42 << 24) | ((unsigned int)v142 >> 8);
        v52 = v134;
        v169 = (v164 >> 8 << 24) | (((v164 << 24) | (v153 >> 8)) >> 8);
        v53 = v132 + 8 * (unsigned __int8)v134;
        v135 = v163 ^ *(_DWORD *)(v45 + 10240) ^ *(_DWORD *)(v53 + 0x2000);
        v54 = (unsigned __int8)v50;
        v50 >>= 8;
        v148 = *(_DWORD *)(v53 + 8196) ^ v147;
        v55 = (v47 << 24) | (v52 >> 8);
        v56 = *(_QWORD *)(v132 + 8 * v54 + 6144);
        v57 = v56 ^ v49;
        v58 = HIDWORD(v56) ^ v161;
        LODWORD(v56) = v132 + 8 * (unsigned __int8)v51;
        v59 = v40 ^ *(_DWORD *)(v132 + 8 * (unsigned __int8)v142 + 0x2000) ^ *(_DWORD *)(v56 + 6144);
        v60 = v41 ^ *(_DWORD *)(v132 + 8 * (unsigned __int8)v142 + 8196) ^ *(_DWORD *)(v56 + 6148);
        v51 >>= 8;
        LODWORD(v56) = v132 + 8 * (unsigned __int8)v55;
        v162 = v135 ^ *(_DWORD *)(v56 + 6144);
        v149 = *(_DWORD *)(v56 + 6148) ^ v148;
        v61 = *(_QWORD *)(v132 + 8 * (unsigned __int8)v50 + 4096);
        LODWORD(v56) = v132 + 8 * (unsigned __int8)v51;
        v166 = *(_DWORD *)(v56 + 4096) ^ v59;
        v62 = *(_DWORD *)(v56 + 4100) ^ v60;
        LODWORD(v56) = v132 + 8 * BYTE1(v55);
        v63 = v132 + 8 * BYTE1(v50);
        HIDWORD(v56) = *(_DWORD *)(v132 + 8 * HIWORD(v50) + 4) ^ *(_DWORD *)(v63 + 2052);
        v156 = *(_DWORD *)(v132 + 8 * HIWORD(v50)) ^ *(_DWORD *)(v63 + 2048) ^ v61 ^ v57;
        v64 = v132 + 8 * BYTE1(v51);
        v65 = *(_DWORD *)(v132 + 8 * HIWORD(v51)) ^ *(_DWORD *)(v64 + 2048) ^ v166;
        v137 = *(_DWORD *)(v132 + 8 * HIWORD(v51) + 4) ^ *(_DWORD *)(v64 + 2052) ^ v62;
        v66 = v132 + 8 * BYTE2(v169);
        v159 = v65;
        v140 = *(_DWORD *)(v132 + 8 * HIBYTE(v169)) ^ *(_DWORD *)(v66 + 2048) ^ *(_DWORD *)(v132 + 8 * BYTE1(v169) + 4096) ^ *(_DWORD *)(v132 + 8 * (unsigned __int8)v169 + 6144) ^ *(_DWORD *)(v132 + 8 * BYTE1(v153) + 0x2000) ^ v44;
        HIDWORD(v141) = *(_DWORD *)(v132 + 8 * HIBYTE(v169) + 4) ^ *(_DWORD *)(v66 + 2052) ^ *(_DWORD *)(v132 + 8 * BYTE1(v169) + 4100) ^ *(_DWORD *)(v132 + 8 * (unsigned __int8)((unsigned __int16)(v153 >> 8) >> 8) + 6148) ^ *(_DWORD *)(v132 + 8 * BYTE1(v153) + 8196) ^ v151;
        v67 = v132 + 8 * BYTE2(v55);
        v7 = v170;
        v16 = a5[2];
        v9 = HIDWORD(v56) ^ HIDWORD(v61) ^ v58;
        v10 = v156;
        v13 = v159;
        LODWORD(v141) = v162 ^ *(_DWORD *)(v56 + 4096) ^ *(_DWORD *)(v132 + 8 * HIBYTE(v55)) ^ *(_DWORD *)(v67 + 2048);
        v143 = *(_DWORD *)(v132 + 8 * HIBYTE(v55) + 4) ^ *(_DWORD *)(v67 + 2052) ^ *(_DWORD *)(v56 + 4100) ^ v149;
        v14 = v137;
        v15 = v140;
      }
      while ( (unsigned int)v170 < v171 );
    }
    v68 = *v7;
    v7 += 4;
    v69 = a5[1];
    v70 = HIDWORD(v68) ^ v9;
    v71 = ((HIDWORD(v68) ^ v9) << 24) | (((unsigned int)v68 ^ v10) >> 8);
    v72 = *(_QWORD *)(v69 + 8 * (unsigned __int8)(v68 ^ v10));
    v73 = v71 ^ v72;
    v74 = HIDWORD(v72) ^ (v70 >> 8);
    v75 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v73);
    v76 = ((v74 << 24) | (v73 >> 8)) ^ v75;
    v77 = HIDWORD(v75) ^ (v74 >> 8);
    v78 = *(_DWORD *)(v69 + 8 * (unsigned __int8)v76 + 4);
    v79 = ((v77 << 24) | (v76 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v76);
    v80 = v78 ^ (v77 >> 8);
    v81 = *(_DWORD *)(v69 + 8 * (unsigned __int8)v79 + 4);
    v82 = ((v80 << 24) | (v79 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v79);
    v83 = v81 ^ (v80 >> 8);
    v84 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v82);
    v85 = ((v83 << 24) | (v82 >> 8)) ^ v84;
    v86 = HIDWORD(v84) ^ (v83 >> 8);
    v87 = *(_DWORD *)(v69 + 8 * (unsigned __int8)v85 + 4);
    v88 = ((v86 << 24) | (v85 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v85);
    v89 = v87 ^ (v86 >> 8);
    v90 = *(_DWORD *)(v69 + 8 * (unsigned __int8)v88 + 4);
    v91 = ((v89 << 24) | (v88 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v88);
    v92 = v90 ^ (v89 >> 8);
    v93 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v91);
    v94 = v93 ^ ((v92 << 24) | (v91 >> 8)) ^ *((_DWORD *)v7 - 6);
    v95 = HIDWORD(v93) ^ (v92 >> 8) ^ *((_DWORD *)v7 - 5) ^ v14;
    v96 = (_DWORD *)(v69 + 8 * (unsigned __int8)(v94 ^ v13));
    v97 = ((v95 << 24) | ((v94 ^ (unsigned int)v13) >> 8)) ^ *v96;
    v98 = v96[1] ^ (v95 >> 8);
    *(_QWORD *)((char *)&v99 + 4) = *(_QWORD *)(v69 + 8 * (unsigned __int8)v97);
    v100 = ((v98 << 24) | (v97 >> 8)) ^ DWORD1(v99);
    v101 = DWORD2(v99) ^ (v98 >> 8);
    v102 = *(_DWORD *)(v69 + 8 * (unsigned __int8)v100 + 4);
    v103 = ((v101 << 24) | (v100 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v100);
    HIDWORD(v99) = v102 ^ (v101 >> 8);
    *(_QWORD *)&v99 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v103);
    v104 = ((HIDWORD(v99) << 24) | (v103 >> 8)) ^ v99;
    HIDWORD(v99) = DWORD1(v99) ^ (HIDWORD(v99) >> 8);
    *(_QWORD *)((char *)&v99 + 4) = *(_QWORD *)(v69 + 8 * (unsigned __int8)v104);
    v105 = ((HIDWORD(v99) << 24) | (v104 >> 8)) ^ DWORD1(v99);
    HIDWORD(v99) = DWORD2(v99) ^ (HIDWORD(v99) >> 8);
    LODWORD(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)v105 + 4);
    v106 = ((HIDWORD(v99) << 24) | (v105 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v105);
    HIDWORD(v99) = v99 ^ (HIDWORD(v99) >> 8);
    *(_QWORD *)&v99 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v106);
    v107 = ((HIDWORD(v99) << 24) | (v106 >> 8)) ^ v99;
    HIDWORD(v99) = DWORD1(v99) ^ (HIDWORD(v99) >> 8);
    *(_QWORD *)((char *)&v99 + 4) = *(_QWORD *)(v69 + 8 * (unsigned __int8)v107);
    v108 = DWORD1(v99) ^ ((HIDWORD(v99) << 24) | (v107 >> 8)) ^ *((_DWORD *)v7 - 4);
    HIDWORD(v99) = DWORD2(v99) ^ (HIDWORD(v99) >> 8) ^ *((_DWORD *)v7 - 3) ^ HIDWORD(v141);
    DWORD2(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)(v108 ^ v15) + 4);
    v109 = ((HIDWORD(v99) << 24) | ((v108 ^ (unsigned int)v15) >> 8)) ^ *(_DWORD *)(v69
                                                                                  + 8 * (unsigned __int8)(v108 ^ v15));
    HIDWORD(v99) = DWORD2(v99) ^ (HIDWORD(v99) >> 8);
    v110 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v109);
    v111 = ((HIDWORD(v99) << 24) | (v109 >> 8)) ^ v110;
    HIDWORD(v99) = HIDWORD(v110) ^ (HIDWORD(v99) >> 8);
    LODWORD(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)v111 + 4);
    v112 = ((HIDWORD(v99) << 24) | (v111 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v111);
    HIDWORD(v99) = v99 ^ (HIDWORD(v99) >> 8);
    DWORD2(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)v112 + 4);
    v113 = ((HIDWORD(v99) << 24) | (v112 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v112);
    HIDWORD(v99) = DWORD2(v99) ^ (HIDWORD(v99) >> 8);
    v114 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v113);
    v115 = ((HIDWORD(v99) << 24) | (v113 >> 8)) ^ v114;
    HIDWORD(v99) = HIDWORD(v114) ^ (HIDWORD(v99) >> 8);
    LODWORD(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)v115 + 4);
    v116 = ((HIDWORD(v99) << 24) | (v115 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v115);
    HIDWORD(v99) = v99 ^ (HIDWORD(v99) >> 8);
    DWORD2(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)v116 + 4);
    v117 = ((HIDWORD(v99) << 24) | (v116 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v116);
    HIDWORD(v99) = DWORD2(v99) ^ (HIDWORD(v99) >> 8);
    v118 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v117);
    v119 = v118 ^ ((HIDWORD(v99) << 24) | (v117 >> 8)) ^ *((_DWORD *)v7 - 2);
    HIDWORD(v99) = HIDWORD(v118) ^ (HIDWORD(v99) >> 8) ^ *((_DWORD *)v7 - 1) ^ v143;
    *(_QWORD *)&v99 = *(_QWORD *)(v69 + 8 * (unsigned __int8)(v141 ^ v119));
    v120 = ((HIDWORD(v99) << 24) | (((unsigned int)v141 ^ v119) >> 8)) ^ v99;
    HIDWORD(v99) = DWORD1(v99) ^ (HIDWORD(v99) >> 8);
    *(_QWORD *)((char *)&v99 + 4) = *(_QWORD *)(v69 + 8 * (unsigned __int8)v120);
    v121 = ((HIDWORD(v99) << 24) | (v120 >> 8)) ^ DWORD1(v99);
    HIDWORD(v99) = DWORD2(v99) ^ (HIDWORD(v99) >> 8);
    LODWORD(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)v121 + 4);
    DWORD2(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)v121);
    v122 = (HIDWORD(v99) << 24) | (v121 >> 8);
    HIDWORD(v99) = v99 ^ (HIDWORD(v99) >> 8);
    v123 = v122 ^ DWORD2(v99);
    *(_QWORD *)&v99 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v123);
    v124 = ((HIDWORD(v99) << 24) | (v123 >> 8)) ^ v99;
    HIDWORD(v99) = DWORD1(v99) ^ (HIDWORD(v99) >> 8);
    *(_QWORD *)((char *)&v99 + 4) = *(_QWORD *)(v69 + 8 * (unsigned __int8)v124);
    v125 = ((HIDWORD(v99) << 24) | (v124 >> 8)) ^ DWORD1(v99);
    HIDWORD(v99) = DWORD2(v99) ^ (HIDWORD(v99) >> 8);
    LODWORD(v99) = *(_DWORD *)(v69 + 8 * (unsigned __int8)v125 + 4);
    v126 = ((HIDWORD(v99) << 24) | (v125 >> 8)) ^ *(_DWORD *)(v69 + 8 * (unsigned __int8)v125);
    HIDWORD(v99) = v99 ^ (HIDWORD(v99) >> 8);
    *(_QWORD *)&v99 = *(_QWORD *)(v69 + 8 * (unsigned __int8)v126);
    v127 = ((HIDWORD(v99) << 24) | (v126 >> 8)) ^ v99;
    HIDWORD(v99) = DWORD1(v99) ^ (HIDWORD(v99) >> 8);
    *(_QWORD *)((char *)&v99 + 4) = *(_QWORD *)(v69 + 8 * (unsigned __int8)v127);
    a2 = v167;
    v6 = a5;
    v8 = a5[6];
    v9 = DWORD2(v99) ^ (HIDWORD(v99) >> 8);
    v10 = DWORD1(v99) ^ ((HIDWORD(v99) << 24) | (v127 >> 8));
  }
  v128 = 0;
  if ( a2 )
  {
    v129 = v6[1];
    do
    {
      v130 = *((_BYTE *)v7 + v128++);
      v131 = (_DWORD *)(v129 + 8 * (unsigned __int8)(v130 ^ v10));
      v10 = *v131 ^ ((v9 << 24) | (v10 >> 8));
      v9 = v131[1] ^ (v9 >> 8);
    }
    while ( v128 < a2 );
  }
  return v8 ^ v10;
}
