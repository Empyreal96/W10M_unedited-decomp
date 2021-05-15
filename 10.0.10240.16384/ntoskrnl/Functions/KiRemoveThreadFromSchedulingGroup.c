// KiRemoveThreadFromSchedulingGroup 
 
unsigned int *__fastcall KiRemoveThreadFromSchedulingGroup(int a1)
{
  int v2; // r5
  unsigned int *v3; // r6
  unsigned int v4; // r2
  int v5; // r0
  _DWORD *v6; // r4
  int v7; // r8
  unsigned __int8 *v8; // r3
  unsigned int v9; // r2
  unsigned int *result; // r0
  _DWORD *v11; // r3
  unsigned int v12; // r8
  __int64 v13; // r0
  unsigned int v14; // lr
  __int64 v15; // kr00_8
  unsigned __int64 *v16; // r6
  __int64 v17; // kr08_8
  unsigned __int64 v18; // kr18_8
  __int64 v19; // r2
  char v20; // r10
  int v21; // r4
  unsigned int v22; // r5
  unsigned __int64 *v23; // r4
  unsigned __int64 v24; // kr20_8
  unsigned __int64 v25; // kr28_8
  int v26; // r1
  int i; // r1
  int v28; // r0
  unsigned int v29; // r1
  unsigned int v30; // r10
  unsigned int v31; // r1
  unsigned __int64 v32; // kr30_8
  unsigned __int64 *v33; // r3
  unsigned __int64 v34; // kr38_8
  unsigned __int64 v35; // kr40_8
  unsigned __int64 *v36; // r4
  unsigned __int64 v37; // kr48_8
  unsigned __int64 v38; // kr58_8
  unsigned int *v39; // r4
  unsigned int v40; // r2
  unsigned __int8 *v41; // r3
  unsigned int v42; // r1
  unsigned __int8 *v43; // r3
  unsigned int v44; // r2
  unsigned int v45; // r6
  int v46; // r5
  int v47; // r2
  unsigned int *v48; // r1
  unsigned int v49; // r2
  unsigned int **v50; // lr
  unsigned int v51; // r2
  _DWORD *v52; // r1
  unsigned int v53; // r2
  unsigned int v54; // [sp+0h] [bp-30h] BYREF
  unsigned int v55[11]; // [sp+4h] [bp-2Ch] BYREF

  if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
  {
    v12 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    __disable_irq();
    *(_BYTE *)(v12 + 16) = 1;
    LODWORD(v13) = ReadTimeStampCounter();
    v16 = (unsigned __int64 *)(a1 + 48);
    v15 = v13 - *(_QWORD *)(v12 + 2376);
    v14 = v15;
    v17 = *(_QWORD *)(a1 + 48);
    v54 = HIDWORD(v15);
    v55[0] = v15;
    __dmb(0xBu);
    do
      v18 = __ldrexd(v16);
    while ( __strexd(v17 + v15, v16) );
    __dmb(0xBu);
    v19 = v15 + *(unsigned int *)(a1 + 56);
    if ( HIDWORD(v19) )
    {
      result = (unsigned int *)sub_515788();
    }
    else
    {
      *(_QWORD *)(v12 + 2376) = v13;
      v20 = *(_BYTE *)(a1 + 2);
      *(_DWORD *)(a1 + 56) = v19;
      if ( (v20 & 0x3E) != 0 )
      {
        if ( (v20 & 0x10) != 0 )
        {
          v45 = v12 + 8 * *(unsigned __int8 *)(a1 + 84);
          *(_QWORD *)(v45 + 2392) = *(_QWORD *)(v45 + 2392) - *(_QWORD *)(v12 + 2384) + *(_QWORD *)(v12 + 2376);
          *(_DWORD *)(v12 + 2384) = 0;
          *(_DWORD *)(v12 + 2388) = 0;
          v20 &= 0xEFu;
        }
        if ( (v20 & 0x3E) != 0 )
        {
          if ( (v20 & 0x20) != 0 )
          {
            v21 = *(_DWORD *)(a1 + 1084);
            if ( v21 )
            {
              v22 = v54;
              v14 = v55[0];
              v23 = (unsigned __int64 *)(v21 + 8 * (*(unsigned __int8 *)(v12 + 2986) + 2 * PoGetFrequencyBucket(v12)));
              v24 = *v23 + __PAIR64__(v54, v55[0]);
              __dmb(0xBu);
              do
                v25 = __ldrexd(v23);
              while ( __strexd(v24, v23) );
              __dmb(0xBu);
            }
            else
            {
              v22 = v54;
            }
            v20 &= 0xDFu;
          }
          else
          {
            v22 = v54;
          }
          if ( (v20 & 0x3E) != 0 )
          {
            v26 = *(_DWORD *)(a1 + 68);
            if ( v26 )
            {
              for ( i = v26 + *(_DWORD *)(v12 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += __PAIR64__(v22, v14);
            }
            if ( (*(_BYTE *)(a1 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v12 + 2360) + 260) & *(_DWORD *)(a1 + 356)) != *(_DWORD *)(*(_DWORD *)(v12 + 2360) + 260) )
            {
              *(_QWORD *)(v12 + 2368) += __PAIR64__(v22, v14);
            }
            if ( *(_DWORD *)(a1 + 236) )
              KiEndCounterAccumulation(a1);
          }
        }
      }
      v28 = ReadTimeStampCounter();
      v30 = v29;
      v31 = v28;
      v32 = __PAIR64__(v30, v28) - *(_QWORD *)(v12 + 2376);
      v55[0] = v28;
      __dmb(0xBu);
      v33 = (unsigned __int64 *)(v12 + 2744);
      do
        v34 = __ldrexd(v33);
      while ( __strexd(v34 + v32, v33) );
      __dmb(0xBu);
      if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
      {
        v35 = __PAIR64__(v30, v28) - *(_QWORD *)(v12 + 2376);
        v36 = (unsigned __int64 *)(v12 + 8 * (*(unsigned __int8 *)(v12 + 2986) + 2 * (PoGetFrequencyBucket(v12) + 1144)));
        v37 = *v36;
        __dmb(0xBu);
        do
          v38 = __ldrexd(v36);
        while ( __strexd(v37 + v35, v36) );
        __dmb(0xBu);
        v31 = v55[0];
      }
      *(_DWORD *)(v12 + 2376) = v31;
      *(_DWORD *)(v12 + 2380) = v30;
      if ( (*(_BYTE *)(a1 + 2) & 0x10) != 0 )
      {
        *(_DWORD *)(v12 + 2384) = v31;
        *(_DWORD *)(v12 + 2388) = v30;
      }
      if ( (*(_BYTE *)(a1 + 2) & 2) != 0 )
        KiBeginCounterAccumulation(a1, 0);
      *(_BYTE *)(v12 + 16) = 0;
      __enable_irq();
      v39 = (unsigned int *)(v12 + 24);
      while ( 1 )
      {
        do
          v40 = __ldrex(v39);
        while ( __strex(1u, v39) );
        __dmb(0xBu);
        if ( !v40 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v39 );
      }
      __dmb(0xBu);
      v41 = (unsigned __int8 *)(a1 + 2);
      do
        v42 = __ldrex(v41);
      while ( __strex(v42 & 0xFB, v41) );
      __dmb(0xBu);
      *(_DWORD *)(a1 + 68) = 0;
      result = (unsigned int *)KeUpdateThreadSchedulingProperties(a1, 2, v12);
      __dmb(0xBu);
      *v39 = 0;
    }
  }
  else
  {
    v2 = 0;
    v3 = (unsigned int *)(a1 + 44);
    while ( 1 )
    {
      do
        v4 = __ldrex(v3);
      while ( __strex(1u, v3) );
      __dmb(0xBu);
      if ( !v4 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v3 );
    }
    v5 = KiAcquireThreadStateLock(a1, v55, &v54);
    v6 = (_DWORD *)v55[0];
    v7 = v5;
    if ( (*(_DWORD *)(a1 + 76) & 0x2000) != 0 )
    {
      KiRemoveThreadFromScbQueue(v55[0], *(_DWORD *)(a1 + 824), a1, *(char *)(a1 + 123));
      v2 = 1;
    }
    __dmb(0xBu);
    v8 = (unsigned __int8 *)(a1 + 2);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 & 0xFB, v8) );
    __dmb(0xBu);
    *(_DWORD *)(a1 + 68) = 0;
    if ( (*(_DWORD *)(a1 + 80) & 0x400) != 0 )
    {
      __dmb(0xBu);
      v43 = (unsigned __int8 *)(a1 + 81);
      do
        v44 = __ldrex(v43);
      while ( __strex(v44 & 0xFB, v43) );
      __dmb(0xBu);
    }
    result = (unsigned int *)KeUpdateThreadSchedulingProperties(a1, v7, v6);
    if ( v2 )
    {
      v46 = *(char *)(a1 + 123);
      v47 = v6[864];
      if ( (*(_DWORD *)(a1 + 80) & 0x1000) != 0 && v47 && (*(_DWORD *)(a1 + 356) & v47) == v47 )
      {
        v48 = (unsigned int *)v6[865];
        result = &v48[2 * v46 + 2];
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
        v50 = (unsigned int **)result[1];
        v51 = a1 + 144;
        *(_DWORD *)(a1 + 144) = result;
        *(_DWORD *)(a1 + 148) = v50;
        if ( *v50 != result )
          __fastfail(3u);
        *v50 = (unsigned int *)v51;
        result[1] = v51;
        v48[1] |= 1 << v46;
        *(_DWORD *)(a1 + 328) |= 0x80000000;
        __dmb(0xBu);
        *v48 = 0;
      }
      else
      {
        v52 = &v6[2 * v46 + 512];
        result = (unsigned int *)v52[1];
        v53 = a1 + 144;
        *(_DWORD *)(a1 + 144) = v52;
        *(_DWORD *)(a1 + 148) = result;
        if ( (_DWORD *)*result != v52 )
          __fastfail(3u);
        *result = v53;
        v52[1] = v53;
        v6[483] |= 1 << v46;
      }
    }
    if ( v6 )
    {
      __dmb(0xBu);
      v6[6] = 0;
    }
    v11 = (_DWORD *)v54;
    if ( v54 )
    {
      __dmb(0xBu);
      *v11 = 0;
    }
    __dmb(0xBu);
    *v3 = 0;
  }
  return result;
}
