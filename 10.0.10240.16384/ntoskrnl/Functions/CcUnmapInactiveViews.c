// CcUnmapInactiveViews 
 
int __fastcall CcUnmapInactiveViews(unsigned int a1, char a2, _DWORD *a3)
{
  unsigned int v3; // lr
  unsigned int v4; // r0
  int v6; // r7
  unsigned int v7; // r2
  int v8; // r6
  unsigned int v9; // r9
  BOOL v10; // r4
  int v11; // r4
  int v12; // r5
  int v13; // r0
  unsigned int v14; // r5
  unsigned int v15; // r0
  int v16; // r3
  _DWORD *v17; // r4
  int v18; // r5
  int v19; // r0
  int v20; // r6
  int v21; // r1
  int v22; // r5
  unsigned int v23; // r7
  int v24; // r9
  BOOL v25; // r10
  unsigned __int8 *v26; // r6
  int v27; // r4
  int v28; // r8
  unsigned int v29; // r2
  unsigned int v30; // r3
  unsigned __int8 *v31; // r4
  int v32; // r0
  int v33; // r6
  unsigned int v34; // r2
  __int64 v35; // r2
  int v36; // r6
  int v37; // r8
  unsigned int v38; // r3
  int v39; // r1
  unsigned int v40; // r0
  unsigned int v41; // r2
  unsigned int *v42; // r4
  int v43; // r7
  unsigned int v44; // r1
  int v45; // r4
  int v46; // r7
  int v47; // r3
  int v48; // r2
  int v49; // r3
  _QWORD *v50; // r2
  __int64 v51; // kr08_8
  __int64 v52; // r0
  _QWORD *v53; // r2
  __int64 v54; // r0
  __int64 v55; // r0
  int v56; // r6
  _QWORD *v57; // r2
  __int64 v58; // r0
  __int64 v59; // r0
  int *v60; // r2
  __int64 v61; // kr10_8
  int **v62; // r1
  int v63; // r1
  unsigned int v64; // r0
  unsigned int v65; // r2
  unsigned int *v66; // r4
  int v67; // r6
  unsigned int v68; // r1
  int v69; // r7
  int v70; // r3
  int v71; // r2
  int v72; // r3
  _QWORD *v73; // r2
  __int64 v74; // kr18_8
  __int64 v75; // r0
  int *v76; // r2
  __int64 v77; // r0
  int **v78; // r1
  int v79; // r1
  int v80; // r0
  BOOL v81; // r6
  _QWORD *v82; // r2
  __int64 v83; // r0
  __int64 v84; // r0
  int *v85; // r2
  __int64 v86; // kr20_8
  int **v87; // r1
  int v88; // r1
  unsigned int v89; // r0
  unsigned int v90; // r2
  unsigned int *v91; // r4
  int v92; // r6
  unsigned int v93; // r1
  int v94; // r3
  int v95; // r2
  int v96; // r3
  _QWORD *v97; // r2
  __int64 v98; // kr28_8
  __int64 v99; // r0
  __int64 v100; // r0
  _QWORD *v101; // r2
  __int64 v102; // r0
  __int64 v103; // r0
  __int64 v104; // kr30_8
  unsigned int v105; // r9
  int v106; // r8
  int v107; // r4
  int v108; // r6
  unsigned int v109; // r2
  int v110; // r5
  unsigned int v111; // r1
  int v112; // r4
  int v113; // r7
  unsigned int v114; // r2
  unsigned int v115; // r1
  unsigned int v116; // r1
  int v119; // [sp+8h] [bp-50h]
  unsigned int v120; // [sp+Ch] [bp-4Ch]
  unsigned int v121; // [sp+10h] [bp-48h]
  BOOL v122; // [sp+14h] [bp-44h]
  int v124; // [sp+1Ch] [bp-3Ch]
  unsigned int v125; // [sp+20h] [bp-38h]
  int v126; // [sp+24h] [bp-34h]
  int v127; // [sp+28h] [bp-30h]
  int v128; // [sp+2Ch] [bp-2Ch]
  int v129; // [sp+30h] [bp-28h]
  int v130; // [sp+34h] [bp-24h]
  _DWORD *v131; // [sp+38h] [bp-20h]

  v3 = a1;
  v4 = 0;
  v6 = -1;
  v7 = 0;
  v8 = 0;
  v124 = -1;
  v125 = 0;
  v131 = a3;
  v119 = 0;
  v120 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  v9 = 0;
  v121 = 0;
  if ( a3 )
  {
    *a3 = 0;
    v127 = 1;
  }
  if ( !CcInitializationComplete || !CcNumberOfMappedVacbs )
    return 0;
  v130 = a2 & 1;
  v10 = v130 == 0;
  v122 = v10;
  while ( v7 < v3 && v4 <= CcVacbArraysHighestUsedIndex )
  {
    if ( v8 )
      goto LABEL_18;
    v6 = -1;
    v124 = -1;
    if ( v10 )
    {
      v8 = CcGetRandomVacbArrayWithReference();
      v119 = v8;
    }
    else
    {
      v11 = v4;
      v12 = KeAcquireQueuedSpinLock(4);
      while ( 1 )
      {
        v13 = CcReferenceVacbArray(v11);
        v8 = v13;
        v119 = v13;
        if ( v13 )
          break;
        if ( ++v11 )
        {
          KeReleaseQueuedSpinLock(4, v12);
          v8 = 0;
          v119 = 0;
          goto LABEL_15;
        }
      }
      CcRecalculateVacbArrayHighwaterMark(v13);
      KeReleaseQueuedSpinLock(4, v12);
LABEL_15:
      v4 = ++v121;
      if ( !v8 )
        goto LABEL_192;
      v10 = v122;
    }
    if ( *(_DWORD *)(v8 + 4) != 1 )
    {
LABEL_18:
      if ( v10 )
      {
        v14 = 0;
        while ( 1 )
        {
          v15 = RtlRandomEx(&CcRandomSeed);
          v16 = *(_DWORD *)(v8 + 8);
          if ( v16 == -1 )
            __brkdiv0();
          v17 = (_DWORD *)(v8 + 24 * (v15 % (v16 + 1)) + 16);
          if ( !CcCanReuseVacb((int)v17, 0) )
          {
            ++v14;
            v17 = 0;
          }
          if ( v17 )
            break;
          if ( v14 > 0x10 )
          {
            v10 = 0;
            v122 = 0;
            ++CcDbgRandomFailed;
            goto LABEL_195;
          }
        }
LABEL_35:
        v20 = KeAcquireQueuedSpinLock(4);
        if ( !CcCanReuseVacb((int)v17, v9) || !CcReferenceSharedCacheMapByVacb((int)v17, v21) )
        {
          v9 = 0;
          v125 = 0;
          KeReleaseQueuedSpinLock(4, v20);
          goto LABEL_191;
        }
        v23 = v17[2];
        v22 = v17[1];
        v24 = v17[3];
        v25 = (*(_DWORD *)(v22 + 96) & 0x200) != 0;
        KeReleaseQueuedSpinLock(4, v20);
        if ( v25 )
        {
          v26 = (unsigned __int8 *)(v22 + 180);
          v27 = KeAbPreAcquire(v22 + 180, 0, 0);
          v28 = KfRaiseIrql(1);
          do
            v29 = __ldrex(v26);
          while ( __strex(v29 & 0xFE, v26) );
          __dmb(0xBu);
          if ( (v29 & 1) == 0 )
            ExpAcquireFastMutexContended(v22 + 180, v27);
          if ( v27 )
            *(_BYTE *)(v27 + 14) |= 1u;
          v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          *(_DWORD *)(v22 + 208) = v28;
          *(_DWORD *)(v22 + 184) = v30;
        }
        v31 = (unsigned __int8 *)(v22 + 72);
        v32 = KeAbPreAcquire(v22 + 72, 0, 0);
        v33 = v32;
        do
          v34 = __ldrex(v31);
        while ( __strex(v34 | 1, v31) );
        __dmb(0xBu);
        if ( (v34 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v22 + 72), v32, v22 + 72);
        if ( v33 )
          *(_BYTE *)(v33 + 14) |= 1u;
        if ( v24 < 0 || (v35 = *(_QWORD *)(v22 + 24), __SPAIR64__(v24, v23) >= v35) )
        {
          __pld(v31);
          v88 = *(_DWORD *)v31;
          v89 = *(_DWORD *)v31 - 16;
          if ( (*(_DWORD *)v31 & 0xFFFFFFF0) <= 0x10 )
            v89 = 0;
          if ( (v88 & 2) != 0 )
            goto LABEL_159;
          __dmb(0xBu);
          do
            v90 = __ldrex((unsigned int *)v31);
          while ( v90 == v88 && __strex(v89, (unsigned int *)v31) );
          if ( v90 != v88 )
LABEL_159:
            ExfReleasePushLock((_DWORD *)(v22 + 72), v88);
          KeAbPostRelease(v22 + 72);
          if ( v25 )
          {
            v91 = (unsigned int *)(v22 + 180);
            v92 = *(_DWORD *)(v22 + 208);
            *(_DWORD *)(v22 + 184) = 0;
            __dmb(0xBu);
            do
              v93 = __ldrex(v91);
            while ( !v93 && __strex(1u, v91) );
            if ( v93 )
              ExpReleaseFastMutexContended((unsigned int *)(v22 + 180), v93);
            KfLowerIrql((unsigned __int8)v92);
            KeAbPostRelease(v22 + 180);
          }
          v69 = KeAcquireQueuedSpinLock(5);
          v94 = *(_DWORD *)(v22 + 4) - 1;
          *(_DWORD *)(v22 + 4) = v94;
          if ( !v94 )
          {
            byte_632771 = 1;
            v95 = *(_DWORD *)(v22 + 96);
            v96 = *(_DWORD *)(v22 + 76);
            if ( (v95 & 0x10000) != 0 )
            {
              if ( !v96 )
              {
                if ( (v95 & 0x3000000) != 0 )
                {
                  v97 = (_QWORD *)(v22 + 80);
                  v98 = *(_QWORD *)(v22 + 80);
                  if ( *(_DWORD *)(v98 + 4) != v22 + 80 || *(_QWORD **)HIDWORD(v98) != v97 )
                    __fastfail(3u);
                  LODWORD(v99) = &CcDirtySharedCacheMapWithLogHandleList;
                  *(_DWORD *)HIDWORD(v98) = v98;
                  *(_DWORD *)(v98 + 4) = HIDWORD(v98);
                  HIDWORD(v99) = dword_632614;
                  *v97 = v99;
                  if ( *(int **)HIDWORD(v99) != &CcDirtySharedCacheMapWithLogHandleList )
                    __fastfail(3u);
                  *(_DWORD *)HIDWORD(v99) = v97;
                  dword_632614 = v22 + 80;
                }
                v76 = (int *)(v22 + 88);
                v100 = *(_QWORD *)(v22 + 88);
                if ( *(_DWORD *)(v100 + 4) != v22 + 88 || *(int **)HIDWORD(v100) != v76 )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v100) = v100;
                *(_DWORD *)(v100 + 4) = HIDWORD(v100);
                v78 = (int **)dword_632634;
                *v76 = (int)&CcLazyWriterCursor;
                *(_DWORD *)(v22 + 92) = v78;
                if ( *v78 != &CcLazyWriterCursor )
                  __fastfail(3u);
LABEL_136:
                *v78 = v76;
                dword_632634 = (int)v76;
              }
LABEL_137:
              v79 = 1;
              v80 = 1;
            }
            else
            {
              if ( v96 || (v95 & 0x20) != 0 )
                goto LABEL_150;
              v81 = *(_DWORD *)(v22 + 176) != 0;
              if ( (v95 & 0x3000000) != 0 )
              {
                v101 = (_QWORD *)(v22 + 80);
                v102 = *(_QWORD *)(v22 + 80);
                if ( *(_DWORD *)(v102 + 4) != v22 + 80 || *(_QWORD **)HIDWORD(v102) != v101 )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v102) = v102;
                *(_DWORD *)(v102 + 4) = HIDWORD(v102);
                LODWORD(v103) = &CcDirtySharedCacheMapWithLogHandleList;
                HIDWORD(v103) = dword_632614;
                *v101 = v103;
                if ( *(int **)HIDWORD(v103) != &CcDirtySharedCacheMapWithLogHandleList )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v103) = v101;
                dword_632614 = v22 + 80;
              }
              v85 = (int *)(v22 + 88);
              v104 = *(_QWORD *)(v22 + 88);
              if ( *(_DWORD *)(v104 + 4) != v22 + 88 || *(int **)HIDWORD(v104) != v85 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v104) = v104;
              *(_DWORD *)(v104 + 4) = HIDWORD(v104);
              v87 = (int **)dword_632634;
              *v85 = (int)&CcLazyWriterCursor;
              *(_DWORD *)(v22 + 92) = v87;
              if ( *v87 != &CcLazyWriterCursor )
                __fastfail(3u);
LABEL_148:
              *v87 = v85;
              dword_632634 = (int)v85;
              v79 = 0;
              v80 = v81;
            }
            CcScheduleLazyWriteScan(v80, v79);
            goto LABEL_150;
          }
        }
        else
        {
          if ( v35 <= 0x2000000 )
            v36 = *(_DWORD *)(*(_DWORD *)(v22 + 64) + 4 * (v23 >> 18));
          else
            v36 = CcGetVacbLargeOffset(v22, __SPAIR64__(v24, v23));
          if ( v36 && !*(_WORD *)(v36 + 8) )
          {
            SetVacb(v22, *(unsigned __int16 *)(v36 + 8), v23, v24, 0);
            if ( CcNumberOfFreeHighPriorityVacbs < (unsigned int)CcMinimumFreeHighPriorityVacbs )
            {
              v37 = 1;
              goto LABEL_60;
            }
            v37 = 0;
            if ( v127 )
            {
LABEL_60:
              v9 = 0;
              v38 = v126 | 2;
              v126 |= 2u;
              goto LABEL_61;
            }
            v9 = v125;
            v38 = v126 & 0xFFFFFFFD;
            v126 &= 0xFFFFFFFD;
            if ( !v125 && v130 )
            {
              v9 = *(_DWORD *)v36;
LABEL_61:
              v125 = v9;
            }
            CcUnmapVacb(v36, v22, v38);
            __pld(v31);
            v39 = *(_DWORD *)v31;
            if ( (*(_DWORD *)v31 & 0xFFFFFFF0) <= 0x10 )
              v40 = 0;
            else
              v40 = v39 - 16;
            if ( (v39 & 2) != 0 )
              goto LABEL_74;
            __dmb(0xBu);
            do
              v41 = __ldrex((unsigned int *)v31);
            while ( v41 == v39 && __strex(v40, (unsigned int *)v31) );
            if ( v41 != v39 )
LABEL_74:
              ExfReleasePushLock((_DWORD *)(v22 + 72), v39);
            KeAbPostRelease(v22 + 72);
            if ( v25 )
            {
              v42 = (unsigned int *)(v22 + 180);
              v43 = *(_DWORD *)(v22 + 208);
              *(_DWORD *)(v22 + 184) = 0;
              __dmb(0xBu);
              do
                v44 = __ldrex(v42);
              while ( !v44 && __strex(1u, v42) );
              if ( v44 )
                ExpReleaseFastMutexContended((unsigned int *)(v22 + 180), v44);
              KfLowerIrql((unsigned __int8)v43);
              KeAbPostRelease(v22 + 180);
            }
            if ( !v37 )
            {
              v129 = 1;
              ++v120;
              if ( v127 )
              {
                *v131 = *(_DWORD *)v36;
                v127 = 0;
                *(_DWORD *)v36 = 0;
              }
            }
            v45 = KeAcquireQueuedSpinLock(4);
            *(_DWORD *)(v36 + 4) = 0;
            CcSetVacbInFreeList(v36, v37);
            KeReleaseQueuedSpinLock(4, v45);
            v46 = KeAcquireQueuedSpinLock(5);
            v47 = *(_DWORD *)(v22 + 4) - 1;
            *(_DWORD *)(v22 + 4) = v47;
            if ( !v47 )
            {
              byte_632771 = 1;
              v48 = *(_DWORD *)(v22 + 96);
              v49 = *(_DWORD *)(v22 + 76);
              if ( (v48 & 0x10000) != 0 )
              {
                if ( !v49 )
                {
                  if ( (v48 & 0x3000000) != 0 )
                  {
                    v50 = (_QWORD *)(v22 + 80);
                    v51 = *(_QWORD *)(v22 + 80);
                    if ( *(_DWORD *)(v51 + 4) != v22 + 80 || *(_QWORD **)HIDWORD(v51) != v50 )
                      __fastfail(3u);
                    LODWORD(v52) = &CcDirtySharedCacheMapWithLogHandleList;
                    *(_DWORD *)HIDWORD(v51) = v51;
                    *(_DWORD *)(v51 + 4) = HIDWORD(v51);
                    HIDWORD(v52) = dword_632614;
                    *v50 = v52;
                    if ( *(int **)HIDWORD(v52) != &CcDirtySharedCacheMapWithLogHandleList )
                      __fastfail(3u);
                    *(_DWORD *)HIDWORD(v52) = v50;
                    dword_632614 = v22 + 80;
                  }
                  v53 = (_QWORD *)(v22 + 88);
                  v54 = *(_QWORD *)(v22 + 88);
                  if ( *(_DWORD *)(v54 + 4) != v22 + 88 || *(_QWORD **)HIDWORD(v54) != v53 )
                    __fastfail(3u);
                  *(_DWORD *)HIDWORD(v54) = v54;
                  *(_DWORD *)(v54 + 4) = HIDWORD(v54);
                  LODWORD(v55) = &CcLazyWriterCursor;
                  HIDWORD(v55) = dword_632634;
                  *v53 = v55;
                  if ( *(int **)HIDWORD(v55) != &CcLazyWriterCursor )
                    __fastfail(3u);
                  *(_DWORD *)HIDWORD(v55) = v53;
                  dword_632634 = v22 + 88;
                }
                CcScheduleLazyWriteScan(1, 1);
              }
              else if ( !v49 && (v48 & 0x20) == 0 )
              {
                v56 = *(_DWORD *)(v22 + 176) != 0;
                if ( (v48 & 0x3000000) != 0 )
                {
                  v57 = (_QWORD *)(v22 + 80);
                  v58 = *(_QWORD *)(v22 + 80);
                  if ( *(_DWORD *)(v58 + 4) != v22 + 80 || *(_QWORD **)HIDWORD(v58) != v57 )
                    __fastfail(3u);
                  *(_DWORD *)HIDWORD(v58) = v58;
                  *(_DWORD *)(v58 + 4) = HIDWORD(v58);
                  LODWORD(v59) = &CcDirtySharedCacheMapWithLogHandleList;
                  HIDWORD(v59) = dword_632614;
                  *v57 = v59;
                  if ( *(int **)HIDWORD(v59) != &CcDirtySharedCacheMapWithLogHandleList )
                    __fastfail(3u);
                  *(_DWORD *)HIDWORD(v59) = v57;
                  dword_632614 = v22 + 80;
                }
                v60 = (int *)(v22 + 88);
                v61 = *(_QWORD *)(v22 + 88);
                if ( *(_DWORD *)(v61 + 4) != v22 + 88 || *(int **)HIDWORD(v61) != v60 )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v61) = v61;
                *(_DWORD *)(v61 + 4) = HIDWORD(v61);
                v62 = (int **)dword_632634;
                *v60 = (int)&CcLazyWriterCursor;
                *(_DWORD *)(v22 + 92) = v62;
                if ( *v62 != &CcLazyWriterCursor )
                  __fastfail(3u);
                *v62 = v60;
                dword_632634 = v22 + 88;
                CcScheduleLazyWriteScan(v56, 0);
              }
            }
            KeReleaseQueuedSpinLock(5, v46);
            v6 = v124;
LABEL_191:
            v8 = v119;
            v4 = v121;
LABEL_192:
            v10 = v122;
            goto LABEL_193;
          }
          __pld(v31);
          v63 = *(_DWORD *)v31;
          v64 = *(_DWORD *)v31 - 16;
          if ( (*(_DWORD *)v31 & 0xFFFFFFF0) <= 0x10 )
            v64 = 0;
          if ( (v63 & 2) != 0 )
            goto LABEL_117;
          __dmb(0xBu);
          do
            v65 = __ldrex((unsigned int *)v31);
          while ( v65 == v63 && __strex(v64, (unsigned int *)v31) );
          if ( v65 != v63 )
LABEL_117:
            ExfReleasePushLock((_DWORD *)(v22 + 72), v63);
          KeAbPostRelease(v22 + 72);
          if ( v25 )
          {
            v66 = (unsigned int *)(v22 + 180);
            v67 = *(_DWORD *)(v22 + 208);
            *(_DWORD *)(v22 + 184) = 0;
            __dmb(0xBu);
            do
              v68 = __ldrex(v66);
            while ( !v68 && __strex(1u, v66) );
            if ( v68 )
              ExpReleaseFastMutexContended((unsigned int *)(v22 + 180), v68);
            KfLowerIrql((unsigned __int8)v67);
            KeAbPostRelease(v22 + 180);
          }
          v69 = KeAcquireQueuedSpinLock(5);
          v70 = *(_DWORD *)(v22 + 4) - 1;
          *(_DWORD *)(v22 + 4) = v70;
          if ( !v70 )
          {
            byte_632771 = 1;
            v71 = *(_DWORD *)(v22 + 96);
            v72 = *(_DWORD *)(v22 + 76);
            if ( (v71 & 0x10000) != 0 )
            {
              if ( !v72 )
              {
                if ( (v71 & 0x3000000) != 0 )
                {
                  v73 = (_QWORD *)(v22 + 80);
                  v74 = *(_QWORD *)(v22 + 80);
                  if ( *(_DWORD *)(v74 + 4) != v22 + 80 || *(_QWORD **)HIDWORD(v74) != v73 )
                    __fastfail(3u);
                  LODWORD(v75) = &CcDirtySharedCacheMapWithLogHandleList;
                  *(_DWORD *)HIDWORD(v74) = v74;
                  *(_DWORD *)(v74 + 4) = HIDWORD(v74);
                  HIDWORD(v75) = dword_632614;
                  *v73 = v75;
                  if ( *(int **)HIDWORD(v75) != &CcDirtySharedCacheMapWithLogHandleList )
                    __fastfail(3u);
                  *(_DWORD *)HIDWORD(v75) = v73;
                  dword_632614 = v22 + 80;
                }
                v76 = (int *)(v22 + 88);
                v77 = *(_QWORD *)(v22 + 88);
                if ( *(_DWORD *)(v77 + 4) != v22 + 88 || *(int **)HIDWORD(v77) != v76 )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v77) = v77;
                *(_DWORD *)(v77 + 4) = HIDWORD(v77);
                v78 = (int **)dword_632634;
                *v76 = (int)&CcLazyWriterCursor;
                *(_DWORD *)(v22 + 92) = v78;
                if ( *v78 != &CcLazyWriterCursor )
                  __fastfail(3u);
                goto LABEL_136;
              }
              goto LABEL_137;
            }
            if ( !v72 && (v71 & 0x20) == 0 )
            {
              v81 = *(_DWORD *)(v22 + 176) != 0;
              if ( (v71 & 0x3000000) != 0 )
              {
                v82 = (_QWORD *)(v22 + 80);
                v83 = *(_QWORD *)(v22 + 80);
                if ( *(_DWORD *)(v83 + 4) != v22 + 80 || *(_QWORD **)HIDWORD(v83) != v82 )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v83) = v83;
                *(_DWORD *)(v83 + 4) = HIDWORD(v83);
                LODWORD(v84) = &CcDirtySharedCacheMapWithLogHandleList;
                HIDWORD(v84) = dword_632614;
                *v82 = v84;
                if ( *(int **)HIDWORD(v84) != &CcDirtySharedCacheMapWithLogHandleList )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v84) = v82;
                dword_632614 = v22 + 80;
              }
              v85 = (int *)(v22 + 88);
              v86 = *(_QWORD *)(v22 + 88);
              if ( *(_DWORD *)(v86 + 4) != v22 + 88 || *(int **)HIDWORD(v86) != v85 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v86) = v86;
              *(_DWORD *)(v86 + 4) = HIDWORD(v86);
              v87 = (int **)dword_632634;
              *v85 = (int)&CcLazyWriterCursor;
              *(_DWORD *)(v22 + 92) = v87;
              if ( *v87 != &CcLazyWriterCursor )
                __fastfail(3u);
              goto LABEL_148;
            }
          }
        }
LABEL_150:
        KeReleaseQueuedSpinLock(5, v69);
        v6 = v124;
LABEL_151:
        v9 = v125;
        goto LABEL_191;
      }
      if ( v6 == -1 )
      {
        v6 = *(_DWORD *)(v8 + 8) + 1;
        v124 = v6;
      }
      if ( v6 )
      {
        v18 = v8 + 16 + 24 * v6 - 24;
        do
        {
          v17 = (_DWORD *)v18;
          v19 = v18;
          --v6;
          v18 -= 24;
          if ( CcCanReuseVacb(v19, v9) )
            break;
          v17 = 0;
        }
        while ( v6 );
        v124 = v6;
        if ( v17 )
          goto LABEL_35;
        v10 = v122;
      }
    }
LABEL_195:
    CcDereferenceVacbArray(v8, 0);
    v8 = 0;
    v4 = v121;
    v119 = 0;
LABEL_193:
    v7 = v120;
    v3 = a1;
  }
  if ( v8 )
  {
    CcDereferenceVacbArray(v8, 0);
    v7 = v120;
    v3 = a1;
    v119 = 0;
  }
  if ( __PAIR64__(v128, v7) < v3 )
  {
    v105 = v3 - v7;
    v128 = 1;
    v106 = 0;
    v107 = KeAbPreAcquire((unsigned int)&CcBcbTrimNotificationListLock, 0, 0);
    v108 = KfRaiseIrql(1);
    do
      v109 = __ldrex((unsigned __int8 *)&CcBcbTrimNotificationListLock);
    while ( __strex(v109 & 0xFE, (unsigned __int8 *)&CcBcbTrimNotificationListLock) );
    __dmb(0xBu);
    if ( (v109 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CcBcbTrimNotificationListLock, v107);
    if ( v107 )
      *(_BYTE *)(v107 + 14) |= 1u;
    __mrc(15, 0, 13, 0, 3);
    dword_63267C = v108;
    v110 = CcBcbTrimNotificationList;
    if ( (int *)CcBcbTrimNotificationList != &CcBcbTrimNotificationList )
    {
      do
      {
        dword_632664 = 0;
        __dmb(0xBu);
        do
          v111 = __ldrex((unsigned int *)&CcBcbTrimNotificationListLock);
        while ( !v111 && __strex(1u, (unsigned int *)&CcBcbTrimNotificationListLock) );
        if ( v111 )
          ExpReleaseFastMutexContended((unsigned int *)&CcBcbTrimNotificationListLock, v111);
        KfLowerIrql((unsigned __int8)v108);
        KeAbPostRelease((unsigned int)&CcBcbTrimNotificationListLock);
        v106 |= (*(int (__fastcall **)(unsigned int, _DWORD))(v110 + 8))(v105 << 18, 0);
        v112 = KeAbPreAcquire((unsigned int)&CcBcbTrimNotificationListLock, 0, 0);
        v113 = KfRaiseIrql(1);
        do
          v114 = __ldrex((unsigned __int8 *)&CcBcbTrimNotificationListLock);
        while ( __strex(v114 & 0xFE, (unsigned __int8 *)&CcBcbTrimNotificationListLock) );
        __dmb(0xBu);
        if ( (v114 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&CcBcbTrimNotificationListLock, v112);
        if ( v112 )
          *(_BYTE *)(v112 + 14) |= 1u;
        dword_632664 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        dword_63267C = v113;
        v110 = *(_DWORD *)v110;
        LOBYTE(v108) = v113;
      }
      while ( (int *)v110 != &CcBcbTrimNotificationList );
      v6 = v124;
    }
    dword_632664 = 0;
    __dmb(0xBu);
    do
      v115 = __ldrex((unsigned int *)&CcBcbTrimNotificationListLock);
    while ( !v115 && __strex(1u, (unsigned int *)&CcBcbTrimNotificationListLock) );
    if ( v115 )
      ExpReleaseFastMutexContended((unsigned int *)&CcBcbTrimNotificationListLock, v115);
    KfLowerIrql((unsigned __int8)v108);
    KeAbPostRelease((unsigned int)&CcBcbTrimNotificationListLock);
    if ( v106 )
      goto LABEL_151;
  }
  __dmb(0xBu);
  do
    v116 = __ldrex(&CcDbgNumberOfCcUnmapInactiveViews);
  while ( __strex(v116 + 1, &CcDbgNumberOfCcUnmapInactiveViews) );
  __dmb(0xBu);
  return v129;
}
