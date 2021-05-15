// MiDecommitPages 
 
int __fastcall MiDecommitPages(unsigned int a1, unsigned int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v7; // lr
  _DWORD *v8; // r7
  int v9; // r0
  int v11; // r4
  int v12; // r5
  unsigned int v13; // r10
  int v14; // r8
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r7
  unsigned int v20; // r6
  int v21; // r4
  unsigned int v22; // r5
  int v23; // r2
  unsigned int v24; // r6
  unsigned int v25; // r5
  _DWORD *v26; // r7
  int v27; // r2
  unsigned int v28; // r0
  unsigned int v29; // r9
  _DWORD *v30; // r6
  int v31; // r4
  unsigned int v32; // r0
  unsigned int *v33; // r4
  unsigned int v34; // r6
  unsigned int v35; // r3
  unsigned int v36; // r0
  unsigned int v37; // r2
  unsigned int v38; // r1
  int v39; // r1
  unsigned int v40; // r6
  int v41; // r1
  unsigned int v42; // r2
  unsigned int v43; // r5
  int v44; // r4
  unsigned int v45; // r7
  unsigned int v46; // r3
  int v47; // r1
  _DWORD *v48; // r4
  int v49; // r6
  int v50; // r7
  int v51; // r8
  int v52; // r2
  unsigned int v53; // r3
  int v54; // r4
  int v55; // r4
  int v56; // r4
  unsigned __int8 *v57; // r3
  unsigned int v58; // r1
  unsigned int v59; // r0
  int v60; // r4
  int v61; // r2
  unsigned int v62; // r4
  int v63; // r0
  int v64; // r5
  unsigned int *v65; // r2
  unsigned int v66; // r0
  unsigned int v67; // r3
  __int64 v68; // kr00_8
  int v69; // r7
  int v70; // r3
  unsigned int *v71; // r8
  unsigned int *v72; // r2
  unsigned int *v73; // r2
  unsigned int v74; // r0
  unsigned int v75; // r4
  int v76; // r0
  unsigned int v77; // r1
  unsigned int v78; // r1
  unsigned int *v79; // r5
  unsigned int v80; // r1
  unsigned int v81; // r2
  int v82; // r6
  unsigned __int8 *v83; // r3
  unsigned int v84; // r1
  unsigned int v85; // r0
  unsigned int v86; // r1
  int v87; // r0
  int v88; // r0
  int *v89; // r6
  int v90; // r1
  unsigned int v91; // r2
  unsigned int v92; // r0
  unsigned int v93; // r1
  int v94; // r0
  __int16 v95; // r3
  int v96; // r2
  __int16 v97; // r3
  int v98; // r0
  int v99; // r2
  int v100; // [sp+0h] [bp-4A0h]
  unsigned int v101; // [sp+10h] [bp-490h]
  int v103; // [sp+18h] [bp-488h]
  int v104; // [sp+20h] [bp-480h] BYREF
  int v105; // [sp+24h] [bp-47Ch]
  int v106; // [sp+28h] [bp-478h]
  int v107; // [sp+2Ch] [bp-474h]
  int v108; // [sp+30h] [bp-470h] BYREF
  unsigned int v109; // [sp+34h] [bp-46Ch]
  unsigned int v110; // [sp+38h] [bp-468h]
  unsigned int i; // [sp+3Ch] [bp-464h]
  int v112; // [sp+40h] [bp-460h]
  _DWORD v113[3]; // [sp+48h] [bp-458h] BYREF
  int v114; // [sp+54h] [bp-44Ch]
  int v115; // [sp+58h] [bp-448h]
  int v116; // [sp+5Ch] [bp-444h]
  int v117; // [sp+60h] [bp-440h]
  _DWORD *v118; // [sp+64h] [bp-43Ch]
  int v119; // [sp+68h] [bp-438h] BYREF
  char v120; // [sp+6Ch] [bp-434h]
  char v121; // [sp+6Dh] [bp-433h]
  unsigned int v122; // [sp+70h] [bp-430h]
  unsigned int v123; // [sp+74h] [bp-42Ch]
  unsigned int v124; // [sp+78h] [bp-428h]
  int v125[265]; // [sp+7Ch] [bp-424h] BYREF

  v123 = 0;
  v121 = 0;
  v125[0] = 0;
  v114 = 0;
  v7 = a3;
  v112 = 1;
  v110 = a2;
  v8 = a6;
  v122 = 256;
  v9 = *(_DWORD *)(a4 + 32);
  v119 = 1;
  v108 = 512;
  v120 = 0;
  v124 = 0;
  if ( (v9 & 0x7FFFFFFF) == 524286 )
    return sub_5315B0();
  if ( (v9 & 0x80000000) != 0 )
  {
    v109 = 4 * ((*(_DWORD *)(a4 + 16) & 0xFFFFF) - 0x10000000);
    v11 = 0;
  }
  else
  {
    v109 = 0;
    v11 = MiVadPureReserve(a4);
    v7 = a3;
    v114 = v11;
  }
  if ( !a5 )
    v112 = 3;
  v12 = 4194300;
  v101 = a1 & 0xFFFFF000;
  v106 = 4194300;
  v13 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  __mrc(15, 0, 13, 0, 3);
  v14 = v7 + 492;
  v105 = v7 + 492;
  v103 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7 + 492);
  }
  else
  {
    v15 = (unsigned __int8 *)(v7 + 495);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 | 0x80, v15) );
    __dmb(0xBu);
    if ( v16 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v7 + 492));
    while ( 1 )
    {
      v17 = *(_DWORD *)v14;
      if ( (*(_DWORD *)v14 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v17 & 0x40000000) == 0 )
      {
        do
          v78 = __ldrex((unsigned int *)v14);
        while ( v78 == v17 && __strex(v17 | 0x40000000, (unsigned int *)v14) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v13 > v110 )
    goto LABEL_93;
  v117 = -2147483647;
  v115 = 0x8000000;
  v107 = 0xFFFFF;
  v116 = 0x7FFFF;
  v18 = ((v110 >> 10) & 0x3FFFFC) - 0x40000000;
  for ( i = v18; ; v18 = i )
  {
    if ( v123 )
    {
      MiDeletePteList(&v119, a3, 512, v8, v100);
      v18 = i;
    }
    if ( v11 )
      break;
    v55 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    while ( !MiIsAddressValid(v13, 1) )
    {
      v79 = (unsigned int *)(v55 + 492);
      if ( (v112 & 1) != 0 )
      {
        MiUnlockWorkingSetExclusive(v55 + 492, v103);
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v55 + 492);
        }
        else
        {
          __dmb(0xBu);
          do
            v80 = __ldrex(v79);
          while ( __strex(v80 & 0xBFFFFFFF, v79) );
          __dmb(0xBu);
          do
            v81 = __ldrex(v79);
          while ( __strex(v81 - 1, v79) );
        }
        KfLowerIrql(v103);
      }
      v82 = MmAccessFault(v117, v13, 0, 0);
      if ( v82 < 0 )
      {
        MmFlushAllFilesystemPages(1);
        KeBugCheckEx(122, 1, v82);
      }
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v55 + 492);
      }
      else
      {
        v83 = (unsigned __int8 *)(v55 + 495);
        do
          v84 = __ldrex(v83);
        while ( __strex(v84 | 0x80, v83) );
        __dmb(0xBu);
        if ( v84 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v55 + 492));
        while ( 1 )
        {
          v85 = *v79;
          if ( (*v79 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v85 & 0x40000000) == 0 )
          {
            do
              v86 = __ldrex(v79);
            while ( v86 == v85 && __strex(v85 | 0x40000000, v79) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    v24 = v101;
LABEL_30:
    v25 = *(_DWORD *)v13;
    if ( !*(_DWORD *)v13 )
    {
      MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * ((v24 >> 22) - 534769440)), 1u);
      if ( v13 > v109 )
        ++v8[3];
      if ( v13 + 0x40000000 <= 0x3FFFFF )
      {
        v60 = 0;
        __dmb(0xBu);
        v61 = 512;
        *(_DWORD *)v13 = 512;
        if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
          goto LABEL_205;
        goto LABEL_122;
      }
      goto LABEL_206;
    }
    if ( (v25 & 2) != 0 )
    {
      v27 = *(_DWORD *)(MmPfnDatabase + 24 * (v25 >> 12));
      v118 = *(_DWORD **)(v14 + 92);
      v26 = v118;
      v28 = MiLocateWsle(v24, v14, v27);
      v29 = v28;
      if ( (*(_DWORD *)(v26[9] * v28 + v26[63]) & 8) != 0
        && (*(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)((v106 & (v24 >> 10)) - 0x40000000) >> 12) + 20) & 0x8000000) == 0 )
      {
        --*(_DWORD *)(v14 + 64);
        if ( v24 < 0xC0000000 || v24 > 0xC03FFFFF )
          --*(_DWORD *)(v14 + 56);
      }
      v30 = *(_DWORD **)(v14 + 92);
      if ( v28 > v30[4] )
        KeBugCheckEx(26, 268165, v30);
      v31 = *(_DWORD *)(v28 * v30[9] + v30[63]);
      if ( (v31 & 1) == 0 )
        KeBugCheckEx(26, 20496, *(_DWORD *)(v14 + 92));
      v32 = v31 & 0xFFFFF000;
      if ( (int *)v14 == &dword_634F00 )
      {
        if ( PsNtosImageBase
          && (v32 >= PsNtosImageBase && v32 < PsNtosImageEnd || v32 >= PsHalImageBase && v32 < PsHalImageEnd) )
        {
          --dword_632F50;
        }
        else if ( v32 >= dword_63389C
               && *((_BYTE *)&MiState[2423]
                  + ((int)(((v32 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 12 )
        {
          --dword_632F54;
        }
      }
      if ( (v31 & 8) == 0 && (v31 & 4) != 0 )
        MiUpdateWsleHash(v32, v29, v14, 1);
      if ( (dword_682604 & v115) != 0 )
        MiLogRemoveWsleEvent(v31, *(_BYTE *)(v14 + 112) & 7);
      *(_DWORD *)(v29 * v30[9] + v30[63]) = v31 & 0xFFFFFFFE;
      v33 = *(unsigned int **)(v14 + 92);
      v34 = v33[1];
      if ( v29 >= v34 )
      {
        v35 = v33[9];
        v36 = v33[63];
        v37 = v36 + v35 * v29;
        v38 = *(_DWORD *)v37;
        if ( v35 == 16 && (int)(16 * v29) >> 4 >= v34 )
        {
          v68 = *(_QWORD *)(v37 + 4);
          v69 = 2 * ((v38 >> 9) & 7);
          if ( v38 < 0xC0000000 || v38 > 0xC03FFFFF )
            ++v69;
          v70 = v107;
          v71 = &v33[2 * v69];
          if ( HIDWORD(v68) == v107 )
          {
            v71[31] = v68;
          }
          else
          {
            *(_DWORD *)(v36 + 16 * HIDWORD(v68) + 4) = v68;
            v70 = v107;
          }
          if ( (_DWORD)v68 == v70 )
            v71[32] = HIDWORD(v68);
          else
            *(_DWORD *)(v36 + 16 * v68 + 8) = HIDWORD(v68);
          v72 = &v33[v69];
          v26 = v118;
          v14 = v105;
          --v72[15];
        }
        v39 = (v38 >> 9) & 7;
        if ( v39 )
        {
          --*(_DWORD *)(v14 + 4 * (v39 - 1) + 20);
          if ( v39 == 7 )
            MiVolunteerForTrimFirst(v14, -1);
        }
      }
      v40 = *v33;
      if ( *v33 != v107 )
      {
        if ( v40 < v33[1] || v40 > v33[4] )
          KeBugCheckEx(26, 20484, v33);
        *(_DWORD *)(v33[9] * v40 + v33[63]) ^= (*(_DWORD *)(v33[9] * v40 + v33[63]) ^ (2 * v29)) & 0xFFE;
      }
      v41 = (v40 << 12) | 0xFFE;
      v24 = v101;
      *(_DWORD *)(v33[9] * v29 + v33[63]) = v41;
      *v33 = v29;
      --*(_DWORD *)(v14 + 60);
      if ( v101 < 0xC0000000 || v101 > 0xC03FFFFF )
        --*(_DWORD *)(v14 + 52);
      if ( v29 < v26[1] )
        MiRemoveLockedPageFromWorkingSet(
          v14,
          v101,
          v29,
          MmPfnDatabase + 24 * (*(_DWORD *)((v106 & (v101 >> 10)) - 0x40000000) >> 12));
      v42 = v25 & 0xFFFFFFFC | 0x400;
      if ( v13 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v13 = v42;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v13 = v42;
        if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
        {
          v88 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v88, v88 + 4 * (v13 & 0xFFF), v42);
        }
      }
      v43 = v123;
      v44 = 1;
      v45 = v101;
      if ( v123 )
      {
        v89 = &v119 + v123;
        v90 = v89[4];
        if ( (v90 & 0x800) != 0
          || (v91 = v89[4] & 0x7FF, v92 = v91 + 1, (v90 & 0xFFFFF000) + ((v91 + 1) << 12) != v101)
          || v92 <= v91
          || v92 > 0x7FF )
        {
          v24 = v101;
          if ( (v90 & 0x800) != 0 )
            goto LABEL_56;
          if ( (v90 & 0xFFFFF000) != v101 + 4096 )
            goto LABEL_56;
          v93 = v90 & 0x7FF;
          if ( v93 + 1 <= v93 || v93 + 1 > 0x7FF )
            goto LABEL_56;
          MiMergeTbFlushEntryBackwards((int)&v119, v93, 1);
          v46 = v122;
          v43 = v123;
        }
        else
        {
          ++v124;
          v89[4] = v90 & 0xFFFFF800 | (v90 + 1) & 0x7FF;
          v46 = v122;
          v43 = v123;
          v24 = v101;
        }
      }
      else
      {
LABEL_56:
        v46 = v122;
        if ( v123 >= v122 )
          goto LABEL_238;
        while ( 1 )
        {
          v47 = (unsigned int)(v44 - 1) > 0x7FF ? 2048 : v44;
          v125[v43] = ((_WORD)v47 - 1) & 0x7FF | v45 & 0xFFFFF000;
          v44 -= v47;
          v45 += v47 << 12;
          v124 += v47;
          v46 = v122;
          v43 = v123 + 1;
          v123 = v43;
          if ( v43 == v122 )
          {
            qsort(v125, v43, 4, MiTbFlushSort);
            MiCompressTbFlushList((int)&v119);
            v46 = v122;
            v43 = v123;
            if ( v123 == v122 )
              break;
          }
          if ( !v44 )
            goto LABEL_61;
        }
        if ( v44 )
        {
          v124 = v123;
LABEL_238:
          v121 = 1;
        }
      }
LABEL_61:
      v48 = a6;
      if ( v43 == v46 - 1 )
        MiDeletePteList(&v119, a3, 512, a6, v100);
      goto LABEL_63;
    }
    if ( (v25 & 0x400) != 0 )
    {
      v75 = (*(_DWORD *)v13 & 0x1FC | (*(_DWORD *)v13 >> 2) & 0x3FFFFE00) - 0x40000000;
      if ( v25 >> 13 != v116 )
      {
        if ( v75 < dword_640484 || v75 >= dword_640488 )
        {
          if ( v25 >> 13 != v116 )
          {
            v94 = MiLocateCloneAddress(a3, v75);
            if ( v94 )
            {
              v76 = MiDecrementCloneBlockReference(v94, v75, a3);
              goto LABEL_163;
            }
          }
        }
        else
        {
          v76 = MiDecrementCombinedPte((*(_DWORD *)v13 & 0x1FC | (*(_DWORD *)v13 >> 2) & 0x3FFFFE00) - 0x40000000);
LABEL_163:
          if ( v76 == 3 )
          {
            ++v8[1];
          }
          else if ( v76 == 5 )
          {
            ++v8[2];
          }
        }
      }
      if ( v13 + 0x40000000 <= 0x3FFFFF )
      {
        v60 = 0;
        __dmb(0xBu);
        v61 = 512;
        *(_DWORD *)v13 = 512;
        if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
          goto LABEL_205;
        goto LABEL_122;
      }
LABEL_206:
      *(_DWORD *)v13 = 512;
      goto LABEL_88;
    }
    if ( (v25 & 0x800) != 0 )
    {
      v62 = 0;
      v63 = MiLockTransitionLeafPage(v13, 0, v23);
      if ( !v63 )
        goto LABEL_66;
      v64 = 1;
      if ( !*(_WORD *)(v63 + 16) )
      {
        v62 = *(_DWORD *)(v63 + 8);
        if ( (v62 & 8) != 0 )
        {
          v95 = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * ((v62 >> 2) & 1) + 1800] + 96);
          if ( (v95 & 0x10) == 0 && (v95 & 0x20) == 0 )
            v64 = 0;
        }
      }
      if ( MiDeleteLockedTransitionPte(v13, v63, 17, 0) == 3 )
        ++v8[1];
      if ( v62 )
        MiReleasePageFileSpace(MiSystemPartition, v62, v64);
      v65 = (unsigned int *)(a3 + 276);
      do
        v66 = __ldrex(v65);
      while ( __strex(v66 - 1, v65) );
      if ( v64 )
      {
        v61 = 512;
        v104 = 512;
      }
      else
      {
        MI_SET_PAGING_FILE_INFO(&v104, &v108, *(_DWORD *)&MiSystemPartition[2 * ((v62 >> 2) & 1) + 1800], v62 >> 13, 2);
        v61 = v104;
      }
      if ( v13 + 0x40000000 <= 0x3FFFFF )
      {
        v67 = *(_DWORD *)v13;
        v60 = 0;
        __dmb(0xBu);
        *(_DWORD *)v13 = v61;
        if ( (v67 & 2) == 0 && (v61 & 2) != 0 )
          v60 = 1;
        if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
        {
LABEL_205:
          v87 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v87, v87 + 4 * (v13 & 0xFFF), v61);
        }
LABEL_122:
        if ( v60 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
        goto LABEL_88;
      }
      *(_DWORD *)v13 = v61;
    }
    else
    {
      if ( (*(_DWORD *)v13 & 0x3E0) == 512 )
        ++v8[3];
      v49 = (v25 >> 4) & 1;
      if ( v49 )
      {
        v73 = (unsigned int *)(a3 + 276);
        do
          v74 = __ldrex(v73);
        while ( __strex(v74 - 1, v73) );
      }
      v50 = (v25 >> 3) & 1;
      if ( !v50
        || (v96 = (v25 >> 2) & 1, v97 = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * v96 + 1800] + 96),
                                  (v97 & 0x10) != 0)
        || (v97 & 0x20) != 0 )
      {
        v51 = 1;
        v52 = 512;
        v104 = 512;
      }
      else
      {
        v51 = 0;
        MI_SET_PAGING_FILE_INFO(&v104, &v108, *(_DWORD *)&MiSystemPartition[2 * v96 + 1800], v25 >> 13, 2);
        v52 = v104;
      }
      if ( v13 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v13 = v52;
      }
      else
      {
        v53 = *(_DWORD *)v13;
        v54 = 0;
        __dmb(0xBu);
        *(_DWORD *)v13 = v52;
        if ( (v53 & 2) == 0 && (v52 & 2) != 0 )
          v54 = 1;
        if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
        {
          v98 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v98, v98 + 4 * (v13 & 0xFFF), v52);
        }
        if ( v54 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      if ( v49 )
      {
        if ( !v51 )
          v25 &= 0xFFFFFFF7;
      }
      else if ( !v50 || !v51 )
      {
        v25 = 0;
      }
      if ( v25 )
        MiReleasePageFileInfo(MiSystemPartition, v25, 0);
      v14 = v105;
      v24 = v101;
    }
LABEL_88:
    v48 = a6;
LABEL_63:
    v13 += 4;
    if ( (v13 & 0x3C) == 0 && (*(_DWORD *)v14 & 0x40000000) != 0 || KeShouldYieldProcessor() )
    {
      if ( v123 )
        MiDeletePteList(&v119, a3, 512, v48, v100);
      MiUnlockWorkingSetExclusive(v14, v103);
      v56 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v14);
      }
      else
      {
        v57 = (unsigned __int8 *)(v14 + 3);
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 | 0x80, v57) );
        __dmb(0xBu);
        if ( v58 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v14);
        while ( 1 )
        {
          v59 = *(_DWORD *)v14;
          if ( (*(_DWORD *)v14 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v59 & 0x40000000) == 0 )
          {
            do
              v77 = __ldrex((unsigned int *)v14);
            while ( v77 == v59 && __strex(v59 | 0x40000000, (unsigned int *)v14) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v103 = v56;
    }
    v101 = v24 + 4096;
LABEL_66:
    v8 = a6;
    if ( v13 > v110 )
      goto LABEL_93;
    v12 = v106;
    v11 = v114;
  }
  v19 = 0;
  v113[0] = (v12 & (v13 >> 10)) - 0x40000000;
  v113[1] = v18;
  v20 = v13;
  v21 = 0;
  do
  {
    v22 = v113[2 * v21];
    while ( !*(_DWORD *)v22 )
    {
      v22 += 4;
      v19 |= 3u;
      if ( (v22 & 0xFFF) == 0 )
        v14 = v105;
      if ( v22 > v113[2 * v21 + 1] )
        goto LABEL_92;
    }
    if ( (*(_DWORD *)v22 & 2) == 0 )
    {
      v100 = 1;
      MiMakeSystemAddressValid(v22 << 10, 0);
    }
    if ( (v19 & 1) != 0 )
      v19 &= 0xFFFFFFFE;
    ++v21;
  }
  while ( !v21 );
  if ( (v19 & 2) != 0 || (*(_DWORD *)v22 & 0x400) != 0 )
    v20 = v22 << 10;
  if ( v20 )
  {
    v8 = a6;
    v23 = v20 - v13;
    v13 = v20;
    v24 = v20 << 10;
    v101 = v24;
    a6[3] += v23 >> 2;
    goto LABEL_30;
  }
LABEL_92:
  v8 = a6;
  a6[3] += ((int)(v110 - v13) >> 2) + 1;
LABEL_93:
  if ( v123 )
    MiDeletePteList(&v119, a3, 512, v8, v100);
  if ( (*(_BYTE *)(v14 + 115) & 0x10) != 0 )
  {
    *(_BYTE *)(v14 + 115) &= 0xEFu;
    MiAgeWorkingSet(v14, v103, 1, *(unsigned __int16 *)(dword_6404B8 + 1218));
  }
  if ( (*(_BYTE *)(v14 + 115) & 0x20) != 0 )
  {
    v99 = *(_DWORD *)(v14 + 68);
    *(_BYTE *)(v14 + 115) &= 0xDFu;
    MiReduceWs(v14, v103, v99);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v14);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v14 = 0;
  }
  return KfLowerIrql(v103);
}
