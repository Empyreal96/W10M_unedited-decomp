// ExpQuerySystemPerformanceInformation 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpQuerySystemPerformanceInformation(int a1, int a2, unsigned int a3)
{
  int v3; // r4
  int v4; // r10
  int v5; // r5 OVERLAPPED
  int v6; // r6 OVERLAPPED
  int v7; // r7
  int v8; // r8
  int v9; // lr
  int v10; // r9
  __int64 v11; // r2
  int v12; // r0
  int v13; // r3
  unsigned __int64 v14; // kr08_8
  int v15; // r3
  unsigned __int64 v16; // kr10_8
  bool v17; // zf
  int v18; // r1
  int v19; // r0
  void **v20; // r4
  int v21; // r5
  int v22; // t1
  unsigned int v23; // r1
  int v24; // r0
  int v25; // r4
  int v26; // r5
  int v27; // r6
  int v28; // r7
  int v29; // r2
  int v30; // r1
  int v31; // r3
  int v32; // lr
  int v33; // r8
  int v34; // r9
  int v35; // r10
  void **v36; // r3
  _DWORD *v37; // r1
  int v38; // r3
  int v39; // r2
  int v40; // r3
  int v41; // r2
  int v42; // r3
  int v43; // r2
  int v44; // r3
  int v45; // r2
  int v46; // r3
  int v47; // r2
  int v48; // r3
  int v49; // r2
  int v50; // r3
  unsigned int v51; // r0
  unsigned int v52; // r1
  int v53; // r5
  int v54; // r6
  int v55; // r9
  int v56; // r7
  int v57; // lr
  int v58; // r8
  int v59; // r10
  int v60; // r0
  void **v61; // r4
  _DWORD *v62; // t1
  int v63; // r2
  __int64 v65; // [sp+10h] [bp-1F0h]
  __int64 v66; // [sp+10h] [bp-1F0h]
  __int64 v67; // [sp+10h] [bp-1F0h]
  int v68; // [sp+18h] [bp-1E8h]
  int v69; // [sp+18h] [bp-1E8h]
  int v70; // [sp+1Ch] [bp-1E4h]
  void **v71; // [sp+1Ch] [bp-1E4h]
  int v72; // [sp+1Ch] [bp-1E4h]
  int v73; // [sp+20h] [bp-1E0h]
  int v74; // [sp+20h] [bp-1E0h]
  int v75; // [sp+24h] [bp-1DCh]
  int v76; // [sp+24h] [bp-1DCh]
  int v78; // [sp+2Ch] [bp-1D4h] BYREF
  int v79; // [sp+30h] [bp-1D0h]
  int v80; // [sp+34h] [bp-1CCh]
  int v81; // [sp+38h] [bp-1C8h]
  int v82; // [sp+3Ch] [bp-1C4h]
  int v83; // [sp+40h] [bp-1C0h]
  int v84; // [sp+44h] [bp-1BCh]
  int v85; // [sp+48h] [bp-1B8h]
  int v86; // [sp+4Ch] [bp-1B4h]
  int v87; // [sp+50h] [bp-1B0h]
  int v88; // [sp+54h] [bp-1ACh]
  int v89; // [sp+58h] [bp-1A8h]
  int v90; // [sp+5Ch] [bp-1A4h]
  int v91; // [sp+60h] [bp-1A0h]
  int v92; // [sp+64h] [bp-19Ch]
  int v93; // [sp+68h] [bp-198h]
  int v94; // [sp+6Ch] [bp-194h]
  unsigned int v95; // [sp+70h] [bp-190h]
  int v96; // [sp+74h] [bp-18Ch]
  unsigned __int64 v97; // [sp+78h] [bp-188h] BYREF
  int v98; // [sp+80h] [bp-180h]
  int v99; // [sp+84h] [bp-17Ch]
  int v100; // [sp+88h] [bp-178h]
  int v101; // [sp+8Ch] [bp-174h]
  int v102; // [sp+90h] [bp-170h]
  int v103; // [sp+94h] [bp-16Ch]
  int v104; // [sp+98h] [bp-168h]
  int v105; // [sp+9Ch] [bp-164h]
  int v106; // [sp+A0h] [bp-160h]
  int v107; // [sp+A4h] [bp-15Ch]
  int v108; // [sp+A8h] [bp-158h]
  int v109; // [sp+ACh] [bp-154h]
  unsigned int v110; // [sp+B0h] [bp-150h]
  int v111; // [sp+B4h] [bp-14Ch]
  int v112; // [sp+B8h] [bp-148h]
  int v113; // [sp+BCh] [bp-144h]
  int v114; // [sp+C0h] [bp-140h]
  int v115; // [sp+C4h] [bp-13Ch]
  int v116; // [sp+C8h] [bp-138h]
  int v117; // [sp+CCh] [bp-134h]
  int v118; // [sp+D0h] [bp-130h]
  int v119; // [sp+D4h] [bp-12Ch]
  int v120; // [sp+D8h] [bp-128h]
  int v121; // [sp+DCh] [bp-124h]
  int v122; // [sp+E0h] [bp-120h]
  int v123; // [sp+E4h] [bp-11Ch]
  int v124; // [sp+E8h] [bp-118h] BYREF
  int v125; // [sp+ECh] [bp-114h] BYREF
  int v126; // [sp+F0h] [bp-110h] BYREF
  int v127; // [sp+F4h] [bp-10Ch] BYREF
  int v128; // [sp+F8h] [bp-108h] BYREF
  int v129[5]; // [sp+FCh] [bp-104h] BYREF
  int v130; // [sp+110h] [bp-F0h] BYREF
  _DWORD v131[5]; // [sp+114h] [bp-ECh] BYREF
  int v132; // [sp+128h] [bp-D8h]
  int v133; // [sp+12Ch] [bp-D4h]
  int v134; // [sp+130h] [bp-D0h]
  int v135; // [sp+134h] [bp-CCh]
  int v136; // [sp+138h] [bp-C8h]
  int v137; // [sp+13Ch] [bp-C4h]
  int v138; // [sp+140h] [bp-C0h]
  int v139; // [sp+144h] [bp-BCh]
  int v140; // [sp+148h] [bp-B8h]
  int v141; // [sp+14Ch] [bp-B4h]
  int v142; // [sp+150h] [bp-B0h]
  int v143; // [sp+154h] [bp-ACh]
  int v144; // [sp+158h] [bp-A8h]
  int v145; // [sp+15Ch] [bp-A4h]
  int v146; // [sp+160h] [bp-A0h]
  int v147; // [sp+164h] [bp-9Ch]
  int v148; // [sp+168h] [bp-98h]
  int v149; // [sp+16Ch] [bp-94h]
  int v150; // [sp+170h] [bp-90h]
  int v151; // [sp+174h] [bp-8Ch]
  int v152; // [sp+178h] [bp-88h]
  int v153; // [sp+17Ch] [bp-84h]
  int v154; // [sp+180h] [bp-80h]
  int v155; // [sp+184h] [bp-7Ch]
  int v156; // [sp+188h] [bp-78h]
  int v157; // [sp+18Ch] [bp-74h]
  int v158; // [sp+190h] [bp-70h]
  int v159; // [sp+194h] [bp-6Ch]
  int v160; // [sp+198h] [bp-68h]
  int v161; // [sp+19Ch] [bp-64h]
  int v162; // [sp+1A0h] [bp-60h]
  int v163; // [sp+1A4h] [bp-5Ch]
  int v164; // [sp+1A8h] [bp-58h]
  int v165; // [sp+1ACh] [bp-54h]
  int v166; // [sp+1B0h] [bp-50h]
  int v167; // [sp+1B4h] [bp-4Ch]
  int v168; // [sp+1B8h] [bp-48h]
  int v169; // [sp+1BCh] [bp-44h]
  int v170; // [sp+1C0h] [bp-40h]
  int v171; // [sp+1C4h] [bp-3Ch]
  int v172; // [sp+1C8h] [bp-38h]
  int v173; // [sp+1CCh] [bp-34h]
  int v174[12]; // [sp+1D0h] [bp-30h] BYREF

  v95 = a3;
  v96 = a2;
  v3 = IoOtherOperationCount;
  v4 = IoWriteTransferCount;
  *(_QWORD *)&v5 = IoOtherTransferCount;
  v7 = IoReadOperationCount;
  v8 = unk_6316DC;
  v9 = IoReadTransferCount;
  v10 = IoWriteOperationCount;
  HIDWORD(v11) = dword_6316E4;
  HIDWORD(v65) = dword_6316E4;
  if ( a1 )
  {
    LODWORD(v11) = &KiProcessorBlock;
    LODWORD(v65) = a1;
    do
    {
      v12 = *(_DWORD *)v11;
      HIDWORD(v11) = *(_DWORD *)(*(_DWORD *)v11 + 1628);
      v70 = v11 + 4;
      __dmb(0xBu);
      v3 += HIDWORD(v11);
      v13 = *(_DWORD *)(v12 + 1620);
      v14 = __PAIR64__(v6, v5) + *(_QWORD *)(v12 + 1648);
      v6 = HIDWORD(v14);
      v5 = v14;
      __dmb(0xBu);
      v7 += v13;
      v15 = *(_DWORD *)(v12 + 1624);
      v16 = __PAIR64__(v8, v9) + *(_QWORD *)(v12 + 1632);
      v8 = HIDWORD(v16);
      v9 = v16;
      __dmb(0xBu);
      v10 += v15;
      HIDWORD(v11) = (__PAIR64__(HIDWORD(v65), v4) + *(_QWORD *)(v12 + 1640)) >> 32;
      v4 += *(_DWORD *)(v12 + 1640);
      LODWORD(v11) = v65 - 1;
      v17 = (_DWORD)v65 == 1;
      v65 = v11;
      LODWORD(v11) = v70;
    }
    while ( !v17 );
  }
  v100 = v4;
  v101 = HIDWORD(v11);
  v18 = 0;
  v19 = 0;
  v98 = v9;
  v99 = v8;
  v102 = v5;
  v103 = v6;
  v104 = v7;
  v105 = v10;
  v106 = v3;
  if ( a1 )
  {
    v20 = &KiProcessorBlock;
    v21 = a1;
    do
    {
      v22 = (int)*v20++;
      v19 += *(_DWORD *)(v22 + 1588);
      v18 += *(_DWORD *)(v22 + 1584);
      --v21;
    }
    while ( v21 );
  }
  v163 = 0;
  v164 = 0;
  v162 = v19;
  v165 = v18;
  v107 = MmGetAvailablePages();
  v108 = MmGetTotalCommittedPages();
  v109 = MmGetTotalCommitLimit();
  v110 = MmGetPeakCommitment();
  if ( v110 < v23 )
    v110 = v23;
  v68 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v73 = 0;
  v66 = 0i64;
  if ( a1 )
  {
    v36 = &KiProcessorBlock;
    v75 = a1;
    do
    {
      v37 = *v36;
      v71 = v36 + 1;
      v38 = *((_DWORD *)*v36 + 386);
      __dmb(0xBu);
      v39 = v37[387];
      v24 += v38;
      __dmb(0xBu);
      v25 += v39;
      v40 = v37[388];
      __dmb(0xBu);
      v26 += v40;
      v41 = v37[730];
      __dmb(0xBu);
      v27 += v41;
      v42 = v37[389];
      __dmb(0xBu);
      v28 += v42;
      v43 = v37[390];
      __dmb(0xBu);
      v32 += v43;
      v44 = v37[391];
      __dmb(0xBu);
      v33 += v44;
      v45 = v37[731];
      __dmb(0xBu);
      v34 += v45;
      v46 = v37[732];
      __dmb(0xBu);
      v35 += v46;
      v47 = v37[392];
      __dmb(0xBu);
      v68 += v47;
      v48 = v37[393];
      __dmb(0xBu);
      v73 += v48;
      v49 = v37[394];
      __dmb(0xBu);
      LODWORD(v66) = v66 + v49;
      v50 = v37[395];
      __dmb(0xBu);
      HIDWORD(v66) += v50;
      v17 = v75-- == 1;
      v36 = v71;
    }
    while ( !v17 );
    v31 = v68;
    v29 = v73;
    v30 = v66;
  }
  v119 = v35;
  v120 = v31;
  v111 = v24;
  v112 = v25;
  v113 = v26;
  v114 = v27;
  v122 = v30;
  v123 = HIDWORD(v66);
  v115 = v28;
  v116 = v32;
  v117 = v33;
  v118 = v34;
  v121 = v29;
  v129[1] = MmGetNumberOfFreeSystemPtes();
  MmGetSystemPageCounts(v174);
  v129[2] = v174[0];
  v131[2] = MmGetWorkingSetLeafSize(2);
  v131[3] = MmGetWorkingSetLeafSize(3);
  v131[4] = v174[1];
  v129[3] = v174[3];
  v129[4] = v174[2];
  MiFreePoolPagesLeft(6);
  v51 = MiMaximumCommitmentAvailable();
  if ( v52 > v51 )
    v52 = v51;
  v131[1] = v52;
  v97 = (unsigned int)PsQueryRuntimeProcess(PsIdleProcess, &v78) * (unsigned __int64)(unsigned int)KeMaximumIncrement;
  ExQueryPoolUsage(&v124, &v125, &v126, &v127, v131, &v128, v129, &v130);
  v53 = 0;
  v54 = 0;
  v55 = CcFastMdlReadWait;
  v56 = 0;
  v136 = 0;
  v137 = CcFastMdlReadWait;
  v67 = 0i64;
  v139 = 0;
  v140 = 0;
  v74 = 0;
  v76 = 0;
  v141 = 0;
  v142 = 0;
  v84 = 0;
  v85 = 0;
  v143 = 0;
  v144 = 0;
  v90 = 0;
  v91 = 0;
  v145 = 0;
  v146 = 0;
  v92 = 0;
  v93 = 0;
  v147 = 0;
  v148 = 0;
  v149 = 0;
  v150 = 0;
  v94 = 0;
  v151 = 0;
  v152 = 0;
  v153 = 0;
  v154 = 0;
  v80 = 0;
  v81 = 0;
  v155 = 0;
  v156 = 0;
  v157 = 0;
  v158 = 0;
  v132 = 0;
  v133 = 0;
  v134 = 0;
  v135 = 0;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v138 = 0;
  v69 = 0;
  v87 = 0;
  v88 = 0;
  v82 = 0;
  v83 = 0;
  v79 = 0;
  v89 = 0;
  v86 = 0;
  v159 = 0;
  v60 = a1;
  v78 = 0;
  v160 = 0;
  v161 = 0;
  v72 = 0;
  if ( a1 )
  {
    v61 = &KiProcessorBlock;
    do
    {
      v62 = *v61++;
      v53 += v62[398];
      v54 += v62[399];
      v56 += v62[720];
      v57 += v62[400];
      v58 += v62[704];
      v55 += v62[705];
      v59 += v62[722];
      v76 += v62[706];
      v139 = v76;
      HIDWORD(v67) += v62[707];
      v140 = HIDWORD(v67);
      LODWORD(v67) = v67 + v62[708];
      v141 = v67;
      v74 += v62[723];
      v142 = v74;
      v69 += v62[724];
      v143 = v69;
      v85 += v62[709];
      v144 = v85;
      v88 += v62[710];
      v145 = v88;
      v90 += v62[711];
      v146 = v90;
      v81 += v62[725];
      v147 = v81;
      v92 += v62[726];
      v148 = v92;
      v83 += v62[401];
      v149 = v83;
      v91 += v62[402];
      v150 = v91;
      v79 += v62[403];
      v151 = v79;
      v94 += v62[721];
      v152 = v94;
      v87 += v62[712];
      v153 = v87;
      v93 += v62[713];
      v154 = v93;
      v89 += v62[727];
      v155 = v89;
      v80 += v62[728];
      v156 = v80;
      v82 += v62[729];
      v157 = v82;
      v84 += v62[715];
      v158 = v84;
      v86 += v62[716];
      v159 = v86;
      v78 += v62[717];
      v160 = v78;
      v72 += v62[718];
      v161 = v72;
      --v60;
    }
    while ( v60 );
    v132 = v53;
    v133 = v54;
    v134 = v56;
    v135 = v57;
    v136 = v58;
    v137 = v55;
    v138 = v59;
  }
  v167 = 0;
  v169 = 0;
  v166 = CcGlobalDirtyPageStatistics;
  v168 = CcGlobalDirtyPageThresholds;
  v170 = MmGetResidentAvailablePages();
  v171 = 0;
  v172 = MmGetSharedCommit();
  v173 = v63;
  return memmove(v96, (int)&v97, v95);
}
