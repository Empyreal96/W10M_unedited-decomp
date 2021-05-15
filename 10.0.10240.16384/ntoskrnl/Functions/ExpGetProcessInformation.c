// ExpGetProcessInformation 
 
int __fastcall ExpGetProcessInformation(int a1, int a2, unsigned int *a3, int a4, int a5)
{
  unsigned int v6; // r3
  unsigned int v7; // r5
  int v8; // r2
  int v9; // r6
  int v10; // r3
  char v11; // r4
  int v12; // r0
  int v13; // r10
  int *v14; // r8
  int v15; // r3
  int v16; // r0
  _DWORD *v17; // r1
  int v18; // r4
  int v19; // r9
  int v20; // r6
  unsigned int v21; // r5
  int v22; // r0
  int v23; // r10
  int v24; // r4
  unsigned int v25; // r6
  _DWORD **v26; // r8
  int v27; // r10
  unsigned int *v28; // r9
  int v29; // r0
  int v30; // r5
  unsigned int v31; // r2
  _DWORD *i; // r5
  unsigned int *v33; // r5
  unsigned int v34; // r2
  int v35; // r0
  __int16 v36; // r3
  int *v37; // r2
  int v38; // r1
  int v39; // r5
  int v40; // r6
  unsigned int v41; // r8
  int v42; // r2
  int v43; // r1
  char v44; // r3
  unsigned int v45; // r2
  char v46; // r3
  int v47; // r1
  int v48; // r2
  unsigned int v49; // r2
  int *v50; // r9
  unsigned int v51; // r6
  unsigned int *v52; // r8
  int v53; // r0
  int v54; // r5
  unsigned int v55; // r2
  int *j; // r5
  int v57; // r8
  unsigned int *v58; // r5
  unsigned int v59; // r2
  int v60; // r0
  __int16 v61; // r3
  int *v62; // r2
  char v63; // r3
  int v64; // r5
  int v65; // r6
  unsigned int v66; // r2
  unsigned int v67; // r1
  int v68; // r9
  unsigned int v69; // r4
  unsigned int v70; // r6
  unsigned int *v71; // r5
  int v72; // r0
  int v73; // r4
  unsigned int v74; // r2
  _DWORD *v75; // r2
  int v76; // r0
  __int16 v77; // r3
  int v78; // r3
  int v79; // r5
  int v80; // r0
  __int16 v81; // r2
  int v82; // r3
  int v83; // r6
  int *v84; // r5
  int v85; // r0
  int v86; // r1
  int v87; // r2
  int v88; // r3
  int *v89; // r5
  int v90; // r0
  int v91; // r1
  int v92; // r2
  int v93; // r3
  int v94; // r3
  int v95; // r9
  int *v96; // r6
  unsigned int v97; // r10
  unsigned int *v98; // r5
  int v99; // r0
  int v100; // r4
  unsigned int v101; // r2
  int v102; // r5
  unsigned int k; // r4
  unsigned int l; // r0
  int *v105; // r8
  int v106; // lr
  unsigned int m; // r6
  unsigned int n; // r5
  unsigned int v109; // r2
  _QWORD *v110; // r4
  unsigned int *v111; // r4
  unsigned int v112; // r2
  int v113; // r0
  __int16 v114; // r3
  int v115; // r1
  int v116; // r5
  int v117; // r5
  int v118; // r4
  int v119; // r8
  unsigned int v120; // r6
  int v121; // r5
  int v122; // r0
  unsigned int v123; // r3
  int v124; // r0
  int v125; // r6
  unsigned int v126; // r5
  int v127; // r0
  int v128; // r6
  __int16 *v129; // r2
  unsigned int v130; // r6
  _WORD *v131; // r8
  _WORD *v132; // r4
  int v133; // r5
  int v134; // r0
  int v135; // r2
  int v136; // r2
  int v137; // r5
  unsigned int v138; // r6
  int v139; // r8
  int v140; // r4
  unsigned int v141; // r2
  int *v142; // r4
  unsigned int v143; // r2
  __int16 v144; // r3
  int v146; // [sp+14h] [bp-324h]
  unsigned int v147; // [sp+18h] [bp-320h]
  int v148; // [sp+1Ch] [bp-31Ch]
  int *v149; // [sp+20h] [bp-318h]
  unsigned int v150; // [sp+24h] [bp-314h] BYREF
  int v151; // [sp+28h] [bp-310h]
  int v152; // [sp+2Ch] [bp-30Ch]
  int v153; // [sp+30h] [bp-308h]
  int *v154; // [sp+34h] [bp-304h]
  unsigned int *v155; // [sp+38h] [bp-300h]
  int v156; // [sp+3Ch] [bp-2FCh]
  unsigned int v157; // [sp+40h] [bp-2F8h]
  int v158; // [sp+44h] [bp-2F4h]
  int v159; // [sp+48h] [bp-2F0h]
  int v160; // [sp+4Ch] [bp-2ECh]
  int v161; // [sp+50h] [bp-2E8h]
  int v162; // [sp+54h] [bp-2E4h]
  _DWORD *v163; // [sp+58h] [bp-2E0h]
  int v164; // [sp+5Ch] [bp-2DCh]
  int v165; // [sp+60h] [bp-2D8h]
  int v166; // [sp+64h] [bp-2D4h]
  int v167; // [sp+68h] [bp-2D0h]
  unsigned int *v168; // [sp+6Ch] [bp-2CCh]
  int v169; // [sp+70h] [bp-2C8h]
  int v170; // [sp+74h] [bp-2C4h]
  int v171; // [sp+78h] [bp-2C0h]
  int v172; // [sp+7Ch] [bp-2BCh]
  int v173; // [sp+80h] [bp-2B8h]
  int v174; // [sp+84h] [bp-2B4h]
  unsigned int v175; // [sp+88h] [bp-2B0h] BYREF
  int v176; // [sp+8Ch] [bp-2ACh] BYREF
  unsigned int v177; // [sp+90h] [bp-2A8h]
  int v178; // [sp+94h] [bp-2A4h] BYREF
  _DWORD *v179; // [sp+98h] [bp-2A0h]
  char v180; // [sp+9Ch] [bp-29Ch]
  _WORD *v181; // [sp+A0h] [bp-298h]
  int v182; // [sp+A4h] [bp-294h]
  _WORD *v183; // [sp+A8h] [bp-290h]
  int v184; // [sp+B0h] [bp-288h] BYREF
  unsigned __int8 v185; // [sp+B4h] [bp-284h]
  unsigned __int8 v186; // [sp+B5h] [bp-283h]
  char v187; // [sp+B6h] [bp-282h]
  char v188; // [sp+B7h] [bp-281h]
  unsigned int v189; // [sp+B8h] [bp-280h]
  unsigned int v190; // [sp+BCh] [bp-27Ch]
  unsigned int v191; // [sp+C0h] [bp-278h]
  int v192; // [sp+C4h] [bp-274h] BYREF
  unsigned int v193; // [sp+C8h] [bp-270h]
  unsigned int v194; // [sp+CCh] [bp-26Ch]
  int v195; // [sp+D0h] [bp-268h]
  int v196; // [sp+D4h] [bp-264h]
  int v197; // [sp+D8h] [bp-260h]
  int v198; // [sp+DCh] [bp-25Ch]
  int v199; // [sp+E0h] [bp-258h]
  int v200; // [sp+E4h] [bp-254h]
  int v201; // [sp+E8h] [bp-250h]
  int v202; // [sp+ECh] [bp-24Ch]
  int v203; // [sp+F0h] [bp-248h]
  _DWORD v204[20]; // [sp+F8h] [bp-240h] BYREF
  _BYTE v205[72]; // [sp+148h] [bp-1F0h] BYREF
  _BYTE v206[136]; // [sp+190h] [bp-1A8h] BYREF
  _DWORD _218[78]; // [sp+218h] [bp-120h] BYREF

  _218[74] = a1;
  _218[76] = a3;
  v164 = a4;
  _218[77] = a4;
  v155 = a3;
  v6 = a2;
  v157 = a2;
  _218[75] = a2;
  v166 = a1;
  v171 = a1;
  v168 = a3;
  v154 = 0;
  v148 = 0;
  v146 = 0;
  v174 = 0;
  v7 = 0;
  v147 = 0;
  v150 = 0;
  if ( a3 )
    *a3 = 0;
  if ( a5 == 5 )
  {
    a2 = 0;
    v161 = 0;
    v8 = 64;
  }
  else
  {
    v161 = 1;
    v8 = 96;
  }
  v169 = v8;
  v159 = v8;
  v167 = 400;
  v173 = 400;
  v153 = a1;
  v158 = a1;
  if ( v6 >= 0x190 )
  {
    v9 = 0;
  }
  else
  {
    v8 = -1073741820;
    v9 = -1073741820;
    v148 = -1073741820;
    v146 = -1073741820;
    if ( !a3 )
      return -1073741820;
  }
  v162 = 0;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_BYTE *)(v10 + 346);
  if ( a5 == 148 )
  {
    v12 = ExpCheckFullProcessInformationAccess(*(_BYTE *)(v10 + 346), a2, v8, v10);
    if ( v12 < 0 )
      return v12;
  }
  if ( ExIsRestrictedCaller(v11) )
    v162 = 1;
  v13 = 0;
  v152 = 0;
  KeFlushProcessWriteBuffers(1);
  v165 = PsGetCurrentSilo();
  v170 = v165;
  v14 = (int *)PsIdleProcess;
  v149 = (int *)PsIdleProcess;
  v154 = (int *)PsIdleProcess;
  while ( v14 )
  {
    if ( (v14[48] & 4) != 0 && v14[1] )
    {
      v15 = v14[101];
      __dmb(0xBu);
      v14 = v154;
      v149 = v154;
      if ( !v15 && (int *)v154[10] == v154 + 10 )
      {
        v148 = v146;
        v13 = v152;
        v147 = v150;
        v153 = v158;
        goto LABEL_265;
      }
      v7 = v150;
      v153 = v158;
      v147 = v150;
      v13 = v152;
      v148 = v146;
    }
    if ( v164 && v14 == (int *)PsIdleProcess )
      goto LABEL_265;
    v16 = MmGetSessionId((int)v14);
    v18 = v16;
    v201 = v16;
    if ( v17 )
    {
      if ( v16 != *v17 )
        goto LABEL_265;
    }
    if ( !PsIsProcessInSilo((int)v14, v165) )
      goto LABEL_265;
    v19 = v166 + v7;
    v153 = v166 + v7;
    v158 = v166 + v7;
    v20 = v167;
    v151 = v167;
    v156 = v167;
    v13 = RtlULongAdd(v7, v167, &v150);
    v172 = v13;
    v152 = v13;
    if ( v13 < 0 )
      goto LABEL_29;
    memset(v204, 0, sizeof(v204));
    v21 = v150;
    v147 = v150;
    if ( v150 <= v157 )
    {
      v22 = ExpCopyProcessInfo(v19, v14, v161, v204);
      v172 = v22;
      v152 = v22;
      if ( v22 < 0 )
      {
        v146 = v22;
        goto LABEL_308;
      }
      *(_DWORD *)(v19 + 4) = 0;
      *(_DWORD *)v19 = 0;
      *(_DWORD *)(v19 + 80) = v18;
      *(_DWORD *)(v19 + 60) = 0;
      *(_WORD *)(v19 + 56) = 0;
      *(_WORD *)(v19 + 58) = 0;
      if ( v14 == (int *)PsIdleProcess )
      {
        *(_DWORD *)(v19 + 76) = 0;
        *(_DWORD *)(v19 + 80) = 0;
      }
    }
    else
    {
      v148 = -1073741820;
      v146 = -1073741820;
      if ( !v155 )
        goto LABEL_308;
    }
    v23 = v19 + 184;
    v163 = (_DWORD *)(v19 + 184);
    v160 = v19 + 184;
    if ( v14 == (int *)PsIdleProcess )
    {
      v37 = (int *)v14[10];
      if ( v37 == v14 + 10 )
      {
        v24 = 0;
      }
      else
      {
        v24 = (int)(v37 - 117);
        KeSynchronizeWithDynamicProcessors();
      }
    }
    else
    {
      v24 = 0;
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = (_DWORD **)(v14 + 99);
      v27 = 0;
      --*(_WORD *)(v25 + 308);
      v28 = (unsigned int *)(v149 + 42);
      v29 = KeAbPreAcquire((unsigned int)(v149 + 42), 0, 0);
      v30 = v29;
      v199 = 0;
      v193 = 17;
      do
        v31 = __ldrex(v28);
      while ( !v31 && __strex(0x11u, v28) );
      __dmb(0xBu);
      v193 = v31;
      if ( v31 )
        ExfAcquirePushLockSharedEx(v28, v29, (unsigned int)v28);
      if ( v30 )
        *(_BYTE *)(v30 + 14) |= 1u;
      for ( i = *v26; i != v26; i = (_DWORD *)*i )
      {
        v24 = (int)(i - 233);
        if ( ObReferenceObjectSafeWithTag((int)(i - 233)) )
        {
          v27 = 1;
          break;
        }
      }
      v33 = (unsigned int *)(v149 + 42);
      v203 = 17;
      v182 = 0;
      __dmb(0xBu);
      do
        v34 = __ldrex(v33);
      while ( v34 == 17 && __strex(0, v33) );
      v182 = v34;
      if ( v34 != 17 )
        ExfReleasePushLockShared(v33);
      v35 = KeAbPostRelease((unsigned int)v33);
      v36 = *(_WORD *)(v25 + 308) + 1;
      *(_WORD *)(v25 + 308) = v36;
      if ( !v36 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
        KiCheckForKernelApcDelivery(v35);
      if ( !v27 )
        v24 = 0;
      v20 = v151;
      v21 = v147;
      v19 = v153;
      v23 = (int)v163;
    }
    v174 = v24;
    while ( v24 )
    {
      if ( !*(_BYTE *)(v24 + 4) )
      {
        v39 = RtlULongAdd(v21, v159, &v150);
        v172 = v39;
        v152 = v39;
        if ( v39 < 0 )
          goto LABEL_69;
        v40 = v20 + v38;
        v151 = v40;
        v156 = v40;
        v41 = v150;
        v147 = v150;
        if ( v150 <= v157 )
        {
          KeQueryValuesThread(v24, (int)&v184);
          v42 = v185;
          if ( v185 == 4 )
          {
            v151 = v40 - v159;
            v156 = v40 - v159;
            v147 = v41 - v159;
            v150 = v41 - v159;
          }
          else
          {
            *(_DWORD *)(v23 + 24) = v184;
            *(_DWORD *)(v23 + 52) = v42;
            *(_DWORD *)(v23 + 56) = v186;
            *(_DWORD *)(v23 + 40) = v187;
            *(_DWORD *)(v23 + 44) = v188;
            *(_QWORD *)v23 = (unsigned int)KeMaximumIncrement * (unsigned __int64)*(unsigned int *)(v24 + 404);
            *(_QWORD *)(v23 + 8) = (unsigned int)KeMaximumIncrement * (unsigned __int64)*(unsigned int *)(v24 + 448);
            v43 = *(_DWORD *)(v24 + 836);
            *(_DWORD *)(v23 + 16) = *(_DWORD *)(v24 + 832);
            *(_DWORD *)(v23 + 20) = v43;
            *(_DWORD *)(v23 + 48) = *(_DWORD *)(v24 + 128);
            *(_DWORD *)(v23 + 32) = *(_DWORD *)(v24 + 876);
            *(_DWORD *)(v23 + 36) = *(_DWORD *)(v24 + 880);
            if ( (*(_DWORD *)(v24 + 76) & 0x400) != 0 )
            {
              v45 = *(_DWORD *)(v24 + 924);
            }
            else
            {
              v44 = *(_BYTE *)(v24 + 968);
              __dmb(0xBu);
              if ( (v44 & 8) != 0
                || (v45 = *(_DWORD *)(v174 + 856), __dmb(0xFu), v46 = *(_BYTE *)(v24 + 968), __dmb(0xBu), (v46 & 8) != 0) )
              {
                v45 = 0;
              }
              v151 = v156;
              v149 = v154;
              v148 = v146;
              v39 = v152;
              v172 = v152;
              v24 = v174;
              v147 = v150;
              v19 = v158;
              v153 = v158;
              v23 = v160;
            }
            v47 = v162;
            if ( v162 && v45 > MmHighestUserAddress )
              *(_DWORD *)(v23 + 28) = 0;
            else
              *(_DWORD *)(v23 + 28) = v45;
            if ( v161 )
            {
              if ( v47 )
              {
                *(_DWORD *)(v23 + 64) = 0;
                *(_DWORD *)(v23 + 68) = 0;
              }
              else
              {
                *(_DWORD *)(v23 + 64) = *(_DWORD *)(v24 + 40);
                v48 = *(_DWORD *)(v24 + 36);
                __dmb(0xBu);
                v23 = v160;
                *(_DWORD *)(v160 + 68) = v48;
                v151 = v156;
                v149 = v154;
                v148 = v146;
                v39 = v152;
                v172 = v152;
                v24 = v174;
                v147 = v150;
                v19 = v158;
                v153 = v158;
              }
              v49 = *(_DWORD *)(v24 + 924);
              if ( v47 && v49 > MmHighestUserAddress )
                *(_DWORD *)(v23 + 72) = 0;
              else
                *(_DWORD *)(v23 + 72) = v49;
              *(_DWORD *)(v23 + 76) = *(_DWORD *)(v24 + 156);
              *(_DWORD *)(v23 + 80) = 0;
              *(_DWORD *)(v23 + 84) = 0;
              *(_DWORD *)(v23 + 88) = 0;
            }
            ++*(_DWORD *)(v19 + 4);
            if ( v39 < 0 )
            {
LABEL_69:
              v146 = v39;
              goto LABEL_308;
            }
            v163 = (_DWORD *)(v23 + v159);
            v160 = v23 + v159;
          }
        }
        else
        {
          v148 = -1073741820;
          v146 = -1073741820;
          if ( !v155 )
            goto LABEL_308;
        }
      }
      if ( v149 == (int *)PsIdleProcess )
      {
        v62 = *(int **)(v24 + 468);
        if ( v62 == v149 + 10 )
        {
          v24 = 0;
        }
        else
        {
          v24 = (int)(v62 - 117);
          if ( KeDynamicPartitioningSupported )
          {
            __dmb(0xFu);
            v63 = KiDynamicProcessorLock;
            __dmb(0xBu);
            if ( (v63 & 1) == 0 )
            {
              v64 = KeAbPreAcquire((unsigned int)&KiDynamicProcessorLock, 0, 0);
              v65 = KfRaiseIrql(1);
              do
                v66 = __ldrex((unsigned __int8 *)&KiDynamicProcessorLock);
              while ( __strex(v66 & 0xFE, (unsigned __int8 *)&KiDynamicProcessorLock) );
              __dmb(0xBu);
              if ( (v66 & 1) == 0 )
                ExpAcquireFastMutexContended((int)&KiDynamicProcessorLock, v64);
              if ( v64 )
                *(_BYTE *)(v64 + 14) |= 1u;
              __mrc(15, 0, 13, 0, 3);
              dword_624E5C = v65;
              dword_624E44 = 0;
              __dmb(0xBu);
              do
                v67 = __ldrex((unsigned int *)&KiDynamicProcessorLock);
              while ( !v67 && __strex(1u, (unsigned int *)&KiDynamicProcessorLock) );
              if ( v67 )
                ExpReleaseFastMutexContended((unsigned int *)&KiDynamicProcessorLock, v67);
              KfLowerIrql((unsigned __int8)v65);
              KeAbPostRelease((unsigned int)&KiDynamicProcessorLock);
            }
          }
        }
      }
      else
      {
        v50 = 0;
        v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v182 = 0;
        --*(_WORD *)(v51 + 308);
        v52 = (unsigned int *)(v149 + 42);
        v53 = KeAbPreAcquire((unsigned int)(v149 + 42), 0, 0);
        v54 = v53;
        v198 = 0;
        v191 = 17;
        do
          v55 = __ldrex(v52);
        while ( !v55 && __strex(0x11u, v52) );
        __dmb(0xBu);
        v191 = v55;
        if ( v55 )
          ExfAcquirePushLockSharedEx(v52, v53, (unsigned int)v52);
        if ( v54 )
          *(_BYTE *)(v54 + 14) |= 1u;
        for ( j = *(int **)(v24 + 932); j != v149 + 99; j = (int *)*j )
        {
          v50 = j - 233;
          if ( ObReferenceObjectSafeWithTag((int)(j - 233)) )
          {
            v57 = 1;
            goto LABEL_110;
          }
        }
        v57 = v182;
LABEL_110:
        v58 = (unsigned int *)(v149 + 42);
        v195 = 17;
        v194 = 0;
        __dmb(0xBu);
        do
          v59 = __ldrex(v58);
        while ( v59 == 17 && __strex(0, v58) );
        v194 = v59;
        if ( v59 != 17 )
          ExfReleasePushLockShared(v58);
        v60 = KeAbPostRelease((unsigned int)v58);
        v61 = *(_WORD *)(v51 + 308) + 1;
        *(_WORD *)(v51 + 308) = v61;
        if ( !v61 && *(_DWORD *)(v51 + 100) != v51 + 100 && !*(_WORD *)(v51 + 310) )
          KiCheckForKernelApcDelivery(v60);
        if ( v24 )
          ObfDereferenceObjectWithTag(v24);
        if ( !v57 )
          v50 = 0;
        v24 = (int)v50;
      }
      v174 = v24;
      v20 = v151;
      v21 = v147;
      v19 = v153;
      v23 = (int)v163;
    }
    v179 = (_DWORD *)v23;
    v68 = v23 + 216;
    v160 = v23 + 216;
    if ( v148 < 0 )
    {
      v13 = v172;
      v115 = v151;
    }
    else
    {
      v69 = ObFastReferenceObject(v149 + 61);
      if ( !v69 )
      {
        v70 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v70 + 308);
        v71 = (unsigned int *)(v149 + 42);
        v72 = KeAbPreAcquire((unsigned int)(v149 + 42), 0, 0);
        v73 = v72;
        v172 = 17;
        do
          v74 = __ldrex(v71);
        while ( !v74 && __strex(0x11u, v71) );
        __dmb(0xBu);
        v172 = v74;
        if ( v74 )
          ExfAcquirePushLockSharedEx(v149 + 42, v72, (unsigned int)(v149 + 42));
        if ( v73 )
          *(_BYTE *)(v73 + 14) |= 1u;
        v69 = ObFastReferenceObjectLocked(v149 + 61);
        v163 = 0;
        __dmb(0xBu);
        do
          v75 = (_DWORD *)__ldrex(v71);
        while ( v75 == (_DWORD *)17 && __strex(0, v71) );
        v163 = v75;
        if ( v75 != (_DWORD *)17 )
          ExfReleasePushLockShared(v149 + 42);
        v76 = KeAbPostRelease((unsigned int)(v149 + 42));
        v77 = *(_WORD *)(v70 + 308) + 1;
        *(_WORD *)(v70 + 308) = v77;
        if ( !v77 && *(_DWORD *)(v70 + 100) != v70 + 100 && !*(_WORD *)(v70 + 310) )
          KiCheckForKernelApcDelivery(v76);
      }
      v78 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v78 & 0xFFFFFFC0) + 0x134);
      ExAcquireResourceSharedLite(*(_DWORD *)(v69 + 48), 1);
      v79 = AuthzBasepSecurityAttributePresent(*(_DWORD *)(v69 + 476), (int)&PspSysAppIdClaim);
      ExReleaseResourceLite(*(_DWORD *)(v69 + 48));
      v80 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v81 = *(_WORD *)(v80 + 0x134);
      *(_WORD *)(v80 + 308) = v81 + 1;
      if ( v81 == -1 && *(_DWORD *)(v80 + 100) != v80 + 100 && !*(_WORD *)(v80 + 310) )
        KiCheckForKernelApcDelivery(v80);
      v180 = v79;
      ObFastDereferenceObject(v149 + 61, v69);
      *(_DWORD *)(v23 + 52) = 0;
      *(_DWORD *)(v23 + 56) = 0;
      *(_DWORD *)(v23 + 208) = 0;
      v82 = v149[216];
      __dmb(0xBu);
      v83 = (int)v179;
      v163 = v179;
      v179[53] = v82 << 12;
      *(_DWORD *)(v83 + 40) = v204[6];
      *(_DWORD *)(v83 + 44) = v204[7];
      *(_DWORD *)(v83 + 48) = 0;
      if ( v79 )
        *(_DWORD *)(v83 + 48) = 1;
      v149 = v154;
      v84 = (int *)v154[194];
      if ( v84 )
      {
        v85 = *v84;
        v86 = v84[1];
        v87 = v84[2];
        v88 = v84[3];
        v89 = v84 + 4;
        *(_DWORD *)v83 = v85;
        *(_DWORD *)(v83 + 4) = v86;
        *(_DWORD *)(v83 + 8) = v87;
        *(_DWORD *)(v83 + 12) = v88;
        v90 = *v89;
        v91 = v89[1];
        v92 = v89[2];
        v93 = v89[3];
        v89 += 4;
        *(_DWORD *)(v83 + 16) = v90;
        *(_DWORD *)(v83 + 20) = v91;
        *(_DWORD *)(v83 + 24) = v92;
        *(_DWORD *)(v83 + 28) = v93;
        v94 = v89[1];
        *(_DWORD *)(v83 + 32) = *v89;
        *(_DWORD *)(v83 + 36) = v94;
      }
      else
      {
        memset((_BYTE *)v83, 0, 40);
      }
      v95 = v83 + 64;
      if ( !PoEnergyEstimationEnabled() || (v96 = v149, v149 == (int *)PsIdleProcess) )
      {
        memset((_BYTE *)v95, 0, 144);
      }
      else
      {
        v97 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v97 + 0x134);
        v98 = (unsigned int *)(v149 + 180);
        v99 = KeAbPreAcquire((unsigned int)(v149 + 180), 0, 0);
        v100 = v99;
        v200 = 0;
        v153 = 17;
        do
          v101 = __ldrex(v98);
        while ( !v101 && __strex(0x11u, v98) );
        __dmb(0xBu);
        v153 = v101;
        if ( v101 )
          ExfAcquirePushLockSharedEx(v149 + 180, v99, (unsigned int)(v149 + 180));
        if ( v100 )
          *(_BYTE *)(v100 + 14) |= 1u;
        v102 = v149[199];
        *(_QWORD *)(v95 + 64) = *(_QWORD *)(v102 + 64);
        *(_QWORD *)(v95 + 72) = *(_QWORD *)(v102 + 72);
        *(_QWORD *)(v95 + 80) = *(_QWORD *)(v102 + 80);
        *(_QWORD *)(v95 + 88) = *(_QWORD *)(v102 + 88);
        *(_QWORD *)(v95 + 96) = *(_QWORD *)(v102 + 96);
        *(_DWORD *)(v95 + 104) = *(_DWORD *)(v102 + 104);
        *(_DWORD *)(v95 + 108) = *(_DWORD *)(v102 + 108);
        *(_QWORD *)(v95 + 112) = *(_QWORD *)(v102 + 112);
        *(_QWORD *)(v95 + 120) = *(_QWORD *)(v102 + 120);
        *(_QWORD *)(v95 + 128) = *(_QWORD *)(v102 + 128);
        *(_QWORD *)(v95 + 136) = *(_QWORD *)(v102 + 136);
        for ( k = 0; k < 4; ++k )
        {
          for ( l = 0; l < 2; ++l )
            *(_QWORD *)(v95 + 8 * (l + 2 * k)) = *(_QWORD *)(v102 + 8 * (l + 2 * k));
        }
        v105 = (int *)v149[99];
        while ( v105 != v96 + 99 )
        {
          v106 = v105[38];
          for ( m = 0; m < 4; ++m )
          {
            for ( n = 0; n < 2; ++n )
            {
              v109 = n + 2 * m;
              v110 = (_QWORD *)(v95 + 8 * v109);
              *v110 += *(_QWORD *)(v106 + 8 * v109);
            }
          }
          v105 = (int *)*v105;
          v96 = v149;
        }
        v111 = (unsigned int *)(v96 + 180);
        v202 = 17;
        v151 = 0;
        __dmb(0xBu);
        do
          v112 = __ldrex(v111);
        while ( v112 == 17 && __strex(0, v111) );
        v151 = v112;
        if ( v112 != 17 )
          ExfReleasePushLockShared(v96 + 180);
        v113 = KeAbPostRelease((unsigned int)(v96 + 180));
        v114 = *(_WORD *)(v97 + 308) + 1;
        *(_WORD *)(v97 + 308) = v114;
        if ( !v114 && *(_DWORD *)(v97 + 100) != v97 + 100 && !*(_WORD *)(v97 + 310) )
          KiCheckForKernelApcDelivery(v113);
      }
      v13 = v152;
      if ( v152 < 0 )
      {
        v146 = v152;
        goto LABEL_308;
      }
      v115 = v156;
      v151 = v156;
      v148 = v146;
      v147 = v150;
      v153 = v158;
      v68 = v160;
    }
    v116 = a5;
    if ( a5 == 148 )
    {
      v117 = PsReferencePrimaryToken((int)v149);
      SeQueryUserSidToken(v117, (int)v205, 0x44u, &v175);
      v178 = 254;
      v176 = 130;
      v152 = RtlQueryPackageIdentity(v117, (int)_218, (int)&v178, (int)v206, (int)&v176, 0);
      if ( v152 >= 0 )
      {
        v119 = v176;
        v118 = v178;
      }
      else
      {
        v118 = 0;
        v178 = 0;
        v119 = 0;
        v176 = 0;
      }
      ObFastDereferenceObject(v149 + 61, v117);
      v120 = v175;
      v121 = (v175 + 7) & 0xFFFFFFF8;
      v177 = v121;
      v122 = RtlULongAdd(v147, v121, &v150);
      v13 = v122;
      v152 = v122;
      if ( v122 < 0 )
      {
        v146 = v122;
        goto LABEL_308;
      }
      v151 += v121;
      v156 = v151;
      v123 = v150;
      v147 = v150;
      if ( v150 <= v157 )
      {
        v163[13] = 216;
        memmove(v68, (int)v205, v120);
        v123 = v147;
        if ( v13 < 0 )
        {
          v146 = v13;
          goto LABEL_308;
        }
        v68 += v121;
        v160 = v68;
      }
      else
      {
        v148 = -1073741820;
        v146 = -1073741820;
        if ( !v155 )
          goto LABEL_308;
      }
      if ( v118 )
      {
        v177 = v118;
        v124 = RtlULongAdd(v123, v118, &v150);
        v13 = v124;
        v152 = v124;
        if ( v124 < 0 )
        {
          v146 = v124;
          goto LABEL_308;
        }
        v125 = v151 + v118;
        v151 = v125;
        v156 = v125;
        v126 = v150;
        v147 = v150;
        if ( v150 <= v157 )
        {
          v163[14] = v68 - (_DWORD)v163;
          memmove(v68, (int)_218, v118);
          if ( v13 < 0 )
          {
            v146 = v13;
            goto LABEL_308;
          }
          v68 += v118;
          v160 = v68;
        }
        else
        {
          v148 = -1073741820;
          v146 = -1073741820;
          if ( !v155 )
            goto LABEL_308;
        }
      }
      else
      {
        v125 = v151;
        v126 = v147;
      }
      if ( v119 )
      {
        v177 = v119;
        v127 = RtlULongAdd(v126, v119, &v150);
        v13 = v127;
        v152 = v127;
        if ( v127 < 0 )
        {
          v146 = v127;
          goto LABEL_308;
        }
        v151 = v125 + v119;
        v156 = v125 + v119;
        v147 = v150;
        if ( v150 <= v157 )
        {
          v163[52] = v68 - (_DWORD)v163;
          memmove(v68, (int)v206, v119);
          v115 = v151;
          v128 = v148;
          v116 = 148;
          if ( v13 < 0 )
          {
            v146 = v13;
            goto LABEL_308;
          }
          v68 += v119;
          v160 = v68;
        }
        else
        {
          v128 = -1073741820;
          v148 = -1073741820;
          v146 = -1073741820;
          if ( !v155 )
            goto LABEL_308;
          v115 = v151;
          v116 = 148;
        }
        goto LABEL_239;
      }
      v115 = v151;
      v116 = 148;
    }
    v128 = v148;
LABEL_239:
    v14 = v149;
    if ( v149 != (int *)PsIdleProcess )
    {
      if ( v149 == (int *)PsInitialSystemProcess )
        v129 = &ExpSystemProcessName;
      else
        v129 = (__int16 *)v149[95];
      v130 = (unsigned __int16)*v129;
      v177 = v130;
      v131 = (_WORD *)v68;
      v181 = (_WORD *)v68;
      v175 = v130;
      v132 = (_WORD *)*((_DWORD *)v129 + 1);
      v183 = v132;
      if ( v116 != 148 && v130 )
      {
        v132 += v130 >> 1;
        v183 = v132;
        while ( v132 != *((_WORD **)v129 + 1) )
        {
          v183 = --v132;
          if ( *v132 == 92 )
          {
            v183 = ++v132;
            break;
          }
        }
        v130 -= 2 * (((int)v132 - *((_DWORD *)v129 + 1)) >> 1);
        v175 = v130;
      }
      v133 = (v130 + 9) & 0xFFFFFFF8;
      v177 = v133;
      v134 = RtlULongAdd(v147, v133, &v150);
      v13 = v134;
      v152 = v134;
      if ( v134 < 0 )
      {
        v146 = v134;
        goto LABEL_308;
      }
      v135 = v151 + v133;
      v151 = v135;
      v156 = v135;
      v147 = v150;
      if ( v150 <= v157 )
      {
        if ( v130 )
        {
          memmove(v68, (int)v132, v130);
          v131 = (_WORD *)(v68 + 2 * (v130 >> 1));
          v181 = v131;
        }
        *v131++ = 0;
        v181 = v131;
        v115 = v151;
        v128 = v148;
        if ( v13 < 0 )
        {
          v146 = v13;
          goto LABEL_308;
        }
      }
      else
      {
        v128 = -1073741820;
        v148 = -1073741820;
        v146 = -1073741820;
        if ( !v155 )
          goto LABEL_308;
        v115 = v135;
      }
      if ( v128 < 0 )
      {
        v14 = v149;
      }
      else
      {
        v136 = v153;
        *(_WORD *)(v153 + 56) = (_WORD)v131 - v68 - 2;
        *(_WORD *)(v136 + 58) = v133;
        *(_DWORD *)(v136 + 60) = v68;
        v14 = v149;
        if ( v13 < 0 )
        {
          v146 = v13;
          goto LABEL_308;
        }
      }
    }
    if ( v128 >= 0 )
    {
      *(_DWORD *)v153 = v115;
      if ( v13 < 0 )
      {
LABEL_29:
        v146 = v13;
        goto LABEL_308;
      }
    }
LABEL_265:
    if ( v14 == (int *)PsIdleProcess )
      v14 = 0;
    v137 = (int)v14;
    while ( 1 )
    {
      v149 = 0;
      v138 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v139 = 0;
      --*(_WORD *)(v138 + 0x136);
      v140 = KeAbPreAcquire((unsigned int)&PspActiveProcessLock, 0, 0);
      v196 = 0;
      v189 = 17;
      do
        v141 = __ldrex((unsigned int *)&PspActiveProcessLock);
      while ( !v141 && __strex(0x11u, (unsigned int *)&PspActiveProcessLock) );
      __dmb(0xBu);
      v189 = v141;
      if ( v141 )
        ExfAcquirePushLockSharedEx(&PspActiveProcessLock, v140, (unsigned int)&PspActiveProcessLock);
      if ( v140 )
        *(_BYTE *)(v140 + 14) |= 1u;
      if ( v137 )
        v142 = *(int **)(v137 + 180);
      else
        v142 = (int *)PsActiveProcessHead;
      while ( v142 != &PsActiveProcessHead )
      {
        v149 = v142 - 45;
        if ( ObReferenceObjectSafeWithTag((int)(v142 - 45)) )
        {
          v139 = 1;
          break;
        }
        v142 = (int *)*v142;
      }
      v197 = 17;
      v190 = 0;
      __dmb(0xBu);
      do
        v143 = __ldrex((unsigned int *)&PspActiveProcessLock);
      while ( v143 == 17 && __strex(0, (unsigned int *)&PspActiveProcessLock) );
      v190 = v143;
      if ( v143 != 17 )
        ExfReleasePushLockShared(&PspActiveProcessLock);
      KeAbPostRelease((unsigned int)&PspActiveProcessLock);
      v144 = *(_WORD *)(v138 + 310) + 1;
      *(_WORD *)(v138 + 310) = v144;
      if ( !v144 && *(_DWORD *)(v138 + 100) != v138 + 100 )
        KiCheckForKernelApcDelivery(310);
      if ( v137 )
        ObfDereferenceObjectWithTag(v137);
      if ( v139 )
      {
        v14 = v149;
      }
      else
      {
        v14 = 0;
        v149 = 0;
      }
      v137 = (int)v14;
      if ( !v14 )
      {
        v14 = 0;
        v149 = 0;
        goto LABEL_301;
      }
      if ( (v14[48] & 0x4000000) != 0 )
      {
        if ( !v162 )
          goto LABEL_301;
        if ( ObOpenObjectByPointer((int)v14, 512, 0, 1024, PsProcessType, 1, &v192) >= 0 )
          break;
      }
    }
    ObCloseHandle(v192);
LABEL_301:
    v154 = v14;
    v7 = v147;
    v9 = v148;
  }
  if ( v9 >= 0 && v153 && (*(_DWORD *)v153 = 0, v13 < 0) )
  {
    v146 = v13;
  }
  else if ( v155 )
  {
    *v155 = v7;
  }
LABEL_308:
  if ( v154 && v154 != (int *)PsIdleProcess )
    ObfDereferenceObjectWithTag((int)v154);
  if ( v174 && *(_DWORD *)(v174 + 336) != PsIdleProcess )
    ObfDereferenceObjectWithTag(v174);
  if ( v170 )
    PspDereferenceSiloObject(v170);
  return v146;
}
