// KiExitDispatcher 
 
int __fastcall KiExitDispatcher(int result, int a2, int a3, int a4, unsigned __int8 a5)
{
  int v8; // r7
  int v9; // r3
  int v10; // r9
  int v11; // r2
  unsigned int *v12; // r1
  unsigned int v13; // r2
  __int64 v14; // r0
  unsigned __int64 *v15; // r6
  __int64 v16; // kr08_8
  unsigned int v17; // lr
  unsigned __int64 v18; // kr10_8
  unsigned __int64 v19; // kr18_8
  __int64 v20; // r2
  char v21; // r10
  int v22; // r4
  unsigned int v23; // r5
  unsigned __int64 *v24; // r4
  unsigned __int64 v25; // kr20_8
  unsigned __int64 v26; // kr28_8
  int v27; // r4
  int v28; // r1
  int i; // r1
  int v30; // r6
  unsigned int v31; // [sp+4h] [bp-34h]
  int v32; // [sp+8h] [bp-30h]

  v8 = result;
  if ( *(_DWORD *)(result + 1540) )
  {
    if ( a2 )
    {
      result = KiDirectSwitchThread(result, a4);
      if ( result )
        goto LABEL_14;
    }
    result = KiProcessThreadWaitList(v8, a3, a4, 0);
  }
  if ( a2 )
  {
LABEL_14:
    v11 = *(_DWORD *)(v8 + 4);
    *(_BYTE *)(v11 + 134) = a5;
    *(_DWORD *)(v11 + 76) |= 4u;
    return result;
  }
  v9 = *(_DWORD *)(v8 + 8);
  if ( a5 < 2u )
  {
    v10 = *(_DWORD *)(v8 + 4);
    if ( v9 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(v8 + 4), 0);
      v12 = (unsigned int *)(v8 + 24);
      while ( 1 )
      {
        do
          v13 = __ldrex(v12);
        while ( __strex(1u, v12) );
        __dmb(0xBu);
        if ( !v13 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v12 );
      }
      v32 = *(_DWORD *)(v8 + 8);
      *(_DWORD *)(v8 + 8) = 0;
      __disable_irq();
      *(_BYTE *)(v8 + 16) = 1;
      LODWORD(v14) = ReadTimeStampCounter();
      v15 = (unsigned __int64 *)(v10 + 48);
      v16 = v14 - *(_QWORD *)(v8 + 2376);
      v17 = v16;
      v31 = v14 - *(_DWORD *)(v8 + 2376);
      v18 = *(_QWORD *)(v10 + 48) + v16;
      __dmb(0xBu);
      do
        v19 = __ldrexd(v15);
      while ( __strexd(v18, v15) );
      __dmb(0xBu);
      v20 = v16 + *(unsigned int *)(v10 + 56);
      if ( HIDWORD(v20) )
        return sub_50C8D0();
      *(_QWORD *)(v8 + 2376) = v14;
      v21 = *(_BYTE *)(v10 + 2);
      *(_DWORD *)(v10 + 56) = v20;
      if ( (v21 & 0x3E) != 0 )
      {
        if ( (v21 & 0x10) != 0 )
        {
          v30 = v8 + 8 * *(unsigned __int8 *)(v10 + 84);
          *(_QWORD *)(v30 + 2392) = *(_QWORD *)(v30 + 2392) - *(_QWORD *)(v8 + 2384) + *(_QWORD *)(v8 + 2376);
          *(_DWORD *)(v8 + 2384) = 0;
          *(_DWORD *)(v8 + 2388) = 0;
          v21 &= 0xEFu;
        }
        if ( (v21 & 0x3E) != 0 )
        {
          if ( (v21 & 0x20) != 0 )
          {
            v22 = *(_DWORD *)(v10 + 1084);
            if ( v22 )
            {
              v23 = HIDWORD(v16);
              v17 = v31;
              v24 = (unsigned __int64 *)(v22 + 8 * (*(unsigned __int8 *)(v8 + 2986) + 2 * PoGetFrequencyBucket(v8)));
              v25 = *v24 + __PAIR64__(HIDWORD(v16), v31);
              __dmb(0xBu);
              do
                v26 = __ldrexd(v24);
              while ( __strexd(v25, v24) );
              __dmb(0xBu);
            }
            else
            {
              v23 = HIDWORD(v16);
            }
            v21 &= 0xDFu;
          }
          else
          {
            v23 = HIDWORD(v16);
          }
          if ( (v21 & 0x3E) != 0 )
          {
            v28 = *(_DWORD *)(v10 + 68);
            if ( v28 )
            {
              for ( i = v28 + *(_DWORD *)(v8 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += __PAIR64__(v23, v17);
            }
            if ( (*(_BYTE *)(v10 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) & *(_DWORD *)(v10 + 356)) != *(_DWORD *)(*(_DWORD *)(v8 + 2360) + 260) )
            {
              *(_QWORD *)(v8 + 2368) += __PAIR64__(v23, v17);
            }
            if ( *(_DWORD *)(v10 + 236) )
              KiEndCounterAccumulation(v10);
          }
        }
      }
      v27 = v32;
      __enable_irq();
      *(_DWORD *)(v8 + 4) = v27;
      *(_BYTE *)(v27 + 132) = 2;
      *(_BYTE *)(v10 + 395) = 32;
      *(_BYTE *)(v10 + 134) = a5;
      KiQueueReadyThread(v8, v10);
      if ( !KiSwapContext(v10, v27, a5) )
        return KfLowerIrql(a5);
    }
    else if ( (*(_DWORD *)(v10 + 76) & 0x40) == 0 )
    {
      return KfLowerIrql(a5);
    }
    KfLowerIrql(1);
    *(_DWORD *)(v10 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    return KfLowerIrql(a5);
  }
  if ( v9 )
  {
    if ( !*(_BYTE *)(v8 + 1754) )
      result = HalRequestSoftwareInterrupt(2);
  }
  return result;
}
