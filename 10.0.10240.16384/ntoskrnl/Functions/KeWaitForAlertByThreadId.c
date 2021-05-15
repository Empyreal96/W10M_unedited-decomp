// KeWaitForAlertByThreadId 
 
int __fastcall KeWaitForAlertByThreadId(unsigned __int8 a1, int a2, int a3)
{
  unsigned int v5; // r5
  unsigned __int8 *v6; // r8
  unsigned int v7; // r4
  char v8; // r2
  int v9; // r4
  unsigned int *v10; // r10
  unsigned int v11; // r6
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r7
  unsigned __int8 *v15; // r8
  unsigned int v16; // r1
  unsigned int v17; // r0
  int result; // r0
  unsigned int v19; // r1
  unsigned int v20; // r2
  unsigned int v21; // r4
  int v22; // r3
  unsigned int v23; // r6
  __int64 v24; // r0
  unsigned int v25; // r2
  unsigned int v26; // r3
  unsigned int v27; // r1
  unsigned int v28; // r2
  unsigned __int64 v29; // kr10_8
  unsigned int v30; // r3
  unsigned int v31; // r7
  int v32; // r3
  int v33; // r8
  int v34; // r4
  unsigned int v35; // r0
  unsigned int v36; // r3
  unsigned int *v37; // r1
  unsigned int v38; // r2
  int v39; // r3
  int v40; // lr
  __int64 v41; // r0
  __int64 v42; // kr18_8
  unsigned __int64 *v43; // r6
  unsigned __int64 v44; // kr20_8
  unsigned __int64 v45; // kr28_8
  __int64 v46; // r2
  char v47; // r9
  int v48; // r4
  unsigned __int64 *v49; // r4
  unsigned __int64 v50; // kr38_8
  unsigned __int64 v51; // kr40_8
  int v52; // r1
  int v53; // r4
  unsigned int v54; // r2
  unsigned int v55; // r6
  void (__fastcall **v56)(int); // r3
  int v57; // r0
  __int64 v58; // [sp+8h] [bp-40h]
  int v59; // [sp+10h] [bp-38h]
  unsigned int v60; // [sp+10h] [bp-38h]
  int v62; // [sp+18h] [bp-30h]
  __int64 v63; // [sp+20h] [bp-28h]
  unsigned int v64; // [sp+20h] [bp-28h]

  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  __dmb(0xBu);
  v6 = (unsigned __int8 *)(v5 + 80);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 & 0xF7, v6) );
  __dmb(0xBu);
  if ( (unsigned __int8)(v7 & 8) >> 3 )
    return 257;
  if ( a2 && !*(_QWORD *)a2 )
    return 258;
  v8 = *(_BYTE *)(v5 + 76);
  *(_BYTE *)(v5 + 76) = v8 & 0xFB;
  v59 = (unsigned __int8)(v8 & 4) >> 2;
  if ( !v59 )
    *(_BYTE *)(v5 + 134) = KfRaiseIrql(2);
  if ( a2 )
  {
    if ( *(int *)(a2 + 4) >= 0 )
    {
      v9 = 1;
      LODWORD(v58) = *(_DWORD *)a2;
      v22 = *(_DWORD *)(a2 + 4);
    }
    else
    {
      v19 = MEMORY[0xFFFF93B0];
      HIDWORD(v58) = MEMORY[0xFFFF93B4];
      v20 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v21 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v20 != MEMORY[0xFFFF9010] )
        return sub_51F0CC(-28664, v19);
      v22 = (__PAIR64__(v20, v21) - __PAIR64__(HIDWORD(v58), v19) - *(_QWORD *)(v5 + 160) - *(_QWORD *)a2) >> 32;
      LODWORD(v58) = v21 - v19 - *(_DWORD *)(v5 + 160) - *(_DWORD *)a2;
      v9 = 2;
    }
    HIDWORD(v58) = v22;
  }
  else
  {
    v9 = 0;
    v58 = v63;
  }
  v10 = (unsigned int *)(v5 + 44);
  while ( 1 )
  {
    v11 = *(unsigned __int8 *)(v5 + 134);
    v64 = v11;
    while ( 1 )
    {
      v12 = *(_DWORD *)(v5 + 76);
      *(_BYTE *)(v5 + 72) = 0;
      *(_DWORD *)(v5 + 76) = v12 & 0xFFFFFFEF;
      *(_BYTE *)(v5 + 135) = a1;
      while ( 1 )
      {
        do
          v13 = __ldrex(v10);
        while ( __strex(1u, v10) );
        __dmb(0xBu);
        if ( !v13 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v10 );
      }
      if ( !*(_BYTE *)(v5 + 121) || *(_WORD *)(v5 + 310) || v11 )
        break;
      __dmb(0xBu);
      *v10 = 0;
      KfLowerIrql(1);
      KiDeliverApc(0, 0, 0);
      KfRaiseIrql(2);
      *(_BYTE *)(v5 + 134) = 0;
    }
    v14 = v59;
    v15 = (unsigned __int8 *)(v5 + 80);
    if ( (*(_BYTE *)(v5 + 122) & a1) != 0 )
    {
      __dmb(0xBu);
      *v10 = 0;
      v30 = (unsigned int)KeGetPcr();
      v31 = (v30 & 0xFFFFF000) + 1408;
      v32 = *(_DWORD *)((v30 & 0xFFFFF000) + 0x588);
      if ( v11 >= 2 )
      {
        if ( !v32 || *(_BYTE *)(v31 + 1754) )
          return 192;
        v56 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
        v57 = 2;
LABEL_46:
        (*v56)(v57);
        return 192;
      }
      v33 = *(_DWORD *)(v31 + 4);
      if ( v32 )
      {
        KiAbProcessContextSwitch(*(_DWORD *)(v31 + 4), 0);
        v37 = (unsigned int *)(v31 + 24);
        while ( 1 )
        {
          do
            v38 = __ldrex(v37);
          while ( __strex(1u, v37) );
          __dmb(0xBu);
          if ( !v38 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v37 );
        }
        v39 = *(_DWORD *)(v31 + 8);
        *(_DWORD *)(v31 + 8) = 0;
        __disable_irq();
        v62 = v39;
        *(_BYTE *)(v31 + 16) = 1;
        LODWORD(v41) = ReadTimeStampCounter();
        v40 = v41;
        v43 = (unsigned __int64 *)(v33 + 48);
        v42 = v41 - *(_QWORD *)(v31 + 2376);
        LODWORD(v41) = HIDWORD(v42);
        v44 = v42 + *(_QWORD *)(v33 + 48);
        __dmb(0xBu);
        do
          v45 = __ldrexd(v43);
        while ( __strexd(v44, v43) );
        __dmb(0xBu);
        v46 = v42 + *(unsigned int *)(v33 + 56);
        if ( HIDWORD(v46) )
          LODWORD(v46) = -1;
        *(_DWORD *)(v31 + 2376) = v40;
        *(_DWORD *)(v31 + 2380) = HIDWORD(v41);
        v47 = *(_BYTE *)(v33 + 2);
        *(_DWORD *)(v33 + 56) = v46;
        if ( (v47 & 0x3E) != 0 )
        {
          if ( (v47 & 0x10) != 0 )
          {
            v55 = v31 + 8 * *(unsigned __int8 *)(v33 + 84);
            *(_QWORD *)(v55 + 2392) = *(_QWORD *)(v55 + 2392) - *(_QWORD *)(v31 + 2384) + *(_QWORD *)(v31 + 2376);
            *(_DWORD *)(v31 + 2384) = 0;
            *(_DWORD *)(v31 + 2388) = 0;
            v47 &= 0xEFu;
          }
          if ( (v47 & 0x3E) != 0 )
          {
            if ( (v47 & 0x20) != 0 )
            {
              v48 = *(_DWORD *)(v33 + 1084);
              if ( v48 )
              {
                v49 = (unsigned __int64 *)(v48 + 8 * (*(unsigned __int8 *)(v31 + 2986) + 2 * PoGetFrequencyBucket(v31)));
                v50 = v42 + *v49;
                __dmb(0xBu);
                do
                  v51 = __ldrexd(v49);
                while ( __strexd(v50, v49) );
                __dmb(0xBu);
                LODWORD(v41) = HIDWORD(v42);
              }
              v47 &= 0xDFu;
            }
            if ( (v47 & 0x3E) != 0 )
            {
              v52 = *(_DWORD *)(v33 + 68);
              if ( v52 )
              {
                for ( HIDWORD(v41) = v52 + *(_DWORD *)(v31 + 2352);
                      HIDWORD(v41);
                      HIDWORD(v41) = *(_DWORD *)(HIDWORD(v41) + 236) )
                {
                  *(_QWORD *)HIDWORD(v41) += __PAIR64__(v41, v42);
                }
              }
              if ( (*(_BYTE *)(v33 + 2) & 8) != 0
                && (*(_DWORD *)(*(_DWORD *)(v31 + 2360) + 260) & *(_DWORD *)(v33 + 356)) != *(_DWORD *)(*(_DWORD *)(v31 + 2360) + 260) )
              {
                *(_QWORD *)(v31 + 2368) += __PAIR64__(v41, v42);
              }
              if ( *(_DWORD *)(v33 + 236) )
                KiEndCounterAccumulation(v33);
            }
          }
        }
        v53 = v62;
        v11 = v64;
        __enable_irq();
        *(_DWORD *)(v31 + 4) = v53;
        *(_BYTE *)(v53 + 132) = 2;
        *(_BYTE *)(v33 + 395) = 32;
        *(_BYTE *)(v33 + 134) = v11;
        KiQueueReadyThread(v31, v33);
        if ( !KiSwapContext(v33, v53, v11) )
          goto LABEL_45;
      }
      else if ( (*(_DWORD *)(v33 + 76) & 0x40) == 0 )
      {
LABEL_45:
        v56 = (void (__fastcall **)(int))&KfLowerIrql;
        v57 = v11;
        goto LABEL_46;
      }
      KfLowerIrql(1);
      *(_DWORD *)(v33 + 76) &= 0xFFFFFFBF;
      KiDeliverApc(0, 0, 0);
      goto LABEL_45;
    }
    *(_BYTE *)(v5 + 132) = 5;
    *(_BYTE *)(v5 + 395) = 37;
    __dmb(0xBu);
    *v10 = 0;
    *(_DWORD *)(v5 + 304) = KeTickCount;
    __dmb(0xBu);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 & 0xF7, v15) );
    __dmb(0xBu);
    if ( (unsigned __int8)(v16 & 8) >> 3 )
    {
      v34 = 257;
      goto LABEL_49;
    }
    if ( v9 == 2 )
    {
      v23 = MEMORY[0xFFFF93B0];
      v60 = MEMORY[0xFFFF93B4];
      while ( 1 )
      {
        HIDWORD(v24) = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        LODWORD(v24) = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( HIDWORD(v24) == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v25 = (unsigned __int64)(v24 - *(_QWORD *)(v5 + 160)) >> 32;
      v26 = v24 - *(_DWORD *)(v5 + 160);
      v17 = HIDWORD(v58);
      v29 = __PAIR64__(v25, v26) - __PAIR64__(v60, v23);
      v28 = (__PAIR64__(v25, v26) - __PAIR64__(v60, v23)) >> 32;
      v27 = v29;
    }
    else
    {
      v17 = HIDWORD(v58);
      if ( !v9 )
        goto LABEL_21;
      if ( !v58 )
        break;
      while ( 1 )
      {
        v28 = MEMORY[0xFFFF9018];
        __dmb(0xBu);
        v27 = MEMORY[0xFFFF9014];
        __dmb(0xBu);
        if ( v28 == MEMORY[0xFFFF901C] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    v10 = (unsigned int *)(v5 + 44);
    if ( v28 > v17 || v28 >= v17 && v27 > (unsigned int)v58 )
      break;
LABEL_21:
    *(_DWORD *)(v5 + 232) = a3;
    *(_BYTE *)(v5 + 225) = 5;
    *(_BYTE *)(v5 + 363) = 1;
    result = KiCommitThreadWait(v5, v5 + 216, v9);
    *(_BYTE *)(v5 + 395) = 0;
    if ( result != 256 )
      return result;
    v59 = 0;
    *(_BYTE *)(v5 + 134) = KfRaiseIrql(2);
  }
  v34 = 258;
LABEL_49:
  *(_BYTE *)(v5 + 395) = 0;
  *(_BYTE *)(v5 + 132) = 2;
  v35 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  __dmb(0xFu);
  v36 = *v10;
  __dmb(0xBu);
  if ( v36 )
  {
    while ( 1 )
    {
      do
        v54 = __ldrex(v10);
      while ( __strex(1u, v10) );
      __dmb(0xBu);
      if ( !v54 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v10 );
    }
    __dmb(0xBu);
    *v10 = 0;
  }
  KiExitThreadWait(v35 + 1408, v5, v14);
  return v34;
}
