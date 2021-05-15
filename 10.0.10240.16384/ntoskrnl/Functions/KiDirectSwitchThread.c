// KiDirectSwitchThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiDirectSwitchThread(int a1, char a2)
{
  int *v2; // r3
  int v4; // r8
  int v5; // r2
  int v6; // r3
  int v8; // r9
  int v9; // r5
  int v10; // r0
  int v11; // r4
  __int64 v12; // r0
  unsigned __int64 *v13; // r4
  __int64 v14; // kr18_8
  unsigned __int64 v15; // kr20_8
  unsigned __int64 v16; // r2
  __int64 v17; // r2
  char v18; // lr
  int v19; // r0
  int v20; // r2
  int v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r2
  unsigned __int64 *v24; // r4
  unsigned __int64 v25; // kr30_8
  unsigned __int64 v26; // kr38_8
  __int64 v27; // r0
  int v28; // lr
  __int64 v29; // kr40_8
  unsigned __int64 *v30; // r3
  unsigned __int64 v31; // kr48_8
  __int64 v32; // kr50_8
  int v33; // r2
  int v34; // r3
  unsigned int v35; // r1
  unsigned int v36; // r3
  unsigned __int64 *v37; // r4
  unsigned __int64 v38; // kr58_8
  unsigned __int64 v39; // kr60_8
  unsigned __int64 *v40; // r1
  unsigned __int64 v41; // kr68_8
  unsigned __int64 *v42; // r1
  unsigned int v43; // r0
  unsigned int v44; // r4
  unsigned __int64 v45; // kr78_8
  unsigned int *v46; // r1
  unsigned int v47; // r2
  int v48; // r6
  char v49; // r5
  unsigned int v50; // r1
  int v51; // r4
  unsigned int v52; // r3
  int v53; // r4
  int v54; // r0
  int v55; // r2
  char v56; // r3
  char v57; // r4
  int v58; // r4
  int v59; // r10
  unsigned int *v60; // r6
  unsigned int v61; // r2
  int v62; // r5
  unsigned int v63; // lr
  unsigned int v64; // r0
  unsigned int v65; // r3
  unsigned int v66; // r9
  unsigned int v67; // r0
  int v68; // lr
  unsigned __int8 *v69; // r3
  unsigned int v70; // r2
  unsigned __int64 v71; // r2
  char v72; // r3
  char v73; // r2
  unsigned int v75; // r2
  int v76; // r3
  unsigned int v77; // r1
  int v78; // r3
  int v79; // r1
  int j; // r1
  int v81; // r2
  int v82; // r4
  int v83; // r2
  unsigned int v84; // r3
  int v85; // r2
  int v86; // r1
  unsigned __int64 v87; // kr88_8
  unsigned __int8 *v88; // r3
  unsigned int v89; // r2
  unsigned __int8 *v90; // r5
  unsigned int v91; // r2
  int v92; // r1 OVERLAPPED
  _DWORD *v93; // r2 OVERLAPPED
  unsigned int v94; // r1
  unsigned int v95; // r1
  unsigned int v96; // r5
  unsigned int v97; // r6
  int i; // r0
  int v99; // r3
  int v100; // r1
  unsigned int v101; // r2
  int v102; // r6
  signed int v103; // r3
  unsigned int v104; // [sp+0h] [bp-60h]
  unsigned int v105; // [sp+4h] [bp-5Ch]
  unsigned int v106; // [sp+8h] [bp-58h]
  unsigned __int64 v107; // [sp+Ch] [bp-54h]
  unsigned int v108; // [sp+1Ch] [bp-44h]
  int v109; // [sp+20h] [bp-40h]
  int v110; // [sp+24h] [bp-3Ch]
  char v111; // [sp+28h] [bp-38h]
  BOOL v113; // [sp+30h] [bp-30h]
  unsigned __int64 *v114; // [sp+38h] [bp-28h]

  v2 = *(int **)(a1 + 1540);
  v4 = (int)(v2 - 36);
  v5 = *v2;
  *(_DWORD *)(a1 + 1540) = *v2;
  if ( !*(_DWORD *)(a1 + 8) )
  {
    v6 = *(v2 - 16);
    if ( (v6 & 0x10000) != 0 && (v6 & 0x40000) == 0 )
    {
      if ( (dword_682604 & 0x200) != 0 )
        return sub_52BBA8();
      v8 = *(_DWORD *)(a1 + 4);
      v9 = *(_DWORD *)(v4 + 68);
      v109 = v9;
      if ( v9 )
      {
        v9 += *(_DWORD *)(a1 + 2352);
        v109 = v9;
      }
      v105 = 0;
      v106 = 0;
      if ( !v9 )
        goto LABEL_9;
      v105 = KiGetThreadEffectiveRankNonZero(v4, v9, 1);
      if ( !v105 )
        goto LABEL_9;
      v81 = *(_DWORD *)(v8 + 68);
      if ( !v81 )
        goto LABEL_9;
      v82 = *(_DWORD *)(a1 + 2352) + v81;
      if ( !v82 )
        goto LABEL_9;
      v106 = KiGetThreadEffectiveRankNonZero(v8, v82, 1);
      if ( !v106 )
        goto LABEL_9;
      v83 = v9;
      if ( v9 == v82 )
      {
        v84 = *(_DWORD *)(v9 + 96);
        v106 = v84;
        goto LABEL_149;
      }
      v95 = *(unsigned __int8 *)(v9 + 93);
      v96 = *(unsigned __int8 *)(v82 + 93);
      v97 = 0;
      i = 0;
      v106 = 0;
      if ( v95 <= v96 )
      {
        if ( v95 >= v96 )
        {
LABEL_198:
          if ( v83 != v82 )
          {
            v99 = *(_DWORD *)(v83 + 236);
            v100 = *(_DWORD *)(v82 + 236);
            for ( i = 0; v99 != v100; v100 = *(_DWORD *)(v100 + 236) )
            {
              v83 = v99;
              v99 = *(_DWORD *)(v99 + 236);
              v82 = v100;
            }
          }
          if ( i )
          {
            if ( i > 0 )
            {
              v105 = v97;
              v106 = 0;
LABEL_9:
              v110 = 0;
              v111 = 1;
              v10 = *(_DWORD *)(v4 + 140);
              v11 = v10 + 24 * *(unsigned __int8 *)(v4 + 363);
              do
              {
                if ( *(unsigned __int8 *)(v10 + 9) < 5u )
                {
                  v90 = *(unsigned __int8 **)(v10 + 16);
                  do
                    v91 = __ldrex(v90);
                  while ( __strex(v91 | 0x80, v90) );
                  __dmb(0xBu);
                  if ( v91 >> 7 )
                  {
                    do
                    {
                      do
                      {
                        __dmb(0xAu);
                        __yield();
                      }
                      while ( (*(_DWORD *)v90 & 0x80) != 0 );
                      do
                        v101 = __ldrex(v90);
                      while ( __strex(v101 | 0x80, v90) );
                      __dmb(0xBu);
                    }
                    while ( v101 >> 7 );
                  }
                  if ( *(_BYTE *)(v10 + 9) == 4 )
                  {
                    *(_QWORD *)&v92 = *(_QWORD *)v10;
                    if ( *(_DWORD *)(*(_DWORD *)v10 + 4) != v10 || *v93 != v10 )
                      __fastfail(3u);
                    *v93 = v92;
                    *(_DWORD *)(v92 + 4) = v93;
                  }
                  __dmb(0xBu);
                  do
                    v94 = __ldrex((unsigned int *)v90);
                  while ( __strex(v94 & 0xFFFFFF7F, (unsigned int *)v90) );
                }
                v10 += 24;
              }
              while ( v10 != v11 );
              v113 = *(_DWORD *)(a1 + 1540) == 0;
              __disable_irq();
              *(_BYTE *)(a1 + 16) = 1;
              LODWORD(v12) = ReadTimeStampCounter();
              v13 = (unsigned __int64 *)(v8 + 48);
              v14 = v12 - *(_QWORD *)(a1 + 2376);
              v15 = *(_QWORD *)(v8 + 48) + v14;
              v107 = v15;
              __dmb(0xBu);
              do
                v16 = __ldrexd(v13);
              while ( __strexd(v15, v13) );
              __dmb(0xBu);
              v17 = v14 + *(unsigned int *)(v8 + 56);
              if ( HIDWORD(v17) )
                LODWORD(v17) = -1;
              *(_QWORD *)(a1 + 2376) = v12;
              v18 = *(_BYTE *)(v8 + 2);
              *(_DWORD *)(v8 + 56) = v17;
              if ( (v18 & 0x3E) != 0 )
              {
                if ( (v18 & 0x10) != 0 )
                {
                  v102 = a1 + 8 * *(unsigned __int8 *)(v8 + 84);
                  *(_QWORD *)(v102 + 2392) = *(_QWORD *)(v102 + 2392) - *(_QWORD *)(a1 + 2384) + *(_QWORD *)(a1 + 2376);
                  *(_DWORD *)(a1 + 2384) = 0;
                  *(_DWORD *)(a1 + 2388) = 0;
                  v18 &= 0xEFu;
                }
                if ( (v18 & 0x3E) != 0 )
                {
                  if ( (v18 & 0x20) != 0 )
                  {
                    v19 = *(_DWORD *)(v8 + 1084);
                    if ( v19 )
                    {
                      v20 = *(_DWORD *)(a1 + 3200);
                      v21 = *(_DWORD *)(a1 + 3204);
                      if ( v20 && v21 )
                      {
                        v22 = *(_DWORD *)(v21 + 44);
                        if ( v22 >= *(_DWORD *)(v20 + 148) )
                          v22 = *(_DWORD *)(v20 + 148);
                      }
                      else
                      {
                        v22 = 100;
                      }
                      v23 = v22 / 0x19;
                      if ( v22 / 0x19 >= 3 )
                        v23 = 3;
                      v24 = (unsigned __int64 *)(v19 + 8 * (*(unsigned __int8 *)(a1 + 2986) + 2 * v23));
                      v25 = *v24 + v14;
                      __dmb(0xBu);
                      do
                        v26 = __ldrexd(v24);
                      while ( __strexd(v25, v24) );
                      __dmb(0xBu);
                    }
                    v18 &= 0xDFu;
                  }
                  if ( (v18 & 0x3E) != 0 )
                  {
                    v79 = *(_DWORD *)(v8 + 68);
                    if ( v79 )
                    {
                      for ( j = v79 + *(_DWORD *)(a1 + 2352); j; j = *(_DWORD *)(j + 236) )
                        *(_QWORD *)j += v14;
                    }
                    if ( (*(_BYTE *)(v8 + 2) & 8) != 0
                      && (*(_DWORD *)(*(_DWORD *)(a1 + 2360) + 260) & *(_DWORD *)(v8 + 356)) != *(_DWORD *)(*(_DWORD *)(a1 + 2360) + 260) )
                    {
                      *(_QWORD *)(a1 + 2368) += v14;
                    }
                    if ( *(_DWORD *)(v8 + 236) )
                      KiEndCounterAccumulation(v8);
                  }
                }
              }
              LODWORD(v27) = ReadTimeStampCounter();
              v28 = HIDWORD(v27);
              v29 = v27 - *(_QWORD *)(a1 + 2376);
              __dmb(0xBu);
              v30 = (unsigned __int64 *)(a1 + 2744);
              do
                v31 = __ldrexd(v30);
              while ( __strexd(v31 + v29, v30) );
              __dmb(0xBu);
              if ( (*(_BYTE *)(v8 + 2) & 0x20) != 0 )
              {
                v32 = v27 - *(_QWORD *)(a1 + 2376);
                v33 = *(_DWORD *)(a1 + 3200);
                v34 = *(_DWORD *)(a1 + 3204);
                if ( v33 && v34 )
                {
                  v35 = *(_DWORD *)(v34 + 44);
                  if ( v35 >= *(_DWORD *)(v33 + 148) )
                    v35 = *(_DWORD *)(v33 + 148);
                }
                else
                {
                  v35 = 100;
                }
                v36 = v35 / 0x19;
                if ( v35 / 0x19 >= 3 )
                  v36 = 3;
                v37 = (unsigned __int64 *)(a1 + 8 * (*(unsigned __int8 *)(a1 + 2986) + 2 * (v36 + 1144)));
                v38 = *v37 + v32;
                __dmb(0xBu);
                do
                  v39 = __ldrexd(v37);
                while ( __strexd(v38, v37) );
                __dmb(0xBu);
              }
              *(_DWORD *)(a1 + 2376) = v27;
              *(_DWORD *)(a1 + 2380) = v28;
              if ( (*(_BYTE *)(v8 + 2) & 0x10) != 0 )
              {
                *(_DWORD *)(a1 + 2384) = v27;
                *(_DWORD *)(a1 + 2388) = v28;
              }
              if ( (*(_BYTE *)(v8 + 2) & 2) != 0 )
                KiBeginCounterAccumulation(v8, 0);
              *(_BYTE *)(a1 + 16) = 0;
              __enable_irq();
              __dmb(0xBu);
              v40 = (unsigned __int64 *)(v8 + 24);
              v114 = (unsigned __int64 *)(v8 + 24);
              do
                v41 = __ldrexd(v40);
              while ( !v41 && __strexd(0i64, v40) );
              __dmb(0xBu);
              v42 = (unsigned __int64 *)(v4 + 48);
              while ( 1 )
              {
                v43 = *(_DWORD *)(v4 + 52);
                v44 = *(_DWORD *)v42;
                v108 = *(_DWORD *)v42;
                v104 = v43;
                do
                  v45 = __ldrexd(v42);
                while ( __PAIR64__(v45, HIDWORD(v45)) == __PAIR64__(v44, v43) && __strexd(__PAIR64__(v43, v44), v42) );
                if ( __PAIR64__(v44, v43) == __PAIR64__(v45, HIDWORD(v45)) )
                  break;
                __dmb(0xAu);
                __yield();
              }
              v46 = (unsigned int *)(v4 + 44);
              while ( 1 )
              {
                do
                  v47 = __ldrex(v46);
                while ( __strex(1u, v46) );
                __dmb(0xBu);
                if ( !v47 )
                  break;
                do
                {
                  __dmb(0xAu);
                  __yield();
                }
                while ( *v46 );
              }
              if ( *(unsigned __int8 *)(a1 + 1052) != *(unsigned __int16 *)(v4 + 360)
                || (*(_DWORD *)(a1 + 1048) & *(_DWORD *)(v4 + 356)) == 0 )
              {
                goto LABEL_114;
              }
              v111 = 0;
              v48 = a2;
              if ( *(char *)(v4 + 123) >= 16 )
              {
                v58 = 1;
              }
              else
              {
                v49 = 0;
                v50 = KeTickCount - *(_DWORD *)(v4 + 304);
                if ( __PAIR64__(v43, v44) >= *(_QWORD *)(v4 + 24) )
                {
                  v49 = 4;
                  if ( v50 < 2 )
                    v49 = 5;
                }
                if ( (v49 & 4) != 0 || *(char *)(v4 + 347) >= 14 || v50 >= 2 && !*(_BYTE *)(v4 + 348) )
                {
                  v51 = *(char *)(v4 + 123);
                  v49 |= 8u;
                  if ( v51 < 16 )
                  {
                    v51 = (char)(-(*(_BYTE *)(v4 + 348) & 0xF) - (*(_BYTE *)(v4 + 348) >> 4) + v51 - 1);
                    if ( v51 < *(char *)(v4 + 347) )
                      v51 = *(char *)(v4 + 347);
                    if ( *(_BYTE *)(v4 + 348) )
                    {
                      if ( (*(_BYTE *)(v4 + 348) & 0xF) != 0 )
                        *(_DWORD *)(v4 + 812) = KeTickCount;
                      *(_BYTE *)(v4 + 348) = 0;
                    }
                    v52 = *(_DWORD *)(v4 + 800);
                    if ( v52 )
                    {
                      v103 = 31 - __clz(v52);
                      if ( v51 < v103 )
                        v51 = (char)v103;
                    }
                    v48 = a2;
                  }
                  KiAbProcessThreadPriorityModification(v4, v51, 1);
                  *(_BYTE *)(v4 + 123) = v51;
                }
                if ( *(_BYTE *)(*(_DWORD *)(v4 + 336) + 606) == 2 )
                  v49 |= 2u;
                if ( (v49 & 1) != 0
                  || (*(_DWORD *)(v4 + 80) & 2) != 0
                  || *(_BYTE *)(v4 + 348) && ((*(_BYTE *)(v4 + 348) & 0xF0) != 0 || (v49 & 2) == 0) )
                {
                  if ( (v49 & 4) != 0 && (v49 & 2) != 0 && (*(_DWORD *)(v4 + 80) & 2) == 0 )
                    KiScheduleNextForegroundBoost(v4);
                }
                else
                {
                  v53 = *(char *)(v4 + 347);
                  v54 = v53 + v48;
                  v55 = v53 + v48;
                  if ( (v49 & 2) != 0 )
                    v55 = v54 + (char)PsPrioritySeparation;
                  if ( v55 >= 16 )
                    v55 = 15;
                  if ( v55 > *(char *)(v4 + 123) )
                  {
                    v56 = 0;
                    if ( v55 > v54 )
                      v56 = v55 - v53 - v48;
                    v57 = v55;
                    *(_BYTE *)(v4 + 348) ^= (v56 ^ *(_BYTE *)(v4 + 348)) & 0xF;
                    KiAbProcessThreadPriorityModification(v4, (char)v55, 1);
                    *(_BYTE *)(v4 + 123) = v57;
                  }
                }
                v58 = (unsigned __int8)(v49 & 8) >> 3;
              }
              v59 = *(char *)(v4 + 123);
              v60 = (unsigned int *)(a1 + 24);
              while ( 1 )
              {
                do
                  v61 = __ldrex(v60);
                while ( __strex(1u, v60) );
                __dmb(0xBu);
                if ( !v61 )
                  break;
                do
                {
                  __dmb(0xAu);
                  __yield();
                }
                while ( *v60 );
              }
              v62 = *(char *)(v8 + 123);
              if ( !*(_DWORD *)(a1 + 8) )
              {
                if ( v105 <= v106 && (v105 != v106 || v59 > v62) )
                {
                  *(_BYTE *)(v8 + 349) = 1;
                  goto LABEL_136;
                }
                v63 = 1 << v59;
                v64 = *(_DWORD *)(*(_DWORD *)(a1 + 3460) + 4) | *(_DWORD *)(a1 + 1932);
                if ( v15 + (unsigned int)KiDirectQuantumTarget > v41 )
                {
                  v65 = v105;
                }
                else
                {
                  v65 = v105;
                  if ( !v105 )
                  {
                    if ( v62 >= 16 )
                    {
                      if ( v59 >= 16 )
                        v62 = v59;
                      else
                        v62 = 15;
                    }
                    v66 = v104;
                    if ( (v64 & v63) != 0 )
                    {
                      v68 = (__PAIR64__(v104, v108) + (unsigned int)KiDirectQuantumTarget) >> 32;
                      v67 = v108 + KiDirectQuantumTarget;
                      v107 = v41 - (unsigned int)KiDirectQuantumTarget;
                    }
                    else
                    {
                      v68 = (__PAIR64__(v104, v108) - v15 + v41) >> 32;
                      v67 = v108 - v15 + v41;
                    }
                    v58 = 0;
                    __dmb(0xBu);
                    v69 = (unsigned __int8 *)(v4 + 80);
                    do
                      v70 = __ldrex(v69);
                    while ( __strex(v70 | 0x10, v69) );
                    __dmb(0xBu);
                    *(_DWORD *)(v4 + 24) = v67;
                    *(_DWORD *)(v4 + 28) = v68;
                    __dmb(0xBu);
                    do
                      v71 = __ldrexd(v114);
                    while ( __strexd(v107, v114) );
                    __dmb(0xBu);
                    if ( v59 != v62 )
                    {
                      KiAbProcessThreadPriorityModification(v4, (char)v62, 1);
                      v72 = *(_BYTE *)(v4 + 348);
                      *(_BYTE *)(v4 + 123) = v62;
                      v58 = 0;
                      *(_BYTE *)(v4 + 348) = v72 + 16 * (v62 - v59);
                    }
                    goto LABEL_109;
                  }
                }
                if ( v63 > v64 )
                {
                  if ( !v65 )
                    goto LABEL_136;
                  if ( v64 <= 1 )
                  {
                    v75 = *(_DWORD *)(*(_DWORD *)(v109 + 240) + 96);
                    v76 = *(_DWORD *)(a1 + 1980);
                    if ( v76 )
                    {
                      v77 = *(_DWORD *)(v76 + 16);
                      if ( v77 == v75 )
                      {
                        if ( *(unsigned __int16 *)(v76 + 14) < v63 )
                        {
LABEL_132:
                          v78 = 1;
                          goto LABEL_133;
                        }
                      }
                      else if ( v77 > v75 )
                      {
                        goto LABEL_132;
                      }
                      v78 = 0;
LABEL_133:
                      v66 = v104;
                      if ( !v78 )
                        goto LABEL_112;
LABEL_109:
                      v110 = 1;
                      *(_BYTE *)(v4 + 349) = 0;
                      *(_DWORD *)(v4 + 328) = *(_DWORD *)(a1 + 20);
                      if ( (*(_BYTE *)(v4 + 2) & 4) != 0 )
                      {
                        if ( *(char *)(v4 + 123) < 16
                          && *(_DWORD *)(v4 + 68)
                          && (v85 = *(_DWORD *)(v4 + 68)) != 0
                          && (v86 = v85 + *(_DWORD *)(a1 + 2352)) != 0
                          && KiGetThreadEffectiveRankNonZero(v4, v86, 0) )
                        {
                          v73 = 1;
                        }
                        else
                        {
                          v73 = *(_BYTE *)(v4 + 123);
                        }
                      }
                      else
                      {
                        v73 = *(_BYTE *)(v4 + 123);
                      }
                      **(_BYTE **)(a1 + 28) = v73;
                      *(_DWORD *)(a1 + 8) = v4;
                      *(_BYTE *)(v4 + 132) = 3;
                      goto LABEL_112;
                    }
LABEL_136:
                    v66 = v104;
                    goto LABEL_109;
                  }
                }
              }
              v66 = v104;
LABEL_112:
              __dmb(0xBu);
              *v60 = 0;
              if ( v58 )
              {
                v87 = __PAIR64__(v66, (unsigned int)*(unsigned __int8 *)(v4 + 403) * KiCyclesPerClockQuantum) + v108;
                if ( (*(_DWORD *)(v4 + 80) & 0x10) != 0 )
                {
                  __dmb(0xBu);
                  v88 = (unsigned __int8 *)(v4 + 80);
                  do
                    v89 = __ldrex(v88);
                  while ( __strex(v89 & 0xEF, v88) );
                  __dmb(0xBu);
                }
                *(_QWORD *)(v4 + 24) = v87;
              }
              v46 = (unsigned int *)(v4 + 44);
LABEL_114:
              __dmb(0xBu);
              *v46 = 0;
              if ( !v110 )
              {
                *(_BYTE *)(v4 + 350) = v111;
                *(_BYTE *)(v4 + 351) = a2;
                KiDeferredReadyThread(a1, v4);
              }
              return v113;
            }
            v84 = 0;
          }
          else
          {
            v84 = *(_DWORD *)(v83 + 96);
            v106 = *(_DWORD *)(v82 + 96);
          }
LABEL_149:
          v105 = v84;
          goto LABEL_9;
        }
        i = -1;
        do
        {
          if ( *(_DWORD *)(v82 + 96) > v97 )
            v97 = *(_DWORD *)(v82 + 96);
          v82 = *(_DWORD *)(v82 + 236);
        }
        while ( v95 < *(unsigned __int8 *)(v82 + 93) );
      }
      else
      {
        i = 1;
        do
        {
          if ( *(_DWORD *)(v83 + 96) > v97 )
            v97 = *(_DWORD *)(v83 + 96);
          v83 = *(_DWORD *)(v83 + 236);
        }
        while ( *(unsigned __int8 *)(v83 + 93) > v96 );
      }
      v106 = v97;
      goto LABEL_198;
    }
  }
  *(_DWORD *)(v4 + 144) = v5;
  *(_DWORD *)(a1 + 1540) = v4 + 144;
  return 0;
}
