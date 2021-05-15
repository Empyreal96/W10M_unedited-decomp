// KiProcessPendingForegroundBoosts 
 
int *KiProcessPendingForegroundBoosts()
{
  _DWORD *v0; // r5
  int v1; // r9
  unsigned int v2; // r7
  _DWORD *v3; // r10
  int v4; // r8
  unsigned int v5; // r1
  int *result; // r0
  int *v7; // r1
  int v8; // r3
  unsigned int v9; // r3
  _DWORD *v10; // r2
  int v11; // r6
  int *v12; // r5
  unsigned __int16 *v13; // r2
  unsigned int v14; // r1
  __int64 v15; // r2
  _DWORD *v16; // r3
  int v17; // r5
  unsigned int *v18; // r1
  unsigned int v19; // r2
  int v20; // r7
  int v21; // r3
  int v22; // r9
  int v23; // r6
  int v24; // r8
  char v25; // r4
  char v26; // r3
  int v27; // r2
  int v28; // r1
  char v29; // r3
  int v30; // r0
  int v31; // r4
  char v32; // r2
  int v33; // r2
  int v34; // r1
  char v35; // r3
  char v36; // r4
  int v37; // r2
  int v38; // r1
  char v39; // r3
  int v40; // r0
  int v41; // r4
  char v42; // r2
  int v43; // r2
  int v44; // r1
  char v45; // r3
  int v46; // r4
  unsigned int *v47; // r3
  int v48; // r3
  unsigned int *v49; // r2
  unsigned int v50; // r4
  unsigned int v51; // r3
  unsigned __int16 *v52; // r2
  unsigned int v53; // r1
  unsigned int v54; // r4
  int v55; // r3
  unsigned int *v56; // r3
  int v57; // r1
  _DWORD *v58; // [sp+14h] [bp-44h]
  _DWORD *v59; // [sp+18h] [bp-40h] BYREF
  unsigned int *v60; // [sp+1Ch] [bp-3Ch] BYREF
  int v61; // [sp+20h] [bp-38h] BYREF
  _DWORD var30[14]; // [sp+28h] [bp-30h] BYREF

  v0 = 0;
  v1 = KeTickCount;
  v2 = 0;
  v58 = 0;
  v59 = 0;
  v3 = 0;
  v4 = 0;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_624F00);
  }
  else
  {
    do
      v5 = __ldrex((unsigned int *)&dword_624F00);
    while ( __strex(1u, (unsigned int *)&dword_624F00) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_624F00);
  }
  result = (int *)dword_624EF8;
  if ( (int *)dword_624EF8 != &dword_624EF8 )
  {
    do
    {
      v7 = result - 204;
      v8 = *(result - 1);
      result = (int *)*result;
      v9 = v1 - v8;
      if ( v9 < 2 )
      {
        if ( v9 > v2 )
          v2 = v9;
      }
      else
      {
        v10 = v7 + 204;
        v11 = v7[204];
        v12 = (int *)v7[205];
        if ( *(int **)(v11 + 4) != v7 + 204 || (_DWORD *)*v12 != v10 )
          __fastfail(3u);
        *v12 = v11;
        *(_DWORD *)(v11 + 4) = v12;
        *v10 = v58;
        v0 = v7 + 204;
        v7[205] = 0;
        v58 = v7 + 204;
        __dmb(0xBu);
        v13 = (unsigned __int16 *)(v7 + 202);
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 + 1, v13) );
        __dmb(0xBu);
      }
    }
    while ( result != &dword_624EF8 );
    result = (int *)dword_624EF8;
  }
  if ( result != &dword_624EF8 )
    v4 = 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = (int *)KiReleaseSpinLockInstrumented(&dword_624F00, var30[13]);
  }
  else
  {
    __dmb(0xBu);
    dword_624F00 = 0;
  }
  if ( v4 )
  {
    var30[0] = 0;
    var30[1] = 0;
    var30[2] = -1;
    var30[3] = -1;
    v15 = 4294817296i64 * (2 - v2);
    HIDWORD(v15) += v2 - 2;
    result = (int *)KeSetTimer2(KiForegroundState, v15, 0i64, (int)var30);
  }
  if ( v0 )
  {
    do
    {
      v16 = v0;
      if ( v0 )
        v58 = (_DWORD *)*v0;
      v17 = (int)(v0 - 204);
      *v16 = 1;
      v18 = v16 - 193;
      while ( 1 )
      {
        do
          v19 = __ldrex(v18);
        while ( __strex(1u, v18) );
        __dmb(0xBu);
        if ( !v19 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v18 );
      }
      result = (int *)KiAcquireThreadStateLock(v17, &v61, &v60);
      if ( result != (int *)2 && result != (int *)1 && result != (int *)7 && result != (int *)3
        || *(_BYTE *)(*(_DWORD *)(v17 + 336) + 606) != 2
        || *(_BYTE *)(v17 + 348)
        || (*(_DWORD *)(v17 + 80) & 2) != 0 )
      {
        goto LABEL_114;
      }
      v20 = (char)(PsPrioritySeparation + *(_BYTE *)(v17 + 347));
      v21 = *(char *)(v17 + 123);
      if ( v20 >= 16 )
        v20 = 15;
      if ( v20 <= v21 )
      {
LABEL_114:
        v55 = v61;
        if ( v61 )
        {
          __dmb(0xBu);
          *(_DWORD *)(v55 + 24) = 0;
        }
        v56 = v60;
        if ( v60 )
        {
          __dmb(0xBu);
          *v56 = 0;
        }
        goto LABEL_110;
      }
      *(_BYTE *)(v17 + 348) = (v20 - v21) & 0xF;
      v22 = *(char *)(v17 + 123);
      v23 = v61;
      v24 = 1;
      if ( result == (int *)1 )
      {
        KiRemoveThreadFromAnyReadyQueue(v61, (int)v60, v17, v22);
        KiAbProcessThreadPriorityModification(v17, (char)v20, 1);
        *(_BYTE *)(v17 + 123) = v20;
        KiPrepareReadyThreadForRescheduling(v17, v20, &v59);
        v3 = v59;
      }
      else if ( result == (int *)2 )
      {
        if ( *(_DWORD *)(v61 + 8) )
          v24 = 0;
        v36 = v20;
        KiAbProcessThreadPriorityModification(v17, (char)v20, 1);
        *(_BYTE *)(v17 + 123) = v20;
        if ( v24 )
        {
          if ( (*(_BYTE *)(v17 + 2) & 4) != 0 )
          {
            if ( (char)v20 < 16
              && *(_DWORD *)(v17 + 68)
              && (v37 = *(_DWORD *)(v17 + 68)) != 0
              && (v38 = *(_DWORD *)(v23 + 2352) + v37) != 0
              && KiGetThreadEffectiveRankNonZero(v17, v38, 0) )
            {
              v39 = 1;
            }
            else
            {
              v39 = *(_BYTE *)(v17 + 123);
            }
            v36 = v39;
          }
          **(_BYTE **)(v23 + 28) = v36;
        }
        if ( v20 < v22 && v24 )
        {
          if ( *(_BYTE *)(v17 + 132) != 2 )
          {
            v46 = 0;
            if ( *(_DWORD *)(v23 + 1932) >> (v20 + 1) )
              *(_BYTE *)(v17 + 72) |= 0x10u;
            goto LABEL_101;
          }
          v40 = KiSelectReadyThreadEx((_DWORD *)v23, v17, 0);
          v41 = v40;
          if ( v40 )
          {
            if ( (*(_BYTE *)(v40 + 2) & 4) != 0 )
            {
              if ( *(char *)(v40 + 123) < 16
                && *(_DWORD *)(v40 + 68)
                && (v43 = *(_DWORD *)(v40 + 68)) != 0
                && (v44 = *(_DWORD *)(v23 + 2352) + v43) != 0
                && KiGetThreadEffectiveRankNonZero(v40, v44, 0) )
              {
                v45 = 1;
              }
              else
              {
                v45 = *(_BYTE *)(v41 + 123);
              }
              v42 = v45;
            }
            else
            {
              v42 = *(_BYTE *)(v40 + 123);
            }
            **(_BYTE **)(v23 + 28) = v42;
            *(_DWORD *)(v23 + 8) = v41;
            *(_BYTE *)(v41 + 132) = 3;
            v46 = 1;
            goto LABEL_101;
          }
        }
      }
      else
      {
        v25 = v20;
        if ( result == (int *)3 )
        {
          KiAbProcessThreadPriorityModification(v17, (char)v20, 1);
          v26 = *(_BYTE *)(v17 + 2);
          *(_BYTE *)(v17 + 123) = v20;
          if ( (v26 & 4) != 0 )
          {
            if ( (char)v20 < 16
              && *(_DWORD *)(v17 + 68)
              && (v27 = *(_DWORD *)(v17 + 68)) != 0
              && (v28 = *(_DWORD *)(v23 + 2352) + v27) != 0
              && KiGetThreadEffectiveRankNonZero(v17, v28, 0) )
            {
              v29 = 1;
            }
            else
            {
              v29 = *(_BYTE *)(v17 + 123);
            }
            v25 = v29;
          }
          **(_BYTE **)(v23 + 28) = v25;
          if ( v20 < v22 )
          {
            v30 = KiSelectReadyThreadEx((_DWORD *)v23, v17, 0);
            v31 = v30;
            if ( v30 )
            {
              if ( (*(_BYTE *)(v30 + 2) & 4) != 0 )
              {
                if ( *(char *)(v30 + 123) < 16
                  && *(_DWORD *)(v30 + 68)
                  && (v33 = *(_DWORD *)(v30 + 68)) != 0
                  && (v34 = *(_DWORD *)(v23 + 2352) + v33) != 0
                  && KiGetThreadEffectiveRankNonZero(v30, v34, 0) )
                {
                  v35 = 1;
                }
                else
                {
                  v35 = *(_BYTE *)(v31 + 123);
                }
                v32 = v35;
              }
              else
              {
                v32 = *(_BYTE *)(v30 + 123);
              }
              **(_BYTE **)(v23 + 28) = v32;
              *(_DWORD *)(v23 + 8) = v31;
              *(_BYTE *)(v31 + 132) = 3;
              *(_BYTE *)(v17 + 132) = 7;
              *(_DWORD *)(v17 + 144) = v3;
              v3 = (_DWORD *)(v17 + 144);
              v59 = (_DWORD *)(v17 + 144);
            }
          }
        }
        else
        {
          KiAbProcessThreadPriorityModification(v17, (char)v20, 1);
          *(_BYTE *)(v17 + 123) = v20;
        }
      }
      v46 = 0;
LABEL_101:
      result = (int *)KiUpdateSharedReadyQueueAffinityThread(0, v17);
      if ( v23 )
      {
        __dmb(0xBu);
        *(_DWORD *)(v23 + 24) = 0;
      }
      v47 = v60;
      if ( v60 )
      {
        __dmb(0xBu);
        *v47 = 0;
      }
      if ( v46 )
      {
        result = *(int **)(v23 + 20);
        if ( *(int **)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != result )
        {
          v48 = (int)*(&KiProcessorBlock + (_DWORD)result);
          __dmb(0xBu);
          v49 = (unsigned int *)(v48 + 1676);
          do
            v50 = __ldrex(v49);
          while ( __strex(v50 | 2, v49) );
          __dmb(0xBu);
          v51 = (unsigned int)KeGetPcr();
          ++*(_DWORD *)((v51 & 0xFFFFF000) + 0x1414);
          result = (int *)HalSendSoftwareInterrupt(result, 2);
        }
      }
LABEL_110:
      __dmb(0xBu);
      *(_DWORD *)(v17 + 44) = 0;
      __dmb(0xBu);
      v52 = (unsigned __int16 *)(v17 + 808);
      do
        v53 = __ldrex(v52);
      while ( __strex(v53 - 1, v52) );
      __dmb(0xBu);
      v0 = v58;
    }
    while ( v58 );
  }
  v54 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  while ( v3 )
  {
    v57 = (int)(v3 - 36);
    v3 = (_DWORD *)*v3;
    result = (int *)KiDeferredReadyThread(v54 + 1408, v57);
  }
  return result;
}
