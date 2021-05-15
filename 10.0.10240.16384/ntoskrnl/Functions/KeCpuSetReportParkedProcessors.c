// KeCpuSetReportParkedProcessors 
 
int __fastcall KeCpuSetReportParkedProcessors(int result, int a2)
{
  unsigned int v2; // r9
  unsigned int v3; // r8
  unsigned int v4; // r2
  int v5; // r2
  int v6; // r1
  unsigned __int16 v7; // r10
  int v8; // r5
  int v9; // r3
  int v10; // r6
  int v11; // r0
  int v12; // r9
  int v13; // r7
  unsigned int v14; // r2
  int v15; // r0
  int v16; // lr
  int v17; // r3
  int v18; // r2
  int v19; // r2
  int v20; // r5
  unsigned int v21; // r1
  int v22; // lr
  _DWORD *v23; // r5
  int v24; // r2
  unsigned __int16 i; // r1
  unsigned int j; // r7
  int v27; // r3
  int v28; // r8
  _DWORD *v29; // r1
  unsigned int *v30; // r1
  unsigned int v31; // r2
  int v32; // r10
  __int64 v33; // r0
  unsigned __int64 *v34; // r6
  unsigned int v35; // r9
  unsigned int v36; // lr
  __int64 v37; // kr10_8
  unsigned __int64 v38; // kr18_8
  unsigned __int64 v39; // kr20_8
  unsigned __int64 v40; // r2
  char v41; // r9
  int v42; // r4
  int v43; // r0
  unsigned int v44; // r5
  unsigned __int64 *v45; // r4
  unsigned __int64 v46; // kr28_8
  unsigned __int64 v47; // kr30_8
  int v48; // r1
  int k; // r1
  int v50; // r1
  int v51; // r10
  int v52; // r3
  unsigned int v53; // r6
  int v54; // [sp+0h] [bp-40h]
  int v55; // [sp+4h] [bp-3Ch]
  unsigned int v56; // [sp+4h] [bp-3Ch]
  int v57[4]; // [sp+8h] [bp-38h] BYREF
  int v58; // [sp+18h] [bp-28h]
  unsigned int v59; // [sp+1Ch] [bp-24h]

  v2 = a2;
  v3 = (unsigned __int16)KiActiveGroups;
  v58 = a2;
  __pld((void *)KiCpuSetAffinities);
  v54 = result;
  __pld((void *)KiCpuSetAffinitiesShadow);
  if ( result )
  {
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_51BE80();
    do
      v4 = __ldrex((unsigned int *)&KiCpuSetLock);
    while ( __strex(1u, (unsigned int *)&KiCpuSetLock) );
    __dmb(0xBu);
    if ( v4 )
      JUMPOUT(0x51BE88);
  }
  v5 = 0;
  v6 = 0;
  v55 = 0;
  if ( v3 )
  {
    v7 = 0;
    v57[0] = 0;
    while ( 1 )
    {
      v8 = dword_681D78[v6];
      if ( result )
      {
        if ( v6 )
          v9 = 0;
        else
          v9 = *(_DWORD *)(result + 8);
        v10 = v9 ^ v8;
        v57[v6 + 2] = v9 ^ v8;
        if ( KiNonParkedCpuSets[v6] == (v9 ^ v8) )
          goto LABEL_28;
      }
      else
      {
        v10 = KiNonParkedCpuSets[v6];
        v57[v6 + 2] = v10;
      }
      v5 = 1;
      v11 = v10 & v8;
      v12 = KiCpuSetAffinitiesShadow;
      v13 = v10 & v8 ^ v8;
      v55 = 1;
      if ( (v10 & v8) != 0 )
      {
        do
        {
          v14 = __clz(__rbit(v11));
          v11 ^= 1 << v14;
          *(_DWORD *)(v12 + 4 * v14) = 1 << v14;
        }
        while ( v11 );
        v5 = 1;
      }
      if ( !v13 )
      {
        result = v54;
        goto LABEL_29;
      }
      v15 = KiGroupBlock[2 * v6 + 1];
      v16 = v15 ^ v8;
      if ( (v15 & v10) == 0 || (v16 & v10) == 0 )
      {
        v15 = 0;
        v16 = 0;
      }
      v17 = KiSystemAllowedCpuSets[v6] ^ v8;
      v18 = v17 & v10;
      if ( v17 )
      {
        if ( v18 )
        {
          v50 = v17 & v13;
          v13 ^= v17 & v13;
          if ( v50 )
          {
            while ( 1 )
            {
              v59 = __clz(__rbit(v50));
              v50 &= ~(1 << v59);
              v51 = v18;
              if ( ((1 << v59) & v15) != 0 )
                break;
              v52 = v18 & v16;
              if ( (v18 & v16) != 0 )
                goto LABEL_94;
LABEL_95:
              *(_DWORD *)(v12 + 4 * v59) = v51;
              if ( !v50 )
              {
                v7 = v57[0];
                goto LABEL_19;
              }
            }
            v52 = v18 & v15;
            if ( (v18 & v15) == 0 )
              goto LABEL_95;
LABEL_94:
            v51 = v52;
            goto LABEL_95;
          }
        }
      }
LABEL_19:
      if ( v13 )
      {
        v19 = v8 & ~v18;
        if ( (v19 & v10) == 0 )
          v19 = v8;
        v20 = v19 & v16;
        do
        {
          v21 = __clz(__rbit(v13));
          v13 &= ~(1 << v21);
          v22 = v19;
          if ( ((1 << v21) & v15) != 0 )
          {
            if ( (v19 & v15 & v10) != 0 )
              v22 = v19 & v15;
          }
          else if ( (v20 & v10) != 0 )
          {
            v22 = v20;
          }
          *(_DWORD *)(v12 + 4 * v21) = v22;
        }
        while ( v13 );
      }
      result = v54;
LABEL_28:
      v5 = v55;
LABEL_29:
      v6 = ++v7;
      v57[0] = v7;
      if ( v7 >= v3 )
      {
        v2 = v58;
        break;
      }
    }
  }
  v23 = 0;
  v57[0] = 0;
  if ( v5 )
  {
    RtlWriteAcquireTickLock(&KiCpuSetSequence, v6);
    v24 = 0;
    if ( v3 )
    {
      for ( i = 0; i < v3; v24 = ++i )
        KiNonParkedCpuSets[v24] = v57[v24 + 2];
    }
    memmove(KiCpuSetAffinities, KiCpuSetAffinitiesShadow, KiCpuSetAffinitySize);
    RtlWriteReleaseTickLock(&KiCpuSetSequence);
    result = KiUpdateGlobalCpuSetConfiguration(v57);
    v23 = (_DWORD *)v57[0];
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = KiReleaseSpinLockInstrumented(&KiCpuSetLock);
  }
  else
  {
    __dmb(0xBu);
    KiCpuSetLock = 0;
  }
  for ( j = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408; v23; result = KiDeferredReadyThread(j, v29) )
  {
    v29 = v23 - 36;
    v23 = (_DWORD *)*v23;
  }
  v27 = *(_DWORD *)(j + 8);
  if ( v2 < 2 )
  {
    v28 = *(_DWORD *)(j + 4);
    if ( v27 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(j + 4), 0);
      v30 = (unsigned int *)(j + 24);
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
      v32 = *(_DWORD *)(j + 8);
      *(_DWORD *)(j + 8) = 0;
      __disable_irq();
      *(_BYTE *)(j + 16) = 1;
      LODWORD(v33) = ReadTimeStampCounter();
      v34 = (unsigned __int64 *)(v28 + 48);
      v35 = (unsigned __int64)(v33 - *(_QWORD *)(j + 2376)) >> 32;
      v37 = *(_QWORD *)(v28 + 48);
      v59 = v33 - *(_DWORD *)(j + 2376);
      v36 = v59;
      v56 = v35;
      v38 = v37 + __PAIR64__(v35, v59);
      __dmb(0xBu);
      do
        v39 = __ldrexd(v34);
      while ( __strexd(v38, v34) );
      __dmb(0xBu);
      v40 = __PAIR64__(v35, *(_DWORD *)(v28 + 56)) + v36;
      if ( HIDWORD(v40) )
      {
        v57[3] = 0;
        LODWORD(v40) = -1;
      }
      *(_QWORD *)(j + 2376) = v33;
      v41 = *(_BYTE *)(v28 + 2);
      *(_DWORD *)(v28 + 56) = v40;
      if ( (v41 & 0x3E) != 0 )
      {
        if ( (v41 & 0x10) != 0 )
        {
          v53 = j + 8 * *(unsigned __int8 *)(v28 + 84);
          *(_QWORD *)(v53 + 2392) = *(_QWORD *)(v53 + 2392) - *(_QWORD *)(j + 2384) + *(_QWORD *)(j + 2376);
          *(_DWORD *)(j + 2384) = 0;
          *(_DWORD *)(j + 2388) = 0;
          v41 &= 0xEFu;
        }
        if ( (v41 & 0x3E) != 0 )
        {
          if ( (v41 & 0x20) != 0 )
          {
            v42 = *(_DWORD *)(v28 + 1084);
            if ( v42 )
            {
              v43 = PoGetFrequencyBucket(j);
              v36 = v59;
              v44 = v56;
              v45 = (unsigned __int64 *)(v42 + 8 * (*(unsigned __int8 *)(j + 2986) + 2 * v43));
              v46 = *v45 + __PAIR64__(v56, v59);
              __dmb(0xBu);
              do
                v47 = __ldrexd(v45);
              while ( __strexd(v46, v45) );
              __dmb(0xBu);
            }
            else
            {
              v44 = v56;
            }
            v41 &= 0xDFu;
          }
          else
          {
            v44 = v56;
          }
          if ( (v41 & 0x3E) != 0 )
          {
            v48 = *(_DWORD *)(v28 + 68);
            if ( v48 )
            {
              for ( k = v48 + *(_DWORD *)(j + 2352); k; k = *(_DWORD *)(k + 236) )
                *(_QWORD *)k += __PAIR64__(v44, v36);
            }
            if ( (*(_BYTE *)(v28 + 2) & 8) != 0
              && (*(_DWORD *)(v28 + 356) & *(_DWORD *)(*(_DWORD *)(j + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(j + 2360)
                                                                                                  + 260) )
            {
              *(_QWORD *)(j + 2368) += __PAIR64__(v44, v36);
            }
            if ( *(_DWORD *)(v28 + 236) )
              KiEndCounterAccumulation(v28);
          }
        }
      }
      v2 = v58;
      __enable_irq();
      *(_DWORD *)(j + 4) = v32;
      *(_BYTE *)(v32 + 132) = 2;
      *(_BYTE *)(v28 + 134) = v2;
      *(_BYTE *)(v28 + 395) = 32;
      KiQueueReadyThread(j, v28);
      if ( !KiSwapContext(v28, v32, v2) )
        return KfLowerIrql(v2);
    }
    else if ( (*(_DWORD *)(v28 + 76) & 0x40) == 0 )
    {
      return KfLowerIrql(v2);
    }
    KfLowerIrql(1);
    *(_DWORD *)(v28 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    return KfLowerIrql(v2);
  }
  if ( v27 )
  {
    if ( !*(_BYTE *)(j + 1754) )
      result = HalRequestSoftwareInterrupt(2);
  }
  return result;
}
