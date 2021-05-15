// KiSchedulerApc 
 
int __fastcall KiSchedulerApc(int result)
{
  int v1; // r7
  BOOL v2; // r4
  unsigned __int8 *v3; // r3
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r9
  unsigned int *v7; // r5
  unsigned int v8; // r2
  int v9; // r10
  int v10; // r2
  int v11; // r2
  __int64 v12; // r0
  unsigned __int64 *v13; // r6
  __int64 v14; // kr08_8
  unsigned int v15; // lr
  unsigned __int64 v16; // kr18_8
  unsigned __int64 v17; // kr20_8
  __int64 v18; // r2
  char v19; // r5
  int v20; // r4
  unsigned __int64 *v21; // r4
  unsigned __int64 v22; // kr28_8
  unsigned __int64 v23; // kr30_8
  int v24; // r1
  int i; // r1
  char v26; // r2
  int v27; // r2
  int v28; // r1
  char v29; // r3
  int v30; // r5
  unsigned int v31; // r4
  unsigned int *v32; // r6
  unsigned int v33; // r2
  int v34; // r5
  int v35; // r0
  int v36; // r6
  int v37; // r0
  __int16 v38; // r2
  unsigned int v39; // r1
  int v40; // r4
  unsigned int v41; // r3
  bool v42; // cf
  unsigned int v43; // r1
  int v44; // r3
  int v45; // r0
  int v46; // r2
  int v47; // r0
  unsigned int *v48; // r1
  unsigned int v49; // r2
  int v50; // r0
  unsigned int *v51; // r1
  unsigned int v52; // r2
  BOOL v53; // [sp+8h] [bp-88h]
  int v54; // [sp+10h] [bp-80h]
  int v55[28]; // [sp+20h] [bp-70h] BYREF

  v1 = result;
  v2 = (*(_DWORD *)(result + 80) & 0x4000) != 0;
  v53 = v2;
  if ( (*(_DWORD *)(result + 80) & 0x200) != 0 && (*(_DWORD *)(result + 80) & 0x4000) == 0 )
  {
    v54 = KfRaiseIrql(2);
    __dmb(0xBu);
    v3 = (unsigned __int8 *)(v1 + 81);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 & 0xFD, v3) );
    __dmb(0xBu);
    KiAbProcessContextSwitch(v1, 0);
    v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v6 = v5 + 1408;
    v7 = (unsigned int *)(v5 + 1432);
    while ( 1 )
    {
      do
        v8 = __ldrex(v7);
      while ( __strex(1u, v7) );
      __dmb(0xBu);
      if ( !v8 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v7 );
    }
    v9 = *(_DWORD *)(v5 + 1416);
    if ( v9 )
      goto LABEL_19;
    v9 = KiSelectReadyThreadEx(v6, v1, 0);
    if ( v9 )
      goto LABEL_19;
    v10 = *(_DWORD *)(v1 + 68);
    if ( !v10 )
      goto LABEL_14;
    v11 = v10 + *(_DWORD *)(v6 + 2352);
    if ( !v11 )
      goto LABEL_14;
    while ( (*(_BYTE *)(v11 + 92) & 2) == 0 )
    {
      v11 = *(_DWORD *)(v11 + 236);
      if ( !v11 )
        goto LABEL_14;
    }
    v9 = *(_DWORD *)(v6 + 12);
    KiSetProcessorIdle(v6, 1, 1);
    if ( v9 )
    {
LABEL_19:
      *(_DWORD *)(v6 + 8) = 0;
      __disable_irq();
      *(_BYTE *)(v6 + 16) = 1;
      LODWORD(v12) = ReadTimeStampCounter();
      v13 = (unsigned __int64 *)(v1 + 48);
      v14 = v12 - *(_QWORD *)(v6 + 2376);
      v15 = v14;
      v16 = v14 + *(_QWORD *)(v1 + 48);
      __dmb(0xBu);
      do
        v17 = __ldrexd(v13);
      while ( __strexd(v16, v13) );
      __dmb(0xBu);
      v18 = v14 + *(unsigned int *)(v1 + 56);
      if ( HIDWORD(v18) )
        return sub_52CE58();
      *(_QWORD *)(v6 + 2376) = v12;
      v19 = *(_BYTE *)(v1 + 2);
      *(_DWORD *)(v1 + 56) = v18;
      if ( (v19 & 0x3E) != 0 )
      {
        if ( (v19 & 0x10) != 0 )
        {
          v39 = *(_DWORD *)(v6 + 2376);
          v40 = v6 + 8 * *(unsigned __int8 *)(v1 + 84);
          v41 = *(_DWORD *)(v6 + 2384);
          v19 &= 0xEFu;
          v42 = v39 >= v41;
          v43 = v39 - v41;
          v44 = *(_DWORD *)(v40 + 2392);
          v45 = *(_DWORD *)(v6 + 2380) - (*(_DWORD *)(v6 + 2388) + !v42);
          v46 = *(_DWORD *)(v40 + 2396);
          *(_DWORD *)(v40 + 2392) = v44 + v43;
          *(_DWORD *)(v40 + 2396) = v45 + __CFADD__(v44, v43) + v46;
          *(_DWORD *)(v6 + 2384) = 0;
          *(_DWORD *)(v6 + 2388) = 0;
        }
        if ( (v19 & 0x3E) != 0 )
        {
          if ( (v19 & 0x20) != 0 )
          {
            v20 = *(_DWORD *)(v1 + 1084);
            if ( v20 )
            {
              v15 = v14;
              v21 = (unsigned __int64 *)(v20 + 8 * (*(unsigned __int8 *)(v6 + 2986) + 2 * PoGetFrequencyBucket(v6)));
              v22 = *v21 + v14;
              __dmb(0xBu);
              do
                v23 = __ldrexd(v21);
              while ( __strexd(v22, v21) );
              __dmb(0xBu);
            }
            v19 &= 0xDFu;
          }
          if ( (v19 & 0x3E) != 0 )
          {
            v24 = *(_DWORD *)(v1 + 68);
            if ( v24 )
            {
              for ( i = v24 + *(_DWORD *)(v6 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += __PAIR64__(HIDWORD(v14), v15);
            }
            if ( (*(_BYTE *)(v1 + 2) & 8) != 0
              && (*(_DWORD *)(v1 + 356) & *(_DWORD *)(*(_DWORD *)(v6 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v6 + 2360)
                                                                                                  + 260) )
            {
              *(_QWORD *)(v6 + 2368) += __PAIR64__(HIDWORD(v14), v15);
            }
            if ( *(_DWORD *)(v1 + 236) )
              KiEndCounterAccumulation(v1);
          }
        }
      }
      __enable_irq();
      if ( (*(_BYTE *)(v9 + 2) & 4) != 0 )
      {
        if ( *(char *)(v9 + 123) < 16
          && *(_DWORD *)(v9 + 68)
          && (v27 = *(_DWORD *)(v9 + 68)) != 0
          && (v28 = *(_DWORD *)(v6 + 2352) + v27) != 0
          && KiGetThreadEffectiveRankNonZero(v9, v28, 0) )
        {
          v29 = 1;
        }
        else
        {
          v29 = *(_BYTE *)(v9 + 123);
        }
        v26 = v29;
      }
      else
      {
        v26 = *(_BYTE *)(v9 + 123);
      }
      **(_BYTE **)(v6 + 28) = v26;
      *(_DWORD *)(v6 + 4) = v9;
      *(_BYTE *)(v9 + 132) = 2;
      *(_BYTE *)(v1 + 395) = 38;
      *(_BYTE *)(v1 + 134) = 0;
      KiQueueReadyThread(v6, v1);
      if ( KiSwapContext(v1, v9, 0) )
      {
        KfLowerIrql(1);
        *(_DWORD *)(v1 + 76) &= 0xFFFFFFBF;
        KiDeliverApc(0, 0, 0);
      }
      v2 = v53;
    }
    else
    {
LABEL_14:
      __dmb(0xBu);
      *v7 = 0;
    }
    result = KfLowerIrql(v54);
  }
  if ( !*(_DWORD *)(v1 + 456) && !v2 )
  {
    v34 = (*(_DWORD *)(v1 + 76) >> 18) & 1;
    if ( !v34 )
    {
      v35 = *(_DWORD *)(v1 + 96);
      if ( v35 )
      {
        --*(_WORD *)(v1 + 310);
        v37 = KiGetTrapFrameMode(v35);
        v34 = v37;
        v38 = *(_WORD *)(v1 + 310);
        *(_WORD *)(v1 + 310) = v38 + 1;
        if ( v38 == -1 && *(_DWORD *)(v1 + 100) != v1 + 100 )
          KiCheckForKernelApcDelivery(v37);
      }
    }
    v36 = *(unsigned __int8 *)(v1 + 122);
    if ( *(_BYTE *)(v1 + 122) )
    {
      v47 = KfRaiseIrql(2);
      v48 = (unsigned int *)(v1 + 44);
      while ( 1 )
      {
        do
          v49 = __ldrex(v48);
        while ( __strex(1u, v48) );
        __dmb(0xBu);
        if ( !v49 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v48 );
      }
      v36 = *(unsigned __int8 *)(v1 + 122);
      *(_BYTE *)(v1 + 122) = 0;
      __dmb(0xBu);
      *v48 = 0;
      KfLowerIrql(v47);
    }
    *(_DWORD *)(v1 + 76) |= 0x80000u;
    result = KeWaitForSingleObject(v1 + 452, 5, v34);
    *(_DWORD *)(v1 + 76) &= 0xFFF7FFFF;
    if ( v36 )
    {
      v50 = KfRaiseIrql(2);
      v51 = (unsigned int *)(v1 + 44);
      while ( 1 )
      {
        do
          v52 = __ldrex(v51);
        while ( __strex(1u, v51) );
        __dmb(0xBu);
        if ( !v52 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v51 );
      }
      if ( *(_DWORD *)(v1 + 108) != v1 + 108 )
        *(_BYTE *)(v1 + 122) = 1;
      __dmb(0xBu);
      *v51 = 0;
      result = KfLowerIrql(v50);
    }
  }
  *(_DWORD *)(v1 + 76) &= 0xFFFBFFFF;
  if ( v2 )
  {
    if ( KiIsCommitFailTerminationRequested(v1) )
    {
      memset(v55, 0, 80);
      v55[0] = -1073741523;
      v55[1] = 1;
      DbgkForwardException(v55, 0, 1);
    }
    v30 = KfRaiseIrql(2);
    v31 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v32 = (unsigned int *)(v1 + 44);
    while ( 1 )
    {
      do
        v33 = __ldrex(v32);
      while ( __strex(1u, v32) );
      __dmb(0xBu);
      if ( !v33 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v32 );
    }
    if ( (*(_DWORD *)(v1 + 76) & 0x4000) != 0 )
    {
      *(_BYTE *)(v1 + 445) = 1;
      *(_DWORD *)(v1 + 420) = KiSchedulerApcTerminate;
      if ( *(_BYTE *)(v1 + 446) )
        KiRemoveQueueApc(v1 + 400);
      *(_BYTE *)(v1 + 446) = 1;
      KiInsertQueueApc(v1 + 400);
      KiSignalThreadForApc(v31 + 1408, v1 + 400, v30);
    }
    __dmb(0xBu);
    *v32 = 0;
    result = KiExitDispatcher(v31 + 1408, 0, 1, 0, v30);
  }
  return result;
}
