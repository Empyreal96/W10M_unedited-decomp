// KiQueueReadyThread 
 
int __fastcall KiQueueReadyThread(int a1, int a2)
{
  int v2; // r10
  int v3; // r5
  int v5; // r1
  unsigned int v6; // r4
  unsigned int v7; // r6
  unsigned __int64 v8; // kr08_8
  int result; // r0
  int v10; // r6
  int v11; // r0
  int v12; // r2
  int v13; // r1
  int v14; // r2
  unsigned int *v15; // r4
  unsigned int *v16; // r1
  unsigned int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r6
  int v20; // r2
  unsigned __int8 *v21; // r3
  unsigned int v22; // r2
  int v23; // r2
  int v24; // r0
  int v25; // r2
  int v26; // r3
  int v27; // r4
  int v28; // r1
  int *v29; // r2
  unsigned int **v30; // r6
  unsigned int *v31; // r1
  unsigned int v32; // r2
  int v33; // r10
  unsigned int v34; // r3
  int v35; // r1
  unsigned __int64 v36; // kr18_8
  int v37; // r3
  int v38; // r1
  int *v39; // r4
  int v40; // r2
  int v41; // r1
  BOOL v42; // r4
  unsigned __int8 *v43; // r3
  unsigned int v44; // r2
  unsigned int v45; // r1
  unsigned int i; // r2
  int v47; // r1
  int v48; // r3
  unsigned __int8 *v49; // r3
  unsigned int v50; // r2
  int v51; // r1
  signed int v52; // r3
  unsigned __int8 *v53; // r3
  unsigned int v54; // r2
  _DWORD *v55; // r3
  unsigned __int8 *v56; // r3
  unsigned int v57; // r2
  unsigned int v58; // r2
  unsigned int v59; // r1
  unsigned int v60; // r3
  int v61; // r9
  int v62; // r3
  int v63; // r0
  int v64; // r9
  int v65; // r3
  int v66; // r3
  __int64 v67; // r0
  __int64 v68; // kr00_8
  int v69; // r3
  int v70; // r2
  int v71; // [sp+0h] [bp-30h]
  int v72; // [sp+8h] [bp-28h]

  v2 = *(unsigned __int8 *)(a2 + 349);
  v3 = a2;
  v72 = v2;
  v5 = a2 + 48;
  v6 = *(_DWORD *)(v5 + 4);
  v7 = *(_DWORD *)v5;
  do
    v8 = __ldrexd((unsigned __int64 *)v5);
  while ( __PAIR64__(v8, HIDWORD(v8)) == __PAIR64__(v7, v6) && __strexd(__PAIR64__(v6, v7), (unsigned __int64 *)v5) );
  if ( __PAIR64__(v7, v6) != __PAIR64__(v8, HIDWORD(v8)) )
    return sub_50BE94();
  if ( *(_DWORD *)(v3 + 352) != KiCpuSetSequence && (*(_DWORD *)(v3 + 76) & 8) == 0
    || __PAIR64__(v6, v7) >= *(_QWORD *)(v3 + 24) )
  {
    v31 = (unsigned int *)(v3 + 44);
    do
      v32 = __ldrex(v31);
    while ( __strex(1u, v31) );
    __dmb(0xBu);
    if ( v32 )
    {
      v53 = (unsigned __int8 *)(v3 + 81);
      do
        v54 = __ldrex(v53);
      while ( __strex(v54 | 8, v53) );
    }
    else
    {
      if ( __PAIR64__(v6, v7) >= *(_QWORD *)(v3 + 24) )
      {
        v33 = *(char *)(v3 + 123);
        if ( v33 < 16 )
        {
          v33 = (char)(-(*(_BYTE *)(v3 + 348) & 0xF) - (*(_BYTE *)(v3 + 348) >> 4) + v33 - 1);
          if ( v33 < *(char *)(v3 + 347) )
            v33 = *(char *)(v3 + 347);
          if ( *(_BYTE *)(v3 + 348) )
          {
            if ( (*(_BYTE *)(v3 + 348) & 0xF) != 0 )
              *(_DWORD *)(v3 + 812) = KeTickCount;
            *(_BYTE *)(v3 + 348) = 0;
          }
          v34 = *(_DWORD *)(v3 + 800);
          if ( v34 )
          {
            v52 = 31 - __clz(v34);
            if ( v33 < v52 )
              v33 = (char)v52;
          }
        }
        KiAbProcessThreadPriorityModification(v3, v33, 1);
        v35 = *(unsigned __int8 *)(v3 + 403);
        *(_BYTE *)(v3 + 123) = v33;
        v36 = __PAIR64__(v6, KiCyclesPerClockQuantum * v35) + v7;
        if ( (*(_DWORD *)(v3 + 80) & 0x10) != 0 )
        {
          __dmb(0xBu);
          v49 = (unsigned __int8 *)(v3 + 80);
          do
            v50 = __ldrex(v49);
          while ( __strex(v50 & 0xEF, v49) );
          __dmb(0xBu);
        }
        v37 = *(_DWORD *)(v3 + 336);
        *(_QWORD *)(v3 + 24) = v36;
        if ( *(_BYTE *)(v37 + 606) == 2 && *(char *)(v3 + 123) < 16 && (*(_DWORD *)(v3 + 80) & 2) == 0 )
          KiScheduleNextForegroundBoost(v3);
        v2 = 0;
        v72 = 0;
      }
      if ( *(_DWORD *)(v3 + 352) != KiCpuSetSequence
        && (*(_DWORD *)(v3 + 76) & 8) == 0
        && KiComputeThreadAffinity(v3)
        && (*(unsigned __int8 *)(a1 + 1052) != *(unsigned __int16 *)(v3 + 360)
         || (*(_DWORD *)(v3 + 356) & *(_DWORD *)(a1 + 1048)) == 0) )
      {
        __dmb(0xBu);
        v56 = (unsigned __int8 *)(v3 + 81);
        do
          v57 = __ldrex(v56);
        while ( __strex(v57 | 8, v56) );
        __dmb(0xBu);
      }
      __dmb(0xBu);
      *(_DWORD *)(v3 + 44) = 0;
    }
  }
  v10 = *(_DWORD *)(v3 + 68);
  v11 = v10;
  if ( v10 )
    v10 += *(_DWORD *)(a1 + 2352);
  if ( v10 )
  {
    while ( 1 )
    {
      if ( (*(_BYTE *)(v10 + 92) & 4) != 0 )
      {
        if ( (*(_BYTE *)(v10 + 92) & 0x10) != 0
          || (*(_BYTE *)(v10 + 92) & 2) != 0
          || *(_QWORD *)v10 <= *(_QWORD *)(v10 + 16) )
        {
          if ( *(_QWORD *)v10 > *(_QWORD *)(v10 + 24) )
            KiRecomputeGroupSchedulingRank(v11, (unsigned int *)v10, a1);
        }
        else
        {
          *(_BYTE *)(v10 + 92) |= 2u;
          if ( *(__int64 *)(v11 + 32) > 0 )
            v11 = KiChargeSchedulingGroupCycleTime();
          if ( (*(_BYTE *)(v10 + 92) & 1) != 0 )
          {
            v64 = v10;
            do
            {
              v65 = *(_DWORD *)(v64 + 236);
              if ( v65 )
                v66 = v65 + 228;
              else
                v66 = a1 + 1976;
              v71 = v66;
              v67 = KeQueryInterruptTime(v11);
              v69 = *(_DWORD *)(v64 + 56);
              v68 = v67 - *(_QWORD *)(v64 + 64);
              v70 = *(_DWORD *)(v64 + 60);
              *(_DWORD *)(v64 + 56) = v69 + v68;
              *(_BYTE *)(v64 + 92) &= 0xFEu;
              *(_DWORD *)(v64 + 60) = HIDWORD(v68) + __CFADD__(v69, (_DWORD)v68) + v70;
              v11 = RtlRbRemoveNode(v71, v64 + 80);
              v64 = *(_DWORD *)(v64 + 236);
            }
            while ( v64 && (*(_BYTE *)(v64 + 92) & 1) != 0 && !*(_DWORD *)(v64 + 228) && !*(_WORD *)(v64 + 94) );
          }
        }
      }
      else
      {
        if ( *(_QWORD *)v10 >= *(_QWORD *)(v10 + 8) )
        {
          KiComputeGroupSchedulingRank(v11, a1, v10);
          goto LABEL_32;
        }
        if ( (*(_BYTE *)(v10 + 92) & 1) != 0 )
        {
          v45 = v10 + 80;
          i = *(_DWORD *)(v10 + 84);
          if ( i )
          {
            v55 = *(_DWORD **)i;
            if ( *(_DWORD *)i )
            {
              do
              {
                i = (unsigned int)v55;
                v55 = (_DWORD *)*v55;
              }
              while ( v55 );
            }
          }
          else
          {
            for ( i = *(_DWORD *)(v10 + 88) & 0xFFFFFFFC; i; i = *(_DWORD *)(i + 8) & 0xFFFFFFFC )
            {
              if ( *(_DWORD *)i == v45 )
                break;
              v45 = i;
            }
          }
          if ( i )
          {
            v47 = *(_DWORD *)(v10 + 96);
            v48 = v47 - *(_DWORD *)(i + 16);
            if ( v48 )
            {
LABEL_96:
              if ( v48 <= 0 )
                goto LABEL_32;
            }
            else
            {
              if ( *(_WORD *)(v10 + 94) )
              {
                v58 = *(unsigned __int16 *)(i + 14);
                v59 = 31 - __clz(*(unsigned __int16 *)(v10 + 94));
                v60 = 0;
                if ( v58 )
                  v60 = 31 - __clz(v58);
                v48 = v60 - v59;
                goto LABEL_96;
              }
              if ( !v47 && *(_QWORD *)v10 <= *(_QWORD *)(i - 80) )
                goto LABEL_32;
            }
            v61 = v10;
            do
            {
              v62 = *(_DWORD *)(v61 + 236);
              if ( v62 )
                v63 = v62 + 228;
              else
                v63 = a1 + 1976;
              *(_BYTE *)(v61 + 92) &= 0xFEu;
              RtlRbRemoveNode(v63, v61 + 80);
              v61 = *(_DWORD *)(v61 + 236);
            }
            while ( v61 && (*(_BYTE *)(v61 + 92) & 1) != 0 && !*(_DWORD *)(v61 + 228) && !*(_WORD *)(v61 + 94) );
            KiInsertSchedulingGroupQueue(a1, v10, 0);
            goto LABEL_32;
          }
        }
      }
LABEL_32:
      v10 = *(_DWORD *)(v10 + 236);
      if ( !v10 )
      {
        v2 = v72;
        v3 = a2;
        v20 = *(_DWORD *)(a2 + 80);
        if ( (v20 & 0x100) == 0
          && *(char *)(a2 + 123) < 16
          && (*(_DWORD *)(a2 + 308) || *(_BYTE *)(a2 + 134) == 1)
          && (v20 & 0x600) == 0 )
        {
          __dmb(0xBu);
          v21 = (unsigned __int8 *)(a2 + 81);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 | 4, v21) );
          __dmb(0xBu);
        }
        break;
      }
      v11 = v10 - *(_DWORD *)(a1 + 2352);
    }
  }
  v12 = 0;
  if ( *(char *)(v3 + 123) >= 16 )
  {
    v41 = *(_DWORD *)(v3 + 68);
    if ( v41 && (v51 = v41 + *(_DWORD *)(a1 + 2352)) != 0 )
    {
      while ( (*(_BYTE *)(v51 + 92) & 2) == 0 )
      {
        v51 = *(_DWORD *)(v51 + 236);
        if ( !v51 )
          goto LABEL_80;
      }
    }
    else
    {
LABEL_80:
      v12 = **(_DWORD **)(a1 + 2360) & *(_DWORD *)(v3 + 356);
    }
  }
  if ( (*(_DWORD *)(v3 + 80) & 0x800) != 0 || v12 )
  {
    v42 = *(_DWORD *)(a1 + 8) != 0;
    *(_BYTE *)(v3 + 132) = 7;
    __dmb(0xBu);
    *(_DWORD *)(a1 + 24) = 0;
    v43 = (unsigned __int8 *)(v3 + 81);
    do
      v44 = __ldrex(v43);
    while ( __strex(v44 & 0xF7, v43) );
    *(_BYTE *)(v3 + 349) = v2;
    result = KiDeferredReadyThread(a1, v3);
    if ( !v42 && *(_DWORD *)(a1 + 4) != *(_DWORD *)(a1 + 12) && *(_DWORD *)(a1 + 8) )
      result = HalRequestSoftwareInterrupt(2);
  }
  else
  {
    *(_BYTE *)(v3 + 349) = 0;
    *(_DWORD *)(v3 + 304) = KeTickCount;
    v13 = *(_DWORD *)(v3 + 68);
    if ( v13 )
      v13 += *(_DWORD *)(a1 + 2352);
    __dmb(0xBu);
    *(_BYTE *)(v3 + 132) = 1;
    if ( !v13
      || (v23 = *(_DWORD *)(v3 + 80), (v23 & 0x600) != 0)
      || (v24 = v13, *(char *)(v3 + 123) >= 16)
      || (v23 & 0x100) != 0 )
    {
LABEL_17:
      result = *(char *)(v3 + 123);
      v14 = *(_DWORD *)(a1 + 3456);
      if ( (*(_DWORD *)(v3 + 80) & 0x1000) != 0 && v14 && (*(_DWORD *)(v3 + 356) & v14) == v14 )
      {
        v15 = *(unsigned int **)(a1 + 3460);
        v16 = &v15[2 * result + 2];
        while ( 1 )
        {
          do
            v17 = __ldrex(v15);
          while ( __strex(1u, v15) );
          __dmb(0xBu);
          if ( !v17 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v15 );
        }
        v18 = (unsigned int *)(v3 + 144);
        if ( v2 )
        {
          v19 = *v16;
          *v18 = *v16;
          *(_DWORD *)(v3 + 148) = v16;
          if ( *(unsigned int **)(v19 + 4) != v16 )
            __fastfail(3u);
          *(_DWORD *)(v19 + 4) = v18;
          *v16 = (unsigned int)v18;
          *(_BYTE *)(a1 + (result >> 3) + 1936) &= ~(1 << (result & 7));
        }
        else
        {
          v30 = (unsigned int **)v16[1];
          *v18 = (unsigned int)v16;
          *(_DWORD *)(v3 + 148) = v30;
          if ( *v30 != v16 )
            __fastfail(3u);
          *v30 = v18;
          v16[1] = (unsigned int)v18;
        }
        v15[1] |= 1 << result;
        *(_DWORD *)(v3 + 328) |= 0x80000000;
        __dmb(0xBu);
        *v15 = 0;
      }
      else
      {
        v26 = result + 256;
        if ( v2 )
        {
          v27 = *(_DWORD *)(a1 + 8 * v26);
          v28 = v3 + 144;
          v29 = (int *)(a1 + 8 * v26);
          *(_DWORD *)(v3 + 144) = v27;
          *(_DWORD *)(v3 + 148) = v29;
          if ( *(int **)(v27 + 4) != v29 )
            __fastfail(3u);
          *(_DWORD *)(v27 + 4) = v28;
          *v29 = v28;
          *(_BYTE *)(a1 + (result >> 3) + 1936) |= 1 << (result & 7);
        }
        else
        {
          v38 = a1 + 8 * v26;
          v39 = *(int **)(v38 + 4);
          v40 = v3 + 144;
          *(_DWORD *)(v3 + 144) = v38;
          *(_DWORD *)(v3 + 148) = v39;
          if ( *v39 != v38 )
            __fastfail(3u);
          *v39 = v40;
          *(_DWORD *)(v38 + 4) = v40;
        }
        *(_DWORD *)(a1 + 1932) |= 1 << result;
      }
      __dmb(0xBu);
      *(_DWORD *)(a1 + 24) = 0;
    }
    else
    {
      v25 = v13;
      while ( (*(_BYTE *)(v25 + 92) & 2) == 0 )
      {
        v25 = *(_DWORD *)(v25 + 236);
        if ( !v25 )
        {
          while ( !*(_DWORD *)(v24 + 96) )
          {
            v24 = *(_DWORD *)(v24 + 236);
            if ( !v24 )
              goto LABEL_17;
          }
          break;
        }
      }
      result = KiAddThreadToScbQueue(a1, v13, v3, v2);
      __dmb(0xBu);
      *(_DWORD *)(a1 + 24) = 0;
    }
  }
  return result;
}
