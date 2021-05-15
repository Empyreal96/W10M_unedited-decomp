// KiSwapThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiSwapThread(int a1, int a2)
{
  int v2; // r7
  __int64 v4; // r0
  unsigned __int64 *v5; // r6
  __int64 v6; // kr10_8
  unsigned __int64 v7; // kr18_8
  unsigned __int64 v8; // kr20_8
  __int64 v9; // r2
  char v11; // lr
  int v12; // r0
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r2
  unsigned __int64 *v17; // r4
  unsigned __int64 v18; // kr30_8
  unsigned __int64 v19; // kr38_8
  __int64 v20; // kr40_8
  unsigned int *v21; // r10
  unsigned int v22; // r2
  int v23; // r6
  int v24; // r0
  int v25; // r9
  int v26; // r10
  int v27; // r4
  int v28; // r5
  char v29; // r2
  int v30; // r1
  int i; // r1
  unsigned __int8 *v32; // r6
  int v33; // r9
  unsigned int v34; // r2
  unsigned int v35; // lr
  unsigned int *v36; // r1
  unsigned int v37; // r2
  _DWORD *v38; // r1 OVERLAPPED
  _DWORD *v39; // r2 OVERLAPPED
  int v40; // r1
  int v41; // r1
  int v42; // r2
  int v43; // r0
  unsigned __int8 *v44; // r3
  unsigned int v45; // r2
  unsigned int v46; // r0
  unsigned int v47; // r2
  char v48; // r2
  unsigned int v49; // r1
  char v50; // r2
  unsigned int v51; // r1
  unsigned int j; // r2
  int v53; // r1
  int v54; // r3
  BOOL v55; // r3
  __int64 v56; // r0
  __int64 v57; // kr48_8
  unsigned __int64 *v58; // r3
  unsigned __int64 v59; // kr50_8
  __int64 v60; // kr58_8
  unsigned __int64 *v61; // r4
  unsigned __int64 v62; // kr60_8
  unsigned __int64 v63; // kr68_8
  int v64; // r6
  int v65; // r2
  int v66; // r1
  int v67; // r2
  int v68; // r1
  unsigned __int8 *v69; // r3
  unsigned int v70; // r2
  unsigned int *v71; // r2
  unsigned int v72; // r1
  unsigned int v73; // r0
  unsigned int v74; // r2
  unsigned int v75; // r1
  _DWORD *v76; // r3
  unsigned int v77; // r2
  unsigned int v78; // r1
  unsigned int v79; // r3
  int v80; // r4
  int v81; // r3
  int v82; // r0
  int v83; // r5
  int v84; // r3
  int v85; // r3
  __int64 v86; // r0
  __int64 v87; // kr70_8
  unsigned int *v88; // [sp+8h] [bp-48h]
  int v89; // [sp+8h] [bp-48h]
  int v90; // [sp+8h] [bp-48h]
  char *v91; // [sp+Ch] [bp-44h]
  __int64 v92; // [sp+Ch] [bp-44h]
  int v93; // [sp+Ch] [bp-44h]
  int v95; // [sp+18h] [bp-38h] BYREF
  int v96[12]; // [sp+20h] [bp-30h] BYREF

  v2 = a1;
  if ( *(_DWORD *)(a2 + 1540) )
    KiProcessThreadWaitList(a2, 1, 0);
  KiAbProcessContextSwitch(v2, 0);
  __disable_irq();
  *(_BYTE *)(a2 + 16) = 1;
  LODWORD(v4) = ReadTimeStampCounter();
  v5 = (unsigned __int64 *)(v2 + 48);
  v6 = v4 - *(_QWORD *)(a2 + 2376);
  v7 = *(_QWORD *)(v2 + 48) + v6;
  __dmb(0xBu);
  do
    v8 = __ldrexd(v5);
  while ( __strexd(v7, v5) );
  __dmb(0xBu);
  v9 = v6 + *(unsigned int *)(v2 + 56);
  if ( HIDWORD(v9) )
    return sub_52F580();
  *(_QWORD *)(a2 + 2376) = v4;
  v11 = *(_BYTE *)(v2 + 2);
  *(_DWORD *)(v2 + 56) = v9;
  if ( (v11 & 0x3E) != 0 )
  {
    if ( (v11 & 0x10) != 0 )
    {
      v64 = a2 + 8 * *(unsigned __int8 *)(v2 + 84);
      *(_QWORD *)(v64 + 2392) = *(_QWORD *)(v64 + 2392) - *(_QWORD *)(a2 + 2384) + *(_QWORD *)(a2 + 2376);
      *(_DWORD *)(a2 + 2384) = 0;
      *(_DWORD *)(a2 + 2388) = 0;
      v11 &= 0xEFu;
    }
    if ( (v11 & 0x3E) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
      {
        v12 = *(_DWORD *)(v2 + 1084);
        if ( v12 )
        {
          v13 = *(_DWORD *)(a2 + 3200);
          v14 = *(_DWORD *)(a2 + 3204);
          if ( v13 && v14 )
          {
            v15 = *(_DWORD *)(v14 + 44);
            if ( v15 >= *(_DWORD *)(v13 + 148) )
              v15 = *(_DWORD *)(v13 + 148);
          }
          else
          {
            v15 = 100;
          }
          v16 = v15 / 0x19;
          if ( v15 / 0x19 >= 3 )
            v16 = 3;
          v17 = (unsigned __int64 *)(v12 + 8 * (*(unsigned __int8 *)(a2 + 2986) + 2 * v16));
          v18 = *v17 + v6;
          __dmb(0xBu);
          do
            v19 = __ldrexd(v17);
          while ( __strexd(v18, v17) );
          __dmb(0xBu);
        }
        v11 &= 0xDFu;
      }
      if ( (v11 & 0x3E) != 0 )
      {
        v30 = *(_DWORD *)(v2 + 68);
        if ( v30 )
        {
          for ( i = v30 + *(_DWORD *)(a2 + 2352); i; i = *(_DWORD *)(i + 236) )
            *(_QWORD *)i += v6;
        }
        if ( (*(_BYTE *)(v2 + 2) & 8) != 0
          && (*(_DWORD *)(*(_DWORD *)(a2 + 2360) + 260) & *(_DWORD *)(v2 + 356)) != *(_DWORD *)(*(_DWORD *)(a2 + 2360)
                                                                                              + 260) )
        {
          *(_QWORD *)(a2 + 2368) += v6;
        }
        if ( *(_DWORD *)(v2 + 236) )
          KiEndCounterAccumulation(v2);
      }
    }
  }
  __enable_irq();
  v20 = *(_QWORD *)(v2 + 56);
  *(_DWORD *)(v2 + 56) = 0;
  v21 = (unsigned int *)(a2 + 24);
  *(_DWORD *)(v2 + 60) = ((unsigned int)v20 >> 1) + (HIDWORD(v20) >> 1);
  while ( 1 )
  {
    do
      v22 = __ldrex(v21);
    while ( __strex(1u, v21) );
    __dmb(0xBu);
    if ( !v22 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v21 );
  }
  v23 = *(_DWORD *)(v2 + 68);
  v24 = v23;
  if ( v23 )
    v23 += *(_DWORD *)(a2 + 2352);
  if ( v23 )
  {
    while ( 1 )
    {
      if ( (*(_BYTE *)(v23 + 92) & 4) != 0 )
      {
        if ( (*(_BYTE *)(v23 + 92) & 0x10) != 0
          || (*(_BYTE *)(v23 + 92) & 2) != 0
          || *(_QWORD *)v23 <= *(_QWORD *)(v23 + 16) )
        {
          if ( *(_QWORD *)v23 > *(_QWORD *)(v23 + 24) )
            KiRecomputeGroupSchedulingRank(v24, (unsigned int *)v23, a2);
        }
        else
        {
          *(_BYTE *)(v23 + 92) |= 2u;
          if ( *(__int64 *)(v24 + 32) > 0 )
            v24 = KiChargeSchedulingGroupCycleTime();
          if ( (*(_BYTE *)(v23 + 92) & 1) != 0 )
          {
            v83 = v23;
            v90 = v23;
            do
            {
              v84 = *(_DWORD *)(v83 + 236);
              if ( v84 )
                v85 = v84 + 228;
              else
                v85 = a2 + 1976;
              v93 = v85;
              v86 = KeQueryInterruptTime(v24);
              v87 = *(_QWORD *)(v83 + 56) - *(_QWORD *)(v90 + 64);
              *(_DWORD *)(v90 + 56) = v87 + v86;
              *(_BYTE *)(v90 + 92) &= 0xFEu;
              *(_DWORD *)(v90 + 60) = (unsigned __int64)(v87 + v86) >> 32;
              v24 = RtlRbRemoveNode(v93, v90 + 80);
              v83 = *(_DWORD *)(v90 + 236);
              v90 = v83;
            }
            while ( v83 && (*(_BYTE *)(v83 + 92) & 1) != 0 && !*(_DWORD *)(v83 + 228) && !*(_WORD *)(v83 + 94) );
          }
        }
      }
      else
      {
        if ( *(_QWORD *)v23 >= *(_QWORD *)(v23 + 8) )
        {
          KiComputeGroupSchedulingRank(v24, a2, v23);
          goto LABEL_49;
        }
        if ( (*(_BYTE *)(v23 + 92) & 1) != 0 )
        {
          v51 = v23 + 80;
          j = *(_DWORD *)(v23 + 84);
          if ( j )
          {
            v76 = *(_DWORD **)j;
            if ( *(_DWORD *)j )
            {
              do
              {
                j = (unsigned int)v76;
                v76 = (_DWORD *)*v76;
              }
              while ( v76 );
            }
          }
          else
          {
            for ( j = *(_DWORD *)(v23 + 88) & 0xFFFFFFFC; j; j = *(_DWORD *)(j + 8) & 0xFFFFFFFC )
            {
              if ( *(_DWORD *)j == v51 )
                break;
              v51 = j;
            }
          }
          if ( j )
          {
            v53 = *(_DWORD *)(v23 + 96);
            v54 = v53 - *(_DWORD *)(j + 16);
            if ( v54 )
            {
LABEL_101:
              if ( v54 <= 0 )
                goto LABEL_49;
            }
            else
            {
              if ( *(_WORD *)(v23 + 94) )
              {
                v77 = *(unsigned __int16 *)(j + 14);
                v78 = 31 - __clz(*(unsigned __int16 *)(v23 + 94));
                v79 = 0;
                if ( v77 )
                  v79 = 31 - __clz(v77);
                v54 = v79 - v78;
                goto LABEL_101;
              }
              if ( !v53 && *(_QWORD *)v23 <= *(_QWORD *)(j - 80) )
                goto LABEL_49;
            }
            v80 = v23;
            do
            {
              v81 = *(_DWORD *)(v80 + 236);
              if ( v81 )
                v82 = v81 + 228;
              else
                v82 = a2 + 1976;
              *(_BYTE *)(v80 + 92) &= 0xFEu;
              RtlRbRemoveNode(v82, v80 + 80);
              v80 = *(_DWORD *)(v80 + 236);
            }
            while ( v80 && (*(_BYTE *)(v80 + 92) & 1) != 0 && !*(_DWORD *)(v80 + 228) && !*(_WORD *)(v80 + 94) );
            KiInsertSchedulingGroupQueue(a2, v23, 0);
            goto LABEL_49;
          }
        }
      }
LABEL_49:
      v23 = *(_DWORD *)(v23 + 236);
      if ( !v23 )
      {
        v2 = a1;
        v21 = (unsigned int *)(a2 + 24);
        break;
      }
      v24 = v23 - *(_DWORD *)(a2 + 2352);
    }
  }
  v25 = KiSearchForNewThread(a2, 0);
  if ( !v25 )
  {
    while ( 1 )
    {
      do
        v47 = __ldrex(v21);
      while ( __strex(1u, v21) );
      __dmb(0xBu);
      if ( !v47 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v21 );
    }
    v25 = *(_DWORD *)(a2 + 8);
    if ( v25 )
      *(_DWORD *)(a2 + 8) = 0;
    else
      v25 = *(_DWORD *)(a2 + 12);
    if ( (*(_BYTE *)(v25 + 2) & 4) != 0 )
    {
      if ( *(char *)(v25 + 123) < 16
        && *(_DWORD *)(v25 + 68)
        && (v65 = *(_DWORD *)(v25 + 68)) != 0
        && (v66 = *(_DWORD *)(a2 + 2352) + v65) != 0
        && KiGetThreadEffectiveRankNonZero(v25, v66, 0) )
      {
        v48 = 1;
      }
      else
      {
        v48 = *(_BYTE *)(v25 + 123);
      }
    }
    else
    {
      v48 = *(_BYTE *)(v25 + 123);
    }
    **(_BYTE **)(a2 + 28) = v48;
    *(_DWORD *)(a2 + 4) = v25;
    *(_BYTE *)(v25 + 132) = 2;
  }
  if ( v25 != *(_DWORD *)(a2 + 12) && v25 != v2 && *(_BYTE *)(v25 + 73) )
  {
    if ( (*(_BYTE *)(v25 + 2) & 4) != 0 )
    {
      if ( *(char *)(v25 + 123) < 16
        && *(_DWORD *)(v25 + 68)
        && (v67 = *(_DWORD *)(v25 + 68)) != 0
        && (v68 = *(_DWORD *)(a2 + 2352) + v67) != 0
        && KiGetThreadEffectiveRankNonZero(v25, v68, 0) )
      {
        v50 = 1;
      }
      else
      {
        v50 = *(_BYTE *)(v25 + 123);
      }
    }
    else
    {
      v50 = *(_BYTE *)(v25 + 123);
    }
    **(_BYTE **)(a2 + 28) = v50;
    *(_DWORD *)(a2 + 8) = v25;
    *(_BYTE *)(v25 + 132) = 3;
    v25 = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(a2 + 4) = v25;
    *(_BYTE *)(v25 + 132) = 2;
  }
  __dmb(0xBu);
  *v21 = 0;
  v26 = *(unsigned __int8 *)(v2 + 134);
  if ( v2 == v25 )
  {
    v55 = *(_BYTE *)(v25 + 121) && !*(_BYTE *)(v2 + 134) && !*(_WORD *)(v25 + 310);
    v89 = v55;
    __disable_irq();
    LODWORD(v56) = ReadTimeStampCounter();
    v92 = v56;
    v57 = v56 - *(_QWORD *)(a2 + 2376);
    __dmb(0xBu);
    v58 = (unsigned __int64 *)(a2 + 2744);
    do
      v59 = __ldrexd(v58);
    while ( __strexd(v59 + v57, v58) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(v25 + 2) & 0x20) != 0 )
    {
      v60 = v56 - *(_QWORD *)(a2 + 2376);
      v61 = (unsigned __int64 *)(a2 + 8 * (*(unsigned __int8 *)(a2 + 2986) + 2 * (PoGetFrequencyBucket(a2) + 1144)));
      v62 = *v61 + v60;
      __dmb(0xBu);
      do
        v63 = __ldrexd(v61);
      while ( __strexd(v62, v61) );
      __dmb(0xBu);
      v56 = v92;
    }
    *(_QWORD *)(a2 + 2376) = v56;
    if ( (*(_BYTE *)(v25 + 2) & 0x10) != 0 )
      *(_QWORD *)(a2 + 2384) = v56;
    if ( (*(_BYTE *)(v25 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(v25, 0);
    *(_BYTE *)(a2 + 16) = 0;
    __enable_irq();
    if ( (*(_DWORD *)(v25 + 80) & 0x400) != 0 )
    {
      __dmb(0xBu);
      v69 = (unsigned __int8 *)(v25 + 81);
      do
        v70 = __ldrex(v69);
      while ( __strex(v70 & 0xFB, v69) );
      __dmb(0xBu);
      KiInsertDeferredPreemptionApc(a2, v25, 0);
    }
    if ( (dword_682604 & 4) != 0 )
      EtwTraceContextSwap((int (*)())v2, v2);
    v27 = v89;
  }
  else
  {
    v27 = KiSwapContext(v2, v25, *(unsigned __int8 *)(v2 + 134));
  }
  v28 = *(_DWORD *)(v2 + 136);
  v29 = *(_BYTE *)(v2 + 77);
  *(_BYTE *)(v2 + 77) = v29 & 0xFD;
  if ( !((unsigned __int8)(v29 & 2) >> 1) )
    goto LABEL_37;
  v32 = (unsigned __int8 *)(v2 + 168);
  v33 = 0;
  while ( 1 )
  {
    do
      v34 = __ldrex(v32);
    while ( __strex(v34 | 0x80, v32) );
    __dmb(0xBu);
    if ( v34 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v32 & 0x80) != 0 );
        do
          v74 = __ldrex(v32);
        while ( __strex(v74 | 0x80, v32) );
        __dmb(0xBu);
      }
      while ( v74 >> 7 );
    }
    if ( (*(_BYTE *)(v2 + 171) & 0xC0) == 0 )
      break;
    v35 = *(unsigned __int8 *)(v2 + 170);
    v36 = (unsigned int *)((char *)*(&KiProcessorBlock + *(_DWORD *)(v2 + 204)) + 24 * v35 + 4352);
    v88 = v36;
    v91 = (char *)*(&KiProcessorBlock + *(_DWORD *)(v2 + 204)) + 4096;
    while ( 1 )
    {
      do
        v37 = __ldrex(v36);
      while ( __strex(1u, v36) );
      __dmb(0xBu);
      if ( !v37 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v36 );
    }
    if ( (*(_BYTE *)(v2 + 171) & 0x80) == 0 )
    {
      *(_QWORD *)&v38 = *(_QWORD *)(v2 + 192);
      if ( v38[1] != v2 + 192 || *v39 != v2 + 192 )
        __fastfail(3u);
      *v39 = v38;
      v38[1] = v39;
      if ( v39 == v38 )
      {
        *(_DWORD *)&v91[24 * v35 + 276] = -1;
        v40 = KiPendingTimerBitmaps[2 * (unsigned __int8)*(v91 - 3044) + 1];
        if ( KiSerializeTimerExpiration )
        {
          v41 = v40 + 4 * (v35 >> 5);
          v42 = v35 & 0x1F;
        }
        else
        {
          v42 = (unsigned __int8)*(v91 - 3043);
          v41 = v40 + (v35 << 7);
        }
        __dmb(0xBu);
        v43 = 1 << (v42 & 7);
        v44 = (unsigned __int8 *)(v41 + (v42 >> 3));
        do
          v45 = __ldrex(v44);
        while ( __strex(v45 & ~(_BYTE)v43, v44) );
        __dmb(0xBu);
      }
      __dmb(0xBu);
      *v88 = 0;
      __dmb(0xBu);
      do
        v46 = __ldrex((unsigned int *)v32);
      while ( __strex(v46 & 0xBFFFFF7F, (unsigned int *)v32) );
      goto LABEL_69;
    }
    __dmb(0xBu);
    *v36 = 0;
    __dmb(0xBu);
    v71 = (unsigned int *)&v91[4 * (*(_BYTE *)(v2 + 171) & 0x3F)];
    do
      v72 = __ldrex(v71);
    while ( __strex(0, v71) );
    __dmb(0xBu);
    __dmb(0xBu);
    if ( v72 )
    {
      do
        v73 = __ldrex((unsigned int *)v32);
      while ( __strex(v73 & 0xFFFF7F, (unsigned int *)v32) );
LABEL_69:
      __dmb(0xBu);
      v33 = 1;
      goto LABEL_70;
    }
    do
      v75 = __ldrex((unsigned int *)v32);
    while ( __strex(v75 & 0xFFFFFF7F, (unsigned int *)v32) );
    while ( (*(_BYTE *)(v2 + 171) & 0x80) != 0 )
    {
      __dmb(0xAu);
      __yield();
    }
  }
  __dmb(0xBu);
  do
    v49 = __ldrex((unsigned int *)v32);
  while ( __strex(v49 & 0xFFFFFF7F, (unsigned int *)v32) );
LABEL_70:
  if ( (dword_682608 & 0x20000) != 0 )
  {
    if ( !v33 )
      goto LABEL_72;
    v96[0] = (int)&v95;
    v96[1] = 0;
    v96[2] = 4;
    v96[3] = 0;
    v95 = v2 + 168;
    EtwTraceKernelEvent(v96, 1, 1073872896, 3925, 1538);
  }
  if ( !v33 )
  {
LABEL_72:
    *(_BYTE *)(v2 + 297) = 4;
    *(_DWORD *)(v2 + 176) = v2 + 288;
    *(_DWORD *)(v2 + 180) = v2 + 288;
  }
LABEL_37:
  if ( v27 )
  {
    KfLowerIrql(1);
    KiDeliverApc(0, 0, 0);
  }
  KfLowerIrql(v26);
  return v28;
}
