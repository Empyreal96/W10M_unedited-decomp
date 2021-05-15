// KiDeferredReadyThread 
 
int __fastcall KiDeferredReadyThread(int a1, int a2)
{
  unsigned __int64 *v3; // r3
  unsigned int v4; // r7
  unsigned int v5; // r8
  unsigned __int64 v6; // kr10_8
  int v7; // r9
  unsigned int *v8; // r10
  unsigned int v9; // r2
  char v10; // r6
  unsigned int v11; // r1
  int v12; // r1
  int v13; // r4
  int v14; // r0
  int v15; // r2
  int v16; // r6
  char v17; // r2
  int v18; // r9
  unsigned int v19; // r2
  int v20; // r0
  int v21; // r1
  int v22; // r6
  int v23; // r8
  int v24; // r4
  int v25; // r2
  char v26; // r2
  int v27; // r3
  int v28; // r7
  int v29; // r3
  int v30; // r2
  int v31; // r0
  unsigned __int8 *v32; // r3
  unsigned int v33; // r2
  int v34; // r2
  int v35; // r4
  unsigned __int8 *v36; // r2
  unsigned int v37; // r1
  int v38; // r4
  unsigned int *v39; // r2
  int result; // r0
  int v41; // r3
  int v42; // r3
  unsigned int *v43; // r1
  unsigned int v44; // r3
  unsigned int v45; // r3
  char *v46; // r7
  char *v47; // r7
  char v48; // r2
  int v49; // r3
  int v50; // r3
  unsigned int *v51; // r1
  unsigned int v52; // r4
  unsigned __int64 v53; // kr18_8
  int v54; // r2
  int v55; // r4
  unsigned int v56; // r3
  int v57; // r7
  int v58; // r2
  int *v59; // r1
  unsigned int v60; // r2
  int *v61; // r2
  int **v62; // r4
  int v63; // r2
  int v64; // r2
  int v65; // r1
  int v66; // r3
  char v67; // r3
  char v68; // r4
  int v69; // r2
  int v70; // r2
  int v71; // r1
  int v72; // r3
  int v73; // r3
  int v74; // r1
  int v75; // r2
  char v76; // r2
  int v77; // r4
  unsigned __int8 *v78; // r3
  unsigned int v79; // r2
  int v80; // r1
  int *v81; // r2
  int v82; // r2
  int v83; // r1
  unsigned int *v84; // r1
  unsigned int v85; // r2
  int v86; // r2
  int v87; // r1
  char v88; // r4
  unsigned __int64 v89; // kr20_8
  int v90; // r4
  unsigned int v91; // r3
  int v92; // r3
  unsigned __int64 v93; // kr28_8
  int v94; // r2
  signed int v95; // r3
  signed int v96; // r3
  int v97; // [sp+0h] [bp-48h] BYREF
  int v98; // [sp+4h] [bp-44h]
  int v99; // [sp+8h] [bp-40h]
  int v100[4]; // [sp+10h] [bp-38h] BYREF
  unsigned int v101; // [sp+20h] [bp-28h] BYREF
  __int16 v102; // [sp+24h] [bp-24h]

  v99 = a1;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = (unsigned __int64 *)(a2 + 48);
      v4 = *(_DWORD *)(a2 + 52);
      v5 = *(_DWORD *)(a2 + 48);
      do
        v6 = __ldrexd(v3);
      while ( v6 == __PAIR64__(v4, v5) && __strexd(__PAIR64__(v4, v5), v3) );
      if ( __PAIR64__(v4, v5) == v6 )
        break;
      __dmb(0xAu);
      __yield();
    }
    v98 = 0;
    v7 = *(_BYTE *)(a2 + 350) == 1 ? *(char *)(a2 + 351) : 0;
    v8 = (unsigned int *)(a2 + 44);
    while ( 1 )
    {
      do
        v9 = __ldrex(v8);
      while ( __strex(1u, v8) );
      __dmb(0xBu);
      if ( !v9 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v8 );
    }
    if ( *(_BYTE *)(a2 + 350) )
    {
      if ( *(char *)(a2 + 123) >= 16 )
      {
        v16 = 1;
      }
      else
      {
        v10 = 0;
        v11 = KeTickCount - *(_DWORD *)(a2 + 304);
        if ( __PAIR64__(v4, v5) >= *(_QWORD *)(a2 + 24) )
        {
          v10 = 4;
          if ( v11 < 2 )
            v10 = 5;
        }
        if ( (v10 & 4) != 0 || *(char *)(a2 + 347) >= 14 || v11 >= 2 && !*(_BYTE *)(a2 + 348) )
        {
          v55 = *(char *)(a2 + 123);
          v10 |= 8u;
          if ( v55 < 16 )
          {
            v55 = (char)(-(*(_BYTE *)(a2 + 348) & 0xF) - (*(_BYTE *)(a2 + 348) >> 4) + v55 - 1);
            if ( v55 < *(char *)(a2 + 347) )
              v55 = *(char *)(a2 + 347);
            if ( *(_BYTE *)(a2 + 348) )
            {
              if ( (*(_BYTE *)(a2 + 348) & 0xF) != 0 )
                *(_DWORD *)(a2 + 812) = KeTickCount;
              *(_BYTE *)(a2 + 348) = 0;
            }
            v56 = *(_DWORD *)(a2 + 800);
            if ( v56 )
            {
              v95 = 31 - __clz(v56);
              v100[3] = v95;
              if ( v55 < v95 )
                v55 = (char)v95;
            }
          }
          KiAbProcessThreadPriorityModification(a2, v55, 1);
          *(_BYTE *)(a2 + 123) = v55;
        }
        if ( *(_BYTE *)(*(_DWORD *)(a2 + 336) + 606) == 2 )
          v10 |= 2u;
        if ( (v10 & 1) != 0
          || (*(_DWORD *)(a2 + 80) & 2) != 0
          || (v12 = *(unsigned __int8 *)(a2 + 348), (_BYTE)v12) && ((v12 & 0xFFFFFFF0) != 0 || (v10 & 2) == 0) )
        {
          if ( (v10 & 4) != 0 && (v10 & 2) != 0 && (*(_DWORD *)(a2 + 80) & 2) == 0 )
            KiScheduleNextForegroundBoost(a2);
        }
        else
        {
          v13 = *(char *)(a2 + 347);
          v14 = v13 + v7;
          v15 = v13 + v7;
          if ( (v10 & 2) != 0 )
            v15 = v14 + (char)PsPrioritySeparation;
          if ( v15 >= 16 )
            v15 = 15;
          if ( v15 > *(char *)(a2 + 123) )
          {
            v67 = 0;
            if ( v15 > v14 )
              v67 = v15 - v13 - v7;
            v68 = v15;
            *(_BYTE *)(a2 + 348) = (v67 ^ v12) & 0xF ^ v12;
            KiAbProcessThreadPriorityModification(a2, (char)v15, 1);
            *(_BYTE *)(a2 + 123) = v68;
          }
        }
        v16 = (unsigned __int8)(v10 & 8) >> 3;
      }
      if ( *(_BYTE *)(a2 + 350) != 2 )
        goto LABEL_29;
      v86 = *(char *)(a2 + 351);
      v87 = *(char *)(a2 + 123);
      if ( v87 < v86 && v87 < 13 && (*(_DWORD *)(a2 + 80) & 2) == 0 )
      {
        if ( v86 >= 13 )
          LOBYTE(v86) = 13;
        v88 = v86;
        *(_BYTE *)(a2 + 348) += 16 * (v86 - v87);
        KiAbProcessThreadPriorityModification(a2, (char)v86, 1);
        v89 = *(_QWORD *)(a2 + 24);
        *(_BYTE *)(a2 + 123) = v88;
        if ( __PAIR64__(v4, v5) > v89 )
        {
          *(_QWORD *)(a2 + 24) = __PAIR64__(v4, KiLockQuantumTarget) + v5;
        }
        else if ( v89 - __PAIR64__(v4, v5) < (unsigned int)KiLockQuantumTarget )
        {
          *(_QWORD *)(a2 + 24) = __PAIR64__(v4, KiLockQuantumTarget) + v5;
        }
LABEL_29:
        if ( v16 )
          goto LABEL_68;
        goto LABEL_30;
      }
      if ( v16 )
        goto LABEL_68;
      v93 = *(_QWORD *)(a2 + 24);
      if ( __PAIR64__(v4, v5) > v93 )
      {
        v94 = KiLockQuantumTarget;
      }
      else
      {
        v94 = KiLockQuantumTarget;
        if ( v93 - __PAIR64__(v4, v5) >= (unsigned int)KiLockQuantumTarget )
          goto LABEL_30;
      }
      *(_QWORD *)(a2 + 24) = __PAIR64__(v4, v94) + v5;
    }
    else
    {
      if ( __PAIR64__(v4, v5) >= *(_QWORD *)(a2 + 24) )
      {
        v90 = *(char *)(a2 + 123);
        if ( v90 < 16 )
        {
          v90 = (char)(-(*(_BYTE *)(a2 + 348) & 0xF) - (*(_BYTE *)(a2 + 348) >> 4) + v90 - 1);
          if ( v90 < *(char *)(a2 + 347) )
            v90 = *(char *)(a2 + 347);
          if ( *(_BYTE *)(a2 + 348) )
          {
            if ( (*(_BYTE *)(a2 + 348) & 0xF) != 0 )
              return sub_50C974(&KeTickCount);
            *(_BYTE *)(a2 + 348) = 0;
          }
          v91 = *(_DWORD *)(a2 + 800);
          if ( v91 )
          {
            v96 = 31 - __clz(v91);
            v100[2] = v96;
            if ( v90 < v96 )
              v90 = (char)v96;
          }
        }
        KiAbProcessThreadPriorityModification(a2, v90, 1);
        v92 = *(_DWORD *)(a2 + 336);
        *(_BYTE *)(a2 + 123) = v90;
        if ( *(_BYTE *)(v92 + 606) == 2 && *(char *)(a2 + 123) < 16 && (*(_DWORD *)(a2 + 80) & 2) == 0 )
          KiScheduleNextForegroundBoost(a2);
LABEL_68:
        v53 = __PAIR64__(v4, (unsigned int)*(unsigned __int8 *)(a2 + 403) * KiCyclesPerClockQuantum) + v5;
        if ( (*(_DWORD *)(a2 + 80) & 0x10) != 0 )
        {
          __dmb(0xBu);
          v78 = (unsigned __int8 *)(a2 + 80);
          do
            v79 = __ldrex(v78);
          while ( __strex(v79 & 0xEF, v78) );
          __dmb(0xBu);
        }
        *(_QWORD *)(a2 + 24) = v53;
        goto LABEL_30;
      }
      v98 = *(unsigned __int8 *)(a2 + 349);
    }
LABEL_30:
    *(_BYTE *)(a2 + 349) = 0;
    *(_BYTE *)(a2 + 350) = 0;
    v17 = *(_BYTE *)(a2 + 76);
    *(_BYTE *)(a2 + 76) = v17 & 0xFD;
    v18 = (unsigned __int8)(v17 & 2) >> 1;
    v100[1] = unk_681FE4;
    if ( *(_DWORD *)(a2 + 352) != KiCpuSetSequence && (*(_DWORD *)(a2 + 76) & 8) == 0 )
      KiComputeThreadAffinity(a2);
    v19 = *(_DWORD *)(a2 + 356);
    v102 = *(_WORD *)(a2 + 360);
    v101 = v19;
    if ( ((v19 - 1) & v19) != 0 )
    {
      if ( *(_BYTE *)(a2 + 85) )
        v20 = KiHeteroChooseTargetProcessor(v99, a2, &v101, &v97);
      else
        v20 = KiChooseTargetProcessor(v99, a2, &v101, &v97);
      v21 = v97;
      v22 = v20;
    }
    else
    {
      v22 = (int)*(&KiProcessorBlock + 31 - __clz(v19));
      v84 = (unsigned int *)(v22 + 24);
      while ( 1 )
      {
        do
          v85 = __ldrex(v84);
        while ( __strex(1u, v84) );
        __dmb(0xBu);
        if ( !v85 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v84 );
      }
      if ( (*(_BYTE *)(v22 + 19) & 1) != 0 )
      {
        v21 = 0;
        v97 = 0;
      }
      else
      {
        v21 = 1;
        v97 = 1;
      }
    }
    v23 = *(_DWORD *)(v22 + 20);
    *(_DWORD *)(a2 + 328) = v23;
    v24 = *(_DWORD *)(a2 + 68);
    if ( v24 )
      v24 += *(_DWORD *)(v22 + 2352);
    v100[0] = v24;
    if ( v24 )
    {
      v54 = v24;
      while ( (*(_BYTE *)(v54 + 92) & 2) == 0 )
      {
        v54 = *(_DWORD *)(v54 + 236);
        if ( !v54 )
          goto LABEL_38;
      }
      if ( !*(_DWORD *)(a2 + 308) && *(_BYTE *)(a2 + 134) != 1 )
        goto LABEL_84;
    }
LABEL_38:
    if ( v21 )
    {
      v25 = *(_DWORD *)(v22 + 8);
      if ( v25 && v25 != *(_DWORD *)(v22 + 12) )
        __fastfail(0x1Eu);
      if ( (*(_BYTE *)(a2 + 2) & 4) == 0 )
      {
        v26 = *(_BYTE *)(a2 + 123);
        goto LABEL_42;
      }
      if ( *(char *)(a2 + 123) < 16 )
      {
        if ( *(_DWORD *)(a2 + 68) )
        {
          v63 = *(_DWORD *)(a2 + 68);
          if ( v63 )
          {
            v64 = v63 + *(_DWORD *)(v22 + 2352);
            if ( v64 )
            {
              if ( *(char *)(a2 + 123) < 16 && (*(_DWORD *)(a2 + 80) & 0x100) == 0 )
              {
                v65 = v64;
                do
                {
                  if ( (*(_BYTE *)(v65 + 92) & 2) != 0 )
                  {
                    v66 = -1;
                    goto LABEL_113;
                  }
                  v65 = *(_DWORD *)(v65 + 236);
                }
                while ( v65 );
                while ( 1 )
                {
                  v66 = *(_DWORD *)(v64 + 96);
                  if ( v66 )
                    break;
                  v64 = *(_DWORD *)(v64 + 236);
                  if ( !v64 )
                    goto LABEL_113;
                }
LABEL_162:
                v26 = 1;
LABEL_42:
                **(_BYTE **)(v22 + 28) = v26;
                *(_DWORD *)(v22 + 8) = a2;
                *(_BYTE *)(a2 + 132) = 3;
                v27 = *(unsigned __int8 *)(v22 + 19);
                v28 = *(_DWORD *)(v22 + 2360);
                *(_BYTE *)(v22 + 1755) = 0;
                if ( (v27 & 1) != 0 )
                  __fastfail(0x21u);
                v29 = v27 + 1;
                *(_BYTE *)(v22 + 19) = v29;
                if ( v29 == 1 )
                {
                  v30 = *(unsigned __int8 *)(v22 + 1053);
                  __dmb(0xBu);
                  v31 = 1 << (v30 & 7);
                  v32 = (unsigned __int8 *)(v28 + (v30 >> 3));
                  do
                    v33 = __ldrex(v32);
                  while ( __strex(v33 & ~(_BYTE)v31, v32) );
                  __dmb(0xBu);
                }
                v34 = *(unsigned __int8 *)(v22 + 1053);
                __dmb(0xBu);
                v35 = 1 << (v34 & 7);
                v36 = (unsigned __int8 *)(v28 + (v34 >> 3) + 8);
                do
                  v37 = __ldrex(v36);
                while ( __strex(v37 & ~(_BYTE)v35, v36) );
                __dmb(0xBu);
                v38 = ~*(_DWORD *)(v22 + 3468);
                __dmb(0xBu);
                v39 = (unsigned int *)(v28 + 4);
                do
                  result = __ldrex(v39);
                while ( __strex(result & v38, v39) );
                __dmb(0xBu);
                *(_DWORD *)(v22 + 24) = 0;
                __dmb(0xBu);
                v41 = v99;
                *(_DWORD *)(a2 + 44) = 0;
                if ( v22 != v41 )
                {
                  v42 = (int)*(&KiProcessorBlock + v23);
                  __dmb(0xBu);
                  v43 = (unsigned int *)(v42 + 1676);
                  do
                    v44 = __ldrex(v43);
                  while ( __strex(v44 | 2, v43) );
LABEL_54:
                  __dmb(0xBu);
                  v45 = (unsigned int)KeGetPcr();
                  ++*(_DWORD *)((v45 & 0xFFFFF000) + 0x1414);
                  return HalSendSoftwareInterrupt(v23, 2);
                }
                return result;
              }
              v66 = 0;
LABEL_113:
              if ( v66 )
                goto LABEL_162;
            }
          }
        }
      }
      v26 = *(_BYTE *)(a2 + 123);
      goto LABEL_42;
    }
    v46 = *(char **)(v22 + 8);
    if ( !v46 )
      break;
    if ( KiGroupSchedulingEnabled )
    {
      if ( !KiEvaluateGroupSchedulingPreemption(v22, *(_DWORD *)(v22 + 8), a2, v100) )
        goto LABEL_83;
    }
    else if ( *(char *)(a2 + 123) <= v46[123] )
    {
      goto LABEL_84;
    }
    v46[349] = 1;
    if ( (*(_BYTE *)(a2 + 2) & 4) != 0 )
    {
      if ( *(char *)(a2 + 123) < 16
        && *(_DWORD *)(a2 + 68)
        && (v82 = *(_DWORD *)(a2 + 68)) != 0
        && (v83 = *(_DWORD *)(v22 + 2352) + v82) != 0
        && KiGetThreadEffectiveRankNonZero(a2, v83, 0) )
      {
        v76 = 1;
      }
      else
      {
        v76 = *(_BYTE *)(a2 + 123);
      }
    }
    else
    {
      v76 = *(_BYTE *)(a2 + 123);
    }
    **(_BYTE **)(v22 + 28) = v76;
    *(_DWORD *)(v22 + 8) = a2;
    *(_BYTE *)(a2 + 132) = 3;
    v46[132] = 7;
    __dmb(0xBu);
    *(_DWORD *)(v22 + 24) = 0;
    __dmb(0xBu);
    a2 = (int)v46;
    *v8 = 0;
  }
  result = (int)&KiProcessorBlock;
  v47 = *(char **)(v22 + 4);
  if ( KiGroupSchedulingEnabled )
  {
    if ( KiEvaluateGroupSchedulingPreemption(v22, *(_DWORD *)(v22 + 4), a2, v100) )
    {
      result = (int)&KiProcessorBlock;
      goto LABEL_59;
    }
LABEL_83:
    v24 = v100[0];
LABEL_84:
    if ( !v18 )
      *(_DWORD *)(a2 + 304) = KeTickCount;
    if ( !v24 )
    {
      v24 = *(_DWORD *)(a2 + 68);
      if ( v24 )
        v24 += *(_DWORD *)(v22 + 2352);
    }
    __dmb(0xBu);
    *(_BYTE *)(a2 + 132) = 1;
    if ( v24 && (*(_DWORD *)(a2 + 80) & 0x600) == 0 && KiGetThreadEffectiveRankNonZero(a2, v24, 0) )
    {
      result = KiAddThreadToScbQueue(v22, v24, a2, v98);
    }
    else
    {
      v57 = *(char *)(a2 + 123);
      v58 = *(_DWORD *)(v22 + 3456);
      if ( (*(_DWORD *)(a2 + 80) & 0x1000) != 0 && v58 && (*(_DWORD *)(a2 + 356) & v58) == v58 )
      {
        result = *(_DWORD *)(v22 + 3460);
        v59 = (int *)(result + 8 * (v57 + 1));
        while ( 1 )
        {
          do
            v60 = __ldrex((unsigned int *)result);
          while ( __strex(1u, (unsigned int *)result) );
          __dmb(0xBu);
          if ( !v60 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *(_DWORD *)result );
        }
        v61 = (int *)(a2 + 144);
        if ( v98 )
        {
          v77 = *v59;
          *v61 = *v59;
          *(_DWORD *)(a2 + 148) = v59;
          if ( *(int **)(v77 + 4) != v59 )
            __fastfail(3u);
          *(_DWORD *)(v77 + 4) = v61;
          *v59 = (int)v61;
          *(_BYTE *)(v22 + (v57 >> 3) + 1936) &= ~(1 << (v57 & 7));
        }
        else
        {
          v62 = (int **)v59[1];
          *v61 = (int)v59;
          *(_DWORD *)(a2 + 148) = v62;
          if ( *v62 != v59 )
            __fastfail(3u);
          *v62 = v61;
          v59[1] = (int)v61;
        }
        *(_DWORD *)(result + 4) |= 1 << v57;
        *(_DWORD *)(a2 + 328) |= 0x80000000;
        __dmb(0xBu);
        *(_DWORD *)result = 0;
      }
      else
      {
        v73 = v57 + 256;
        if ( v98 )
        {
          result = *(_DWORD *)(v22 + 8 * v73);
          v80 = a2 + 144;
          v81 = (int *)(v22 + 8 * v73);
          *(_DWORD *)(a2 + 144) = result;
          *(_DWORD *)(a2 + 148) = v81;
          if ( *(int **)(result + 4) != v81 )
            __fastfail(3u);
          *(_DWORD *)(result + 4) = v80;
          *v81 = v80;
          *(_BYTE *)(v22 + (v57 >> 3) + 1936) |= 1 << (v57 & 7);
        }
        else
        {
          v74 = v22 + 8 * v73;
          result = *(_DWORD *)(v74 + 4);
          v75 = a2 + 144;
          *(_DWORD *)(a2 + 144) = v74;
          *(_DWORD *)(a2 + 148) = result;
          if ( *(_DWORD *)result != v74 )
            __fastfail(3u);
          *(_DWORD *)result = v75;
          *(_DWORD *)(v74 + 4) = v75;
        }
        *(_DWORD *)(v22 + 1932) |= 1 << v57;
      }
    }
    __dmb(0xBu);
    *(_DWORD *)(v22 + 24) = 0;
    __dmb(0xBu);
    *(_DWORD *)(a2 + 44) = 0;
    return result;
  }
  if ( *(char *)(a2 + 123) <= v47[123] )
    goto LABEL_84;
LABEL_59:
  if ( v47[132] == 2 )
    v47[349] = 1;
  if ( (*(_BYTE *)(a2 + 2) & 4) == 0 )
  {
    v48 = *(_BYTE *)(a2 + 123);
    goto LABEL_63;
  }
  if ( *(char *)(a2 + 123) >= 16
    || !*(_DWORD *)(a2 + 68)
    || (v69 = *(_DWORD *)(a2 + 68)) == 0
    || (v70 = v69 + *(_DWORD *)(v22 + 2352)) == 0 )
  {
LABEL_137:
    v48 = *(_BYTE *)(a2 + 123);
    goto LABEL_63;
  }
  if ( *(char *)(a2 + 123) >= 16 || (*(_DWORD *)(a2 + 80) & 0x100) != 0 )
  {
    v72 = 0;
LABEL_136:
    if ( v72 )
      goto LABEL_166;
    goto LABEL_137;
  }
  v71 = v70;
  do
  {
    if ( (*(_BYTE *)(v71 + 92) & 2) != 0 )
    {
      v72 = -1;
      goto LABEL_136;
    }
    v71 = *(_DWORD *)(v71 + 236);
  }
  while ( v71 );
  while ( 1 )
  {
    v72 = *(_DWORD *)(v70 + 96);
    if ( v72 )
      break;
    v70 = *(_DWORD *)(v70 + 236);
    if ( !v70 )
      goto LABEL_136;
  }
LABEL_166:
  v48 = 1;
LABEL_63:
  **(_BYTE **)(v22 + 28) = v48;
  *(_DWORD *)(v22 + 8) = a2;
  *(_BYTE *)(a2 + 132) = 3;
  __dmb(0xBu);
  *(_DWORD *)(v22 + 24) = 0;
  __dmb(0xBu);
  v49 = v99;
  *(_DWORD *)(a2 + 44) = 0;
  if ( v49 != v22 )
  {
    v50 = (int)*(&KiProcessorBlock + v23);
    __dmb(0xBu);
    v51 = (unsigned int *)(v50 + 1676);
    do
      v52 = __ldrex(v51);
    while ( __strex(v52 | 2, v51) );
    goto LABEL_54;
  }
  return result;
}
