// KeRemovePriorityBoost 
 
int __fastcall KeRemovePriorityBoost(int result)
{
  int v1; // r4
  unsigned int v2; // r8
  int v3; // r6
  int v4; // r3
  int v5; // r7
  unsigned int *v6; // r1
  unsigned int v7; // r2
  __int64 v8; // r0
  unsigned __int64 *v9; // r5
  __int64 v10; // kr08_8
  unsigned __int64 v11; // kr10_8
  unsigned __int64 v12; // kr18_8
  __int64 v13; // r2
  char v14; // r5
  unsigned int v15; // r1
  int v16; // r4
  unsigned int v17; // r3
  bool v18; // cf
  unsigned int v19; // r1
  int v20; // r3
  int v21; // r0
  int v22; // r2
  int v23; // r4
  unsigned __int64 *v24; // r4
  unsigned __int64 v25; // kr20_8
  unsigned __int64 v26; // kr28_8
  int v27; // r1
  int i; // r1
  int v29; // r4
  int (__fastcall **v30)(int); // r3
  int v31; // r0
  int v32; // [sp+0h] [bp-30h]

  v1 = result;
  if ( *(_BYTE *)(result + 348) )
  {
    v2 = KfRaiseIrql(2);
    v3 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    result = KiRemoveBoostThread(v3, v1);
    v4 = *(_DWORD *)(v3 + 8);
    if ( v2 < 2 )
    {
      v5 = *(_DWORD *)(v3 + 4);
      if ( v4 )
      {
        KiAbProcessContextSwitch(*(_DWORD *)(v3 + 4), 0);
        v6 = (unsigned int *)(v3 + 24);
        while ( 1 )
        {
          do
            v7 = __ldrex(v6);
          while ( __strex(1u, v6) );
          __dmb(0xBu);
          if ( !v7 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v6 );
        }
        v32 = *(_DWORD *)(v3 + 8);
        *(_DWORD *)(v3 + 8) = 0;
        __disable_irq();
        *(_BYTE *)(v3 + 16) = 1;
        LODWORD(v8) = ReadTimeStampCounter();
        v9 = (unsigned __int64 *)(v5 + 48);
        v10 = v8 - *(_QWORD *)(v3 + 2376);
        v11 = *(_QWORD *)(v5 + 48) + v10;
        __dmb(0xBu);
        do
          v12 = __ldrexd(v9);
        while ( __strexd(v11, v9) );
        __dmb(0xBu);
        v13 = v10 + *(unsigned int *)(v5 + 56);
        if ( HIDWORD(v13) )
          LODWORD(v13) = -1;
        *(_QWORD *)(v3 + 2376) = v8;
        v14 = *(_BYTE *)(v5 + 2);
        *(_DWORD *)(v5 + 56) = v13;
        if ( (v14 & 0x3E) != 0 )
        {
          if ( (v14 & 0x10) != 0 )
          {
            v15 = *(_DWORD *)(v3 + 2376);
            v16 = v3 + 8 * *(unsigned __int8 *)(v5 + 84);
            v17 = *(_DWORD *)(v3 + 2384);
            v14 &= 0xEFu;
            v18 = v15 >= v17;
            v19 = v15 - v17;
            v20 = *(_DWORD *)(v16 + 2392);
            v21 = *(_DWORD *)(v3 + 2380) - (*(_DWORD *)(v3 + 2388) + !v18);
            v22 = *(_DWORD *)(v16 + 2396);
            *(_DWORD *)(v16 + 2392) = v20 + v19;
            *(_DWORD *)(v16 + 2396) = v21 + __CFADD__(v20, v19) + v22;
            *(_DWORD *)(v3 + 2384) = 0;
            *(_DWORD *)(v3 + 2388) = 0;
          }
          if ( (v14 & 0x3E) != 0 )
          {
            if ( (v14 & 0x20) != 0 )
            {
              v23 = *(_DWORD *)(v5 + 1084);
              if ( v23 )
              {
                v24 = (unsigned __int64 *)(v23 + 8 * (*(unsigned __int8 *)(v3 + 2986) + 2 * PoGetFrequencyBucket(v3)));
                v25 = *v24 + v10;
                __dmb(0xBu);
                do
                  v26 = __ldrexd(v24);
                while ( __strexd(v25, v24) );
                __dmb(0xBu);
              }
              v14 &= 0xDFu;
            }
            if ( (v14 & 0x3E) != 0 )
            {
              v27 = *(_DWORD *)(v5 + 68);
              if ( v27 )
              {
                for ( i = v27 + *(_DWORD *)(v3 + 2352); i; i = *(_DWORD *)(i + 236) )
                  *(_QWORD *)i += v10;
              }
              if ( (*(_BYTE *)(v5 + 2) & 8) != 0
                && (*(_DWORD *)(*(_DWORD *)(v3 + 2360) + 260) & *(_DWORD *)(v5 + 356)) != *(_DWORD *)(*(_DWORD *)(v3 + 2360) + 260) )
              {
                *(_QWORD *)(v3 + 2368) += v10;
              }
              if ( *(_DWORD *)(v5 + 236) )
                KiEndCounterAccumulation(v5);
            }
          }
        }
        v29 = v32;
        __enable_irq();
        *(_DWORD *)(v3 + 4) = v29;
        *(_BYTE *)(v29 + 132) = 2;
        *(_BYTE *)(v5 + 395) = 32;
        *(_BYTE *)(v5 + 134) = v2;
        KiQueueReadyThread(v3, v5);
        if ( !KiSwapContext(v5, v29, v2) )
          goto LABEL_37;
      }
      else if ( (*(_DWORD *)(v5 + 76) & 0x40) == 0 )
      {
LABEL_37:
        v30 = &KfLowerIrql;
        v31 = v2;
        return (*v30)(v31);
      }
      KfLowerIrql(1);
      *(_DWORD *)(v5 + 76) &= 0xFFFFFFBF;
      KiDeliverApc(0, 0, 0);
      goto LABEL_37;
    }
    if ( v4 && !*(_BYTE *)(v3 + 1754) )
    {
      v30 = &HalRequestSoftwareInterrupt;
      v31 = 2;
      return (*v30)(v31);
    }
  }
  return result;
}
