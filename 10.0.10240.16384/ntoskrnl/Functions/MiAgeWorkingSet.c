// MiAgeWorkingSet 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiAgeWorkingSet(int result, int a2, char a3, unsigned int a4)
{
  int v4; // r8
  unsigned int v5; // r1
  __int64 v6; // kr00_8
  unsigned int v7; // r5
  unsigned int v8; // r4
  int v9; // r7
  unsigned int v10; // r1
  unsigned int v11; // r5
  int v12; // r2
  unsigned int *i; // r6
  char *v14; // r10
  int v15; // r7
  unsigned int v16; // r1
  int *v17; // r2
  int v18; // t1
  unsigned int v19; // r9
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r7
  unsigned int *v23; // r4
  int v24; // r3
  unsigned int v25; // r7
  unsigned int v26; // r9
  int v27; // r7
  int v28; // r10
  int v29; // r3
  unsigned int v30; // r4
  unsigned int v31; // r3
  unsigned int v32; // r2
  unsigned int v33; // r3
  unsigned __int8 *v34; // r1
  int v35; // r8
  unsigned int v36; // r2
  int v37; // lr
  int v38; // r2
  int v39; // r1
  int v40; // r4
  unsigned int *v41; // r2
  unsigned int v42; // r4
  int v43; // r4
  _DWORD *v44; // r1
  unsigned int v45; // r2
  int v46; // r9
  int v47; // r7
  unsigned int v48; // r0
  unsigned int v49; // r8
  int v50; // r6
  int v51; // r1
  unsigned int v52; // r2
  unsigned int v53; // r4
  int v54; // r0
  unsigned int v55; // r1
  __int64 v56; // kr08_8
  int v57; // r2
  int v58; // r0
  int v59; // r1 OVERLAPPED
  unsigned int v60; // r9
  unsigned int v61; // r3
  unsigned int v62; // r9
  int v63; // r7
  char v64; // r1
  unsigned int v65; // r4
  unsigned int v66; // r2
  unsigned int v67; // r3
  unsigned int v68; // r2
  unsigned int *v69; // r2
  unsigned int v70; // r0
  int v71; // r0
  int v72; // r3
  unsigned int *v73; // r7
  unsigned int v74; // r1
  int v75; // r2
  unsigned int *v76; // r2
  unsigned int v77; // r0
  unsigned int v78; // r3
  int v79; // r3
  unsigned __int8 *v80; // r3
  unsigned int v81; // r1
  unsigned int v82; // r0
  unsigned int v83; // r2
  unsigned int v84; // r3
  int v85; // lr
  __int64 v86; // kr18_8
  unsigned int v87; // r7
  int v88; // r0
  int v89; // r8
  unsigned int v90; // r4
  int v91; // r1
  int v92; // r0
  unsigned int v93; // r2
  int v94; // r7
  __int64 v95; // kr20_8
  unsigned int v96; // r4
  int v97; // lr
  _DWORD *v98; // r2
  unsigned int v99; // r7
  int v100; // r0
  _DWORD *v101; // r4
  unsigned int v102; // r2
  int v103; // r7
  __int64 v104; // kr28_8
  unsigned int v105; // r0
  int v106; // lr
  int v107; // r8
  unsigned int v108; // r7
  int v109; // r0
  int v110; // r2
  unsigned int v111; // r1
  unsigned int v112; // r1
  int v113; // r3
  unsigned int v114; // r2
  unsigned int *v115; // r2
  unsigned int v116; // r0
  int v117; // [sp+8h] [bp-1A0h]
  int v118; // [sp+10h] [bp-198h]
  int v119; // [sp+18h] [bp-190h]
  unsigned int v120; // [sp+1Ch] [bp-18Ch]
  unsigned int v121; // [sp+20h] [bp-188h]
  int v123; // [sp+28h] [bp-180h]
  int v124; // [sp+2Ch] [bp-17Ch]
  int v125; // [sp+30h] [bp-178h]
  unsigned int v126; // [sp+34h] [bp-174h]
  unsigned int v127; // [sp+38h] [bp-170h]
  int v128; // [sp+3Ch] [bp-16Ch]
  unsigned int v129; // [sp+40h] [bp-168h]
  unsigned int v130; // [sp+48h] [bp-160h]
  int v131; // [sp+4Ch] [bp-15Ch]
  unsigned int v132; // [sp+54h] [bp-154h]
  unsigned int v133; // [sp+58h] [bp-150h]
  unsigned int v135[34]; // [sp+68h] [bp-140h] BYREF
  char v136[184]; // [sp+F0h] [bp-B8h] BYREF

  v4 = *(_DWORD *)(result + 92);
  v5 = *(_DWORD *)(result + 60);
  v6 = *(_QWORD *)(v4 + 4);
  v7 = a4;
  v117 = result;
  v133 = *(_DWORD *)(v4 + 8);
  v127 = v6;
  v125 = a4;
  v119 = v4;
  if ( v5 <= (unsigned int)v6 )
    return result;
  if ( !a4 )
  {
    v7 = 10;
    v125 = 10;
  }
  v8 = v5 - v6;
  if ( (a3 & 2) != 0 )
    return sub_543070(v7);
  v9 = *(_DWORD *)(v4 + 32);
  if ( !v7 )
    __brkdiv0();
  v10 = (v9 + v8) % v7;
  v11 = *(_DWORD *)(v4 + 20);
  *(_DWORD *)(v4 + 32) = v10;
  if ( v9 + v8 < v8 )
    v9 = 0;
  v121 = (v9 + v8) * v125 / 0x3E8;
  if ( v121 > v8 )
    v121 = v8 * v125 / 0x3E8;
  if ( v11 < (unsigned int)v6 || v11 > HIDWORD(v6) )
    v11 = v6;
  v12 = *(_DWORD *)(v4 + 36);
  for ( i = (unsigned int *)(*(_DWORD *)(v4 + 252) + v12 * v11);
        (*i & 1) == 0;
        i = (unsigned int *)(*(_DWORD *)(v4 + 252) + v12 * v11) )
  {
    if ( ++v11 > HIDWORD(v6) )
      v11 = v6;
  }
  v14 = 0;
  v15 = dword_6404B8;
  v130 = 0;
  v131 = dword_6404B8;
  v118 = 0;
  v120 = 0;
  v135[0] = 0;
  v126 = 0;
  v132 = 0;
  if ( (a3 & 3) != 0 )
  {
    v16 = dword_63FB80 + dword_63FC00;
    v17 = dword_63FD00;
    do
    {
      v18 = *v17;
      v17 += 5;
      v16 += v18;
    }
    while ( v17 < &dword_63FD64 );
    if ( v16 + dword_63FD64 < *(_DWORD *)(dword_6404B8 + 60) )
    {
      if ( *(_BYTE *)(result + 114) != 2 )
      {
        if ( v16 < *(_DWORD *)(dword_6404B8 + 56) )
          v126 = 3;
        else
          v126 = 5;
      }
      if ( result != PsInitialSystemProcess + 492 )
      {
        v132 = *(unsigned __int8 *)(dword_6404B8 + 1222);
        v130 = *(unsigned __int8 *)(dword_6404B8 + 1223);
      }
    }
    v19 = v121;
    if ( v121 > 0x100 )
    {
      v22 = 1019;
      if ( v121 < 0x3FB )
        v22 = v121;
      v14 = (char *)ExAllocatePoolWithTag(512, 4 * (v22 + 5), 1935109453);
      v118 = (int)v14;
      if ( v14 )
        goto LABEL_34;
      v15 = v131;
    }
    v20 = (unsigned int *)(v15 + 92);
    do
      v21 = __ldrex(v20);
    while ( !v21 && __strex(1u, v20) );
    __dmb(0xBu);
    if ( v21 )
    {
      v14 = v136;
      v22 = 33;
    }
    else
    {
      v14 = (char *)(v15 + 96);
      v22 = 256;
    }
    v118 = (int)v14;
LABEL_34:
    v23 = (unsigned int *)v117;
    if ( (*(_BYTE *)(v117 + 112) & 7) != 0 )
    {
      if ( (*(_BYTE *)(v117 + 112) & 7u) < 2 )
        v24 = 2;
      else
        v24 = 0;
    }
    else
    {
      v24 = 1;
    }
    *((_DWORD *)v14 + 3) = 0;
    *((_DWORD *)v14 + 4) = 0;
    v14[4] = 0;
    v14[5] = 0;
    *(_DWORD *)v14 = v24;
    *((_DWORD *)v14 + 2) = v22;
    *((_DWORD *)v14 + 5) = 0;
    goto LABEL_37;
  }
  v23 = (unsigned int *)result;
  v19 = v121;
LABEL_37:
  v124 = 0;
  v128 = 0;
  v123 = 0;
  v25 = 0;
  v129 = 0;
LABEL_38:
  if ( v25 < v19 )
  {
    v26 = ((*i >> 10) & 0x3FFFFC) - 0x40000000;
    v27 = *(_DWORD *)v26;
    v28 = MmPfnDatabase + 24 * (*(_DWORD *)v26 >> 12);
    v29 = *(_DWORD *)(v28 + 4);
    if ( (v29 & 0x80000000) == 0 && MiDemoteCombinedPte(((*i >> 10) & 0x3FFFFC) - 0x40000000, v29 | 0x80000000) == 1 )
      v27 = *(_DWORD *)v26;
    v30 = (*i >> 9) & 7;
    if ( (v27 & 0x10) == 0 )
    {
      if ( (*(_BYTE *)(v28 + 19) & 8) != 0 )
        v62 = 5;
      else
        v62 = *(_BYTE *)(v28 + 19) & 7;
      v63 = v117;
      if ( v30 < 6 && v62 < 5 )
      {
        MiUpdateWorkingSetAgeDistribution(v117, (*i >> 9) & 7, -1);
        v30 = 6;
        MiUpdateWorkingSetAgeDistribution(v117, 6, 1);
        MiSetWsleAge(v4, i, 6);
        ++v123;
      }
      v64 = a3;
      if ( (a3 & 1) != 0 && v30 < 6 )
      {
        if ( v30 )
          --*(_DWORD *)(v117 + 4 * (v30 - 1) + 20);
        v65 = v30 + 1;
        ++*(_DWORD *)(v117 + 4 * (v65 - 1) + 20);
        if ( *(_DWORD *)(v4 + 36) == 16 )
        {
          v85 = *(_DWORD *)(v4 + 252);
          if ( (unsigned int)(((int)i - v85) >> 4) >= *(_DWORD *)(v4 + 4) )
          {
            v86 = *(_QWORD *)i;
            v87 = i[2];
            v88 = 2 * ((*i >> 9) & 7);
            if ( *i < 0xC0000000 || (unsigned int)v86 > 0xC03FFFFF )
              ++v88;
            v89 = v4 + 8 * v88;
            if ( v87 == 0xFFFFF )
              *(_DWORD *)(v89 + 124) = HIDWORD(v86);
            else
              *(_DWORD *)(v85 + 16 * v87 + 4) = HIDWORD(v86);
            if ( HIDWORD(v86) == 0xFFFFF )
              *(_DWORD *)(v89 + 128) = v87;
            else
              *(_DWORD *)(v85 + 16 * HIDWORD(v86) + 8) = v87;
            v4 = v119;
            --*(_DWORD *)(v119 + 4 * v88 + 60);
          }
        }
        v66 = ((unsigned __int16)*i ^ (unsigned __int16)((_WORD)v65 << 9)) & 0xE00 ^ *i;
        *i = v66;
        if ( *(_DWORD *)(v4 + 36) == 16 )
        {
          v90 = ((int)i - *(_DWORD *)(v4 + 252)) >> 4;
          if ( v90 >= *(_DWORD *)(v4 + 4) )
          {
            v91 = 2 * ((v66 >> 9) & 7);
            if ( v66 < 0xC0000000 || v66 > 0xC03FFFFF )
              ++v91;
            v92 = v4 + 8 * v91;
            v93 = *(_DWORD *)(v92 + 128);
            i[1] = 0xFFFFF;
            i[2] = v93;
            if ( v93 == 0xFFFFF )
              *(_DWORD *)(v92 + 124) = v90;
            else
              *(_DWORD *)(*(_DWORD *)(v4 + 252) + 16 * v93 + 4) = v90;
            *(_DWORD *)(v92 + 128) = v90;
            ++*(_DWORD *)(v4 + 4 * v91 + 60);
          }
        }
        v64 = a3;
        v63 = v117;
        ++v123;
      }
      if ( (*(_DWORD *)(v28 + 20) & 0x8000000) != 0 )
        v67 = v130;
      else
        v67 = v132;
      v68 = v67;
      if ( !v67 )
        v68 = 7;
      if ( (v64 & 3) != 0 && (((*i >> 9) & 7) >= v68 || v62 < v126) )
      {
        v135[v120 + 1] = v11;
        ++v124;
        v120 = ++v135[0];
        if ( v135[0] == 32 )
        {
          MiFreeWsleList(v63, v135, 0);
          v120 = 0;
          v135[0] = 0;
        }
      }
      goto LABEL_84;
    }
    v31 = v30 - 1;
    if ( v30 - 1 <= 5 )
    {
      v30 = 0;
      --*(_DWORD *)(v117 + 4 * v31 + 20);
      if ( *(_DWORD *)(v4 + 36) == 16 )
      {
        v103 = *(_DWORD *)(v4 + 252);
        if ( (unsigned int)(((int)i - v103) >> 4) >= *(_DWORD *)(v4 + 4) )
        {
          v104 = *(_QWORD *)i;
          v105 = i[2];
          v106 = 2 * ((*i >> 9) & 7);
          if ( *i < 0xC0000000 || (unsigned int)v104 > 0xC03FFFFF )
            ++v106;
          v107 = v4 + 8 * v106;
          if ( v105 == 0xFFFFF )
            *(_DWORD *)(v107 + 124) = HIDWORD(v104);
          else
            *(_DWORD *)(v103 + 16 * v105 + 4) = HIDWORD(v104);
          if ( HIDWORD(v104) == 0xFFFFF )
            *(_DWORD *)(v107 + 128) = v105;
          else
            *(_DWORD *)(v103 + 16 * HIDWORD(v104) + 8) = v105;
          v4 = v119;
          --*(_DWORD *)(v119 + 4 * v106 + 60);
        }
      }
      v32 = *i & 0xFFFFF1FF;
      *i = v32;
      if ( *(_DWORD *)(v4 + 36) == 16 )
      {
        v108 = ((int)i - *(_DWORD *)(v4 + 252)) >> 4;
        if ( v108 >= *(_DWORD *)(v4 + 4) )
        {
          v109 = 0;
          if ( v32 < 0xC0000000 || v32 > 0xC03FFFFF )
            v109 = 1;
          v110 = v4 + 8 * v109;
          v111 = *(_DWORD *)(v110 + 128);
          i[1] = 0xFFFFF;
          i[2] = v111;
          if ( v111 == 0xFFFFF )
            *(_DWORD *)(v110 + 124) = v108;
          else
            *(_DWORD *)(*(_DWORD *)(v4 + 252) + 16 * v111 + 4) = v108;
          *(_DWORD *)(v110 + 128) = v108;
          ++*(_DWORD *)(v4 + 4 * v109 + 60);
        }
      }
    }
    if ( (a3 & 3) == 0 )
    {
LABEL_84:
      v25 = v129 + 1;
      v129 = v25;
      if ( (v25 & 0xF) != 0 || (v23 = (unsigned int *)v117, (*(_DWORD *)v117 & 0x40000000) == 0) )
      {
        if ( !KeShouldYieldProcessor() )
        {
          v60 = v133;
          v61 = v121;
          goto LABEL_87;
        }
LABEL_160:
        v23 = (unsigned int *)v117;
      }
      while ( 1 )
      {
        v14 = (char *)v118;
        if ( v118 )
          MiFlushTbList(v118);
        if ( v120 )
        {
          MiFreeWsleList((int)v23, v135, 0);
          v120 = 0;
          v135[0] = 0;
        }
        MiUnlockWorkingSetExclusive(v23, a2);
        a2 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v23);
        }
        else
        {
          v80 = (unsigned __int8 *)v23 + 3;
          do
            v81 = __ldrex(v80);
          while ( __strex(v81 | 0x80, v80) );
          __dmb(0xBu);
          if ( v81 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v23);
          while ( 1 )
          {
            v82 = *v23;
            if ( (*v23 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v82 & 0x40000000) == 0 )
            {
              do
                v112 = __ldrex(v23);
              while ( v112 == v82 && __strex(v82 | 0x40000000, v23) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v60 = *(_DWORD *)(v4 + 8);
        v83 = *(_DWORD *)(v4 + 4);
        v133 = v60;
        v127 = v83;
        if ( v11 < v83 )
          v11 = *(_DWORD *)(v4 + 4);
        if ( v11 > v60 )
          v11 = *(_DWORD *)(v4 + 4);
        v84 = v23[15];
        if ( v84 <= v83 )
          goto LABEL_145;
        v61 = (v84 - v83) * v125 / 0x3E8;
        v121 = v61;
LABEL_87:
        if ( v25 >= v61 )
        {
          v23 = (unsigned int *)v117;
          if ( *(_DWORD *)(v117 + 60) == v127 )
          {
            v14 = (char *)v118;
            v11 = v127 - 1;
            goto LABEL_145;
          }
        }
        while ( 1 )
        {
          if ( ++v11 > v60 )
            v11 = v127;
          if ( (v11 & 0xF) == 0 )
          {
            v23 = (unsigned int *)v117;
            if ( (*(_DWORD *)v117 & 0x40000000) != 0 )
              break;
          }
          if ( KeShouldYieldProcessor() )
            goto LABEL_160;
          i = (unsigned int *)(*(_DWORD *)(v4 + 252) + *(_DWORD *)(v4 + 36) * v11);
          if ( (*i & 1) != 0 )
          {
            v14 = (char *)v118;
            v23 = (unsigned int *)v117;
            v19 = v121;
            goto LABEL_38;
          }
        }
      }
    }
    if ( v30 != 7 )
    {
      v33 = (*(_BYTE *)(v28 + 19) & 8) != 0 ? 5 : *(_BYTE *)(v28 + 19) & 7;
      if ( v33 < 5 )
        MiLockSetPfnPriority(v28, 5);
    }
    v34 = (unsigned __int8 *)(v28 + 15);
    v35 = dword_634484;
    do
      v36 = __ldrex(v34);
    while ( __strex(v36 | 0x80, v34) );
    __dmb(0xBu);
    if ( v36 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v113 = *(_DWORD *)(v28 + 12);
          __dmb(0xBu);
        }
        while ( (v113 & 0x80000000) != 0 );
        do
          v114 = __ldrex(v34);
        while ( __strex(v114 | 0x80, v34) );
        __dmb(0xBu);
      }
      while ( v114 >> 7 );
    }
    if ( ((*(_DWORD *)(v28 + 12) & 0x3FFFFFFFu) <= 1 || (*(_DWORD *)(v28 + 20) & 0x8000000) != 0)
      && ((v37 = v117, (*(_BYTE *)(v117 + 112) & 7) == 0) || *(unsigned __int16 *)(v28 + 16) <= 1u) )
    {
      if ( v118 )
      {
        v38 = *(_DWORD *)v26;
        v39 = *(_DWORD *)v26;
        if ( v26 < 0xC0300000 || v26 > 0xC0300FFF )
          v39 = v38 & 0xFFFFFFEF;
        if ( v26 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v26 = v39;
        }
        else
        {
          v40 = 0;
          __dmb(0xBu);
          *(_DWORD *)v26 = v39;
          if ( (v38 & 2) == 0 && (v39 & 2) != 0 )
            v40 = 1;
          if ( v26 >= 0xC0300000 && v26 <= 0xC0300FFF )
          {
            v71 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            v72 = v26 & 0xFFF;
            v73 = (unsigned int *)(v71 + 4 * v72);
            if ( (v39 & 2) != 0 )
            {
              if ( (v39 & 0x400) != 0 )
              {
                MiArmWriteLargePageHardwarePde(v71, (unsigned int *)(v71 + 4 * v72), v39, v72);
                v37 = v117;
              }
              else
              {
                v74 = v39 & 0xFFFFF000 | 1;
                if ( (KeFeatureBits & 2) != 0 && v72 << 20 < (unsigned int)dword_63389C )
                  v74 |= 4u;
                v75 = 4;
                do
                {
                  __dmb(0xBu);
                  *v73++ = v74;
                  v74 = v74 & 0x3FF ^ ((v74 & 0xFFFFFC00) + 1024);
                  --v75;
                }
                while ( v75 );
              }
            }
            else
            {
              *v73 = 0;
              v73[1] = 0;
              v73[2] = 0;
              v73[3] = 0;
            }
          }
          if ( v40 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        __dmb(0xBu);
        v41 = (unsigned int *)(v28 + 12);
        do
          v42 = __ldrex(v41);
        while ( __strex(v42 & 0x7FFFFFFF, v41) );
        v43 = (*i >> 9) & 7;
        if ( v35 && v43 != 7 )
        {
          MiLogPageAccess(v37, v26);
          v37 = v117;
        }
        if ( !v43 )
        {
          v44 = *(_DWORD **)(v37 + 92);
          if ( v44[9] == 16 )
          {
            v94 = v44[63];
            if ( (unsigned int)(((int)i - v94) >> 4) >= v44[1] )
            {
              v95 = *(_QWORD *)i;
              v96 = i[2];
              v97 = 2 * ((*i >> 9) & 7);
              if ( *i < 0xC0000000 || (unsigned int)v95 > 0xC03FFFFF )
                ++v97;
              if ( v96 == 0xFFFFF )
                *(_DWORD *)(v95 + 124) = HIDWORD(v95);
              else
                *(_DWORD *)(v94 + 16 * v96 + 4) = HIDWORD(v95);
              v98 = &v44[v97];
              if ( HIDWORD(v95) == 0xFFFFF )
                v44[2 * v97 + 32] = v96;
              else
                *(_DWORD *)(v94 + 16 * HIDWORD(v95) + 8) = v96;
              v37 = v117;
              --v98[15];
            }
          }
          v45 = *i & 0xFFFFF1FF | 0x200;
          *i = v45;
          if ( v44[9] == 16 )
          {
            v99 = ((int)i - v44[63]) >> 4;
            if ( v99 >= v44[1] )
            {
              v100 = 2 * ((v45 >> 9) & 7);
              if ( v45 < 0xC0000000 || v45 > 0xC03FFFFF )
                ++v100;
              v101 = &v44[2 * v100];
              v102 = v101[32];
              i[1] = 0xFFFFF;
              i[2] = v102;
              if ( v102 == 0xFFFFF )
                v101[31] = v99;
              else
                *(_DWORD *)(v44[63] + 16 * v102 + 4) = v99;
              v101[32] = v99;
              ++v44[v100 + 15];
            }
          }
          ++*(_DWORD *)(v37 + 20);
        }
        v46 = v118;
        v47 = 1;
        v48 = *(_DWORD *)(v118 + 12);
        v49 = *i & 0xFFFFF000;
        if ( v48 )
        {
          v50 = v118 + 4 * v48;
          v51 = *(_DWORD *)(v50 + 16);
          if ( (v51 & 0x800) == 0 )
          {
            v52 = *(_DWORD *)(v50 + 16) & 0x7FF;
            v53 = v52 + 1;
            if ( (v51 & 0xFFFFF000) + ((v52 + 1) << 12) == v49 && v53 > v52 && v53 <= 0x7FF )
            {
              ++*(_DWORD *)(v118 + 16);
              *(_DWORD *)(v50 + 16) = v51 & 0xFFFFF800 | (v51 + 1) & 0x7FF;
              goto LABEL_80;
            }
          }
          if ( (v51 & 0x800) == 0 && (v51 & 0xFFFFF000) == v49 + 4096 )
          {
            v78 = *(_DWORD *)(v50 + 16) & 0x7FF;
            if ( v78 + 1 > v78 && v78 + 1 <= 0x7FF )
            {
              if ( (v51 & 0x800) != 0 )
                v79 = 0x400000;
              else
                v79 = 4096;
              ++*(_DWORD *)(v118 + 16);
              *(_DWORD *)(v50 + 16) = (v51 - v79) & 0xFFFFF800 | ((_WORD)v51 - (_WORD)v79 + 1) & 0x7FF;
              goto LABEL_80;
            }
          }
        }
        if ( v48 >= *(_DWORD *)(v118 + 8) )
        {
          *(_BYTE *)(v118 + 5) = 1;
        }
        else
        {
          while ( 1 )
          {
            v54 = (unsigned int)(v47 - 1) > 0x7FF ? 2048 : v47;
            v55 = ((_WORD)v54 - 1) & 0x7FF | v49 & 0xFFFFF000;
            v47 -= v54;
            v49 += v54 << 12;
            *(_DWORD *)(v118 + 4 * *(_DWORD *)(v118 + 12) + 20) = v55;
            v56 = *(_QWORD *)(v118 + 12);
            v57 = HIDWORD(v56) + v54;
            v58 = *(_DWORD *)(v118 + 8);
            v59 = v56 + 1;
            *(_QWORD *)(v118 + 12) = *(_QWORD *)&v59;
            if ( (_DWORD)v56 + 1 == v58 )
            {
              qsort(v118 + 20, v59, 4, MiTbFlushSort);
              MiCompressTbFlushList(v118);
              if ( *(_DWORD *)(v118 + 12) == *(_DWORD *)(v118 + 8) )
                break;
            }
            if ( !v47 )
              goto LABEL_80;
          }
          if ( v47 )
          {
            *(_BYTE *)(v118 + 5) = 1;
            *(_DWORD *)(v118 + 16) = *(_DWORD *)(v118 + 12);
          }
        }
        goto LABEL_80;
      }
      __dmb(0xBu);
      v115 = (unsigned int *)(v28 + 12);
      do
        v116 = __ldrex(v115);
      while ( __strex(v116 & 0x7FFFFFFF, v115) );
    }
    else
    {
      __dmb(0xBu);
      v69 = (unsigned int *)(v28 + 12);
      do
        v70 = __ldrex(v69);
      while ( __strex(v70 & 0x7FFFFFFF, v69) );
    }
    v46 = v118;
LABEL_80:
    ++v128;
    if ( (*(_DWORD *)(v46 + 12) >= *(_DWORD *)(v46 + 8)
       || *(_BYTE *)(v46 + 5)
       || *(_DWORD *)(v46 + 16) > (unsigned int)dword_63382C)
      && (unsigned int)dword_63382C >= 0x400
      && !*(_BYTE *)(v46 + 5) )
    {
      MiFlushTbList(v46);
    }
    v4 = v119;
    goto LABEL_84;
  }
LABEL_145:
  if ( v14 )
  {
    MiFlushTbList(v14);
    if ( v14 == (char *)(v131 + 96) )
    {
      __dmb(0xBu);
      v76 = (unsigned int *)(v131 + 92);
      do
        v77 = __ldrex(v76);
      while ( __strex(0, v76) );
    }
    else if ( v14 != v136 )
    {
      ExFreePoolWithTag(v14, 0);
    }
  }
  if ( v120 )
    MiFreeWsleList((int)v23, v135, 0);
  if ( (a3 & 2) != 0 )
    *(_DWORD *)(v4 + 24) = v11 + 1;
  else
    *(_DWORD *)(v4 + 20) = v11 + 1;
  return MiLogWsAging(v23, v25, v128, v123, v124);
}
