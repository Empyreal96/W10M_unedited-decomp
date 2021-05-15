// MiResolveDemandZeroFault 
 
int __fastcall MiResolveDemandZeroFault(int a1, unsigned int a2, int a3, unsigned int a4, int a5, unsigned __int8 a6, int a7)
{
  unsigned int v7; // lr
  unsigned int v8; // r5
  int v9; // r1
  _DWORD *v10; // r9
  int v11; // r10
  unsigned int v12; // r7
  int v13; // r0
  int v14; // r8
  int v15; // r3
  int v16; // r4
  unsigned int v17; // r3
  unsigned int v18; // r6
  unsigned int v19; // r10
  unsigned int v20; // lr
  unsigned int v21; // r1
  unsigned int v22; // r0
  char v23; // r3
  _WORD *v24; // r9
  int v25; // r2
  unsigned int v26; // r7
  unsigned int v27; // r1
  int v28; // r8
  int v29; // r1
  int v30; // r3
  int v31; // r3
  int v32; // r2
  int v33; // r0
  int v34; // r4
  int v35; // r10
  int v36; // r3
  unsigned int *v37; // lr
  int v38; // r1
  unsigned int v39; // r6
  int v40; // r8
  unsigned int *v41; // lr
  int v42; // r0
  unsigned int v43; // r6
  int v44; // r8
  int v45; // r3
  int v46; // r7
  int v47; // r3
  unsigned int *v48; // r9
  int v49; // r1
  unsigned int v50; // r4
  int v51; // r2
  int v52; // r3
  int v53; // lr
  int v54; // r2
  int v55; // r4
  int v56; // r3
  unsigned int v57; // r6
  int v58; // r5
  unsigned __int8 *v59; // r3
  unsigned int v60; // r1
  unsigned __int8 *v61; // r3
  unsigned int v62; // r1
  unsigned int *v63; // r0
  unsigned int v64; // r4
  char v65; // r4
  char v66; // r0
  unsigned int v67; // r6
  unsigned int v68; // r1
  int v69; // r1
  int v70; // r4
  unsigned int v71; // r2
  int v72; // r0
  unsigned int *v73; // r2
  unsigned int v74; // r0
  unsigned int *v75; // r2
  unsigned int v76; // r1
  int v78; // r2
  char v79; // r3
  unsigned int *v80; // lr
  int v81; // r10
  int v82; // r0
  unsigned int v83; // r6
  int v84; // r2
  char v85; // r3
  unsigned int v86; // r3
  unsigned int v87; // r3
  int v88; // r3
  int v89; // r3
  int v90; // r4
  int v91; // r10
  int v92; // r0
  unsigned int v93; // r6
  _QWORD *v94; // r2
  unsigned int v95; // r3
  unsigned int v96; // r9
  unsigned int v97; // r4
  unsigned int v98; // r7
  unsigned int v99; // r10
  unsigned int v100; // r2
  unsigned int v101; // t1
  int v102; // r0
  int v103; // r3
  unsigned int v104; // r2
  int v105; // r6
  int v106; // r4
  int v107; // r3
  int v108; // r7
  unsigned int v109; // r8
  int v110; // r1
  int *v111; // lr
  int v112; // r9
  int v113; // r6
  int v114; // r3
  unsigned int v115; // r10
  unsigned int v116; // r1
  int v117; // r4
  int v118; // r3
  unsigned int v119; // r6
  unsigned int v120; // r3
  unsigned int v121; // r2
  bool v122; // zf
  int v123; // r7
  int *v124; // r6
  unsigned int i; // r4
  int v126; // t1
  int v127; // r0
  unsigned int *v128; // r2
  unsigned int v129; // r1
  int v130; // r0
  unsigned int v131; // r3
  unsigned int v132; // r3
  unsigned int v133; // r0
  unsigned int v134; // r1
  unsigned __int8 *v135; // r1
  int v136; // r3
  unsigned int v137; // r2
  unsigned int *v138; // r2
  unsigned int v139; // r3
  unsigned int v140; // t1
  unsigned int v141; // r0
  unsigned int v142; // r1
  unsigned int v143; // r0
  unsigned int v144; // r1
  unsigned int v145; // r0
  unsigned int v146; // r1
  unsigned int v147; // r0
  unsigned int v148; // r1
  char v149; // r1
  unsigned __int8 *v150; // r1
  unsigned int v151; // r3
  unsigned int v152; // r2
  int v153; // r2
  int v154; // r0
  unsigned int *v155; // r2
  unsigned int v156; // r4
  int v157; // r0
  int v158; // r5
  int v159; // r4
  unsigned int v160; // r2
  unsigned int v161; // r4
  int v162; // r0
  int v163; // r3
  int v164; // r0
  int v165; // r2
  int v166; // r4
  char v167; // r1
  int v168; // r2
  int v169; // r0
  int v170; // r3
  int v171; // r4
  int v172; // r0
  unsigned int v173; // [sp+10h] [bp-80h]
  int v174; // [sp+14h] [bp-7Ch]
  int v175; // [sp+14h] [bp-7Ch]
  unsigned int v176; // [sp+14h] [bp-7Ch]
  unsigned int v177; // [sp+18h] [bp-78h] BYREF
  unsigned int v178; // [sp+1Ch] [bp-74h]
  int v179; // [sp+20h] [bp-70h]
  _DWORD *v180; // [sp+24h] [bp-6Ch]
  unsigned int v181; // [sp+28h] [bp-68h]
  int v182; // [sp+2Ch] [bp-64h]
  unsigned int v183; // [sp+30h] [bp-60h] BYREF
  unsigned int v184; // [sp+34h] [bp-5Ch] BYREF
  unsigned int v185; // [sp+38h] [bp-58h]
  int v186; // [sp+3Ch] [bp-54h]
  _DWORD *v187; // [sp+40h] [bp-50h]
  unsigned int v188; // [sp+44h] [bp-4Ch]
  int v189; // [sp+48h] [bp-48h]
  int v190; // [sp+4Ch] [bp-44h]
  char v191[4]; // [sp+50h] [bp-40h] BYREF
  int v192; // [sp+54h] [bp-3Ch]
  int v193; // [sp+58h] [bp-38h] BYREF
  int v194; // [sp+5Ch] [bp-34h]
  int v195; // [sp+60h] [bp-30h]
  int v196; // [sp+64h] [bp-2Ch]
  int v197; // [sp+68h] [bp-28h]
  int v198; // [sp+6Ch] [bp-24h]
  unsigned int v199; // [sp+70h] [bp-20h]

  v7 = a4;
  v173 = a4;
  v179 = 0;
  v180 = (_DWORD *)a1;
  v181 = a2;
  v8 = 0;
  v9 = a3 & 1;
  v182 = v9;
  v190 = a3;
  v10 = (_DWORD *)a1;
  v177 = 1;
  v184 = 1;
  if ( (a3 & 1) != 0 && *(_BYTE *)(a3 & 0xFFFFFFFE) == 2 )
  {
    v8 = 4;
  }
  else if ( (a3 & 1) != 0 )
  {
    if ( *(_BYTE *)(a3 & 0xFFFFFFFE) == 1 )
      return sub_535990();
    if ( *(_BYTE *)(a3 & 0xFFFFFFFE) == 5 )
      v8 = 32;
  }
  if ( (v8 & 0x2C) != 0 )
  {
    v187 = (_DWORD *)(a3 & 0xFFFFFFFE);
    if ( (v8 & 8) != 0 )
    {
      if ( (*(_DWORD *)((a3 & 0xFFFFFFFE) + 0x28) & 0x4000) == 0 )
        return 0;
      v8 |= 0x10u;
    }
  }
  else
  {
    v187 = 0;
  }
  v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v185 = v11;
  if ( (a3 & 1) != 0 )
    v12 = a3 & 0xFFFFFFFE;
  else
    v12 = 0;
  v13 = a5;
  v14 = 0;
  v15 = *(_DWORD *)(a5 + 92);
  v16 = 0;
  v174 = 0;
  v193 = 0;
  if ( v15 == -1069539328 )
  {
    v17 = v181;
    if ( v181 < 0xC0000000 || v181 > 0xC03FFFFF )
    {
      if ( !v12 )
      {
        if ( MEMORY[0xC040213C] != 1 )
          goto LABEL_11;
        v17 = v181;
      }
      v130 = MiLocateAddress(v17);
      if ( !v130
        || (v131 = *(_DWORD *)(v130 + 28), v16 = v130, v193 = v130, v14 = (v131 >> 8) & 0x3F, (v174 = v14) != 0) )
      {
        v7 = v173;
        v9 = v182;
      }
      else
      {
        v9 = v182;
        v7 = v173;
        if ( (v131 & 0x8000) == 0 )
        {
          v14 = (*(_DWORD *)(**(_DWORD **)(v130 + 44) + 28) >> 20) & 0x3F;
          v174 = v14;
        }
      }
      v13 = a5;
    }
    if ( v12 && !v14 && *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
    {
      v132 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(unsigned __int16 *)(*(_DWORD *)(v132 + 116) + 2 * *(unsigned __int16 *)(v132 + 360) + 112) + 1;
      v174 = v14;
    }
  }
  else
  {
    if ( (a3 & 1) != 0 && *(_BYTE *)(v190 & 0xFFFFFFFE) == 4 )
      v14 = *(unsigned __int8 *)(v12 + 20);
    v174 = v14;
  }
LABEL_11:
  if ( *(_DWORD *)(v13 + 92) == -1069539328 )
    v8 |= 1u;
  v192 = 4194300;
  v186 = 0x40000000;
  if ( v16
    || v11 == PsInitialSystemProcess
    && v7 <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000
    && v7 >= 0xC0000000
    && (v16 = MiLocateAddress(v181), v9 = v182, v13 = a5, (v193 = v16) != 0) )
  {
    if ( (*(_DWORD *)(v16 + 32) & 0x7FFFFFFF) == 524286 )
      v179 = 64;
  }
  if ( !a7 )
  {
    v189 = v8 & 1;
    if ( (v8 & 1) != 0 && *(_DWORD *)(v11 + 264) )
    {
      if ( MiWaitForForkToComplete(v11, a6, 1) == 1 )
        return -1073740748;
      v9 = v182;
      v13 = a5;
    }
    v18 = v173;
    v19 = (*(_DWORD *)v173 >> 5) & 0x1F;
    v183 = v19;
    if ( v9 && *(_BYTE *)(v190 & 0xFFFFFFFE) == 4 )
    {
      v19 = 4;
      v183 = 4;
    }
    v199 = (v8 >> 4) & 1;
    if ( v199 && v19 >> 3 != 1 && (v19 >> 3 != 3 || (v19 & 7) == 0) )
    {
      MiAdvanceFaultList(v187);
      return 0;
    }
    if ( v16 && (v8 & 0x14) != 0 )
    {
      v133 = MiComputeZeroClusterMaximum((int)v187, v16);
      v134 = 1;
      v177 = 1;
      if ( v133 > 1 )
      {
        v138 = (unsigned int *)(v173 + 4);
        do
        {
          v140 = *v138++;
          v139 = v140;
          if ( (v140 & 2) != 0 )
            break;
          if ( (v139 & 0x400) != 0 )
            break;
          if ( (v139 & 0x800) != 0 )
            break;
          if ( (v139 & 0x10) != 0 )
            break;
          if ( v19 != ((v139 >> 5) & 0x1F) )
            break;
          ++v134;
        }
        while ( v134 < v133 );
        v177 = v134;
      }
      v13 = a5;
      v184 = v134;
      v9 = v182;
    }
    if ( v189
      || (*(_BYTE *)(v13 + 112) & 7) == 1
      || v181 >= dword_63389C
      && *((_BYTE *)&MiState[2423] + ((int)(((v181 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 12
      || PsNtosImageBase
      && (v181 >= PsNtosImageBase && v181 < PsNtosImageEnd || v181 >= PsHalImageBase && v181 < PsHalImageEnd) )
    {
      if ( v19 >> 3 == 3 && (v19 & 7) != 0 )
      {
        v20 = 578;
      }
      else if ( v19 >> 3 == 1 )
      {
        v20 = 322;
      }
      else
      {
        v20 = 194;
      }
    }
    else if ( v9 && *(_BYTE *)(v190 & 0xFFFFFFFE) == 4 )
    {
      v20 = 8;
    }
    else
    {
      v20 = 0;
    }
    v178 = v20;
    if ( v14 )
    {
      v21 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
      v198 = (unsigned __int16)((v14 + 0xFFFF) << byte_6337F5);
    }
    else
    {
      v21 = (unsigned int)*(&KiProcessorBlock + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C));
      v198 = (unsigned __int16)*(_DWORD *)(v21 + 2732);
    }
    v22 = (unsigned __int16)((1 << byte_6337FC) - 1);
    v23 = *(_BYTE *)(a5 + 112);
    v188 = v22;
    if ( (v23 & 7u) >= 2 )
      v24 = (_WORD *)(v21 + 2724);
    else
      v24 = (_WORD *)(a5 + 96);
    v25 = 1;
    v196 = v19 >> 3;
    v194 = (int)v24;
    if ( v19 >> 3 == 3 && (v19 & 7) != 0 )
    {
      v25 = 2;
    }
    else if ( v19 >> 3 == 1 )
    {
      v25 = 0;
    }
    v26 = 0;
    v175 = 0;
    v180 = (_DWORD *)MiPlatformCacheAttributes[v25];
    v27 = v177;
    v197 = 0xFFFFF;
    v28 = 0xFFFFF;
    v195 = 0;
    if ( !v177 )
      goto LABEL_53;
    while ( 1 )
    {
      v29 = v198;
      v30 = (unsigned __int16)(*v24 + 1);
      *v24 = v30;
      v31 = v30 & v22;
      if ( (v20 & 2) != 0 )
        v32 = 2;
      else
        v32 = 0;
      v33 = MiGetPage(MiSystemPartition, v29 | v31, v32);
      v34 = v33;
      if ( v33 == -1 )
      {
        v35 = v195;
LABEL_277:
        v27 = v26;
        v177 = v26;
LABEL_50:
        if ( v35 )
        {
          MiChangePageAttributeBatch(v35, v180, 0);
          v27 = v177;
        }
        v18 = v173;
        v19 = v183;
LABEL_53:
        v44 = v175;
        if ( v175 )
        {
          v45 = 273;
          v194 = 273;
          if ( (v8 & 0x20) != 0 )
            v180 = v187;
          else
            v180 = 0;
          v176 = 0;
          if ( v27 )
          {
            v178 = 0x3FFFFF;
            do
            {
              v46 = v44;
              v188 = *(_DWORD *)v18;
              v47 = *(_DWORD *)(v44 + 12) & 0xFFFFF;
              if ( v47 == v197 )
                v44 = 0;
              else
                v44 = MmPfnDatabase + 24 * v47;
              v48 = (unsigned int *)(v46 + 12);
              v49 = *(_DWORD *)(v46 + 12);
              do
                v50 = __ldrex(v48);
              while ( v50 == v49 && __strex(v49 & 0xFFF00000, v48) );
              if ( v49 != v50 )
              {
                do
                {
                  v147 = v50;
                  do
                    v148 = __ldrex(v48);
                  while ( v148 == v50 && __strex(v50 & 0xFFF00000, v48) );
                  v50 = v148;
                }
                while ( v147 != v148 );
              }
              v183 = (v46 - MmPfnDatabase) / 24;
              v51 = v179 | 0x10;
              v179 |= 0x10u;
              if ( (!v182 || *(_BYTE *)(v190 & 0xFFFFFFFE) != 4)
                && v19 != 31
                && (v19 & 2) != 0
                && (v181 < 0xC0000000 || v181 > 0xC03FFFFF)
                && (BYTE2(MiFlags) & 3u) > 1 )
              {
                v149 = 2;
                if ( (v19 & 4) != 0 && (v19 & 5) != 5 )
                  v149 = 3;
                MiMarkPfnVerified(v46, v149);
                v51 = v179;
              }
              if ( v199 )
              {
                v51 |= 0x20u;
                v179 = v51;
              }
              v52 = *(_DWORD *)v18;
              if ( (v51 & 4) != 0 )
                v52 = 32 * v19;
              *(_DWORD *)(v46 + 8) = v52;
              if ( (v51 & 2) != 0 )
                *(_DWORD *)(v46 + 20) |= 0x8000000u;
              v53 = 1;
              if ( v19 == 31 )
              {
                v53 = 1;
              }
              else if ( v196 == 3 )
              {
                if ( (v19 & 7) != 0 )
                  v53 = 2;
              }
              else if ( v196 == 1 )
              {
                v53 = 0;
              }
              *(_WORD *)(v46 + 16) = 1;
              if ( (v51 & 0x20) == 0 )
                *(_BYTE *)(v46 + 18) |= 0x10u;
              v54 = *(_DWORD *)((v192 & (v18 >> 10)) - v186) >> 12;
              *(_DWORD *)(v46 + 20) = *(_DWORD *)(v46 + 20) & 0xFFF00000 | ((unsigned __int16)HIWORD(*(_DWORD *)((v192 & (v18 >> 10)) - v186)) >> 4);
              v55 = MmPfnDatabase + 24 * v54;
              v56 = __mrc(15, 0, 13, 0, 3);
              if ( (*(_DWORD *)((v56 & 0xFFFFFFC0) + 0x3C8) & 0x100) != 0 )
              {
                v57 = (*(_DWORD *)((v56 & 0xFFFFFFC0) + 0x3C8) & 0xE00u) >> 9;
              }
              else
              {
                v57 = (*(_DWORD *)((v56 & 0xFFFFFFC0) + 0x3C0) >> 12) & 7;
                if ( (*(_DWORD *)(*(_DWORD *)((v56 & 0xFFFFFFC0) + 0x150) + 192) & 0x100000) != 0 && v57 >= 2 )
                  LOBYTE(v57) = 2;
              }
              v58 = v179 & 1;
              if ( (v179 & 1) == 0 )
              {
                v59 = (unsigned __int8 *)(v46 + 15);
                do
                  v60 = __ldrex(v59);
                while ( __strex(v60 | 0x80, v59) );
                __dmb(0xBu);
                if ( v60 >> 7 )
                {
                  v150 = (unsigned __int8 *)(v46 + 15);
                  do
                  {
                    do
                    {
                      __dmb(0xAu);
                      __yield();
                      v151 = *v48;
                      __dmb(0xBu);
                    }
                    while ( (v151 & 0x80000000) != 0 );
                    do
                      v152 = __ldrex(v150);
                    while ( __strex(v152 | 0x80, v150) );
                    __dmb(0xBu);
                  }
                  while ( v152 >> 7 );
                }
              }
              v61 = (unsigned __int8 *)(v55 + 15);
              do
                v62 = __ldrex(v61);
              while ( __strex(v62 | 0x80, v61) );
              __dmb(0xBu);
              if ( v62 >> 7 )
              {
                v135 = (unsigned __int8 *)(v55 + 15);
                do
                {
                  do
                  {
                    __dmb(0xAu);
                    __yield();
                    v136 = *(_DWORD *)(v55 + 12);
                    __dmb(0xBu);
                  }
                  while ( (v136 & 0x80000000) != 0 );
                  do
                    v137 = __ldrex(v135);
                  while ( __strex(v137 | 0x80, v135) );
                  __dmb(0xBu);
                }
                while ( v137 >> 7 );
              }
              *(_DWORD *)(v55 + 12) = *(_DWORD *)(v55 + 12) & 0xC0000000 | ((*(_DWORD *)(v55 + 12) & 0x3FFFFFFF) + 1) & 0x3FFFFFFF;
              __dmb(0xBu);
              v63 = (unsigned int *)(v55 + 12);
              do
                v64 = __ldrex(v63);
              while ( __strex(v64 & 0x7FFFFFFF, v63) );
              if ( *(unsigned __int8 *)(v46 + 18) >> 6 != v53 )
                MiChangePageAttribute(v46, v53, 1);
              *(_DWORD *)(v46 + 12) = *(_DWORD *)(v46 + 12) & 0xC0000000 | 1;
              v65 = v179;
              v66 = (*(_BYTE *)(v46 + 19) ^ v57) & 7 ^ *(_BYTE *)(v46 + 19);
              v67 = v173;
              *(_BYTE *)(v46 + 18) = *(_BYTE *)(v46 + 18) & 0xF8 | 6;
              *(_BYTE *)(v46 + 19) = v66;
              *(_DWORD *)(v46 + 4) = v173;
              if ( (v65 & 0x40) != 0 )
                *(_BYTE *)(v46 + 19) = v66 | 0x20;
              if ( !v58 )
              {
                __dmb(0xBu);
                do
                  v68 = __ldrex(v48);
                while ( __strex(v68 & 0x7FFFFFFF, v48) );
              }
              if ( (v65 & 8) != 0 )
                *(_DWORD *)(v46 + 8) = v188;
              if ( v199 )
              {
                v153 = 32 * (v19 & 0x1F | (v183 << 7) | 0x40);
                if ( v186 + v173 > v178 )
                {
                  *(_DWORD *)v173 = v153;
                }
                else
                {
                  __dmb(0xBu);
                  *(_DWORD *)v173 = v153;
                  if ( v173 + 1070596096 <= 0xFFF )
                  {
                    v154 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                    MiArmWriteConvertedHardwarePde(v154, v154 + 4 * (v173 & 0xFFF), v153);
                  }
                }
                if ( v189 )
                {
                  v155 = (unsigned int *)(v185 + 276);
                  do
                    v156 = __ldrex(v155);
                  while ( __strex(v156 + 1, v155) );
                }
                MiLockAndDecrementShareCount(v46, 0);
                MiAdvanceFaultList(v187);
              }
              else
              {
                v69 = v186;
                if ( v173 > (v192 & ((unsigned int)MmHighestUserAddress >> 10)) - v186 || v173 < 0xC0000000 )
                {
                  v70 = a5;
                  if ( (*(_BYTE *)(a5 + 112) & 7u) < 2 )
                    v87 = MmProtectToPteMask[v19] & 0xFED | (v183 << 12) | MiDetermineUserGlobalPteMask(v173);
                  else
                    v87 = (MmProtectToPteMask[v19] & 0x3ED | (v183 << 12) | MiDetermineUserGlobalPteMask(v173)) & 0xFFFFF3FF;
                  v69 = v186;
                  v71 = v87 | 0x12;
                }
                else
                {
                  v70 = a5;
                  v71 = (MmProtectToPteMask[v19] | (v183 << 12)) & 0xFFFFFBFF | 0x832;
                }
                if ( (v71 & 0x80) != 0 )
                  v71 &= 0xFFFFFDFF;
                if ( v182 && *(_BYTE *)(v190 & 0xFFFFFFFE) == 4 )
                {
                  if ( v173 + v69 > v178 )
                  {
                    *(_DWORD *)v173 = v71;
                  }
                  else
                  {
                    v89 = *(_DWORD *)v173;
                    v90 = 0;
                    __dmb(0xBu);
                    *(_DWORD *)v173 = v71;
                    if ( (v89 & 2) == 0 )
                      v90 = 1;
                    if ( v173 >= 0xC0300000 && v173 <= 0xC0300FFF )
                    {
                      v157 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                      MiArmWriteConvertedHardwarePde(v157, v157 + 4 * (v173 & 0xFFF), v71);
                    }
                    if ( v90 == 1 )
                    {
                      __dsb(0xFu);
                      __isb(0xFu);
                    }
                  }
                }
                else
                {
                  v72 = MiAllocateWsle(v70, v173, v46, 0, v71, v180);
                  v180 = 0;
                  if ( v72 )
                  {
                    if ( v189 )
                    {
                      v73 = (unsigned int *)(v185 + 276);
                      do
                        v74 = __ldrex(v73);
                      while ( __strex(v74 + 1, v73) );
                    }
                  }
                  else
                  {
                    v158 = 3 * (*(_DWORD *)(v46 + 20) & 0xFFFFF);
                    v159 = MmPfnDatabase;
                    MiReleaseFreshPage(v46);
                    MiLockAndDecrementShareCount(v159 + 8 * v158, 0);
                    if ( !v176 )
                      v194 = -1073741801;
                    v160 = v176 + 1;
                    v176 = v160;
                    if ( v160 < v177 )
                    {
                      v161 = v177 - v160;
                      v176 = v177;
                      do
                      {
                        v162 = v44;
                        v163 = *(_DWORD *)(v44 + 12) & 0xFFFFF;
                        if ( v163 == v197 )
                          v44 = 0;
                        else
                          v44 = MmPfnDatabase + 24 * v163;
                        MiReleaseFreshPage(v162);
                        --v161;
                      }
                      while ( v161 );
                      v67 = v173;
                    }
                  }
                  v75 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2964);
                  do
                    v76 = __ldrex(v75);
                  while ( __strex(v76 + 1, v75) );
                }
              }
              v18 = v67 + 4;
              v173 = v18;
              ++v176;
            }
            while ( v176 < v177 );
            v45 = v194;
          }
          return v45;
        }
        return -1073741801;
      }
      v175 = MmPfnDatabase + 24 * v33;
      if ( *(_DWORD *)(v175 + 8) && (v178 & 0x40) != 0 )
      {
        MiZeroPhysicalPage(v33, 1, v180);
        v78 = v175;
        *(_DWORD *)(v175 + 8) = 0;
        __dmb(0xFu);
        v79 = KiTbFlushTimeStamp;
        __dmb(0xBu);
        v80 = (unsigned int *)(v78 + 12);
        v81 = v79 & 0xF;
        v82 = *(_DWORD *)(v78 + 12);
        do
          v83 = __ldrex(v80);
        while ( v83 == v82 && __strex(v82 & 0xFF0FFFFF | (v81 << 20), v80) );
        if ( v82 != v83 )
        {
          do
          {
            v141 = v83;
            do
              v142 = __ldrex(v80);
            while ( v142 == v83 && __strex(v83 & 0xFF0FFFFF | (v81 << 20), v80) );
            v83 = v142;
          }
          while ( v141 != v142 );
          v24 = (_WORD *)v194;
        }
        v177 = v184;
      }
      v35 = v175;
      v36 = *(unsigned __int8 *)(v175 + 18) >> 6;
      if ( (_DWORD *)v36 != v180 )
      {
        if ( v180 != (_DWORD *)1 )
          goto LABEL_149;
        if ( v36 == 3 )
        {
          MiChangePageAttribute(v175, 1, 4);
        }
        else
        {
          v84 = (*(_DWORD *)(v175 + 12) >> 20) & 0xF;
          __dmb(0xFu);
          v85 = KiTbFlushTimeStamp;
          __dmb(0xBu);
          v86 = (v85 - (_BYTE)v84) & 0xF;
          if ( v86 <= 2 && ((v84 & 1) != 0 || v86 < 2) )
          {
            v177 = v184;
LABEL_149:
            v88 = v195;
            v195 = v175;
            *(_DWORD *)(v175 + 8) = v88;
            goto LABEL_43;
          }
          MiChangePageAttribute(v175, 1, 4);
          v177 = v184;
        }
      }
      v37 = (unsigned int *)(v175 + 12);
      v38 = *(_DWORD *)(v175 + 12);
      do
        v39 = __ldrex(v37);
      while ( v39 == v38 && __strex(v38 & 0xFF0FFFFF, v37) );
      if ( v38 != v39 )
      {
        do
        {
          v143 = v39;
          do
            v144 = __ldrex(v37);
          while ( v144 == v39 && __strex(v39 & 0xFF0FFFFF, v37) );
          v39 = v144;
        }
        while ( v143 != v144 );
      }
      v35 = v195;
LABEL_43:
      v40 = v28 & 0xFFFFF;
      v41 = (unsigned int *)(v175 + 12);
      v42 = *(_DWORD *)(v175 + 12);
      do
        v43 = __ldrex(v41);
      while ( v43 == v42 && __strex(v42 & 0xFFF00000 | v40, v41) );
      if ( v42 != v43 )
      {
        do
        {
          v145 = v43;
          do
            v146 = __ldrex(v41);
          while ( v146 == v43 && __strex(v43 & 0xFFF00000 | v40, v41) );
          v43 = v146;
        }
        while ( v145 != v146 );
      }
      ++v26;
      v28 = v34;
      if ( (v26 & 0xF) == 0 && ExSpinLockIsContended(a5) || KeShouldYieldProcessor() )
        goto LABEL_277;
      v27 = v177;
      LOBYTE(v20) = v178;
      v22 = v188;
      if ( v26 >= v177 )
        goto LABEL_50;
    }
  }
  v91 = 0;
  v178 = 0x3FFFFF;
  v189 = 0;
  if ( (v8 & 0x14) != 0 && (v8 & 1) != 0 )
  {
    v92 = MiCheckVirtualAddress(v181, &v183, &v193);
    v93 = v183;
    if ( (v8 & 0x10) != 0 && v183 >> 3 != 1 && (v183 >> 3 != 3 || (v183 & 7) == 0) )
    {
      MiUnlockProtoPoolPage(MmPfnDatabase + 24 * (*(_DWORD *)((v192 & (v173 >> 10)) - 0x40000000) >> 12), 17);
      return 0;
    }
    if ( v92 && v193 && v183 != 24 && (v183 & 0xFFFFFFF8) != 16 )
    {
      v94 = *(_QWORD **)(v193 + 68);
      if ( (int)v94 < 0 )
      {
        v8 |= 2u;
        v95 = (*v94 - 1i64) >> 12;
      }
      else
      {
        v95 = 0;
      }
      v185 = v95;
      v96 = (v181 >> 12) + 1;
      v188 = MiComputeZeroClusterMaximum((int)v187, v193);
      v97 = (v192 & (v181 >> 10)) - v186;
      v98 = 1;
      if ( v188 > 1 )
      {
        v196 = 134217721;
        v99 = v192 & (v181 >> 10);
        do
        {
          v101 = *(_DWORD *)(v97 + 4);
          v97 += 4;
          v100 = v101;
          v99 += 4;
          if ( v101
            && ((v100 & 2) != 0 || (v100 & 0x400) == 0 || (v100 & 0xFFFFE000) != -8192 || ((v100 >> 5) & 0x1F) != v93) )
          {
            break;
          }
          v102 = MiGetProtoPteAddress(v193, v96, 0, &v177);
          if ( !v102 || ((v173 ^ v102) & 0xFFFFF000) != 0 || (v8 & 2) != 0 && v96 - *(_DWORD *)(v193 + 12) > v185 )
            break;
          v103 = *(_DWORD *)v102;
          if ( (*(_DWORD *)v102 & 2) != 0 || !v103 || (v103 & 0xC00) != 0 || (v103 & 0x10) != 0 )
            break;
          if ( v93 == 256 )
            v104 = v102 & 0x1FC | (4 * (v102 & 0xFFFFFE00 | 0x100));
          else
            v104 = 32 * (v93 & 0x1F | 0xFFFFFF20);
          if ( !*(_DWORD *)v97 )
          {
            if ( v99 > v178 )
            {
              *(_DWORD *)v97 = v104;
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)v97 = v104;
              if ( v97 >= 0xC0300000 && v97 <= 0xC0300FFF )
              {
                v164 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v164, v164 + 4 * (v97 & 0xFFF), v104);
              }
            }
            ++v189;
          }
          ++v98;
          ++v96;
        }
        while ( v98 < v188 );
        v14 = v174;
        v91 = v189;
      }
      v184 = v98;
      if ( v91 )
        MiUpdatePageTableUseCount(v181, v91);
      v10 = v180;
    }
  }
  v105 = MmPfnDatabase;
  v106 = 3 * (*(_DWORD *)((v192 & (v173 >> 10)) - 0x40000000) >> 12);
  v107 = (*(_DWORD *)v173 >> 5) & 0x1F;
  v196 = v106;
  v188 = MmPfnDatabase;
  v108 = MiGetZeroedPages(MiSystemPartition, a5, v14, v107, 66, &v184);
  if ( !v108 )
  {
    MiUnlockProtoPoolPage(v105 + 8 * v106, 17);
    return -1073741801;
  }
  v109 = v184;
  if ( v184 )
  {
    v110 = 0xFFFFF;
    v111 = MiState;
    v185 = v184;
    v197 = 0xFFFFF;
    v112 = (v8 >> 4) & 1;
    do
    {
      v113 = v108;
      v114 = *(_DWORD *)(v108 + 12) & 0xFFFFF;
      if ( v114 == v110 )
        v108 = 0;
      else
        v108 = MmPfnDatabase + 24 * v114;
      v115 = (v113 - MmPfnDatabase) / 24;
      if ( (MiFlags & 0x80) != 0 && v115 < 0x200000 && (*(_BYTE *)(MmPfnDatabase + 24 * v115 + 19) & 0x40) == 0 )
      {
        v165 = v111[1637] + 1;
        v111[1637] = v165;
        if ( (MmPageValidationFrequency & v165) == 0 )
        {
          if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
          {
            v166 = MiMapPageInHyperSpaceWorker(v115, v191, 0x80000000);
            if ( RtlCompareMemoryUlong(v166, 4096, 0) != 4096 )
              MiPageNotZero(v166, v115);
            MiUnmapPageInHyperSpaceWorker(v166, (unsigned __int8)v191[0], 0x80000000);
          }
        }
      }
      v116 = v173;
      v117 = (*(_DWORD *)v173 >> 5) & 0x1F;
      if ( (BYTE2(MiFlags) & 3u) > 1 && ((*(_DWORD *)v173 >> 5) & 2) != 0 )
      {
        v167 = 2;
        if ( ((*(_DWORD *)v173 >> 5) & 4) != 0 && ((*(_DWORD *)v173 >> 5) & 5) != 5 )
          v167 = 3;
        MiMarkPfnVerified(v113, v167);
        v116 = v173;
      }
      v118 = v179 | 0x112;
      v179 |= 0x112u;
      if ( v112 || v117 != 4 && v117 != 6 )
      {
        v118 |= 0x20u;
        v179 = v118;
      }
      MiInitializePfn(v113, v116, v117, v118);
      if ( v112 )
      {
        v168 = 32 * (v117 & 0x1F | (v115 << 7) | 0x40);
        if ( v173 + 0x40000000 > v178 )
        {
          *(_DWORD *)v173 = v168;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v173 = v168;
          if ( v173 + 1070596096 <= 0xFFF )
          {
            v169 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v169, v169 + 4 * (v173 & 0xFFF), v168);
          }
        }
        MiLockAndDecrementShareCount(v113, 0);
        MiAdvanceFaultList(v187);
        v119 = v173;
      }
      else
      {
        v119 = v173;
        if ( v173 > (v192 & ((unsigned int)MmHighestUserAddress >> 10)) - v186 || v173 < 0xC0000000 )
        {
          if ( (*(_BYTE *)(a5 + 112) & 7u) >= 2 )
            v120 = (MmProtectToPteMask[v117] & 0x3ED | (v115 << 12) | MiDetermineUserGlobalPteMask(v173)) & 0xFFFFF3FF;
          else
            v120 = MmProtectToPteMask[v117] & 0xFED | (v115 << 12) | MiDetermineUserGlobalPteMask(v173);
          v121 = v120 | 0x12;
        }
        else
        {
          v121 = (MmProtectToPteMask[v117] | (v115 << 12)) & 0xFFFFFBFF | 0x832;
        }
        if ( (v121 & 0x80) != 0 )
          v121 &= 0xFFFFFDFF;
        if ( v173 + 0x40000000 <= v178 )
        {
          v170 = *(_DWORD *)v173;
          v171 = 0;
          __dmb(0xBu);
          *(_DWORD *)v173 = v121;
          if ( (v170 & 2) == 0 )
            v171 = 1;
          if ( v173 + 1070596096 <= 0xFFF )
          {
            v172 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v172, v172 + 4 * (v173 & 0xFFF), v121);
          }
          if ( v171 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        else
        {
          *(_DWORD *)v173 = v121;
        }
      }
      v122 = v185 == 1;
      v111 = MiState;
      v110 = v197;
      --v185;
      v173 = v119 + 4;
    }
    while ( !v122 );
    v10 = v180;
    v109 = v184;
    v106 = v196;
    v105 = v188;
  }
  MiUnlockProtoPoolPage(v105 + 8 * v106, 17);
  v123 = 273;
  v124 = (int *)(v173 - 4 * v109);
  if ( (v8 & 0x10) != 0 )
    v109 = 0;
  for ( i = 0; i < v109; ++i )
  {
    v126 = *v124++;
    v127 = MiCompleteProtoPteFault(a5, a6, v181, v126, v10, 1, v190);
    v181 += 4096;
    if ( !i )
    {
      if ( v127 < 0 )
        v123 = v127;
      if ( (v8 & 0x20) != 0 )
        v190 = 0;
    }
    v128 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2964);
    do
      v129 = __ldrex(v128);
    while ( __strex(v129 + 1, v128) );
  }
  return v123;
}
