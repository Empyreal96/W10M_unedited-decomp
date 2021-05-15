// KiFastReadyThread 
 
int __fastcall KiFastReadyThread(int a1)
{
  unsigned int v2; // r10
  int result; // r0
  int v4; // r7
  unsigned int *v5; // r1
  unsigned int v6; // r2
  int v7; // r3
  int v8; // r8
  int (__fastcall **v9)(int); // r3
  int v10; // r0
  unsigned int *v11; // r1
  unsigned int v12; // r2
  int v13; // r3
  __int64 v14; // r0
  unsigned __int64 *v15; // r5
  unsigned int v16; // r6
  unsigned int v17; // lr
  __int64 v18; // kr08_8
  unsigned __int64 v19; // kr10_8
  unsigned __int64 v20; // kr18_8
  __int64 v21; // r2
  char v22; // r9
  int v23; // r4
  unsigned __int64 *v24; // r4
  unsigned __int64 v25; // kr20_8
  unsigned __int64 v26; // kr28_8
  int v27; // r1
  int i; // r1
  int v29; // r4
  int v30; // r6
  int v31; // [sp+8h] [bp-30h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x200) != 0 )
    return sub_54787C();
  v4 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v5 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v6 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v5 );
  }
  *(_BYTE *)(a1 + 132) = 7;
  __dmb(0xBu);
  *v5 = 0;
  result = KiDeferredReadyThread(v4, a1);
  v7 = *(_DWORD *)(v4 + 8);
  if ( v2 < 2 )
  {
    v8 = *(_DWORD *)(v4 + 4);
    if ( v7 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(v4 + 4), 0);
      v11 = (unsigned int *)(v4 + 24);
      while ( 1 )
      {
        do
          v12 = __ldrex(v11);
        while ( __strex(1u, v11) );
        __dmb(0xBu);
        if ( !v12 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v11 );
      }
      v13 = *(_DWORD *)(v4 + 8);
      *(_DWORD *)(v4 + 8) = 0;
      __disable_irq();
      v31 = v13;
      *(_BYTE *)(v4 + 16) = 1;
      LODWORD(v14) = ReadTimeStampCounter();
      v15 = (unsigned __int64 *)(v8 + 48);
      v18 = v14 - *(_QWORD *)(v4 + 2376);
      v17 = HIDWORD(v18);
      v16 = v18;
      v19 = *(_QWORD *)(v8 + 48) + v18;
      __dmb(0xBu);
      do
        v20 = __ldrexd(v15);
      while ( __strexd(v19, v15) );
      __dmb(0xBu);
      v21 = v18 + *(unsigned int *)(v8 + 56);
      if ( HIDWORD(v21) )
        LODWORD(v21) = -1;
      *(_QWORD *)(v4 + 2376) = v14;
      v22 = *(_BYTE *)(v8 + 2);
      *(_DWORD *)(v8 + 56) = v21;
      if ( (v22 & 0x3E) != 0 )
      {
        if ( (v22 & 0x10) != 0 )
        {
          v30 = v4 + 8 * *(unsigned __int8 *)(v8 + 84);
          *(_QWORD *)(v30 + 2392) = *(_QWORD *)(v30 + 2392) - *(_QWORD *)(v4 + 2384) + *(_QWORD *)(v4 + 2376);
          *(_DWORD *)(v4 + 2384) = 0;
          *(_DWORD *)(v4 + 2388) = 0;
          v16 = v18;
          v22 &= 0xEFu;
        }
        if ( (v22 & 0x3E) != 0 )
        {
          if ( (v22 & 0x20) != 0 )
          {
            v23 = *(_DWORD *)(v8 + 1084);
            if ( v23 )
            {
              v17 = HIDWORD(v18);
              v24 = (unsigned __int64 *)(v23 + 8 * (*(unsigned __int8 *)(v4 + 2986) + 2 * PoGetFrequencyBucket(v4)));
              v25 = *v24 + __PAIR64__(HIDWORD(v18), v16);
              __dmb(0xBu);
              do
                v26 = __ldrexd(v24);
              while ( __strexd(v25, v24) );
              __dmb(0xBu);
            }
            v22 &= 0xDFu;
          }
          if ( (v22 & 0x3E) != 0 )
          {
            v27 = *(_DWORD *)(v8 + 68);
            if ( v27 )
            {
              for ( i = v27 + *(_DWORD *)(v4 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += __PAIR64__(v17, v16);
            }
            if ( (*(_BYTE *)(v8 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v4 + 2360) + 260) & *(_DWORD *)(v8 + 356)) != *(_DWORD *)(*(_DWORD *)(v4 + 2360)
                                                                                                  + 260) )
            {
              *(_QWORD *)(v4 + 2368) += __PAIR64__(v17, v16);
            }
            if ( *(_DWORD *)(v8 + 236) )
              KiEndCounterAccumulation(v8);
          }
        }
      }
      v29 = v31;
      __enable_irq();
      *(_DWORD *)(v4 + 4) = v29;
      *(_BYTE *)(v29 + 132) = 2;
      *(_BYTE *)(v8 + 395) = 32;
      *(_BYTE *)(v8 + 134) = v2;
      KiQueueReadyThread(v4, v8);
      if ( !KiSwapContext(v8, v29, v2) )
        goto LABEL_11;
    }
    else if ( (*(_DWORD *)(v8 + 76) & 0x40) == 0 )
    {
LABEL_11:
      v9 = &KfLowerIrql;
      v10 = v2;
      return (*v9)(v10);
    }
    KfLowerIrql(1);
    *(_DWORD *)(v8 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_11;
  }
  if ( v7 && !*(_BYTE *)(v4 + 1754) )
  {
    v9 = &HalRequestSoftwareInterrupt;
    v10 = 2;
    return (*v9)(v10);
  }
  return result;
}
