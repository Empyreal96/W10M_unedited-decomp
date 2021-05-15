// MiBuildForkPte 
 
BOOL __fastcall MiBuildForkPte(unsigned int *a1, int a2, unsigned int a3, unsigned int *a4, int a5, unsigned int *a6, _DWORD *a7, _WORD *a8, unsigned int a9, int a10, int a11, int a12, unsigned __int8 a13, _DWORD *a14)
{
  unsigned int v14; // r6
  int v17; // r4
  _WORD *v18; // r0
  BOOL v19; // r5
  int v20; // r0
  int v21; // r1
  int v22; // r9
  _DWORD *v23; // r5
  unsigned int *v24; // r8
  _DWORD *v25; // r2
  int v26; // r9
  unsigned int v27; // r0
  int v28; // r3
  unsigned int v29; // r3
  unsigned int v30; // lr
  int v31; // r4
  unsigned int *v32; // r4
  __int16 v33; // r1
  int v34; // r3
  int v35; // r1
  unsigned __int8 *v36; // r3
  unsigned int v37; // r1
  unsigned int v38; // r0
  unsigned int v39; // r1
  int v40; // r0
  int v41; // r9
  int v42; // r3
  unsigned int *v43; // r4
  unsigned __int8 *v44; // r3
  unsigned int v45; // r1
  unsigned int v46; // r0
  unsigned int v47; // r1
  unsigned __int8 *v48; // r1
  unsigned int v49; // r2
  int v50; // r3
  unsigned int *v51; // r2
  unsigned int v52; // r0
  unsigned __int8 *v53; // r1
  unsigned int v54; // r2
  int v55; // r3
  unsigned int v56; // r1
  char v57; // r3
  unsigned int v58; // r3
  int v59; // r2
  int v60; // r3
  unsigned int *v61; // r2
  unsigned int v62; // r5
  unsigned int v63; // r3
  int v64; // r0
  int v65; // r0
  _DWORD *v66; // r2
  unsigned int v67; // r2
  int v68; // r0
  unsigned int *v69; // r2
  unsigned int v70; // r0
  int v71; // r1
  unsigned int v72; // r5
  unsigned int v73; // r4
  unsigned int *v74; // r2
  unsigned int v75; // r1
  unsigned int *v76; // r2
  unsigned int v77; // r1
  unsigned int v78; // r1
  int v79; // r0
  bool v80; // zf
  int v81; // r4
  unsigned __int8 *v82; // r1
  unsigned int v83; // r2
  int v84; // r3
  unsigned int *v85; // r2
  unsigned int v86; // r0
  int v87; // r2
  int v88; // r4
  int v89; // r0
  unsigned int v90; // r4
  int v91; // r0
  int v92; // r0
  unsigned int *v93; // r2
  unsigned int v94; // r0
  unsigned int v95; // r3
  int v96; // r4
  bool v97; // zf
  int v98; // r0
  int v99; // r0
  unsigned int v100; // r3
  int v101; // r2
  unsigned int v102; // r4
  unsigned int *v103; // r2
  unsigned int v104; // r1
  unsigned int *v105; // r2
  unsigned int v106; // r1
  unsigned int v107; // r1
  unsigned int v108; // r3
  int v109; // r4
  int v110; // r0
  int v112; // [sp+20h] [bp-60h]
  int v114; // [sp+30h] [bp-50h]
  int v115; // [sp+34h] [bp-4Ch] BYREF
  int v116; // [sp+38h] [bp-48h] BYREF
  int v117; // [sp+3Ch] [bp-44h]
  int v118; // [sp+40h] [bp-40h]
  unsigned int v119; // [sp+44h] [bp-3Ch]
  _DWORD *v120; // [sp+48h] [bp-38h]
  _WORD *v121; // [sp+50h] [bp-30h] BYREF
  __int16 v122; // [sp+54h] [bp-2Ch]
  unsigned __int16 v123; // [sp+56h] [bp-2Ah]
  int v124[10]; // [sp+58h] [bp-28h] BYREF

  v14 = *(_DWORD *)a3;
  if ( !*(_DWORD *)a3 )
  {
    if ( a5 )
    {
      if ( *(int *)(a11 + 32) < 0 )
      {
        v17 = MiFindZeroCloneBlock(a5, (unsigned __int8)*(_DWORD *)(a10 + 28) >> 3);
        if ( v17 )
        {
          v18 = MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(a8, 1u);
          MiWriteSharedDemandZeroPte(v18, v17, a4, a14);
        }
      }
    }
    return 0;
  }
  MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(a8, 1u);
  v20 = 0;
  v21 = 0;
  v112 = -1;
  v115 = 0;
  v116 = -1;
  v118 = -1073741824;
  v22 = a13;
  v23 = a14;
  v24 = a6;
  v114 = a13;
  while ( 1 )
  {
    while ( 1 )
    {
      v25 = a7;
      if ( v20 == 1 )
      {
        MiMakeSystemAddressValid(a3, 0, (int)a7, v22, 1);
        v14 = *(_DWORD *)a3;
        v21 = v115;
        v25 = a7;
      }
      v117 = 1;
      if ( (v14 & 2) == 0 )
        break;
      v26 = MmPfnDatabase + 24 * (v14 >> 12);
      if ( v21 == 1 || *(unsigned __int16 *)(v26 + 16) > 1u && (*(_DWORD *)(v26 + 20) & 0x8000000) == 0 )
      {
        v32 = a1 + 123;
        MI_INITIALIZE_COLOR_BASE((int)(a1 + 123), 0, (int)&v121);
        v33 = *v121 + 1;
        v34 = v112;
        *v121 = v33;
        if ( v112 != -1
          || (v34 = MiGetPage((int)MiSystemPartition, (unsigned __int16)(v122 & v33) | v123, 0),
              v112 = v34,
              v116 = v34,
              v34 != -1) )
        {
          v81 = MmPfnDatabase + 24 * v34;
          v82 = (unsigned __int8 *)(v81 + 15);
          do
            v83 = __ldrex(v82);
          while ( __strex(v83 | 0x80, v82) );
          while ( 1 )
          {
            __dmb(0xBu);
            if ( !(v83 >> 7) )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
              v84 = *(_DWORD *)(v81 + 12);
              __dmb(0xBu);
            }
            while ( (v84 & 0x80000000) != 0 );
            do
              v83 = __ldrex(v82);
            while ( __strex(v83 | 0x80, v82) );
          }
          MiFinalizePageAttribute(v81, *(unsigned __int8 *)(v26 + 18) >> 6, 1);
          __dmb(0xBu);
          v85 = (unsigned int *)(v81 + 12);
          do
            v86 = __ldrex(v85);
          while ( __strex(v86 & 0x7FFFFFFF, v85) );
          MiDuplicateCloneLeaf(a3, a4, v112, v114, 17);
          ++*a7;
          return 0;
        }
        MiFlushTbList(a9, v35);
        MiUnlockWorkingSetExclusive((int)v32, v114);
        MiWaitForFreePage((int)MiSystemPartition);
        v22 = KfRaiseIrql(2);
        v114 = v22;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v32);
LABEL_33:
          v21 = v115;
          goto LABEL_34;
        }
        v36 = (unsigned __int8 *)a1 + 495;
        do
          v37 = __ldrex(v36);
        while ( __strex(v37 | 0x80, v36) );
        __dmb(0xBu);
        if ( v37 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v32);
        while ( 1 )
        {
          v38 = *v32;
          if ( (*v32 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v38 & 0x40000000) == 0 )
          {
            do
              v39 = __ldrex(v32);
            while ( v39 == v38 && __strex(v38 | 0x40000000, v32) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
LABEL_32:
        v23 = a14;
        goto LABEL_33;
      }
      v27 = MiLocateWsle(a3 << 10, (int)(a1 + 123), *(_DWORD *)v26);
      v28 = *(_DWORD *)(v26 + 20);
      v120 = (_DWORD *)(MEMORY[0xC0402024] * v27 - 1069537344);
      if ( (v28 & 0x8000000) != 0 )
      {
        v71 = *(_DWORD *)(v26 + 4);
        v72 = v71 | 0x80000000;
        if ( (*(_DWORD *)(MEMORY[0xC0402024] * v27 - 1069537344) & 0x1F0) != 0 )
          v73 = 2 * (*(_DWORD *)(MEMORY[0xC0402024] * v27 - 1069537344) & 0x1F0 | 0xFFFFF200);
        else
          v73 = *(_DWORD *)(v26 + 4) & 0x1FC | (4 * ((*(_DWORD *)(v26 + 4) | 0x80000000) & 0xFFFFFE00 | 0x100));
        if ( (v71 & 0x80000000) != 0 )
        {
          if ( MiLocateCloneAddress((int)a1) )
          {
            v74 = (unsigned int *)(v72 + 12);
            do
              v75 = __ldrex(v74);
            while ( __strex(v75 + 1, v74) );
            if ( (a12 & 1) != 0 )
            {
              v73 |= 0x200u;
              __dmb(0xBu);
              v76 = (unsigned int *)(v72 + 8);
              do
              {
                v77 = __ldrex(v76);
                v78 = v77 + 1;
              }
              while ( __strex(v78, v76) );
              __dmb(0xBu);
              if ( (v78 & 0x7FFFFFF) == 1 )
                ++a14[1];
              else
                ++*a14;
            }
          }
        }
        else
        {
          MiIncrementCombinedPte(v71 | 0x80000000);
        }
        if ( (unsigned int)(a4 + 0x10000000) <= 0x3FFFFF )
        {
          __dmb(0xBu);
          *a4 = v73;
          if ( (unsigned int)(a4 + 267649024) <= 0xFFF )
          {
            v79 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v79, (_DWORD *)(v79 + 4 * ((unsigned __int16)a4 & 0xFFF)), v73);
          }
          v80 = 0;
          goto LABEL_220;
        }
        *a4 = v73;
LABEL_224:
        v19 = 0;
        goto LABEL_225;
      }
      v29 = *(_DWORD *)((((unsigned int)v24 >> 10) & 0x3FFFFC) + v118);
      v30 = 0;
      v115 = 0;
      v119 = v29;
      v31 = MmPfnDatabase + 24 * (v29 >> 12);
      if ( v27 >= MEMORY[0xC0402004] )
        goto LABEL_56;
      if ( MiLockPageTablePage(v31, 2) )
      {
        v30 = 0;
LABEL_56:
        v48 = (unsigned __int8 *)(v31 + 15);
        do
          v49 = __ldrex(v48);
        while ( __strex(v49 | 0x80, v48) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v49 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
            v50 = *(_DWORD *)(v31 + 12);
            __dmb(0xBu);
          }
          while ( (v50 & 0x80000000) != 0 );
          do
            v49 = __ldrex(v48);
          while ( __strex(v49 | 0x80, v48) );
        }
        *(_DWORD *)(v31 + 12) = *(_DWORD *)(v31 + 12) & 0xC0000000 | (*(_DWORD *)(v31 + 12) + 1) & 0x3FFFFFFF;
        __dmb(0xBu);
        v51 = (unsigned int *)(v31 + 12);
        do
          v52 = __ldrex(v51);
        while ( __strex(v52 & 0x7FFFFFFF, v51) );
        v53 = (unsigned __int8 *)(v26 + 15);
        do
          v54 = __ldrex(v53);
        while ( __strex(v54 | 0x80, v53) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v54 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
            v55 = *(_DWORD *)(v26 + 12);
            __dmb(0xBu);
          }
          while ( (v55 & 0x80000000) != 0 );
          do
            v54 = __ldrex(v53);
          while ( __strex(v54 | 0x80, v53) );
        }
        if ( (v14 & 0x200) == 0 )
        {
          if ( (*(_DWORD *)(a10 + 28) & 7) == 4 && (*(_DWORD *)(v26 + 20) & 0x8000000) == 0 )
            MiCaptureWriteWatchDirtyBit(a1, a3 << 10, a10);
          v30 = MiCaptureDirtyBitToPfn(v26);
          v115 = v30;
          v14 |= 0x200u;
        }
        v56 = *(_DWORD *)(v26 + 8);
        if ( (v56 & 8) != 0 )
        {
          v57 = 2;
          if ( v30 )
            v57 = 3;
          MI_SET_PAGING_FILE_INFO(
            &v115,
            (_DWORD *)(v26 + 8),
            *(_DWORD *)&MiSystemPartition[2 * ((v56 >> 2) & 1) + 1800],
            v56 >> 13,
            v57);
          v30 = v115;
          *(_DWORD *)(v26 + 8) &= 0xFFFFFFF7;
        }
        v58 = v119;
        v59 = *(_DWORD *)(v26 + 20);
        *(_DWORD *)(v26 + 4) = v24;
        *(_DWORD *)(v26 + 20) = v59 & 0xFFF00000 | (v58 >> 12) | 0x8000000;
        v60 = *(_DWORD *)(v26 + 8);
        if ( (v60 & 0x80) != 0 )
          *(_DWORD *)(v26 + 8) = v60 | 0x20;
        v119 = (*(_DWORD *)(v26 + 8) >> 5) & 0x1F;
        __dmb(0xBu);
        v61 = (unsigned int *)(v26 + 12);
        do
          v62 = __ldrex(v61);
        while ( __strex(v62 & 0x7FFFFFFF, v61) );
        if ( v30 )
          MiReleasePageFileInfo((int)MiSystemPartition, v30, 1, 0);
        if ( (v14 & 0x80) != 0 )
          v14 = v14 & 0xFFFFFE7F | 0x100;
        if ( a3 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)a3 = v14;
        }
        else
        {
          v63 = *(_DWORD *)a3;
          v117 = 0;
          __dmb(0xBu);
          *(_DWORD *)a3 = v14;
          if ( (v63 & 2) == 0 && (v14 & 2) != 0 )
            v117 = 1;
          if ( a3 + 1070596096 <= 0xFFF )
          {
            v64 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v64, (_DWORD *)(v64 + 4 * (a3 & 0xFFF)), v14);
          }
          if ( v117 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        MiInsertTbFlushEntry(a9, a3 << 10, 1, 0);
        *v24 = 0;
        if ( (unsigned int)(v24 + 0x10000000) > 0x3FFFFF )
        {
          *v24 = v14;
        }
        else
        {
          v117 = 0;
          __dmb(0xBu);
          *v24 = v14;
          if ( (v14 & 2) != 0 )
            v117 = 1;
          if ( (unsigned int)(v24 + 267649024) <= 0xFFF )
          {
            v65 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v65, (_DWORD *)(v65 + 4 * ((unsigned __int16)v24 & 0xFFF)), v14);
          }
          if ( v117 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        v66 = v120;
        v24[3] = 2;
        *v66 &= 0xFFFFFE0F;
        v67 = *(_DWORD *)(v26 + 4) & 0x1FC | (4 * (*(_DWORD *)(v26 + 4) & 0xFFFFFE00 | 0x100));
        if ( (a12 & 1) != 0 )
        {
          v24[2] = 1;
          v67 |= 0x200u;
          ++a14[1];
        }
        else
        {
          v24[2] = 0;
        }
        v24[2] = v24[2] & 0x7FFFFFF | (v119 << 27);
        if ( (unsigned int)(a4 + 0x10000000) > 0x3FFFFF )
        {
          *a4 = v67;
        }
        else
        {
          __dmb(0xBu);
          *a4 = v67;
          if ( (unsigned int)(a4 + 267649024) <= 0xFFF )
          {
            v68 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v68, (_DWORD *)(v68 + 4 * ((unsigned __int16)a4 & 0xFFF)), v67);
          }
        }
        v69 = a1 + 69;
        do
          v70 = __ldrex(v69);
        while ( __strex(v70 - 1, v69) );
        --a1[139];
        if ( (a3 << 10) + 0x40000000 > 0x3FFFFF )
          --a1[137];
LABEL_116:
        v19 = 1;
        goto LABEL_225;
      }
      v21 = 1;
      v22 = v114;
      v115 = 1;
LABEL_34:
      v20 = v117;
    }
    if ( (v14 & 0x400) != 0 )
    {
      v101 = (v14 >> 2) & 0x3FFFFE00;
      v102 = (v14 & 0x1FC | v101) - 0x40000000;
      if ( (v14 & 0xFFFFE000) == -8192 || v102 < dword_640484 || v102 >= dword_640488 )
      {
        if ( MiLocateCloneAddress((int)a1) )
        {
          __dmb(0xBu);
          v103 = (unsigned int *)(v102 + 12);
          do
            v104 = __ldrex(v103);
          while ( __strex(v104 + 1, v103) );
          __dmb(0xBu);
          if ( (a12 & 1) != 0 )
          {
            if ( (*(_DWORD *)(v102 + 8) & 0xF8000000) != v118 )
              v14 |= 0x200u;
            __dmb(0xBu);
            v105 = (unsigned int *)(v102 + 8);
            do
            {
              v106 = __ldrex(v105);
              v107 = v106 + 1;
            }
            while ( __strex(v107, v105) );
            __dmb(0xBu);
            if ( (v107 & 0x7FFFFFF) == 1 )
              ++v23[1];
            else
              ++*v23;
          }
        }
      }
      else
      {
        MiIncrementCombinedPte((v14 & 0x1FC | v101) - 0x40000000);
      }
      if ( (unsigned int)(a4 + 0x10000000) > 0x3FFFFF )
      {
        *a4 = v14;
      }
      else
      {
        v108 = *a4;
        v109 = 0;
        __dmb(0xBu);
        *a4 = v14;
        if ( (v108 & 2) == 0 && (v14 & 2) != 0 )
          v109 = 1;
        if ( (unsigned int)(a4 + 267649024) <= 0xFFF )
        {
          v110 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v110, (_DWORD *)(v110 + 4 * ((unsigned __int16)a4 & 0xFFF)), v14);
        }
        v80 = v109 == 1;
LABEL_220:
        if ( v80 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      goto LABEL_224;
    }
    if ( (v14 & 0x800) == 0 )
      break;
    v40 = MiHandleForkTransitionPte(a1, v21, a3, a4, v24, v25, a9, &v116, a12, v22, v23);
    if ( v40 )
    {
      v87 = v116;
      v19 = v40 != 1;
      goto LABEL_226;
    }
    v21 = v115;
    v20 = v117;
    v112 = v116;
  }
  v19 = 0;
  v41 = (v14 >> 5) & 0x1F;
  if ( (v14 & 0x10) != 0 )
  {
    if ( v41 == 16 )
    {
      if ( (v14 & 8) != 0 )
        v14 &= 0xFFFFFFF7;
      if ( (unsigned int)(a4 + 0x10000000) <= 0x3FFFFF )
      {
        v95 = *a4;
        v96 = 0;
        __dmb(0xBu);
        *a4 = v14;
        if ( (v95 & 2) == 0 )
        {
          v97 = (v14 & 2) == 0;
LABEL_181:
          if ( !v97 )
            v96 = 1;
        }
        goto LABEL_183;
      }
LABEL_187:
      *a4 = v14;
      goto LABEL_225;
    }
    v42 = (v14 >> 5) & 0x18;
    if ( v42 != 16 )
    {
      if ( (v14 & 0x80) != 0 )
        v14 |= 0x20u;
      if ( (v14 & 8) != 0 )
      {
        MiReleasePageFileInfo((int)MiSystemPartition, v14 & 0xFFFFFFEF, 1, v42);
        v14 &= 0xFFFFFFF7;
      }
      *v24 = 0;
      if ( (unsigned int)(v24 + 0x10000000) > 0x3FFFFF )
      {
        *v24 = v14;
      }
      else
      {
        v88 = 0;
        __dmb(0xBu);
        if ( (v14 & 2) != 0 )
          v88 = 1;
        *v24 = v14;
        if ( (unsigned int)(v24 + 267649024) <= 0xFFF )
        {
          v89 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v89, (_DWORD *)(v89 + 4 * ((unsigned __int16)v24 & 0xFFF)), v14);
        }
        if ( v88 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v24[3] = 2;
      v90 = (unsigned __int16)v24 & 0x1FC | (4 * ((unsigned int)v24 & 0xFFFFFE00 | 0x100));
      if ( a3 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)a3 = v90;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)a3 = v90;
        if ( a3 + 1070596096 <= 0xFFF )
        {
          v91 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(
            v91,
            (_DWORD *)(v91 + 4 * (a3 & 0xFFF)),
            (unsigned __int16)v24 & 0x1FC | (4 * ((unsigned __int16)v24 & 0xFE00 | 0x100)));
        }
      }
      if ( (a12 & 1) != 0 )
      {
        if ( v41 != 24 )
          v90 |= 0x200u;
        v24[2] = 1;
        ++a14[1];
      }
      else
      {
        v24[2] = 0;
      }
      v24[2] = v24[2] & 0x7FFFFFF | (v41 << 27);
      if ( (unsigned int)(a4 + 0x10000000) > 0x3FFFFF )
      {
        *a4 = v90;
      }
      else
      {
        __dmb(0xBu);
        *a4 = v90;
        if ( (unsigned int)(a4 + 267649024) <= 0xFFF )
        {
          v92 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v92, (_DWORD *)(v92 + 4 * ((unsigned __int16)a4 & 0xFFF)), v90);
        }
      }
      v93 = a1 + 69;
      do
        v94 = __ldrex(v93);
      while ( __strex(v94 - 1, v93) );
      goto LABEL_116;
    }
    MiFlushTbList(a9, v21);
    v43 = a1 + 123;
    MiUnlockWorkingSetExclusive((int)(a1 + 123), v114);
    v124[0] = a3 << 10;
    v124[1] = 4096;
    MiPrefetchVirtualMemory(1, (int)v124, (int)(a1 + 123), 45);
    v22 = KfRaiseIrql(2);
    v114 = v22;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v43);
    }
    else
    {
      v44 = (unsigned __int8 *)a1 + 495;
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 | 0x80, v44) );
      __dmb(0xBu);
      if ( v45 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v43);
      while ( 1 )
      {
        v46 = *v43;
        if ( (*v43 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v46 & 0x40000000) == 0 )
        {
          do
            v47 = __ldrex(v43);
          while ( v47 == v46 && __strex(v46 | 0x40000000, v43) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v24 = a6;
    }
    goto LABEL_32;
  }
  if ( (v14 & 8) != 0 )
    v14 &= 0xFFFFFFF7;
  if ( a5 )
    v99 = MiFindZeroCloneBlock(a5, v41);
  else
    v99 = 0;
  if ( v99 )
  {
    MiWriteSharedDemandZeroPte(v99, v99, a4, a14);
  }
  else
  {
    if ( (unsigned int)(a4 + 0x10000000) > 0x3FFFFF )
      goto LABEL_187;
    v100 = *a4;
    v96 = 0;
    __dmb(0xBu);
    *a4 = v14;
    if ( (v100 & 2) == 0 )
    {
      v97 = (v14 & 2) == 0;
      goto LABEL_181;
    }
LABEL_183:
    if ( (unsigned int)(a4 + 267649024) <= 0xFFF )
    {
      v98 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v98, (_DWORD *)(v98 + 4 * ((unsigned __int16)a4 & 0xFFF)), v14);
    }
    if ( v96 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
LABEL_225:
  v87 = v112;
LABEL_226:
  if ( v87 != -1 )
    MiLockAndInsertPageInFreeList(MmPfnDatabase + 24 * v87);
  return v19;
}
