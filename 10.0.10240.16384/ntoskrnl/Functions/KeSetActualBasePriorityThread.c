// KeSetActualBasePriorityThread 
 
int __fastcall KeSetActualBasePriorityThread(int a1, int a2)
{
  void *v2; // r2
  int v3; // r8
  _DWORD *v6; // r5
  unsigned int v7; // r3
  unsigned int v8; // r10
  BOOL v9; // r6
  unsigned int *v10; // r9
  unsigned int v11; // r2
  int v12; // r3
  unsigned __int64 *v13; // r1
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // kr10_8
  unsigned __int64 v16; // r0
  int v17; // r4
  unsigned __int64 v18; // kr18_8
  unsigned __int64 *v19; // r3
  unsigned __int64 v20; // kr20_8
  _BYTE *v21; // r0
  int v22; // r9
  int v23; // r3
  int v24; // r4
  int v25; // r4
  void (__fastcall **v26)(int); // r3
  int v27; // r0
  __int64 v28; // r0
  int v29; // r5
  __int64 v30; // kr28_8
  unsigned __int64 *v31; // r4
  int v32; // r6
  unsigned __int64 v33; // r0
  unsigned __int64 v34; // r2
  unsigned int v35; // r0
  __int64 v36; // r2
  char v37; // lr
  int v38; // r4
  unsigned int v39; // r5
  unsigned __int64 *v40; // r4
  unsigned __int64 v41; // kr40_8
  unsigned __int64 v42; // kr48_8
  unsigned __int64 v43; // r0
  unsigned __int64 v44; // kr50_8
  unsigned __int64 *v45; // r3
  unsigned __int64 v46; // kr58_8
  unsigned __int64 v47; // kr60_8
  unsigned __int64 *v48; // r4
  unsigned __int64 v49; // kr68_8
  unsigned __int64 v50; // kr70_8
  _DWORD *v51; // r1
  unsigned int *v52; // r1
  unsigned int v53; // r2
  int v54; // r3
  __int64 v55; // r0
  unsigned int v56; // r3
  unsigned int v57; // r2
  __int64 v58; // r0
  int v59; // lr
  unsigned __int64 *v60; // r6
  unsigned __int64 v61; // kr78_8
  unsigned __int64 v62; // kr80_8
  __int64 v63; // r2
  int v64; // lr
  int v65; // r5
  unsigned __int64 *v66; // r4
  unsigned int v67; // r5
  unsigned __int64 v68; // kr98_8
  unsigned __int64 v69; // krA0_8
  int v70; // r1
  int v71; // r5
  unsigned __int8 *v72; // r3
  unsigned int v73; // r2
  int v74; // r1
  int i; // r1
  unsigned int v76; // r6
  unsigned int v77; // r6
  unsigned int v78; // [sp+Ch] [bp-44h]
  unsigned int v79; // [sp+Ch] [bp-44h]
  unsigned int v80; // [sp+10h] [bp-40h]
  unsigned int v81; // [sp+10h] [bp-40h]
  unsigned int v82; // [sp+10h] [bp-40h]
  unsigned int v83; // [sp+14h] [bp-3Ch]
  int v84; // [sp+14h] [bp-3Ch]
  unsigned int v85; // [sp+14h] [bp-3Ch]
  char v87; // [sp+18h] [bp-38h]
  unsigned int v88; // [sp+18h] [bp-38h]
  int v89; // [sp+18h] [bp-38h]
  int v90[2]; // [sp+20h] [bp-30h] BYREF
  int v91; // [sp+28h] [bp-28h]
  unsigned int v92; // [sp+2Ch] [bp-24h]
  int anonymous0; // [sp+58h] [bp+8h]
  int varsC; // [sp+5Ch] [bp+Ch] BYREF

  anonymous0 = a1;
  varsC = a2;
  v2 = *(void **)(a1 + 336);
  v3 = a2;
  varsC = a2;
  if ( v2 == &KiInitialProcess )
    return sub_50BD4C();
  v6 = 0;
  v90[0] = 0;
  v92 = KfRaiseIrql(2);
  v7 = (unsigned int)KeGetPcr();
  v8 = (v7 & 0xFFFFF000) + 1408;
  v9 = a1 == *(_DWORD *)((v7 & 0xFFFFF000) + 0x584);
  v10 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v11 = __ldrex(v10);
    while ( __strex(1u, v10) );
    __dmb(0xBu);
    if ( !v11 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v10 );
  }
  v91 = *(char *)(a1 + 347);
  *(_BYTE *)(a1 + 397) = 0;
  KiAbProcessThreadPriorityModification(a1, (char)v3, 0);
  v12 = *(char *)(a1 + 348);
  *(_BYTE *)(a1 + 347) = v3;
  if ( v12 )
  {
    if ( (v12 & 0xF) != 0 )
      *(_DWORD *)(a1 + 812) = KeTickCount;
    *(_BYTE *)(a1 + 348) = 0;
  }
  if ( v3 != *(char *)(a1 + 123) )
  {
    if ( v9 )
    {
      if ( *(_BYTE *)(v8 + 16) )
      {
        v16 = *(_QWORD *)(a1 + 48);
      }
      else
      {
        __disable_irq();
        *(_BYTE *)(v8 + 16) = 1;
        LODWORD(v28) = ReadTimeStampCounter();
        v29 = HIDWORD(v28);
        v31 = (unsigned __int64 *)(a1 + 48);
        v30 = v28 - *(_QWORD *)(v8 + 2376);
        v32 = v28;
        v33 = *(_QWORD *)(a1 + 48) + v30;
        v81 = HIDWORD(v33);
        v85 = *(_DWORD *)(a1 + 48) + v30;
        __dmb(0xBu);
        do
          v34 = __ldrexd(v31);
        while ( __strexd(v33, v31) );
        __dmb(0xBu);
        v35 = HIDWORD(v30);
        v36 = v30 + *(unsigned int *)(a1 + 56);
        if ( HIDWORD(v36) )
          LODWORD(v36) = -1;
        *(_DWORD *)(v8 + 2376) = v32;
        *(_DWORD *)(v8 + 2380) = v29;
        v37 = *(_BYTE *)(a1 + 2);
        *(_DWORD *)(a1 + 56) = v36;
        v87 = v37;
        if ( (v37 & 0x3E) != 0 )
        {
          if ( (v37 & 0x10) != 0 )
          {
            v76 = v8 + 8 * *(unsigned __int8 *)(a1 + 84);
            *(_QWORD *)(v76 + 2392) = *(_QWORD *)(v76 + 2392) - *(_QWORD *)(v8 + 2384) + *(_QWORD *)(v8 + 2376);
            v37 &= 0xEFu;
            v35 = HIDWORD(v30);
            *(_DWORD *)(v8 + 2384) = 0;
            *(_DWORD *)(v8 + 2388) = 0;
            v87 = v37;
          }
          if ( (v37 & 0x3E) != 0 )
          {
            if ( (v37 & 0x20) != 0 )
            {
              v38 = *(_DWORD *)(a1 + 1084);
              if ( v38 )
              {
                v39 = v30;
                v40 = (unsigned __int64 *)(v38 + 8 * (*(unsigned __int8 *)(v8 + 2986) + 2 * PoGetFrequencyBucket(v8)));
                v41 = *v40 + v30;
                __dmb(0xBu);
                do
                  v42 = __ldrexd(v40);
                while ( __strexd(v41, v40) );
                __dmb(0xBu);
                v37 = v87;
                v35 = HIDWORD(v30);
              }
              else
              {
                v39 = v30;
              }
              v37 &= 0xDFu;
            }
            else
            {
              v39 = v30;
            }
            if ( (v37 & 0x3E) != 0 )
            {
              v74 = *(_DWORD *)(a1 + 68);
              if ( v74 )
              {
                for ( i = v74 + *(_DWORD *)(v8 + 2352); i; i = *(_DWORD *)(i + 236) )
                  *(_QWORD *)i += __PAIR64__(v35, v39);
              }
              if ( (*(_BYTE *)(a1 + 2) & 8) != 0
                && (*(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) & *(_DWORD *)(a1 + 356)) != *(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) )
              {
                *(_QWORD *)(v8 + 2368) += __PAIR64__(v35, v39);
              }
              if ( *(_DWORD *)(a1 + 236) )
                KiEndCounterAccumulation(a1);
            }
          }
        }
        LODWORD(v43) = ReadTimeStampCounter();
        v88 = HIDWORD(v43);
        v44 = v43 - *(_QWORD *)(v8 + 2376);
        v78 = v43;
        __dmb(0xBu);
        v45 = (unsigned __int64 *)(v8 + 2744);
        do
          v46 = __ldrexd(v45);
        while ( __strexd(v46 + v44, v45) );
        __dmb(0xBu);
        if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v47 = v43 - *(_QWORD *)(v8 + 2376);
          v48 = (unsigned __int64 *)(v8 + 8 * (*(unsigned __int8 *)(v8 + 2986) + 2 * (PoGetFrequencyBucket(v8) + 1144)));
          v49 = *v48 + v47;
          __dmb(0xBu);
          do
            v50 = __ldrexd(v48);
          while ( __strexd(v49, v48) );
          __dmb(0xBu);
          v43 = __PAIR64__(v88, v78);
        }
        *(_QWORD *)(v8 + 2376) = v43;
        if ( (*(_BYTE *)(a1 + 2) & 0x10) != 0 )
          *(_QWORD *)(v8 + 2384) = v43;
        if ( (*(_BYTE *)(a1 + 2) & 2) != 0 )
          KiBeginCounterAccumulation(a1, 0);
        v16 = __PAIR64__(v81, v85);
        *(_BYTE *)(v8 + 16) = 0;
        __enable_irq();
      }
      v17 = 0;
    }
    else
    {
      v13 = (unsigned __int64 *)(a1 + 48);
      while ( 1 )
      {
        v14 = *v13;
        v80 = *(_DWORD *)(a1 + 52);
        v83 = *(_DWORD *)v13;
        do
          v15 = __ldrexd(v13);
        while ( v15 == v14 && __strexd(v14, v13) );
        if ( __PAIR64__(v14, HIDWORD(v14)) == __PAIR64__(v15, HIDWORD(v15)) )
          break;
        __dmb(0xAu);
        __yield();
      }
      v16 = __PAIR64__(v80, v83);
      v3 = a2;
      v17 = 1;
      v10 = (unsigned int *)(a1 + 44);
    }
    v18 = v16 + (unsigned int)*(unsigned __int8 *)(a1 + 403) * KiCyclesPerClockQuantum;
    if ( (*(_DWORD *)(a1 + 80) & 0x10) != 0 )
    {
      __dmb(0xBu);
      v72 = (unsigned __int8 *)(a1 + 80);
      do
        v73 = __ldrex(v72);
      while ( __strex(v73 & 0xEF, v72) );
      __dmb(0xBu);
    }
    if ( v17 )
    {
      __dmb(0xBu);
      v19 = (unsigned __int64 *)(a1 + 24);
      do
        v20 = __ldrexd(v19);
      while ( __strexd(v18, v19) );
      __dmb(0xBu);
    }
    else
    {
      *(_QWORD *)(a1 + 24) = v18;
    }
    KiSetPriorityThread(a1, v90, v3);
    v6 = (_DWORD *)v90[0];
  }
  v21 = *(_BYTE **)(a1 + 152);
  if ( v21 && (*v21 & 0x7F) == 21 )
  {
    KiPriQueueThreadPriorityChanged((int)v21, a1);
  }
  else
  {
    __dmb(0xBu);
    *v10 = 0;
  }
  while ( v6 )
  {
    v51 = v6 - 36;
    v6 = (_DWORD *)*v6;
    KiDeferredReadyThread(v8, v51);
  }
  v22 = v92;
  v23 = *(_DWORD *)(v8 + 8);
  if ( v92 < 2 )
  {
    v25 = *(_DWORD *)(v8 + 4);
    v84 = v25;
    if ( v23 )
    {
      KiAbProcessContextSwitch(v25, 0);
      v52 = (unsigned int *)(v8 + 24);
      while ( 1 )
      {
        do
          v53 = __ldrex(v52);
        while ( __strex(1u, v52) );
        __dmb(0xBu);
        if ( !v53 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v52 );
      }
      v54 = *(_DWORD *)(v8 + 8);
      *(_DWORD *)(v8 + 8) = 0;
      __disable_irq();
      v89 = v54;
      *(_BYTE *)(v8 + 16) = 1;
      LODWORD(v55) = ReadTimeStampCounter();
      v56 = *(_DWORD *)(v8 + 2376);
      v57 = *(_DWORD *)(v8 + 2380);
      v59 = HIDWORD(v55);
      v92 = v55;
      v60 = (unsigned __int64 *)(v25 + 48);
      v58 = v55 - __PAIR64__(v57, v56);
      v79 = HIDWORD(v58);
      v82 = v58;
      v61 = *(_QWORD *)(v25 + 48) + v58;
      __dmb(0xBu);
      do
        v62 = __ldrexd(v60);
      while ( __strexd(v61, v60) );
      __dmb(0xBu);
      v63 = v58 + *(unsigned int *)(v25 + 56);
      if ( HIDWORD(v63) )
      {
        v90[1] = 0;
        LODWORD(v63) = -1;
      }
      HIDWORD(v63) = v92;
      *(_DWORD *)(v8 + 2380) = v59;
      *(_DWORD *)(v8 + 2376) = HIDWORD(v63);
      v64 = *(unsigned __int8 *)(v25 + 2);
      *(_DWORD *)(v25 + 56) = v63;
      v90[0] = v64;
      if ( (v64 & 0x3E) != 0 )
      {
        if ( (v64 & 0x10) != 0 )
        {
          v77 = v8 + 8 * *(unsigned __int8 *)(v25 + 84);
          *(_QWORD *)(v77 + 2392) = *(_QWORD *)(v77 + 2392) - *(_QWORD *)(v8 + 2384) + *(_QWORD *)(v8 + 2376);
          v64 &= 0xEFu;
          *(_DWORD *)(v8 + 2384) = 0;
          *(_DWORD *)(v8 + 2388) = 0;
          v90[0] = v64;
        }
        if ( (v64 & 0x3E) != 0 )
        {
          if ( (v64 & 0x20) != 0 )
          {
            v65 = *(_DWORD *)(v25 + 1084);
            if ( v65 )
            {
              v66 = (unsigned __int64 *)(v65 + 8 * (*(unsigned __int8 *)(v8 + 2986) + 2 * PoGetFrequencyBucket(v8)));
              v67 = v79;
              v68 = *v66 + __PAIR64__(v79, v82);
              __dmb(0xBu);
              do
                v69 = __ldrexd(v66);
              while ( __strexd(v68, v66) );
              __dmb(0xBu);
              LODWORD(v58) = v82;
              v25 = v84;
              LOBYTE(v64) = v90[0];
            }
            else
            {
              v67 = HIDWORD(v58);
            }
            LOBYTE(v64) = v64 & 0xDF;
          }
          else
          {
            v67 = HIDWORD(v58);
          }
          if ( (v64 & 0x3E) != 0 )
          {
            v70 = *(_DWORD *)(v25 + 68);
            if ( v70 )
            {
              for ( HIDWORD(v58) = v70 + *(_DWORD *)(v8 + 2352);
                    HIDWORD(v58);
                    HIDWORD(v58) = *(_DWORD *)(HIDWORD(v58) + 236) )
              {
                *(_QWORD *)HIDWORD(v58) += __PAIR64__(v67, v58);
              }
            }
            if ( (*(_BYTE *)(v25 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) & *(_DWORD *)(v25 + 356)) != *(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) )
            {
              *(_QWORD *)(v8 + 2368) += __PAIR64__(v67, v58);
            }
            if ( *(_DWORD *)(v25 + 236) )
              KiEndCounterAccumulation(v25);
          }
        }
      }
      v71 = v89;
      __enable_irq();
      *(_DWORD *)(v8 + 4) = v71;
      *(_BYTE *)(v71 + 132) = 2;
      *(_BYTE *)(v25 + 395) = 32;
      *(_BYTE *)(v25 + 134) = v22;
      KiQueueReadyThread(v8, v25);
      if ( !KiSwapContext(v25, v71, v22) )
        goto LABEL_32;
    }
    else if ( (*(_DWORD *)(v25 + 76) & 0x40) == 0 )
    {
LABEL_32:
      v26 = (void (__fastcall **)(int))&KfLowerIrql;
      v27 = v22;
LABEL_33:
      (*v26)(v27);
      goto LABEL_26;
    }
    KfLowerIrql(1);
    *(_DWORD *)(v25 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_32;
  }
  if ( v23 && !*(_BYTE *)(v8 + 1754) )
  {
    v26 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
    v27 = 2;
    goto LABEL_33;
  }
LABEL_26:
  v24 = v91;
  if ( (dword_682604 & 0x2000) != 0 )
    EtwTracePriority(a1, 1329, v91, v3, &varsC);
  return v24;
}
