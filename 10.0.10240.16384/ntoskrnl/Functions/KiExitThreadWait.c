// KiExitThreadWait 
 
int __fastcall KiExitThreadWait(int result, int a2, int a3)
{
  unsigned int v3; // r9
  int v4; // r7
  int v5; // r0
  int (__fastcall **v6)(int); // r3
  int v7; // r3
  int v8; // r8
  unsigned int *v9; // r1
  unsigned int v10; // r2
  __int64 v11; // r0
  unsigned int v12; // lr
  __int64 v13; // kr00_8
  unsigned __int64 *v14; // r6
  __int64 v15; // kr08_8
  unsigned __int64 v16; // kr18_8
  __int64 v17; // r2
  char v18; // r5
  int v19; // r6
  unsigned __int64 *v20; // r4
  _DWORD *v21; // r6
  unsigned __int64 v22; // kr20_8
  unsigned __int64 v23; // kr28_8
  int v24; // r1
  int v25; // r5
  __int64 v26; // kr30_8
  int j; // r1
  unsigned int *v28; // r4
  unsigned int v29; // r2
  unsigned int *v30; // r1
  unsigned int v31; // r2
  int v32; // r5
  __int64 v33; // r0
  unsigned int v34; // lr
  __int64 v35; // kr38_8
  unsigned __int64 *v36; // r6
  __int64 v37; // kr40_8
  unsigned __int64 v38; // kr50_8
  __int64 v39; // r2
  char v40; // r9
  int v41; // r6
  int v42; // r5
  unsigned __int64 *v43; // r4
  _DWORD *v44; // r5
  unsigned __int64 v45; // kr60_8
  unsigned __int64 v46; // kr68_8
  int v47; // r1
  int i; // r1
  unsigned int v49; // r1
  int v50; // r4
  unsigned int v51; // r3
  bool v52; // cf
  unsigned int v53; // r1
  int v54; // r3
  int v55; // r0
  int v56; // r2
  _DWORD *v57; // [sp+0h] [bp-38h] BYREF
  unsigned int v58; // [sp+4h] [bp-34h]
  unsigned int v59; // [sp+8h] [bp-30h]
  int v60; // [sp+14h] [bp-24h]

  v3 = *(unsigned __int8 *)(a2 + 134);
  v4 = result;
  if ( (*(_BYTE *)(a2 + 72) & 0x38) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 72) & 0x18) != 0 )
    {
      if ( (*(_BYTE *)(a2 + 72) & 8) != 0 )
        return sub_50DF54();
      v57 = 0;
      v28 = (unsigned int *)(result + 24);
      while ( 1 )
      {
        do
          v29 = __ldrex(v28);
        while ( __strex(1u, v28) );
        __dmb(0xBu);
        if ( !v29 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v28 );
      }
      if ( !*(_DWORD *)(result + 8) )
        KiSelectNextThread(result, &v57);
      __dmb(0xBu);
      *v28 = 0;
      return KiProcessDeferredReadyList(v4, &v57, v3);
    }
    v26 = *(_QWORD *)(result + 4);
    if ( HIDWORD(v26) )
    {
      KiAbProcessContextSwitch(v26, 0);
      v30 = (unsigned int *)(v4 + 24);
      while ( 1 )
      {
        do
          v31 = __ldrex(v30);
        while ( __strex(1u, v30) );
        __dmb(0xBu);
        if ( !v31 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v30 );
      }
      v59 = *(_DWORD *)(v4 + 8);
      *(_DWORD *)(v4 + 8) = 0;
      __disable_irq();
      *(_BYTE *)(v4 + 16) = 1;
      LODWORD(v33) = ReadTimeStampCounter();
      v36 = (unsigned __int64 *)(v26 + 48);
      v35 = v33 - *(_QWORD *)(v4 + 2376);
      v34 = v35;
      v37 = *(_QWORD *)(v26 + 48);
      v57 = (_DWORD *)HIDWORD(v35);
      v58 = v35;
      __dmb(0xBu);
      do
        v38 = __ldrexd(v36);
      while ( __strexd(v37 + v35, v36) );
      __dmb(0xBu);
      v39 = v35 + *(unsigned int *)(v26 + 56);
      if ( HIDWORD(v39) )
      {
        v60 = 0;
        LODWORD(v39) = -1;
      }
      *(_QWORD *)(v4 + 2376) = v33;
      v40 = *(_BYTE *)(v26 + 2);
      *(_DWORD *)(v26 + 56) = v39;
      if ( (v40 & 0x3E) != 0 )
      {
        if ( (v40 & 0x10) != 0 )
        {
          v41 = v4 + 8 * *(unsigned __int8 *)(v26 + 84);
          *(_QWORD *)(v41 + 2392) = *(_QWORD *)(v41 + 2392) - *(_QWORD *)(v4 + 2384) + *(_QWORD *)(v4 + 2376);
          *(_DWORD *)(v4 + 2384) = 0;
          *(_DWORD *)(v4 + 2388) = 0;
          v40 &= 0xEFu;
        }
        if ( (v40 & 0x3E) != 0 )
        {
          if ( (v40 & 0x20) != 0 )
          {
            v42 = *(_DWORD *)(v26 + 1084);
            if ( v42 )
            {
              v34 = v58;
              v43 = (unsigned __int64 *)(v42 + 8 * (*(unsigned __int8 *)(v4 + 2986) + 2 * PoGetFrequencyBucket(v4)));
              v44 = v57;
              v45 = *v43 + __PAIR64__((unsigned int)v57, v58);
              __dmb(0xBu);
              do
                v46 = __ldrexd(v43);
              while ( __strexd(v45, v43) );
              __dmb(0xBu);
            }
            else
            {
              v44 = v57;
            }
            v40 &= 0xDFu;
          }
          else
          {
            v44 = v57;
          }
          if ( (v40 & 0x3E) != 0 )
          {
            v47 = *(_DWORD *)(v26 + 68);
            if ( v47 )
            {
              for ( i = v47 + *(_DWORD *)(v4 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += __PAIR64__((unsigned int)v44, v34);
            }
            if ( (*(_BYTE *)(v26 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v4 + 2360) + 260) & *(_DWORD *)(v26 + 356)) != *(_DWORD *)(*(_DWORD *)(v4 + 2360) + 260) )
            {
              *(_QWORD *)(v4 + 2368) += __PAIR64__((unsigned int)v44, v34);
            }
            if ( *(_DWORD *)(v26 + 236) )
              KiEndCounterAccumulation(v26);
          }
        }
      }
      v32 = v59;
      __enable_irq();
      *(_DWORD *)(v4 + 4) = v32;
      *(_BYTE *)(v32 + 132) = 2;
      *(_BYTE *)(v26 + 134) = 1;
      *(_BYTE *)(v26 + 395) = 32;
      KiQueueReadyThread(v4, v26);
      if ( !KiSwapContext(v26, v32, 1) )
        goto LABEL_43;
    }
    else if ( (*(_DWORD *)(v26 + 76) & 0x40) == 0 )
    {
LABEL_43:
      KfLowerIrql(1);
      KiDeliverApc(0, 0, 0);
      v5 = 0;
      goto LABEL_4;
    }
    KfLowerIrql(1);
    *(_DWORD *)(v26 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_43;
  }
  if ( !a3 )
  {
LABEL_3:
    v5 = v3;
LABEL_4:
    v6 = &KfLowerIrql;
    return (*v6)(v5);
  }
  v7 = *(_DWORD *)(result + 8);
  if ( v3 < 2 )
  {
    v8 = *(_DWORD *)(result + 4);
    if ( v7 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(result + 4), 0);
      v9 = (unsigned int *)(v4 + 24);
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
      v58 = *(_DWORD *)(v4 + 8);
      *(_DWORD *)(v4 + 8) = 0;
      __disable_irq();
      *(_BYTE *)(v4 + 16) = 1;
      LODWORD(v11) = ReadTimeStampCounter();
      v14 = (unsigned __int64 *)(v8 + 48);
      v13 = v11 - *(_QWORD *)(v4 + 2376);
      v12 = v13;
      v15 = *(_QWORD *)(v8 + 48);
      v57 = (_DWORD *)HIDWORD(v13);
      v59 = v13;
      __dmb(0xBu);
      do
        v16 = __ldrexd(v14);
      while ( __strexd(v13 + v15, v14) );
      __dmb(0xBu);
      v17 = v13 + *(unsigned int *)(v8 + 56);
      if ( HIDWORD(v17) )
      {
        v60 = 0;
        LODWORD(v17) = -1;
      }
      *(_QWORD *)(v4 + 2376) = v11;
      v18 = *(_BYTE *)(v8 + 2);
      *(_DWORD *)(v8 + 56) = v17;
      if ( (v18 & 0x3E) != 0 )
      {
        if ( (v18 & 0x10) != 0 )
        {
          v49 = *(_DWORD *)(v4 + 2376);
          v50 = v4 + 8 * *(unsigned __int8 *)(v8 + 84);
          v51 = *(_DWORD *)(v4 + 2384);
          v18 &= 0xEFu;
          v52 = v49 >= v51;
          v53 = v49 - v51;
          v54 = *(_DWORD *)(v50 + 2392);
          v55 = *(_DWORD *)(v4 + 2380) - (*(_DWORD *)(v4 + 2388) + !v52);
          v56 = *(_DWORD *)(v50 + 2396);
          *(_DWORD *)(v50 + 2392) = v54 + v53;
          *(_DWORD *)(v50 + 2396) = v55 + __CFADD__(v54, v53) + v56;
          *(_DWORD *)(v4 + 2384) = 0;
          *(_DWORD *)(v4 + 2388) = 0;
        }
        if ( (v18 & 0x3E) != 0 )
        {
          if ( (v18 & 0x20) != 0 )
          {
            v19 = *(_DWORD *)(v8 + 1084);
            if ( v19 )
            {
              v12 = v59;
              v20 = (unsigned __int64 *)(v19 + 8 * (*(unsigned __int8 *)(v4 + 2986) + 2 * PoGetFrequencyBucket(v4)));
              v21 = v57;
              v22 = __PAIR64__((unsigned int)v57, v59) + *v20;
              __dmb(0xBu);
              do
                v23 = __ldrexd(v20);
              while ( __strexd(v22, v20) );
              __dmb(0xBu);
            }
            else
            {
              v21 = v57;
            }
            v18 &= 0xDFu;
          }
          else
          {
            v21 = v57;
          }
          if ( (v18 & 0x3E) != 0 )
          {
            v24 = *(_DWORD *)(v8 + 68);
            if ( v24 )
            {
              for ( j = v24 + *(_DWORD *)(v4 + 2352); j; j = *(_DWORD *)(j + 236) )
                *(_QWORD *)j += __PAIR64__((unsigned int)v21, v12);
            }
            if ( (*(_BYTE *)(v8 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v4 + 2360) + 260) & *(_DWORD *)(v8 + 356)) != *(_DWORD *)(*(_DWORD *)(v4 + 2360)
                                                                                                  + 260) )
            {
              *(_QWORD *)(v4 + 2368) += __PAIR64__((unsigned int)v21, v12);
            }
            if ( *(_DWORD *)(v8 + 236) )
              KiEndCounterAccumulation(v8);
          }
        }
      }
      v25 = v58;
      __enable_irq();
      *(_DWORD *)(v4 + 4) = v25;
      *(_BYTE *)(v25 + 132) = 2;
      *(_BYTE *)(v8 + 395) = 32;
      *(_BYTE *)(v8 + 134) = v3;
      KiQueueReadyThread(v4, v8);
      if ( !KiSwapContext(v8, v25, v3) )
        goto LABEL_3;
    }
    else if ( (*(_DWORD *)(v8 + 76) & 0x40) == 0 )
    {
      goto LABEL_3;
    }
    KfLowerIrql(1);
    *(_DWORD *)(v8 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_3;
  }
  if ( v7 && !*(_BYTE *)(result + 1754) )
  {
    v6 = &HalRequestSoftwareInterrupt;
    v5 = 2;
    return (*v6)(v5);
  }
  return result;
}
