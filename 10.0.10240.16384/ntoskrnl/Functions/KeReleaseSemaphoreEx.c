// KeReleaseSemaphoreEx 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeReleaseSemaphoreEx(int a1, int a2, int a3, int a4, char a5)
{
  int v7; // r0
  int v8; // r10
  int v9; // r8
  unsigned int v10; // r4
  int v11; // r7
  int v12; // r2
  _QWORD *v13; // r4
  int v14; // r9
  int v15; // r1 OVERLAPPED
  _DWORD *v16; // r2 OVERLAPPED
  int v17; // r3
  int v18; // r3
  unsigned int v19; // r1
  int v20; // r9
  int v22; // r5
  unsigned __int8 *v23; // r3
  unsigned int v24; // r2
  __int64 v25; // r0
  unsigned __int64 *v26; // r4
  __int64 v27; // kr18_8
  unsigned __int64 v28; // kr20_8
  unsigned __int64 v29; // r2
  unsigned int v30; // r4
  __int64 v31; // r2
  char v32; // r6
  int v33; // r4
  unsigned __int64 *v34; // r4
  unsigned __int64 v35; // kr28_8
  unsigned __int64 v36; // kr30_8
  unsigned __int64 v37; // r0
  unsigned __int64 v38; // kr38_8
  unsigned __int64 *v39; // r3
  unsigned __int64 v40; // kr40_8
  unsigned __int64 v41; // kr48_8
  unsigned __int64 *v42; // r4
  unsigned __int64 v43; // kr50_8
  unsigned __int64 v44; // kr60_8
  int v45; // r2
  unsigned __int64 *v46; // r3
  unsigned __int64 v47; // kr68_8
  unsigned __int64 *v48; // r4
  unsigned __int64 v49; // kr70_8
  unsigned __int64 v50; // r2
  unsigned __int64 *v51; // r3
  unsigned __int64 v52; // kr78_8
  int v53; // r0
  int v54; // r0
  int v55; // lr
  int v56; // r1
  unsigned int v57; // r2
  unsigned int v58; // r1
  int v59; // r3
  int v60; // r2
  int *v61; // r1
  int v62; // r1
  int i; // r1
  unsigned int v64; // r2
  unsigned int v65; // r2
  unsigned int v66; // r1
  unsigned int v67; // r1
  int v68; // r4
  unsigned int v69; // r3
  bool v70; // cf
  unsigned int v71; // r1
  int v72; // r3
  int v73; // r0
  int v74; // r2
  unsigned int v75; // [sp+8h] [bp-48h]
  int v76; // [sp+8h] [bp-48h]
  unsigned int v77; // [sp+Ch] [bp-44h]
  unsigned int v78; // [sp+10h] [bp-40h]

  v7 = KfRaiseIrql(2);
  v8 = v7;
  v9 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  do
    v10 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v10 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v10 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)a1 & 0x80) != 0 );
      do
        v64 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v64 | 0x80, (unsigned __int8 *)a1) );
      __dmb(0xBu);
    }
    while ( v64 >> 7 );
  }
  v11 = *(_DWORD *)(a1 + 4);
  v12 = v11 + a3;
  if ( v11 + a3 > *(_DWORD *)(a1 + 16) || v12 < v11 )
  {
    __dmb(0xBu);
    do
      v66 = __ldrex((unsigned int *)a1);
    while ( __strex(v66 & 0xFFFFFF7F, (unsigned int *)a1) );
    KfLowerIrql(v7);
    RtlRaiseStatus(-1073741753);
  }
  *(_DWORD *)(a1 + 4) = v12;
  if ( !v11 )
  {
    v13 = *(_QWORD **)(a1 + 8);
    while ( v13 != (_QWORD *)(a1 + 8) )
    {
      v14 = (int)v13;
      *(_QWORD *)&v15 = *v13;
      v13 = *(_QWORD **)v13;
      if ( *(_DWORD *)(v15 + 4) != v14 || *v16 != v14 )
        __fastfail(3u);
      *v16 = v15;
      *(_DWORD *)(v15 + 4) = v16;
      v17 = *(unsigned __int8 *)(v14 + 8);
      if ( v17 == 1 )
      {
        if ( KiTryUnwaitThread(v9, v14, *(unsigned __int16 *)(v14 + 10), 0) )
        {
          v18 = *(_DWORD *)(a1 + 4) - 1;
          *(_DWORD *)(a1 + 4) = v18;
          if ( !v18 )
            break;
        }
        continue;
      }
      if ( v17 != 2 )
      {
        KiTryUnwaitThread(v9, v14, 256, 0);
        continue;
      }
      *(_BYTE *)(v14 + 9) = 5;
      v53 = *(_DWORD *)(v14 + 12);
      *(_DWORD *)v14 = 0;
      v76 = v53;
      KfRaiseIrql(2);
      v54 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
      v55 = *(_DWORD *)(v54 + 4);
      if ( (dword_682604 & 0x1000000) != 0 )
        return sub_50C298();
      v56 = v76;
      do
        v57 = __ldrex((unsigned __int8 *)v76);
      while ( __strex(v57 | 0x80, (unsigned __int8 *)v76) );
      __dmb(0xBu);
      if ( v57 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v76 & 0x80) != 0 );
          do
            v65 = __ldrex((unsigned __int8 *)v76);
          while ( __strex(v65 | 0x80, (unsigned __int8 *)v76) );
          __dmb(0xBu);
        }
        while ( v65 >> 7 );
      }
      if ( *(_DWORD *)(v76 + 12) != v76 + 8
        && *(_DWORD *)(v76 + 24) < *(_DWORD *)(v76 + 28)
        && (*(_DWORD *)(v55 + 152) != v76 || *(_BYTE *)(v55 + 395) != 15) )
      {
        if ( KiWakeQueueWaiter(v54, v76, v14) )
          goto LABEL_71;
        v56 = v76;
      }
      v60 = v56 + 16;
      ++*(_DWORD *)(v56 + 4);
      v61 = *(int **)(v56 + 20);
      *(_DWORD *)v14 = v60;
      *(_DWORD *)(v14 + 4) = v61;
      if ( *v61 != v60 )
        __fastfail(3u);
      *v61 = v14;
      *(_DWORD *)(v60 + 4) = v14;
LABEL_71:
      __dmb(0xBu);
      do
        v58 = __ldrex((unsigned int *)v76);
      while ( __strex(v58 & 0xFFFFFF7F, (unsigned int *)v76) );
      v59 = *(_DWORD *)(a1 + 4) - 1;
      *(_DWORD *)(a1 + 4) = v59;
      if ( !v59 )
        break;
    }
  }
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)a1);
  while ( __strex(v19 & 0xFFFFFF7F, (unsigned int *)a1) );
  if ( (a5 & 1) != 0 )
  {
    v20 = 1;
  }
  else
  {
    v20 = 0;
    if ( (a5 & 2) != 0 )
    {
      v22 = *(_DWORD *)(v9 + 4);
      if ( (*(_DWORD *)(v22 + 80) & 0x10) != 0 )
      {
        __dmb(0xBu);
        v23 = (unsigned __int8 *)(v22 + 80);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 & 0xEF, v23) );
        __dmb(0xBu);
        __disable_irq();
        *(_BYTE *)(v9 + 16) = 1;
        LODWORD(v25) = ReadTimeStampCounter();
        v26 = (unsigned __int64 *)(v22 + 48);
        v27 = v25 - *(_QWORD *)(v9 + 2376);
        v28 = v27 + *(_QWORD *)(v22 + 48);
        v77 = v25 - *(_DWORD *)(v9 + 2376) + *(_DWORD *)(v22 + 48);
        __dmb(0xBu);
        do
          v29 = __ldrexd(v26);
        while ( __strexd(v28, v26) );
        __dmb(0xBu);
        v30 = v27;
        v31 = v27 + *(unsigned int *)(v22 + 56);
        if ( HIDWORD(v31) )
          LODWORD(v31) = -1;
        *(_QWORD *)(v9 + 2376) = v25;
        v32 = *(_BYTE *)(v22 + 2);
        *(_DWORD *)(v22 + 56) = v31;
        if ( (v32 & 0x3E) != 0 )
        {
          if ( (v32 & 0x10) != 0 )
          {
            v67 = *(_DWORD *)(v9 + 2376);
            v68 = v9 + 8 * *(unsigned __int8 *)(v22 + 84);
            v69 = *(_DWORD *)(v9 + 2384);
            v32 &= 0xEFu;
            v70 = v67 >= v69;
            v71 = v67 - v69;
            v72 = *(_DWORD *)(v68 + 2392);
            v73 = *(_DWORD *)(v9 + 2380) - (*(_DWORD *)(v9 + 2388) + !v70);
            v74 = *(_DWORD *)(v68 + 2396);
            *(_DWORD *)(v68 + 2392) = v72 + v71;
            *(_DWORD *)(v68 + 2396) = v73 + __CFADD__(v72, v71) + v74;
            v30 = v27;
            *(_DWORD *)(v9 + 2384) = 0;
            *(_DWORD *)(v9 + 2388) = 0;
          }
          if ( (v32 & 0x3E) != 0 )
          {
            if ( (v32 & 0x20) != 0 )
            {
              v33 = *(_DWORD *)(v22 + 1084);
              if ( v33 )
              {
                v34 = (unsigned __int64 *)(v33 + 8 * (*(unsigned __int8 *)(v9 + 2986) + 2 * PoGetFrequencyBucket(v9)));
                v35 = *v34 + v27;
                __dmb(0xBu);
                do
                  v36 = __ldrexd(v34);
                while ( __strexd(v35, v34) );
                __dmb(0xBu);
              }
              v30 = v27;
              v32 &= 0xDFu;
            }
            if ( (v32 & 0x3E) != 0 )
            {
              v62 = *(_DWORD *)(v22 + 68);
              if ( v62 )
              {
                for ( i = v62 + *(_DWORD *)(v9 + 2352); i; i = *(_DWORD *)(i + 236) )
                  *(_QWORD *)i += __PAIR64__(HIDWORD(v27), v30);
              }
              if ( (*(_BYTE *)(v22 + 2) & 8) != 0
                && (*(_DWORD *)(*(_DWORD *)(v9 + 2360) + 260) & *(_DWORD *)(v22 + 356)) != *(_DWORD *)(*(_DWORD *)(v9 + 2360) + 260) )
              {
                *(_QWORD *)(v9 + 2368) += __PAIR64__(HIDWORD(v27), v30);
              }
              if ( *(_DWORD *)(v22 + 236) )
                KiEndCounterAccumulation(v22);
            }
          }
        }
        LODWORD(v37) = ReadTimeStampCounter();
        v78 = HIDWORD(v37);
        v38 = v37 - *(_QWORD *)(v9 + 2376);
        v75 = v37;
        __dmb(0xBu);
        v39 = (unsigned __int64 *)(v9 + 2744);
        do
          v40 = __ldrexd(v39);
        while ( __strexd(v40 + v38, v39) );
        __dmb(0xBu);
        if ( (*(_BYTE *)(v22 + 2) & 0x20) != 0 )
        {
          v41 = v37 - *(_QWORD *)(v9 + 2376);
          v42 = (unsigned __int64 *)(v9 + 8 * (*(unsigned __int8 *)(v9 + 2986) + 2 * (PoGetFrequencyBucket(v9) + 1144)));
          v43 = *v42;
          __dmb(0xBu);
          do
            v44 = __ldrexd(v42);
          while ( __strexd(v43 + v41, v42) );
          __dmb(0xBu);
          v37 = __PAIR64__(v78, v75);
        }
        *(_QWORD *)(v9 + 2376) = v37;
        if ( (*(_BYTE *)(v22 + 2) & 0x10) != 0 )
          *(_QWORD *)(v9 + 2384) = v37;
        if ( (*(_BYTE *)(v22 + 2) & 2) != 0 )
          KiBeginCounterAccumulation(v22, 0);
        *(_BYTE *)(v9 + 16) = 0;
        __enable_irq();
        v45 = *(_DWORD *)(v9 + 1540);
        if ( v45 )
        {
          __dmb(0xBu);
          v46 = (unsigned __int64 *)(v22 + 24);
          do
            v47 = __ldrexd(v46);
          while ( !v47 && __strexd(0i64, v46) );
          __dmb(0xBu);
          if ( v47 > __PAIR64__(HIDWORD(v28), v77) )
          {
            __dmb(0xBu);
            v48 = (unsigned __int64 *)(v45 - 120);
            do
              v49 = __ldrexd(v48);
            while ( !v49 && __strexd(0i64, v48) );
            __dmb(0xBu);
            do
              v50 = __ldrexd(v48);
            while ( __strexd(v49 - __PAIR64__(HIDWORD(v28), v77) + v47, v48) );
            __dmb(0xBu);
          }
        }
        KiRemoveBoostThread(v9, v22);
        __dmb(0xBu);
        v51 = (unsigned __int64 *)(v22 + 24);
        do
          v52 = __ldrexd(v51);
        while ( __strexd(__PAIR64__(HIDWORD(v28), v77), v51) );
        __dmb(0xBu);
        v20 = 0;
      }
    }
  }
  KiExitDispatcher(v9, v20, 1, a2, v8);
  return v11;
}
