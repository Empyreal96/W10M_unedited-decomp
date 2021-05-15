// KiReadyOutSwappedThreads 
 
int __fastcall KiReadyOutSwappedThreads(_DWORD *a1, unsigned int a2)
{
  _DWORD *v2; // r8
  _DWORD *v3; // r5
  unsigned int v4; // r7
  _DWORD *v5; // r4
  unsigned int *v6; // r6
  unsigned int v7; // r2
  int result; // r0
  int v9; // r3
  int v10; // r8
  int (__fastcall **v11)(int); // r3
  int v12; // r0
  unsigned int *v13; // r1
  unsigned int v14; // r2
  __int64 v15; // r0
  __int64 v16; // kr00_8
  unsigned __int64 *v17; // r6
  unsigned __int64 v18; // kr08_8
  unsigned __int64 v19; // kr10_8
  __int64 v20; // r2
  char v21; // r9
  int v22; // r4
  unsigned int v23; // r5
  unsigned __int64 *v24; // r4
  unsigned __int64 v25; // kr18_8
  unsigned __int64 v26; // kr20_8
  int v27; // r1
  int v28; // r4
  int i; // r1
  unsigned int v30; // r6
  int v32; // [sp+8h] [bp-30h]

  v2 = a1;
  v3 = a1;
  v4 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  do
  {
    v5 = v3 - 36;
    v3 = (_DWORD *)*v3;
    v6 = v5 + 11;
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
    *((_BYTE *)v5 + 132) = 7;
    __dmb(0xBu);
    *v6 = 0;
    if ( (dword_682604 & 0x200) != 0 )
      return sub_516098(1, 7);
    KiReadyThread(v4, v5);
    result = 1;
  }
  while ( v3 != v2 );
  v9 = *(_DWORD *)(v4 + 8);
  if ( a2 < 2 )
  {
    v10 = *(_DWORD *)(v4 + 4);
    if ( v9 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(v4 + 4), 0);
      v13 = (unsigned int *)(v4 + 24);
      while ( 1 )
      {
        do
          v14 = __ldrex(v13);
        while ( __strex(1u, v13) );
        __dmb(0xBu);
        if ( !v14 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v13 );
      }
      v32 = *(_DWORD *)(v4 + 8);
      *(_DWORD *)(v4 + 8) = 0;
      __disable_irq();
      *(_BYTE *)(v4 + 16) = 1;
      LODWORD(v15) = ReadTimeStampCounter();
      v17 = (unsigned __int64 *)(v10 + 48);
      v16 = v15 - *(_QWORD *)(v4 + 2376);
      v18 = *(_QWORD *)(v10 + 48) + v16;
      __dmb(0xBu);
      do
        v19 = __ldrexd(v17);
      while ( __strexd(v18, v17) );
      __dmb(0xBu);
      v20 = v16 + *(unsigned int *)(v10 + 56);
      if ( HIDWORD(v20) )
        LODWORD(v20) = -1;
      *(_QWORD *)(v4 + 2376) = v15;
      v21 = *(_BYTE *)(v10 + 2);
      *(_DWORD *)(v10 + 56) = v20;
      if ( (v21 & 0x3E) != 0 )
      {
        if ( (v21 & 0x10) != 0 )
        {
          v30 = v4 + 8 * *(unsigned __int8 *)(v10 + 84);
          *(_QWORD *)(v30 + 2392) = *(_QWORD *)(v30 + 2392) - *(_QWORD *)(v4 + 2384) + *(_QWORD *)(v4 + 2376);
          *(_DWORD *)(v4 + 2384) = 0;
          *(_DWORD *)(v4 + 2388) = 0;
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
              v24 = (unsigned __int64 *)(v22 + 8 * (*(unsigned __int8 *)(v4 + 2986) + 2 * PoGetFrequencyBucket(v4)));
              v25 = *v24 + v16;
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
            v27 = *(_DWORD *)(v10 + 68);
            if ( v27 )
            {
              for ( i = v27 + *(_DWORD *)(v4 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += __PAIR64__(v23, v16);
            }
            if ( (*(_BYTE *)(v10 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v4 + 2360) + 260) & *(_DWORD *)(v10 + 356)) != *(_DWORD *)(*(_DWORD *)(v4 + 2360) + 260) )
            {
              *(_QWORD *)(v4 + 2368) += __PAIR64__(v23, v16);
            }
            if ( *(_DWORD *)(v10 + 236) )
              KiEndCounterAccumulation(v10);
          }
        }
      }
      v28 = v32;
      __enable_irq();
      *(_DWORD *)(v4 + 4) = v28;
      *(_BYTE *)(v28 + 132) = 2;
      *(_BYTE *)(v10 + 395) = 32;
      *(_BYTE *)(v10 + 134) = a2;
      KiQueueReadyThread(v4, v10);
      if ( !KiSwapContext(v10, v28, a2) )
        goto LABEL_13;
    }
    else if ( (*(_DWORD *)(v10 + 76) & 0x40) == 0 )
    {
LABEL_13:
      v11 = &KfLowerIrql;
      v12 = a2;
      return (*v11)(v12);
    }
    KfLowerIrql(1);
    *(_DWORD *)(v10 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_13;
  }
  if ( v9 && !*(_BYTE *)(v4 + 1754) )
  {
    v11 = (int (__fastcall **)(int))&HalRequestSoftwareInterrupt;
    v12 = 2;
    return (*v11)(v12);
  }
  return result;
}
