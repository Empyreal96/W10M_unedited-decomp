// KeWaitForSingleObject 
 
int __fastcall KeWaitForSingleObject(unsigned int a1, int a2, char a3, _DWORD *a4, int *a5)
{
  _DWORD *v5; // r10
  unsigned int v6; // r6
  char v7; // r5
  int v8; // r2
  int v9; // r5
  unsigned int *v10; // r9
  unsigned int v11; // r5
  int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r7
  _DWORD *v16; // r8
  int v17; // r10
  unsigned int v18; // r2
  int v19; // r3
  int v20; // lr
  unsigned int v21; // r4
  unsigned int v22; // r0
  unsigned int v23; // r1
  unsigned int v24; // r3
  unsigned int v25; // r8
  void (__fastcall **v26)(int); // r3
  int v27; // r0
  int v28; // r8
  int v30; // r3
  int v31; // r3
  unsigned int v32; // r2
  char v33; // r2
  int v34; // r3
  unsigned int *v35; // r0
  unsigned int v36; // r1
  unsigned int v37; // r1
  unsigned int v38; // r9
  void (__fastcall **v39)(int); // r3
  int v40; // r0
  unsigned int v41; // r4
  __int64 v42; // r0
  int v43; // r2
  unsigned int v44; // r3
  bool v45; // cf
  unsigned int v46; // r1
  unsigned int v47; // r2
  _DWORD *v48; // r1
  unsigned int v49; // r1
  unsigned int v50; // r1
  __int64 v51; // kr20_8
  unsigned int v52; // r2
  unsigned int v53; // r1
  unsigned int v54; // r1
  unsigned int v55; // r2
  int v56; // r3
  int v57; // r9
  unsigned int v58; // r3
  int v59; // r7
  int v60; // r3
  unsigned int v61; // r2
  int v62; // r9
  __int64 v63; // kr30_8
  unsigned int *v64; // r1
  unsigned int v65; // r2
  _DWORD *v66; // r3
  unsigned int v67; // r3
  unsigned int v68; // r2
  __int64 v69; // r0
  unsigned int v70; // lr
  unsigned __int64 *v71; // r6
  __int64 v72; // kr40_8
  unsigned __int64 v73; // kr50_8
  unsigned __int64 v74; // r2
  char v75; // r6
  unsigned __int64 *v76; // r4
  unsigned __int64 v77; // kr58_8
  unsigned __int64 v78; // kr60_8
  int v79; // r1
  _DWORD *v80; // r5
  unsigned int *v81; // r1
  unsigned int v82; // r2
  int v83; // r3
  __int64 v84; // r0
  __int64 v85; // r0
  int v86; // r10
  int v87; // lr
  unsigned __int64 *v88; // r6
  unsigned __int64 v89; // kr68_8
  unsigned __int64 v90; // kr70_8
  __int64 v91; // r2
  char v92; // r10
  int v93; // r5
  unsigned int *v94; // r1
  unsigned int v95; // r2
  unsigned int v96; // r3
  __int64 v97; // r0
  unsigned int v98; // r3
  unsigned int v99; // r2
  __int64 v100; // r0
  int v101; // lr
  unsigned __int64 *v102; // r6
  unsigned __int64 v103; // kr78_8
  unsigned __int64 v104; // kr80_8
  __int64 v105; // r2
  int v106; // r5
  int v107; // r6
  unsigned __int64 *v108; // r4
  unsigned int v109; // r6
  unsigned __int64 v110; // kr90_8
  unsigned __int64 v111; // kr98_8
  int v112; // r1
  int v113; // r5
  unsigned __int8 *v114; // r3
  unsigned int v115; // r2
  unsigned int *v116; // r4
  unsigned int v117; // r2
  int v118; // r6
  char v119; // r5
  int v120; // r3
  int v121; // r5
  unsigned int *v122; // r1
  unsigned int v123; // r2
  unsigned int v124; // r3
  __int64 v125; // r0
  unsigned int v126; // r3
  unsigned int v127; // r2
  __int64 v128; // r0
  int v129; // lr
  unsigned __int64 *v130; // r6
  unsigned __int64 v131; // krA0_8
  unsigned __int64 v132; // krA8_8
  int v133; // r4
  __int64 v134; // r2
  int v135; // r6
  unsigned __int64 *v136; // r4
  unsigned __int64 v137; // krB8_8
  unsigned __int64 v138; // krC0_8
  int v139; // r1
  unsigned int v140; // r6
  int v141; // r6
  unsigned int v142; // r1
  unsigned int v143; // r3
  unsigned int v144; // r2
  unsigned __int8 *v145; // r3
  unsigned int v146; // r2
  unsigned int *v147; // r4
  unsigned int v148; // r2
  __int64 v149; // krC8_8
  unsigned int *v150; // r1
  unsigned int v151; // r2
  _DWORD *v152; // r9
  unsigned int v153; // r3
  unsigned int v154; // r2
  __int64 v155; // r0
  unsigned int v156; // lr
  unsigned __int64 *v157; // r6
  unsigned int v158; // r2
  unsigned int v159; // r3
  unsigned __int64 v160; // krE8_8
  unsigned __int64 v161; // r2
  char v162; // r6
  unsigned int v163; // r1
  int v164; // r4
  unsigned int v165; // r3
  int v166; // r3
  int v167; // r2
  int v168; // r2
  int v169; // r9
  unsigned __int64 *v170; // r4
  unsigned __int64 v171; // krF0_8
  unsigned __int64 v172; // krF8_8
  int v173; // r1
  unsigned int v174; // r1
  int v175; // r4
  unsigned int v176; // r3
  int v177; // r3
  int v178; // r2
  int v179; // r2
  int v180; // r6
  int v181; // r5
  unsigned __int64 *v182; // r4
  unsigned int v183; // r5
  unsigned __int64 v184; // kr108_8
  unsigned __int64 v185; // kr110_8
  int v186; // r1
  unsigned __int64 v187; // [sp+8h] [bp-68h]
  unsigned int v188; // [sp+Ch] [bp-64h]
  int v189; // [sp+10h] [bp-60h]
  unsigned int v190; // [sp+10h] [bp-60h]
  unsigned int v191; // [sp+10h] [bp-60h]
  int v192; // [sp+14h] [bp-5Ch]
  unsigned int v193; // [sp+14h] [bp-5Ch]
  unsigned int v194; // [sp+14h] [bp-5Ch]
  unsigned int v195; // [sp+14h] [bp-5Ch]
  int v196; // [sp+18h] [bp-58h]
  unsigned int v197; // [sp+18h] [bp-58h]
  unsigned int v198; // [sp+18h] [bp-58h]
  int v199; // [sp+20h] [bp-50h]
  int v200; // [sp+20h] [bp-50h]
  _DWORD *v201[2]; // [sp+28h] [bp-48h] BYREF
  int v202; // [sp+30h] [bp-40h]
  int v203; // [sp+34h] [bp-3Ch]
  unsigned int v204; // [sp+38h] [bp-38h]
  int v205; // [sp+3Ch] [bp-34h]
  int v206; // [sp+40h] [bp-30h]
  int v207; // [sp+44h] [bp-2Ch]

  v192 = a3;
  v5 = a4;
  v201[0] = a4;
  v206 = a2;
  v204 = a1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_BYTE *)(v6 + 0x4C);
  *(_BYTE *)(v6 + 0x4C) = v7 & 0xFB;
  v196 = (unsigned __int8)(v7 & 4) >> 2;
  if ( !v196 )
    *(_BYTE *)(v6 + 134) = KfRaiseIrql(2);
  if ( a5 )
  {
    if ( a5[1] < 0 )
    {
      v51 = MEMORY[0xFFFF93B0];
      v52 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v53 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v52 != MEMORY[0xFFFF9010] )
        return sub_50CF38(v51, v53);
      LODWORD(v187) = (__PAIR64__(v52, v53) - v51 - *(_QWORD *)(v6 + 160) - *(_QWORD *)a5) >> 32;
      HIDWORD(v187) = v53 - v51 - *(_DWORD *)(v6 + 160) - *a5;
      v5 = v201[0];
      v189 = 2;
      goto LABEL_6;
    }
    v8 = a5[1];
    v9 = *a5;
    v189 = 1;
  }
  else
  {
    v9 = v206;
    v8 = v207;
    v189 = 0;
  }
  v187 = __PAIR64__(v9, v8);
LABEL_6:
  v202 = 0;
  v10 = (unsigned int *)(v6 + 44);
  while ( 1 )
  {
    v11 = *(unsigned __int8 *)(v6 + 134);
    v199 = v11;
    while ( 1 )
    {
      v12 = *(_DWORD *)(v6 + 76);
      *(_BYTE *)(v6 + 72) = 0;
      *(_BYTE *)(v6 + 135) = v192;
      v13 = v12 & 0xFFFFFFEF;
      *(_DWORD *)(v6 + 76) = v13;
      if ( v5 )
        *(_DWORD *)(v6 + 76) = v13 | 0x10;
      while ( 1 )
      {
        do
          v14 = __ldrex(v10);
        while ( __strex(1u, v10) );
        __dmb(0xBu);
        if ( !v14 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v10 );
      }
      if ( !*(_BYTE *)(v6 + 121) || *(_WORD *)(v6 + 310) || v11 )
        break;
      __dmb(0xBu);
      *v10 = 0;
      KfLowerIrql(1);
      KiDeliverApc(0, 0, 0);
      KfRaiseIrql(2);
      *(_BYTE *)(v6 + 134) = 0;
    }
    v15 = v204;
    v16 = (_DWORD *)(v6 + 216);
    if ( !v5 )
    {
      if ( (*(_BYTE *)(v6 + 122) & (unsigned __int8)v192) != 0 )
        goto LABEL_101;
      goto LABEL_15;
    }
    if ( *(_BYTE *)(v192 + v6 + 74) )
    {
      *(_BYTE *)(v192 + v6 + 74) = 0;
      v28 = 257;
      goto LABEL_102;
    }
    if ( v192 && *(_DWORD *)(v6 + 108) != v6 + 108 )
      break;
    if ( *(_BYTE *)(v6 + 74) )
    {
      *(_BYTE *)(v6 + 74) = 0;
      v28 = 257;
      goto LABEL_102;
    }
LABEL_15:
    *(_BYTE *)(v6 + 132) = 5;
    *(_BYTE *)(v6 + 395) = v206;
    __dmb(0xBu);
    *v10 = 0;
    *(_DWORD *)(v6 + 304) = KeTickCount;
    *(_BYTE *)(v6 + 224) = 1;
    *(_BYTE *)(v6 + 225) = 4;
    *(_WORD *)(v6 + 226) = 0;
    *(_DWORD *)(v6 + 232) = v15;
    v17 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    do
      v18 = __ldrex((unsigned __int8 *)v15);
    while ( __strex(v18 | 0x80, (unsigned __int8 *)v15) );
    __dmb(0xBu);
    if ( v18 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v15 & 0x80) != 0 );
        do
          v55 = __ldrex((unsigned __int8 *)v15);
        while ( __strex(v55 | 0x80, (unsigned __int8 *)v15) );
        __dmb(0xBu);
      }
      while ( v55 >> 7 );
    }
    v19 = *(_DWORD *)(v15 + 4);
    if ( (*(_BYTE *)v15 & 0x7F) != 2 )
    {
      if ( v19 <= 0 )
        goto LABEL_20;
      if ( (*(_BYTE *)v15 & 7) == 1 )
      {
        *(_DWORD *)(v15 + 4) = 0;
      }
      else if ( (*(_BYTE *)v15 & 0x7F) == 5 )
      {
        --*(_DWORD *)(v15 + 4);
      }
      __dmb(0xBu);
      do
        v50 = __ldrex((unsigned int *)v15);
      while ( __strex(v50 & 0xFFFFFF7F, (unsigned int *)v15) );
LABEL_26:
      *(_BYTE *)(v6 + 132) = 2;
      __dmb(0xFu);
      v24 = *v10;
      __dmb(0xBu);
      if ( v24 )
      {
        while ( 1 )
        {
          do
            v61 = __ldrex(v10);
          while ( __strex(1u, v10) );
          __dmb(0xBu);
          if ( !v61 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v10 );
        }
        __dmb(0xBu);
        *v10 = 0;
      }
      v25 = *(unsigned __int8 *)(v6 + 134);
      if ( (*(_BYTE *)(v6 + 72) & 0x38) == 0 )
      {
        if ( !v196 )
        {
LABEL_29:
          v26 = (void (__fastcall **)(int))&KfLowerIrql;
          v27 = v25;
          goto LABEL_30;
        }
        v56 = *(_DWORD *)(v17 + 8);
        if ( v25 >= 2 )
        {
          if ( !v56 || *(_BYTE *)(v17 + 1754) )
            return v202;
          v26 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
          v27 = 2;
LABEL_30:
          (*v26)(v27);
          return v202;
        }
        v57 = *(_DWORD *)(v17 + 4);
        if ( v56 )
        {
          KiAbProcessContextSwitch(*(_DWORD *)(v17 + 4), 0);
          v64 = (unsigned int *)(v17 + 24);
          while ( 1 )
          {
            do
              v65 = __ldrex(v64);
            while ( __strex(1u, v64) );
            __dmb(0xBu);
            if ( !v65 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v64 );
          }
          v66 = *(_DWORD **)(v17 + 8);
          *(_DWORD *)(v17 + 8) = 0;
          __disable_irq();
          v201[0] = v66;
          *(_BYTE *)(v17 + 16) = 1;
          LODWORD(v69) = ReadTimeStampCounter();
          v67 = *(_DWORD *)(v17 + 2376);
          v68 = *(_DWORD *)(v17 + 2380);
          v206 = v69;
          v71 = (unsigned __int64 *)(v57 + 48);
          v70 = (v69 - __PAIR64__(v68, v67)) >> 32;
          LODWORD(v69) = v69 - v67;
          v72 = *(_QWORD *)(v57 + 48);
          v197 = v69;
          v204 = v70;
          __dmb(0xBu);
          do
            v73 = __ldrexd(v71);
          while ( __strexd(v72 + __PAIR64__(v70, v69), v71) );
          __dmb(0xBu);
          v74 = __PAIR64__(v70, *(_DWORD *)(v57 + 56)) + (unsigned int)v69;
          if ( HIDWORD(v74) )
            LODWORD(v74) = -1;
          HIDWORD(v74) = v206;
          *(_DWORD *)(v17 + 2380) = HIDWORD(v69);
          *(_DWORD *)(v17 + 2376) = HIDWORD(v74);
          v75 = *(_BYTE *)(v57 + 2);
          *(_DWORD *)(v57 + 56) = v74;
          if ( (v75 & 0x3E) != 0 )
          {
            if ( (v75 & 0x10) != 0 )
            {
              v174 = *(_DWORD *)(v17 + 2376);
              v175 = v17 + 8 * *(unsigned __int8 *)(v57 + 84);
              v176 = *(_DWORD *)(v17 + 2384);
              v75 &= 0xEFu;
              v45 = v174 >= v176;
              HIDWORD(v69) = v174 - v176;
              v177 = *(_DWORD *)(v175 + 2392);
              LODWORD(v69) = *(_DWORD *)(v17 + 2380) - (*(_DWORD *)(v17 + 2388) + !v45);
              v178 = *(_DWORD *)(v175 + 2396);
              *(_DWORD *)(v175 + 2392) = v177 + HIDWORD(v69);
              v179 = v69 + __CFADD__(v177, HIDWORD(v69)) + v178;
              LODWORD(v69) = v197;
              *(_DWORD *)(v175 + 2396) = v179;
              *(_DWORD *)(v17 + 2384) = 0;
              *(_DWORD *)(v17 + 2388) = 0;
            }
            if ( (v75 & 0x3E) != 0 )
            {
              if ( (v75 & 0x20) != 0 )
              {
                v206 = *(_DWORD *)(v57 + 1084);
                if ( v206 )
                {
                  v76 = (unsigned __int64 *)(v206
                                           + 8 * (*(unsigned __int8 *)(v17 + 2986) + 2 * PoGetFrequencyBucket(v17)));
                  v70 = v204;
                  v77 = __PAIR64__(v204, v197) + *v76;
                  __dmb(0xBu);
                  do
                    v78 = __ldrexd(v76);
                  while ( __strexd(v77, v76) );
                  __dmb(0xBu);
                  LODWORD(v69) = v197;
                }
                v75 &= 0xDFu;
              }
              if ( (v75 & 0x3E) != 0 )
              {
                v79 = *(_DWORD *)(v57 + 68);
                if ( v79 )
                {
                  for ( HIDWORD(v69) = v79 + *(_DWORD *)(v17 + 2352);
                        HIDWORD(v69);
                        HIDWORD(v69) = *(_DWORD *)(HIDWORD(v69) + 236) )
                  {
                    *(_QWORD *)HIDWORD(v69) += __PAIR64__(v70, v69);
                  }
                }
                if ( (*(_BYTE *)(v57 + 2) & 8) != 0
                  && (*(_DWORD *)(v57 + 356) & *(_DWORD *)(*(_DWORD *)(v17 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v17 + 2360) + 260) )
                {
                  *(_QWORD *)(v17 + 2368) += __PAIR64__(v70, v69);
                }
                if ( *(_DWORD *)(v57 + 236) )
                  KiEndCounterAccumulation(v57);
              }
            }
          }
          v80 = v201[0];
          __enable_irq();
          *(_DWORD *)(v17 + 4) = v80;
          *((_BYTE *)v80 + 132) = 2;
          *(_BYTE *)(v57 + 395) = 32;
          *(_BYTE *)(v57 + 134) = v25;
          KiQueueReadyThread(v17, v57);
          if ( !KiSwapContext(v57, (int)v80, v25) )
            goto LABEL_29;
        }
        else if ( (*(_DWORD *)(v57 + 76) & 0x40) == 0 )
        {
          goto LABEL_29;
        }
        KfLowerIrql(1);
        *(_DWORD *)(v57 + 76) &= 0xFFFFFFBF;
        KiDeliverApc(0, 0, 0);
        goto LABEL_29;
      }
      if ( (*(_BYTE *)(v6 + 72) & 0x18) != 0 )
      {
        if ( (*(_BYTE *)(v6 + 72) & 8) != 0 )
        {
          v145 = (unsigned __int8 *)(v6 + 81);
          do
            v146 = __ldrex(v145);
          while ( __strex(v146 | 8, v145) );
        }
        v201[0] = 0;
        v147 = (unsigned int *)(v17 + 24);
        while ( 1 )
        {
          do
            v148 = __ldrex(v147);
          while ( __strex(1u, v147) );
          __dmb(0xBu);
          if ( !v148 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v147 );
        }
        if ( !*(_DWORD *)(v17 + 8) )
          KiSelectNextThread(v17, v201);
        __dmb(0xBu);
        *v147 = 0;
        KiProcessDeferredReadyList(v17, v201, v25);
        return v202;
      }
      v149 = *(_QWORD *)(v17 + 4);
      if ( HIDWORD(v149) )
      {
        KiAbProcessContextSwitch(v149, 0);
        v150 = (unsigned int *)(v17 + 24);
        while ( 1 )
        {
          do
            v151 = __ldrex(v150);
          while ( __strex(1u, v150) );
          __dmb(0xBu);
          if ( !v151 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v150 );
        }
        v152 = *(_DWORD **)(v17 + 8);
        *(_DWORD *)(v17 + 8) = 0;
        __disable_irq();
        v201[0] = v152;
        *(_BYTE *)(v17 + 16) = 1;
        LODWORD(v155) = ReadTimeStampCounter();
        v153 = *(_DWORD *)(v17 + 2376);
        v154 = *(_DWORD *)(v17 + 2380);
        v206 = v155;
        v157 = (unsigned __int64 *)(v149 + 48);
        v156 = (v155 - __PAIR64__(v154, v153)) >> 32;
        LODWORD(v155) = v155 - v153;
        v158 = *(_DWORD *)(v149 + 52);
        v159 = *(_DWORD *)(v149 + 48);
        v195 = v155;
        v204 = v156;
        __dmb(0xBu);
        do
          v160 = __ldrexd(v157);
        while ( __strexd(__PAIR64__(v158, v155) + __PAIR64__(v156, v159), v157) );
        __dmb(0xBu);
        v161 = __PAIR64__(v156, *(_DWORD *)(v149 + 56)) + (unsigned int)v155;
        if ( HIDWORD(v161) )
          LODWORD(v161) = -1;
        HIDWORD(v161) = v206;
        *(_DWORD *)(v17 + 2380) = HIDWORD(v155);
        *(_DWORD *)(v17 + 2376) = HIDWORD(v161);
        v162 = *(_BYTE *)(v149 + 2);
        *(_DWORD *)(v149 + 56) = v161;
        if ( (v162 & 0x3E) != 0 )
        {
          if ( (v162 & 0x10) != 0 )
          {
            v163 = *(_DWORD *)(v17 + 2376);
            v164 = v17 + 8 * *(unsigned __int8 *)(v149 + 84);
            v165 = *(_DWORD *)(v17 + 2384);
            v162 &= 0xEFu;
            v45 = v163 >= v165;
            HIDWORD(v155) = v163 - v165;
            v166 = *(_DWORD *)(v164 + 2392);
            LODWORD(v155) = *(_DWORD *)(v17 + 2380) - (*(_DWORD *)(v17 + 2388) + !v45);
            v167 = *(_DWORD *)(v164 + 2396);
            *(_DWORD *)(v164 + 2392) = v166 + HIDWORD(v155);
            v168 = v155 + __CFADD__(v166, HIDWORD(v155)) + v167;
            LODWORD(v155) = v195;
            *(_DWORD *)(v164 + 2396) = v168;
            *(_DWORD *)(v17 + 2384) = 0;
            *(_DWORD *)(v17 + 2388) = 0;
          }
          if ( (v162 & 0x3E) != 0 )
          {
            if ( (v162 & 0x20) != 0 )
            {
              v169 = *(_DWORD *)(v149 + 1084);
              if ( v169 )
              {
                v156 = v204;
                v170 = (unsigned __int64 *)(v169 + 8
                                                 * (*(unsigned __int8 *)(v17 + 2986) + 2 * PoGetFrequencyBucket(v17)));
                v171 = __PAIR64__(v204, v195) + *v170;
                __dmb(0xBu);
                do
                  v172 = __ldrexd(v170);
                while ( __strexd(v171, v170) );
                __dmb(0xBu);
                LODWORD(v155) = v195;
              }
              v152 = v201[0];
              v162 &= 0xDFu;
            }
            if ( (v162 & 0x3E) != 0 )
            {
              v173 = *(_DWORD *)(v149 + 68);
              if ( v173 )
              {
                for ( HIDWORD(v155) = v173 + *(_DWORD *)(v17 + 2352);
                      HIDWORD(v155);
                      HIDWORD(v155) = *(_DWORD *)(HIDWORD(v155) + 236) )
                {
                  *(_QWORD *)HIDWORD(v155) += __PAIR64__(v156, v155);
                }
              }
              if ( (*(_BYTE *)(v149 + 2) & 8) != 0
                && (*(_DWORD *)(v149 + 356) & *(_DWORD *)(*(_DWORD *)(v17 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v17 + 2360) + 260) )
              {
                *(_QWORD *)(v17 + 2368) += __PAIR64__(v156, v155);
              }
              if ( *(_DWORD *)(v149 + 236) )
                KiEndCounterAccumulation(v149);
            }
          }
        }
        __enable_irq();
        *(_DWORD *)(v17 + 4) = v152;
        *((_BYTE *)v152 + 132) = 2;
        *(_BYTE *)(v149 + 395) = 32;
        *(_BYTE *)(v149 + 134) = 1;
        KiQueueReadyThread(v17, v149);
        if ( !KiSwapContext(v149, (int)v152, 1) )
          goto LABEL_312;
      }
      else if ( (*(_DWORD *)(v149 + 76) & 0x40) == 0 )
      {
LABEL_312:
        KfLowerIrql(1);
        KiDeliverApc(0, 0, 0);
        v26 = (void (__fastcall **)(int))&KfLowerIrql;
        v27 = 0;
        goto LABEL_30;
      }
      KfLowerIrql(1);
      *(_DWORD *)(v149 + 76) &= 0xFFFFFFBF;
      KiDeliverApc(0, 0, 0);
      goto LABEL_312;
    }
    if ( v19 > 0 || v6 == *(_DWORD *)(v15 + 24) && *(unsigned __int8 *)(v15 + 2) == *(unsigned __int8 *)(v17 + 1754) )
    {
      v30 = *(_DWORD *)(v15 + 4);
      if ( v30 == 0x80000000 )
      {
        __dmb(0xBu);
        do
          v142 = __ldrex((unsigned int *)v15);
        while ( __strex(v142 & 0xFFFFFF7F, (unsigned int *)v15) );
        *(_BYTE *)(v6 + 132) = 2;
        __dmb(0xFu);
        v143 = *v10;
        __dmb(0xBu);
        if ( v143 )
        {
          while ( 1 )
          {
            do
              v144 = __ldrex(v10);
            while ( __strex(1u, v10) );
            __dmb(0xBu);
            if ( !v144 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v10 );
          }
          __dmb(0xBu);
          *v10 = 0;
        }
        KiExitThreadWait(v17, v6, v196);
        RtlRaiseStatus(-1073741423);
      }
      v31 = v30 - 1;
      *(_DWORD *)(v15 + 4) = v31;
      if ( v31 )
      {
        __dmb(0xBu);
        do
          v54 = __ldrex((unsigned int *)v15);
        while ( __strex(v54 & 0xFFFFFF7F, (unsigned int *)v15) );
        goto LABEL_26;
      }
      *(_DWORD *)(v6 + 136) = 0;
      while ( 1 )
      {
        do
          v32 = __ldrex(v10);
        while ( __strex(1u, v10) );
        __dmb(0xBu);
        if ( !v32 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v10 );
      }
      *(_WORD *)(v6 + 308) -= *(unsigned __int8 *)(v15 + 29);
      if ( *(_DWORD *)(v17 + 4) == v6 )
        v33 = *(_BYTE *)(v17 + 1754);
      else
        v33 = 0;
      v206 = *(_DWORD *)v15;
      BYTE2(v206) = v33;
      *(_DWORD *)v15 = v206;
      v34 = *(unsigned __int8 *)(v15 + 28);
      *(_DWORD *)(v15 + 24) = v6;
      if ( v34 )
      {
        *(_BYTE *)(v15 + 28) = 0;
        *(_DWORD *)(v6 + 136) |= 0x80u;
      }
      v35 = *(unsigned int **)(v6 + 480);
      v36 = v15 + 16;
      *(_DWORD *)(v15 + 16) = v6 + 476;
      *(_DWORD *)(v15 + 20) = v35;
      if ( *v35 != v6 + 476 )
        __fastfail(3u);
      *v35 = v36;
      *(_DWORD *)(v6 + 480) = v36;
      __dmb(0xBu);
      do
        v37 = __ldrex((unsigned int *)v15);
      while ( __strex(v37 & 0xFFFFFF7F, (unsigned int *)v15) );
      *(_BYTE *)(v6 + 132) = 2;
      __dmb(0xBu);
      *v10 = 0;
      v28 = *(_DWORD *)(v6 + 136);
      v38 = *(unsigned __int8 *)(v6 + 134);
      if ( (*(_BYTE *)(v6 + 72) & 0x38) == 0 )
      {
        if ( !v196 )
        {
LABEL_50:
          v39 = (void (__fastcall **)(int))&KfLowerIrql;
          v40 = v38;
          goto LABEL_51;
        }
        v120 = *(_DWORD *)(v17 + 8);
        if ( v38 >= 2 )
        {
          if ( v120 && !*(_BYTE *)(v17 + 1754) )
            goto LABEL_105;
          return v28;
        }
        v121 = *(_DWORD *)(v17 + 4);
        if ( v120 )
        {
          KiAbProcessContextSwitch(v121, 0);
          v122 = (unsigned int *)(v17 + 24);
          while ( 1 )
          {
            do
              v123 = __ldrex(v122);
            while ( __strex(1u, v122) );
            __dmb(0xBu);
            if ( !v123 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v122 );
          }
          v124 = *(_DWORD *)(v17 + 8);
          *(_DWORD *)(v17 + 8) = 0;
          v204 = v124;
          __disable_irq();
          *(_BYTE *)(v17 + 16) = 1;
          LODWORD(v125) = ReadTimeStampCounter();
          v126 = *(_DWORD *)(v17 + 2376);
          v127 = *(_DWORD *)(v17 + 2380);
          v129 = HIDWORD(v125);
          v206 = v125;
          v130 = (unsigned __int64 *)(v121 + 48);
          v128 = v125 - __PAIR64__(v127, v126);
          v188 = HIDWORD(v128);
          v191 = v128;
          v131 = *(_QWORD *)(v121 + 48) + v128;
          __dmb(0xBu);
          do
            v132 = __ldrexd(v130);
          while ( __strexd(v131, v130) );
          __dmb(0xBu);
          v133 = v121;
          v134 = v128 + *(unsigned int *)(v121 + 56);
          if ( HIDWORD(v134) )
          {
            v203 = 0;
            LODWORD(v134) = -1;
          }
          HIDWORD(v134) = v206;
          *(_DWORD *)(v17 + 2380) = v129;
          *(_DWORD *)(v17 + 2376) = HIDWORD(v134);
          v135 = *(unsigned __int8 *)(v121 + 2);
          *(_DWORD *)(v121 + 56) = v134;
          v206 = v135;
          if ( (v135 & 0x3E) != 0 )
          {
            if ( (v135 & 0x10) != 0 )
            {
              v135 = v17 + 8 * *(unsigned __int8 *)(v121 + 84);
              *(_QWORD *)(v135 + 2392) = *(_QWORD *)(v135 + 2392) - *(_QWORD *)(v17 + 2384) + *(_QWORD *)(v17 + 2376);
              v133 = v121;
              LOBYTE(v135) = v206 & 0xEF;
              *(_DWORD *)(v17 + 2384) = 0;
              *(_DWORD *)(v17 + 2388) = 0;
            }
            if ( (v135 & 0x3E) != 0 )
            {
              if ( (v135 & 0x20) != 0 )
              {
                v206 = *(_DWORD *)(v133 + 1084);
                if ( v206 )
                {
                  v136 = (unsigned __int64 *)(v206
                                            + 8 * (*(unsigned __int8 *)(v17 + 2986) + 2 * PoGetFrequencyBucket(v17)));
                  v137 = __PAIR64__(v188, v191) + *v136;
                  __dmb(0xBu);
                  do
                    v138 = __ldrexd(v136);
                  while ( __strexd(v137, v136) );
                  __dmb(0xBu);
                  LODWORD(v128) = v191;
                  v133 = v121;
                }
                LOBYTE(v135) = v135 & 0xDF;
              }
              if ( (v135 & 0x3E) != 0 )
              {
                v139 = *(_DWORD *)(v133 + 68);
                if ( v139 && (HIDWORD(v128) = v139 + *(_DWORD *)(v17 + 2352)) != 0 )
                {
                  v140 = v188;
                  do
                  {
                    *(_QWORD *)HIDWORD(v128) += __PAIR64__(v188, v128);
                    HIDWORD(v128) = *(_DWORD *)(HIDWORD(v128) + 236);
                  }
                  while ( HIDWORD(v128) );
                }
                else
                {
                  v140 = v188;
                }
                if ( (*(_BYTE *)(v133 + 2) & 8) != 0
                  && (*(_DWORD *)(*(_DWORD *)(v17 + 2360) + 260) & *(_DWORD *)(v133 + 356)) != *(_DWORD *)(*(_DWORD *)(v17 + 2360) + 260) )
                {
                  *(_QWORD *)(v17 + 2368) += __PAIR64__(v140, v128);
                }
                if ( *(_DWORD *)(v133 + 236) )
                  KiEndCounterAccumulation(v133);
              }
            }
          }
          v141 = v204;
          __enable_irq();
          *(_DWORD *)(v17 + 4) = v141;
          *(_BYTE *)(v141 + 132) = 2;
          *(_BYTE *)(v133 + 395) = 32;
          *(_BYTE *)(v133 + 134) = v38;
          KiQueueReadyThread(v17, v133);
          if ( !KiSwapContext(v133, v141, v38) )
            goto LABEL_50;
          KfLowerIrql(1);
          *(_DWORD *)(v133 + 76) &= 0xFFFFFFBF;
        }
        else
        {
          if ( (*(_DWORD *)(v121 + 76) & 0x40) == 0 )
            goto LABEL_50;
          KfLowerIrql(1);
          *(_DWORD *)(v121 + 76) &= 0xFFFFFFBF;
        }
        KiDeliverApc(0, 0, 0);
        goto LABEL_50;
      }
      if ( (*(_BYTE *)(v6 + 72) & 0x18) != 0 )
      {
        if ( (*(_BYTE *)(v6 + 72) & 8) != 0 )
        {
          v114 = (unsigned __int8 *)(v6 + 81);
          do
            v115 = __ldrex(v114);
          while ( __strex(v115 | 8, v114) );
        }
        v201[0] = 0;
        v116 = (unsigned int *)(v17 + 24);
        while ( 1 )
        {
          do
            v117 = __ldrex(v116);
          while ( __strex(1u, v116) );
          __dmb(0xBu);
          if ( !v117 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v116 );
        }
        if ( !*(_DWORD *)(v17 + 8) )
          KiSelectNextThread(v17, v201);
        __dmb(0xBu);
        *v116 = 0;
        KiProcessDeferredReadyList(v17, v201, v38);
        return v28;
      }
      v63 = *(_QWORD *)(v17 + 4);
      if ( HIDWORD(v63) )
      {
        KiAbProcessContextSwitch(v63, 0);
        v94 = (unsigned int *)(v17 + 24);
        while ( 1 )
        {
          do
            v95 = __ldrex(v94);
          while ( __strex(1u, v94) );
          __dmb(0xBu);
          if ( !v95 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v94 );
        }
        v96 = *(_DWORD *)(v17 + 8);
        *(_DWORD *)(v17 + 8) = 0;
        __disable_irq();
        v204 = v96;
        *(_BYTE *)(v17 + 16) = 1;
        LODWORD(v97) = ReadTimeStampCounter();
        v98 = *(_DWORD *)(v17 + 2376);
        v99 = *(_DWORD *)(v17 + 2380);
        v101 = HIDWORD(v97);
        v206 = v97;
        v102 = (unsigned __int64 *)(v63 + 48);
        v100 = v97 - __PAIR64__(v99, v98);
        v190 = HIDWORD(v100);
        v194 = v100;
        v103 = *(_QWORD *)(v63 + 48) + v100;
        __dmb(0xBu);
        do
          v104 = __ldrexd(v102);
        while ( __strexd(v103, v102) );
        __dmb(0xBu);
        v105 = v100 + *(unsigned int *)(v63 + 56);
        if ( HIDWORD(v105) )
        {
          v203 = 0;
          LODWORD(v105) = -1;
        }
        HIDWORD(v105) = v206;
        *(_DWORD *)(v17 + 2380) = v101;
        *(_DWORD *)(v17 + 2376) = HIDWORD(v105);
        v106 = *(unsigned __int8 *)(v63 + 2);
        *(_DWORD *)(v63 + 56) = v105;
        v206 = v106;
        if ( (v106 & 0x3E) != 0 )
        {
          if ( (v106 & 0x10) != 0 )
          {
            v118 = v17 + 8 * *(unsigned __int8 *)(v63 + 84);
            v119 = v206;
            *(_QWORD *)(v118 + 2392) = *(_QWORD *)(v118 + 2392) - *(_QWORD *)(v17 + 2384) + *(_QWORD *)(v17 + 2376);
            *(_DWORD *)(v17 + 2384) = 0;
            *(_DWORD *)(v17 + 2388) = 0;
            LOBYTE(v106) = v119 & 0xEF;
          }
          if ( (v106 & 0x3E) != 0 )
          {
            if ( (v106 & 0x20) != 0 )
            {
              v107 = *(_DWORD *)(v63 + 1084);
              if ( v107 )
              {
                v108 = (unsigned __int64 *)(v107 + 8
                                                 * (*(unsigned __int8 *)(v17 + 2986) + 2 * PoGetFrequencyBucket(v17)));
                v109 = v190;
                v110 = __PAIR64__(v190, v194) + *v108;
                __dmb(0xBu);
                do
                  v111 = __ldrexd(v108);
                while ( __strexd(v110, v108) );
                __dmb(0xBu);
                LODWORD(v100) = v194;
              }
              else
              {
                v109 = HIDWORD(v100);
              }
              LOBYTE(v106) = v106 & 0xDF;
            }
            else
            {
              v109 = HIDWORD(v100);
            }
            if ( (v106 & 0x3E) != 0 )
            {
              v112 = *(_DWORD *)(v63 + 68);
              if ( v112 )
              {
                for ( HIDWORD(v100) = v112 + *(_DWORD *)(v17 + 2352);
                      HIDWORD(v100);
                      HIDWORD(v100) = *(_DWORD *)(HIDWORD(v100) + 236) )
                {
                  *(_QWORD *)HIDWORD(v100) += __PAIR64__(v109, v100);
                }
              }
              if ( (*(_BYTE *)(v63 + 2) & 8) != 0
                && (*(_DWORD *)(v63 + 356) & *(_DWORD *)(*(_DWORD *)(v17 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v17 + 2360) + 260) )
              {
                *(_QWORD *)(v17 + 2368) += __PAIR64__(v109, v100);
              }
              if ( *(_DWORD *)(v63 + 236) )
                KiEndCounterAccumulation(v63);
            }
          }
        }
        v113 = v204;
        __enable_irq();
        *(_DWORD *)(v17 + 4) = v113;
        *(_BYTE *)(v113 + 132) = 2;
        *(_BYTE *)(v63 + 395) = 32;
        *(_BYTE *)(v63 + 134) = 1;
        KiQueueReadyThread(v17, v63);
        if ( !KiSwapContext(v63, v113, 1) )
          goto LABEL_119;
      }
      else if ( (*(_DWORD *)(v63 + 76) & 0x40) == 0 )
      {
LABEL_119:
        KfLowerIrql(1);
        KiDeliverApc(0, 0, 0);
        KfLowerIrql(0);
        return v28;
      }
      KfLowerIrql(1);
      *(_DWORD *)(v63 + 76) &= 0xFFFFFFBF;
      KiDeliverApc(0, 0, 0);
      goto LABEL_119;
    }
LABEL_20:
    v20 = v189;
    if ( v189 == 2 )
    {
      v41 = MEMORY[0xFFFF93B0];
      v200 = MEMORY[0xFFFF93B4];
      while ( 1 )
      {
        HIDWORD(v42) = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        LODWORD(v42) = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( HIDWORD(v42) == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v43 = (unsigned __int64)(v42 - *(_QWORD *)(v6 + 160)) >> 32;
      v44 = v42 - *(_DWORD *)(v6 + 160);
      v45 = v44 >= v41;
      v46 = v44 - v41;
      v22 = HIDWORD(v187);
      v21 = v187;
      v47 = v43 - (v200 + !v45);
    }
    else
    {
      v21 = v187;
      if ( !v189 )
        goto LABEL_58;
      v22 = HIDWORD(v187);
      if ( !v187 )
        goto LABEL_23;
      while ( 1 )
      {
        v47 = MEMORY[0xFFFF9018];
        __dmb(0xBu);
        v46 = MEMORY[0xFFFF9014];
        __dmb(0xBu);
        if ( v47 == MEMORY[0xFFFF901C] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v20 = v189;
    }
    v16 = (_DWORD *)(v6 + 216);
    v10 = (unsigned int *)(v6 + 44);
    if ( v47 > v21 || v47 >= v21 && v46 > v22 )
    {
LABEL_23:
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)v15);
      while ( __strex(v23 & 0xFFFFFF7F, (unsigned int *)v15) );
      v202 = 258;
      goto LABEL_26;
    }
LABEL_58:
    v48 = *(_DWORD **)(v15 + 12);
    *v16 = v15 + 8;
    v16[1] = v48;
    if ( *v48 != v15 + 8 )
      __fastfail(3u);
    *v48 = v16;
    *(_DWORD *)(v15 + 12) = v16;
    __dmb(0xBu);
    do
      v49 = __ldrex((unsigned int *)v15);
    while ( __strex(v49 & 0xFFFFFF7F, (unsigned int *)v15) );
    *(_BYTE *)(v6 + 363) = 1;
    v28 = KiCommitThreadWait(v6, v16, v20);
    if ( v28 != 256 )
      return v28;
    v196 = 0;
    v5 = v201[0];
    *(_BYTE *)(v6 + 134) = KfRaiseIrql(2);
  }
  *(_BYTE *)(v6 + 122) = 1;
LABEL_101:
  v28 = 192;
LABEL_102:
  __dmb(0xBu);
  *v10 = 0;
  v58 = (unsigned int)KeGetPcr();
  v59 = (v58 & 0xFFFFF000) + 1408;
  v60 = *(_DWORD *)((v58 & 0xFFFFF000) + 0x588);
  if ( v11 < 2 )
  {
    v62 = *(_DWORD *)(v59 + 4);
    if ( v60 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(v59 + 4), 0);
      v81 = (unsigned int *)(v59 + 24);
      while ( 1 )
      {
        do
          v82 = __ldrex(v81);
        while ( __strex(1u, v81) );
        __dmb(0xBu);
        if ( !v82 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v81 );
      }
      v83 = *(_DWORD *)(v59 + 8);
      *(_DWORD *)(v59 + 8) = 0;
      __disable_irq();
      v206 = v83;
      *(_BYTE *)(v59 + 16) = 1;
      LODWORD(v84) = ReadTimeStampCounter();
      v87 = HIDWORD(v84);
      v86 = v84;
      v88 = (unsigned __int64 *)(v62 + 48);
      v85 = v84 - *(_QWORD *)(v59 + 2376);
      v193 = HIDWORD(v85);
      v198 = v85;
      v89 = v85 + *(_QWORD *)(v62 + 48);
      __dmb(0xBu);
      do
        v90 = __ldrexd(v88);
      while ( __strexd(v89, v88) );
      __dmb(0xBu);
      v91 = v85 + *(unsigned int *)(v62 + 56);
      if ( HIDWORD(v91) )
      {
        v205 = 0;
        LODWORD(v91) = -1;
      }
      *(_DWORD *)(v59 + 2376) = v86;
      *(_DWORD *)(v59 + 2380) = v87;
      v92 = *(_BYTE *)(v62 + 2);
      *(_DWORD *)(v62 + 56) = v91;
      if ( (v92 & 0x3E) != 0 )
      {
        if ( (v92 & 0x10) != 0 )
        {
          v180 = v59 + 8 * *(unsigned __int8 *)(v62 + 84);
          *(_QWORD *)(v180 + 2392) = *(_QWORD *)(v180 + 2392) - *(_QWORD *)(v59 + 2384) + *(_QWORD *)(v59 + 2376);
          *(_DWORD *)(v59 + 2384) = 0;
          *(_DWORD *)(v59 + 2388) = 0;
          v92 &= 0xEFu;
        }
        if ( (v92 & 0x3E) != 0 )
        {
          if ( (v92 & 0x20) != 0 )
          {
            v181 = *(_DWORD *)(v62 + 1084);
            if ( v181 )
            {
              v182 = (unsigned __int64 *)(v181 + 8 * (*(unsigned __int8 *)(v59 + 2986) + 2 * PoGetFrequencyBucket(v59)));
              v183 = v193;
              v184 = __PAIR64__(v193, v198) + *v182;
              __dmb(0xBu);
              do
                v185 = __ldrexd(v182);
              while ( __strexd(v184, v182) );
              __dmb(0xBu);
              LODWORD(v85) = v198;
            }
            else
            {
              v183 = HIDWORD(v85);
            }
            v92 &= 0xDFu;
          }
          else
          {
            v183 = HIDWORD(v85);
          }
          if ( (v92 & 0x3E) != 0 )
          {
            v186 = *(_DWORD *)(v62 + 68);
            if ( v186 )
            {
              for ( HIDWORD(v85) = v186 + *(_DWORD *)(v59 + 2352);
                    HIDWORD(v85);
                    HIDWORD(v85) = *(_DWORD *)(HIDWORD(v85) + 236) )
              {
                *(_QWORD *)HIDWORD(v85) += __PAIR64__(v183, v85);
              }
            }
            if ( (*(_BYTE *)(v62 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v59 + 2360) + 260) & *(_DWORD *)(v62 + 356)) != *(_DWORD *)(*(_DWORD *)(v59 + 2360) + 260) )
            {
              *(_QWORD *)(v59 + 2368) += __PAIR64__(v183, v85);
            }
            if ( *(_DWORD *)(v62 + 236) )
              KiEndCounterAccumulation(v62);
          }
        }
      }
      v93 = v206;
      __enable_irq();
      *(_DWORD *)(v59 + 4) = v93;
      *(_BYTE *)(v93 + 132) = 2;
      *(_BYTE *)(v62 + 395) = 32;
      *(_BYTE *)(v62 + 134) = v199;
      KiQueueReadyThread(v59, v62);
      if ( !KiSwapContext(v62, v93, v199) )
        goto LABEL_111;
    }
    else if ( (*(_DWORD *)(v62 + 76) & 0x40) == 0 )
    {
LABEL_111:
      KfLowerIrql(v199);
      return v28;
    }
    KfLowerIrql(1);
    *(_DWORD *)(v62 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_111;
  }
  if ( v60 && !*(_BYTE *)(v59 + 1754) )
  {
LABEL_105:
    v39 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
    v40 = 2;
LABEL_51:
    (*v39)(v40);
  }
  return v28;
}
