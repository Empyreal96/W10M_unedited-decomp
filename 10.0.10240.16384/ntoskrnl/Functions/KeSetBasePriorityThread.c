// KeSetBasePriorityThread 
 
int __fastcall KeSetBasePriorityThread(int a1, int a2)
{
  int v2; // r5
  _DWORD *v6; // r6
  unsigned int v7; // r3
  unsigned int v8; // r8
  unsigned int *v9; // r10
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r3
  int v16; // r9
  int v17; // r2
  unsigned int v18; // r3
  int v19; // r5
  char v20; // r2
  __int64 v21; // r0
  unsigned __int64 *v22; // r4
  unsigned int v23; // r5
  unsigned int v24; // r6
  __int64 v25; // kr18_8
  unsigned __int64 v26; // r2
  __int64 v27; // r2
  int v28; // lr
  int v29; // r4
  unsigned __int64 *v30; // r4
  unsigned __int64 v31; // kr38_8
  unsigned __int64 v32; // kr40_8
  int v33; // r1
  int i; // r1
  __int64 v35; // r0
  unsigned int v36; // r3
  unsigned int v37; // r2
  unsigned __int64 v38; // kr48_8
  unsigned __int64 *v39; // r3
  unsigned __int64 v40; // kr50_8
  __int64 v41; // kr58_8
  unsigned __int64 *v42; // r4
  unsigned __int64 v43; // kr60_8
  unsigned __int64 v44; // kr68_8
  int v45; // r6
  int v46; // r0
  unsigned __int64 v47; // kr70_8
  _BYTE *v48; // r0
  __int64 v49; // kr78_8
  char v50; // r3
  unsigned __int64 *v51; // r1
  unsigned int v52; // r10
  unsigned __int64 v53; // kr88_8
  unsigned __int64 *v54; // r3
  unsigned __int64 v55; // kr90_8
  _DWORD *v56; // r1
  unsigned int *v57; // r1
  unsigned int v58; // r2
  int v59; // r3
  unsigned int v60; // r3
  unsigned int v61; // r2
  __int64 v62; // r0
  unsigned int v63; // lr
  unsigned __int64 *v64; // r6
  __int64 v65; // krA0_8
  unsigned __int64 v66; // krB0_8
  unsigned __int64 v67; // r2
  char v68; // r5
  int v69; // r4
  int v70; // r0
  unsigned __int64 *v71; // r4
  unsigned __int64 v72; // krB8_8
  unsigned __int64 v73; // krC0_8
  int v74; // r1
  int v75; // r5
  int v76; // r4
  unsigned __int8 *v77; // r3
  unsigned int v78; // r2
  signed int v79; // r3
  unsigned int v80; // r6
  unsigned int v81; // r1
  unsigned int v82; // r4
  unsigned int v83; // r3
  bool v84; // cf
  int v85; // r3
  int v86; // r2
  int v87; // r2
  int v88; // [sp+8h] [bp-50h]
  int v89; // [sp+Ch] [bp-4Ch] BYREF
  unsigned int v90; // [sp+10h] [bp-48h]
  unsigned int v91; // [sp+14h] [bp-44h]
  int v92; // [sp+18h] [bp-40h]
  int v93; // [sp+1Ch] [bp-3Ch]
  int v94[2]; // [sp+20h] [bp-38h] BYREF
  int v95; // [sp+28h] [bp-30h]
  __int64 v96; // [sp+2Ch] [bp-2Ch]
  int v97; // [sp+34h] [bp-24h]
  int v98; // [sp+38h] [bp-20h]

  v2 = *(_DWORD *)(a1 + 336);
  if ( (_UNKNOWN *)v2 == &KiInitialProcess )
    return sub_52B364();
  v6 = 0;
  v94[0] = 0;
  v91 = KfRaiseIrql(2);
  v7 = (unsigned int)KeGetPcr();
  v8 = (v7 & 0xFFFFF000) + 1408;
  v90 = a1 == *(_DWORD *)((v7 & 0xFFFFF000) + 0x584);
  v9 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v10 = __ldrex(v9);
    while ( __strex(1u, v9) );
    __dmb(0xBu);
    if ( !v10 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v9 );
  }
  v11 = *(char *)(a1 + 347);
  v12 = *(char *)(v2 + 104);
  v98 = v11;
  v13 = v11 - v12;
  v14 = *(char *)(a1 + 397);
  v95 = v13;
  if ( v14 )
    v95 = 16 * v14;
  *(_BYTE *)(a1 + 397) = 0;
  if ( (int)abs32(a2) >= 16 )
  {
    if ( a2 <= 0 )
      v50 = -1;
    else
      v50 = 1;
    *(_BYTE *)(a1 + 397) = v50;
  }
  v15 = *(char *)(v2 + 104);
  v16 = v15 + a2;
  if ( v15 >= 16 )
  {
    if ( v16 >= 16 )
    {
      if ( v16 > 31 )
        v16 = 31;
    }
    else
    {
      v16 = 16;
    }
    v19 = v16;
    v89 = v16;
  }
  else
  {
    if ( v16 >= 16 )
    {
      v16 = 15;
    }
    else if ( v16 <= 0 )
    {
      v16 = 1;
    }
    if ( *(_BYTE *)(a1 + 397) )
    {
      v19 = v16;
      v89 = v16;
    }
    else
    {
      v17 = *(char *)(a1 + 123);
      if ( v17 < 16 )
      {
        v17 = (char)(-(*(_BYTE *)(a1 + 348) & 0xF) - (*(_BYTE *)(a1 + 348) >> 4) + v17);
        if ( v17 < v11 )
          v17 = v11;
        if ( *(_BYTE *)(a1 + 348) )
        {
          if ( (*(_BYTE *)(a1 + 348) & 0xF) != 0 )
            *(_DWORD *)(a1 + 812) = KeTickCount;
          *(_BYTE *)(a1 + 348) = 0;
        }
        v18 = *(_DWORD *)(a1 + 800);
        if ( v18 )
        {
          v79 = 31 - __clz(v18);
          if ( v17 < v79 )
            v17 = (char)v79;
        }
      }
      v19 = v17 - v11 + v16;
      v88 = v19;
      v89 = v19;
      if ( v19 >= 16 )
      {
        v19 = 15;
      }
      else
      {
        if ( v19 > 0 )
          goto LABEL_21;
        v19 = 1;
      }
      v89 = v19;
    }
  }
  v88 = v19;
LABEL_21:
  KiAbProcessThreadPriorityModification(a1, (char)v16, 0);
  v20 = *(_BYTE *)(a1 + 348);
  *(_BYTE *)(a1 + 347) = v16;
  if ( v20 )
  {
    if ( (v20 & 0xF) != 0 )
      *(_DWORD *)(a1 + 812) = KeTickCount;
    *(_BYTE *)(a1 + 348) = 0;
  }
  if ( v19 != *(char *)(a1 + 123) )
  {
    if ( v90 )
    {
      if ( *(_BYTE *)(v8 + 16) )
      {
        v45 = *(_DWORD *)(a1 + 52);
        v90 = *(_DWORD *)(a1 + 48);
      }
      else
      {
        __disable_irq();
        *(_BYTE *)(v8 + 16) = 1;
        LODWORD(v21) = ReadTimeStampCounter();
        v22 = (unsigned __int64 *)(a1 + 48);
        v25 = *(_QWORD *)(a1 + 48);
        v96 = v21 - *(_QWORD *)(v8 + 2376);
        v24 = HIDWORD(v96);
        v23 = v96;
        v97 = (unsigned __int64)(v25 + v96) >> 32;
        v90 = v25 + v96;
        __dmb(0xBu);
        do
          v26 = __ldrexd(v22);
        while ( __strexd(__PAIR64__((unsigned __int64)(v25 + v96) >> 32, v90), v22) );
        __dmb(0xBu);
        v9 = (unsigned int *)(a1 + 44);
        v27 = v96 + *(unsigned int *)(a1 + 56);
        if ( HIDWORD(v27) )
        {
          v93 = 0;
          LODWORD(v27) = -1;
        }
        *(_QWORD *)(v8 + 2376) = v21;
        v28 = *(unsigned __int8 *)(a1 + 2);
        *(_DWORD *)(a1 + 56) = v27;
        v92 = v28;
        if ( (v28 & 0x3E) != 0 )
        {
          if ( (v28 & 0x10) != 0 )
          {
            v80 = v8 + 8 * *(unsigned __int8 *)(a1 + 84);
            *(_QWORD *)(v80 + 2392) = *(_QWORD *)(v80 + 2392) - *(_QWORD *)(v8 + 2384) + *(_QWORD *)(v8 + 2376);
            v28 &= 0xEFu;
            v24 = HIDWORD(v96);
            v23 = v96;
            *(_DWORD *)(v8 + 2384) = 0;
            *(_DWORD *)(v8 + 2388) = 0;
            v92 = v28;
          }
          if ( (v28 & 0x3E) != 0 )
          {
            if ( (v28 & 0x20) != 0 )
            {
              v29 = *(_DWORD *)(a1 + 1084);
              if ( v29 )
              {
                v30 = (unsigned __int64 *)(v29 + 8 * (*(unsigned __int8 *)(v8 + 2986) + 2 * PoGetFrequencyBucket(v8)));
                v31 = *v30 + __PAIR64__(v24, v23);
                __dmb(0xBu);
                do
                  v32 = __ldrexd(v30);
                while ( __strexd(v31, v30) );
                __dmb(0xBu);
                LOBYTE(v28) = v92;
              }
              LOBYTE(v28) = v28 & 0xDF;
            }
            if ( (v28 & 0x3E) != 0 )
            {
              v33 = *(_DWORD *)(a1 + 68);
              if ( v33 )
              {
                for ( i = v33 + *(_DWORD *)(v8 + 2352); i; i = *(_DWORD *)(i + 236) )
                  *(_QWORD *)i += __PAIR64__(v24, v23);
              }
              if ( (*(_BYTE *)(a1 + 2) & 8) != 0
                && (*(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) & *(_DWORD *)(a1 + 356)) != *(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) )
              {
                *(_QWORD *)(v8 + 2368) += __PAIR64__(v24, v23);
              }
              if ( *(_DWORD *)(a1 + 236) )
                KiEndCounterAccumulation(a1);
            }
          }
        }
        LODWORD(v35) = ReadTimeStampCounter();
        v36 = *(_DWORD *)(v8 + 2376);
        v37 = *(_DWORD *)(v8 + 2380);
        v96 = v35;
        v38 = v35 - __PAIR64__(v37, v36);
        __dmb(0xBu);
        v39 = (unsigned __int64 *)(v8 + 2744);
        do
          v40 = __ldrexd(v39);
        while ( __strexd(v40 + v38, v39) );
        __dmb(0xBu);
        if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v41 = v35 - *(_QWORD *)(v8 + 2376);
          v42 = (unsigned __int64 *)(v8 + 8 * (*(unsigned __int8 *)(v8 + 2986) + 2 * (PoGetFrequencyBucket(v8) + 1144)));
          v43 = *v42 + v41;
          __dmb(0xBu);
          do
            v44 = __ldrexd(v42);
          while ( __strexd(v43, v42) );
          __dmb(0xBu);
          v35 = v96;
        }
        *(_QWORD *)(v8 + 2376) = v35;
        if ( (*(_BYTE *)(a1 + 2) & 0x10) != 0 )
          *(_QWORD *)(v8 + 2384) = v35;
        if ( (*(_BYTE *)(a1 + 2) & 2) != 0 )
          KiBeginCounterAccumulation(a1, 0);
        v19 = v88;
        v45 = v97;
        *(_BYTE *)(v8 + 16) = 0;
        __enable_irq();
      }
      v46 = 0;
    }
    else
    {
      v51 = (unsigned __int64 *)(a1 + 48);
      while ( 1 )
      {
        v45 = *(_DWORD *)(a1 + 52);
        v52 = *(_DWORD *)v51;
        v90 = *(_DWORD *)v51;
        do
          v53 = __ldrexd(v51);
        while ( __PAIR64__(v53, HIDWORD(v53)) == __PAIR64__(v52, v45) && __strexd(__PAIR64__(v45, v52), v51) );
        if ( __PAIR64__(v52, v45) == __PAIR64__(v53, HIDWORD(v53)) )
          break;
        __dmb(0xAu);
        __yield();
      }
      v46 = 1;
      v9 = (unsigned int *)(a1 + 44);
    }
    v47 = __PAIR64__(v45, (unsigned int)*(unsigned __int8 *)(a1 + 403) * KiCyclesPerClockQuantum) + v90;
    if ( (*(_DWORD *)(a1 + 80) & 0x10) != 0 )
    {
      __dmb(0xBu);
      v77 = (unsigned __int8 *)(a1 + 80);
      do
        v78 = __ldrex(v77);
      while ( __strex(v78 & 0xEF, v77) );
      __dmb(0xBu);
    }
    if ( v46 )
    {
      __dmb(0xBu);
      v54 = (unsigned __int64 *)(a1 + 24);
      do
        v55 = __ldrexd(v54);
      while ( __strexd(v47, v54) );
      __dmb(0xBu);
    }
    else
    {
      *(_QWORD *)(a1 + 24) = v47;
    }
    KiSetPriorityThread(a1, v94, v19);
    v6 = (_DWORD *)v94[0];
  }
  v48 = *(_BYTE **)(a1 + 152);
  if ( v48 && (*v48 & 0x7F) == 21 )
  {
    KiPriQueueThreadPriorityChanged((int)v48, a1);
  }
  else
  {
    __dmb(0xBu);
    *v9 = 0;
  }
  while ( v6 )
  {
    v56 = v6 - 36;
    v6 = (_DWORD *)*v6;
    KiDeferredReadyThread(v8, v56);
  }
  if ( v91 >= 2 )
  {
    if ( *(_DWORD *)(v8 + 8) && !*(_BYTE *)(v8 + 1754) )
      HalRequestSoftwareInterrupt(2);
    goto LABEL_67;
  }
  v49 = *(_QWORD *)(v8 + 4);
  if ( HIDWORD(v49) )
  {
    KiAbProcessContextSwitch(v49, 0);
    v57 = (unsigned int *)(v8 + 24);
    while ( 1 )
    {
      do
        v58 = __ldrex(v57);
      while ( __strex(1u, v57) );
      __dmb(0xBu);
      if ( !v58 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v57 );
    }
    v59 = *(_DWORD *)(v8 + 8);
    *(_DWORD *)(v8 + 8) = 0;
    __disable_irq();
    LODWORD(v96) = v59;
    *(_BYTE *)(v8 + 16) = 1;
    LODWORD(v62) = ReadTimeStampCounter();
    v60 = *(_DWORD *)(v8 + 2376);
    v61 = *(_DWORD *)(v8 + 2380);
    v97 = v62;
    v64 = (unsigned __int64 *)(v49 + 48);
    v63 = (v62 - __PAIR64__(v61, v60)) >> 32;
    LODWORD(v62) = v62 - v60;
    v65 = *(_QWORD *)(v49 + 48);
    v90 = v62;
    HIDWORD(v96) = v63;
    __dmb(0xBu);
    do
      v66 = __ldrexd(v64);
    while ( __strexd(v65 + __PAIR64__(v63, v62), v64) );
    __dmb(0xBu);
    v67 = __PAIR64__(v63, *(_DWORD *)(v49 + 56)) + (unsigned int)v62;
    if ( HIDWORD(v67) )
    {
      v94[1] = 0;
      LODWORD(v67) = -1;
    }
    HIDWORD(v67) = v97;
    *(_DWORD *)(v8 + 2380) = HIDWORD(v62);
    *(_DWORD *)(v8 + 2376) = HIDWORD(v67);
    v68 = *(_BYTE *)(v49 + 2);
    *(_DWORD *)(v49 + 56) = v67;
    if ( (v68 & 0x3E) != 0 )
    {
      if ( (v68 & 0x10) != 0 )
      {
        v81 = *(_DWORD *)(v8 + 2376);
        v82 = v8 + 8 * *(unsigned __int8 *)(v49 + 84);
        v83 = *(_DWORD *)(v8 + 2384);
        v68 &= 0xEFu;
        v84 = v81 >= v83;
        HIDWORD(v62) = v81 - v83;
        v85 = *(_DWORD *)(v82 + 2392);
        LODWORD(v62) = *(_DWORD *)(v8 + 2380) - (*(_DWORD *)(v8 + 2388) + !v84);
        v86 = *(_DWORD *)(v82 + 2396);
        *(_DWORD *)(v82 + 2392) = v85 + HIDWORD(v62);
        v87 = v62 + __CFADD__(v85, HIDWORD(v62)) + v86;
        LODWORD(v62) = v90;
        *(_DWORD *)(v82 + 2396) = v87;
        *(_DWORD *)(v8 + 2384) = 0;
        *(_DWORD *)(v8 + 2388) = 0;
      }
      if ( (v68 & 0x3E) != 0 )
      {
        if ( (v68 & 0x20) != 0 )
        {
          v69 = *(_DWORD *)(v49 + 1084);
          if ( v69 )
          {
            v70 = PoGetFrequencyBucket(v8);
            v63 = HIDWORD(v96);
            v71 = (unsigned __int64 *)(v69 + 8 * (*(unsigned __int8 *)(v8 + 2986) + 2 * v70));
            v72 = *v71 + __PAIR64__(HIDWORD(v96), v90);
            __dmb(0xBu);
            do
              v73 = __ldrexd(v71);
            while ( __strexd(v72, v71) );
            __dmb(0xBu);
            LODWORD(v62) = v90;
          }
          v68 &= 0xDFu;
        }
        if ( (v68 & 0x3E) != 0 )
        {
          v74 = *(_DWORD *)(v49 + 68);
          if ( v74 )
          {
            for ( HIDWORD(v62) = v74 + *(_DWORD *)(v8 + 2352); HIDWORD(v62); HIDWORD(v62) = *(_DWORD *)(HIDWORD(v62) + 236) )
              *(_QWORD *)HIDWORD(v62) += __PAIR64__(v63, v62);
          }
          if ( (*(_BYTE *)(v49 + 2) & 8) != 0
            && (*(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) & *(_DWORD *)(v49 + 356)) != *(_DWORD *)(*(_DWORD *)(v8 + 2360)
                                                                                                 + 260) )
          {
            *(_QWORD *)(v8 + 2368) += __PAIR64__(v63, v62);
          }
          if ( *(_DWORD *)(v49 + 236) )
            KiEndCounterAccumulation(v49);
        }
      }
    }
    v75 = v96;
    v76 = v91;
    __enable_irq();
    *(_DWORD *)(v8 + 4) = v75;
    *(_BYTE *)(v75 + 132) = 2;
    *(_BYTE *)(v49 + 395) = 32;
    *(_BYTE *)(v49 + 134) = v76;
    KiQueueReadyThread(v8, v49);
    if ( !KiSwapContext(v49, v75, v76) )
      goto LABEL_72;
    goto LABEL_131;
  }
  if ( (*(_DWORD *)(v49 + 76) & 0x40) != 0 )
  {
LABEL_131:
    KfLowerIrql(1);
    *(_DWORD *)(v49 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
  }
LABEL_72:
  KfLowerIrql(v91);
LABEL_67:
  if ( (dword_682604 & 0x2000) != 0 )
    EtwTracePriority(a1, 1329, v98, v16, &v89);
  return v95;
}
