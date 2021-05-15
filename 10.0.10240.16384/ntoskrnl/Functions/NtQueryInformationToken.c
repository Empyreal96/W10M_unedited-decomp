// NtQueryInformationToken 
 
int __fastcall NtQueryInformationToken(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  int *v6; // r6
  int v8; // r10
  unsigned int v9; // r1
  unsigned int v10; // r1
  _DWORD *v11; // r4
  _DWORD *v12; // r2
  int v13; // r0
  int v14; // r5
  int v15; // r3
  _DWORD *v16; // r10
  unsigned int v17; // r9
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  _DWORD *v21; // r0
  int v22; // r4
  int *v23; // r3
  int i; // r8
  unsigned int v25; // r0
  unsigned int v26; // r2
  int v27; // r0
  unsigned int v28; // r1
  __int16 v29; // r3
  int v30; // r0
  int v31; // r3
  _DWORD *v32; // r9
  unsigned int v33; // r0
  unsigned int v34; // r2
  int *v35; // r1
  unsigned int v36; // r0
  int v37; // t1
  int v38; // r0
  unsigned int v39; // r1
  __int16 v40; // r3
  int v41; // r0
  unsigned int v42; // r1
  __int16 v43; // r3
  int v44; // r3
  int v45; // r1
  unsigned int v46; // r2
  int *v47; // r0
  int v48; // t1
  int v49; // r0
  unsigned int v50; // r1
  __int16 v51; // r3
  int v52; // r0
  unsigned int v53; // r1
  __int16 v54; // r3
  int v55; // r3
  _DWORD *v56; // r9
  unsigned int v57; // r0
  unsigned int v58; // lr
  int v59; // r10
  int v60; // r3
  unsigned int v61; // r3
  int v62; // r0
  unsigned int v63; // r1
  __int16 v64; // r3
  int v65; // r0
  unsigned int v66; // r1
  __int16 v67; // r3
  int v68; // r3
  unsigned int v69; // lr
  int v70; // r0
  unsigned int v71; // r1
  __int16 v72; // r3
  int v73; // r1
  unsigned int v74; // r2
  int v75; // r0
  unsigned int v76; // r1
  __int16 v77; // r3
  int v78; // r3
  unsigned int v79; // r0
  int v80; // r0
  unsigned int v81; // r1
  __int16 v82; // r3
  int v83; // r1
  unsigned int v84; // r2
  int v85; // r0
  unsigned int v86; // r1
  __int16 v87; // r3
  unsigned int v88; // r10
  int v89; // r3
  int v90; // r3
  int v91; // r0
  unsigned int v92; // r1
  __int16 v93; // r3
  int v94; // r0
  int v95; // r0
  unsigned int v96; // r1
  __int16 v97; // r3
  _DWORD *v98; // r4
  int v99; // r1
  int v100; // r2
  int v101; // r3
  int v102; // r3
  unsigned int v103; // r2
  int v104; // lr
  int v105; // r3
  int v106; // r8
  unsigned int j; // r0
  int v108; // r0
  unsigned int v109; // r1
  __int16 v110; // r3
  int v111; // r3
  _DWORD *v112; // r9
  unsigned int v113; // r0
  int v114; // lr
  int v115; // r10
  int v116; // r9
  int v117; // r2
  int v118; // lr
  int *v119; // r1
  int v120; // t1
  int v121; // r2
  int v122; // r10
  int *v123; // r1
  int v124; // t1
  unsigned int v125; // r3
  int v126; // r1
  int v127; // r0
  unsigned int v128; // r1
  __int16 v129; // r3
  int *v130; // r4
  int v131; // r3
  int v132; // r8
  int v133; // r0
  unsigned int v134; // r1
  __int16 v135; // r3
  int v136; // r3
  int v137; // r10
  unsigned int v138; // r0
  int v139; // r0
  unsigned int v140; // r1
  __int16 v141; // r3
  unsigned int v142; // r2
  int v143; // r0
  unsigned int v144; // r1
  int v145; // r3
  int v146; // r8
  int v147; // r3
  _DWORD *v148; // r9
  int v149; // r10
  unsigned int *v150; // r0
  unsigned int k; // r1
  unsigned int v152; // r2
  int v153; // r4
  int v154; // r3
  int v155; // r8
  unsigned int v156; // r9
  int *v157; // r4
  unsigned int v158; // r1
  unsigned __int8 *v159; // r0
  int v160; // r2
  int *v161; // r0
  int v162; // t1
  int v163; // r0
  unsigned int v164; // r1
  __int16 v165; // r3
  int v166; // r3
  int v167; // r3
  int v168; // r8
  unsigned int v169; // r2
  int v170; // r3
  int v171; // r0
  unsigned int v172; // r1
  __int16 v173; // r3
  int v174; // r3
  int v175; // r1
  unsigned int v176; // r3
  int v177; // r0
  unsigned int v178; // r1
  __int16 v179; // r3
  int v180; // r3
  int v181; // r1
  unsigned int v182; // r2
  int *v183; // r0
  int v184; // t1
  int v185; // r0
  unsigned int v186; // r1
  __int16 v187; // r3
  int v188; // r3
  unsigned int v189; // r3
  int v190; // r0
  unsigned int v191; // r1
  __int16 v192; // r3
  int v193; // r6
  unsigned int v194; // r2
  int v195; // r10
  unsigned int v196; // r0
  unsigned int v197; // lr
  int v198; // r2
  int v199; // r0
  unsigned int v200; // r1
  __int16 v201; // r3
  unsigned int v202; // r3
  int v203; // r0
  unsigned int v204; // r1
  __int16 v205; // r3
  int v206; // r3
  _DWORD *v207; // r10
  int v208; // r2
  int *v209; // r9
  unsigned int v210; // r1
  int v211; // r0
  unsigned int v212; // r1
  __int16 v213; // r3
  int v214; // r4
  int v215; // r0
  unsigned int v216; // r1
  __int16 v217; // r3
  unsigned int v218; // r2
  int *v219; // r3
  int v220; // r0
  unsigned int v221; // r2
  int *v222; // r1
  int v223; // lr
  int v224; // t1
  int v225; // r0
  unsigned int v226; // r1
  __int16 v227; // r3
  int v228; // r3
  int *v229; // r0
  unsigned int v230; // r3
  int v231; // r0
  unsigned int v232; // r1
  __int16 v233; // r3
  int v234; // r4
  int v235; // r0
  unsigned int v236; // r1
  __int16 v237; // r3
  int v238; // r3
  int v239; // r2
  int v240; // lr
  int v241; // r1
  unsigned int v242; // r3
  int v243; // r0
  unsigned int v244; // r1
  __int16 v245; // r3
  char v247[4]; // [sp+30h] [bp-A0h] BYREF
  _DWORD *v248; // [sp+34h] [bp-9Ch] BYREF
  int v249; // [sp+38h] [bp-98h] BYREF
  unsigned int v250[2]; // [sp+3Ch] [bp-94h] BYREF
  int v251; // [sp+44h] [bp-8Ch] BYREF
  char v252; // [sp+48h] [bp-88h]
  int v253; // [sp+4Ch] [bp-84h] BYREF
  int v254; // [sp+50h] [bp-80h]
  int *v255; // [sp+54h] [bp-7Ch] BYREF
  int v256; // [sp+58h] [bp-78h] BYREF
  int v257; // [sp+5Ch] [bp-74h] BYREF
  _DWORD v258[2]; // [sp+60h] [bp-70h] BYREF
  int v259; // [sp+68h] [bp-68h] BYREF
  int v260; // [sp+6Ch] [bp-64h] BYREF
  int v261; // [sp+70h] [bp-60h] BYREF
  int v262; // [sp+74h] [bp-5Ch] BYREF
  int v263; // [sp+78h] [bp-58h] BYREF
  int v264; // [sp+80h] [bp-50h] BYREF
  int *v265; // [sp+84h] [bp-4Ch] BYREF
  int **v266; // [sp+88h] [bp-48h]
  int v267; // [sp+8Ch] [bp-44h]
  int *v268; // [sp+90h] [bp-40h] BYREF
  int **v269; // [sp+94h] [bp-3Ch]
  _DWORD _98[20]; // [sp+98h] [bp-38h] BYREF

  _98[19] = a4;
  v6 = (int *)a3;
  _98[18] = a3;
  _98[17] = a2;
  v253 = a1;
  _98[16] = a1;
  v259 = 0;
  v261 = 0;
  v251 = 0;
  v264 = 0;
  v265 = 0;
  v266 = 0;
  v267 = 0;
  v268 = 0;
  v269 = 0;
  v247[0] = 0;
  v249 = 0;
  v252 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v8 = v252;
  if ( v252 )
  {
    if ( a4 )
    {
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v9 = a3 + a4 - 1;
      if ( a3 > v9 || v9 >= MmUserProbeAddress )
        ExRaiseAccessViolation();
      v10 = (v9 & 0xFFFFF000) + 4096;
      do
      {
        *(_BYTE *)a3 = *(_BYTE *)a3;
        a3 = (a3 & 0xFFFFF000) + 4096;
      }
      while ( a3 != v10 );
    }
    v11 = (_DWORD *)a5;
    v12 = (_DWORD *)a5;
    if ( a5 >= MmUserProbeAddress )
      v12 = (_DWORD *)MmUserProbeAddress;
    *v12 = *v12;
  }
  else
  {
    v11 = (_DWORD *)a5;
  }
  switch ( a2 )
  {
    case 1:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v15 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v15 & 0xFFFFFFC0) + 0x134);
      v16 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v17 = 4 * (*(unsigned __int8 *)(*(_DWORD *)v16[37] + 1) + 4);
      v250[0] = v17;
      *v11 = v17;
      if ( a4 < v17 )
      {
        v18 = ExReleaseResourceLite(v16[12]);
        v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v20 = *(_WORD *)(v19 + 0x134) + 1;
        *(_WORD *)(v19 + 308) = v20;
        if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
          KiCheckForKernelApcDelivery(v18);
        v21 = v16;
        goto LABEL_23;
      }
      v22 = (int)(v6 + 2);
      v23 = (int *)v16[37];
      v255 = v23;
      for ( i = 0; !i; i = 1 )
      {
        v25 = 4 * (*(unsigned __int8 *)(*v23 + 1) + 2);
        v251 = (v25 + 3) & 0xFFFFFFFC;
        if ( v25 > v17 )
          goto LABEL_32;
        v17 -= (v25 + 3) & 0xFFFFFFFC;
        *v6 = v22;
        v6[1] = v23[1];
        v26 = 4 * (*(unsigned __int8 *)(*v23 + 1) + 2);
        if ( v26 <= v25 )
          memmove(v22, *v23, v26);
        v22 += v251;
        v23 = v255;
      }
      v249 = v17;
LABEL_32:
      v27 = ExReleaseResourceLite(v16[12]);
      v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v29 = *(_WORD *)(v28 + 0x134) + 1;
      *(_WORD *)(v28 + 308) = v29;
      if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
        KiCheckForKernelApcDelivery(v27);
      goto LABEL_36;
    case 2:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v31 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v31 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v33 = v32[31];
      v34 = 8 * (v33 - 2) + 12;
      v250[0] = v34;
      if ( v33 > 1 )
      {
        v35 = (int *)(v32[37] + 8);
        v36 = v33 - 1;
        do
        {
          v37 = *v35;
          v35 += 2;
          v34 += 4 * (*(unsigned __int8 *)(v37 + 1) + 2);
          --v36;
        }
        while ( v36 );
        v250[0] = v34;
      }
      *v11 = v34;
      if ( a4 < v34 )
      {
        v38 = ExReleaseResourceLite(v32[12]);
        v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v40 = *(_WORD *)(v39 + 0x134) + 1;
        *(_WORD *)(v39 + 308) = v40;
        if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
          KiCheckForKernelApcDelivery(v38);
        goto LABEL_430;
      }
      *v6 = v32[31] - 1;
      RtlCopySidAndAttributesArray(v32[31] - 1, v32[37] + 8);
      v41 = ExReleaseResourceLite(v32[12]);
      v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v43 = *(_WORD *)(v42 + 0x134) + 1;
      *(_WORD *)(v42 + 308) = v43;
      if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
        KiCheckForKernelApcDelivery(v41);
      goto LABEL_52;
    case 3:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v55 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v55 & 0xFFFFFFC0) + 0x134);
      v56 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v57 = 0;
      v58 = 0;
      v59 = v56[16];
      v251 = v56[17];
      do
      {
        if ( (1 << (v58 - 32)) & v251 | (1 << v58) & v59 )
          ++v57;
        ++v58;
      }
      while ( v58 <= 0x23 );
      if ( v57 <= 1 )
        v60 = 0;
      else
        v60 = 12 * (v57 - 1);
      v61 = v60 + 16;
      v250[0] = v61;
      v32 = v248;
      *v11 = v61;
      if ( a4 < v61 )
      {
        v62 = ExReleaseResourceLite(v32[12]);
        v63 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v64 = *(_WORD *)(v63 + 0x134) + 1;
        *(_WORD *)(v63 + 308) = v64;
        if ( !v64 && *(_DWORD *)(v63 + 100) != v63 + 100 && !*(_WORD *)(v63 + 310) )
          KiCheckForKernelApcDelivery(v62);
        goto LABEL_430;
      }
      SepConvertTokenPrivileges((int)v32, v6);
      v65 = ExReleaseResourceLite(v32[12]);
      v66 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v67 = *(_WORD *)(v66 + 0x134) + 1;
      *(_WORD *)(v66 + 308) = v67;
      if ( !v67 && *(_DWORD *)(v66 + 100) != v66 + 100 && !*(_WORD *)(v66 + 310) )
        KiCheckForKernelApcDelivery(v65);
      goto LABEL_133;
    case 4:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v68 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v68 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v69 = 4 * (*(unsigned __int8 *)(*(_DWORD *)(v32[37] + 8 * v32[36]) + 1) + 3);
      v250[0] = v69;
      *v11 = v69;
      if ( a4 < v69 )
      {
        v70 = ExReleaseResourceLite(v32[12]);
        v71 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v72 = *(_WORD *)(v71 + 0x134) + 1;
        *(_WORD *)(v71 + 308) = v72;
        if ( !v72 && *(_DWORD *)(v71 + 100) != v71 + 100 && !*(_WORD *)(v71 + 310) )
          KiCheckForKernelApcDelivery(v70);
        goto LABEL_430;
      }
      *v6 = (int)(v6 + 1);
      v73 = *(_DWORD *)(v32[37] + 8 * v32[36]);
      v74 = 4 * (*(unsigned __int8 *)(v73 + 1) + 2);
      if ( v74 <= v69 - 4 )
        memmove((int)(v6 + 1), v73, v74);
      v75 = ExReleaseResourceLite(v32[12]);
      v76 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v77 = *(_WORD *)(v76 + 0x134) + 1;
      *(_WORD *)(v76 + 308) = v77;
      if ( !v77 && *(_DWORD *)(v76 + 100) != v76 + 100 && !*(_WORD *)(v76 + 310) )
        KiCheckForKernelApcDelivery(v75);
      goto LABEL_133;
    case 5:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v78 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v78 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v79 = 4 * (*(unsigned __int8 *)(v32[39] + 1) + 3);
      v250[0] = v79;
      *v11 = v79;
      if ( a4 < v79 )
      {
        v80 = ExReleaseResourceLite(v32[12]);
        v81 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v82 = *(_WORD *)(v81 + 0x134) + 1;
        *(_WORD *)(v81 + 308) = v82;
        if ( !v82 && *(_DWORD *)(v81 + 100) != v81 + 100 && !*(_WORD *)(v81 + 310) )
          KiCheckForKernelApcDelivery(v80);
        goto LABEL_430;
      }
      *v6 = (int)(v6 + 1);
      v83 = v32[39];
      v84 = 4 * (*(unsigned __int8 *)(v83 + 1) + 2);
      if ( v84 <= v79 - 4 )
        memmove((int)(v6 + 1), v83, v84);
      v85 = ExReleaseResourceLite(v32[12]);
      v86 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v87 = *(_WORD *)(v86 + 0x134) + 1;
      *(_WORD *)(v86 + 308) = v87;
      if ( !v87 && *(_DWORD *)(v86 + 100) != v86 + 100 && !*(_WORD *)(v86 + 310) )
        KiCheckForKernelApcDelivery(v85);
      goto LABEL_133;
    case 6:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v88 = 4;
      v250[0] = 4;
      v89 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v89 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v90 = v32[41];
      if ( v90 )
      {
        v88 = *(unsigned __int16 *)(v90 + 2) + 4;
        v250[0] = v88;
      }
      *v11 = v88;
      if ( a4 < v88 )
      {
        v91 = ExReleaseResourceLite(v32[12]);
        v92 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v93 = *(_WORD *)(v92 + 0x134) + 1;
        *(_WORD *)(v92 + 308) = v93;
        if ( !v93 && *(_DWORD *)(v92 + 100) != v92 + 100 && !*(_WORD *)(v92 + 310) )
          KiCheckForKernelApcDelivery(v91);
        goto LABEL_430;
      }
      v94 = (int)(v6 + 1);
      if ( v32[41] )
      {
        *v6 = v94;
        memmove(v94, v32[41], *(unsigned __int16 *)(v32[41] + 2));
      }
      else
      {
        *v6 = 0;
      }
      v95 = ExReleaseResourceLite(v32[12]);
      v96 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v97 = *(_WORD *)(v96 + 0x134) + 1;
      *(_WORD *)(v96 + 308) = v97;
      if ( !v97 && *(_DWORD *)(v96 + 100) != v96 + 100 && !*(_WORD *)(v96 + 310) )
        KiCheckForKernelApcDelivery(v95);
      goto LABEL_133;
    case 7:
      v13 = SepReferenceTokenByHandle(a1, 16, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 16;
      v98 = v248;
      if ( a4 < 0x10 )
        goto LABEL_136;
      v99 = v248[1];
      v100 = v248[2];
      v101 = v248[3];
      *v6 = *v248;
      v6[1] = v99;
      v6[2] = v100;
      v6[3] = v101;
      goto LABEL_138;
    case 8:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      v98 = v248;
      if ( a4 < 4 )
        goto LABEL_136;
      *v6 = v248[42];
      goto LABEL_138;
    case 9:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v32 = v248;
      if ( v248[42] != 2 )
      {
        ObfDereferenceObject((int)v248);
        return -1073741821;
      }
      *v11 = 4;
      if ( a4 < 4 )
        goto LABEL_430;
      *v6 = v32[43];
LABEL_52:
      v30 = (int)v32;
      goto LABEL_53;
    case 10:
      v251 = (int)v6;
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 56;
      v98 = v248;
      if ( a4 < 0x38 )
        goto LABEL_136;
      v103 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v103 + 308);
      ExAcquireResourceSharedLite(v98[12], 1);
      *v6 = v98[4];
      v6[1] = v98[5];
      v6[2] = v98[6];
      v6[3] = v98[7];
      v6[4] = v98[10];
      v6[5] = v98[11];
      v6[6] = v98[42];
      v6[7] = v98[43];
      v6[8] = v98[34];
      v104 = v98[34] - 4 * *(unsigned __int8 *)(v98[39] + 1) - 8;
      v105 = v98[41];
      if ( v105 )
        v104 -= *(unsigned __int16 *)(v105 + 2);
      v6[9] = v104;
      v6[10] = v98[31] - 1;
      v106 = 0;
      for ( j = 0; j <= 0x23; ++j )
      {
        if ( v98[17] & (1 << (j - 32)) | (1 << j) & v98[16] )
          ++v106;
      }
      v6[11] = v106;
      v6[12] = v98[13];
      v6[13] = v98[14];
      v108 = ExReleaseResourceLite(v98[12]);
      v109 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v110 = *(_WORD *)(v109 + 0x134) + 1;
      *(_WORD *)(v109 + 308) = v110;
      if ( !v110 && *(_DWORD *)(v109 + 100) != v109 + 100 && !*(_WORD *)(v109 + 310) )
        KiCheckForKernelApcDelivery(v108);
      v30 = (int)v98;
      goto LABEL_53;
    case 11:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v44 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v44 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v45 = v32[32];
      v46 = 8 * v45 + 4;
      v250[0] = v46;
      if ( v45 )
      {
        v47 = (int *)v32[38];
        do
        {
          v48 = *v47;
          v47 += 2;
          v46 += 4 * (*(unsigned __int8 *)(v48 + 1) + 2);
          --v45;
        }
        while ( v45 );
        v250[0] = v46;
      }
      *v11 = v46;
      if ( a4 < v46 )
      {
        v49 = ExReleaseResourceLite(v32[12]);
        v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v51 = *(_WORD *)(v50 + 0x134) + 1;
        *(_WORD *)(v50 + 308) = v51;
        if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
          KiCheckForKernelApcDelivery(v49);
        goto LABEL_430;
      }
      *v6 = v32[32];
      RtlCopySidAndAttributesArray(v32[32], v32[38]);
      v52 = ExReleaseResourceLite(v32[12]);
      v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v54 = *(_WORD *)(v53 + 0x134) + 1;
      *(_WORD *)(v53 + 308) = v54;
      if ( !v54 && *(_DWORD *)(v53 + 100) != v53 + 100 && !*(_WORD *)(v53 + 310) )
        KiCheckForKernelApcDelivery(v52);
LABEL_133:
      ObfDereferenceObject((int)v32);
      return 0;
    case 12:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      v16 = v248;
      v21 = v248;
      if ( a4 >= 4 )
      {
        SeQuerySessionIdToken((int)v248, &v251);
        *v6 = v251;
        *v11 = 4;
        goto LABEL_36;
      }
LABEL_23:
      ObfDereferenceObject((int)v21);
      return -1073741789;
    case 13:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v111 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v111 & 0xFFFFFFC0) + 0x134);
      v112 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v249 = 0;
      v257 = 0;
      v113 = 0;
      v114 = v112[16];
      v115 = v112[17];
      v116 = 0;
      do
      {
        if ( (1 << (v113 - 32)) & v115 | (1 << v113) & v114 )
          v257 = ++v116;
        ++v113;
      }
      while ( v113 <= 0x23 );
      v249 = v116;
      v32 = v248;
      v256 = 12 * v249;
      v263 = 12 * v249;
      v117 = v248[31];
      v255 = (int *)(8 * v117);
      v262 = 8 * v117;
      v118 = 8 * v117;
      v253 = 8 * v117;
      if ( v117 )
      {
        v119 = (int *)v248[37];
        do
        {
          v120 = *v119;
          v119 += 2;
          v118 += (4 * *(unsigned __int8 *)(v120 + 1) + 11) & 0xFFFFFFFC;
          --v117;
        }
        while ( v117 );
        v253 = v118;
      }
      v121 = v248[32];
      v251 = 8 * v121;
      v258[0] = 8 * v121;
      v122 = 8 * v121;
      v260 = 8 * v121;
      if ( v121 )
      {
        v123 = (int *)v248[38];
        do
        {
          v124 = *v123;
          v123 += 2;
          v122 += (4 * *(unsigned __int8 *)(v124 + 1) + 11) & 0xFFFFFFFC;
          --v121;
        }
        while ( v121 );
        v260 = v122;
      }
      v125 = v122 + v118 + v256 + 44;
      v250[0] = v125;
      *v11 = v125;
      v126 = v249;
      if ( a4 < v125 )
      {
        v127 = ExReleaseResourceLite(v32[12]);
        v128 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v129 = *(_WORD *)(v128 + 0x134) + 1;
        *(_WORD *)(v128 + 308) = v129;
        if ( !v129 && *(_DWORD *)(v128 + 100) != v128 + 100 && !*(_WORD *)(v128 + 310) )
          KiCheckForKernelApcDelivery(v127);
        goto LABEL_430;
      }
      v6[9] = v32[6];
      v6[10] = v32[7];
      v6[1] = v118;
      *v6 = v32[31];
      v130 = v6 + 11;
      v6[2] = (int)(v6 + 11);
      v6[4] = v122;
      v6[3] = v32[32];
      if ( v32[32] )
      {
        v131 = (int)v130 + ((v118 + 3) & 0xFFFFFFFC);
        v259 = v131;
      }
      else
      {
        v131 = 0;
      }
      v6[5] = v131;
      v6[7] = v256;
      v6[6] = v126;
      v132 = (int)v130 + v122 + v118;
      v6[8] = v132;
      RtlCopySidAndAttributesArray(v32[31], v32[37]);
      if ( v259 )
        RtlCopySidAndAttributesArray(v32[32], v32[38]);
      SepConvertTokenPrivilegesToLuidAndAttributes(v32, v132);
      goto LABEL_196;
    case 15:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      if ( a4 < 4 )
        return -1073741789;
      v98 = v248;
      *v6 = (v248[44] & 0x40) != 0;
      goto LABEL_212;
    case 16:
      if ( !SeSinglePrivilegeCheck(SeSecurityPrivilege, SHIDWORD(SeSecurityPrivilege), v8, (int)&SeSecurityPrivilege) )
        return -1073741727;
      v13 = SepReferenceTokenByHandle(v253, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 30;
      v98 = v248;
      if ( a4 < 0x1E )
      {
LABEL_136:
        ObfDereferenceObject((int)v98);
        return -1073741789;
      }
      v142 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v142 + 308);
      ExAcquireResourceSharedLite(v98[12], 1);
      *v6 = v98[22];
      v6[1] = v98[23];
      v6[2] = v98[24];
      v6[3] = v98[25];
      v6[4] = v98[26];
      v6[5] = v98[27];
      v6[6] = v98[28];
      *((_WORD *)v6 + 14) = *((_WORD *)v98 + 58);
      v143 = ExReleaseResourceLite(v98[12]);
      v144 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v145 = (__int16)(*(_WORD *)(v144 + 0x134) + 1);
      *(_WORD *)(v144 + 308) = v145;
      if ( v145 || *(_DWORD *)(v144 + 100) == v144 + 100 || *(_WORD *)(v144 + 310) )
        goto LABEL_212;
      KiCheckForKernelApcDelivery(v143);
      v30 = (int)v98;
      goto LABEL_53;
    case 17:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 8;
      v98 = v248;
      if ( a4 < 8 )
        goto LABEL_136;
      *v6 = v248[49];
      v6[1] = v98[50];
      goto LABEL_212;
    case 18:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      v98 = v248;
      if ( a4 < 4 )
        goto LABEL_136;
      v102 = *(_DWORD *)(v248[48] + 24);
      if ( (v102 & 4) != 0 )
      {
        *v6 = 3;
      }
      else if ( (v102 & 2) != 0 )
      {
        *v6 = 2;
      }
      else
      {
        *v6 = 1;
      }
LABEL_138:
      ObfDereferenceObject((int)v98);
      return 0;
    case 19:
      v255 = 0;
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      v98 = v248;
      if ( a4 != 4 )
      {
        ObfDereferenceObject((int)v248);
        return -1073741820;
      }
      if ( SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v8, (int)&SeSecurityPrivilege) )
        v251 = 1;
      else
        v251 = 2;
      v146 = SepReferenceLogonSessionSilo((_DWORD *)(v98[48] + 12), *(_DWORD *)(v98[48] + 88), v258);
      if ( v146 < 0 )
        goto LABEL_232;
      _98[0] = 24;
      _98[1] = 0;
      if ( v8 )
        v147 = 0;
      else
        v147 = 512;
      _98[3] = v147;
      _98[2] = 0;
      _98[4] = 0;
      _98[5] = 0;
      v148 = (_DWORD *)v258[0];
      v149 = SepDuplicateToken(*(_DWORD *)(v258[0] + 32), (int)_98, 0, v251, 1, 0, 0, (int *)&v255);
      v150 = v148 + 5;
      __pld(v148 + 5);
      for ( k = v148[5]; (int)(k - 1) > 0; k = v152 )
      {
        __dmb(0xBu);
        do
          v152 = __ldrex(v150);
        while ( v152 == k && __strex(k - 1, v150) );
        if ( v152 == k )
          goto LABEL_246;
      }
      if ( k != 1 )
        __fastfail(0xEu);
      v258[0] = v148[1];
      v258[1] = v148[2];
      SepDeReferenceLogonSession(v258, v148[22]);
LABEL_246:
      if ( v149 < 0 )
      {
        ObfDereferenceObject((int)v98);
        return v149;
      }
      v146 = ObInsertObject((int)v255, 0, 983551, 0, 0, (int)&v257);
      if ( v146 < 0 )
      {
LABEL_232:
        ObfDereferenceObject((int)v98);
        return v146;
      }
      *v6 = v257;
      goto LABEL_212;
    case 20:
      v249 = 0;
      v247[0] = 0;
      *v11 = 4;
      v153 = 0;
      if ( a4 != 4 )
        return -1073741820;
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v154 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v154 & 0xFFFFFFC0) + 0x134);
      v16 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      if ( v16[16] & 0x20160684 | v16[17] & 1 )
        v153 = 1;
      v249 = v153;
      v155 = 0;
      v156 = v16[31];
      if ( !v156 )
        goto LABEL_270;
      while ( 2 )
      {
        if ( !v153 )
        {
          v157 = (int *)(v16[37] + 8 * v155);
          if ( (v157[1] & 0x30) == 0 )
          {
            if ( !*(_BYTE *)RtlSubAuthorityCountSid(*v157) )
            {
              v158 = 0;
              goto LABEL_263;
            }
            v159 = (unsigned __int8 *)RtlSubAuthorityCountSid(*v157);
            v158 = *(_DWORD *)RtlSubAuthoritySid(*v157, *v159 - 1);
            if ( v158 <= 0x239 )
            {
LABEL_263:
              v160 = 0;
              v161 = &SepLUARids;
              while ( 1 )
              {
                v162 = *v161++;
                if ( v158 == v162 )
                  break;
                if ( (unsigned int)++v160 >= 0x13 )
                  goto LABEL_268;
              }
              v153 = 1;
              v249 = 1;
LABEL_269:
              if ( ++v155 >= v156 )
                break;
              continue;
            }
          }
LABEL_268:
          v153 = v249;
          goto LABEL_269;
        }
        break;
      }
LABEL_270:
      v163 = ExReleaseResourceLite(v16[12]);
      v164 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v165 = *(_WORD *)(v164 + 0x134) + 1;
      *(_WORD *)(v164 + 308) = v165;
      if ( !v165 && *(_DWORD *)(v164 + 100) != v164 + 100 && !*(_WORD *)(v164 + 310) )
        KiCheckForKernelApcDelivery(v163);
      *v6 = v153;
LABEL_36:
      v30 = (int)v16;
      goto LABEL_53;
    case 21:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 1;
      v98 = v248;
      if ( !a4 )
        goto LABEL_136;
      *(_BYTE *)v6 = (v248[44] & 0x810) != 0;
      goto LABEL_212;
    case 22:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v136 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v136 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v137 = v249;
      v258[0] = (unsigned __int8)v247[0];
      v138 = SepGetTokenAccessInformationBufferSize(
               v32,
               (unsigned __int8)v247[0],
               v249,
               &v251,
               &v253,
               &v259,
               &v260,
               &v256,
               (unsigned int *)&v261,
               &v257,
               &v255,
               (unsigned int *)&v263,
               &v262);
      v250[0] = v138;
      *v11 = v138;
      if ( a4 >= v138 )
      {
        SepCopyTokenAccessInformation(
          v32,
          v6,
          a4,
          v251,
          v253,
          v259,
          v260,
          v256,
          v261,
          v257,
          (int)v255,
          v263,
          v262,
          v258[0],
          v137);
        goto LABEL_196;
      }
      v139 = ExReleaseResourceLite(v32[12]);
      v140 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v141 = *(_WORD *)(v140 + 0x134) + 1;
      *(_WORD *)(v140 + 308) = v141;
      if ( !v141 && *(_DWORD *)(v140 + 100) != v140 + 100 && !*(_WORD *)(v140 + 310) )
        KiCheckForKernelApcDelivery(v139);
      goto LABEL_430;
    case 23:
    case 24:
    case 26:
    case 40:
    case 42:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      v98 = v248;
      if ( a4 < 4 )
        goto LABEL_136;
      v166 = v248[44];
      switch ( a2 )
      {
        case 23:
          if ( (v166 & 0x200) != 0 )
            goto LABEL_290;
          break;
        case 24:
          if ( (v166 & 0x400) != 0 )
            goto LABEL_290;
          break;
        case 26:
          if ( (v166 & 0x1000) != 0 )
            goto LABEL_290;
          break;
        case 40:
          if ( (v166 & 0x18) != 0 )
          {
            v167 = 1;
            goto LABEL_292;
          }
          break;
        default:
          if ( (v166 & 0x10000) != 0 )
          {
LABEL_290:
            v167 = 1;
            goto LABEL_292;
          }
          break;
      }
      v167 = 0;
LABEL_292:
      *v6 = v167;
LABEL_212:
      v30 = (int)v98;
LABEL_53:
      ObfDereferenceObject(v30);
      return 0;
    case 25:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v188 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v188 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      SepCopyTokenIntegrity((int)v32, v258);
      v189 = 4 * (*(unsigned __int8 *)(v258[0] + 1) + 4);
      v250[0] = v189;
      *v11 = v189;
      if ( a4 >= v189 )
      {
        RtlCopySidAndAttributesArray(1, v258);
        goto LABEL_196;
      }
      v190 = ExReleaseResourceLite(v32[12]);
      v191 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v192 = *(_WORD *)(v191 + 0x134) + 1;
      *(_WORD *)(v191 + 308) = v192;
      if ( !v192 && *(_DWORD *)(v191 + 100) != v191 + 100 && !*(_WORD *)(v191 + 310) )
        KiCheckForKernelApcDelivery(v190);
      goto LABEL_430;
    case 27:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      v254 = v13;
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      v98 = v248;
      if ( a4 < 4 )
        goto LABEL_136;
      v193 = SeQueryMandatoryPolicyToken((int)v248, v6);
      v254 = v193;
      ObfDereferenceObject((int)v98);
      return v193;
    case 28:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v194 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v194 + 308);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v195 = 0;
      v196 = 0;
      v251 = 0;
      v197 = v32[31];
      if ( !v197 )
        goto LABEL_350;
      v198 = v32[37];
      while ( (*(_DWORD *)(v198 + 4) & 0xC0000000) != -1073741824 )
      {
        v251 = ++v196;
        v198 += 8;
        if ( v196 >= v197 )
          goto LABEL_350;
      }
      v195 = *(_DWORD *)(v32[37] + 8 * v196);
LABEL_350:
      if ( !v195 )
      {
        v199 = ExReleaseResourceLite(v32[12]);
        v200 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v201 = *(_WORD *)(v200 + 0x134) + 1;
        *(_WORD *)(v200 + 308) = v201;
        if ( !v201 && *(_DWORD *)(v200 + 100) != v200 + 100 && !*(_WORD *)(v200 + 310) )
          KiCheckForKernelApcDelivery(v199);
        ObfDereferenceObject((int)v32);
        return -1073741275;
      }
      v202 = 4 * (*(unsigned __int8 *)(*(_DWORD *)(v32[37] + 8 * v196) + 1) + 5);
      v250[0] = v202;
      *v11 = v202;
      if ( a4 < v202 )
      {
        v203 = ExReleaseResourceLite(v32[12]);
        v204 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v205 = *(_WORD *)(v204 + 0x134) + 1;
        *(_WORD *)(v204 + 308) = v205;
        if ( !v205 && *(_DWORD *)(v204 + 100) != v204 + 100 && !*(_WORD *)(v204 + 310) )
          KiCheckForKernelApcDelivery(v203);
LABEL_430:
        ObfDereferenceObject((int)v32);
        return -1073741789;
      }
      *v6 = 1;
      RtlCopySidAndAttributesArray(1, v32[37] + 8 * v196);
LABEL_196:
      v133 = ExReleaseResourceLite(v32[12]);
      v134 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v135 = *(_WORD *)(v134 + 0x134) + 1;
      *(_WORD *)(v134 + 308) = v135;
      if ( !v135 && *(_DWORD *)(v134 + 100) != v134 + 100 && !*(_WORD *)(v134 + 310) )
        KiCheckForKernelApcDelivery(v133);
      v30 = (int)v32;
      goto LABEL_53;
    case 29:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      v98 = v248;
      if ( a4 < 4 )
        goto LABEL_136;
      *v6 = (v248[44] & 0x4000) != 0;
      goto LABEL_212;
    case 30:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v180 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v180 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v181 = v32[122];
      v182 = 8 * v181 + 4;
      v250[0] = v182;
      if ( v181 )
      {
        v183 = (int *)v32[121];
        do
        {
          v184 = *v183;
          v183 += 2;
          v182 += 4 * (*(unsigned __int8 *)(v184 + 1) + 2);
          --v181;
        }
        while ( v181 );
        v250[0] = v182;
      }
      *v11 = v182;
      if ( a4 >= v182 )
      {
        *v6 = v32[122];
        RtlCopySidAndAttributesArray(v32[122], v32[121]);
        goto LABEL_196;
      }
      v185 = ExReleaseResourceLite(v32[12]);
      v186 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v187 = *(_WORD *)(v186 + 0x134) + 1;
      *(_WORD *)(v186 + 308) = v187;
      if ( !v187 && *(_DWORD *)(v186 + 100) != v186 + 100 && !*(_WORD *)(v186 + 310) )
        KiCheckForKernelApcDelivery(v185);
      goto LABEL_430;
    case 31:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v174 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v174 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v175 = v32[120];
      v253 = v175;
      if ( v175 )
        v176 = 4 * (*(unsigned __int8 *)(v175 + 1) + 3);
      else
        v176 = 4;
      v250[0] = v176;
      *v11 = v176;
      if ( a4 < v176 )
      {
        v177 = ExReleaseResourceLite(v32[12]);
        v178 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v179 = *(_WORD *)(v178 + 0x134) + 1;
        *(_WORD *)(v178 + 308) = v179;
        if ( !v179 && *(_DWORD *)(v178 + 100) != v178 + 100 && !*(_WORD *)(v178 + 310) )
          KiCheckForKernelApcDelivery(v177);
        goto LABEL_430;
      }
      if ( v175 )
        v175 = (int)(v6 + 1);
      *v6 = v175;
      if ( v175 )
        RtlCopySid(v176 - 4, v175, v32[120]);
      goto LABEL_196;
    case 32:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      *v11 = 4;
      v98 = v248;
      if ( a4 < 4 )
        goto LABEL_136;
      v168 = 0;
      v169 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v169 + 308);
      ExAcquireResourceSharedLite(v98[12], 1);
      v170 = v98[157];
      if ( v170 )
        v168 = *(_DWORD *)(v170 + 20);
      v171 = ExReleaseResourceLite(v98[12]);
      v172 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v173 = *(_WORD *)(v172 + 0x134) + 1;
      *(_WORD *)(v172 + 308) = v173;
      if ( !v173 && *(_DWORD *)(v172 + 100) != v172 + 100 && !*(_WORD *)(v172 + 310) )
        KiCheckForKernelApcDelivery(v171);
      *v6 = v168;
      goto LABEL_212;
    case 33:
    case 34:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      v254 = v13;
      if ( v13 < 0 )
        return v13;
      v206 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v206 & 0xFFFFFFC0) + 0x134);
      v207 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v208 = v207[159];
      if ( v208 && ((v258[0] = *(_DWORD *)(v208 + 288)) != 0 || a2 != 33) && (*(_DWORD *)(v208 + 292) || a2 != 34) )
      {
        if ( a2 == 33 )
        {
          v209 = (int *)v258[0];
          v256 = v258[0];
        }
        else
        {
          v209 = *(int **)(v208 + 292);
          v256 = (int)v209;
        }
        v254 = AuthzBasepQueryClaimAttributesToken(v209, 0, 0, v250);
        v210 = v250[0];
      }
      else
      {
        v210 = 12;
        v250[0] = 12;
        v264 = 0;
        v266 = &v265;
        v265 = (int *)&v265;
        v267 = 0;
        v269 = &v268;
        v268 = (int *)&v268;
        v209 = &v264;
        v256 = (int)&v264;
      }
      *v11 = v210;
      if ( a4 >= v210 )
      {
        v214 = AuthzBasepQueryClaimAttributesToken(v209, v6, a4, v250);
        v254 = v214;
        v215 = ExReleaseResourceLite(v207[12]);
        v216 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v217 = *(_WORD *)(v216 + 0x134) + 1;
        *(_WORD *)(v216 + 308) = v217;
        if ( !v217 && *(_DWORD *)(v216 + 100) != v216 + 100 && !*(_WORD *)(v216 + 310) )
          KiCheckForKernelApcDelivery(v215);
        ObfDereferenceObject((int)v207);
        v14 = v214;
      }
      else
      {
        v211 = ExReleaseResourceLite(v207[12]);
        v212 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v213 = *(_WORD *)(v212 + 0x134) + 1;
        *(_WORD *)(v212 + 308) = v213;
        if ( !v213 && *(_DWORD *)(v212 + 100) != v212 + 100 && !*(_WORD *)(v212 + 310) )
          KiCheckForKernelApcDelivery(v211);
        ObfDereferenceObject((int)v207);
        v14 = -1073741789;
      }
      return v14;
    case 37:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v218 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v218 + 308);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v219 = (int *)v32[159];
      if ( v219 && (v220 = *v219) != 0 )
      {
        v221 = 8 * (v220 - 1) + 12;
      }
      else
      {
        v220 = 0;
        v221 = 12;
      }
      v250[0] = v221;
      v251 = v220;
      if ( v220 )
      {
        v222 = *(int **)(v32[159] + 4);
        v223 = v220;
        do
        {
          v224 = *v222;
          v222 += 2;
          v221 += 4 * (*(unsigned __int8 *)(v224 + 1) + 2);
          --v223;
        }
        while ( v223 );
        v250[0] = v221;
      }
      *v11 = v221;
      if ( a4 < v221 )
      {
        v225 = ExReleaseResourceLite(v32[12]);
        v226 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v227 = *(_WORD *)(v226 + 0x134) + 1;
        *(_WORD *)(v226 + 308) = v227;
        if ( !v227 && *(_DWORD *)(v226 + 100) != v226 + 100 && !*(_WORD *)(v226 + 310) )
          KiCheckForKernelApcDelivery(v225);
        goto LABEL_430;
      }
      *v6 = 0;
      v6[1] = 0;
      v6[2] = 0;
      *v6 = v220;
      if ( v220 )
        RtlCopySidAndAttributesArray(v220, *(_DWORD *)(v32[159] + 4));
      goto LABEL_196;
    case 39:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      v254 = v13;
      if ( v13 < 0 )
        return v13;
      v228 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v228 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v229 = (int *)v32[119];
      if ( v229 )
      {
        v254 = AuthzBasepQuerySecurityAttributesToken(v229, 0, 0, 0, 0, v250);
        v230 = v250[0];
      }
      else
      {
        v230 = 12;
        v250[0] = 12;
      }
      *v11 = v230;
      if ( a4 < v230 )
      {
        v231 = ExReleaseResourceLite(v32[12]);
        v232 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v233 = *(_WORD *)(v232 + 0x134) + 1;
        *(_WORD *)(v232 + 308) = v233;
        if ( !v233 && *(_DWORD *)(v232 + 100) != v232 + 100 && !*(_WORD *)(v232 + 310) )
          KiCheckForKernelApcDelivery(v231);
        goto LABEL_430;
      }
      v234 = AuthzBasepQuerySecurityAttributesToken((int *)v32[119], 0, 0, (int)v6, a4, v250);
      v254 = v234;
      v235 = ExReleaseResourceLite(v32[12]);
      v236 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v237 = *(_WORD *)(v236 + 0x134) + 1;
      *(_WORD *)(v236 + 308) = v237;
      if ( !v237 && *(_DWORD *)(v236 + 100) != v236 + 100 && !*(_WORD *)(v236 + 310) )
        KiCheckForKernelApcDelivery(v235);
      ObfDereferenceObject((int)v32);
      return v234;
    case 41:
      v13 = SepReferenceTokenByHandle(a1, 8, v8, &v248, v247, &v249);
      if ( v13 < 0 )
        return v13;
      v238 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v238 & 0xFFFFFFC0) + 0x134);
      v32 = v248;
      ExAcquireResourceSharedLite(v248[12], 1);
      v239 = (unsigned __int8)v247[0];
      v240 = v249;
      if ( v247[0] )
      {
        v241 = v249;
        v253 = v249;
      }
      else
      {
        v241 = v32[160];
        v253 = v241;
      }
      if ( v241 )
        v242 = 4 * (*(unsigned __int8 *)(v241 + 1) + 3);
      else
        v242 = 4;
      v250[0] = v242;
      *v11 = v242;
      if ( a4 < v242 )
      {
        v243 = ExReleaseResourceLite(v32[12]);
        v244 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v245 = *(_WORD *)(v244 + 0x134) + 1;
        *(_WORD *)(v244 + 308) = v245;
        if ( !v245 && *(_DWORD *)(v244 + 100) != v244 + 100 && !*(_WORD *)(v244 + 310) )
          KiCheckForKernelApcDelivery(v243);
        goto LABEL_430;
      }
      if ( v241 )
        v241 = (int)(v6 + 1);
      *v6 = v241;
      if ( v241 )
      {
        if ( !v239 )
          v240 = v32[160];
        RtlCopySid(v242 - 4, v241, v240);
      }
      goto LABEL_196;
    default:
      return -1073741821;
  }
}
