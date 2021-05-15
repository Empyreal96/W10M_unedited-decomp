// sub_7F8200 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_7F8200(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  unsigned __int8 *v14; // r6
  int v15; // r0
  unsigned int v16; // r2
  unsigned int *v17; // r1
  unsigned int v18; // r2
  int v19; // r2
  unsigned __int8 *v20; // r7
  int v21; // r0
  int v22; // r6
  unsigned int v23; // r2
  int v24; // r2
  __int64 v25; // r1
  unsigned int v26; // r0
  unsigned int v27; // r2
  int v28; // r6
  bool v29; // zf
  unsigned int *v30; // lr
  int v31; // r0
  int v32; // r1
  unsigned int *v33; // r10
  unsigned int v34; // r1
  unsigned int *v35; // r6
  unsigned int v36; // r2
  int v37; // r3
  char *v38; // r2
  unsigned __int8 *v39; // r6
  int v40; // r0
  int v41; // r5
  unsigned int v42; // r2
  unsigned int *v43; // r1
  unsigned int v44; // r2
  int v45; // r2
  int v46; // r6
  int v47; // r2
  unsigned int *v48; // r7
  int v49; // r4
  int v50; // r0
  unsigned int *v51; // r4
  unsigned int v52; // r1
  unsigned __int8 *v53; // r5
  int v54; // r0
  int v55; // r4
  unsigned int v56; // r2
  unsigned int *v57; // r1
  unsigned int v58; // r2
  int v59; // r2
  unsigned __int8 *v60; // r9
  int v61; // r0
  int v62; // r6
  unsigned int v63; // r2
  unsigned int *v64; // r1
  unsigned int v65; // r2
  int v66; // r2
  _DWORD *v67; // r2
  _DWORD *v68; // r3
  int v69; // r9
  unsigned int *v70; // r6
  unsigned int v71; // r1
  unsigned int *v72; // r2
  unsigned int v73; // r0
  int v74; // r0
  _DWORD *v75; // r5
  int v76; // r6
  int v77; // r7
  int v78; // r8
  int *v79; // r9
  _DWORD *v80; // r10
  unsigned int v81; // lr
  int v82; // r4
  unsigned int *v83; // r0
  unsigned int v84; // r2
  int v85; // r3
  int v86; // r4
  unsigned __int8 *v87; // r0
  unsigned int v88; // r2
  unsigned int *v89; // r4
  unsigned int v90; // r1
  int v91; // r3
  unsigned int *v92; // r4
  unsigned int v93; // r1
  unsigned int v94; // r2
  int v95; // r4
  unsigned __int8 *v96; // r0
  unsigned int v97; // r2
  int v98; // r3
  __int64 v99; // r2
  unsigned int *v100; // r4
  unsigned int v101; // r1
  unsigned int v102; // r1
  unsigned int v103; // r2
  unsigned int *v104; // r0
  int v105; // r4
  unsigned __int8 *v106; // r0
  unsigned int v107; // r2
  unsigned __int8 *v108; // r6
  int v109; // r0
  int v110; // r4
  unsigned int v111; // r2
  _DWORD *v112; // r0
  _DWORD *v113; // r1
  unsigned int v114; // r1
  unsigned int *v115; // r4
  unsigned int v116; // r1
  int v117; // r3
  unsigned int *v118; // r4
  unsigned int v119; // r1
  unsigned int v120; // r2
  int v121; // r2
  unsigned int v122; // r1
  unsigned int v123; // r2
  unsigned int *v124; // r9
  int v125; // r0
  int v126; // r6
  unsigned int v127; // r2
  int v128; // r0
  int v129; // r6
  unsigned int v130; // r2
  _DWORD *v131; // r1
  _DWORD *v132; // r3
  unsigned int v133; // r1
  unsigned int v134; // r2
  unsigned int v135; // r2
  int v136; // r9
  unsigned int *v137; // r6
  unsigned int v138; // r1
  unsigned int *v139; // r2
  unsigned int v140; // r0
  int v141; // r0
  unsigned int *v142; // r5
  unsigned int v143; // r1
  unsigned int v144; // r1
  unsigned int v145; // r2
  unsigned __int8 *v146; // r4
  int v147; // r0
  int v148; // r5
  unsigned int v149; // r2
  int v150; // r0
  _DWORD *v151; // r1
  unsigned int v152; // r1
  unsigned int v153; // r1
  int v154; // r0
  unsigned int v155; // r1
  __int16 v156; // r3
  int v157; // r0
  unsigned int v158; // r2
  int v159; // r4
  unsigned __int8 *v160; // r6
  int v161; // r0
  int v162; // r5
  unsigned int v163; // r2
  unsigned int *v164; // r2
  unsigned int v165; // r1
  int v166; // r1
  bool v167; // zf
  int v168; // r3
  unsigned int *v169; // r4
  unsigned int v170; // r1
  unsigned int v171; // r2
  unsigned int v172; // r1
  unsigned int v173; // r2
  int v174; // [sp-24h] [bp-24h]
  _DWORD *v175; // [sp-20h] [bp-20h]
  unsigned int *v176; // [sp-1Ch] [bp-1Ch]
  char v177; // [sp-18h] [bp-18h]
  int *v178; // [sp-14h] [bp-14h]
  int *v179; // [sp-10h] [bp-10h]

  while ( 1 )
  {
    while ( 1 )
    {
LABEL_1:
      v82 = KeAbPreAcquire(v81, 0, 0);
      v83 = v75 + 52;
      do
        v84 = __ldrex(v83);
      while ( !v84 && __strex(0x11u, v83) );
      __dmb(0xBu);
      if ( v84 )
        ExfAcquirePushLockSharedEx(v83, v82, (unsigned int)(v75 + 52));
      if ( v82 )
        *(_BYTE *)(v82 + 14) |= 1u;
      v85 = 0;
LABEL_303:
      v174 = v85;
      v37 = v75[61];
      if ( (v37 & 0x40) != 0 || (v37 & 0x10) != 0 )
        goto LABEL_292;
      v86 = KeAbPreAcquire((unsigned int)(v75 + 23), 0, 0);
      v87 = (unsigned __int8 *)(v75 + 23);
      do
        v88 = __ldrex(v87);
      while ( __strex(v88 | 1, v87) );
      __dmb(0xBu);
      if ( (v88 & 1) != 0 )
      {
        ExfAcquirePushLockExclusiveEx(v87, v86, (unsigned int)(v75 + 23));
        v87 = (unsigned __int8 *)(v75 + 23);
      }
      if ( v86 )
        *(_BYTE *)(v86 + 14) |= 1u;
      v159 = v75[26];
      if ( (_DWORD *)v159 == v75 + 26 || !v159 )
      {
        v159 = v75[24];
        if ( (_DWORD *)v159 == v75 + 24 || !v159 )
          break;
      }
      v14 = (unsigned __int8 *)(v159 - 4);
      v15 = KeAbPreAcquire(v159 - 4, 0, 1);
      do
        v16 = __ldrex(v14);
      while ( __strex(v16 | 1, v14) );
      __dmb(0xBu);
      if ( (v16 & 1) == 0 )
      {
        if ( v15 )
          *(_BYTE *)(v15 + 14) |= 1u;
        *(_BYTE *)(v159 - 16) |= 1u;
        __dmb(0xBu);
        v17 = (unsigned int *)(v159 - 12);
        do
        {
          v18 = __ldrex(v17);
          v19 = v18 + 0x10000;
        }
        while ( __strex(v19, v17) );
        __dmb(0xBu);
        if ( v19 <= 0 )
          KeBugCheckEx(24, 0, v159, 39, v19);
LABEL_247:
        if ( (*(_DWORD *)(v159 + 20) & 7) == 1 )
          --v75[65];
        else
          --v75[66];
        *(_DWORD *)(v159 + 20) &= 0xFFFFFFF8;
        *(_DWORD *)(v159 + 8) = 0;
        **(_DWORD **)(v159 + 4) = *(_DWORD *)v159;
        *(_DWORD *)(*(_DWORD *)v159 + 4) = *(_DWORD *)(v159 + 4);
        if ( (*(_DWORD *)(v159 + 20) & v78) == 0 )
          goto LABEL_250;
        v27 = 0;
        if ( *(_DWORD *)(v159 + 72) )
          v27 = 0x80000000;
        if ( *(_DWORD *)(v159 + 76) )
          v27 |= 0x40000000u;
        if ( *(_DWORD *)(v159 + 80) )
          v27 |= 0x10000000u;
        if ( (v27 & a14) != 0 )
        {
LABEL_250:
          v20 = (unsigned __int8 *)(v75 + 28);
          *(_WORD *)(v159 + 124) |= 0x2000u;
          v21 = KeAbPreAcquire((unsigned int)(v75 + 28), 0, 0);
          v22 = v21;
          do
            v23 = __ldrex(v20);
          while ( __strex(v23 | 1, v20) );
          __dmb(0xBu);
          if ( (v23 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v75 + 28, v21, (unsigned int)(v75 + 28));
          if ( v22 )
            *(_BYTE *)(v22 + 14) |= 1u;
          v24 = *(_DWORD *)(v159 + 20);
          *(_DWORD *)(v159 + 8) = v75;
          LODWORD(v25) = v75 + 29;
          *(_DWORD *)(v159 + 20) = v24 & 0xFFFFFF83 | (4 * (v75[61] & 6)) | 3;
          HIDWORD(v25) = v75[30];
          *(_QWORD *)v159 = v25;
          *(_DWORD *)v75[30] = v159;
          v75[30] = v159;
          ++v75[67];
          __dmb(0xBu);
          do
            v26 = __ldrex((unsigned int *)v20);
          while ( __strex(v26 - 1, (unsigned int *)v20) );
          if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
            ExfTryToWakePushLock(v75 + 28);
          KeAbPostRelease((unsigned int)(v75 + 28));
        }
        else
        {
          *(_WORD *)(v159 + 124) &= 0xDFFFu;
          --*(_WORD *)(v159 - 14);
        }
        v142 = v75 + 23;
        __dmb(0xBu);
        do
          v143 = __ldrex(v142);
        while ( __strex(v143 - 1, v142) );
        if ( (v143 & 2) != 0 && (v143 & 4) == 0 )
          ExfTryToWakePushLock(v142);
        KeAbPostRelease((unsigned int)v142);
        v167 = v174 == 0;
        __dmb(0xBu);
        if ( v167 )
        {
          do
            v145 = __ldrex(v176);
          while ( v145 == 17 && __strex(0, v176) );
          if ( v145 != 17 )
            ExfReleasePushLockShared(v176);
        }
        else
        {
          do
            v144 = __ldrex(v176);
          while ( __strex(v144 - 1, v176) );
          if ( (v144 & 2) != 0 && (v144 & 4) == 0 )
            ExfTryToWakePushLock(v176);
        }
        KeAbPostRelease((unsigned int)v176);
        goto LABEL_320;
      }
      if ( v15 )
        KeAbPostReleaseEx(v159 - 4, v15);
      if ( *(_DWORD *)(v159 + 52) )
      {
        __dmb(0xBu);
        v89 = v75 + 23;
        do
          v90 = __ldrex(v89);
        while ( __strex(v90 - 1, v89) );
        if ( (v90 & 2) != 0 && (v90 & 4) == 0 )
          ExfTryToWakePushLock(v75 + 23);
        KeAbPostRelease((unsigned int)(v75 + 23));
        v91 = v174;
        __dmb(0xBu);
        v92 = v75 + 52;
        if ( v91 )
        {
          do
            v93 = __ldrex(v92);
          while ( __strex(v93 - 1, v92) );
          if ( (v93 & 2) != 0 && (v93 & 4) == 0 )
            ExfTryToWakePushLock(v75 + 52);
        }
        else
        {
          do
            v94 = __ldrex(v92);
          while ( v94 == 17 && __strex(0, v92) );
          if ( v94 != 17 )
            ExfReleasePushLockShared(v75 + 52);
        }
        KeAbPostRelease((unsigned int)(v75 + 52));
        v95 = KeAbPreAcquire((unsigned int)(v75 + 52), 0, 0);
        v96 = (unsigned __int8 *)(v75 + 52);
        do
          v97 = __ldrex(v96);
        while ( __strex(v97 | 1, v96) );
        __dmb(0xBu);
        if ( (v97 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v96, v95, (unsigned int)(v75 + 52));
        if ( v95 )
          *(_BYTE *)(v95 + 14) |= 1u;
        v85 = 1;
        v76 = 0xFFFFFF;
        goto LABEL_303;
      }
      v28 = *(_DWORD *)(v159 - 12);
      v29 = v28 == 0;
      if ( v28 > 0 )
      {
        v30 = (unsigned int *)(v159 - 12);
        do
        {
          v31 = v28;
          __dmb(0xBu);
          do
            v32 = __ldrex(v30);
          while ( v32 == v28 && __strex(v28 + 1, v30) );
          v28 = v32;
          __dmb(0xBu);
          if ( v32 == v31 )
            goto LABEL_280;
        }
        while ( v32 > 0 );
        v29 = v32 == 0;
      }
      if ( !v29 )
        KeBugCheckEx(24, 0, v159, 32, v28);
LABEL_280:
      v33 = v75 + 23;
      __dmb(0xBu);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 - 1, v33) );
      if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
        ExfTryToWakePushLock(v75 + 23);
      KeAbPostRelease((unsigned int)(v75 + 23));
      v167 = v174 == 0;
      __dmb(0xBu);
      v35 = v75 + 52;
      if ( v167 )
      {
        do
          v123 = __ldrex(v35);
        while ( v123 == 17 && __strex(0, v35) );
        if ( v123 != 17 )
          ExfReleasePushLockShared(v75 + 52);
      }
      else
      {
        do
          v122 = __ldrex(v35);
        while ( __strex(v122 - 1, v35) );
        if ( (v122 & 2) != 0 && (v122 & 4) == 0 )
          ExfTryToWakePushLock(v75 + 52);
      }
      KeAbPostRelease((unsigned int)(v75 + 52));
      v60 = (unsigned __int8 *)(v159 - 4);
      v61 = KeAbPreAcquire(v159 - 4, 0, 0);
      v62 = v61;
      do
        v63 = __ldrex(v60);
      while ( __strex(v63 | 1, v60) );
      __dmb(0xBu);
      if ( (v63 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v159 - 4), v61, v159 - 4);
      if ( v62 )
        *(_BYTE *)(v62 + 14) |= 1u;
      *(_BYTE *)(v159 - 16) |= 1u;
      __dmb(0xBu);
      v64 = (unsigned int *)(v159 - 12);
      do
      {
        v65 = __ldrex(v64);
        v66 = v65 + 0x10000;
      }
      while ( __strex(v66, v64) );
      __dmb(0xBu);
      if ( v66 <= 0 )
        KeBugCheckEx(24, 0, v159, 38, v66);
      v124 = v75 + 52;
      --*(_WORD *)(v159 - 14);
      v125 = KeAbPreAcquire((unsigned int)(v75 + 52), 0, 0);
      v126 = v125;
      do
        v127 = __ldrex(v124);
      while ( !v127 && __strex(0x11u, v124) );
      __dmb(0xBu);
      if ( v127 )
        ExfAcquirePushLockSharedEx(v75 + 52, v125, (unsigned int)(v75 + 52));
      if ( v126 )
        *(_BYTE *)(v126 + 14) |= 1u;
      v174 = 0;
      if ( (v75[61] & 0x50) != 0 )
      {
        __dmb(0xBu);
        do
          v135 = __ldrex(v124);
        while ( v135 == 17 && __strex(0, v124) );
        if ( v135 != 17 )
          ExfReleasePushLockShared(v75 + 52);
        KeAbPostRelease((unsigned int)(v75 + 52));
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v159);
        v136 = 0;
        if ( (*(_BYTE *)(v159 - 16) & 1) != 0 )
        {
          v136 = 0x10000 - *(__int16 *)(v159 - 14);
          *(_BYTE *)(v159 - 16) &= 0xFEu;
          *(_WORD *)(v159 - 14) = 0;
        }
        v137 = (unsigned int *)(v159 - 4);
        __dmb(0xBu);
        do
          v138 = __ldrex(v137);
        while ( __strex(v138 - 1, v137) );
        if ( (v138 & 2) != 0 && (v138 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v159 - 4));
        KeAbPostRelease(v159 - 4);
        if ( v136 > 0 )
        {
          __dmb(0xBu);
          v139 = (unsigned int *)(v159 - 12);
          do
          {
            v140 = __ldrex(v139);
            v141 = v140 - v136;
          }
          while ( __strex(v141, v139) );
          __dmb(0xBu);
          if ( v141 <= 0 )
          {
            if ( v141 )
              KeBugCheckEx(24, 0, v159, 40, v141);
            AlpcpDestroyBlob(v159);
            JUMPOUT(0x72231A);
          }
        }
LABEL_381:
        JUMPOUT(0x72231E);
      }
      v128 = KeAbPreAcquire((unsigned int)(v75 + 23), 0, 0);
      v129 = v128;
      do
        v130 = __ldrex((unsigned __int8 *)v33);
      while ( __strex(v130 | 1, (unsigned __int8 *)v33) );
      __dmb(0xBu);
      if ( (v130 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v75 + 23, v128, (unsigned int)(v75 + 23));
      if ( v129 )
        *(_BYTE *)(v129 + 14) |= 1u;
      v131 = v75 + 26;
      v132 = (_DWORD *)v75[26];
      if ( v132 == v75 + 26 || !v132 )
      {
        v67 = (_DWORD *)v75[24];
        if ( v67 == v75 + 24 || !v67 )
          v67 = 0;
        if ( (_DWORD *)v159 == v67 )
          goto LABEL_247;
      }
      v68 = (_DWORD *)*v131;
      if ( (_DWORD *)*v131 == v131 || !v68 )
        v68 = 0;
      if ( (_DWORD *)v159 == v68 )
        goto LABEL_247;
      __dmb(0xBu);
      do
        v133 = __ldrex(v33);
      while ( __strex(v133 - 1, v33) );
      if ( (v133 & 2) != 0 && (v133 & 4) == 0 )
        ExfTryToWakePushLock(v75 + 23);
      KeAbPostRelease((unsigned int)(v75 + 23));
      __dmb(0xBu);
      do
        v134 = __ldrex(v124);
      while ( v134 == 17 && __strex(0, v124) );
      if ( v134 != 17 )
        ExfReleasePushLockShared(v75 + 52);
      KeAbPostRelease((unsigned int)(v75 + 52));
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v159);
      v69 = 0;
      if ( (*(_BYTE *)(v159 - 16) & 1) != 0 )
      {
        v69 = 0x10000 - *(__int16 *)(v159 - 14);
        *(_BYTE *)(v159 - 16) &= 0xFEu;
        *(_WORD *)(v159 - 14) = 0;
      }
      v70 = (unsigned int *)(v159 - 4);
      __dmb(0xBu);
      do
        v71 = __ldrex(v70);
      while ( __strex(v71 - 1, v70) );
      if ( (v71 & 2) != 0 && (v71 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v159 - 4));
      KeAbPostRelease(v159 - 4);
      if ( v69 <= 0 )
        goto LABEL_381;
      __dmb(0xBu);
      v72 = (unsigned int *)(v159 - 12);
      do
      {
        v73 = __ldrex(v72);
        v74 = v73 - v69;
      }
      while ( __strex(v74, v72) );
      __dmb(0xBu);
      v80 = v175;
      if ( v74 > 0 )
        goto LABEL_381;
      if ( v74 )
        KeBugCheckEx(24, 0, v159, 40, v74);
      AlpcpDestroyBlob(v159);
      v79 = v179;
      v81 = (unsigned int)(v75 + 52);
      v76 = 0xFFFFFF;
    }
    if ( (_DWORD *)v75[56] != v75 + 56 )
    {
      v46 = v75[56] - 44;
      **(_DWORD **)(v75[56] + 4) = *(_DWORD *)v75[56];
      *(_DWORD *)(*(_DWORD *)(v46 + 44) + 4) = *(_DWORD *)(v46 + 48);
      --v75[69];
      v47 = *(_DWORD *)(v46 - 12);
      v167 = v47 == 0;
      if ( v47 > 0 )
      {
        v48 = (unsigned int *)(v46 - 12);
        do
        {
          v49 = v47;
          __dmb(0xBu);
          do
            v50 = __ldrex(v48);
          while ( v50 == v47 && __strex(v47 + 1, v48) );
          v47 = v50;
          __dmb(0xBu);
          if ( v50 == v49 )
            goto LABEL_330;
        }
        while ( v50 > 0 );
        v167 = v50 == 0;
      }
      if ( !v167 )
        KeBugCheckEx(24, 0, v46, 32, v47);
LABEL_330:
      v51 = v75 + 23;
      __dmb(0xBu);
      do
        v52 = __ldrex(v51);
      while ( __strex(v52 - 1, v51) );
      if ( (v52 & 2) != 0 && (v52 & 4) == 0 )
        ExfTryToWakePushLock(v75 + 23);
      KeAbPostRelease((unsigned int)(v75 + 23));
      v168 = v174;
      __dmb(0xBu);
      v169 = v75 + 52;
      if ( v168 )
      {
        do
          v170 = __ldrex(v169);
        while ( __strex(v170 - 1, v169) );
        if ( (v170 & 2) != 0 && (v170 & 4) == 0 )
          ExfTryToWakePushLock(v75 + 52);
      }
      else
      {
        do
          v171 = __ldrex(v169);
        while ( v171 == 17 && __strex(0, v169) );
        if ( v171 != 17 )
          ExfReleasePushLockShared(v75 + 52);
      }
      KeAbPostRelease((unsigned int)(v75 + 52));
      v53 = (unsigned __int8 *)(v46 - 4);
      v54 = KeAbPreAcquire(v46 - 4, 0, 0);
      v55 = v54;
      do
        v56 = __ldrex(v53);
      while ( __strex(v56 | 1, v53) );
      __dmb(0xBu);
      if ( (v56 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v46 - 4), v54, v46 - 4);
      if ( v55 )
        *(_BYTE *)(v55 + 14) |= 1u;
      *(_BYTE *)(v46 - 16) |= 1u;
      __dmb(0xBu);
      v57 = (unsigned int *)(v46 - 12);
      do
      {
        v58 = __ldrex(v57);
        v59 = v58 + 0x10000;
      }
      while ( __strex(v59, v57) );
      __dmb(0xBu);
      if ( v59 > 0 )
      {
        *(_WORD *)(v46 - 14) -= 2;
        *v178 = v46;
        __asm { POP.W           {R4-R11,PC} }
      }
      KeBugCheckEx(24, 0, v46, 38, v59);
    }
    v98 = v75[53];
    if ( v98 )
    {
      v99 = *(_QWORD *)(*(_DWORD *)(v98 + 40) + 128);
      __dmb(0xBu);
      if ( (v99 & 0xFFFFFF) != v76 )
      {
        v100 = v75 + 23;
        __dmb(0xBu);
        do
          v101 = __ldrex(v100);
        while ( __strex(v101 - 1, v100) );
        if ( (v101 & 2) != 0 && (v101 & 4) == 0 )
          ExfTryToWakePushLock(v100);
        KeAbPostRelease((unsigned int)v100);
LABEL_292:
        v167 = v174 == 0;
        __dmb(0xBu);
        v146 = (unsigned __int8 *)v176;
        if ( v167 )
        {
          do
            v173 = __ldrex(v176);
          while ( v173 == 17 && __strex(0, v176) );
          if ( v173 != 17 )
            ExfReleasePushLockShared(v176);
        }
        else
        {
          do
            v172 = __ldrex(v176);
          while ( __strex(v172 - 1, v176) );
          if ( (v172 & 2) != 0 && (v172 & 4) == 0 )
            goto LABEL_183;
        }
        goto LABEL_233;
      }
    }
    __dmb(0xBu);
    do
      v102 = __ldrex((unsigned int *)v87);
    while ( __strex(v102 - 1, (unsigned int *)v87) );
    if ( (v102 & 2) != 0 && (v102 & 4) == 0 )
    {
      ExfTryToWakePushLock((unsigned int *)v87);
      v87 = (unsigned __int8 *)(v75 + 23);
    }
    KeAbPostRelease((unsigned int)v87);
    if ( v75[4] )
      goto LABEL_292;
    if ( (v75[61] & v78) != 0 )
    {
      if ( (v75[38] & 0x1000) == 0 )
        goto LABEL_292;
      v117 = v174;
      __dmb(0xBu);
      v118 = v75 + 52;
      if ( v117 )
      {
        do
          v119 = __ldrex(v118);
        while ( __strex(v119 - 1, v118) );
        if ( (v119 & 2) != 0 && (v119 & 4) == 0 )
          ExfTryToWakePushLock(v75 + 52);
      }
      else
      {
        do
          v120 = __ldrex(v118);
        while ( v120 == 17 && __strex(0, v118) );
        if ( v120 != 17 )
          ExfReleasePushLockShared(v75 + 52);
      }
      KeAbPostRelease((unsigned int)(v75 + 52));
      if ( AlpcpLogEnabled )
        ((void (__fastcall *)(_DWORD *))AlpcpLogWaitForNewMessage)(v75);
      if ( !AlpcpCompleteDeferSignalRequestAndWait(v77, v75[37], v121, v177, v79) )
      {
        v76 = 0xFFFFFF;
        v81 = (unsigned int)(v75 + 52);
        goto LABEL_1;
      }
LABEL_323:
      __asm { POP.W           {R4-R11,PC} }
    }
    if ( v75[54] || (v80[241] & 8) != 0 )
      goto LABEL_292;
    if ( !v174 )
    {
      __dmb(0xBu);
      v104 = v75 + 52;
      do
        v36 = __ldrex(v104);
      while ( v36 == 17 && __strex(1u, v104) );
      __dmb(0xBu);
      if ( v36 != 17 )
      {
        __dmb(0xBu);
        do
          v103 = __ldrex(v104);
        while ( v103 == 17 && __strex(0, v104) );
        if ( v103 != 17 )
        {
          ExfReleasePushLockShared(v104);
          v104 = v75 + 52;
        }
        KeAbPostRelease((unsigned int)v104);
        v105 = KeAbPreAcquire((unsigned int)(v75 + 52), 0, 0);
        v106 = (unsigned __int8 *)(v75 + 52);
        do
          v107 = __ldrex(v106);
        while ( __strex(v107 | 1, v106) );
        __dmb(0xBu);
        if ( (v107 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v106, v105, (unsigned int)(v75 + 52));
        if ( v105 )
          *(_BYTE *)(v105 + 14) |= 1u;
      }
      v85 = 1;
      goto LABEL_303;
    }
    v108 = (unsigned __int8 *)(v75 + 34);
    v80[245] = a14;
    v109 = KeAbPreAcquire((unsigned int)(v75 + 34), 0, 0);
    v110 = v109;
    do
      v111 = __ldrex(v108);
    while ( __strex(v111 | 1, v108) );
    __dmb(0xBu);
    if ( (v111 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v75 + 34, v109, (unsigned int)(v75 + 34));
    if ( v110 )
      *(_BYTE *)(v110 + 14) |= 1u;
    v112 = (_DWORD *)v75[36];
    v113 = v80 + 247;
    v80[248] = v112;
    v80[247] = v75 + 35;
    if ( (_DWORD *)*v112 != v75 + 35 )
      __fastfail(3u);
    *v112 = v113;
    v75[36] = v113;
    __dmb(0xBu);
    do
      v114 = __ldrex((unsigned int *)v108);
    while ( __strex(v114 - 1, (unsigned int *)v108) );
    if ( (v114 & 2) != 0 && (v114 & 4) == 0 )
      ExfTryToWakePushLock(v75 + 34);
    KeAbPostRelease((unsigned int)(v75 + 34));
    __dmb(0xBu);
    v115 = v75 + 52;
    do
      v116 = __ldrex(v115);
    while ( __strex(v116 - 1, v115) );
    if ( (v116 & 2) != 0 && (v116 & 4) == 0 )
      ExfTryToWakePushLock(v75 + 52);
    KeAbPostRelease((unsigned int)(v75 + 52));
    v38 = &AlpcpLogEnabled;
    if ( AlpcpLogEnabled )
      ((void (__fastcall *)(_DWORD *))AlpcpLogWaitForNewMessage)(v75);
    if ( AlpcpCompleteDeferSignalRequestAndWait(v77, (unsigned int)(v80 + 221), (int)v38, v177, v79) )
    {
      v146 = (unsigned __int8 *)(v75 + 34);
      v147 = KeAbPreAcquire((unsigned int)(v75 + 34), 0, 0);
      v148 = v147;
      do
        v149 = __ldrex(v146);
      while ( __strex(v149 | 1, v146) );
      __dmb(0xBu);
      if ( (v149 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v146, v147, (unsigned int)v146);
      if ( v148 )
        *(_BYTE *)(v148 + 14) |= 1u;
      if ( v80[247] )
      {
        v80[245] = 0;
        v150 = v80[247];
        v151 = (_DWORD *)v80[248];
        if ( *(_DWORD **)(v150 + 4) != v80 + 247 || (_DWORD *)*v151 != v80 + 247 )
          __fastfail(3u);
        *v151 = v150;
        *(_DWORD *)(v150 + 4) = v151;
        v80[247] = 0;
        __dmb(0xBu);
        do
          v152 = __ldrex((unsigned int *)v146);
        while ( __strex(v152 - 1, (unsigned int *)v146) );
        if ( (v152 & 2) != 0 && (v152 & 4) == 0 )
LABEL_183:
          ExfTryToWakePushLock((unsigned int *)v146);
LABEL_233:
        KeAbPostRelease((unsigned int)v146);
        goto LABEL_323;
      }
      __dmb(0xBu);
      do
        v153 = __ldrex((unsigned int *)v146);
      while ( __strex(v153 - 1, (unsigned int *)v146) );
      if ( (v153 & 2) != 0 && (v153 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)v146);
      v154 = KeAbPostRelease((unsigned int)v146);
      v155 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v156 = *(_WORD *)(v155 + 0x134) + 1;
      *(_WORD *)(v155 + 308) = v156;
      if ( !v156 && *(_DWORD *)(v155 + 100) != v155 + 100 && !*(_WORD *)(v155 + 310) )
        KiCheckForKernelApcDelivery(v154);
      v157 = KeWaitForSingleObject((unsigned int)(v80 + 221), 16, 0, 0, 0);
      v158 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v158 + 308);
      if ( AlpcpLogEnabled )
        AlpcpLogUnwait(v157);
      v159 = v80[245];
      v80[245] = 0;
      if ( !v159 )
        goto LABEL_323;
      v160 = (unsigned __int8 *)(v159 - 4);
      v161 = KeAbPreAcquire(v159 - 4, 0, 0);
      v162 = v161;
      do
        v163 = __ldrex(v160);
      while ( __strex(v163 | 1, v160) );
      __dmb(0xBu);
      if ( (v163 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v159 - 4), v161, v159 - 4);
      if ( v162 )
        *(_BYTE *)(v162 + 14) |= 1u;
      *(_BYTE *)(v159 - 16) |= 1u;
      __dmb(0xBu);
      v164 = (unsigned int *)(v159 - 12);
      do
      {
        v165 = __ldrex(v164);
        v166 = v165 + 0x10000;
      }
      while ( __strex(v166, v164) );
      __dmb(0xBu);
      if ( v166 <= 0 )
        KeBugCheckEx(24, 0, v159, 38, v166);
LABEL_319:
      --*(_WORD *)(v159 - 14);
      *(_DWORD *)(v159 + 20) &= 0xFFFFBFFF;
LABEL_320:
      if ( AlpcpLogEnabled )
        AlpcpLogReceiveMessage(v159);
      *v178 = v159;
      goto LABEL_323;
    }
    v159 = v80[245];
    v80[245] = 0;
    if ( v159 )
    {
      v39 = (unsigned __int8 *)(v159 - 4);
      v40 = KeAbPreAcquire(v159 - 4, 0, 0);
      v41 = v40;
      do
        v42 = __ldrex(v39);
      while ( __strex(v42 | 1, v39) );
      __dmb(0xBu);
      if ( (v42 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v159 - 4), v40, v159 - 4);
      if ( v41 )
        *(_BYTE *)(v41 + 14) |= 1u;
      *(_BYTE *)(v159 - 16) |= 1u;
      __dmb(0xBu);
      v43 = (unsigned int *)(v159 - 12);
      do
      {
        v44 = __ldrex(v43);
        v45 = v44 + 0x10000;
      }
      while ( __strex(v45, v43) );
      __dmb(0xBu);
      if ( v45 <= 0 )
        KeBugCheckEx(24, 0, v159, 38, v45);
      goto LABEL_319;
    }
    v76 = 0xFFFFFF;
    v81 = (unsigned int)(v75 + 52);
  }
}
