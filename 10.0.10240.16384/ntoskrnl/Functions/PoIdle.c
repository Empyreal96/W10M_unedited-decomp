// PoIdle 
 
int __fastcall PoIdle(int a1)
{
  int v1; // r9
  int result; // r0
  unsigned __int8 *v3; // r10
  int v4; // r8
  int v5; // r3
  int v6; // lr
  unsigned __int64 v7; // r4
  int v8; // r2
  int v9; // r6
  __int64 *v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int64 v13; // t1
  bool v14; // cc
  int v15; // r7
  unsigned int v16; // r2
  unsigned int v17; // kr04_4
  int v18; // r3
  unsigned __int64 v19; // r0
  int v20; // r3
  int v21; // r1
  int v22; // r6
  int v23; // r3
  BOOL v25; // r3
  int v26; // r5
  __int64 v27; // kr18_8
  unsigned int v28; // r7
  unsigned int v29; // r0
  unsigned int v30; // r1
  int v31; // r1
  unsigned int v32; // r6
  unsigned __int64 v33; // kr28_8
  unsigned int v34; // r3
  int v35; // r2
  int v36; // r1
  char v37; // r2
  int v38; // r6
  unsigned int v39; // r3
  int v40; // r4
  int v41; // r7
  int v42; // r0
  int v43; // r4
  unsigned int v44; // lr
  int v45; // r4
  int v46; // r6
  int v47; // r3
  unsigned int v48; // r0
  int v49; // r2
  int v50; // r1
  int v51; // r3
  unsigned __int64 v52; // r4
  unsigned int v53; // r7
  unsigned int v54; // r4
  unsigned int v55; // r7
  unsigned int v56; // kr38_4
  unsigned int v57; // r3
  unsigned int v58; // r5
  unsigned int v59; // r2
  __int16 v60; // r2
  char v61; // r3
  int v62; // r6
  int v63; // r5
  unsigned int v64; // r7
  int v65; // r1
  int v66; // r2
  int v67; // r4
  int v68; // r6
  int v69; // r7
  int v70; // r2
  int v71; // r1
  int v72; // r3
  unsigned int v73; // r2
  int v74; // r4
  int v75; // r10
  char v76; // r8
  unsigned int v77; // r3
  int v78; // r4
  int v79; // r1
  char v80; // r2
  int v81; // lr
  __int64 v82; // r0
  unsigned int v83; // r1
  int v84; // r3
  int v85; // r0
  int v86; // r4
  int v87; // r0
  int v88; // r0
  int v89; // r3
  unsigned int v90; // r6
  __int64 v91; // r0
  unsigned __int64 v92; // kr50_8
  int v93; // r3
  int v94; // r3
  int v95; // r2
  int v96; // r0
  unsigned int v97; // r5
  void **v98; // r1
  int v99; // t1
  int v100; // r3
  unsigned int v101; // r0
  unsigned int v102; // r4
  unsigned int v103; // r2
  int v104; // r3
  unsigned int v105; // r2
  unsigned int v106; // r1
  unsigned __int64 v107; // r2
  int v108; // r3
  int v109; // [sp+18h] [bp-B8h]
  unsigned int v110; // [sp+1Ch] [bp-B4h]
  int i; // [sp+20h] [bp-B0h] BYREF
  int v112; // [sp+24h] [bp-ACh]
  unsigned int v113; // [sp+28h] [bp-A8h]
  int v114; // [sp+2Ch] [bp-A4h]
  int v115; // [sp+30h] [bp-A0h]
  unsigned int v116; // [sp+34h] [bp-9Ch]
  unsigned int v117; // [sp+38h] [bp-98h]
  unsigned __int8 v118; // [sp+3Ch] [bp-94h] BYREF
  char v119[3]; // [sp+3Dh] [bp-93h] BYREF
  unsigned int v120; // [sp+40h] [bp-90h]
  unsigned int v121; // [sp+44h] [bp-8Ch] BYREF
  int v122; // [sp+48h] [bp-88h] BYREF
  unsigned int v123; // [sp+4Ch] [bp-84h]
  int v124; // [sp+50h] [bp-80h]
  int v125; // [sp+54h] [bp-7Ch]
  int v126; // [sp+58h] [bp-78h]
  unsigned int v127; // [sp+5Ch] [bp-74h]
  unsigned int v128; // [sp+60h] [bp-70h]
  unsigned __int8 *v129; // [sp+68h] [bp-68h]
  int v130; // [sp+6Ch] [bp-64h]
  int v131; // [sp+70h] [bp-60h]
  unsigned int v132; // [sp+74h] [bp-5Ch]
  unsigned int v133; // [sp+78h] [bp-58h]
  __int16 v134[2]; // [sp+80h] [bp-50h] BYREF
  int v135; // [sp+84h] [bp-4Ch]
  unsigned int v136; // [sp+88h] [bp-48h]
  unsigned __int64 v137; // [sp+90h] [bp-40h] BYREF
  int v138; // [sp+98h] [bp-38h]
  int v139; // [sp+9Ch] [bp-34h]
  int v140; // [sp+A0h] [bp-30h] BYREF
  int v141; // [sp+A4h] [bp-2Ch]
  int v142; // [sp+A8h] [bp-28h]
  int v143; // [sp+ACh] [bp-24h]

  v1 = a1;
  v122 = a1;
  result = 176;
  if ( BYTE1(PpmCurrentProfile[44 * dword_61EC0C + 31]) )
    return result;
  v127 = 0;
  v123 = 0;
  v3 = *(unsigned __int8 **)(v1 + 2944);
  v4 = v1 + 2944;
  v5 = *(_DWORD *)(v1 + 2948);
  v129 = v3;
  v131 = v5;
  if ( !v3 )
    return HalProcessorIdle();
  *((_DWORD *)v3 + 60) = 0;
  v6 = *(_DWORD *)v4;
  if ( *(_BYTE *)(*(_DWORD *)v4 + 5) )
  {
    v7 = *(_QWORD *)(v1 + 2952);
    v8 = *(_DWORD *)(v1 + 2948);
    *(_DWORD *)(v1 + 2952) = 0;
    *(_DWORD *)(v1 + 2956) = 0;
    v9 = v8 + 984 * *(_DWORD *)(v6 + 16) + 40;
    *(_QWORD *)(v1 + 2960) += v7;
    *(_QWORD *)v9 += v7;
    if ( *(_DWORD *)(v6 + 52) == 3 )
    {
      if ( *(int *)(v6 + 48) < 0 )
      {
        ++*(_DWORD *)(v9 + 12);
      }
      else
      {
        v10 = (__int64 *)&PpmIdleIntervalLimits;
        ++*(_DWORD *)(v9 + 16);
        v11 = 0;
        while ( 1 )
        {
          v13 = *v10;
          v10 += 3;
          v12 = v13;
          v14 = HIDWORD(v7) > HIDWORD(v13);
          if ( HIDWORD(v7) < HIDWORD(v13) || !v14 && (unsigned int)v7 < v12 )
            break;
          if ( (unsigned int)++v11 >= 0x1A )
            return sub_5416BC();
        }
        v15 = v9 + 32 * v11;
        v16 = *(_DWORD *)(v15 + 156);
        v17 = *(_DWORD *)(v15 + 152);
        v18 = *(_DWORD *)(v15 + 176);
        *(_DWORD *)(v15 + 152) = v17 + v7;
        HIDWORD(v19) = *(_DWORD *)(v15 + 164);
        *(_DWORD *)(v15 + 156) = (__PAIR64__(v16, v17) + v7) >> 32;
        LODWORD(v19) = *(_DWORD *)(v15 + 160);
        *(_DWORD *)(v15 + 176) = v18 + 1;
        if ( v7 < v19 )
          *(_QWORD *)(v15 + 160) = v7;
        if ( v7 > *(_QWORD *)(v15 + 168) )
          *(_QWORD *)(v15 + 168) = v7;
        if ( v7 < *(_QWORD *)(v9 + 24) )
          *(_QWORD *)(v9 + 24) = v7;
        if ( v7 > *(_QWORD *)(v9 + 32) )
          *(_QWORD *)(v9 + 32) = v7;
      }
    }
    else
    {
      ++*(_DWORD *)(v9 + 8);
    }
  }
  *(_DWORD *)(v6 + 48) = 0;
  *(_DWORD *)(v6 + 52) = 3;
  *(_BYTE *)(v6 + 5) = 0;
  v3[5] = 1;
  v134[0] = 1;
  v135 = 0;
  v136 = 0;
  v134[1] = 1;
  v20 = *v3;
  *((_WORD *)v3 + 18) = 0;
  if ( v20 )
  {
    if ( !PpmIdleVetoBias || (v89 = *((_DWORD *)v3 + 8), v89 != 3) && v89 != 4 )
    {
      PpmIdleSelectStates(v1, &v137, &v140, &v118, &v121, &v122, v119);
      v63 = v121;
      v68 = v122;
      v117 = v141;
      v69 = (unsigned __int8)v119[0];
      v109 = v118;
      v113 = v140;
      v125 = HIDWORD(v137);
      v126 = v137;
      goto LABEL_77;
    }
    return HalProcessorIdle();
  }
  v127 = 0;
  v123 = 0;
  v21 = PpmPlatformStates;
  v109 = 0;
  v22 = *(_DWORD *)(v1 + 2944);
  v121 = PpmDripsStateIndex;
  v23 = *(unsigned __int8 *)(v1 + 17);
  v124 = v22;
  v130 = PpmPlatformStates;
  v25 = 0;
  if ( v23 )
  {
    if ( PopDeepSleepIsEnabled && PopDeepSleepPhaseEngaged() && !PopPendingSetPowerDeviceIrps )
      v25 = 1;
  }
  if ( v25 && (v21 || *(_DWORD *)(v22 + 28) > 1u) )
  {
    v93 = 1;
LABEL_170:
    v109 = v93;
    goto LABEL_27;
  }
  while ( 1 )
  {
LABEL_27:
    v26 = *(_DWORD *)v4;
    v120 = 0;
    v116 = 0;
    while ( 1 )
    {
      v27 = MEMORY[0xFFFF9340];
      __dmb(0xBu);
      if ( (v27 & 1) == 0 )
      {
        v28 = MEMORY[0xFFFF9350];
        v128 = MEMORY[0xFFFF9354];
        v115 = MEMORY[0xFFFF9008];
        v114 = MEMORY[0xFFFF900C];
        KeQueryPerformanceCounter(&v140, 0);
        v30 = v140;
        v29 = v141;
        v125 = v141;
        v126 = v140;
        __dmb(0xBu);
        if ( MEMORY[0xFFFF9340] == v27 )
          break;
      }
      __dmb(0xAu);
      __yield();
    }
    v1 = v122;
    v3 = v129;
    if ( v29 < v128 || v29 <= v128 && v30 <= v28 )
    {
      v35 = v116;
      v34 = v120;
    }
    else
    {
      v32 = (__PAIR64__(v29, v30) - __PAIR64__(v128, v28) - 1) >> 32;
      v31 = v30 - v28 - 1;
      if ( MEMORY[0xFFFF9369] )
      {
        v32 = __PAIR64__(v32, v31) << MEMORY[0xFFFF9369] >> 32;
        v31 <<= MEMORY[0xFFFF9369];
      }
      v33 = MEMORY[0xFFFF9364] * (unsigned __int64)(unsigned int)v31;
      if ( v32 )
      {
        v35 = (v32 * (unsigned __int64)MEMORY[0xFFFF9364]
             + __PAIR64__(
                 MEMORY[0xFFFF9360] * (unsigned __int64)v32 + v33 < v33,
                 (MEMORY[0xFFFF9360] * (unsigned __int64)v32 + v33) >> 32)) >> 32;
        v34 = v32 * MEMORY[0xFFFF9364] + ((MEMORY[0xFFFF9360] * (unsigned __int64)v32 + v33) >> 32);
      }
      else
      {
        v34 = (((MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v31) >> 32) + v33) >> 32;
        v128 = (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v31) >> 32;
        v35 = 0;
      }
    }
    v113 = v34 + v115;
    v36 = v125;
    v117 = v35 + __CFADD__(v34, v115) + v114;
    *(_DWORD *)(v26 + 128) = v126;
    *(_DWORD *)(v26 + 132) = v36;
    *(_DWORD *)(v26 + 136) = *(_DWORD *)(v4 + 16);
    *(_DWORD *)(v26 + 140) = *(_DWORD *)(v4 + 20);
    *(_BYTE *)(v26 + 170) = *(_BYTE *)(v4 + 278);
    *(_BYTE *)(v26 + 168) = *(_BYTE *)(v4 + 48);
    v37 = *(_BYTE *)(v4 + 49);
    *(_BYTE *)(v26 + 171) = 1;
    *(_BYTE *)(v26 + 169) = v37;
    if ( !*(_DWORD *)(v1 + 3272) && !*(_BYTE *)(v1 + 17) )
    {
      *(_BYTE *)(v26 + 171) = 0;
      *(_WORD *)(v26 + 36) |= 0x40u;
    }
    if ( *(_BYTE *)(v1 + 17)
      && (v38 = 0,
          v39 = (unsigned int)KeGetPcr(),
          v40 = *(_DWORD *)((v39 & 0xFFFFF000) + 0xEB8),
          v41 = *(unsigned __int16 *)(v40 + 266),
          v42 = *(_DWORD *)(v40 + 128) & ~(1 << *(_BYTE *)((v39 & 0xFFFFF000) + 0x99D)),
          v43 = *(_DWORD *)(v40 + 260) & ~(1 << *(_DWORD *)((v39 & 0xFFFFF000) + 0x594)),
          v42 == v43) )
    {
      while ( 1 )
      {
        while ( v43 )
        {
          v83 = __clz(__rbit(v43));
          v43 &= ~(1 << v83);
          v84 = (int)*(&KiProcessorBlock + v83);
          v133 = v83;
          v85 = HIBYTE(*(_DWORD *)(v84 + 3000));
          if ( v85 == 8 || v85 == 6 || v85 == 7 )
            goto LABEL_42;
        }
        if ( ++v38 == (unsigned __int16)KeNumberNodes )
          break;
        v94 = (int)*(&KeNodeBlock
                   + *(unsigned __int16 *)(dword_6337E4 + 2 * (v38 + (unsigned __int16)KeNumberNodes * v41)));
        v43 = *(_DWORD *)(v94 + 260);
        if ( *(_DWORD *)(v94 + 128) != v43 )
          goto LABEL_42;
      }
      *(_BYTE *)(v26 + 172) = 1;
      *(_WORD *)(v26 + 36) |= 0x80u;
    }
    else
    {
LABEL_42:
      *(_BYTE *)(v26 + 172) = 0;
    }
    v44 = -1;
    if ( *(_BYTE *)(v26 + 1) )
    {
      *(_WORD *)(v26 + 36) |= 0x100u;
      *(_DWORD *)(v26 + 160) = *(_DWORD *)(v26 + 24);
    }
    else
    {
      *(_DWORD *)(v26 + 160) = -1;
    }
    v45 = v109;
    if ( v109 && !*(_BYTE *)(v124 + 172) )
    {
      *(_WORD *)(v124 + 36) = 0;
      v93 = 0;
      goto LABEL_170;
    }
    v46 = *(_DWORD *)(v1 + 2944);
    v47 = *(unsigned __int8 *)(v1 + 17);
    v114 = v46;
    if ( v47 || !KiSerializeTimerExpiration )
    {
      v120 = 0;
      v128 = 0;
    }
    else
    {
      v82 = PpmGetPlatformIdleDurationHint(1, &KeNumberNodes);
      v45 = v109;
      v128 = HIDWORD(v82);
      v120 = v82;
      v44 = -1;
    }
    v48 = -1;
    v49 = 0;
    v50 = *(unsigned __int8 *)(*(_DWORD *)(v1 + 2944) + 172);
    v51 = *(unsigned __int8 *)(v1 + 17);
    v110 = -1;
    v116 = -1;
    v112 = 0;
    if ( v51 )
    {
      v49 = 8;
      v112 = 8;
    }
    if ( v45 )
      v112 = v49 | 4;
    v115 = 2;
    i = 2;
    v52 = *(_QWORD *)&KiClockTimerNextTickTime;
    if ( *(_BYTE *)(v1 + 17) )
    {
      if ( !v50 || (_BYTE)KiDynamicTickDisableReason )
      {
        v53 = v113;
      }
      else
      {
        v53 = v113;
        if ( !KiClockState )
        {
          KiGetNextTimerExpirationDueTime(v1, 1, v113, v117, v109, &v137, &i);
          if ( __PAIR64__(v117, KiLastRequestedTimeIncrement) + v53 < v137 )
          {
            v48 = -1;
            v44 = v116;
            v52 = v137;
            v115 = i;
          }
          else
          {
            v44 = v116;
            v48 = -1;
            v115 = 2;
          }
        }
      }
    }
    else
    {
      v53 = v113;
      KiGetNextTimerExpirationDueTime(v1, 0, v113, v117, v109, &v137, &i);
      if ( v52 <= v137 )
        v52 = v137;
      v48 = -1;
      v44 = v116;
      v115 = i;
    }
    if ( ((unsigned int)v52 & HIDWORD(v52)) == -1 )
    {
      v55 = -1;
      v54 = -1;
    }
    else if ( v52 <= __PAIR64__(v117, v53) )
    {
      v55 = 0;
      v54 = 0;
    }
    else
    {
      v56 = v52 - v53;
      v54 = (v52 - __PAIR64__(v117, v53)) >> 32;
      v55 = v56;
    }
    v57 = *(_DWORD *)(v1 + 1784);
    v58 = 0;
    v59 = v57;
    for ( i = v54; v59; v58 += KeMaximumIncrement )
      v59 >>= 4;
    if ( v57 && !v109 )
    {
      if ( v57 == -1 )
        __brkdiv0();
      v48 = KeMaximumIncrement / (v57 + 1);
      v110 = v48;
      if ( !v48 )
      {
        v48 = 1;
        v110 = 1;
      }
      v44 = 0;
    }
    if ( v54 >= v44 && (v54 > v44 || v55 > v48) )
    {
      if ( v54 || v55 >= v58 )
      {
        v54 = 0;
        i = 0;
        v55 = v58;
      }
      v60 = v112 | 1;
      v112 |= 1u;
    }
    else
    {
      v48 = v55;
      v60 = v112;
      v110 = v55;
      i = v54;
      v44 = v54;
    }
    if ( PpmIdleCheckIdleDurationExpiration && *(_BYTE *)(v1 + 17) )
    {
      v95 = (unsigned __int16)KeNumberNodes;
      v96 = 0;
      v97 = 0;
      if ( !KeNumberNodes )
        goto LABEL_204;
      v98 = &KeNodeBlock;
      do
      {
        v99 = (int)*v98++;
        v100 = *(_DWORD *)(v99 + 132);
        v97 |= v100;
        if ( v100 )
          v96 = 1;
        --v95;
      }
      while ( v95 );
      if ( !v96 )
        goto LABEL_204;
      v101 = 0;
      v102 = 0;
      while ( v97 )
      {
        v103 = __clz(__rbit(v97));
        v97 &= ~(1 << v103);
        v132 = v103;
        if ( v103 >= KeNumberProcessors_0 )
          v104 = 0;
        else
          v104 = (int)*(&KiProcessorBlock + v103);
        v105 = *(_DWORD *)(v104 + 2976);
        v106 = *(_DWORD *)(v104 + 2980);
        if ( (v105 & v106) != -1 && __PAIR64__(v106, v105) > __PAIR64__(v102, v101) )
        {
          v101 = *(_DWORD *)(v104 + 2976);
          v102 = *(_DWORD *)(v104 + 2980);
        }
      }
      v3 = v129;
      if ( !(v101 | v102)
        || (HIDWORD(v107) = v117 + __CFADD__(v55, v113) + i, LODWORD(v107) = v55 + v113, v107 <= __PAIR64__(v102, v101)) )
      {
        v54 = i;
        v46 = v114;
LABEL_204:
        v60 = v112;
        v48 = v110;
        goto LABEL_65;
      }
      v60 = v112 | 0x2000;
      if ( v102 > v117 || v102 >= v117 && v101 > v113 )
        v55 = v101 - v113;
      else
        v55 = 1;
      v54 = 0;
      if ( v44 || (v48 = v110, v55 < v110) )
      {
        v48 = v55;
        v44 = 0;
      }
      v46 = v114;
    }
LABEL_65:
    if ( v44 <= v128 && (v44 < v128 || v48 < v120) )
    {
      v48 = v120;
      v44 = v128;
      v55 = v120;
      v54 = v128;
      v60 |= 0x1000u;
    }
    v61 = v115;
    *(_WORD *)(v46 + 36) |= v60;
    *(_DWORD *)(v46 + 152) = v55;
    *(_DWORD *)(v46 + 156) = v54;
    *(_BYTE *)(v46 + 173) = v61;
    *(_DWORD *)(v46 + 144) = v48;
    *(_DWORD *)(v46 + 148) = v44;
    v62 = v124;
    result = (*(int (__fastcall **)(int))(v124 + 80))(v124 + 120);
    v63 = *(_DWORD *)(v62 + 192);
    v64 = *(_DWORD *)(v62 + 188);
    if ( v63 == -2 || v63 == -1 )
      break;
    v65 = *(_DWORD *)(v62 + 184);
    v66 = *(_DWORD *)(v62 + 180);
    v67 = *(_DWORD *)(v1 + 2948);
    result = 0;
    if ( v66 )
    {
      v90 = v136;
      do
      {
        if ( *(unsigned __int8 *)(v65 + 4) == 255 )
        {
          if ( !result )
            result = 1;
          v90 |= 1 << *(_DWORD *)v65;
          v136 = v90;
        }
        v65 += 8;
        --v66;
      }
      while ( v66 );
      v62 = v124;
      if ( result )
      {
        if ( *(_BYTE *)(v124 + 172) )
        {
          v92 = *(_QWORD *)(v124 + 144);
          if ( __PAIR64__(v123, v127) < v92 )
          {
            v123 = HIDWORD(v92);
            v127 = v92;
          }
        }
      }
    }
    if ( !v109 )
      goto LABEL_72;
    if ( v130 )
    {
      if ( v64 != -1 && v64 >= v121 )
        goto LABEL_72;
    }
    else if ( v63 == *(_DWORD *)(v62 + 28) - 1 )
    {
      goto LABEL_72;
    }
    v109 = 0;
    (*(void (__fastcall **)(_DWORD, _DWORD))(v62 + 108))(*(_DWORD *)(v62 + 120), 0);
    ++*(_DWORD *)(v67 + 984 * v63 + 48);
    if ( v64 != -1 && v130 )
      ++*(_DWORD *)(*(_DWORD *)(v130 + 32) + 992 * v64 + 24);
    *(_WORD *)(v62 + 36) = 2;
  }
  v109 = 0;
LABEL_72:
  if ( v63 == -2 )
    return HalProcessorIdle();
  if ( v63 == -1 )
  {
    ++*(_DWORD *)(v131 + 12);
  }
  else
  {
    v68 = *((_DWORD *)v3 + 47);
    if ( v68 != -1 )
    {
      **((_DWORD **)v3 + 62) = v68;
      *((_DWORD *)v3 + 60) = 1;
    }
    v69 = v3[64 * v63 + 310] == 0;
LABEL_77:
    v70 = *((_DWORD *)v3 + 3);
    if ( v63 != v70 )
    {
      *((_DWORD *)v3 + 5) = v70;
      *((_DWORD *)v3 + 3) = v63;
      if ( (dword_682610 & 0x8000) != 0 )
      {
        v140 = v63;
        v141 = v70;
        v142 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x998);
        v143 = 0;
        LODWORD(v137) = &v140;
        HIDWORD(v137) = 0;
        v138 = 16;
        v139 = 0;
        EtwTraceKernelEvent(&v137, 1, -2147450880, 4661, 1538);
      }
    }
    v71 = v131;
    v72 = *(_DWORD *)(v131 + 4) + 1;
    *(_DWORD *)(v131 + 4) = v72;
    if ( !v72 )
      PpmResetProcessorIdleAccounting(v71, v71, v126, v125);
    v73 = v136;
    v74 = v3[64 * v63 + 309];
    v75 = *(_DWORD *)(v1 + 2944);
    if ( v136 )
    {
      *(_WORD *)(v75 + 36) |= 0x400u;
      if ( KiSerializeTimerExpiration )
      {
        HIDWORD(v91) = v123;
        if ( v127 | v123 )
        {
          LODWORD(v91) = v127;
          PpmSetPlatformIdleDurationHint(v91);
        }
      }
      v73 = v136;
    }
    v76 = KiClockTimerOwner;
    if ( !(_BYTE)KiDynamicTickDisableReason
      && !PpmIpiLastClockOwnerDisable
      && !*(_BYTE *)(v1 + 17)
      && *((_BYTE *)*(&KiProcessorBlock + KiClockTimerOwner) + 17)
      && !v74 )
    {
      v122 = 0;
      v77 = (unsigned int)KeGetPcr();
      v78 = *(_DWORD *)((v77 & 0xFFFFF000) + 0xEB8);
      v79 = 1 << *(_DWORD *)((v77 & 0xFFFFF000) + 0x594);
      v80 = *(_BYTE *)((v77 & 0xFFFFF000) + 0x99D);
      v121 = *(unsigned __int16 *)(v78 + 266);
      v81 = *(_DWORD *)(v78 + 260) & ~v79;
      if ( (*(_DWORD *)(v78 + 128) & ~(1 << v80)) != v81 )
        goto LABEL_99;
      v86 = v121;
      while ( 1 )
      {
        while ( v81 )
        {
          v132 = __clz(__rbit(v81));
          v81 &= ~(1 << v132);
          v87 = HIBYTE(*((_DWORD *)*(&KiProcessorBlock + v132) + 750));
          if ( v87 == 8 || v87 == 6 )
            goto LABEL_99;
          if ( v87 == 7 )
          {
            v73 = v136;
            goto LABEL_84;
          }
        }
        v88 = MmGetNextNode(v86, &v122);
        if ( v88 == -1 )
          break;
        v108 = (int)*(&KeNodeBlock + v88);
        v81 = *(_DWORD *)(v108 + 260);
        if ( *(_DWORD *)(v108 + 128) != v81 )
          goto LABEL_99;
      }
      v73 = v136;
      if ( ((v136 >> v76) & 1) == 0 )
      {
        v136 |= 1 << v76;
        *(_WORD *)(v75 + 36) |= 0x800u;
LABEL_99:
        v73 = v136;
      }
    }
LABEL_84:
    if ( v73 )
      HalRequestIpi(0, v134);
    result = PpmIdleExecuteTransition(v1, v63, v68, v109, v126, v125, v113, v117, v69);
  }
  return result;
}
