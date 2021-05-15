// KeSetPriorityAndQuantumProcess 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeSetPriorityAndQuantumProcess(int a1, int a2, char a3, int a4)
{
  int v5; // r1
  int v6; // r6
  int v9; // r9
  unsigned int v10; // r3
  unsigned int v11; // r8
  int v12; // r3
  unsigned int *v13; // r7
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  int v17; // r3
  _DWORD *v18; // r2
  bool v19; // cc
  int v20; // r4
  int v21; // r7
  BOOL v22; // r1
  unsigned int *v23; // r6
  unsigned int v24; // r2
  int v25; // r3
  int v26; // r3
  int v27; // r10
  unsigned __int64 *v28; // r1
  unsigned int v29; // r7 OVERLAPPED
  unsigned int v30; // r8 OVERLAPPED
  unsigned __int64 v31; // kr00_8
  unsigned int v32; // r1
  unsigned int v33; // r4
  BOOL v34; // r0
  unsigned __int64 v35; // r4
  unsigned __int64 *v36; // r3
  unsigned __int64 v37; // kr10_8
  int v38; // r2
  _BYTE *v39; // r0
  __int64 v40; // r0
  unsigned __int64 *v41; // r4
  int v42; // r5
  __int64 v43; // kr18_8
  __int64 v44; // kr20_8
  unsigned __int64 v45; // r2
  __int64 v46; // r2
  char v47; // r9
  int v48; // r4
  unsigned __int64 *v49; // r4
  unsigned __int64 v50; // kr40_8
  unsigned __int64 v51; // kr48_8
  __int64 v52; // r0
  int v53; // r9
  __int64 v54; // kr50_8
  int v55; // r10
  unsigned __int64 *v56; // r3
  unsigned __int64 v57; // kr58_8
  __int64 v58; // kr60_8
  unsigned __int64 *v59; // r4
  unsigned __int64 v60; // kr68_8
  unsigned __int64 v61; // kr78_8
  unsigned __int8 *v62; // r3
  unsigned int v63; // r2
  unsigned int v64; // r1
  int v65; // r7
  BOOL v66; // r1
  unsigned int *v67; // r6
  unsigned int v68; // r2
  int v69; // r3
  int v70; // r3
  int v71; // r3
  int v72; // r3
  __int64 v73; // r0
  unsigned __int64 *v74; // r4
  int v75; // r5
  __int64 v76; // kr80_8
  __int64 v77; // kr88_8
  unsigned __int64 v78; // r2
  __int64 v79; // r2
  char v80; // r9
  unsigned int v81; // r6
  __int64 v82; // krA0_8
  int v83; // r4
  unsigned __int64 *v84; // r4
  unsigned __int64 v85; // krA8_8
  unsigned __int64 v86; // krB0_8
  int v87; // r1
  int i; // r1
  __int64 v89; // r0
  int v90; // r9
  __int64 v91; // krB8_8
  int v92; // r10
  unsigned __int64 *v93; // r3
  unsigned __int64 v94; // krC0_8
  __int64 v95; // krC8_8
  unsigned __int64 *v96; // r4
  unsigned __int64 v97; // krD0_8
  unsigned __int64 v98; // krE0_8
  unsigned int v99; // r1
  unsigned int v100; // r4
  BOOL v101; // r0
  int v102; // r1
  unsigned int v103; // r7 OVERLAPPED
  unsigned int v104; // r8 OVERLAPPED
  unsigned __int64 v105; // krF8_8
  unsigned __int64 v106; // r4
  unsigned __int8 *v107; // r3
  unsigned int v108; // r2
  unsigned __int64 *v109; // r3
  unsigned __int64 v110; // kr100_8
  int v111; // r2
  _BYTE *v112; // r0
  int v113; // r3
  int v114; // r3
  unsigned int v115; // r6
  __int64 v116; // kr38_8
  int v117; // r1
  int j; // r1
  char v119; // r1
  int v120; // [sp+8h] [bp-78h] BYREF
  unsigned __int64 v121; // [sp+Ch] [bp-74h]
  _DWORD *v122; // [sp+14h] [bp-6Ch]
  BOOL v123; // [sp+18h] [bp-68h]
  int v124; // [sp+1Ch] [bp-64h]
  _DWORD *v125; // [sp+20h] [bp-60h]
  int v126; // [sp+24h] [bp-5Ch]
  int v127; // [sp+28h] [bp-58h]
  int v128; // [sp+2Ch] [bp-54h]
  int v129; // [sp+30h] [bp-50h] BYREF
  BOOL v130; // [sp+34h] [bp-4Ch]
  int v131; // [sp+38h] [bp-48h]
  unsigned int *v132; // [sp+3Ch] [bp-44h]
  int v133; // [sp+40h] [bp-40h]
  unsigned int v134; // [sp+44h] [bp-3Ch]
  _DWORD *v135; // [sp+48h] [bp-38h]
  int v136; // [sp+4Ch] [bp-34h]
  int v137; // [sp+50h] [bp-30h]
  int v138; // [sp+5Ch] [bp-24h]

  v5 = *(char *)(a1 + 104);
  v6 = a3;
  v124 = a4;
  v128 = a3;
  if ( v5 != a2 )
  {
    if ( (_UNKNOWN *)a1 == &KiInitialProcess )
      return v5;
    if ( !a2 )
      a2 = 1;
    v126 = 0;
    v9 = 0;
    v129 = 0;
    v130 = (dword_682604 & 0x2000) != 0;
    v137 = KfRaiseIrql(2);
    v10 = (unsigned int)KeGetPcr();
    v11 = (v10 & 0xFFFFF000) + 1408;
    v12 = *(_DWORD *)((v10 & 0xFFFFF000) + 0x584);
    v13 = (unsigned int *)(a1 + 48);
    v134 = v11;
    v131 = v12;
    v132 = (unsigned int *)(a1 + 48);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 48);
    }
    else
    {
      v14 = (unsigned __int8 *)(a1 + 51);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      __dmb(0xBu);
      if ( v15 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 48));
      while ( 1 )
      {
        v16 = *v13;
        if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v16 & 0x40000000) == 0 )
        {
          do
            v64 = __ldrex(v13);
          while ( v64 == v16 && __strex(v16 | 0x40000000, v13) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v6 = v128;
    }
    if ( v6 )
      *(_BYTE *)(a1 + 105) = v6;
    v17 = *(char *)(a1 + 104);
    *(_BYTE *)(a1 + 104) = a2;
    v127 = v17;
    v133 = a2 - v17;
    KeFlushProcessWriteBuffers(1);
    v18 = *(_DWORD **)(a1 + 40);
    v19 = a2 < 16;
    v125 = v18;
    v20 = a1 + 40;
    if ( !v19 )
    {
      v124 = a1 + 40;
      if ( v18 == (_DWORD *)v20 )
      {
LABEL_50:
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v13);
        }
        else
        {
          __dmb(0xBu);
          *v13 = 0;
        }
        KiProcessDeferredReadyList(v11, &v129, v137);
        return v127;
      }
      while ( 1 )
      {
        v65 = (int)(v18 - 117);
        v122 = v18 - 117;
        if ( v6 )
          *((_BYTE *)v18 - 65) = v6;
        v66 = v65 == v131;
        v123 = v66;
        v67 = v18 - 106;
        while ( 1 )
        {
          do
            v68 = __ldrex(v67);
          while ( __strex(1u, v67) );
          __dmb(0xBu);
          if ( !v68 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v67 );
        }
        v69 = *(char *)(v65 + 347) + v133;
        v120 = v69;
        if ( v69 >= 16 )
        {
          if ( v69 <= 31 )
            goto LABEL_110;
          v70 = 31;
        }
        else
        {
          v70 = 16;
        }
        v120 = v70;
LABEL_110:
        v71 = *(char *)(v65 + 397);
        if ( !*(_BYTE *)(v65 + 397) )
          goto LABEL_118;
        if ( v127 < 16 )
        {
          if ( v71 > 0 )
          {
            v72 = 31;
            goto LABEL_117;
          }
          if ( v71 < 0 )
          {
            v72 = 16;
LABEL_117:
            v120 = v72;
          }
LABEL_118:
          v126 = *(char *)(v65 + 347);
          if ( v66 )
          {
            if ( *(_BYTE *)(v11 + 16) )
            {
              v99 = *(_DWORD *)(v65 + 52);
              v100 = *(_DWORD *)(v65 + 48);
            }
            else
            {
              __disable_irq();
              *(_BYTE *)(v11 + 16) = 1;
              LODWORD(v73) = ReadTimeStampCounter();
              v74 = (unsigned __int64 *)(v65 + 48);
              v76 = v73 - *(_QWORD *)(v11 + 2376);
              v75 = HIDWORD(v76);
              v77 = *(_QWORD *)(v65 + 48);
              v122 = (_DWORD *)HIDWORD(v76);
              LODWORD(v121) = (unsigned __int64)(v77 + v76) >> 32;
              HIDWORD(v121) = v77 + v76;
              __dmb(0xBu);
              do
                v78 = __ldrexd(v74);
              while ( __strexd(v77 + v76, v74) );
              __dmb(0xBu);
              v79 = v76 + *(unsigned int *)(v65 + 56);
              if ( HIDWORD(v79) )
              {
                v136 = 0;
                LODWORD(v79) = -1;
              }
              *(_QWORD *)(v11 + 2376) = v73;
              v80 = *(_BYTE *)(v65 + 2);
              *(_DWORD *)(v65 + 56) = v79;
              if ( (v80 & 0x3E) != 0 )
              {
                if ( (v80 & 0x10) != 0 )
                {
                  v81 = v11 + 8 * *(unsigned __int8 *)(v65 + 84);
                  v82 = *(_QWORD *)(v81 + 2392) - *(_QWORD *)(v11 + 2384) + *(_QWORD *)(v11 + 2376);
                  *(_DWORD *)(v81 + 2392) = v82;
                  v75 = (int)v122;
                  *(_DWORD *)(v81 + 2396) = HIDWORD(v82);
                  *(_DWORD *)(v11 + 2384) = 0;
                  *(_DWORD *)(v11 + 2388) = 0;
                  v80 &= 0xEFu;
                }
                if ( (v80 & 0x3E) != 0 )
                {
                  if ( (v80 & 0x20) != 0 )
                  {
                    v83 = *(_DWORD *)(v65 + 1084);
                    if ( v83 )
                    {
                      v84 = (unsigned __int64 *)(v83
                                               + 8 * (*(unsigned __int8 *)(v11 + 2986) + 2 * PoGetFrequencyBucket(v11)));
                      v85 = *v84 + __PAIR64__(v75, v76);
                      __dmb(0xBu);
                      do
                        v86 = __ldrexd(v84);
                      while ( __strexd(v85, v84) );
                      __dmb(0xBu);
                    }
                    v80 &= 0xDFu;
                  }
                  if ( (v80 & 0x3E) != 0 )
                  {
                    v87 = *(_DWORD *)(v65 + 68);
                    if ( v87 )
                    {
                      for ( i = v87 + *(_DWORD *)(v11 + 2352); i; i = *(_DWORD *)(i + 236) )
                        *(_QWORD *)i += __PAIR64__(v75, v76);
                    }
                    if ( (*(_BYTE *)(v65 + 2) & 8) != 0
                      && (*(_DWORD *)(v65 + 356) & *(_DWORD *)(*(_DWORD *)(v11 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v11 + 2360) + 260) )
                    {
                      *(_QWORD *)(v11 + 2368) += __PAIR64__(v75, v76);
                    }
                    if ( *(_DWORD *)(v65 + 236) )
                      KiEndCounterAccumulation(v65);
                  }
                }
              }
              LODWORD(v89) = ReadTimeStampCounter();
              v90 = HIDWORD(v89);
              v91 = v89 - *(_QWORD *)(v11 + 2376);
              v92 = v89;
              __dmb(0xBu);
              v93 = (unsigned __int64 *)(v11 + 2744);
              do
                v94 = __ldrexd(v93);
              while ( __strexd(v94 + v91, v93) );
              __dmb(0xBu);
              if ( (*(_BYTE *)(v65 + 2) & 0x20) != 0 )
              {
                v95 = v89 - *(_QWORD *)(v11 + 2376);
                v96 = (unsigned __int64 *)(v11
                                         + 8
                                         * (*(unsigned __int8 *)(v11 + 2986) + 2 * (PoGetFrequencyBucket(v11) + 1144)));
                v97 = *v96;
                __dmb(0xBu);
                do
                  v98 = __ldrexd(v96);
                while ( __strexd(v97 + v95, v96) );
                __dmb(0xBu);
              }
              *(_DWORD *)(v11 + 2376) = v92;
              *(_DWORD *)(v11 + 2380) = v90;
              if ( (*(_BYTE *)(v65 + 2) & 0x10) != 0 )
              {
                *(_DWORD *)(v11 + 2384) = v92;
                *(_DWORD *)(v11 + 2388) = v90;
              }
              if ( (*(_BYTE *)(v65 + 2) & 2) != 0 )
                KiBeginCounterAccumulation(v65, 0);
              *(_BYTE *)(v11 + 16) = 0;
              __enable_irq();
              v67 = (unsigned int *)(v65 + 44);
LABEL_155:
              v100 = HIDWORD(v121);
              v99 = v121;
            }
            v101 = !v123;
            v106 = __PAIR64__(v99, v100) + (unsigned int)*(unsigned __int8 *)(v65 + 403) * KiCyclesPerClockQuantum;
            if ( (*(_DWORD *)(v65 + 80) & 0x10) != 0 )
            {
              __dmb(0xBu);
              v107 = (unsigned __int8 *)(v65 + 80);
              do
                v108 = __ldrex(v107);
              while ( __strex(v108 & 0xEF, v107) );
              __dmb(0xBu);
            }
            if ( v101 )
            {
              __dmb(0xBu);
              v109 = (unsigned __int64 *)(v65 + 24);
              do
                v110 = __ldrexd(v109);
              while ( __strexd(v106, v109) );
              __dmb(0xBu);
            }
            else
            {
              *(_QWORD *)(v65 + 24) = v106;
            }
            KiAbProcessThreadPriorityModification(v65, (char)v120, 0);
            *(_BYTE *)(v65 + 347) = v120;
            v111 = v120;
            if ( *(_BYTE *)(v65 + 348) )
            {
              if ( (*(_BYTE *)(v65 + 348) & 0xF) != 0 )
                *(_DWORD *)(v65 + 812) = KeTickCount;
              *(_BYTE *)(v65 + 348) = 0;
            }
            v120 = v111;
            KiSetPriorityThread(v65, &v129, v111);
            v112 = *(_BYTE **)(v65 + 152);
            v9 = 1;
            if ( v112 && (*v112 & 0x7F) == 21 )
            {
              KiPriQueueThreadPriorityChanged((int)v112, v65);
            }
            else
            {
              __dmb(0xBu);
              *v67 = 0;
            }
            v20 = v124;
            goto LABEL_183;
          }
          v102 = v65 + 48;
          while ( 1 )
          {
            *(_QWORD *)&v103 = *(_QWORD *)v102;
            LODWORD(v121) = *(_DWORD *)(v102 + 4);
            HIDWORD(v121) = v103;
            do
              v105 = __ldrexd((unsigned __int64 *)v102);
            while ( __PAIR64__(v105, HIDWORD(v105)) == __PAIR64__(v103, v104)
                 && __strexd(__PAIR64__(v104, v103), (unsigned __int64 *)v102) );
            if ( __PAIR64__(v103, v104) == __PAIR64__(v105, HIDWORD(v105)) )
              break;
            __dmb(0xAu);
            __yield();
          }
          v65 = (int)v122;
          v11 = v134;
          goto LABEL_155;
        }
        __dmb(0xBu);
        *v67 = 0;
LABEL_183:
        if ( v130 && v9 )
        {
          v9 = 0;
          EtwTracePriority(v65, 1329, v126, v120, &v120);
        }
        v6 = v128;
        v18 = (_DWORD *)*v125;
        v125 = v18;
        if ( v18 == (_DWORD *)v20 )
          goto LABEL_49;
      }
    }
    v122 = (_DWORD *)(a1 + 40);
    if ( v18 == (_DWORD *)v20 )
      goto LABEL_50;
    while ( 1 )
    {
      v21 = (int)(v18 - 117);
      v135 = v18 - 117;
      if ( v6 )
        *((_BYTE *)v18 - 65) = v6;
      v22 = v21 == v131;
      v123 = v22;
      v23 = v18 - 106;
      while ( 1 )
      {
        do
          v24 = __ldrex(v23);
        while ( __strex(1u, v23) );
        __dmb(0xBu);
        if ( !v24 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v23 );
      }
      v25 = *(char *)(v21 + 347) + v133;
      v120 = v25;
      if ( v25 >= 16 )
      {
        v113 = 15;
      }
      else
      {
        if ( v25 > 0 )
          goto LABEL_29;
        v113 = 1;
      }
      v120 = v113;
LABEL_29:
      v26 = *(char *)(v21 + 397);
      v27 = v124;
      if ( !*(_BYTE *)(v21 + 397) )
        goto LABEL_30;
      if ( v127 >= 16 )
      {
        if ( v26 > 0 )
        {
          v114 = 15;
          goto LABEL_199;
        }
        if ( v26 < 0 )
        {
          v114 = 1;
LABEL_199:
          v120 = v114;
        }
LABEL_30:
        v126 = *(char *)(v21 + 347);
        if ( !v22 )
        {
          v28 = (unsigned __int64 *)(v21 + 48);
          while ( 1 )
          {
            *(_QWORD *)&v29 = *v28;
            v121 = *v28;
            do
              v31 = __ldrexd(v28);
            while ( __PAIR64__(v31, HIDWORD(v31)) == __PAIR64__(v29, v30) && __strexd(__PAIR64__(v30, v29), v28) );
            if ( __PAIR64__(v29, v30) == __PAIR64__(v31, HIDWORD(v31)) )
              break;
            __dmb(0xAu);
            __yield();
          }
          v11 = v134;
          v21 = (int)v135;
          goto LABEL_37;
        }
        if ( *(_BYTE *)(v11 + 16) )
        {
          v32 = *(_DWORD *)(v21 + 52);
          v33 = *(_DWORD *)(v21 + 48);
        }
        else
        {
          __disable_irq();
          *(_BYTE *)(v11 + 16) = 1;
          LODWORD(v40) = ReadTimeStampCounter();
          v41 = (unsigned __int64 *)(v21 + 48);
          v43 = v40 - *(_QWORD *)(v11 + 2376);
          v42 = HIDWORD(v43);
          v44 = *(_QWORD *)(v21 + 48);
          v135 = (_DWORD *)HIDWORD(v43);
          v121 = v44 + v43;
          __dmb(0xBu);
          do
            v45 = __ldrexd(v41);
          while ( __strexd(v44 + v43, v41) );
          __dmb(0xBu);
          v46 = v43 + *(unsigned int *)(v21 + 56);
          if ( HIDWORD(v46) )
          {
            v138 = 0;
            LODWORD(v46) = -1;
          }
          *(_QWORD *)(v11 + 2376) = v40;
          v47 = *(_BYTE *)(v21 + 2);
          *(_DWORD *)(v21 + 56) = v46;
          if ( (v47 & 0x3E) != 0 )
          {
            if ( (v47 & 0x10) != 0 )
            {
              v115 = v11 + 8 * *(unsigned __int8 *)(v21 + 84);
              v116 = *(_QWORD *)(v115 + 2392) - *(_QWORD *)(v11 + 2384) + *(_QWORD *)(v11 + 2376);
              *(_DWORD *)(v115 + 2392) = v116;
              v42 = (int)v135;
              *(_DWORD *)(v115 + 2396) = HIDWORD(v116);
              *(_DWORD *)(v11 + 2384) = 0;
              *(_DWORD *)(v11 + 2388) = 0;
              v47 &= 0xEFu;
            }
            if ( (v47 & 0x3E) != 0 )
            {
              if ( (v47 & 0x20) != 0 )
              {
                v48 = *(_DWORD *)(v21 + 1084);
                if ( v48 )
                {
                  v49 = (unsigned __int64 *)(v48 + 8
                                                 * (*(unsigned __int8 *)(v11 + 2986) + 2 * PoGetFrequencyBucket(v11)));
                  v50 = *v49 + __PAIR64__(v42, v43);
                  __dmb(0xBu);
                  do
                    v51 = __ldrexd(v49);
                  while ( __strexd(v50, v49) );
                  __dmb(0xBu);
                }
                v47 &= 0xDFu;
              }
              if ( (v47 & 0x3E) != 0 )
              {
                v117 = *(_DWORD *)(v21 + 68);
                if ( v117 )
                {
                  for ( j = v117 + *(_DWORD *)(v11 + 2352); j; j = *(_DWORD *)(j + 236) )
                    *(_QWORD *)j += __PAIR64__(v42, v43);
                }
                if ( (*(_BYTE *)(v21 + 2) & 8) != 0
                  && (*(_DWORD *)(v21 + 356) & *(_DWORD *)(*(_DWORD *)(v11 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v11 + 2360) + 260) )
                {
                  *(_QWORD *)(v11 + 2368) += __PAIR64__(v42, v43);
                }
                if ( *(_DWORD *)(v21 + 236) )
                  KiEndCounterAccumulation(v21);
              }
            }
          }
          LODWORD(v52) = ReadTimeStampCounter();
          v53 = HIDWORD(v52);
          v54 = v52 - *(_QWORD *)(v11 + 2376);
          v55 = v52;
          __dmb(0xBu);
          v56 = (unsigned __int64 *)(v11 + 2744);
          do
            v57 = __ldrexd(v56);
          while ( __strexd(v57 + v54, v56) );
          __dmb(0xBu);
          if ( (*(_BYTE *)(v21 + 2) & 0x20) != 0 )
          {
            v58 = v52 - *(_QWORD *)(v11 + 2376);
            v59 = (unsigned __int64 *)(v11
                                     + 8 * (*(unsigned __int8 *)(v11 + 2986) + 2 * (PoGetFrequencyBucket(v11) + 1144)));
            v60 = *v59;
            __dmb(0xBu);
            do
              v61 = __ldrexd(v59);
            while ( __strexd(v60 + v58, v59) );
            __dmb(0xBu);
          }
          *(_DWORD *)(v11 + 2376) = v55;
          *(_DWORD *)(v11 + 2380) = v53;
          if ( (*(_BYTE *)(v21 + 2) & 0x10) != 0 )
          {
            *(_DWORD *)(v11 + 2384) = v55;
            *(_DWORD *)(v11 + 2388) = v53;
          }
          if ( (*(_BYTE *)(v21 + 2) & 2) != 0 )
            KiBeginCounterAccumulation(v21, 0);
          v27 = v124;
          *(_BYTE *)(v11 + 16) = 0;
          __enable_irq();
          v23 = (unsigned int *)(v21 + 44);
LABEL_37:
          v32 = HIDWORD(v121);
          v33 = v121;
        }
        v34 = !v123;
        v35 = __PAIR64__(v32, v33) + (unsigned int)*(unsigned __int8 *)(v21 + 403) * KiCyclesPerClockQuantum;
        if ( (*(_DWORD *)(v21 + 80) & 0x10) != 0 )
        {
          __dmb(0xBu);
          v62 = (unsigned __int8 *)(v21 + 80);
          do
            v63 = __ldrex(v62);
          while ( __strex(v63 & 0xEF, v62) );
          __dmb(0xBu);
        }
        if ( v34 )
        {
          __dmb(0xBu);
          v36 = (unsigned __int64 *)(v21 + 24);
          do
            v37 = __ldrexd(v36);
          while ( __strexd(v35, v36) );
          __dmb(0xBu);
        }
        else
        {
          *(_QWORD *)(v21 + 24) = v35;
        }
        KiAbProcessThreadPriorityModification(v21, (char)v120, 0);
        *(_BYTE *)(v21 + 347) = v120;
        v38 = v120;
        if ( *(_BYTE *)(v21 + 348) )
        {
          if ( (*(_BYTE *)(v21 + 348) & 0xF) != 0 )
            *(_DWORD *)(v21 + 812) = KeTickCount;
          if ( v27 )
          {
            v119 = *(_BYTE *)(v21 + 348);
            v38 = *(char *)(v21 + 123) - (v119 & 0xF);
            *(_BYTE *)(v21 + 348) = v119 & 0xF0;
          }
          else
          {
            *(_BYTE *)(v21 + 348) = 0;
          }
        }
        v120 = v38;
        KiSetPriorityThread(v21, &v129, v38);
        v39 = *(_BYTE **)(v21 + 152);
        v9 = 1;
        if ( v39 && (*v39 & 0x7F) == 21 )
        {
          KiPriQueueThreadPriorityChanged((int)v39, v21);
        }
        else
        {
          __dmb(0xBu);
          *v23 = 0;
        }
        v20 = (int)v122;
        goto LABEL_47;
      }
      __dmb(0xBu);
      *v23 = 0;
LABEL_47:
      if ( v130 && v9 )
      {
        v9 = 0;
        EtwTracePriority(v21, 1329, v126, v120, &v120);
      }
      v6 = v128;
      v18 = (_DWORD *)*v125;
      v125 = v18;
      if ( v18 == (_DWORD *)v20 )
      {
LABEL_49:
        v13 = v132;
        goto LABEL_50;
      }
    }
  }
  if ( a4 )
    return sub_523F70();
  if ( a3 )
    KeSetQuantumProcess(a1, a3);
  return a2;
}
