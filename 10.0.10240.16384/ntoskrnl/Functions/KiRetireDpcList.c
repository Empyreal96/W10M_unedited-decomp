// KiRetireDpcList 
 
int __fastcall KiRetireDpcList(int a1)
{
  int v1; // r9
  int v2; // r8
  unsigned __int16 *v3; // r10
  __int64 v4; // r0
  __int64 v5; // r6
  unsigned __int64 v6; // kr08_8
  unsigned __int64 *v7; // lr
  unsigned __int64 v8; // kr10_8
  __int64 v9; // kr18_8
  int result; // r0
  char v11; // r5
  int v12; // r0
  unsigned int v13; // r2
  char v14; // r4
  int v15; // r5
  int v16; // r7
  unsigned int v17; // r10
  int v18; // r6
  int v19; // r2
  int v20; // r3
  unsigned int v21; // r7
  unsigned int v22; // r10
  char *v23; // r9
  int v24; // r2
  unsigned int *v25; // r4
  unsigned int v26; // r2
  unsigned int v27; // r0
  int v28; // r3
  unsigned int v29; // r4
  unsigned int v30; // lr
  unsigned int v31; // r0
  unsigned int v32; // r8
  unsigned int v33; // r2
  unsigned int v34; // r10
  int v35; // r5
  unsigned int *v36; // r6
  char *v37; // r4
  BOOL v38; // r9
  int v39; // r0
  unsigned int v40; // r7
  int v41; // r3
  BOOL v42; // r10
  unsigned int *v43; // r8
  unsigned int v44; // r4
  unsigned int v45; // r2
  int v46; // r2
  int v47; // r6
  __int64 v48; // r1
  _DWORD *v49; // r5
  int v50; // r1
  int v51; // r0
  int v52; // r2
  unsigned int v53; // r4
  unsigned int v54; // r0
  bool v55; // zf
  int v56; // r4
  unsigned int v57; // lr
  unsigned int v58; // r3
  __int64 v59; // kr20_8
  unsigned int v60; // r6
  __int64 v61; // r0
  unsigned __int64 v62; // kr28_8
  unsigned __int64 v63; // kr30_8
  int v64; // r2
  int v65; // r3
  unsigned int v66; // r1
  unsigned int v67; // r3
  unsigned __int64 *v68; // r4
  unsigned __int64 v69; // kr38_8
  unsigned __int64 v70; // kr48_8
  unsigned int v71; // r2
  unsigned int v72; // r2
  unsigned int *v73; // r9
  _DWORD *v74; // r3
  unsigned int v75; // lr
  __int64 v76; // kr50_8
  unsigned int v77; // r2
  int v78; // r3
  unsigned int v79; // r0
  int v80; // r2
  int v81; // r1
  int v82; // r1
  int v83; // r1
  int v84; // r2
  int v85; // r0
  unsigned __int8 *v86; // r3
  unsigned int v87; // r2
  int v88; // r2
  int v89; // r3
  unsigned int v90; // r1
  unsigned int v91; // r2
  unsigned __int64 *v92; // r4
  unsigned __int64 v93; // kr58_8
  unsigned __int64 v94; // kr60_8
  int v95; // r1
  int i; // r1
  unsigned int v97; // r1
  int v98; // r4
  unsigned int v99; // r3
  bool v100; // cf
  unsigned int v101; // r1
  int v102; // r3
  int v103; // r0
  int v104; // r2
  unsigned int v105; // r2
  __int64 v106; // r2
  bool v107; // cc
  unsigned int v108; // r2
  int v109; // r3
  int v110; // [sp+8h] [bp-1D0h]
  unsigned int v111; // [sp+Ch] [bp-1CCh]
  BOOL v112; // [sp+Ch] [bp-1CCh]
  unsigned int *v113; // [sp+10h] [bp-1C8h]
  int v114; // [sp+14h] [bp-1C4h]
  unsigned int v115; // [sp+18h] [bp-1C0h]
  unsigned int v116; // [sp+1Ch] [bp-1BCh]
  char v117; // [sp+20h] [bp-1B8h]
  BOOL v118; // [sp+20h] [bp-1B8h]
  unsigned int v119; // [sp+24h] [bp-1B4h]
  unsigned int v120; // [sp+28h] [bp-1B0h]
  unsigned int v121; // [sp+2Ch] [bp-1ACh]
  char v122; // [sp+30h] [bp-1A8h]
  void (__fastcall *v123)(int, _DWORD, _DWORD, int); // [sp+34h] [bp-1A4h] BYREF
  unsigned int v124; // [sp+38h] [bp-1A0h]
  unsigned int v125; // [sp+3Ch] [bp-19Ch]
  int v126; // [sp+40h] [bp-198h]
  unsigned int v127; // [sp+44h] [bp-194h]
  int v128; // [sp+48h] [bp-190h]
  unsigned int v129; // [sp+4Ch] [bp-18Ch]
  int v130; // [sp+50h] [bp-188h]
  unsigned int *v131; // [sp+54h] [bp-184h]
  _DWORD v132[2]; // [sp+58h] [bp-180h] BYREF
  _DWORD v133[2]; // [sp+60h] [bp-178h] BYREF
  int v134; // [sp+68h] [bp-170h]
  int v135; // [sp+70h] [bp-168h]
  int v136[4]; // [sp+80h] [bp-158h] BYREF
  int v137[4]; // [sp+90h] [bp-148h] BYREF
  int v138[4]; // [sp+A0h] [bp-138h] BYREF
  char v139; // [sp+B0h] [bp-128h]
  _QWORD v140[2]; // [sp+B8h] [bp-120h] BYREF
  int v141[2]; // [sp+C8h] [bp-110h] BYREF
  int v142; // [sp+D0h] [bp-108h] BYREF
  int v143; // [sp+D4h] [bp-104h]
  _DWORD v144[48]; // [sp+D8h] [bp-100h] BYREF
  int v145[16]; // [sp+198h] [bp-40h] BYREF

  v1 = *(_DWORD *)(a1 + 4);
  v141[0] = 0;
  v110 = a1;
  v126 = 536871040;
  v2 = a1;
  v114 = v1;
  v3 = (unsigned __int16 *)(a1 + 1756);
  do
  {
    *(_BYTE *)(v2 + 16) = 1;
    LODWORD(v4) = ReadTimeStampCounter();
    v5 = v4 - *(_QWORD *)(v2 + 2376);
    v6 = *(_QWORD *)(v1 + 48) + v5;
    __dmb(0xBu);
    v7 = (unsigned __int64 *)(v1 + 48);
    do
      v8 = __ldrexd(v7);
    while ( __strexd(v6, v7) );
    __dmb(0xBu);
    v9 = v5 + *(unsigned int *)(v1 + 56);
    if ( HIDWORD(v9) )
      return sub_52E910();
    *(_QWORD *)(v2 + 2376) = v4;
    v11 = *(_BYTE *)(v1 + 2);
    *(_DWORD *)(v1 + 56) = v9;
    if ( (v11 & 0x3E) != 0 )
    {
      if ( (v11 & 0x10) != 0 )
      {
        v97 = *(_DWORD *)(v2 + 2376);
        v98 = v2 + 8 * *(unsigned __int8 *)(v1 + 84);
        v99 = *(_DWORD *)(v2 + 2384);
        v11 &= 0xEFu;
        v100 = v97 >= v99;
        v101 = v97 - v99;
        v102 = *(_DWORD *)(v98 + 2392);
        v103 = *(_DWORD *)(v2 + 2380) - (*(_DWORD *)(v2 + 2388) + !v100);
        v104 = *(_DWORD *)(v98 + 2396);
        *(_DWORD *)(v98 + 2392) = v102 + v101;
        *(_DWORD *)(v98 + 2396) = v103 + __CFADD__(v102, v101) + v104;
        *(_DWORD *)(v2 + 2384) = 0;
        *(_DWORD *)(v2 + 2388) = 0;
      }
      if ( (v11 & 0x3E) != 0 )
      {
        if ( (v11 & 0x20) != 0 )
        {
          v12 = *(_DWORD *)(v1 + 1084);
          if ( v12 )
          {
            v88 = *(_DWORD *)(v2 + 3200);
            v89 = *(_DWORD *)(v2 + 3204);
            if ( v88 && v89 )
            {
              v90 = *(_DWORD *)(v89 + 44);
              if ( v90 >= *(_DWORD *)(v88 + 148) )
                v90 = *(_DWORD *)(v88 + 148);
            }
            else
            {
              v90 = 100;
            }
            v91 = v90 / 0x19;
            if ( v90 / 0x19 >= 3 )
              v91 = 3;
            v92 = (unsigned __int64 *)(v12 + 8 * (*(unsigned __int8 *)(v2 + 2986) + 2 * v91));
            v93 = *v92 + v5;
            __dmb(0xBu);
            do
              v94 = __ldrexd(v92);
            while ( __strexd(v93, v92) );
            __dmb(0xBu);
          }
          v11 &= 0xDFu;
        }
        if ( (v11 & 0x3E) != 0 )
        {
          v95 = *(_DWORD *)(v1 + 68);
          if ( v95 )
          {
            for ( i = v95 + *(_DWORD *)(v2 + 2352); i; i = *(_DWORD *)(i + 236) )
              *(_QWORD *)i += v5;
          }
          if ( (*(_BYTE *)(v1 + 2) & 8) != 0
            && (*(_DWORD *)(*(_DWORD *)(v2 + 2360) + 260) & *(_DWORD *)(v1 + 356)) != *(_DWORD *)(*(_DWORD *)(v2 + 2360)
                                                                                                + 260) )
          {
            *(_QWORD *)(v2 + 2368) += v5;
          }
          if ( *(_DWORD *)(v1 + 236) )
            KiEndCounterAccumulation(v1);
        }
      }
    }
    *(_BYTE *)(v2 + 1754) = 1;
    __dmb(0xBu);
    do
      v13 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    v14 = v13;
    v122 = v13;
    if ( (v13 & 8) == 0 )
      goto LABEL_71;
    v15 = *(_DWORD *)(v2 + 1760);
    while ( 1 )
    {
      v16 = MEMORY[0xFFFF900C];
      v119 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v17 = MEMORY[0xFFFF9008];
      v115 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v16 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
    v2 = v110;
    v18 = (v16 << 14) | (v17 >> 18);
    v1 = v114;
    *(_DWORD *)(v110 + 1760) = v18;
    __enable_irq();
    while ( 1 )
    {
      v19 = MEMORY[0xFFFF9018];
      __dmb(0xBu);
      v20 = MEMORY[0xFFFF9014];
      v143 = v19;
      __dmb(0xBu);
      v142 = v20;
      if ( v19 == MEMORY[0xFFFF901C] )
        break;
      __dmb(0xAu);
      __yield();
    }
    v21 = v119;
    v22 = v115;
    v14 = v122;
    if ( KiSerializeTimerExpiration )
    {
      if ( !*(_BYTE *)(v110 + 17) )
        goto LABEL_68;
      v23 = (char *)KiProcessorBlock + 4096;
    }
    else
    {
      v23 = (char *)(v110 + 4096);
    }
    v113 = (unsigned int *)v23;
    if ( !v23 )
    {
LABEL_136:
      v1 = v114;
      goto LABEL_68;
    }
    v24 = *(_DWORD *)(v110 + 18232);
    v25 = (unsigned int *)(v110 + 16 * v24 + 17976);
    *(_DWORD *)(v110 + 18232) = ((_BYTE)v24 + 1) & 0xF;
    *v25 = v115;
    v25[1] = v119;
    KeQueryPerformanceCounter(v133, 0);
    v26 = v133[1];
    v25[2] = v133[0];
    v25[3] = v26;
    if ( (dword_682608 & 0x20000) != 0 )
    {
      v136[0] = (int)v132;
      v136[1] = 0;
      v136[2] = 8;
      v136[3] = 0;
      v132[0] = v115;
      v132[1] = v119;
      EtwTraceKernelEvent(v136, 1, 1073872896, 3920, 1538);
    }
    v27 = v18 - v15 + 1;
    v125 = v27;
    if ( v27 > 0x100 )
    {
      v57 = ((((unsigned int)v18 + __PAIR64__(v119 >> 18, 1)) << 18) - __PAIR64__(v27 >> 14, v27 << 18)) >> 32;
      v56 = ((v18 + 1) << 18) - (v27 << 18);
      goto LABEL_150;
    }
    while ( 2 )
    {
      v28 = 256 - v27;
      v29 = v22;
      if ( 256 - v27 > 0x18 )
        v28 = 24;
      v124 = v27;
      v120 = v21;
      v121 = v22;
      v30 = v21;
LABEL_31:
      v31 = 0;
      v32 = 0;
      v134 = v124 + v15;
      v33 = v124 + v15 - 1;
      v34 = v33 + v28;
      v35 = v15 - 1;
      v116 = 0;
      v117 = -64;
      v111 = v33;
      do
      {
        v36 = (unsigned int *)&v23[24 * (unsigned __int8)++v35 + 256];
        if ( v32 > v33 )
        {
          v106 = *(_QWORD *)&v23[24 * (unsigned __int8)v35 + 272];
          if ( HIDWORD(v106) > v30 )
          {
            v33 = v111;
            goto LABEL_35;
          }
          if ( HIDWORD(v106) >= v30 )
          {
            v107 = (unsigned int)v106 > v29;
            v33 = v111;
            if ( v107 )
              goto LABEL_35;
          }
          else
          {
            v33 = v111;
          }
        }
        v37 = &v23[24 * (unsigned __int8)v35 + 260];
        if ( v37 != *(char **)v37 )
        {
          do
          {
            while ( 1 )
            {
              do
                v72 = __ldrex(v36);
              while ( __strex(1u, v36) );
              __dmb(0xBu);
              if ( !v72 )
                break;
              do
              {
                __dmb(0xAu);
                __yield();
              }
              while ( *v36 );
            }
            v73 = (unsigned int *)&v23[4 * v31];
            do
            {
              v74 = *(_DWORD **)v37;
              if ( v37 == *(char **)v37 )
                goto LABEL_100;
              v75 = (unsigned int)(v74 - 6);
              if ( *((_QWORD *)v74 - 1) > __PAIR64__(v120, v121) )
              {
                __disable_irq();
                v36[4] = *(v74 - 2);
                v36[5] = *(v74 - 1);
                __enable_irq();
LABEL_100:
                __dmb(0xBu);
                v23 = (char *)v113;
                *v36 = 0;
                goto LABEL_101;
              }
              v76 = *(_QWORD *)v74;
              if ( *(_DWORD **)(*v74 + 4) != v74 || *(_DWORD **)HIDWORD(v76) != v74 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v76) = v76;
              *(_DWORD *)(v76 + 4) = HIDWORD(v76);
              if ( HIDWORD(v76) == (_DWORD)v76 )
              {
                v36[5] = -1;
                v82 = KiPendingTimerBitmaps[2 * *((unsigned __int8 *)v113 - 3044) + 1];
                if ( KiSerializeTimerExpiration )
                {
                  v83 = v82 + 4 * ((unsigned __int8)v35 >> 5);
                  v84 = v35 & 0x1F;
                }
                else
                {
                  v84 = *((unsigned __int8 *)v113 - 3043);
                  v83 = v82 + ((unsigned __int8)v35 << 7);
                }
                __dmb(0xBu);
                v85 = 1 << (v84 & 7);
                v86 = (unsigned __int8 *)(v83 + (v84 >> 3));
                do
                  v87 = __ldrex(v86);
                while ( __strex(v87 & ~(_BYTE)v85, v86) );
                __dmb(0xBu);
              }
              __dmb(0xBu);
              do
                v77 = __ldrex(v73);
              while ( __strex(v75, v73) );
              __dmb(0xBu);
              if ( v77 )
                KeBugCheck2(199, 8, 1, v75, v77, 0);
              ++v73;
              v135 = 0;
              v117 ^= (v117 ^ v116) & 0x3F;
              HIBYTE(v135) = v117 ^ *(_BYTE *)(v75 + 3);
              ++v116;
              __dmb(0xBu);
              v78 = v135;
              do
                v79 = __ldrex((unsigned int *)v75);
              while ( __strex(v79 ^ v78, (unsigned int *)v75) );
              __dmb(0xBu);
              v31 = v116;
            }
            while ( v116 != 64 );
            __dmb(0xBu);
            v23 = (char *)v113;
            *v36 = 0;
            KiProcessExpiredTimerList(v110, v141, v113, 64);
            v31 = 0;
            v116 = 0;
          }
          while ( v37 != *(char **)v37 );
LABEL_101:
          v33 = v111;
        }
        ++v32;
LABEL_35:
        v30 = v120;
        v29 = v121;
      }
      while ( v35 != v34 );
      if ( v31 )
      {
        v38 = (dword_682604 & 0x80) != 0;
        v39 = v110;
        v40 = 0;
        v118 = v38;
        v41 = *(_DWORD *)(*(_DWORD *)(v110 + 4) + 308);
        v128 = *(_DWORD *)(v110 + 4);
        v130 = v41;
        v42 = (dword_682608 & 0x20000) != 0;
        v112 = v42;
        v43 = v113;
        do
        {
          __dmb(0xBu);
          do
            v44 = __ldrex(v43);
          while ( __strex(0, v43) );
          __dmb(0xBu);
          ++v40;
          ++v43;
          v129 = v40;
          v131 = v43;
          if ( v44 )
          {
            do
              v45 = __ldrex((unsigned __int8 *)v44);
            while ( __strex(v45 | 0x80, (unsigned __int8 *)v44) );
            __dmb(0xBu);
            if ( v45 >> 7 )
            {
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                }
                while ( (*(_DWORD *)v44 & 0x80) != 0 );
                do
                  v105 = __ldrex((unsigned __int8 *)v44);
                while ( __strex(v105 | 0x80, (unsigned __int8 *)v44) );
                __dmb(0xBu);
              }
              while ( v105 >> 7 );
            }
            if ( v42 )
            {
              v138[0] = *(_DWORD *)(v44 + 16);
              v138[1] = *(_DWORD *)(v44 + 20);
              v108 = bswap32(__ROR4__(KiWaitNever ^ *(_DWORD *)(v44 + 32), -(char)KiWaitNever) ^ v44);
              if ( KiWaitAlways != v108 )
                v109 = *(_DWORD *)((KiWaitAlways ^ v108) + 0xC);
              else
                v109 = 0;
              v138[3] = v109;
            }
            v47 = KiTimerWaitTest(v39, v44, &v142);
            if ( v42 )
            {
              v138[2] = v44;
              v139 = *(_BYTE *)(v44 + 1) >> 2;
              v137[0] = (int)v138;
              v137[1] = 0;
              v137[2] = 24;
              v137[3] = 0;
              EtwTraceKernelEvent(v137, 1, 1073872896, 3921, 1538);
            }
            if ( v47 )
            {
              if ( *(_DWORD *)(v110 + 1540) )
                KiProcessThreadWaitList(v110, 1, 0, 2);
              if ( v38 )
                EtwGetKernelTraceTimestamp(v140, v126, v46);
              v49 = &v144[3 * (v141[0] & 0xF)];
              v123 = *(void (__fastcall **)(int, _DWORD, _DWORD, int))(v47 + 12);
              LODWORD(v48) = v123;
              ++v141[0];
              HIDWORD(v48) = KeTickCount;
              *(_QWORD *)v49 = v48;
              HIDWORD(v48) = v142;
              *(_DWORD *)(v110 + 2332) = 0;
              v123(v47, *(_DWORD *)(v47 + 16), HIDWORD(v48), v143);
              v50 = v128;
              v51 = v130;
              v52 = *(_DWORD *)(v128 + 308);
              v49[2] = KeTickCount;
              if ( v51 != v52 )
                KeBugCheck2(199, 5, v123, v51, *(_DWORD *)(v50 + 308), 0);
              if ( v38 )
              {
                v145[4] = (int)&v123;
                v145[5] = 0;
                v145[6] = 4;
                v145[7] = 0;
                v53 = EtwpActiveSystemLoggers;
                v54 = __clz(__rbit(EtwpActiveSystemLoggers));
                v127 = v54;
                if ( 1 != (unsigned __int8)(v54 >> 5) )
                {
                  do
                  {
                    v53 &= v53 - 1;
                    if ( &EtwpGroupMasks[8 * v54] && (EtwpGroupMasks[8 * v54 + 1] & 0x80) != 0 )
                    {
                      v80 = (unsigned __int16)EtwpSystemLogger[2 * v54 + 1];
                      v145[1] = 0;
                      v145[2] = 8;
                      v145[0] = (int)&v140[v80];
                      v81 = (unsigned __int16)EtwpSystemLogger[2 * v54];
                      v145[3] = 0;
                      EtwpLogKernelEvent(v145, v81, 2, 3909, 4196866);
                    }
                    v54 = __clz(__rbit(v53));
                    v127 = v54;
                  }
                  while ( 1 != (unsigned __int8)(v54 >> 5) );
                  v40 = v129;
                  v43 = v131;
                  v38 = v118;
                  v42 = v112;
                }
              }
            }
            v39 = v110;
          }
        }
        while ( v40 < v116 );
        v2 = v110;
        if ( *(_DWORD *)(v110 + 1540) )
          KiProcessThreadWaitList(v110, 1, 0, 2);
      }
      else
      {
        v2 = v110;
      }
      v15 = v134;
      v23 = (char *)v113;
      v27 = v125 - v124;
      v55 = v125 == v124;
      v57 = v120;
      v56 = v121;
      v21 = v119;
      v22 = v115;
      v125 -= v124;
      if ( !v55 )
      {
LABEL_150:
        if ( v27 <= 0x100 )
          continue;
        v30 = (__PAIR64__(v57, v56) + 0x4000000) >> 32;
        v29 = v56 + 0x4000000;
        v120 = v30;
        v121 = v29;
        v124 = 256;
        v28 = 0;
        goto LABEL_31;
      }
      break;
    }
    v21 = v119;
    v22 = v115;
    v14 = v122;
    if ( (*(_WORD *)(v2 + 1756) & 8) != 0 )
      goto LABEL_136;
    v58 = *(_DWORD *)(v2 + 2344);
    *(_DWORD *)(v2 + 2340) = 0;
    v1 = v114;
    if ( v58 >= KeTimeIncrement )
      *(_DWORD *)(v2 + 2344) = v58 - KeTimeIncrement;
    else
      *(_DWORD *)(v2 + 2344) = 0;
LABEL_68:
    if ( *(_BYTE *)(v2 + 17) )
      KiTimer2Expiration(v2, v141, v22, v21, v141);
    __disable_irq();
    v3 = (unsigned __int16 *)(v2 + 1756);
LABEL_71:
    KiExecuteAllDpcs(v2, v1, v141, 0);
    *(_BYTE *)(v2 + 1754) = 0;
    if ( (v14 & 4) != 0 )
    {
      __enable_irq();
      KeSignalGate(v2 + 1792, 0);
      __disable_irq();
    }
    LODWORD(v61) = ReadTimeStampCounter();
    v59 = v61 - *(_QWORD *)(v2 + 2376);
    v60 = HIDWORD(v61);
    __dmb(0xBu);
    HIDWORD(v61) = v2 + 2744;
    do
      v62 = __ldrexd((unsigned __int64 *)HIDWORD(v61));
    while ( __strexd(v62 + v59, (unsigned __int64 *)HIDWORD(v61)) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(v1 + 2) & 0x20) != 0 )
    {
      v63 = __PAIR64__(v60, v61) - *(_QWORD *)(v2 + 2376);
      v64 = *(_DWORD *)(v2 + 3200);
      v65 = *(_DWORD *)(v2 + 3204);
      if ( v64 && v65 )
      {
        v66 = *(_DWORD *)(v65 + 44);
        if ( v66 >= *(_DWORD *)(v64 + 148) )
          v66 = *(_DWORD *)(v64 + 148);
      }
      else
      {
        v66 = 100;
      }
      v67 = v66 / 0x19;
      if ( v66 / 0x19 >= 3 )
        v67 = 3;
      v68 = (unsigned __int64 *)(v2 + 8 * (*(unsigned __int8 *)(v2 + 2986) + 2 * (v67 + 1144)));
      v69 = *v68;
      __dmb(0xBu);
      do
        v70 = __ldrexd(v68);
      while ( __strexd(v69 + v63, v68) );
      __dmb(0xBu);
    }
    *(_DWORD *)(v2 + 2376) = v61;
    *(_DWORD *)(v2 + 2380) = v60;
    if ( (*(_BYTE *)(v1 + 2) & 0x10) != 0 )
    {
      *(_DWORD *)(v2 + 2384) = v61;
      *(_DWORD *)(v2 + 2388) = v60;
    }
    if ( (*(_BYTE *)(v1 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(v1, 0);
    *(_BYTE *)(v2 + 16) = 0;
    __dmb(0xBu);
    result = 0;
    do
      v71 = __ldrex(v3);
    while ( v71 == 1 && __strex(0, v3) );
    __dmb(0xBu);
  }
  while ( (__int16)v71 != 1 );
  *(_DWORD *)(v2 + 1700) = 0;
  return result;
}
