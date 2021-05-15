// KiProcessDeferredReadyList 
 
int __fastcall KiProcessDeferredReadyList(int result, _DWORD **a2, unsigned int a3)
{
  _DWORD *v3; // r4
  int v5; // r7
  _DWORD *v6; // r1
  int v7; // r3
  int v8; // r8
  int (__fastcall **v9)(int); // r3
  int v10; // r0
  unsigned int *v11; // r1
  unsigned int v12; // r2
  __int64 v13; // r0
  unsigned __int64 *v14; // r6
  __int64 v15; // kr08_8
  unsigned __int64 v16; // kr10_8
  unsigned __int64 v17; // kr18_8
  __int64 v18; // r2
  char v19; // r5
  int v20; // r4
  unsigned __int64 *v21; // r4
  unsigned __int64 v22; // kr20_8
  unsigned __int64 v23; // kr28_8
  int v24; // r1
  int v25; // r4
  int i; // r1
  unsigned int v27; // r1
  int v28; // r4
  unsigned int v29; // r3
  bool v30; // cf
  unsigned int v31; // r1
  int v32; // r3
  int v33; // r0
  int v34; // r2
  int v35; // [sp+4h] [bp-2Ch]

  v3 = *a2;
  v5 = result;
  while ( v3 )
  {
    v6 = v3 - 36;
    v3 = (_DWORD *)*v3;
    result = KiDeferredReadyThread(v5, v6);
  }
  v7 = *(_DWORD *)(v5 + 8);
  if ( a3 < 2 )
  {
    v8 = *(_DWORD *)(v5 + 4);
    if ( v7 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(v5 + 4), 0);
      v11 = (unsigned int *)(v5 + 24);
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
      v35 = *(_DWORD *)(v5 + 8);
      *(_DWORD *)(v5 + 8) = 0;
      __disable_irq();
      *(_BYTE *)(v5 + 16) = 1;
      LODWORD(v13) = ReadTimeStampCounter();
      v14 = (unsigned __int64 *)(v8 + 48);
      v15 = v13 - *(_QWORD *)(v5 + 2376);
      v16 = *(_QWORD *)(v8 + 48) + v15;
      __dmb(0xBu);
      do
        v17 = __ldrexd(v14);
      while ( __strexd(v16, v14) );
      __dmb(0xBu);
      v18 = v15 + *(unsigned int *)(v8 + 56);
      if ( HIDWORD(v18) )
        return sub_50BCF0();
      *(_QWORD *)(v5 + 2376) = v13;
      v19 = *(_BYTE *)(v8 + 2);
      *(_DWORD *)(v8 + 56) = v18;
      if ( (v19 & 0x3E) != 0 )
      {
        if ( (v19 & 0x10) != 0 )
        {
          v27 = *(_DWORD *)(v5 + 2376);
          v28 = v5 + 8 * *(unsigned __int8 *)(v8 + 84);
          v29 = *(_DWORD *)(v5 + 2384);
          v19 &= 0xEFu;
          v30 = v27 >= v29;
          v31 = v27 - v29;
          v32 = *(_DWORD *)(v28 + 2392);
          v33 = *(_DWORD *)(v5 + 2380) - (*(_DWORD *)(v5 + 2388) + !v30);
          v34 = *(_DWORD *)(v28 + 2396);
          *(_DWORD *)(v28 + 2392) = v32 + v31;
          *(_DWORD *)(v28 + 2396) = v33 + __CFADD__(v32, v31) + v34;
          *(_DWORD *)(v5 + 2384) = 0;
          *(_DWORD *)(v5 + 2388) = 0;
        }
        if ( (v19 & 0x3E) != 0 )
        {
          if ( (v19 & 0x20) != 0 )
          {
            v20 = *(_DWORD *)(v8 + 1084);
            if ( v20 )
            {
              v21 = (unsigned __int64 *)(v20 + 8 * (*(unsigned __int8 *)(v5 + 2986) + 2 * PoGetFrequencyBucket(v5)));
              v22 = *v21 + v15;
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
            v24 = *(_DWORD *)(v8 + 68);
            if ( v24 )
            {
              for ( i = v24 + *(_DWORD *)(v5 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += v15;
            }
            if ( (*(_BYTE *)(v8 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v5 + 2360) + 260) & *(_DWORD *)(v8 + 356)) != *(_DWORD *)(*(_DWORD *)(v5 + 2360)
                                                                                                  + 260) )
            {
              *(_QWORD *)(v5 + 2368) += v15;
            }
            if ( *(_DWORD *)(v8 + 236) )
              KiEndCounterAccumulation(v8);
          }
        }
      }
      v25 = v35;
      __enable_irq();
      *(_DWORD *)(v5 + 4) = v25;
      *(_BYTE *)(v25 + 132) = 2;
      *(_BYTE *)(v8 + 395) = 32;
      *(_BYTE *)(v8 + 134) = a3;
      KiQueueReadyThread(v5, v8);
      if ( !KiSwapContext(v8, v25, a3) )
      {
LABEL_9:
        v9 = &KfLowerIrql;
        v10 = a3;
        return (*v9)(v10);
      }
    }
    else if ( (*(_DWORD *)(v8 + 76) & 0x40) == 0 )
    {
      goto LABEL_9;
    }
    KfLowerIrql(1);
    *(_DWORD *)(v8 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_9;
  }
  if ( v7 && !*(_BYTE *)(v5 + 1754) )
  {
    v9 = &HalRequestSoftwareInterrupt;
    v10 = 2;
    return (*v9)(v10);
  }
  return result;
}
