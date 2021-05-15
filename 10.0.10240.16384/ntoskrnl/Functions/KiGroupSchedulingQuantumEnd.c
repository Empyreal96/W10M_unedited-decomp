// KiGroupSchedulingQuantumEnd 
 
int __fastcall KiGroupSchedulingQuantumEnd(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // lr
  int v6; // r0
  int v7; // r5
  int result; // r0
  unsigned int *v9; // r10
  unsigned int v10; // r2
  int v11; // r9
  int v12; // r2
  int v13; // r5
  int v14; // r5
  int v15; // r10
  int v16; // r1
  unsigned int *v17; // r10
  int v18; // r4
  unsigned int v19; // r2
  int v20; // r3
  int v21; // r5
  char v22; // r2
  unsigned int i; // r1
  int v24; // r3
  int v25; // r2
  int v26; // r1
  char v27; // r3
  int v28; // r5
  char v29; // r2
  int v30; // r5
  _DWORD *v31; // r3
  unsigned int v32; // r1
  unsigned int v33; // r3
  unsigned __int64 v34; // kr00_8
  int v35; // r4
  int v36; // r3
  int v37; // r0
  int v38; // r7
  int v39; // r3
  int v40; // r3
  __int64 v41; // r0
  int v42; // r4
  unsigned __int64 v43; // kr08_8
  int v44; // r3
  int v45; // r2
  int v46; // r2
  int v47; // r1
  char v48; // r3
  int v49; // r2
  unsigned int *v50; // r5
  unsigned int *v51; // r1
  unsigned int v52; // r2
  unsigned int v53; // r7
  int v54; // r2
  int v55; // r5
  int v56; // r1
  int *v57; // r2
  int v58; // [sp+8h] [bp-48h]
  int v59; // [sp+Ch] [bp-44h]
  int v60; // [sp+10h] [bp-40h]
  int v61; // [sp+14h] [bp-3Ch]
  int v62; // [sp+1Ch] [bp-34h]

  v60 = 0;
  v61 = 0;
  v4 = 0;
  v58 = 0;
  v6 = dword_690384;
  __dmb(0xBu);
  v7 = KeTickCount;
  __dmb(0xBu);
  if ( v6 != dword_690388 )
    return sub_52B8FC();
  v9 = (unsigned int *)(a1 + 24);
  while ( 1 )
  {
    do
      v10 = __ldrex(v9);
    while ( __strex(1u, v9) );
    __dmb(0xBu);
    if ( !v10 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v9 );
  }
  v11 = *(_DWORD *)(a1 + 8);
  v12 = 0;
  v59 = 0;
  if ( v11 )
  {
    v12 = *(_DWORD *)(v11 + 68);
    v59 = v12;
    if ( v12 )
    {
      v12 += *(_DWORD *)(a1 + 2352);
      v59 = v12;
    }
  }
  if ( __PAIR64__(v6, v7) > *(_QWORD *)(a1 + 2408) )
    return KiGroupSchedulingGenerationEnd(a1, *(_DWORD *)(a1 + 2412), v7, v6, 0);
  v13 = *(_DWORD *)(a2 + 68);
  result = v13;
  if ( v13 )
  {
    v14 = v13 + *(_DWORD *)(a1 + 2352);
    if ( v14 )
    {
      v15 = a3;
      while ( 1 )
      {
        if ( (*(_BYTE *)(v14 + 92) & 4) != 0 )
        {
          if ( (*(_BYTE *)(v14 + 92) & 0x10) == 0
            && (*(_BYTE *)(v14 + 92) & 2) == 0
            && *(_QWORD *)v14 > *(_QWORD *)(v14 + 16) )
          {
            *(_BYTE *)(v14 + 92) |= 2u;
            if ( *(__int64 *)(result + 32) > 0 )
              result = KiChargeSchedulingGroupCycleTime();
            if ( (*(_BYTE *)(v14 + 92) & 1) != 0 )
            {
              v38 = v14;
              do
              {
                v39 = *(_DWORD *)(v38 + 236);
                if ( v39 )
                  v40 = v39 + 228;
                else
                  v40 = a1 + 1976;
                v62 = v40;
                v41 = KeQueryInterruptTime(result);
                v44 = *(_DWORD *)(v38 + 56);
                v43 = v41 - *(_QWORD *)(v38 + 64);
                HIDWORD(v41) = HIDWORD(v43);
                v42 = v43;
                v45 = *(_DWORD *)(v38 + 60);
                *(_DWORD *)(v38 + 56) = v44 + v42;
                *(_BYTE *)(v38 + 92) &= 0xFEu;
                *(_DWORD *)(v38 + 60) = HIDWORD(v41) + __CFADD__(v44, v42) + v45;
                result = RtlRbRemoveNode(v62, v38 + 80);
                v38 = *(_DWORD *)(v38 + 236);
              }
              while ( v38 && (*(_BYTE *)(v38 + 92) & 1) != 0 && !*(_DWORD *)(v38 + 228) && !*(_WORD *)(v38 + 94) );
            }
LABEL_45:
            v12 = v59;
            v4 = 1;
            v60 = 1;
            v61 = 1;
            if ( v59 == v14 )
              v58 = 1;
LABEL_15:
            v16 = v58;
            goto LABEL_16;
          }
          if ( *(_QWORD *)v14 > *(_QWORD *)(v14 + 24) )
          {
            result = KiRecomputeGroupSchedulingRank(result, (unsigned int *)v14, a1);
            goto LABEL_45;
          }
          v16 = v58;
          v12 = v59;
          if ( v15 )
          {
            v4 = 1;
            v60 = 1;
          }
        }
        else
        {
          if ( *(_QWORD *)v14 < *(_QWORD *)(v14 + 8) )
          {
            if ( (*(_BYTE *)(v14 + 92) & 1) == 0 )
              goto LABEL_15;
            result = v14 + 80;
            i = *(_DWORD *)(v14 + 84);
            if ( i )
            {
              v31 = *(_DWORD **)i;
              if ( *(_DWORD *)i )
              {
                do
                {
                  i = (unsigned int)v31;
                  v31 = (_DWORD *)*v31;
                }
                while ( v31 );
              }
            }
            else
            {
              for ( i = *(_DWORD *)(v14 + 88) & 0xFFFFFFFC; i; i = *(_DWORD *)(i + 8) & 0xFFFFFFFC )
              {
                if ( *(_DWORD *)i == result )
                  break;
                result = i;
              }
            }
            if ( !i )
              goto LABEL_15;
            result = *(_DWORD *)(v14 + 96);
            v24 = result - *(_DWORD *)(i + 16);
            if ( v24 )
              goto LABEL_58;
            if ( *(_WORD *)(v14 + 94) )
            {
              v32 = *(unsigned __int16 *)(i + 14);
              result = 31 - __clz(*(unsigned __int16 *)(v14 + 94));
              v33 = 0;
              if ( v32 )
                v33 = 31 - __clz(v32);
              v24 = v33 - result;
LABEL_58:
              if ( v24 <= 0 )
                goto LABEL_15;
            }
            else if ( !result )
            {
              v34 = *(_QWORD *)(i - 80);
              result = v34;
              if ( *(_QWORD *)v14 <= v34 )
                goto LABEL_15;
            }
            v35 = v14;
            do
            {
              v36 = *(_DWORD *)(v35 + 236);
              if ( v36 )
                v37 = v36 + 228;
              else
                v37 = a1 + 1976;
              *(_BYTE *)(v35 + 92) &= 0xFEu;
              RtlRbRemoveNode(v37, v35 + 80);
              v35 = *(_DWORD *)(v35 + 236);
            }
            while ( v35 && (*(_BYTE *)(v35 + 92) & 1) != 0 && !*(_DWORD *)(v35 + 228) && !*(_WORD *)(v35 + 94) );
            result = KiInsertSchedulingGroupQueue(a1, v14, 0);
            v12 = v59;
            v4 = v60;
            v15 = a3;
            goto LABEL_15;
          }
          result = KiComputeGroupSchedulingRank(result, a1, v14);
          v12 = v59;
          v4 = 1;
          v60 = 1;
          v61 = 1;
          if ( v59 != v14 )
            goto LABEL_15;
          v16 = 1;
          v58 = 1;
        }
LABEL_16:
        v14 = *(_DWORD *)(v14 + 236);
        if ( !v14 )
        {
          v17 = (unsigned int *)(a1 + 24);
          v18 = *(_DWORD *)(a2 + 68);
          if ( v18 )
            v18 += *(_DWORD *)(a1 + 2352);
          if ( !v4 || v11 )
          {
            if ( v61 && v12 && v11 )
            {
              if ( v12 == v18 )
                goto LABEL_74;
              while ( v12 )
              {
                v12 = *(_DWORD *)(v12 + 236);
                if ( v12 == v18 )
                  goto LABEL_74;
              }
              if ( !v18 || v16 )
              {
LABEL_74:
                result = KiChooseLowestRankedThread((_DWORD *)a1, v11, *(char *)(v11 + 123) + 1, *(char *)(v11 + 123));
                v28 = result;
                if ( result )
                {
                  *(_BYTE *)(v11 + 132) = 1;
                  *(_DWORD *)(v11 + 304) = KeTickCount;
                  if ( (*(_BYTE *)(result + 2) & 4) != 0 )
                  {
                    if ( *(char *)(result + 123) < 16
                      && *(_DWORD *)(result + 68)
                      && (v46 = *(_DWORD *)(result + 68)) != 0
                      && (v47 = *(_DWORD *)(a1 + 2352) + v46) != 0
                      && KiGetThreadEffectiveRankNonZero(result, v47, 0) )
                    {
                      v48 = 1;
                    }
                    else
                    {
                      v48 = *(_BYTE *)(v28 + 123);
                    }
                    v29 = v48;
                  }
                  else
                  {
                    v29 = *(_BYTE *)(result + 123);
                  }
                  **(_BYTE **)(a1 + 28) = v29;
                  *(_DWORD *)(a1 + 8) = v28;
                  *(_BYTE *)(v28 + 132) = 3;
                  v30 = *(_DWORD *)(v11 + 68);
                  if ( v30 )
                    v30 += *(_DWORD *)(a1 + 2352);
                  if ( KiGetThreadEffectiveRankNonZero(v11, v30, 1) )
                  {
                    result = KiAddThreadToScbQueue(a1, v30, v11, 1);
                  }
                  else
                  {
                    result = *(char *)(v11 + 123);
                    v49 = *(_DWORD *)(a1 + 3456);
                    if ( (*(_DWORD *)(v11 + 80) & 0x1000) != 0 && v49 && (*(_DWORD *)(v11 + 356) & v49) == v49 )
                    {
                      v50 = *(unsigned int **)(a1 + 3460);
                      v51 = &v50[2 * result + 2];
                      while ( 1 )
                      {
                        do
                          v52 = __ldrex(v50);
                        while ( __strex(1u, v50) );
                        __dmb(0xBu);
                        if ( !v52 )
                          break;
                        do
                        {
                          __dmb(0xAu);
                          __yield();
                        }
                        while ( *v50 );
                      }
                      v53 = *v51;
                      v54 = v11 + 144;
                      *(_DWORD *)(v11 + 144) = *v51;
                      *(_DWORD *)(v11 + 148) = v51;
                      if ( *(unsigned int **)(v53 + 4) != v51 )
                        __fastfail(3u);
                      *(_DWORD *)(v53 + 4) = v54;
                      *v51 = v54;
                      *(_BYTE *)(a1 + (result >> 3) + 1936) &= ~(unsigned __int8)(1 << (result & 7));
                      v50[1] |= 1 << result;
                      *(_DWORD *)(v11 + 328) |= 0x80000000;
                      __dmb(0xBu);
                      *v50 = 0;
                    }
                    else
                    {
                      v55 = *(_DWORD *)(a1 + 8 * (result + 256));
                      v56 = v11 + 144;
                      v57 = (int *)(a1 + 8 * (result + 256));
                      *(_DWORD *)(v11 + 144) = v55;
                      *(_DWORD *)(v11 + 148) = v57;
                      if ( *(int **)(v55 + 4) != v57 )
                        __fastfail(3u);
                      *(_DWORD *)(v55 + 4) = v56;
                      *v57 = v56;
                      *(_BYTE *)(a1 + (result >> 3) + 1936) |= 1 << (result & 7);
                      *(_DWORD *)(a1 + 1932) |= 1 << result;
                    }
                  }
                }
              }
            }
          }
          else
          {
            if ( KiGetThreadEffectiveRankNonZero(a2, v18, 1) )
              result = KiChooseLowestRankedThread((_DWORD *)a1, a2, *(char *)(a2 + 123), v20);
            else
              result = KiSelectReadyThread(*(char *)(a2 + 123), a1);
            v21 = result;
            if ( result )
            {
              if ( (*(_BYTE *)(result + 2) & 4) != 0 )
              {
                if ( *(char *)(result + 123) < 16
                  && *(_DWORD *)(result + 68)
                  && (v25 = *(_DWORD *)(result + 68)) != 0
                  && (v26 = *(_DWORD *)(a1 + 2352) + v25) != 0
                  && (result = KiGetThreadEffectiveRankNonZero(result, v26, 0)) != 0 )
                {
                  v27 = 1;
                }
                else
                {
                  v27 = *(_BYTE *)(v21 + 123);
                }
                v22 = v27;
              }
              else
              {
                v22 = *(_BYTE *)(result + 123);
              }
              **(_BYTE **)(a1 + 28) = v22;
              *(_DWORD *)(a1 + 8) = v21;
              *(_BYTE *)(v21 + 132) = 3;
            }
          }
          if ( v18 )
          {
            if ( *(_DWORD *)(a2 + 308) || *(_BYTE *)(a2 + 134) == 1 )
            {
              if ( (*(_DWORD *)(a2 + 80) & 0x600) == 0 )
              {
                __dmb(0xBu);
                *v17 = 0;
                result = KiInsertDeferredPreemptionApc(a1, a2, 0);
                while ( 1 )
                {
                  do
                    v19 = __ldrex(v17);
                  while ( __strex(1u, v17) );
                  __dmb(0xBu);
                  if ( !v19 )
                    break;
                  do
                  {
                    __dmb(0xAu);
                    __yield();
                  }
                  while ( *v17 );
                }
              }
            }
            else
            {
              while ( (*(_BYTE *)(v18 + 92) & 2) == 0 )
              {
                v18 = *(_DWORD *)(v18 + 236);
                if ( !v18 )
                  return result;
              }
              if ( !*(_DWORD *)(a1 + 8) )
                result = KiSelectNextThread(a1, a4);
            }
          }
          return result;
        }
        result = v14 - *(_DWORD *)(a1 + 2352);
      }
    }
  }
  return result;
}
