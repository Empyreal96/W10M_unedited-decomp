// KeDelayExecutionThread 
 
int __fastcall KeDelayExecutionThread(char a1, int a2, unsigned int *a3)
{
  unsigned int *v3; // r6
  unsigned int v5; // r5
  int v6; // r4
  char v7; // r2
  int v8; // r8
  unsigned int v9; // r1
  __int64 v10; // kr08_8
  unsigned int v11; // r7
  int v12; // r3
  unsigned int *v13; // r0
  unsigned int v14; // r3
  unsigned int v15; // r2
  int result; // r0
  unsigned int *v17; // r6
  int v18; // r0
  __int64 v19; // kr10_8
  __int64 v20; // r0
  unsigned int v21; // lr
  unsigned int v22; // r1
  unsigned int v23; // r2
  unsigned int v24; // r0
  unsigned int *v25; // r1
  int v26; // r3
  unsigned int v27; // r3
  unsigned int v28; // r8
  int v29; // r3
  int v30; // r7
  unsigned int *v31; // r1
  unsigned int v32; // r2
  int v33; // r3
  int v34; // r9
  __int64 v35; // r0
  unsigned int v36; // lr
  unsigned __int64 *v37; // r6
  unsigned __int64 v38; // kr30_8
  unsigned __int64 v39; // kr38_8
  unsigned __int64 v40; // r2
  char v41; // r9
  int v42; // r4
  unsigned __int64 *v43; // r4
  unsigned __int64 v44; // kr48_8
  unsigned __int64 v45; // kr50_8
  int v46; // r1
  int v47; // r4
  int v48; // r5
  void (__fastcall **v49)(int); // r3
  int v50; // r0
  int v51; // r10
  unsigned int v52; // r2
  unsigned int v53; // r6
  int v54; // [sp+8h] [bp-48h]
  unsigned int v55; // [sp+10h] [bp-40h]
  unsigned int v56; // [sp+18h] [bp-38h]
  int v57; // [sp+18h] [bp-38h]
  int v58; // [sp+1Ch] [bp-34h]
  unsigned int v60; // [sp+20h] [bp-30h]
  int v61[10]; // [sp+28h] [bp-28h] BYREF

  v3 = a3;
  v54 = a1;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = a1;
  if ( !*(_QWORD *)a3 && !a2 && a1 && !*(_BYTE *)(v5 + 122) )
    return NtYieldExecution();
  v7 = *(_BYTE *)(v5 + 76);
  *(_BYTE *)(v5 + 76) = v7 & 0xFB;
  v8 = (unsigned __int8)(v7 & 4) >> 2;
  if ( !v8 )
    *(_BYTE *)(v5 + 134) = KfRaiseIrql(2);
  if ( (v3[1] & 0x80000000) == 0 )
  {
    v9 = v3[1];
    v55 = *v3;
    v58 = 1;
  }
  else
  {
    v10 = RtlGetInterruptTimePrecise(v61) - MEMORY[0xFFFF93B0] - *(_QWORD *)(v5 + 160) - *(_QWORD *)v3;
    v9 = HIDWORD(v10);
    v58 = 2;
    v55 = v10;
  }
  v56 = v9;
  while ( 1 )
  {
    v11 = *(unsigned __int8 *)(v5 + 134);
    v61[0] = v11;
    v12 = *(_DWORD *)(v5 + 76);
    v13 = (unsigned int *)(v5 + 44);
    *(_BYTE *)(v5 + 72) = 0;
    v14 = v12 & 0xFFFFFFEF;
    *(_DWORD *)(v5 + 76) = v14;
    *(_BYTE *)(v5 + 135) = v6;
    if ( a2 )
      *(_DWORD *)(v5 + 76) = v14 | 0x10;
    while ( 1 )
    {
      do
        v15 = __ldrex(v13);
      while ( __strex(1u, v13) );
      __dmb(0xBu);
      if ( !v15 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v13 );
    }
    if ( *(_BYTE *)(v5 + 121) )
      return sub_50BA48();
    v17 = a3;
    if ( !a2 )
    {
      if ( (*(_BYTE *)(v5 + 122) & (unsigned __int8)v6) != 0 )
        goto LABEL_41;
      goto LABEL_15;
    }
    if ( *(_BYTE *)(v6 + v5 + 74) )
    {
      *(_BYTE *)(v6 + v5 + 74) = 0;
      v51 = 257;
      goto LABEL_42;
    }
    if ( v6 && *(_DWORD *)(v5 + 108) != v5 + 108 )
      break;
    if ( *(_BYTE *)(v5 + 74) )
    {
      *(_BYTE *)(v5 + 74) = 0;
      v51 = 257;
      goto LABEL_42;
    }
LABEL_15:
    *(_BYTE *)(v5 + 132) = 5;
    *(_BYTE *)(v5 + 395) = 4;
    __dmb(0xBu);
    *v13 = 0;
    v18 = v58;
    *(_DWORD *)(v5 + 304) = KeTickCount;
    if ( v58 == 2 )
    {
      v19 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        HIDWORD(v20) = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        LODWORD(v20) = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( HIDWORD(v20) == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v21 = v55;
      v23 = (unsigned __int64)(v20 - *(_QWORD *)(v5 + 160) - v19) >> 32;
      v22 = v20 - *(_DWORD *)(v5 + 160) - v19;
      v18 = 2;
    }
    else
    {
      v21 = v55;
      if ( !(v56 | v55) )
        goto LABEL_36;
      while ( 1 )
      {
        v23 = MEMORY[0xFFFF9018];
        __dmb(0xBu);
        v22 = MEMORY[0xFFFF9014];
        __dmb(0xBu);
        if ( v23 == MEMORY[0xFFFF901C] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    v6 = v54;
    v17 = a3;
    if ( v23 > v56 || v23 >= v56 && v22 > v21 )
    {
LABEL_36:
      *(_BYTE *)(v5 + 132) = 2;
      v24 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      __dmb(0xFu);
      v25 = (unsigned int *)(v5 + 44);
      v26 = *(_DWORD *)(v5 + 44);
      __dmb(0xBu);
      if ( v26 )
      {
        while ( 1 )
        {
          do
            v52 = __ldrex(v25);
          while ( __strex(1u, v25) );
          __dmb(0xBu);
          if ( !v52 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v25 );
        }
        __dmb(0xBu);
        *v25 = 0;
      }
      KiExitThreadWait(v24 + 1408, v5, v8);
      if ( !*(_QWORD *)v17 )
        return NtYieldExecution();
      return 0;
    }
    *(_DWORD *)(v5 + 232) = -1;
    *(_BYTE *)(v5 + 225) = 5;
    *(_BYTE *)(v5 + 363) = 1;
    result = KiCommitThreadWait(v5, v5 + 216, v18);
    if ( result != 256 )
    {
      if ( result != 258 )
        return result;
      return 0;
    }
    v8 = 0;
    *(_BYTE *)(v5 + 134) = KfRaiseIrql(2);
  }
  *(_BYTE *)(v5 + 122) = 1;
LABEL_41:
  v51 = 192;
LABEL_42:
  __dmb(0xBu);
  *v13 = 0;
  v27 = (unsigned int)KeGetPcr();
  v28 = (v27 & 0xFFFFF000) + 1408;
  v29 = *(_DWORD *)((v27 & 0xFFFFF000) + 0x588);
  if ( v11 >= 2 )
  {
    if ( v29 && !*(_BYTE *)(v28 + 1754) )
    {
      v49 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
      v50 = 2;
      goto LABEL_76;
    }
  }
  else
  {
    v30 = *(_DWORD *)(v28 + 4);
    if ( v29 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(v28 + 4), 0);
      v31 = (unsigned int *)(v28 + 24);
      while ( 1 )
      {
        do
          v32 = __ldrex(v31);
        while ( __strex(1u, v31) );
        __dmb(0xBu);
        if ( !v32 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v31 );
      }
      v33 = *(_DWORD *)(v28 + 8);
      *(_DWORD *)(v28 + 8) = 0;
      __disable_irq();
      v57 = v33;
      *(_BYTE *)(v28 + 16) = 1;
      LODWORD(v35) = ReadTimeStampCounter();
      v34 = v35;
      v37 = (unsigned __int64 *)(v30 + 48);
      v36 = (unsigned __int64)(v35 - *(_QWORD *)(v28 + 2376)) >> 32;
      LODWORD(v35) = v35 - *(_DWORD *)(v28 + 2376);
      v60 = v35;
      v38 = __PAIR64__(v36, v35) + *(_QWORD *)(v30 + 48);
      __dmb(0xBu);
      do
        v39 = __ldrexd(v37);
      while ( __strexd(v38, v37) );
      __dmb(0xBu);
      v40 = __PAIR64__(v36, *(_DWORD *)(v30 + 56)) + (unsigned int)v35;
      if ( HIDWORD(v40) )
        LODWORD(v40) = -1;
      *(_DWORD *)(v28 + 2376) = v34;
      *(_DWORD *)(v28 + 2380) = HIDWORD(v35);
      v41 = *(_BYTE *)(v30 + 2);
      *(_DWORD *)(v30 + 56) = v40;
      if ( (v41 & 0x3E) != 0 )
      {
        if ( (v41 & 0x10) != 0 )
        {
          v53 = v28 + 8 * *(unsigned __int8 *)(v30 + 84);
          *(_QWORD *)(v53 + 2392) = *(_QWORD *)(v53 + 2392) - *(_QWORD *)(v28 + 2384) + *(_QWORD *)(v28 + 2376);
          *(_DWORD *)(v28 + 2384) = 0;
          *(_DWORD *)(v28 + 2388) = 0;
          v41 &= 0xEFu;
        }
        if ( (v41 & 0x3E) != 0 )
        {
          if ( (v41 & 0x20) != 0 )
          {
            v42 = *(_DWORD *)(v30 + 1084);
            if ( v42 )
            {
              v43 = (unsigned __int64 *)(v42 + 8 * (*(unsigned __int8 *)(v28 + 2986) + 2 * PoGetFrequencyBucket(v28)));
              v44 = __PAIR64__(v36, v60) + *v43;
              __dmb(0xBu);
              do
                v45 = __ldrexd(v43);
              while ( __strexd(v44, v43) );
              __dmb(0xBu);
              LODWORD(v35) = v60;
            }
            v41 &= 0xDFu;
          }
          if ( (v41 & 0x3E) != 0 )
          {
            v46 = *(_DWORD *)(v30 + 68);
            if ( v46 )
            {
              for ( HIDWORD(v35) = v46 + *(_DWORD *)(v28 + 2352);
                    HIDWORD(v35);
                    HIDWORD(v35) = *(_DWORD *)(HIDWORD(v35) + 236) )
              {
                *(_QWORD *)HIDWORD(v35) += __PAIR64__(v36, v35);
              }
            }
            if ( (*(_BYTE *)(v30 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v28 + 2360) + 260) & *(_DWORD *)(v30 + 356)) != *(_DWORD *)(*(_DWORD *)(v28 + 2360) + 260) )
            {
              *(_QWORD *)(v28 + 2368) += __PAIR64__(v36, v35);
            }
            if ( *(_DWORD *)(v30 + 236) )
              KiEndCounterAccumulation(v30);
          }
        }
      }
      v47 = v57;
      __enable_irq();
      *(_DWORD *)(v28 + 4) = v47;
      *(_BYTE *)(v47 + 132) = 2;
      *(_BYTE *)(v30 + 395) = 32;
      v48 = v61[0];
      *(_BYTE *)(v30 + 134) = v61[0];
      KiQueueReadyThread(v28, v30);
      if ( KiSwapContext(v30, v47, v48) )
      {
        KfLowerIrql(1);
        *(_DWORD *)(v30 + 76) &= 0xFFFFFFBF;
        KiDeliverApc(0, 0, 0);
        KfLowerIrql(v48);
        return v51;
      }
    }
    else
    {
      if ( (*(_DWORD *)(v30 + 76) & 0x40) != 0 )
      {
        KfLowerIrql(1);
        *(_DWORD *)(v30 + 76) &= 0xFFFFFFBF;
        KiDeliverApc(0, 0, 0);
      }
      v48 = v61[0];
    }
    v49 = (void (__fastcall **)(int))&KfLowerIrql;
    v50 = v48;
LABEL_76:
    (*v49)(v50);
  }
  return v51;
}
