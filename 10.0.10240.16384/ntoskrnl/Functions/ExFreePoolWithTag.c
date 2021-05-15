// ExFreePoolWithTag 
 
unsigned int __fastcall ExFreePoolWithTag(unsigned int a1)
{
  _DWORD *v1; // r8
  unsigned int result; // r0
  unsigned int v3; // r4
  unsigned int v4; // r6
  unsigned int v5; // r3
  int v6; // r7
  int v7; // lr
  unsigned int v8; // r5
  char v9; // r2
  int v10; // r3
  __int16 *v11; // r2
  int v12; // r1
  unsigned int v13; // r9
  int v14; // r4
  int v15; // lr
  int *v16; // r3
  int v17; // r10
  int v18; // r1
  int v19; // r3
  unsigned int *v20; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int *v23; // r2
  unsigned int v24; // r4
  __int16 v25; // r2
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r0
  unsigned int v29; // r2
  int v30; // r3
  unsigned int *v31; // r2
  unsigned int v32; // r1
  unsigned int *v33; // r2
  unsigned int v34; // r4
  int v35; // r5
  unsigned int *v36; // r2
  unsigned int v37; // r1
  unsigned int *v38; // r2
  unsigned int v39; // r4
  int *v40; // r0
  unsigned int v41; // r7
  int v42; // r8
  int v43; // r2
  int v44; // r3
  unsigned int v45; // r2
  unsigned int v46; // r1
  int v47; // r3
  unsigned int v48; // r1
  int v49; // r4
  int v50; // r3
  __int16 v51; // r3
  int v52; // r5
  unsigned int v53; // r2
  int v54; // r5
  int v55; // r1
  int v56; // r8
  _DWORD *v57; // r10
  unsigned int *v58; // r2
  unsigned int v59; // r4
  unsigned int v60; // r4
  int v61; // r4
  unsigned int v62; // r1
  __int16 v63; // r1
  int v64; // r1
  unsigned int v65; // r2
  __int64 v66; // r0
  _DWORD *v67; // r4
  int v68; // r5
  _DWORD *v69; // r6
  int v70; // r8
  unsigned int *v71; // r2
  unsigned int v72; // r1
  int v73; // r4
  unsigned int v74; // r1
  int v75; // r8
  int v76; // r5
  int v77; // r3
  int v78; // r2
  int v79; // r6
  unsigned int v80; // r1
  int v81; // r2
  int v82; // r3
  int v83; // r4
  __int16 v84; // r3
  int v85; // r2
  int v86; // r3
  _DWORD *v87; // r1
  _DWORD *v88; // r1
  int v89; // r0
  unsigned int *v90; // r1
  int *v91; // r0
  __int64 v92; // kr08_8
  __int16 v93; // r3
  unsigned int v94; // r0
  int v95; // r1
  _BYTE *v96; // r7
  unsigned int v97; // r10
  int *v98; // r2
  unsigned int *v99; // r0
  unsigned int v100; // r4
  unsigned int v101; // lr
  unsigned int v102; // r2
  unsigned int v103; // r2
  unsigned int v104; // lr
  unsigned int v105; // r3
  unsigned int v106; // r1
  unsigned int *v107; // r4
  unsigned int v108; // r0
  unsigned int *v109; // r10
  unsigned int v110; // r2
  signed int v111; // r2
  __int64 v112; // r0
  int v113; // r4
  unsigned int v114; // r1
  unsigned int *v115; // r0
  unsigned int v116; // r4
  unsigned int v117; // lr
  unsigned int v118; // r1
  int v119; // r2
  int v120; // r0
  unsigned int v121; // r3
  int v122; // r3
  unsigned int *v123; // r2
  unsigned int v124; // r0
  unsigned int v125; // r2
  unsigned int *v126; // r9
  unsigned int v127; // r1
  unsigned int *v128; // r9
  unsigned int v129; // r1
  unsigned int v130; // r3
  unsigned __int8 *v131; // r4
  char v132; // r5
  unsigned int v133; // r0
  unsigned __int8 *v134; // r3
  unsigned int v135; // r2
  unsigned int *v136; // r2
  unsigned int v137; // r1
  char v138; // r2
  unsigned __int8 *v139; // r4
  int v140; // r10
  unsigned int *v141; // r1
  int v142; // r2
  unsigned int *v143; // r5
  unsigned int v144; // r3
  int v145; // r1
  int v146; // r3
  unsigned int *v147; // r4
  unsigned int *v148; // r8
  int v149; // r1
  unsigned int v150; // r2
  unsigned int v151; // r2
  unsigned int v152; // r0
  _BYTE *v153; // r0
  unsigned int *v154; // r4
  unsigned int v155; // r2
  _DWORD *v156; // r0
  int v157; // r8
  int v158; // r4
  _BYTE *v159; // r0
  unsigned int *v160; // r10
  unsigned int v161; // r2
  __int64 **v162; // r6
  __int64 v163; // r2
  int v164; // r0
  __int64 **v165; // r6
  __int64 v166; // r2
  int v167; // r0
  _DWORD *v168; // r1
  int v169; // [sp+8h] [bp-68h]
  _DWORD *v170; // [sp+Ch] [bp-64h]
  int v171; // [sp+10h] [bp-60h]
  unsigned int v172; // [sp+10h] [bp-60h]
  int v173; // [sp+10h] [bp-60h]
  int v174; // [sp+14h] [bp-5Ch]
  int *v175; // [sp+14h] [bp-5Ch]
  int v176; // [sp+18h] [bp-58h]
  unsigned int v177; // [sp+18h] [bp-58h]
  int v178; // [sp+1Ch] [bp-54h]
  int v179; // [sp+24h] [bp-4Ch] BYREF
  int v180; // [sp+28h] [bp-48h] BYREF
  unsigned int *v181; // [sp+2Ch] [bp-44h]
  unsigned __int8 v182; // [sp+30h] [bp-40h]
  int v183; // [sp+38h] [bp-38h]
  int v184; // [sp+3Ch] [bp-34h]
  unsigned int v185; // [sp+40h] [bp-30h]
  unsigned int v186; // [sp+44h] [bp-2Ch]
  unsigned int *v187; // [sp+48h] [bp-28h]
  _DWORD *v188; // [sp+4Ch] [bp-24h]
  unsigned int v189; // [sp+50h] [bp-20h]
  int vars4; // [sp+74h] [bp+4h]

  v1 = (_DWORD *)a1;
  if ( ExpSpecialAllocations )
    return sub_60CC14();
  v3 = 1;
  if ( (a1 & 0xFFF) == 0 )
  {
    v120 = MmDeterminePoolType(a1);
    return ExFreeLargePool((unsigned int)v1, &v179, 0, v120);
  }
  v4 = a1 - 8;
  v5 = *(unsigned __int16 *)(a1 - 6);
  v6 = v5 >> 9;
  v7 = (v5 >> 9) & 1;
  v169 = v7;
  v8 = *(_WORD *)(a1 - 6) & 0x1FF;
  if ( (v5 & 0x400) == 0 )
    KeBugCheck2(194, 7, 0x1254u, *(_DWORD *)v4, a1, 0);
  v9 = ExpPoolFlags;
  if ( (ExpPoolFlags & 0x417) != 0 )
  {
    if ( (ExpPoolFlags & 0x400) != 0 && !v7 )
    {
      ExpCheckForLookaside(a1 - 8, 8 * v8);
      v9 = ExpPoolFlags;
    }
    if ( (v9 & 1) != 0 )
    {
      KeCheckForTimer((int)(v1 - 2), 8 * v8);
      v9 = ExpPoolFlags;
    }
    if ( (v9 & 4) != 0 )
    {
      ExpCheckForResource((unsigned int)(v1 - 2), 8 * v8);
      v9 = ExpPoolFlags;
    }
    if ( (v9 & 2) != 0 )
    {
      ExpCheckForWorker(v1 - 2, 8 * v8);
      v9 = ExpPoolFlags;
    }
    if ( (v9 & 0x10) != 0 )
      VfFreePoolNotification(v1 - 2, 8 * v8);
  }
  if ( (v6 & 0x40) != 0 )
    VerifierFreeTrackedPool((int)v1, 8 * v8, v7, 0);
  if ( (v6 & 4) != 0 )
  {
    v117 = *(_WORD *)v4 & 0x1FF;
    v118 = v4 - 8 * v117;
    if ( (*(_WORD *)(v118 + 2) & 0x400) == 0 )
      KeBugCheck2(194, 11, v4 - 8 * v117, *(_DWORD *)v118, (unsigned int)v1, 0);
    v119 = (ExpCacheLineSize - 1) & (-8 - v118);
    if ( !v119 || v119 + v118 != v4 || (v8 = *(_WORD *)(v118 + 2) & 0x1FF, v8 != (*((_WORD *)v1 - 3) & 0x1FF) + v117) )
      KeBugCheck2(194, 16, v4 - 8 * v117, *(_DWORD *)v118, v119 + v118, 0);
    if ( v117 > 1 && (ExpPoolQuotaCookie ^ v4) != *(_DWORD *)(v118 + 8) )
      KeBugCheck2(194, 17, v4 - 8 * v117, *(_DWORD *)v118, ExpPoolQuotaCookie ^ v4, 0);
    v7 = v169;
    v4 = v118;
    v1 = (_DWORD *)(v118 + 8);
  }
  *(_WORD *)(v4 + 2) |= 0x800u;
  __dmb(0xFu);
  v10 = *(_DWORD *)(v4 + 4);
  *(_WORD *)(v4 + 2) &= 0xFBFFu;
  v174 = v10;
  v179 = v10;
  if ( v10 < 0 )
  {
    v174 = v10 & 0x7FFFFFFF;
    v179 = v10 & 0x7FFFFFFF;
  }
  v184 = v4 + 8 * v8;
  if ( (((_WORD)v4 + 8 * (_WORD)v8) & 0xFFF) != 0 && v8 != (*(_WORD *)(v4 + 8 * v8) & 0x1FF) )
    KeBugCheck2(25, 32, v4, v4 + 8 * v8, *(_DWORD *)v4, 0);
  v11 = &KeNumberNodes;
  v12 = PoolVector[v7];
  v170 = (_DWORD *)v12;
  v13 = *(unsigned __int16 *)v4 >> 9;
  if ( v7 )
  {
    if ( (v6 & 0x20) != 0 )
    {
      v170 = (_DWORD *)MiSessionPoolVector();
    }
    else
    {
      v3 = ExpNumberOfPagedPools + 1;
      v170 = (_DWORD *)ExpPagedPoolDescriptor[v13];
    }
  }
  else
  {
    if ( (unsigned int)ExpNumberOfNonPagedPools > 1 )
    {
      v3 = ExpNumberOfNonPagedPools;
      v12 = ExpNonPagedPoolDescriptor[v13];
      v170 = (_DWORD *)v12;
    }
    v30 = *(_DWORD *)(((v4 >> 20) & 0xFFC) - 1070596096);
    if ( (v30 & 0x400) == 0 )
      v30 = *(_DWORD *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000);
    v11 = &KeNumberNodes;
    if ( (v30 & 1) == 0 )
      v170 = (_DWORD *)(v12 + 4736);
  }
  if ( v13 >= v3 )
    KeBugCheck2(25, 37, v13, v3, v4, 0);
  v186 = 8 * v8;
  v14 = v174 & 0x7FFFFFFF;
  if ( (v174 & 0x7FFFFFFF) == *((_DWORD *)v11 + 784) )
    __debugbreak();
  if ( (dword_682604 & 0x41) != 0 )
    EtwTracePool(3618, v6, v174 & 0x7FFFFFFF, (unsigned int)v1, 8 * v8);
  v178 = v6 & 0x20;
  if ( (v6 & 0x20) != 0 )
  {
    v15 = ExpSessionPoolTrackTable;
    v16 = &ExpSessionPoolTrackTableMask;
  }
  else
  {
    v15 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
    v16 = &PoolTrackTableMask;
  }
  v17 = *v16;
  v18 = *v16 & ((int)(40543
                    * (((v174 & 0x7FFFFFFFu) >> 24) ^ (4
                                                     * ((unsigned __int8)((v174 & 0x7FFFFFFFu) >> 16) ^ (4 * (BYTE1(v174) ^ (4 * (unsigned __int8)v174))))))) >> 2);
  v171 = v18;
  while ( 1 )
  {
    v19 = *(_DWORD *)(28 * v18 + v15);
    v20 = (unsigned int *)(28 * v18 + v15);
    if ( v19 == v14 )
      break;
    if ( v19 || (v6 & 0x20) != 0 || (v130 = *(_DWORD *)(28 * v18 + PoolTrackTable)) == 0 )
    {
      v18 = (v18 + 1) & v17;
      if ( v18 == v171 )
      {
        ExpRemovePoolTrackerExpansion(v14, 8 * v8, v6, 28);
        v140 = v169;
        goto LABEL_32;
      }
    }
    else
    {
      *v20 = v130;
    }
  }
  v140 = v169;
  if ( v169 )
  {
    v21 = v20 + 5;
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 + 1, v21) );
    v23 = v20 + 6;
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 - 8 * v8, v23) );
  }
  else
  {
    v31 = v20 + 2;
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 + 1, v31) );
    v33 = v20 + 3;
    do
      v34 = __ldrex(v33);
    while ( __strex(v34 - 8 * v8, v33) );
  }
LABEL_32:
  if ( (v6 & 8) != 0 )
  {
    v94 = *(unsigned __int16 *)(v4 + 2);
    if ( (v94 & 0x1000) != 0 )
    {
      v95 = v94 & 0x1FF;
      v96 = (_BYTE *)(ExpPoolQuotaCookie ^ *(_DWORD *)(v4 + 8 * v95 - 4) ^ v4);
      if ( v96 && ((unsigned int)v96 < MmSystemRangeStart || (*v96 & 0x7F) != 3) )
        KeBugCheck2(194, 13, v4 + 8, *(_DWORD *)(v4 + 4), (unsigned int)v96, 0);
      if ( v96 )
      {
        v177 = 8 * v95;
        if ( v96 != (_BYTE *)PsInitialSystemProcess )
        {
          v97 = ((v94 >> 9) & 1) == 1;
          v98 = *(int **)((ExpPoolQuotaCookie ^ *(_DWORD *)(v4 + 8 * v95 - 4) ^ v4) + 0x14C);
          v175 = v98;
          __dmb(0xBu);
          v99 = (unsigned int *)&v98[64 * v97];
          v187 = v99;
          v100 = *v99;
          v183 = (unsigned __int8)PspResourceFlags[8 * v97];
          __dmb(0xBu);
          v101 = v99[32];
          __dmb(0xBu);
          if ( v99[34] )
          {
            v188 = &PspQuotaExpansionDescriptors[7 * v97];
            if ( v101 > v100 )
            {
              v102 = PspQuotaExpansionDescriptors[7 * v97 + 1];
              v173 = v102;
              if ( v101 - v100 > v102 )
              {
                if ( v102 > 8 * v95 )
                {
                  v102 = 8 * v95;
                  v173 = 8 * v95;
                }
                v125 = v101 - v102;
                __dmb(0xBu);
                v126 = v99 + 32;
                do
                  v127 = __ldrex(v126);
                while ( v127 == v101 && __strex(v125, v126) );
                __dmb(0xBu);
                if ( v127 == v101 )
                {
                  __dmb(0xBu);
                  v128 = v99 + 33;
                  do
                    v129 = __ldrex(v128);
                  while ( __strex(v129 + v173, v128) );
                  __dmb(0xBu);
                  if ( v173 + v129 > v188[1] )
                  {
                    __dmb(0xBu);
                    v141 = v99 + 33;
                    do
                      v142 = __ldrex(v141);
                    while ( __strex(0, v141) );
                    __dmb(0xBu);
                    if ( v142 )
                    {
                      PspReturnResourceQuota(v97, (int)v99, v142, 0);
                      v99 = v187;
                    }
                  }
                }
              }
            }
          }
          v103 = v177;
          while ( 1 )
          {
            while ( 1 )
            {
              if ( v103 >= v100 )
              {
                v104 = v100;
                v105 = 0;
              }
              else
              {
                v104 = v103;
                v105 = v100 - v103;
              }
              __dmb(0xBu);
              do
                v106 = __ldrex(v99);
              while ( v106 == v100 && __strex(v105, v99) );
              __dmb(0xBu);
              if ( v106 == v100 )
                break;
              v100 = v106;
            }
            v103 -= v104;
            if ( !v103 )
              break;
            if ( v175 == PspSystemQuotaBlock )
              KeBugCheck2(33, (int)v96, v97, v177, v103, 0);
            v99 = (unsigned int *)&PspSystemQuotaBlock[64 * v97];
            v100 = *v99;
            v175 = PspSystemQuotaBlock;
            __dmb(0xBu);
          }
          if ( (v183 & 4) != 0 )
          {
            v107 = (unsigned int *)&v96[4 * v97 + 208];
            __dmb(0xBu);
            do
              v108 = __ldrex(v107);
            while ( __strex(v108 - v177, v107) );
            __dmb(0xBu);
          }
        }
        v109 = (unsigned int *)(v96 - 24);
        if ( ObpTraceFlags )
          ObpPushStackInfo((unsigned int)(v96 - 24), 0, 1u, *(_DWORD *)(v4 + 4));
        __dmb(0xBu);
        do
        {
          v110 = __ldrex(v109);
          v111 = v110 - 1;
        }
        while ( __strex(v111, v109) );
        if ( v111 <= 0 )
        {
          if ( *((_DWORD *)v96 - 5) )
            KeBugCheck2(
              24,
              ObTypeIndexTable[(unsigned __int8)((unsigned __int16)((_WORD)v96 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ (unsigned __int8)*(v96 - 12)],
              (unsigned int)v96,
              3u,
              *((_DWORD *)v96 - 5),
              0);
          if ( v111 < 0 )
            KeBugCheck2(24, 0, (unsigned int)v96, 4u, v111, 0);
          ObpDeferObjectDeletion((unsigned int)(v96 - 24));
          v140 = v169;
        }
        else
        {
          v140 = v169;
        }
      }
    }
  }
  if ( !v178 || v140 != 1 )
  {
    if ( v8 > 0x20 )
      goto LABEL_56;
    v25 = ExpPoolFlags;
    if ( (ExpPoolFlags & 0x100) != 0 )
      goto LABEL_57;
    if ( v140 == 1 )
    {
      if ( !v170[64] )
        goto LABEL_57;
      if ( (unsigned __int16)KeNumberNodes > 1u
        && *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266) != v170[64] - 1 )
      {
        goto LABEL_56;
      }
      v26 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 + 72 * v8;
      v27 = 15032;
    }
    else
    {
      if ( (unsigned __int16)KeNumberNodes > 1u )
      {
        v87 = v170;
        if ( *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266) != v170[64] )
          goto LABEL_56;
      }
      else
      {
        v87 = v170;
      }
      v26 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 + 72 * v8;
      if ( *v87 == 512 )
        v27 = 10424;
      else
        v27 = 12728;
    }
    v28 = v26 + v27;
LABEL_41:
    if ( v28 )
    {
      v29 = *(unsigned __int16 *)(v28 + 8);
      ++*(_DWORD *)(v28 + 20);
      if ( *(unsigned __int16 *)(v28 + 4) < v29 )
      {
        ++*(_DWORD *)(v28 + 24);
        *v1 = ExpPoolQuotaCookie ^ v4;
        return RtlpInterlockedPushEntrySList((unsigned __int64 *)v28, v1 + 1);
      }
    }
    goto LABEL_56;
  }
  if ( v8 <= ExpSessionPoolSmallLists )
  {
    v28 = ExpSessionPoolLookaside + (v8 << 7) - 128;
    goto LABEL_41;
  }
LABEL_56:
  v25 = ExpPoolFlags;
LABEL_57:
  if ( (v25 & 0x200) != 0 )
  {
    v143 = v170 + 129;
    v144 = v170[129];
    if ( v144 < 0x20 )
      goto LABEL_300;
    if ( v144 < 0x100 )
    {
      if ( v170[35] )
        goto LABEL_300;
      v145 = 0;
    }
    else
    {
      v145 = 1;
    }
    ExDeferredFreePool(v170, v145);
LABEL_300:
    v146 = ExpPoolQuotaCookie ^ v4;
    v147 = v170 + 128;
    __pld(v170 + 128);
    *v1 = v146;
    v148 = v1 + 1;
    result = *v147;
    do
    {
      *v148 = result;
      v149 = result;
      __dmb(0xBu);
      do
        v150 = __ldrex(v147);
      while ( v150 == result && __strex((unsigned int)v148, v147) );
      result = v150;
    }
    while ( v150 != v149 );
    do
      v151 = __ldrex(v143);
    while ( __strex(v151 + 1, v143) );
    return result;
  }
  v35 = 0;
  __dmb(0xBu);
  v36 = v170 + 33;
  do
    v37 = __ldrex(v36);
  while ( __strex(v37 + 1, v36) );
  __dmb(0xBu);
  v38 = v170 + 36;
  do
    v39 = __ldrex(v38);
  while ( __strex(v39 - v186, v38) );
  __dmb(0xBu);
  v40 = MiState;
  v172 = -1;
  if ( v140 )
  {
    v41 = (unsigned int)(v170 + 1);
    if ( !KiAbEnabled || (v41 & 0x7FFFFFFC) == 0 )
    {
      v49 = 0;
      goto LABEL_80;
    }
    v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v43 = 0;
    }
    else
    {
      __disable_irq();
      v43 = 1;
    }
    v44 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v43 )
      __enable_irq();
    if ( (v44 & 0x10001) != 0 )
    {
      v152 = KeGetCurrentIrql(MiState);
      KeBugCheck2(402, v42, v41, v152, 0, 0);
    }
    --*(_WORD *)(v42 + 310);
    if ( !*(_BYTE *)(v42 + 484) )
    {
      if ( !*(_BYTE *)(v42 + 810) )
      {
        v49 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          v40 = EtwTraceAutoBoostEntryExhaustion(v42, v41);
        goto LABEL_252;
      }
      v131 = (unsigned __int8 *)(v42 + 810);
      v132 = *(_BYTE *)(v42 + 810);
      __dmb(0xBu);
      do
        v133 = __ldrex(v131);
      while ( __strex(v133 & ~v132, v131) );
      __dmb(0xBu);
      v40 = MiState;
      *(_BYTE *)(v42 + 484) |= v132;
    }
    v45 = *(unsigned __int8 *)(v42 + 484);
    v46 = __clz(__rbit(v45));
    v47 = v45 & ~(1 << v46);
    v189 = v46;
    v48 = v42 + 48 * v46;
    v49 = v48 + 488;
    *(_BYTE *)(v42 + 484) = v47;
    if ( v48 != -488 )
    {
      if ( v41 >= dword_63389C
        && ((v50 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v41 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v50 == 1)
         || v50 == 11) )
      {
        v40 = (int *)MmGetSessionIdEx(*(_DWORD *)(v42 + 116));
      }
      else
      {
        v40 = (int *)-1;
      }
      *(_DWORD *)(v49 + 20) = v40;
      *(_DWORD *)(v49 + 16) = v41 & 0x7FFFFFFC;
LABEL_77:
      v51 = *(_WORD *)(v42 + 310) + 1;
      *(_WORD *)(v42 + 310) = v51;
      if ( !v51 && *(_DWORD *)(v42 + 100) != v42 + 100 )
        KiCheckForKernelApcDelivery((int)v40);
LABEL_80:
      v52 = KfRaiseIrql(1);
      do
        v53 = __ldrex((unsigned __int8 *)v41);
      while ( __strex(v53 & 0xFE, (unsigned __int8 *)v41) );
      __dmb(0xBu);
      if ( (v53 & 1) == 0 )
        ExpAcquireFastMutexContended(v41, v49);
      if ( v49 )
        *(_BYTE *)(v49 + 14) |= 1u;
      v170[2] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v170[8] = v52;
      v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v55 = 0;
      v56 = 0;
      v176 = 0;
      v57 = 0;
      if ( !PspAlwaysTrackIoBoosting )
        goto LABEL_87;
      v56 = 1;
      v153 = (_BYTE *)ExAllocatePoolWithTag(512, 56);
      v57 = v153;
      if ( v153 )
      {
        memset(v153, 0, 56);
        RtlCaptureStackBackTrace(1u, 0xAu, (int)(v57 + 2), 0);
        v57[12] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v57[13] = 0;
      }
      v154 = (unsigned int *)(v54 + 1020);
      v55 = KfRaiseIrql(2);
      v176 = v55;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v54 + 1020);
      }
      else
      {
        do
          v155 = __ldrex(v154);
        while ( __strex(1u, v154) );
        __dmb(0xBu);
        if ( !v155 )
          goto LABEL_87;
        KxWaitForSpinLockAndAcquire((unsigned int *)(v54 + 1020));
      }
      v55 = v176;
LABEL_87:
      __dmb(0xBu);
      v58 = (unsigned int *)(v54 + 1000);
      do
      {
        v59 = __ldrex(v58);
        v60 = v59 + 1;
      }
      while ( __strex(v60, v58) );
      __dmb(0xBu);
      if ( v56 )
      {
        if ( v57 )
        {
          v156 = *(_DWORD **)(v54 + 1008);
          *v57 = v54 + 1004;
          v57[1] = v156;
          if ( *v156 != v54 + 1004 )
            __fastfail(3u);
          *v156 = v57;
          *(_DWORD *)(v54 + 1008) = v57;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented((_DWORD *)(v54 + 1020), vars4);
          v55 = v176;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)(v54 + 1020) = 0;
        }
        KfLowerIrql(v55);
      }
      if ( v60 == 1 && KiAbEnabled && *(_BYTE *)(v54 + 485) )
      {
        v157 = KfRaiseIrql(2);
        v158 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
        if ( KiAbThreadInsertList(v54, (_DWORD *)(v158 + 17412), (_DWORD *)(v54 + 776)) )
          KiAbQueueAutoBoostDpc(v158);
        KfLowerIrql(v157);
      }
      v140 = v169;
      v35 = 0;
      goto LABEL_94;
    }
LABEL_252:
    v134 = (unsigned __int8 *)(v42 + 81);
    do
      v135 = __ldrex(v134);
    while ( __strex(v135 | 0x80, v134) );
    goto LABEL_77;
  }
  v41 = (unsigned int)(v170 + 1);
  v180 = 0;
  v181 = v170 + 1;
  __dmb(0xBu);
  v182 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireQueuedSpinLockInstrumented((int)&v180, (unsigned int *)v41);
  }
  else
  {
    do
      v88 = (_DWORD *)__ldrex((unsigned int *)v41);
    while ( __strex((unsigned int)&v180, (unsigned int *)v41) );
    __dmb(0xBu);
    if ( v88 )
      KxWaitForLockOwnerShip((int)&v180, v88);
  }
LABEL_94:
  v61 = v184;
  if ( (v184 & 0xFFF) != 0 && (*(_WORD *)(v184 + 2) & 0xFE00) == 0 )
  {
    v35 = 1;
    if ( (*(_WORD *)(v184 + 2) & 0x1FF) != 1 )
    {
      v112 = *(_QWORD *)(v184 + 8);
      if ( *(_DWORD *)(v112 + 4) != v184 + 8 || *(_DWORD *)HIDWORD(v112) != v184 + 8 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v112) = v112;
      *(_DWORD *)(v112 + 4) = HIDWORD(v112);
    }
    *(_WORD *)(v4 + 2) = *(_WORD *)(v4 + 2) & 0xFE00 | (*(_WORD *)(v61 + 2) + *(_WORD *)(v4 + 2)) & 0x1FF;
  }
  if ( (*(_WORD *)v4 & 0x1FF) != 0 )
  {
    v62 = v4 - 8 * (*(_WORD *)v4 & 0x1FF);
    if ( (*(_WORD *)(v62 + 2) & 0xFE00) == 0 )
    {
      v35 = 1;
      if ( (*(_WORD *)(v62 + 2) & 0x1FF) != 1 )
      {
        v92 = *(_QWORD *)(v62 + 8);
        if ( *(_DWORD *)(v92 + 4) != v62 + 8 || *(_DWORD *)HIDWORD(v92) != v62 + 8 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v92) = v92;
        *(_DWORD *)(v92 + 4) = HIDWORD(v92);
      }
      v93 = *(_WORD *)(v4 + 2);
      v4 = v62;
      *(_WORD *)(v62 + 2) = *(_WORD *)(v62 + 2) & 0xFE00 | (v93 + *(_WORD *)(v62 + 2)) & 0x1FF;
    }
  }
  if ( (v4 & 0xFFF) == 0 && (((_WORD)v4 + 8 * (*(_WORD *)(v4 + 2) & 0x1FF)) & 0xFFF) == 0 )
  {
    if ( v140 )
    {
      PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, 0);
      v113 = *(_DWORD *)(v41 + 28);
      *(_DWORD *)(v41 + 4) = 0;
      __dmb(0xBu);
      do
        v114 = __ldrex((unsigned int *)v41);
      while ( !v114 && __strex(1u, (unsigned int *)v41) );
      if ( v114 )
        ExpReleaseFastMutexContended((unsigned int *)v41, v114);
      KfLowerIrql((unsigned __int8)v113);
      KeAbPostRelease(v41);
    }
    else
    {
      KeReleaseInStackQueuedSpinLock((int)&v180);
    }
    __dmb(0xBu);
    v115 = v170 + 96;
    do
      v116 = __ldrex(v115);
    while ( __strex(v116 - 1, v115) );
    __dmb(0xBu);
    return MiFreePoolPages(v4, 0x1000u);
  }
  v63 = *(_WORD *)(v4 + 2) & 0x1FF;
  *(_WORD *)(v4 + 2) = v63;
  v64 = v63 & 0x1FF;
  if ( v35 && (((_WORD)v4 + 8 * (_WORD)v64) & 0xFFF) != 0 )
    *(_WORD *)(v4 + 8 * v64) ^= (*(_WORD *)(v4 + 8 * v64) ^ v64) & 0x1FF;
  v65 = v4 + 8;
  HIDWORD(v66) = &v170[2 * v64 + 158];
  LODWORD(v66) = *(_DWORD *)HIDWORD(v66);
  *(_QWORD *)(v4 + 8) = v66;
  if ( *(_DWORD *)(v66 + 4) != HIDWORD(v66) )
    __fastfail(3u);
  *(_DWORD *)(v66 + 4) = v65;
  *(_DWORD *)HIDWORD(v66) = v65;
  if ( !v140 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v180, vars4);
    }
    else
    {
      v89 = v180;
      if ( !v180 )
      {
        v90 = v181;
        __dmb(0xBu);
        do
          v91 = (int *)__ldrex(v90);
        while ( v91 == &v180 && __strex(0, v90) );
        if ( v91 == &v180 )
          return KfLowerIrql(v182);
        v89 = KxWaitForLockChainValid(&v180);
      }
      v180 = 0;
      __dmb(0xBu);
      v123 = (unsigned int *)(v89 + 4);
      do
        v124 = __ldrex(v123);
      while ( __strex(v124 ^ 1, v123) );
    }
    return KfLowerIrql(v182);
  }
  v67 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v68 = 0;
  v69 = 0;
  v70 = 0;
  if ( PspAlwaysTrackIoBoosting )
  {
    v68 = 1;
    v159 = (_BYTE *)ExAllocatePoolWithTag(512, 56);
    v69 = v159;
    if ( v159 )
    {
      memset(v159, 0, 56);
      RtlCaptureStackBackTrace(1u, 0xAu, (int)(v69 + 2), 0);
      v69[12] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v69[13] = 0;
    }
    v160 = v67 + 255;
    v70 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)(v67 + 255));
    }
    else
    {
      do
        v161 = __ldrex(v160);
      while ( __strex(1u, v160) );
      __dmb(0xBu);
      if ( v161 )
        KxWaitForSpinLockAndAcquire(v67 + 255);
    }
  }
  if ( v67[250] )
  {
    __dmb(0xBu);
    v71 = v67 + 250;
    do
      v72 = __ldrex(v71);
    while ( __strex(v72 - 1, v71) );
    __dmb(0xBu);
    if ( !v68 )
      goto LABEL_107;
    if ( v67[250] )
    {
      if ( v69 )
      {
        v168 = (_DWORD *)v67[254];
        *v69 = v67 + 253;
        v69[1] = v168;
        if ( (_DWORD *)*v168 != v67 + 253 )
          __fastfail(3u);
        *v168 = v69;
        v67[254] = v69;
      }
    }
    else
    {
      if ( v69 )
        ExFreePoolWithTag(v69);
      v162 = (__int64 **)(v67 + 251);
      while ( *v162 != (__int64 *)v162 )
      {
        v163 = **v162;
        v164 = v67[251];
        if ( (__int64 **)HIDWORD(v163) != v162 || *(__int64 **)(v163 + 4) != *v162 )
          __fastfail(3u);
        *v162 = (__int64 *)v163;
        *(_DWORD *)(v163 + 4) = v162;
        ExFreePoolWithTag(v164);
      }
      v165 = (__int64 **)(v67 + 253);
      while ( *v165 != (__int64 *)v165 )
      {
        v166 = **v165;
        v167 = v67[253];
        if ( (__int64 **)HIDWORD(v166) != v165 || *(__int64 **)(v166 + 4) != *v165 )
          __fastfail(3u);
        *v165 = (__int64 *)v166;
        *(_DWORD *)(v166 + 4) = v165;
        ExFreePoolWithTag(v167);
      }
    }
  }
  if ( v68 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v67 + 255, vars4);
    }
    else
    {
      __dmb(0xBu);
      v67[255] = 0;
    }
    KfLowerIrql(v70);
  }
LABEL_107:
  v73 = *(_DWORD *)(v41 + 28);
  *(_DWORD *)(v41 + 4) = 0;
  __dmb(0xBu);
  do
    v74 = __ldrex((unsigned int *)v41);
  while ( !v74 && __strex(1u, (unsigned int *)v41) );
  if ( v74 )
    ExpReleaseFastMutexContended((unsigned int *)v41, v74);
  result = KfLowerIrql((unsigned __int8)v73);
  if ( KiAbEnabled && (v41 & 0x7FFFFFFC) != 0 )
  {
    v75 = 0;
    v76 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( v41 >= dword_63389C )
    {
      result = 4092;
      v77 = *((unsigned __int8 *)&MiState[2423]
            + ((int)(((v41 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
      if ( v77 == 1 || v77 == 11 )
      {
        result = MmGetSessionIdEx(*(_DWORD *)(v76 + 116));
        v172 = result;
      }
    }
    if ( (unsigned int)KeGetCurrentIrql(result) <= 1 )
    {
      v75 = 1;
      --*(_WORD *)(v76 + 310);
    }
    v78 = *(char *)(v76 + 484);
    __dmb(0xBu);
    v79 = (v78 | *(char *)(v76 + 810)) ^ 0x3F;
    v80 = __clz(v79);
    result = 31 - v80;
    v185 = 31 - v80;
    if ( 1 != (unsigned __int8)(v80 >> 5) )
    {
      v81 = 2147483644;
      while ( 1 )
      {
        v79 &= ~(1 << result);
        v82 = v76 + 48 * result;
        v83 = v82 + 488;
        if ( (*(_BYTE *)(v82 + 502) & 1) != 0
          && (*(_DWORD *)(v82 + 504) & 1) == 0
          && (*(_DWORD *)(v82 + 504) & 0x7FFFFFFC) == (v41 & 0x7FFFFFFC)
          && *(_DWORD *)(v82 + 508) == v172 )
        {
          *(_BYTE *)(v82 + 502) &= 0xFEu;
          if ( *(_DWORD *)(v82 + 504) )
            break;
        }
        v121 = __clz(v79);
        result = 31 - v121;
        v185 = 31 - v121;
        if ( 1 == (unsigned __int8)(v121 >> 5) )
          goto LABEL_212;
      }
      *(_BYTE *)(v82 + 504) |= 2u;
      if ( *(int *)(v82 + 504) < 0 )
        KiAbEntryRemoveFromTree(v83);
      v84 = *(_WORD *)(v83 + 44);
      if ( v84 )
      {
        if ( (v84 & 1) != 0 )
        {
          __dmb(0xBu);
          v136 = (unsigned int *)(v76 + 804);
          do
            v137 = __ldrex(v136);
          while ( __strex(v137 - 1, v136) );
          __dmb(0xBu);
          PsBoostThreadIoEx(v76, 1, 0);
        }
        if ( (*(_WORD *)(v83 + 44) & 0xFFFE) != 0 )
          KiAbThreadUnboostCpuPriority(v76, v83, v81, *(_WORD *)(v83 + 44) & 0xFFFE);
        if ( (dword_682604 & 0x200) != 0 )
          EtwTraceAutoBoostClearFloor(v76, *(_DWORD *)(v83 + 16) & 0xFFFFFFFC | 0x80000000, *(_WORD *)(v83 + 44));
        *(_WORD *)(v83 + 44) = 0;
      }
      *(_BYTE *)(v83 + 13) &= 0xFEu;
      *(_DWORD *)(v83 + 16) = 0;
      result = (unsigned __int64)(715827883i64 * (v83 - v76 - 488)) >> 32;
      v85 = (v83 - v76 - 488) / 48;
      if ( !v75 )
      {
        __dmb(0xBu);
        v138 = 1 << v85;
        v139 = (unsigned __int8 *)(v76 + 810);
        do
          result = __ldrex(v139);
        while ( __strex(result | v138, v139) );
        __dmb(0xBu);
        return result;
      }
      *(_BYTE *)(v76 + 484) |= 1 << v85;
      v86 = (__int16)(*(_WORD *)(v76 + 310) + 1);
      *(_WORD *)(v76 + 310) = v86;
      if ( v86 || *(_DWORD *)(v76 + 100) == v76 + 100 )
        return result;
      return KiCheckForKernelApcDelivery(result);
    }
LABEL_212:
    if ( (*(_DWORD *)(v76 + 80) & 0x8000) == 0 )
      KeBugCheck2(354, v76, v41, v172, 0, 0);
    if ( v75 )
    {
      v122 = (__int16)(*(_WORD *)(v76 + 310) + 1);
      *(_WORD *)(v76 + 310) = v122;
      if ( !v122 && *(_DWORD *)(v76 + 100) != v76 + 100 )
        return KiCheckForKernelApcDelivery(result);
    }
  }
  return result;
}
