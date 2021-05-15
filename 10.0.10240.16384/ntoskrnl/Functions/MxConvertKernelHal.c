// MxConvertKernelHal 
 
int MxConvertKernelHal()
{
  unsigned int v0; // r1
  unsigned int v1; // r2
  unsigned int v2; // r9
  unsigned int v3; // r1
  int v4; // r3
  unsigned int v5; // r9
  unsigned int v6; // r3
  unsigned int v7; // r2
  int v8; // r8
  unsigned int v9; // r2
  _DWORD *v10; // r1
  unsigned int v11; // r3
  int v12; // r7
  int v13; // r6
  int v14; // r4
  int *v15; // r0
  unsigned int v16; // r1
  int result; // r0
  int *v18; // r7
  int v19; // r0
  int *v20; // r7
  int v21; // r5
  int v22; // t1
  int v23; // r10
  unsigned __int8 *v24; // r3
  unsigned int v25; // r1
  unsigned __int8 *v26; // r1
  int v27; // r3
  unsigned int v28; // r2
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r7
  int v32; // r6
  unsigned int *v33; // r0
  int v34; // r1
  unsigned int v35; // t1
  int *v36; // r2
  int v37; // r3
  int v38; // r4
  int v39; // lr
  unsigned int v40; // r10
  unsigned int v41; // r3
  int v42; // r1
  unsigned int v43; // r5
  unsigned int v44; // r2
  unsigned int v45; // r3
  _DWORD *v46; // r9
  unsigned int v47; // r10
  int *v48; // r0
  unsigned int *v49; // r5
  int v50; // r3
  unsigned int v51; // r3
  int v52; // r2
  int v53; // r3
  int v54; // r3
  int v55; // r5
  int v56; // r0
  int v57; // r3
  int v58; // r3
  unsigned int v59; // r5
  unsigned int v60; // r3
  int v61; // r10
  int v62; // r9
  int v63; // r5
  int v64; // r4
  int v65; // r5
  int v66; // r1
  int v67; // r0
  int v68; // r8
  int v69; // r10
  int v70; // r4
  int v71; // r0
  int v72; // r8
  unsigned int v73; // r6
  int *v74; // r7
  int v75; // t1
  int v76; // r5
  int v77; // r3
  int v78; // r5
  int v79; // r0
  unsigned int v80; // r7
  int v81; // r10
  int v82; // r1
  int v83; // r2
  int v84; // r9
  int v85; // r0
  _DWORD *v86; // r2
  int v87; // r3
  _DWORD *v88; // r9
  int v89; // r4
  unsigned int v90; // r8
  unsigned int v91; // r5
  int v92; // r1
  unsigned int v93; // r2
  int v94; // r0
  int v95; // r4
  int v96; // r9
  int v97; // r10
  unsigned __int8 *v98; // r3
  unsigned int v99; // r1
  unsigned __int8 *v100; // r1
  int v101; // r3
  unsigned int v102; // r2
  int v103; // r2
  int v104; // r0
  unsigned int *v105; // r2
  unsigned int v106; // r0
  int v107; // r3
  unsigned int v108; // r0
  _DWORD *v109; // r2
  _DWORD *v110; // r4
  unsigned int v111; // [sp+8h] [bp-68h]
  int v112; // [sp+8h] [bp-68h]
  unsigned int v113; // [sp+Ch] [bp-64h]
  int *v114; // [sp+Ch] [bp-64h]
  _DWORD *v115; // [sp+Ch] [bp-64h]
  int v116; // [sp+10h] [bp-60h]
  int v117; // [sp+10h] [bp-60h]
  char v118[4]; // [sp+14h] [bp-5Ch] BYREF
  int *v119; // [sp+18h] [bp-58h]
  unsigned int v120; // [sp+1Ch] [bp-54h]
  unsigned int v121; // [sp+20h] [bp-50h]
  int v122; // [sp+24h] [bp-4Ch]
  int v123; // [sp+28h] [bp-48h]
  unsigned int v124; // [sp+2Ch] [bp-44h]
  int v125; // [sp+30h] [bp-40h]
  int *v126; // [sp+34h] [bp-3Ch]
  _DWORD *v127; // [sp+38h] [bp-38h]
  _DWORD *v128; // [sp+3Ch] [bp-34h]
  unsigned int *v129; // [sp+40h] [bp-30h]
  unsigned int v130; // [sp+44h] [bp-2Ch]
  _DWORD *v131; // [sp+48h] [bp-28h]
  int v132; // [sp+4Ch] [bp-24h]

  v0 = *(_DWORD *)(dword_9833D0 + 24);
  v1 = *(_DWORD *)(MxHalDataTableEntry + 24);
  v2 = v0;
  if ( v1 < v0 )
    v2 = *(_DWORD *)(MxHalDataTableEntry + 24);
  v3 = v0 + *(_DWORD *)(dword_9833D0 + 32);
  v4 = *(_DWORD *)(MxHalDataTableEntry + 32);
  v5 = v2 & 0xFFC00000;
  v132 = v5;
  v6 = v4 + v1;
  if ( v6 > v3 )
    v3 = v6;
  v7 = (v3 + 0x3FFFFF) & 0xFFC00000;
  v124 = 0x3FFFFF;
  v8 = (v7 - v5) >> 22;
  v9 = ((v7 >> 10) & 0x3FFFFC) - 0x40000000;
  v122 = v8;
  v128 = (_DWORD *)(((v5 >> 10) & 0x3FFFFC) - 0x40000000);
  v10 = v128;
  while ( (unsigned int)v10 < v9 )
  {
    if ( (*v10 & 2) != 0 )
    {
      if ( v10 == (_DWORD *)(((*(_DWORD *)(dword_9833D0 + 24) >> 10) & 0x3FFFFC) - 0x40000000) )
      {
        v11 = *(_DWORD *)(dword_9833D0 + 32);
      }
      else
      {
        if ( v10 != (_DWORD *)(((*(_DWORD *)(MxHalDataTableEntry + 24) >> 10) & 0x3FFFFC) - 0x40000000) )
        {
          MxUseLargePagesForKernelAndHal = 0;
          return 0;
        }
        v11 = *(_DWORD *)(MxHalDataTableEntry + 32);
      }
      v10 += v11 >> 12;
    }
    else
    {
      if ( *v10 )
        return 0;
      ++v10;
    }
  }
  v12 = MiReservePtes(&dword_634D58, v8 << 10);
  v113 = v12;
  if ( !v12 )
    return 0;
  v13 = 0;
  v14 = 0;
  v15 = (int *)ExAllocatePoolWithTag(512, 4 * v8, 538996045);
  v119 = v15;
  if ( !v15 )
  {
    v16 = v12;
    goto LABEL_18;
  }
  if ( !v8 )
  {
LABEL_41:
    v127 = 0;
    v31 = 0;
    v32 = (unsigned __int8)MxUseLargePagesForKernelAndHal;
    if ( MxUseLargePagesForKernelAndHal == 1 )
    {
      v33 = (unsigned int *)(((v5 >> 20) & 0xFFC) - 1070596096);
      if ( v8 )
      {
        v34 = v8;
        do
        {
          v35 = *v33++;
          --v34;
          v36 = (int *)(MmPfnDatabase + 24 * (v35 >> 12));
          v37 = v36[3];
          *v36 = v31;
          v31 = (int)v36;
          v36[3] = v37 | 0x40000000;
        }
        while ( v34 );
      }
    }
    v131 = (_DWORD *)(v113 + (v8 << 12));
    v126 = (int *)(v113 << 10);
    LOWORD(v8) = (dword_681128 | MiDetermineUserGlobalPteMask(v113)) & 0x1ED | 0xF012;
    v38 = *v119;
    v39 = (*v119 - MmPfnDatabase) / 24;
    v116 = v39;
    v129 = v128;
    v40 = ((v5 >> 20) & 0xFFC) - 1070596096;
    v41 = *(_DWORD *)v40;
    v125 = v40;
    v130 = v40;
    v42 = MmPfnDatabase + 24 * (v41 >> 12);
    v43 = *(_DWORD *)(((v40 >> 10) & 0x3FFFFC) - 0x40000000);
    v123 = v42;
    v120 = v43;
    v121 = ((v40 >> 10) & 0x3FFFFC) - 0x40000000;
    if ( v32 == 1 )
    {
      v44 = v43 >> 12;
    }
    else
    {
      v45 = (int)((unsigned __int64)(715827883i64 * (int)(24 * (v41 >> 12))) >> 32) >> 2;
      v42 = v123;
      v44 = v45 + (v45 >> 31);
    }
    v46 = (_DWORD *)v113;
    v47 = v113 + 1070596096;
    v48 = v119;
    v114 = v119;
LABEL_49:
    v111 = v44;
    while ( 1 )
    {
      *(_DWORD *)v38 = 0;
      *(_DWORD *)(v38 + 12) = *(_DWORD *)(v38 + 12) & 0xC0000000 | 1;
      *(_WORD *)(v38 + 16) = 1;
      *(_DWORD *)(v38 + 8) = 192;
      v49 = v129;
      *(_BYTE *)(v38 + 18) = *(_BYTE *)(v38 + 18) & 0xE8 | 0x16;
      v50 = *(_DWORD *)(v38 + 20);
      *(_DWORD *)(v38 + 4) = v49;
      *(_DWORD *)(v38 + 20) = v50 & 0xFFF00000 | v44 & 0xFFFFF;
      v51 = *v49;
      v129 = v49 + 1;
      if ( (v51 & 2) != 0 )
      {
        v52 = 3 * (v51 >> 12);
        v53 = MmPfnDatabase;
        *(_DWORD *)(MmPfnDatabase + 8 * v52) = v31;
        v31 = v53 + 8 * v52;
        if ( v32 == 1 )
          *(_DWORD *)(v42 + 12) = *(_DWORD *)(v42 + 12) & 0xC0000000 | 1;
        v8 = v8 & 0xFFF | (v39 << 12);
        if ( v47 + 3145728 > v124 )
        {
          v44 = v111;
          *v46 = v8;
        }
        else
        {
          v54 = *v46;
          v55 = 0;
          __dmb(0xBu);
          *v46 = v8;
          if ( (v54 & 2) == 0 && (v8 & 2) != 0 )
            v55 = 1;
          if ( v47 <= 0xFFF )
          {
            v56 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v56, (_DWORD *)(v56 + 4 * ((unsigned __int16)v46 & 0xFFF)), v8);
            v48 = v114;
            v39 = v116;
          }
          if ( v55 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
          v44 = v111;
          v32 = (unsigned __int8)MxUseLargePagesForKernelAndHal;
        }
      }
      else if ( v32 == 1 )
      {
        v57 = (int)v127;
        v127 = (_DWORD *)v38;
        *(_DWORD *)v38 = v57;
      }
      else
      {
        *(_DWORD *)v38 = v31;
        v31 = v38;
      }
      ++v46;
      v47 += 4;
      if ( v46 == v131 )
        break;
      ++v39;
      v42 = v123;
      v38 += 24;
      v116 = v39;
      if ( (v39 & 0x3FF) == 0 )
      {
        v38 = v48[1];
        v114 = v48 + 1;
        v39 = (v38 - MmPfnDatabase) / 24;
        v116 = v39;
        v42 = MmPfnDatabase + 24 * (*(_DWORD *)(v130 + 4) >> 12);
        v58 = ((_WORD)v130 + 4) & 0xFFF;
        v130 += 4;
        v123 = v42;
        if ( v58 )
        {
          v59 = v120;
        }
        else
        {
          v59 = *(_DWORD *)(v121 + 4);
          v120 = v59;
          v121 += 4;
        }
        if ( v32 == 1 )
        {
          v44 = v59 >> 12;
        }
        else
        {
          v60 = (int)((unsigned __int64)(715827883i64 * (v42 - MmPfnDatabase)) >> 32) >> 2;
          v42 = v123;
          v44 = v60 + (v60 >> 31);
        }
        ++v48;
        goto LABEL_49;
      }
    }
    v61 = (int)v126;
    v115 = v46;
    v62 = v132;
    v112 = v31;
    v63 = *(_DWORD *)(dword_9833D0 + 24);
    __disable_irq();
    v64 = dword_9833D0;
    memmove(v61 - v62 + v63, v63, *(_DWORD *)(dword_9833D0 + 32));
    KeSweepIcacheRange(0, v61 - v62 + v63, *(_DWORD *)(v64 + 32));
    v65 = MxHalDataTableEntry;
    v66 = *(_DWORD *)(MxHalDataTableEntry + 24);
    v70 = v66 - v62;
    memmove(v66 - v62 + v61, v66, *(_DWORD *)(MxHalDataTableEntry + 32));
    KeSweepIcacheRange(0, v70 + v61, *(_DWORD *)(v65 + 32));
    v67 = MiDetermineUserGlobalPteMask(0);
    v68 = v122;
    v69 = v125;
    LOWORD(v70) = (dword_681128 | v67) & 0x1ED | 0xF412;
    v120 = (dword_681128 | v67) & 0x1ED | 0xFFFFF412;
    if ( v122 )
    {
      v71 = v122;
      v72 = (int)v128;
      v73 = v125 + 1070596096;
      v121 = v125 + 1070596096;
      v117 = v122;
      v74 = v119;
      do
      {
        v75 = *v74++;
        v126 = v74;
        v76 = (v75 - MmPfnDatabase) / 24;
        if ( MxUseLargePagesForKernelAndHal == 1 )
        {
          v70 = v70 & 0xFFF | (v76 << 12);
          v120 = v70;
          if ( v73 + 3145728 > v124 )
          {
            *(_DWORD *)v69 = v70;
          }
          else
          {
            v77 = *(_DWORD *)v69;
            v78 = 0;
            __dmb(0xBu);
            *(_DWORD *)v69 = v70;
            if ( (v77 & 2) == 0 && (v70 & 2) != 0 )
              v78 = 1;
            if ( v73 <= 0xFFF )
            {
              v79 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v79, (_DWORD *)(v79 + 4 * (v69 & 0xFFF)), v70);
              v71 = v117;
            }
            if ( v78 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
        }
        else
        {
          v80 = v124;
          v81 = 1024;
          do
          {
            v82 = *(_DWORD *)v72;
            if ( *(_DWORD *)v72 )
            {
              v83 = *(_DWORD *)v72 & 0xFFF | (v76 << 12);
              if ( v72 + 0x40000000 > v80 )
              {
                *(_DWORD *)v72 = v83;
              }
              else
              {
                v84 = 0;
                __dmb(0xBu);
                *(_DWORD *)v72 = v83;
                if ( (v82 & 2) == 0 && (v83 & 2) != 0 )
                  v84 = 1;
                if ( (unsigned int)(v72 + 1070596096) <= 0xFFF )
                {
                  v85 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v85, (_DWORD *)(v85 + 4 * (v72 & 0xFFF)), v83);
                }
                if ( v84 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
            }
            ++v76;
            --v81;
            v72 += 4;
          }
          while ( v81 );
          LOWORD(v70) = v120;
          v73 = v121;
          v69 = v125;
          v74 = v126;
          v71 = v117;
        }
        v73 += 4;
        --v71;
        v69 += 4;
        v117 = v71;
        v125 = v69;
        v121 = v73;
      }
      while ( v71 );
      v31 = v112;
      v68 = v122;
    }
    __dsb(0xFu);
    __mcr(15, 0, 0, 8, 7, 0);
    __dsb(0xFu);
    __isb(0xFu);
    __enable_irq();
    v86 = (_DWORD *)v31;
    if ( v31 )
    {
      do
      {
        v87 = v86[3];
        v88 = (_DWORD *)*v86;
        if ( (v87 & 0x40000000) != 0 )
        {
          v89 = MiMapPageInHyperSpaceWorker(((int)v86 - MmPfnDatabase) / 24, (int)v118, 0x80000000);
          v90 = v124;
          v91 = v89 + 1070596096;
          v92 = v89 & 0xFFF;
          do
          {
            if ( (*(_DWORD *)v89 & 2) != 0 )
            {
              v93 = *(_DWORD *)v89 & 0xFFFFFFFC | 0x400;
              if ( v91 + 3145728 > v90 )
              {
                *(_DWORD *)v89 = v93;
              }
              else
              {
                __dmb(0xBu);
                *(_DWORD *)v89 = v93;
                if ( v91 <= 0xFFF )
                {
                  v94 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v94, (_DWORD *)(v94 + 4 * v92), v93);
                }
              }
            }
            v89 += 4;
            v92 = v89 & 0xFFF;
            v91 += 4;
          }
          while ( (v89 & 0xFFF) != 0 );
          MiUnmapPageInHyperSpaceWorker(v89 - 4096, (unsigned __int8)v118[0], 0x80000000);
        }
        else
        {
          v86[3] = v87 | 0x40000000;
        }
        v86 = v88;
      }
      while ( v88 );
      v31 = v112;
      v68 = v122;
    }
    v95 = 0;
    if ( v31 )
    {
      do
      {
        v96 = *(_DWORD *)v31;
        v97 = KfRaiseIrql(2);
        v98 = (unsigned __int8 *)(v31 + 15);
        do
          v99 = __ldrex(v98);
        while ( __strex(v99 | 0x80, v98) );
        __dmb(0xBu);
        if ( v99 >> 7 )
        {
          v100 = (unsigned __int8 *)(v31 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v101 = *(_DWORD *)(v31 + 12);
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
        if ( (*(_BYTE *)(v31 + 18) & 7) != 6 )
          KeBugCheck2(
            78,
            153,
            (v31 - MmPfnDatabase) / 24,
            *(_BYTE *)(v31 + 18) & 7,
            *(_DWORD *)(v31 + 12) & 0x3FFFFFFF,
            0);
        v103 = *(_DWORD *)(v31 + 12);
        *(_DWORD *)(v31 + 12) = v103 & 0xC0000000 | ((v103 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
        if ( (v103 & 0x3FFFFFFF) == 1 )
          v104 = MiPfnShareCountIsZero(v31, 0);
        else
          v104 = 2;
        if ( v104 != 3 )
          ++v95;
        __dmb(0xBu);
        v105 = (unsigned int *)(v31 + 12);
        do
          v106 = __ldrex(v105);
        while ( __strex(v106 & 0x7FFFFFFF, v105) );
        KfLowerIrql(v97);
        v31 = v96;
      }
      while ( v96 );
      if ( v95 )
      {
        MiReturnCommit((int)MiSystemPartition, v95);
        v107 = dword_634D90 - v95;
        __dmb(0xBu);
        dword_634D90 = v107;
        MiReturnResidentAvailable(v95);
        do
          v108 = __ldrex(&dword_634A2C[11]);
        while ( __strex(v108 + v95, &dword_634A2C[11]) );
      }
    }
    v109 = v127;
    if ( v127 )
    {
      do
      {
        v110 = (_DWORD *)*v109;
        MiAddExpansionNonPagedPool(((int)v109 - MmPfnDatabase) / 24, 1);
        v109 = v110;
      }
      while ( v110 );
      v68 = v122;
    }
    ExFreePoolWithTag((unsigned int)v119);
    MiReleasePtes(&dword_634D58, (unsigned int)&v115[-1024 * v68], v68 << 10);
    result = 1;
    MiFlags |= 4u;
    return result;
  }
  v18 = v15;
  while ( 1 )
  {
    v19 = MiUnlinkNodeLargePage((int)MiSystemPartition, v13, 1, 1);
    if ( v19 )
    {
      *v18 = v19;
      ++v14;
      ++v18;
      goto LABEL_40;
    }
    if ( ++v13 >= (unsigned int)(unsigned __int16)KeNumberNodes )
      break;
LABEL_40:
    if ( v14 == v8 )
      goto LABEL_41;
  }
  if ( v14 )
  {
    v20 = v119;
    do
    {
      v22 = *v20++;
      v21 = v22;
      v23 = KfRaiseIrql(2);
      v24 = (unsigned __int8 *)(v22 + 15);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 | 0x80, v24) );
      __dmb(0xBu);
      if ( v25 >> 7 )
      {
        v26 = (unsigned __int8 *)(v21 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v27 = *(_DWORD *)(v21 + 12);
            __dmb(0xBu);
          }
          while ( (v27 & 0x80000000) != 0 );
          do
            v28 = __ldrex(v26);
          while ( __strex(v28 | 0x80, v26) );
          __dmb(0xBu);
        }
        while ( v28 >> 7 );
      }
      MiInsertLargePageInNodeList(
        (v21 - MmPfnDatabase) / 24,
        0x400u,
        1,
        (int)((unsigned __int64)(715827883i64 * (v21 - MmPfnDatabase)) >> 32) >> 2);
      __dmb(0xBu);
      v29 = (unsigned int *)(v21 + 12);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 & 0x7FFFFFFF, v29) );
      KfLowerIrql(v23);
      --v14;
    }
    while ( v14 );
    v8 = v122;
  }
  ExFreePoolWithTag((unsigned int)v119);
  v16 = v113;
LABEL_18:
  MiReleasePtes(&dword_634D58, v16, v8 << 10);
  return 0;
}
