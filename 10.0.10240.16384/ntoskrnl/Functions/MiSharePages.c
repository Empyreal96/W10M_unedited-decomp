// MiSharePages 
 
int __fastcall MiSharePages(_DWORD *a1, __int64 **a2, __int16 ***a3, int a4, int a5, int a6, _DWORD *a7)
{
  _DWORD *v7; // r9
  unsigned int *v9; // r8
  int v10; // r0
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r10
  char *v14; // r7
  int v15; // r6
  int v16; // r4
  int v17; // r4
  int v18; // r5
  int result; // r0
  char *v20; // r3
  int v21; // r2
  __int64 *v22; // r9
  unsigned __int8 *v23; // r1
  unsigned int v24; // r2
  unsigned int v25; // r0
  int v26; // r8
  int v27; // r1
  __int64 v28; // kr00_8
  int v29; // r8
  int v30; // r2
  int v31; // r3
  unsigned int *v32; // r4
  unsigned int v33; // r7
  int v34; // r4
  unsigned __int8 *v35; // r3
  unsigned int v36; // r1
  int v37; // r5
  unsigned int v38; // r6
  int v39; // r10
  bool v40; // zf
  unsigned int *v41; // r2
  unsigned int v42; // r0
  int v43; // r2
  unsigned int *v44; // lr
  unsigned int v45; // r6
  _DWORD *v46; // r0
  unsigned int v47; // r5
  int *v48; // r8
  int v49; // r3
  int v50; // r4
  int v51; // r4
  char *v52; // r2
  int v53; // r3
  int v54; // r2
  int v55; // r6
  char *v56; // r5
  int v57; // r4
  int i; // r5
  int v59; // r1
  int v60; // r2
  int v61; // r3
  unsigned int v62; // r6
  int v63; // r4
  int v64; // r1
  int v65; // r3
  int v66; // r0
  int v67; // r6
  int v68; // r0
  int v69; // r4
  unsigned int *v70; // r5
  int v71; // r7
  unsigned __int8 *v72; // r3
  unsigned int v73; // r1
  unsigned int v74; // r0
  int v75; // r6
  __int16 *v76; // r4
  int v77; // r2
  __int16 *v78; // r3
  int v79; // r0
  unsigned int v80; // r0
  int v81; // r7
  int v82; // r0
  unsigned int v83; // r8
  int v84; // r5
  int v85; // r3
  int v86; // r0
  int v87; // r7
  int v88; // r4
  unsigned __int8 *v89; // r3
  unsigned int v90; // r1
  int v91; // r2
  unsigned int *v92; // r2
  unsigned int v93; // r0
  __int64 v94; // r2
  __int64 v95; // r2
  unsigned int *v96; // r2
  unsigned int v97; // r0
  unsigned int v98; // r1
  __int64 *v99; // r2
  unsigned __int8 *v100; // r1
  int v101; // r3
  unsigned int v102; // r2
  unsigned __int8 *v103; // r1
  int v104; // r3
  unsigned int v105; // r2
  unsigned int *v106; // r2
  unsigned int v107; // r0
  int v108; // r1
  unsigned int v109; // r0
  int v110; // r0
  int v111; // r0
  unsigned int v112; // r5
  unsigned int v113; // r2
  int v114; // r3
  int v115; // r4
  int v116; // r0
  int v117; // r4
  int v118; // r2
  int v119; // r3
  int v120; // r4
  int v121; // r0
  int v122; // r1
  unsigned int v123; // r1
  char *v124; // [sp+10h] [bp-1D0h]
  unsigned int *v125; // [sp+14h] [bp-1CCh]
  __int16 **v126; // [sp+18h] [bp-1C8h]
  int v127; // [sp+1Ch] [bp-1C4h]
  unsigned int v128; // [sp+20h] [bp-1C0h]
  int v129; // [sp+24h] [bp-1BCh]
  unsigned int v130; // [sp+28h] [bp-1B8h]
  int v131; // [sp+2Ch] [bp-1B4h]
  int v132; // [sp+30h] [bp-1B0h]
  int v133; // [sp+30h] [bp-1B0h]
  __int64 v134; // [sp+34h] [bp-1ACh]
  unsigned int v136; // [sp+48h] [bp-198h]
  unsigned int v137; // [sp+4Ch] [bp-194h]
  int v138; // [sp+50h] [bp-190h]
  int v140; // [sp+5Ch] [bp-184h]
  int v141; // [sp+64h] [bp-17Ch]
  int v142; // [sp+6Ch] [bp-174h]
  unsigned int v143; // [sp+70h] [bp-170h]
  int v144; // [sp+74h] [bp-16Ch]
  __int16 *v145; // [sp+78h] [bp-168h]
  int v146; // [sp+7Ch] [bp-164h]
  _DWORD v147[4]; // [sp+88h] [bp-158h] BYREF
  __int64 v148; // [sp+98h] [bp-148h]
  char v149[24]; // [sp+B0h] [bp-130h] BYREF
  char v150[152]; // [sp+C8h] [bp-118h] BYREF
  char v151[12]; // [sp+160h] [bp-80h] BYREF
  int v152; // [sp+16Ch] [bp-74h]
  char v153; // [sp+190h] [bp-50h] BYREF

  v7 = a7;
  __dmb(0xBu);
  v147[0] = 0;
  v147[1] = 0;
  v147[2] = 0;
  v137 = 0;
  v129 = 0;
  v9 = (unsigned int *)a1[4];
  v125 = v9;
  v126 = *a3;
  v145 = **a3;
  v10 = MiTbFlushType((int)v9);
  v144 = 0;
  v12 = a1[3];
  v13 = a1[6];
  v14 = v150;
  v15 = v10;
  v140 = 0;
  v124 = v150;
  if ( v12 > 0x21 )
  {
    v16 = 1019;
    if ( v12 < 0x3FB )
      v16 = a1[3];
    v14 = (char *)ExAllocatePoolWithTag(512, 4 * (v16 + 5));
    v124 = v14;
    if ( !v14 )
      return sub_54EB7C();
    v11 = 0;
  }
  else
  {
    v16 = a1[3];
  }
  *((_DWORD *)v14 + 3) = v11;
  *((_DWORD *)v14 + 4) = v11;
  *(_DWORD *)v14 = v15;
  v14[4] = v11;
  v14[5] = v11;
  *((_DWORD *)v14 + 2) = v16;
  *((_DWORD *)v14 + 5) = v11;
  v17 = a1[5];
  v141 = v17;
  if ( !v17 || v17 == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
    goto LABEL_7;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v147);
  v18 = MiPrepareAttachThread(v17, v17 + 492);
  v140 = v18;
  result = KeReleaseInStackQueuedSpinLock((int)v147);
  if ( v18 )
  {
    KiStackAttachProcess(v17, 1, (int)v149);
LABEL_7:
    v131 = 0;
    v20 = v151;
    v21 = 4;
    do
    {
      *((_DWORD *)v20 + 3) = 0;
      v20 += 24;
      --v21;
    }
    while ( v21 );
    v22 = 0;
    v142 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9);
    }
    else
    {
      v23 = (unsigned __int8 *)v9 + 3;
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 | 0x80, v23) );
      __dmb(0xBu);
      if ( v24 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v9);
      while ( 1 )
      {
        v25 = *v9;
        if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v25 & 0x40000000) == 0 )
        {
          do
            v98 = __ldrex(v9);
          while ( v98 == v25 && __strex(v25 | 0x40000000, v9) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( !v17
      || (*(_DWORD *)(v17 + 192) & 0xC00u) >= 0xC00
      && !v9[1]
      && (v17 != PsInitialSystemProcess || !*((_DWORD *)v145 + 168)) )
    {
      v138 = v152;
      while ( 1 )
      {
        v127 = v13;
        if ( v22 )
        {
          if ( v22[2] )
          {
            MiDecrementCombinedPte((int)(v22 + 4));
          }
          else
          {
            v99 = *a2;
            *(_DWORD *)v22 = *a2;
            *((_DWORD *)v22 + 1) = a2;
            if ( *((__int64 ***)v99 + 1) != a2 )
              __fastfail(3u);
            *((_DWORD *)v99 + 1) = v22;
            *a2 = v22;
          }
        }
        v26 = 0;
        ++v144;
        v132 = 0;
        if ( (v144 & 0x1F) == 0 && ExSpinLockIsContended(v125)
          || KeShouldYieldProcessor()
          || MiFlushTbListEarly((int)v14, 2) )
        {
          v26 = 1;
          v132 = 1;
        }
        if ( v13 )
        {
          if ( !v26 )
            goto LABEL_26;
        }
        else
        {
          ++v137;
        }
        v55 = 2;
        v56 = &v153;
        do
        {
          v57 = *((_DWORD *)v56 + 3);
          if ( v57 )
          {
            do
            {
              v87 = *(_DWORD *)(v57 + 12);
              if ( MiCrcStillIntact((int)v126, (int)v125, v57, v55) )
              {
                *(_DWORD *)(v57 + 12) = v13;
                v13 = v57;
              }
              v57 = v87;
            }
            while ( v87 );
            v127 = v13;
          }
          *((_DWORD *)v56 + 3) = 0;
          ++v55;
          v56 += 24;
        }
        while ( v55 <= 3 );
        v14 = v124;
        MiFlushTbList((unsigned int)v124, v27);
        for ( i = v152; i; i = *(_DWORD *)(i + 12) )
        {
          v88 = *(_DWORD *)(i + 8);
          v89 = (unsigned __int8 *)(v88 + 15);
          do
            v90 = __ldrex(v89);
          while ( __strex(v90 | 0x80, v89) );
          __dmb(0xBu);
          if ( v90 >> 7 )
          {
            v100 = (unsigned __int8 *)(v88 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v101 = *(_DWORD *)(v88 + 12);
                __dmb(0xBu);
              }
              while ( (v101 & 0x80000000) != 0 );
              do
                v102 = __ldrex(v100);
              while ( __strex(v102 | 0x80, v100) );
              __dmb(0xBu);
            }
            while ( v102 >> 7 );
          }
          if ( (*(_BYTE *)(v88 + 18) & 7) != 6 )
            KeBugCheckEx(78, 153, (v88 - MmPfnDatabase) / 24);
          v91 = *(_DWORD *)(v88 + 12);
          *(_DWORD *)(v88 + 12) = v91 & 0xC0000000 | ((v91 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
          if ( (v91 & 0x3FFFFFFF) == 1 )
            MiPfnShareCountIsZero(v88, 0);
          __dmb(0xBu);
          v92 = (unsigned int *)(v88 + 12);
          do
            v93 = __ldrex(v92);
          while ( __strex(v93 & 0x7FFFFFFF, v92) );
        }
        v138 = 0;
        v152 = 0;
        if ( !v13 )
        {
          v9 = v125;
          v17 = v141;
          break;
        }
        if ( v132 )
        {
          v9 = v125;
          MiUnlockWorkingSetExclusive((int)v125, v142);
          v17 = v141;
          goto LABEL_7;
        }
LABEL_26:
        v28 = *(_QWORD *)(v13 + 8);
        v22 = *(__int64 **)(v13 + 16);
        v146 = *(_DWORD *)(v13 + 12);
        v128 = *(_DWORD *)(v13 + 8);
        v134 = *(_QWORD *)v13;
        if ( (unsigned int)v22 >= 0x100 )
        {
          v29 = *((_DWORD *)v22 + 7);
        }
        else
        {
          v29 = *(_DWORD *)(v13 + 16);
          v22 = 0;
        }
        if ( !MiRecheckVaVm(v125, v28) )
          goto LABEL_62;
        v31 = ((unsigned int)v28 >> 10) & 0x3FFFFC;
        v32 = (unsigned int *)(v31 - 0x40000000);
        v130 = v31 - 0x40000000;
        if ( !MiIsAddressValid(v31 - 0x40000000, 0, v30, v31) )
          goto LABEL_62;
        v33 = *v32;
        if ( (*v32 & 2) != 0 )
        {
          v143 = v33 >> 12;
          if ( !MI_IS_PFN(v33 >> 12) )
            goto LABEL_182;
          v34 = MmPfnDatabase + 24 * (v33 >> 12);
          v35 = (unsigned __int8 *)(v34 + 15);
          do
            v36 = __ldrex(v35);
          while ( __strex(v36 | 0x80, v35) );
          __dmb(0xBu);
          if ( v36 >> 7 )
          {
            v103 = (unsigned __int8 *)(v34 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v104 = *(_DWORD *)(v34 + 12);
                __dmb(0xBu);
              }
              while ( (v104 & 0x80000000) != 0 );
              do
                v105 = __ldrex(v103);
              while ( __strex(v105 | 0x80, v103) );
              __dmb(0xBu);
            }
            while ( v105 >> 7 );
          }
        }
        else
        {
          if ( (v33 & 0x400) != 0 )
            goto LABEL_155;
          if ( (v33 & 0x800) == 0 )
            goto LABEL_155;
          v79 = MiLockTransitionLeafPage(v32, 0);
          v34 = v79;
          if ( !v79 )
            goto LABEL_155;
          v143 = (v79 - MmPfnDatabase) / 24;
        }
        v37 = MiCombineCandidate(v126, v34);
        if ( !v37 )
        {
          __dmb(0xBu);
          v96 = (unsigned int *)(v34 + 12);
          do
            v97 = __ldrex(v96);
          while ( __strex(v97 & 0x7FFFFFFF, v96) );
          goto LABEL_155;
        }
        v38 = (*(_DWORD *)(v34 + 8) >> 5) & 0x1F;
        if ( *(_DWORD *)(v34 + 20) >> 28 != a5 )
        {
          __dmb(0xBu);
          v106 = (unsigned int *)(v34 + 12);
          do
            v107 = __ldrex(v106);
          while ( __strex(v107 & 0x7FFFFFFF, v106) );
          goto LABEL_182;
        }
        v133 = 0;
        v39 = 0;
        v40 = (*(_BYTE *)(v34 + 18) & 7) == 6;
        __dmb(0xBu);
        v41 = (unsigned int *)(v34 + 12);
        if ( !v40 )
        {
          do
            v80 = __ldrex(v41);
          while ( __strex(v80 & 0x7FFFFFFF, v41) );
          v81 = 0;
          v82 = MiReservePtes(&dword_634D58, 1u);
          v83 = v82;
          if ( !v82 )
            goto LABEL_182;
          *(_DWORD *)(a4 + 32) = v34;
          *(_DWORD *)(a4 + 36) = v82;
          if ( !MiMapArbitraryPage(v126, a4, v37, 1) )
          {
            MiReleasePtes(&dword_634D58, v83, 1u);
            goto LABEL_182;
          }
          v84 = -1;
          if ( v22 )
          {
LABEL_128:
            if ( MiConvertStandbyToProto((int)v125, v126, a4, (int)v22, v34, v130, v84) )
            {
              ++a7[1];
              if ( v84 == -1 )
              {
                v81 = 1;
                v22 = 0;
                ++v129;
              }
              else
              {
                *(_DWORD *)(v39 + 24) += 4096;
                v133 = 1;
                v81 = 1;
              }
              ++v131;
            }
          }
          else if ( MiPerformCombineScan() && v148 == v134 )
          {
            v85 = 1;
            if ( v38 >> 3 == 1 )
            {
              v85 = 0;
            }
            else if ( v38 >> 3 == 3 && (v38 & 7) != 0 )
            {
              v85 = 2;
            }
            v39 = *(_DWORD *)(a6 + 4 * v85);
            if ( v39 )
            {
              if ( *(_DWORD *)(v39 + 24) < *(_DWORD *)(v39 + 20) )
              {
                v86 = MiAllocateCombineProto(v126, HIDWORD(v134), v134, HIDWORD(v134), v38, 0);
                v22 = (__int64 *)v86;
                if ( v86 )
                {
                  *(_DWORD *)(v127 + 16) = v86;
                }
                else
                {
                  v22 = *a2;
                  v95 = **a2;
                  if ( (__int64 **)HIDWORD(v95) != a2 || *(__int64 **)(v95 + 4) != v22 )
                    __fastfail(3u);
                  *a2 = (__int64 *)v95;
                  *(_DWORD *)(v95 + 4) = a2;
                  *((_DWORD *)v22 + 7) = v38;
                  v84 = *(_DWORD *)(v39 + 4 * (*(_DWORD *)(v39 + 24) >> 12) + 28);
                }
                goto LABEL_128;
              }
            }
          }
          MiReleaseArbitraryPage(a4);
          MiReleasePtes(&dword_634D58, v83, 1u);
          v40 = v81 == 0;
          v14 = v124;
          if ( !v40 )
            goto LABEL_99;
          goto LABEL_62;
        }
        do
          v42 = __ldrex(v41);
        while ( __strex(v42 & 0x7FFFFFFF, v41) );
        if ( v130 != (*(_DWORD *)(v34 + 4) | 0x80000000) )
          goto LABEL_182;
        v43 = *(_DWORD *)(v34 + 20);
        if ( (v43 & 0x8000000) != 0 )
          goto LABEL_182;
        if ( (*(_BYTE *)(v34 + 19) & 8) != 0 )
          goto LABEL_182;
        if ( (v43 & 0xFFFFF) == 1048573 )
          goto LABEL_182;
        v44 = v125;
        v45 = MiLocateWsle(v128, (int)v125, *(_DWORD *)v34);
        if ( v45 < *(_DWORD *)(v125[23] + 4) || *(_WORD *)(v34 + 16) != 1 )
          goto LABEL_182;
        v46 = 0;
        if ( v37 == 1 )
        {
          v46 = MiLocateAddress(v128);
          if ( !v46 || ((1 << (v46[7] & 7)) & 0x55) == 0 )
            goto LABEL_182;
          v44 = v125;
        }
        v47 = (*(_DWORD *)(v34 + 8) >> 5) & 0x1F;
        v136 = v47;
        if ( v47 != v29 )
          goto LABEL_182;
        if ( (v33 & 0x200) != 0 )
        {
          if ( v134 != qword_634310 || ((*(_DWORD *)(v34 + 8) >> 5) & 0x18) != 0 || (v33 & 0x10) == 0 )
          {
            v48 = (int *)v130;
            if ( (v33 & 0x10) == 0 )
            {
              v33 |= 0x10u;
              if ( v130 + 0x40000000 > 0x3FFFFF )
              {
                *(_DWORD *)v130 = v33;
              }
              else
              {
                v49 = *(_DWORD *)v130;
                v50 = 0;
                __dmb(0xBu);
                *(_DWORD *)v130 = v33;
                if ( (v49 & 2) == 0 && (v33 & 2) != 0 )
                  v50 = 1;
                if ( v130 >= 0xC0300000 && v130 <= 0xC0300FFF )
                {
                  v110 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v110, (_DWORD *)(v110 + 4 * (v130 & 0xFFF)), v33);
                }
                if ( v50 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
              if ( (MiFlags & 0x300) == 0 )
              {
                v51 = 1;
LABEL_61:
                v14 = v124;
                MiInsertTbFlushEntry((int)v124, v128, 1, 0);
                v52 = &v151[24 * v51];
                v53 = *((_DWORD *)v52 + 3);
                *((_DWORD *)v52 + 3) = v127;
                v54 = v152;
                *(_DWORD *)(v127 + 12) = v53;
                v22 = 0;
                v138 = v54;
                goto LABEL_62;
              }
            }
            goto LABEL_83;
          }
          if ( v137 < 3 )
          {
            v51 = 3;
            goto LABEL_61;
          }
          v48 = (int *)v130;
          if ( !MiClearPteAccessed(
                  v44,
                  v34,
                  v130,
                  *(_DWORD *)(v44[23] + 252) + *(_DWORD *)(v44[23] + 36) * v45,
                  v124,
                  dword_634484) )
            goto LABEL_182;
          if ( v130 < 0xC0300000 || v130 > 0xC0300FFF )
            v33 &= 0xFFFFFFEF;
          v109 = (unsigned int)v124;
        }
        else
        {
          if ( v137 < 8 )
          {
            v51 = 2;
            goto LABEL_61;
          }
          v48 = (int *)v130;
          MiMakeCombineCandidateClean(v130, v46);
          MiInsertTbFlushEntry((int)v124, v128, 1, 0);
          v109 = (unsigned int)v124;
        }
        MiFlushTbList(v109, v108);
LABEL_83:
        if ( v134 == qword_634310 && (v47 & 0x18) == 0 )
        {
          v111 = MiReservePtes(&dword_634D58, 1u);
          v112 = v111;
          if ( v111 )
          {
            v113 = (dword_681114 & 0x3ED | (v143 << 12) | MiDetermineUserGlobalPteMask(v111)) & 0xFFFFF3FF | 0x12;
            if ( v112 + 0x40000000 > 0x3FFFFF )
            {
              *(_DWORD *)v112 = v113;
            }
            else
            {
              v114 = *(_DWORD *)v112;
              v115 = 0;
              __dmb(0xBu);
              *(_DWORD *)v112 = v113;
              if ( (v114 & 2) == 0 )
                v115 = 1;
              if ( v112 + 1070596096 <= 0xFFF )
              {
                v116 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v116, (_DWORD *)(v116 + 4 * (v112 & 0xFFF)), v113);
              }
              if ( v115 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
            }
            v117 = MiConvertPrivateToDemandZero(v125, v112 << 10, v45);
            MiReleasePtes(&dword_634D58, v112, 1u);
            if ( v117 )
            {
              ++v129;
              ++v131;
              ++a7[1];
LABEL_182:
              v14 = v124;
              goto LABEL_62;
            }
          }
          v47 = v136;
        }
        if ( (v33 & 0x10) != 0 )
        {
          v62 = v128;
          v14 = v124;
        }
        else
        {
          v118 = v33 | 0x10;
          if ( (unsigned int)(v48 + 0x10000000) > 0x3FFFFF )
          {
            *v48 = v118;
          }
          else
          {
            v119 = *v48;
            v120 = 0;
            __dmb(0xBu);
            *v48 = v118;
            if ( (v119 & 2) == 0 && (v118 & 2) != 0 )
              v120 = 1;
            if ( (unsigned int)(v48 + 267649024) <= 0xFFF )
            {
              v121 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v121, (_DWORD *)(v121 + 4 * ((unsigned __int16)v48 & 0xFFF)), v118);
            }
            if ( v120 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          v62 = v128;
          v14 = v124;
          if ( (MiFlags & 0x300) == 0 )
          {
            MiInsertTbFlushEntry((int)v124, v128, 1, 0);
            MiFlushTbList((unsigned int)v124, v122);
          }
        }
        v63 = -1;
        if ( v22 )
          goto LABEL_159;
        if ( MiComputeHash64(v62) == (_DWORD)v134 && v64 == HIDWORD(v134) )
        {
          v65 = 1;
          if ( v47 >> 3 == 1 )
          {
            v65 = 0;
          }
          else if ( v47 >> 3 == 3 && (v47 & 7) != 0 )
          {
            v65 = 2;
          }
          v39 = *(_DWORD *)(a6 + 4 * v65);
          if ( v39 )
          {
            if ( *(_DWORD *)(v39 + 24) < *(_DWORD *)(v39 + 20) )
            {
              v66 = MiAllocateCombineProto(v126, v64, v134, HIDWORD(v134), v47, 0);
              v22 = (__int64 *)v66;
              if ( v66 )
              {
                v67 = v127;
                *(_DWORD *)(v127 + 16) = v66;
              }
              else
              {
                v22 = *a2;
                v94 = **a2;
                if ( (__int64 **)HIDWORD(v94) != a2 || *(__int64 **)(v94 + 4) != v22 )
                  __fastfail(3u);
                *a2 = (__int64 *)v94;
                *(_DWORD *)(v94 + 4) = a2;
                *((_DWORD *)v22 + 7) = v47;
                v63 = *(_DWORD *)(v39 + 4 * (*(_DWORD *)(v39 + 24) >> 12) + 28);
LABEL_159:
                v67 = v127;
              }
              v68 = MiConvertPrivateToProto(v125, v48, v22 + 4, v126, v14, v63);
              if ( !v68 )
                goto LABEL_62;
              ++a7[1];
              if ( v63 == -1 )
              {
                v22 = 0;
                ++v129;
              }
              else
              {
                *(_DWORD *)(v39 + 24) += 4096;
                v133 = 1;
              }
              *(_DWORD *)(v67 + 8) = v68;
              *(_DWORD *)(v67 + 12) = v138;
              ++v131;
              v138 = v67;
              v152 = v67;
LABEL_99:
              if ( v133 != 1 )
                goto LABEL_62;
              v69 = v134 & 0xF;
              v22[2] = v134;
              v70 = (unsigned int *)&v126[2 * v69 + 13];
              v71 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&v126[2 * v69 + 13]);
              }
              else
              {
                v72 = (unsigned __int8 *)&v126[2 * v69 + 13] + 3;
                do
                  v73 = __ldrex(v72);
                while ( __strex(v73 | 0x80, v72) );
                __dmb(0xBu);
                if ( v73 >> 7 )
                  ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&v126[2 * v69 + 13]);
                while ( 1 )
                {
                  v74 = *v70;
                  if ( (*v70 & 0xBFFFFFFF) == 0x80000000 )
                    break;
                  if ( (v74 & 0x40000000) == 0 )
                  {
                    do
                      v123 = __ldrex(v70);
                    while ( v123 == v74 && __strex(v74 | 0x40000000, v70) );
                    __dmb(0xBu);
                  }
                  __dmb(0xAu);
                  __yield();
                }
              }
              v75 = v69 + 6;
              v76 = v126[2 * v69 + 12];
              v77 = 0;
              if ( v76 )
              {
                while ( 1 )
                {
                  if ( MiCombineCompare(v22, v76) >= 0 )
                  {
                    v78 = (__int16 *)*((_DWORD *)v76 + 1);
                    if ( !v78 )
                    {
                      v77 = 1;
                      break;
                    }
                  }
                  else
                  {
                    v78 = *(__int16 **)v76;
                    if ( !*(_DWORD *)v76 )
                    {
                      v77 = 0;
                      break;
                    }
                  }
                  v76 = v78;
                }
              }
              RtlAvlInsertNodeEx((int)&v126[2 * v75], (int)v76, v77, v22);
              if ( (dword_682604 & 0x10000) != 0 )
              {
                ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v70);
              }
              else
              {
                __dmb(0xBu);
                *v70 = 0;
              }
              KfLowerIrql(v71);
              v22 = 0;
LABEL_155:
              v14 = v124;
              goto LABEL_62;
            }
          }
        }
LABEL_62:
        v13 = v146;
      }
    }
    result = MiUnlockWorkingSetExclusive((int)v9, v142);
    v7 = a7;
    v18 = v140;
  }
  if ( v18 == 1 )
  {
    KiUnstackDetachProcess((unsigned int)v149, 1);
    result = MiAttachThreadDone(v17 + 492, v59, v60, v61);
  }
  if ( v14 != v150 )
    result = ExFreePoolWithTag(v14, 0);
  *v7 += v129;
  return result;
}
