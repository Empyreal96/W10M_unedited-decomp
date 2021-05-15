// ExAllocatePoolWithTag 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExAllocatePoolWithTag(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r9
  unsigned int v5; // r8
  int v7; // r2
  int v8; // r5
  int v9; // r1
  int v10; // r3
  __int16 v11; // r6
  unsigned int v12; // r7
  unsigned int v13; // r8
  unsigned int v14; // r3
  unsigned int v15; // r4
  int v16; // r0
  int v17; // r2
  int v18; // r5
  unsigned int v19; // r2
  int v20; // r8
  int v21; // r10
  int v22; // lr
  int v23; // r6
  int v24; // r2
  int v25; // r7
  int v26; // r3
  unsigned int *v27; // r4
  unsigned int *v28; // r2
  unsigned int v29; // r1
  unsigned int *v30; // r0
  unsigned int v31; // r1
  int v32; // r4
  unsigned int *v33; // r2
  unsigned int v34; // r1
  unsigned int *v35; // r0
  unsigned int v36; // r1
  unsigned int v37; // r2
  int v38; // r3
  int v39; // r3
  int v40; // r4
  int v41; // r2
  int v42; // r0
  int v43; // r2
  unsigned int v44; // r10
  int v45; // r5
  int *v46; // r6
  int v47; // r0
  int v48; // r7
  int v49; // r8
  unsigned int *v50; // r1
  unsigned int v51; // r0
  unsigned int *v52; // r1
  unsigned int v53; // r4
  unsigned __int8 *v54; // r4
  unsigned int *v55; // r0
  int v56; // r6
  int v57; // r8
  unsigned int v58; // r2
  unsigned int v59; // r1
  int *v60; // r0
  int v61; // r2
  int v62; // r6
  unsigned int v63; // r1
  unsigned int *v64; // r2
  unsigned int v65; // r1
  unsigned int v66; // r10
  int v67; // r5
  int v68; // r8
  int v69; // r2
  int v70; // r3
  unsigned int v71; // r2
  unsigned int v72; // r1
  int v73; // r3
  unsigned int v74; // r1
  int v75; // r4
  int v76; // r3
  __int16 v77; // r3
  int v78; // r5
  unsigned int v79; // r2
  int v80; // r5
  int v81; // r1
  int v82; // r8
  _DWORD *v83; // r10
  unsigned int *v84; // r2
  unsigned int v85; // r4
  unsigned int v86; // r4
  unsigned int *v87; // r5
  int v88; // r0
  int v89; // r3
  int v90; // r1 OVERLAPPED
  unsigned int v91; // r1
  __int16 v92; // r2
  __int16 v93; // r2
  int v94; // r4
  __int16 v95; // r1
  __int16 v96; // r2
  __int16 v97; // r1
  int v98; // r2
  int v99; // r1
  int *v100; // r0
  __int16 v101; // r3
  _DWORD *v102; // r4
  int v103; // r6
  _DWORD *v104; // r7
  int v105; // r8
  unsigned int *v106; // r2
  unsigned int v107; // r1
  unsigned int v108; // r7
  int v109; // r4
  unsigned int v110; // r1
  int v111; // r0
  int v112; // r8
  int v113; // r6
  int v114; // r3
  int v115; // r2
  int v116; // lr
  unsigned int v117; // r1
  int v118; // r0
  int v119; // r2
  int v120; // r3
  int v121; // r4
  __int16 v122; // r3
  int v123; // r2
  __int16 v124; // r3
  unsigned int *v125; // r2
  unsigned int v126; // r1
  unsigned int *v127; // r1
  int v128; // r2
  unsigned int v129; // r4
  _DWORD *v130; // r1
  __int16 v131; // r3
  __int16 v132; // r2
  int v133; // r2
  unsigned int v134; // r0
  int v135; // r3
  int v136; // r6
  __int16 v137; // r4
  __int16 v138; // r3
  __int16 v139; // r2
  __int16 v140; // r3
  unsigned int v141; // r3
  int v142; // r3
  unsigned int v143; // r3
  unsigned int v144; // r4
  unsigned int v145; // r1
  char v146; // r5
  unsigned __int8 *v147; // r4
  unsigned int v148; // r0
  char v149; // r3
  unsigned __int8 *v150; // r3
  unsigned int v151; // r2
  unsigned int v152; // r2
  unsigned int *v153; // r2
  unsigned int v154; // r1
  unsigned int v155; // r7
  _BYTE *v156; // r0
  int v157; // r6
  int v158; // r1
  int v159; // r5
  int v160; // r10
  int *v161; // r3
  int v162; // r0
  int v163; // r8
  int v164; // lr
  int v165; // r9
  unsigned int *v166; // r5
  unsigned int v167; // r3
  unsigned int v168; // r2
  unsigned int *v169; // r2
  unsigned int v170; // r1
  unsigned int *v171; // r2
  unsigned int v172; // r0
  unsigned int *v173; // r2
  unsigned int v174; // r1
  unsigned int *v175; // r2
  unsigned int v176; // r0
  unsigned int v177; // r1
  unsigned int v178; // r4
  unsigned int v179; // r4
  _BYTE *v180; // r0
  unsigned int *v181; // r4
  unsigned int v182; // r2
  _DWORD *v183; // r1
  int v184; // r8
  int v185; // r4
  int v186; // r0
  _BYTE *v187; // r0
  unsigned int *v188; // r10
  unsigned int v189; // r2
  __int64 **v190; // r7
  __int64 v191; // r2
  unsigned int v192; // r0
  __int64 **v193; // r7
  __int64 v194; // r2
  unsigned int v195; // r0
  _DWORD *v196; // r1
  char v197; // r2
  unsigned __int8 *v198; // r4
  unsigned int v199; // r0
  int v200; // [sp+8h] [bp-70h]
  int v201; // [sp+8h] [bp-70h]
  int v202; // [sp+Ch] [bp-6Ch]
  unsigned int v204; // [sp+14h] [bp-64h]
  int v205; // [sp+14h] [bp-64h]
  int v206; // [sp+14h] [bp-64h]
  unsigned int *v207; // [sp+18h] [bp-60h]
  int v208; // [sp+1Ch] [bp-5Ch]
  int v209; // [sp+20h] [bp-58h]
  int v210; // [sp+24h] [bp-54h]
  int v211; // [sp+24h] [bp-54h]
  int v212; // [sp+28h] [bp-50h]
  int v213; // [sp+28h] [bp-50h]
  int v214; // [sp+2Ch] [bp-4Ch]
  unsigned int v215; // [sp+30h] [bp-48h]
  _DWORD v216[2]; // [sp+38h] [bp-40h] BYREF
  char v217; // [sp+40h] [bp-38h]
  char v218[12]; // [sp+48h] [bp-30h] BYREF
  unsigned int v219; // [sp+54h] [bp-24h]
  int vars4; // [sp+7Ch] [bp+4h]

  v3 = a3;
  v4 = a1;
  v5 = a2;
  v214 = a2;
  if ( (a1 & 0x44) == 68 )
    return sub_60D408(4);
  if ( (a1 & 2) != 0 )
    KeBugCheckEx(65, a2, 0, 0, 0);
  v7 = 32;
  v8 = a1 & 1;
  v9 = 512;
  if ( (a1 & 0x20) != 0 )
  {
    if ( (a1 & 1) == 0 )
    {
      v10 = PoolVector[0];
      v202 = PoolVector[0];
      goto LABEL_41;
    }
    v10 = MiSessionPoolVector(4, 512);
  }
  else
  {
    v10 = PoolVector[v8];
  }
  v202 = v10;
  if ( v8 )
  {
LABEL_7:
    v11 = ExpPoolFlags;
    goto LABEL_8;
  }
LABEL_41:
  if ( (v4 & v9) != 0 )
    goto LABEL_7;
  v11 = ExpPoolFlags;
  if ( (ExpPoolFlags & 0x800) != 0 )
    v4 |= v9;
  else
    v202 = v10 + 4736;
LABEL_8:
  if ( (v11 & 8) != 0 )
  {
    if ( (v4 & 0x80000080) == 0 )
      return VeAllocatePoolWithTagPriority(v4, v5, v3, 32, vars4);
    v4 &= 0xFFFFFF7F;
  }
  if ( MmSpecialPoolTag )
  {
    if ( ExpUseSpecialPool(v5, v3, v7, MmSpecialPoolTag) )
    {
      v155 = v4;
      if ( (v4 & 0x20) != 0 && (v4 & 1) == 0 )
        v155 = v4 & 0xFFFFFFDF;
      v156 = (_BYTE *)MmAllocateSpecialPool(v5, v3, v155, 2);
      v32 = (int)v156;
      if ( v156 )
      {
        if ( (v4 & 0x40) != 0 )
        {
          v5 -= 4;
          v214 = v5;
        }
        if ( v4 < 0 )
          memset(v156, 0, v5);
        v157 = a3 & 0x7FFFFFFF;
        if ( (a3 & 0x7FFFFFFF) == PoolHitTag )
          __debugbreak();
        if ( (dword_682604 & 0x41) != 0 )
          EtwTracePool(3616, v155, v157, v32, v5);
        v158 = v155 & 0x20;
        if ( (v155 & 0x20) != 0 )
        {
          v159 = ExpSessionPoolTrackTable;
          v160 = ExpSessionPoolTrackTableMask;
          v161 = &ExpSessionPoolTrackTableSize;
        }
        else
        {
          v159 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
          v160 = PoolTrackTableMask;
          v161 = &PoolTrackTableSize;
        }
        v162 = *v161;
        v206 = *v161;
        v201 = v159;
        v163 = v160 & ((int)(40543
                           * (((a3 & 0x7FFFFFFFu) >> 24) ^ (4
                                                          * ((unsigned __int8)((a3 & 0x7FFFFFFFu) >> 16) ^ (4 * (BYTE1(a3) ^ (4 * (unsigned __int8)a3))))))) >> 2);
        v164 = v163;
        while ( 1 )
        {
          while ( 1 )
          {
            v165 = 28 * v163;
            v166 = (unsigned int *)(v159 + 28 * v163);
            if ( *v166 == v157 )
            {
              if ( (v155 & 1) != 0 )
              {
                v173 = v166 + 4;
                do
                  v174 = __ldrex(v173);
                while ( __strex(v174 + 1, v173) );
                v175 = v166 + 6;
                do
                  v176 = __ldrex(v175);
                while ( __strex(v176 + v214, v175) );
              }
              else
              {
                v169 = v166 + 1;
                do
                  v170 = __ldrex(v169);
                while ( __strex(v170 + 1, v169) );
                v171 = v166 + 3;
                do
                  v172 = __ldrex(v171);
                while ( __strex(v172 + v214, v171) );
              }
              goto LABEL_309;
            }
            if ( !*v166 )
              break;
LABEL_297:
            v163 = (v163 + 1) & v160;
            v159 = v201;
            if ( v163 == v164 )
            {
              ExpInsertPoolTrackerExpansion(v157, v214, v155);
              do
LABEL_309:
                v177 = __ldrex((unsigned int *)&ExpSpecialAllocations);
              while ( __strex(v177 + 1, (unsigned int *)&ExpSpecialAllocations) );
              return v32;
            }
          }
          if ( v158 || (v167 = *(_DWORD *)(v165 + PoolTrackTable)) == 0 )
          {
            if ( v163 == v162 - 1 )
              goto LABEL_297;
            if ( v158 )
            {
              do
                v168 = __ldrex(v166);
              while ( !v168 && __strex(v157, v166) );
              v159 = v201;
            }
            else
            {
              KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v218);
              if ( !*(_DWORD *)(v165 + PoolTrackTable) )
              {
                *(_DWORD *)(v165 + PoolTrackTable) = v157;
                *v166 = v157;
              }
              KeReleaseInStackQueuedSpinLock((int)v218);
              v158 = v155 & 0x20;
              v164 = v160 & ((int)(40543
                                 * (((a3 & 0x7FFFFFFFu) >> 24) ^ (4
                                                                * ((unsigned __int8)((a3 & 0x7FFFFFFFu) >> 16) ^ (4 * (BYTE1(a3) ^ (4 * (unsigned __int8)a3))))))) >> 2);
              v162 = v206;
              v159 = v201;
            }
          }
          else
          {
            *v166 = v167;
            v159 = v201;
          }
        }
      }
      v11 = ExpPoolFlags;
      v3 = a3;
    }
    v7 = 32;
    v9 = 512;
  }
  if ( v5 > 0xFF0 )
  {
    v32 = ExpAllocateBigPool(0, v4, v5, v3, 0);
    if ( v32 )
      return v32;
LABEL_387:
    ++ExPoolFailures;
    if ( (v4 & 2) != 0 )
      KeBugCheckEx(65, v5, dword_643E80[1184 * ((v4 & 0x200) == 0)], dword_643D88[1184 * ((v4 & 0x200) == 0)], 0);
    if ( (v4 & 0x10) != 0 )
      RtlRaiseStatus(-1073741670);
    return 0;
  }
  if ( !v5 )
    v5 = 1;
  v12 = v5 + 15;
  if ( (v4 & 4) != 0 )
  {
    if ( !ExpCacheLineSize )
      __brkdiv0();
    v134 = ((v12 & 0xFFFFFFF8) + ExpCacheLineSize - 1) / ExpCacheLineSize;
    v9 = 512;
    if ( (v134 + 1) * ExpCacheLineSize > 0xFF0 )
      v4 &= 0xFFFFFFFB;
    else
      v12 = (v134 + 1) * ExpCacheLineSize;
    v7 = 32;
  }
  v13 = v12 >> 3;
  v204 = v12 >> 3;
  if ( v8 )
  {
    if ( (v4 & v7) != 0 )
    {
      if ( v13 <= ExpSessionPoolSmallLists )
      {
        v15 = ExpSessionPoolLookaside + (v13 << 7) - 128;
        *(_DWORD *)(v15 + 12) = *(_DWORD *)(ExpSessionPoolLookaside + (v13 << 7) - 116) + 1;
        v16 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v15);
        if ( v16 )
          goto LABEL_20;
      }
    }
    else if ( (v4 & 0x80000000) == 0 )
    {
      if ( v13 <= 0x20 && (v11 & 0x100) == 0 )
      {
        v14 = (unsigned int)KeGetPcr();
        v15 = (v14 & 0xFFFFF000) + 1408 + 72 * v13 + 15032;
        *(_DWORD *)(v15 + 12) = *(_DWORD *)((v14 & 0xFFFFF000) + 1408 + 72 * v13 + 0x3AC4) + 1;
        v16 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v15);
        if ( v16 )
        {
LABEL_20:
          v17 = *(_DWORD *)(v16 - 4);
          v18 = v16 - 12;
          if ( v17 != (ExpPoolQuotaCookie ^ (v16 - 12)) )
            KeBugCheckEx(25, 14, v16 - 12, v17, ExpPoolQuotaCookie ^ (v16 - 12));
          ++*(_DWORD *)(v15 + 16);
          *(_WORD *)(v16 - 10) = *(_WORD *)(v16 - 10) & 0x1FF | ((v4 & 0xFFEF | 2) << 9);
          goto LABEL_22;
        }
        v11 = ExpPoolFlags;
      }
      if ( (v11 & 0x100) != 0 )
      {
        if ( (v4 & 0x100) != 0 )
          v40 = ExpNumberOfPagedPools;
        else
          v40 = 1;
      }
      else
      {
        if ( (unsigned __int16)KeNumberNodes > 1u )
        {
          v179 = *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266);
          v39 = ExpNumberOfPagedPools;
          if ( v179 < ExpNumberOfPagedPools )
          {
            v200 = v179 + 1;
            v202 = ExpPagedPoolDescriptor[v179 + 1];
            goto LABEL_65;
          }
        }
        else
        {
          v39 = ExpNumberOfPagedPools;
        }
        v40 = 1;
        v200 = 1;
        if ( v39 == 1 )
          goto LABEL_64;
        v40 = ExpPoolIndex + 1;
        if ( ExpPoolIndex + 1 > (unsigned int)ExpNumberOfPagedPools )
          v40 = 1;
        ExpPoolIndex = v40;
        v41 = v40;
        do
        {
          if ( !*(_DWORD *)(ExpPagedPoolDescriptor[v40] + 8) )
            break;
          if ( ++v40 > (unsigned int)ExpNumberOfPagedPools )
            v40 = 1;
        }
        while ( v40 != v41 );
      }
      v200 = v40;
LABEL_64:
      v202 = ExpPagedPoolDescriptor[v40];
      goto LABEL_65;
    }
LABEL_54:
    v200 = 0;
LABEL_65:
    v42 = 1408;
    v43 = 4736;
    goto LABEL_66;
  }
  if ( v13 <= 0x20 )
  {
    v37 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 + 72 * v13;
    v38 = (v4 & v9) != 0 ? 10424 : 12728;
    v15 = v37 + v38;
    ++*(_DWORD *)(v37 + v38 + 12);
    v16 = RtlpInterlockedPopEntrySList((unsigned __int64 *)(v37 + v38));
    if ( v16 )
      goto LABEL_20;
  }
  if ( (unsigned int)ExpNumberOfNonPagedPools <= 1 )
    goto LABEL_54;
  v178 = *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266);
  v200 = v178;
  if ( v178 >= ExpNumberOfNonPagedPools )
  {
    v178 = ExpNumberOfNonPagedPools - 1;
    v200 = ExpNumberOfNonPagedPools - 1;
  }
  v43 = 4736;
  v42 = 1408;
  v202 = ExpNonPagedPoolDescriptor[v178];
  if ( (v4 & 0x200) == 0 )
    v202 = ExpNonPagedPoolDescriptor[v178] + 4736;
LABEL_66:
  v211 = 0;
  v44 = v13 + 79;
  v213 = -1;
  v45 = v202;
  v215 = v13 + 79;
LABEL_67:
  v46 = (int *)(v45 + 8 * v44);
  while ( (int *)*v46 == v46 )
  {
LABEL_69:
    v46 += 2;
    v42 = 1408;
    if ( v46 == (int *)(v202 + 4736) )
    {
      v5 = 4096;
      v47 = MiAllocatePoolPages(v4 & 0x80000221, 0x1000u, v43, -2147483103);
      v18 = v47;
      if ( v47 )
      {
        if ( v4 < 0 )
        {
          memset((_BYTE *)(v47 + 8), 0, 8 * v204 - 8);
          *(_DWORD *)(v18 + 4) = a3;
        }
        *(_DWORD *)v18 = 0;
        *(_WORD *)v18 = *(_WORD *)v18 & 0x1FF | ((_WORD)v200 << 9);
        *(_WORD *)(v18 + 2) = v204 & 0x1FF | ((v4 & 0xFFEF | 2) << 9);
        v48 = v18 + 8 * v204;
        *(_DWORD *)v48 = 0;
        v49 = v202;
        *(_WORD *)(v48 + 2) ^= (*(_WORD *)(v48 + 2) ^ (512 - v204)) & 0x1FF;
        v50 = (unsigned int *)(v202 + 384);
        *(_WORD *)v48 = v204 & 0x1FF | ((_WORD)v200 << 9);
        do
          v51 = __ldrex(v50);
        while ( __strex(v51 + 1, v50) );
        v52 = (unsigned int *)(v202 + 144);
        do
          v53 = __ldrex(v52);
        while ( __strex(v53 + 8 * v204, v52) );
        if ( (*(_WORD *)(v48 + 2) & 0x1FF) != 1 )
        {
          v54 = (unsigned __int8 *)(v202 + 4);
          v55 = (unsigned int *)(v202 + 4);
          if ( (v4 & 1) != 0 )
          {
            v56 = KeAbPreAcquire((unsigned int)v55, 0, 0);
            v57 = KfRaiseIrql(1);
            do
              v58 = __ldrex(v54);
            while ( __strex(v58 & 0xFE, v54) );
            __dmb(0xBu);
            if ( (v58 & 1) == 0 )
              ExpAcquireFastMutexContended((int)v54, v56);
            if ( v56 )
              *(_BYTE *)(v56 + 14) |= 1u;
            *(_DWORD *)(v202 + 8) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            *(_DWORD *)(v202 + 32) = v57;
            PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, 0);
            v49 = v202;
          }
          else
          {
            KeAcquireInStackQueuedSpinLock(v55, (unsigned int)v216);
          }
          v59 = v49 + 8 * (591 - v204);
          v60 = *(int **)(v59 + 4);
          v61 = v48 + 8;
          *(_DWORD *)(v48 + 8) = v59;
          *(_DWORD *)(v48 + 12) = v60;
          if ( *v60 != v59 )
            __fastfail(3u);
          *v60 = v61;
          *(_DWORD *)(v59 + 4) = v61;
          if ( (v4 & 1) != 0 )
          {
            PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, 0);
            v62 = *(_DWORD *)(v202 + 32);
            *(_DWORD *)(v202 + 8) = 0;
            __dmb(0xBu);
            do
              v63 = __ldrex((unsigned int *)v54);
            while ( !v63 && __strex(1u, (unsigned int *)v54) );
            if ( v63 )
              ExpReleaseFastMutexContended((unsigned int *)v54, v63);
            KfLowerIrql((unsigned __int8)v62);
            KeAbPostRelease((unsigned int)v54);
          }
          else
          {
            KeReleaseInStackQueuedSpinLock((int)v216);
          }
        }
        v64 = (unsigned int *)(v49 + 128);
        do
          v65 = __ldrex(v64);
        while ( __strex(v65 + 1, v64) );
        goto LABEL_22;
      }
      if ( ++v211 != 1 || (ExpPoolFlags & 0x200) == 0 )
        goto LABEL_387;
      v45 = v202;
      ExDeferredFreePool(v202, 0);
      v44 = v215;
      v42 = 1408;
      goto LABEL_67;
    }
  }
  if ( (v4 & 1) != 0 )
  {
    v66 = v45 + 4;
    v207 = (unsigned int *)(v45 + 4);
    if ( !KiAbEnabled || (v67 = v66 & 0x7FFFFFFC, (v66 & 0x7FFFFFFC) == 0) )
    {
      v75 = 0;
      goto LABEL_115;
    }
    v68 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v69 = 0;
    }
    else
    {
      __disable_irq();
      v69 = 1;
    }
    v70 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v69 )
      __enable_irq();
    if ( (v70 & 0x10001) != 0 )
    {
      v186 = KeGetCurrentIrql(1408);
      KeBugCheckEx(402, v68, v66, v186, 0);
    }
    --*(_WORD *)(v68 + 310);
    if ( !*(_BYTE *)(v68 + 484) )
    {
      if ( !*(_BYTE *)(v68 + 810) )
      {
        v75 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          v42 = (int)EtwTraceAutoBoostEntryExhaustion(v68, v66);
        goto LABEL_244;
      }
      v146 = *(_BYTE *)(v68 + 810);
      v147 = (unsigned __int8 *)(v68 + 810);
      __dmb(0xBu);
      do
        v148 = __ldrex(v147);
      while ( __strex(v148 & ~v146, v147) );
      __dmb(0xBu);
      v149 = *(_BYTE *)(v68 + 484) | v146;
      v67 = v66 & 0x7FFFFFFC;
      *(_BYTE *)(v68 + 484) = v149;
    }
    v71 = *(unsigned __int8 *)(v68 + 484);
    v42 = 1;
    v72 = __clz(__rbit(v71));
    v73 = v71 & ~(1 << v72);
    v219 = v72;
    v74 = v68 + 48 * v72;
    v75 = v74 + 488;
    *(_BYTE *)(v68 + 484) = v73;
    if ( v74 != -488 )
    {
      if ( v66 >= dword_63389C
        && ((v76 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v66 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v76 == 1)
         || v76 == 11) )
      {
        v42 = MmGetSessionIdEx(*(_DWORD *)(v68 + 116));
      }
      else
      {
        v42 = -1;
      }
      *(_DWORD *)(v75 + 20) = v42;
      *(_DWORD *)(v75 + 16) = v67;
LABEL_112:
      v77 = *(_WORD *)(v68 + 310) + 1;
      *(_WORD *)(v68 + 310) = v77;
      if ( !v77 && *(_DWORD *)(v68 + 100) != v68 + 100 )
        KiCheckForKernelApcDelivery(v42);
LABEL_115:
      v78 = KfRaiseIrql(1);
      do
        v79 = __ldrex((unsigned __int8 *)v66);
      while ( __strex(v79 & 0xFE, (unsigned __int8 *)v66) );
      __dmb(0xBu);
      if ( (v79 & 1) == 0 )
        ExpAcquireFastMutexContended(v66, v75);
      if ( v75 )
        *(_BYTE *)(v75 + 14) |= 1u;
      *(_DWORD *)(v66 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v66 + 28) = v78;
      v80 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v81 = 0;
      v82 = 0;
      v208 = 0;
      v83 = 0;
      if ( !PspAlwaysTrackIoBoosting )
        goto LABEL_122;
      v82 = 1;
      v180 = (_BYTE *)ExAllocatePoolWithTag(512, 56);
      v83 = v180;
      if ( v180 )
      {
        memset(v180, 0, 56);
        RtlCaptureStackBackTrace(1u, 0xAu, (int)(v83 + 2), 0);
        v83[12] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v83[13] = 0;
      }
      v181 = (unsigned int *)(v80 + 1020);
      v81 = KfRaiseIrql(2);
      v208 = v81;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v80 + 1020);
      }
      else
      {
        do
          v182 = __ldrex(v181);
        while ( __strex(1u, v181) );
        __dmb(0xBu);
        if ( !v182 )
          goto LABEL_122;
        KxWaitForSpinLockAndAcquire((unsigned int *)(v80 + 1020));
      }
      v81 = v208;
LABEL_122:
      __dmb(0xBu);
      v84 = (unsigned int *)(v80 + 1000);
      do
      {
        v85 = __ldrex(v84);
        v86 = v85 + 1;
      }
      while ( __strex(v86, v84) );
      __dmb(0xBu);
      if ( v82 )
      {
        if ( v83 )
        {
          v183 = *(_DWORD **)(v80 + 1008);
          *v83 = v80 + 1004;
          v83[1] = v183;
          if ( *v183 != v80 + 1004 )
            __fastfail(3u);
          *v183 = v83;
          v81 = v208;
          *(_DWORD *)(v80 + 1008) = v83;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented((_DWORD *)(v80 + 1020), vars4);
          v81 = v208;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)(v80 + 1020) = 0;
        }
        KfLowerIrql(v81);
      }
      if ( v86 == 1 && KiAbEnabled && *(_BYTE *)(v80 + 485) )
      {
        v184 = KfRaiseIrql(2);
        v185 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
        if ( KiAbThreadInsertList(v80, (_DWORD *)(v185 + 17412), (_DWORD *)(v80 + 776)) )
          KiAbQueueAutoBoostDpc(v185);
        KfLowerIrql(v184);
      }
      v87 = v207;
      goto LABEL_129;
    }
LABEL_244:
    v150 = (unsigned __int8 *)(v68 + 81);
    do
      v151 = __ldrex(v150);
    while ( __strex(v151 | 0x80, v150) );
    goto LABEL_112;
  }
  v87 = (unsigned int *)(v45 + 4);
  v216[0] = 0;
  v216[1] = v87;
  __dmb(0xBu);
  v217 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireQueuedSpinLockInstrumented((int)v216, v87);
  }
  else
  {
    do
      v130 = (_DWORD *)__ldrex(v87);
    while ( __strex((unsigned int)v216, v87) );
    __dmb(0xBu);
    if ( v130 )
      KxWaitForLockOwnerShip((int)v216, v130);
  }
LABEL_129:
  if ( (int *)*v46 == v46 )
  {
    if ( (v4 & 1) != 0 )
    {
      PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, 0);
      v144 = v87[7];
      v87[1] = 0;
      __dmb(0xBu);
      do
        v145 = __ldrex(v87);
      while ( !v145 && __strex(1u, v87) );
      if ( v145 )
        ExpReleaseFastMutexContended(v87, v145);
      KfLowerIrql((unsigned __int8)v144);
      KeAbPostRelease((unsigned int)v87);
    }
    else
    {
      KeReleaseInStackQueuedSpinLock((int)v216);
    }
    v45 = v202;
    goto LABEL_69;
  }
  v88 = *v46;
  v89 = *(_DWORD *)(*(_DWORD *)*v46 + 4);
  if ( v89 != *v46 || **(_DWORD **)(v88 + 4) != v88 )
    KeBugCheckEx(25, 3, *v46, v89, **(_DWORD **)(v88 + 4));
  *(_QWORD *)&v90 = *(_QWORD *)v88;
  if ( *(int **)(v88 + 4) != v46 || *(_DWORD *)(v90 + 4) != v88 )
    __fastfail(3u);
  *v46 = v90;
  v18 = v88 - 8;
  *(_DWORD *)(v90 + 4) = v46;
  v91 = *(unsigned __int16 *)(v88 - 8);
  if ( v91 >> 9 != v200 )
    KeBugCheckEx(25, 35, v91 >> 9, v200, v18);
  v92 = *(_WORD *)(v88 - 6);
  if ( (v92 & 0x1FF) != v204 )
  {
    if ( (v91 & 0x1FF) != 0 )
    {
      v93 = v92 & 0xFE00 | (v92 - v204) & 0x1FF;
      *(_WORD *)(v88 - 6) = v93;
      v94 = v88 - 8;
      v18 += 8 * (v93 & 0x1FF);
      *(_WORD *)v18 ^= (*(_WORD *)v18 ^ *(_WORD *)(v88 - 6)) & 0x1FF;
      if ( (((_WORD)v18 + 8 * (_WORD)v204) & 0xFFF) != 0 )
        *(_WORD *)(v18 + 8 * v204) ^= (*(_WORD *)(v18 + 8 * v204) ^ v204) & 0x1FF;
    }
    else
    {
      v94 = v18 + 8 * v204;
      v131 = *(_WORD *)v94;
      *(_WORD *)(v94 + 2) ^= ((v92 - v204) ^ *(_WORD *)(v94 + 2)) & 0x1FF;
      v132 = *(_WORD *)(v94 + 2);
      *(_WORD *)v94 = (v131 ^ v204) & 0x1FF ^ v131;
      v133 = v132 & 0x1FF;
      if ( (((_WORD)v94 + 8 * (_WORD)v133) & 0xFFF) != 0 )
        *(_WORD *)(v94 + 8 * v133) = *(_WORD *)(v94 + 8 * v133) & 0xFE00 | v133;
    }
    v95 = (*(_WORD *)(v18 + 2) ^ v204) & 0x1FF ^ *(_WORD *)(v18 + 2);
    *(_WORD *)v18 = *(_WORD *)v18 & 0x1FF | ((_WORD)v200 << 9);
    *(_WORD *)(v18 + 2) = v95;
    v96 = *(_WORD *)v94;
    v97 = *(_WORD *)(v94 + 2) & 0x1FF;
    *(_DWORD *)(v94 + 4) = 1701147206;
    *(_WORD *)(v94 + 2) = v97;
    *(_WORD *)v94 = v96 & 0x1FF | ((_WORD)v200 << 9);
    if ( (v97 & 0x1FF) != 1 )
    {
      v98 = v94 + 8;
      v99 = v202 + 8 * ((v97 & 0x1FF) + 79);
      v100 = *(int **)(v99 + 4);
      *(_DWORD *)(v94 + 8) = v99;
      *(_DWORD *)(v94 + 12) = v100;
      if ( *v100 != v99 )
        __fastfail(3u);
      *v100 = v98;
      *(_DWORD *)(v99 + 4) = v98;
    }
  }
  v101 = *(_WORD *)(v18 + 2) & 0x1FF | ((v4 & 0x6D | 2) << 9);
  *(_WORD *)(v18 + 2) = v101;
  if ( v4 < 0 )
  {
    memset((_BYTE *)(v18 + 8), 0, 8 * (v101 & 0x1FF) - 8);
    *(_DWORD *)(v18 + 4) = a3;
  }
  if ( (v4 & 1) == 0 )
  {
    KeReleaseInStackQueuedSpinLock((int)v216);
    goto LABEL_175;
  }
  v102 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v103 = 0;
  v104 = 0;
  v105 = 0;
  if ( PspAlwaysTrackIoBoosting )
  {
    v103 = 1;
    v187 = (_BYTE *)ExAllocatePoolWithTag(512, 56);
    v104 = v187;
    if ( v187 )
    {
      memset(v187, 0, 56);
      RtlCaptureStackBackTrace(1u, 0xAu, (int)(v104 + 2), 0);
      v104[12] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v104[13] = 0;
    }
    v188 = v102 + 255;
    v105 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)(v102 + 255));
    }
    else
    {
      do
        v189 = __ldrex(v188);
      while ( __strex(1u, v188) );
      __dmb(0xBu);
      if ( v189 )
        KxWaitForSpinLockAndAcquire(v102 + 255);
    }
  }
  if ( v102[250] )
  {
    __dmb(0xBu);
    v106 = v102 + 250;
    do
      v107 = __ldrex(v106);
    while ( __strex(v107 - 1, v106) );
    __dmb(0xBu);
    if ( !v103 )
      goto LABEL_150;
    if ( v102[250] )
    {
      if ( v104 )
      {
        v196 = (_DWORD *)v102[254];
        *v104 = v102 + 253;
        v104[1] = v196;
        if ( (_DWORD *)*v196 != v102 + 253 )
          __fastfail(3u);
        *v196 = v104;
        v102[254] = v104;
      }
    }
    else
    {
      if ( v104 )
        ExFreePoolWithTag((unsigned int)v104);
      v190 = (__int64 **)(v102 + 251);
      while ( *v190 != (__int64 *)v190 )
      {
        v191 = **v190;
        v192 = v102[251];
        if ( (__int64 **)HIDWORD(v191) != v190 || *(__int64 **)(v191 + 4) != *v190 )
          __fastfail(3u);
        *v190 = (__int64 *)v191;
        *(_DWORD *)(v191 + 4) = v190;
        ExFreePoolWithTag(v192);
      }
      v193 = (__int64 **)(v102 + 253);
      while ( *v193 != (__int64 *)v193 )
      {
        v194 = **v193;
        v195 = v102[253];
        if ( (__int64 **)HIDWORD(v194) != v193 || *(__int64 **)(v194 + 4) != *v193 )
          __fastfail(3u);
        *v193 = (__int64 *)v194;
        *(_DWORD *)(v194 + 4) = v193;
        ExFreePoolWithTag(v195);
      }
    }
  }
  if ( v103 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v102 + 255, vars4);
    }
    else
    {
      __dmb(0xBu);
      v102[255] = 0;
    }
    KfLowerIrql(v105);
  }
LABEL_150:
  v108 = v202 + 4;
  v109 = *(_DWORD *)(v202 + 32);
  *(_DWORD *)(v202 + 8) = 0;
  __dmb(0xBu);
  do
    v110 = __ldrex((unsigned int *)v108);
  while ( !v110 && __strex(1u, (unsigned int *)v108) );
  if ( v110 )
    ExpReleaseFastMutexContended((unsigned int *)v108, v110);
  v111 = KfLowerIrql((unsigned __int8)v109);
  if ( KiAbEnabled && (v108 & 0x7FFFFFFC) != 0 )
  {
    v112 = 0;
    v113 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( v108 >= dword_63389C )
    {
      v111 = 4092;
      v114 = *((unsigned __int8 *)&MiState[2423]
             + ((int)(((v108 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
      if ( v114 == 1 || v114 == 11 )
      {
        v111 = MmGetSessionIdEx(*(_DWORD *)(v113 + 116));
        v213 = v111;
      }
    }
    if ( (unsigned int)KeGetCurrentIrql(v111) <= 1 )
    {
      v112 = 1;
      --*(_WORD *)(v113 + 310);
    }
    v115 = *(char *)(v113 + 484);
    __dmb(0xBu);
    v116 = (v115 | *(char *)(v113 + 810)) ^ 0x3F;
    v117 = __clz(v116);
    v118 = 31 - v117;
    if ( 1 == (unsigned __int8)(v117 >> 5) )
    {
LABEL_209:
      if ( (*(_DWORD *)(v113 + 80) & 0x8000) == 0 )
        KeBugCheckEx(354, v113, v108, v213, 0);
      if ( v112 )
      {
        v142 = (__int16)(*(_WORD *)(v113 + 310) + 1);
        *(_WORD *)(v113 + 310) = v142;
        if ( !v142 && *(_DWORD *)(v113 + 100) != v113 + 100 )
          goto LABEL_213;
      }
    }
    else
    {
      v119 = 2147483644;
      while ( 1 )
      {
        v116 &= ~(1 << v118);
        v120 = v113 + 48 * v118;
        v121 = v120 + 488;
        if ( (*(_BYTE *)(v120 + 502) & 1) != 0
          && (*(_DWORD *)(v120 + 504) & 1) == 0
          && (*(_DWORD *)(v120 + 504) & 0x7FFFFFFC) == (v108 & 0x7FFFFFFC)
          && *(_DWORD *)(v120 + 508) == v213 )
        {
          *(_BYTE *)(v120 + 502) &= 0xFEu;
          if ( *(_DWORD *)(v120 + 504) )
            break;
        }
        v141 = __clz(v116);
        v118 = 31 - v141;
        if ( 1 == (unsigned __int8)(v141 >> 5) )
          goto LABEL_209;
      }
      *(_BYTE *)(v120 + 504) |= 2u;
      if ( *(int *)(v120 + 504) < 0 )
        KiAbEntryRemoveFromTree(v121);
      v122 = *(_WORD *)(v121 + 44);
      if ( v122 )
      {
        if ( (v122 & 1) != 0 )
        {
          __dmb(0xBu);
          v153 = (unsigned int *)(v113 + 804);
          do
            v154 = __ldrex(v153);
          while ( __strex(v154 - 1, v153) );
          __dmb(0xBu);
          PsBoostThreadIoEx(v113, 1, 0);
        }
        if ( (*(_WORD *)(v121 + 44) & 0xFFFE) != 0 )
          KiAbThreadUnboostCpuPriority(v113, v121, v119, *(_WORD *)(v121 + 44) & 0xFFFE);
        if ( (dword_682604 & 0x200) != 0 )
          EtwTraceAutoBoostClearFloor(v113, *(_DWORD *)(v121 + 16) & 0xFFFFFFFC | 0x80000000, *(_WORD *)(v121 + 44));
        *(_WORD *)(v121 + 44) = 0;
      }
      *(_BYTE *)(v121 + 13) &= 0xFEu;
      *(_DWORD *)(v121 + 16) = 0;
      v118 = (unsigned __int64)(715827883i64 * (v121 - v113 - 488)) >> 32;
      v123 = (v121 - v113 - 488) / 48;
      if ( v112 )
      {
        *(_BYTE *)(v113 + 484) |= 1 << v123;
        v124 = *(_WORD *)(v113 + 310) + 1;
        *(_WORD *)(v113 + 310) = v124;
        if ( v124 || *(_DWORD *)(v113 + 100) == v113 + 100 )
          goto LABEL_175;
LABEL_213:
        KiCheckForKernelApcDelivery(v118);
        goto LABEL_175;
      }
      __dmb(0xBu);
      v197 = 1 << v123;
      v198 = (unsigned __int8 *)(v113 + 810);
      do
        v199 = __ldrex(v198);
      while ( __strex(v199 | v197, v198) );
      __dmb(0xBu);
    }
  }
LABEL_175:
  v125 = (unsigned int *)(v202 + 128);
  do
    v126 = __ldrex(v125);
  while ( __strex(v126 + 1, v125) );
  v127 = (unsigned int *)(v202 + 144);
  v128 = 8 * (*(_WORD *)(v18 + 2) & 0x1FF);
  do
    v129 = __ldrex(v127);
  while ( __strex(v129 + v128, v127) );
LABEL_22:
  v19 = 8 * (*(_WORD *)(v18 + 2) & 0x1FF);
  *(_DWORD *)(v18 + 4) = a3;
  v20 = a3 & 0x7FFFFFFF;
  v205 = v19;
  if ( (a3 & 0x7FFFFFFF) == PoolHitTag )
    __debugbreak();
  if ( (dword_682604 & 0x41) != 0 )
    EtwTracePool(3616, v4, a3 & 0x7FFFFFFF, v18 + 8, v19);
  if ( (v4 & 0x20) != 0 )
  {
    v21 = ExpSessionPoolTrackTable;
    v22 = ExpSessionPoolTrackTableMask;
    v209 = ExpSessionPoolTrackTableSize;
  }
  else
  {
    v21 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
    v22 = PoolTrackTableMask;
    v209 = PoolTrackTableSize;
  }
  v210 = v22;
  v23 = v22 & ((int)(40543
                   * (((a3 & 0x7FFFFFFFu) >> 24) ^ (4
                                                  * ((unsigned __int8)((a3 & 0x7FFFFFFFu) >> 16) ^ (4
                                                                                                  * (BYTE1(a3) ^ (4 * (unsigned __int8)a3))))))) >> 2);
  v24 = v23;
  v212 = v23;
  while ( 1 )
  {
    v25 = 28 * v23;
    v26 = *(_DWORD *)(28 * v23 + v21);
    v27 = (unsigned int *)(28 * v23 + v21);
    if ( v26 == v20 )
      break;
    if ( v26 )
      goto LABEL_30;
    if ( (v4 & 0x20) == 0 )
    {
      v143 = *(_DWORD *)(v25 + PoolTrackTable);
      if ( v143 )
      {
        *v27 = v143;
        continue;
      }
    }
    if ( v23 == v209 - 1 )
    {
LABEL_30:
      v23 = (v23 + 1) & v22;
      if ( v23 == v24 )
      {
        ExpInsertPoolTrackerExpansion(v20, v205, v4);
        goto LABEL_37;
      }
    }
    else if ( (v4 & 0x20) != 0 )
    {
      do
        v152 = __ldrex(v27);
      while ( !v152 && __strex(v20, v27) );
      v24 = v212;
    }
    else
    {
      KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v218);
      if ( !*(_DWORD *)(v25 + PoolTrackTable) )
      {
        *(_DWORD *)(v25 + PoolTrackTable) = v20;
        *v27 = v20;
      }
      KeReleaseInStackQueuedSpinLock((int)v218);
      v22 = v210;
      v24 = v212;
    }
  }
  if ( (v4 & 1) != 0 )
  {
    v28 = v27 + 4;
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 + 1, v28) );
    v30 = v27 + 6;
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 + v205, v30) );
  }
  else
  {
    v33 = v27 + 1;
    do
      v34 = __ldrex(v33);
    while ( __strex(v34 + 1, v33) );
    v35 = v27 + 3;
    do
      v36 = __ldrex(v35);
    while ( __strex(v36 + v205, v35) );
  }
LABEL_37:
  if ( (v4 & 4) != 0 )
  {
    *(_WORD *)(v18 + 2) &= 0xF7FFu;
    v135 = (-8 - v18) & (ExpCacheLineSize - 1);
    if ( v135 )
    {
      v136 = v135 + v18;
      v137 = (*(_WORD *)(v135 + v18) ^ (v135 >> 3)) & 0x1FF ^ *(_WORD *)(v135 + v18);
      *(_WORD *)v136 = v137;
      *(_WORD *)(v136 + 2) = ((*(_WORD *)(v18 + 2) - v137) ^ *(_WORD *)(v135 + v18 + 2)) & 0x1FF ^ *(_WORD *)(v135 + v18 + 2);
      v138 = *(_WORD *)(v135 + v18 + 2);
      *(_WORD *)v136 = (v137 ^ *(_WORD *)v18) & 0x1FF ^ *(_WORD *)v18;
      v139 = v138 & 0x1FF | *(_WORD *)(v18 + 2) & 0xF600 | 0x800;
      v140 = *(_WORD *)v136;
      *(_WORD *)(v136 + 2) = v139;
      *(_DWORD *)(v136 + 4) = *(_DWORD *)(v18 + 4);
      if ( (v140 & 0x1FFu) > 1 )
        *(_DWORD *)(v18 + 8) = ExpPoolQuotaCookie ^ v136;
      v18 = v136;
    }
  }
  *(_DWORD *)(v18 + 8) = 0;
  return v18 + 8;
}
