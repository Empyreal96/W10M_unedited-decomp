// EtwpEventWriteFull 
 
int __fastcall EtwpEventWriteFull(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned __int16 *a6, unsigned __int16 a7, unsigned __int16 a8, _DWORD *a9, _DWORD *a10, unsigned int a11, int a12, int a13, _DWORD *a14, int a15, unsigned __int8 a16, unsigned __int16 *a17, _DWORD *a18)
{
  char v18; // r4
  char v19; // r5
  int v20; // r2
  int v21; // lr
  int v22; // r4
  unsigned int v23; // r10
  int v24; // r2
  int v25; // r1
  unsigned int v26; // r2
  unsigned __int64 v27; // r0
  int v28; // r2
  unsigned int v29; // r3
  unsigned int v30; // r2
  unsigned int v31; // r9
  int v32; // lr
  unsigned __int8 v33; // r2
  unsigned int v34; // r4
  int v35; // r3
  int v36; // r5
  int v37; // r2
  int v38; // r2
  int v40; // r3
  int v41; // r5
  unsigned __int16 *v42; // r2
  unsigned int v43; // r3
  unsigned int v44; // r8
  int v45; // r5
  int v46; // r5
  int v47; // r3
  int v48; // r2
  int v50; // r9
  int v51; // r0
  int v52; // r1
  int v53; // r2
  _DWORD *v54; // r5
  int v55; // r8
  bool v56; // r3
  unsigned __int8 v57; // r3
  int *v58; // r4
  unsigned int v59; // r2
  int v60; // r1
  int v61; // r5
  int v62; // r3
  int v63; // r3
  bool v64; // zf
  int v65; // r8
  unsigned int v66; // r5
  int v67; // r10
  int v68; // r4
  _DWORD *v69; // r8
  unsigned __int16 *v70; // r9
  int v71; // r0
  int v72; // r8
  int v73; // r4
  _DWORD *v74; // r4
  int v75; // r2
  int v76; // r3
  int v77; // r1
  int v78; // r2
  int v79; // r3
  int v80; // r1
  int v81; // r2
  int v82; // r3
  _DWORD *v83; // r4
  int v84; // r1
  int v85; // r2
  int v86; // r3
  _DWORD *v87; // r0
  char v88; // lr
  int v89; // r1
  int v90; // r2
  int v91; // r3
  int v92; // r5
  int v93; // r4
  int v94; // r4
  int v95; // r0
  int v96; // r2
  int v97; // r4
  int v98; // r4
  _DWORD *v99; // r3
  int v100; // r1
  int v101; // r3
  int v102; // r4
  int v103; // r0
  int v104; // r5
  int v105; // lr
  int v106; // r1
  unsigned __int16 *v107; // r4
  unsigned int v108; // r0
  unsigned __int16 v109; // r2
  int v110; // r5
  int v111; // lr
  int v112; // r2
  int v113; // r1
  _WORD *v114; // r4
  __int16 v115; // r2
  unsigned int i; // r4
  int v117; // r2
  unsigned int v118; // r5
  _DWORD *v119; // r1
  int v120; // r3
  int v121; // r0
  unsigned int v122; // lr
  int v123; // r3
  unsigned int j; // r3
  _QWORD *v125; // r5
  unsigned int v126; // r6
  _DWORD *v127; // r4
  unsigned int *v128; // r2
  unsigned int v129; // r1
  int v130; // r1
  __int16 v131; // r3
  _DWORD *v132; // r0
  unsigned int v133; // r3
  int v134; // r4
  char v136[760]; // [sp+328h] [bp-510h] BYREF
  char v137; // [sp+638h] [bp-200h]
  char v138; // [sp+639h] [bp-1FFh]
  int v139; // [sp+63Ch] [bp-1FCh]
  unsigned int v140; // [sp+640h] [bp-1F8h]
  char v141; // [sp+644h] [bp-1F4h]
  int v142; // [sp+648h] [bp-1F0h]
  unsigned __int16 *v143; // [sp+64Ch] [bp-1ECh]
  unsigned __int16 *v144; // [sp+650h] [bp-1E8h]
  unsigned int v145; // [sp+654h] [bp-1E4h]
  int v146; // [sp+658h] [bp-1E0h]
  char *v147; // [sp+65Ch] [bp-1DCh]
  unsigned int v148; // [sp+660h] [bp-1D8h]
  int v149; // [sp+664h] [bp-1D4h]
  unsigned __int16 *v150; // [sp+668h] [bp-1D0h]
  unsigned __int16 *v151; // [sp+66Ch] [bp-1CCh]
  _DWORD *v152; // [sp+670h] [bp-1C8h]
  int v153; // [sp+674h] [bp-1C4h]
  unsigned int v154; // [sp+678h] [bp-1C0h]
  int v155; // [sp+67Ch] [bp-1BCh]
  __int16 v156; // [sp+680h] [bp-1B8h]
  unsigned int v157; // [sp+684h] [bp-1B4h]
  unsigned int v158; // [sp+688h] [bp-1B0h]
  int v159; // [sp+68Ch] [bp-1ACh]
  int v160; // [sp+690h] [bp-1A8h]
  int v161; // [sp+694h] [bp-1A4h]
  char *v162; // [sp+698h] [bp-1A0h] BYREF
  int v163; // [sp+69Ch] [bp-19Ch]
  int v164; // [sp+6A0h] [bp-198h]
  int v165; // [sp+6A4h] [bp-194h]
  int v166; // [sp+6A8h] [bp-190h]
  unsigned int v167; // [sp+6ACh] [bp-18Ch]
  int v168; // [sp+6B0h] [bp-188h] BYREF
  int v169; // [sp+6B4h] [bp-184h]
  int v170; // [sp+6B8h] [bp-180h]
  _DWORD *v171; // [sp+6BCh] [bp-17Ch]
  unsigned int v172; // [sp+6C0h] [bp-178h]
  int v173; // [sp+6C4h] [bp-174h]
  unsigned int v174; // [sp+6C8h] [bp-170h]
  unsigned __int16 *v175; // [sp+6CCh] [bp-16Ch]
  int v176; // [sp+6D0h] [bp-168h]
  _DWORD *v177; // [sp+6D4h] [bp-164h]
  int v178; // [sp+6D8h] [bp-160h]
  int v179; // [sp+6DCh] [bp-15Ch]
  int v180; // [sp+6E0h] [bp-158h]
  int v181; // [sp+6E4h] [bp-154h]
  int v182; // [sp+6E8h] [bp-150h]
  _DWORD *v183; // [sp+6ECh] [bp-14Ch]
  int v184; // [sp+6F0h] [bp-148h]
  int v185; // [sp+6F4h] [bp-144h]
  __int16 v186; // [sp+6F8h] [bp-140h]
  unsigned __int16 *v187; // [sp+6FCh] [bp-13Ch]
  _DWORD *v188; // [sp+700h] [bp-138h]
  int v189; // [sp+704h] [bp-134h]
  int v190; // [sp+708h] [bp-130h]
  int v191; // [sp+70Ch] [bp-12Ch]
  _DWORD v192[9]; // [sp+710h] [bp-128h] BYREF
  int v193; // [sp+734h] [bp-104h] BYREF
  _DWORD v194[2]; // [sp+738h] [bp-100h] BYREF
  _DWORD v195[4]; // [sp+740h] [bp-F8h] BYREF
  _QWORD v196[24]; // [sp+750h] [bp-E8h] BYREF
  unsigned int v197; // [sp+810h] [bp-28h]
  _DWORD *varg_r0; // [sp+840h] [bp+8h]
  int varg_r1; // [sp+844h] [bp+Ch]
  int varg_r2; // [sp+848h] [bp+10h]
  int varg_r3; // [sp+84Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v18 = a3;
  v19 = a2;
  v152 = a1;
  v192[6] = a1;
  v144 = a6;
  v192[7] = a6;
  v170 = a12;
  v192[5] = a12;
  v177 = a14;
  v192[2] = a14;
  v167 = a15;
  v20 = (int)a17;
  v175 = a17;
  v188 = a18;
  v192[4] = a18;
  v149 = 0;
  v189 = 0;
  v151 = 0;
  v187 = 0;
  v147 = 0;
  v162 = 0;
  v159 = 0;
  v168 = 0;
  v161 = 0;
  v169 = 0;
  v21 = 0;
  v164 = 0;
  v156 = 0;
  if ( a11 > 0x80 )
    return -1073741811;
  if ( a15 )
  {
    v183 = (_DWORD *)a15;
  }
  else
  {
    v167 = (unsigned int)a1;
    v183 = a1;
  }
  if ( a17 )
  {
    v21 = *a17;
    v164 = v21;
    v156 = v21;
  }
  if ( !v21 )
  {
    v20 = 0;
    v175 = 0;
  }
  v184 = v20;
  v146 = 0;
  v137 = 0;
  v23 = 0;
  v197 = 0;
  if ( a18 )
  {
    v24 = *a18;
    v25 = a18[1];
    if ( *(_QWORD *)a18 )
    {
      v159 = *a18;
      v168 = v24;
      v161 = v25;
      v169 = v25;
      v146 = 4;
      v137 = 4;
    }
  }
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v165 = v26;
  v192[3] = v26;
  v171 = (_DWORD *)a13;
  if ( !a13 )
    v171 = (_DWORD *)v26;
  v179 = 0;
  v138 = 0;
  LODWORD(v27) = KeAreInterruptsEnabled();
  if ( (_DWORD)v27 )
  {
    LODWORD(v27) = KeGetCurrentIrql();
    v29 = v27;
    v28 = v165;
  }
  else
  {
    v29 = 15;
  }
  v158 = v29;
  v141 = v29;
  if ( !v29 )
  {
    --*(_WORD *)(v28 + 308);
    v179 = 1;
    v138 = 1;
  }
  v30 = (unsigned __int8)(~v18 & v19);
  v140 = v30;
  v191 = -2147483643;
  v176 = a16;
  v190 = a8;
  v185 = a7;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          do
          {
            HIDWORD(v27) = __clz(__rbit(v30));
            v157 = HIDWORD(v27);
            if ( 1 == (unsigned __int8)(HIDWORD(v27) >> 5) )
            {
              v69 = v152;
              v22 = v149;
              v70 = v144;
              goto LABEL_232;
            }
            v155 = 1;
            v166 = 1;
            v31 = 80;
            v154 = 80;
            v148 = 80;
            v142 = 80;
            v145 = 80;
            v143 = 0;
            v150 = 0;
            v153 = 0;
            v32 = 0;
            v180 = 0;
            v186 = 0;
            v160 = 0;
            v178 = 0;
            v163 = 0;
            v173 = 0;
            v174 = 0;
            v182 = 0;
            v33 = v30 & (v30 - 1);
            v140 = v33;
            LOBYTE(varg_r1) = v33;
            v34 = v167 + 32 * HIDWORD(v27);
            LODWORD(v27) = v177;
            if ( !v177 )
              break;
            v30 = v140;
          }
          while ( v177[1] & (1 << (*(_WORD *)(v34 + 94) - 32)) | (1 << *(_WORD *)(v34 + 94)) & *v177 );
          HIDWORD(v27) = *((_DWORD *)v144 + 2);
          LODWORD(v27) = *((_DWORD *)v144 + 3);
          if ( *(_DWORD *)(v34 + 88) )
            break;
LABEL_21:
          v30 = v140;
        }
        if ( *((unsigned __int8 *)v144 + 4) > (unsigned int)*(unsigned __int8 *)(v34 + 92) )
        {
          v30 = v140;
          if ( *(_BYTE *)(v34 + 92) )
            continue;
        }
        if ( (*(_DWORD *)(v34 + 96) & 0x40) == 0 || v27 )
        {
          v30 = v140;
          if ( !(*(_DWORD *)(v34 + 108) & (unsigned int)v27 | *(_DWORD *)(v34 + 104) & HIDWORD(v27)) )
            continue;
          v30 = v140;
          if ( (*(_DWORD *)(v34 + 112) & HIDWORD(v27)) != *(_DWORD *)(v34 + 112) )
            continue;
          v30 = v140;
          if ( (*(_DWORD *)(v34 + 116) & (unsigned int)v27) != *(_DWORD *)(v34 + 116) )
            continue;
        }
        v35 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        if ( (a5 & 2) == 0 && (*(_DWORD *)(v35 + 736) & 0x400) == 0 )
          break;
        v30 = v140;
        if ( (*(_DWORD *)(v34 + 96) & 0x200) == 0 )
          break;
      }
      v36 = 0;
      v139 = 0;
      v27 = __PAIR64__(v157, v167);
      v37 = *(_DWORD *)(v167 + 344);
      if ( !v37 )
        break;
      v38 = *(_DWORD *)(v37 + 36 * v157);
      if ( (v38 & 0x80000200) != -2147483136 && (v38 & 0x80000100) != -2147483392 )
        break;
      LODWORD(v27) = EtwpApplyEventIdPayloadFilter(v167, v157, v144, v144, *v144, a11, v170, 0, v158);
      v30 = v140;
      if ( (_DWORD)v27 )
      {
        HIDWORD(v27) = v157;
        v32 = v180;
        break;
      }
    }
    if ( a10 )
    {
      v31 = 104;
      v154 = 104;
      v148 = 104;
      v36 = 8;
      v139 = 8;
    }
    if ( (*(_DWORD *)(v34 + 96) & 0xFFFFFF9F) == 0 )
      goto LABEL_108;
    if ( EtwpPagingDisabled )
      goto LABEL_53;
    LODWORD(v27) = 1;
    if ( (a5 & 1) != 0 )
      goto LABEL_54;
    if ( !MmCanThreadFault() || *(_BYTE *)(v165 + 974) )
    {
      HIDWORD(v27) = v157;
LABEL_53:
      LODWORD(v27) = 1;
LABEL_54:
      v40 = 0;
      goto LABEL_55;
    }
    v40 = 1;
    HIDWORD(v27) = v157;
    LODWORD(v27) = 1;
LABEL_55:
    v41 = v36 ^ (v36 ^ (v40 << 7)) & 0x80;
    v139 = v41;
    if ( (*(_DWORD *)(v34 + 96) & 1) != 0 && (v41 & 0x80) != 0 )
    {
      v42 = v151;
      if ( v151 )
        goto LABEL_65;
      v43 = (unsigned int)KeGetPcr();
      v44 = (v43 & 0xFFFFF000) + 1408;
      v45 = *(_DWORD *)((v43 & 0xFFFFF000) + 0xB40);
      ++*(_DWORD *)(v45 + 12);
      v42 = (unsigned __int16 *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v45);
      v151 = v42;
      if ( v42 )
        goto LABEL_61;
      ++*(_DWORD *)(v45 + 16);
      v46 = *(_DWORD *)(v44 + 1476);
      ++*(_DWORD *)(v46 + 12);
      v42 = (unsigned __int16 *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v46);
      v151 = v42;
      if ( v42
        || (++*(_DWORD *)(v46 + 16),
            v42 = (unsigned __int16 *)(*(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(v46 + 40))(
                                        *(_DWORD *)(v46 + 28),
                                        *(_DWORD *)(v46 + 36),
                                        *(_DWORD *)(v46 + 32)),
            (v151 = v42) != 0) )
      {
LABEL_61:
        *(_DWORD *)v42 = *(_DWORD *)(v44 + 20);
      }
      v187 = v42;
      if ( v42 )
      {
        EtwpGetSidExtendedHeaderItem(v42);
        v42 = v151;
      }
      LODWORD(v27) = 1;
      v41 = v139;
      HIDWORD(v27) = v157;
      if ( v42 )
      {
LABEL_65:
        v41 |= 2u;
        v139 = v41;
        v31 += *v42;
        v154 = v31;
        v148 = v31;
      }
    }
    v47 = *(_DWORD *)(v34 + 96);
    if ( (v47 & 2) != 0 )
    {
      v41 |= 1u;
      v139 = v41;
      v31 += 16;
      v154 = v31;
      v148 = v31;
    }
    if ( (v47 & 0x80) != 0 && (v41 & 0x80) != 0 )
    {
      v41 |= 0x20u;
      v139 = v41;
      v31 += 16;
      v154 = v31;
      v148 = v31;
    }
    if ( (v47 & 0x100) != 0 )
    {
      v41 |= 0x40u;
      v139 = v41;
      v31 += 16;
      v154 = v31;
      v148 = v31;
    }
    if ( (v47 & 4) == 0 || EtwpPagingDisabled )
    {
LABEL_107:
      v32 = v180;
      goto LABEL_108;
    }
    v48 = *(_DWORD *)(v167 + 344);
    if ( v48 && (*(_DWORD *)(v48 + 36 * HIDWORD(v27)) & 0x80001000) == -2147479552 )
    {
      LODWORD(v27) = EtwpApplyStackWalkFilter(*v144, v167, HIDWORD(v27), v158 < 2);
      if ( !(_DWORD)v27 )
        goto LABEL_107;
      LODWORD(v27) = 1;
    }
    if ( (v146 & 1) != 0 )
    {
      HIDWORD(v27) = v147;
    }
    else
    {
      v50 = 256;
      v51 = RtlpInterlockedPopEntrySList(&EtwpStackLookAsideList);
      if ( v51 )
        v52 = v51 + 4;
      else
        v52 = 0;
      v147 = (char *)v52;
      v162 = (char *)v52;
      if ( v52 )
        goto LABEL_94;
      LODWORD(v27) = RtlpGetStackLimits(&v193, v192);
      if ( (_DWORD)v27 )
      {
        v53 = v193;
      }
      else
      {
        v53 = 0;
        v193 = 0;
        v192[0] = 0;
      }
      if ( (unsigned int)v192 - v53 <= 0x5E0 )
      {
        HIDWORD(v27) = v147;
      }
      else
      {
        HIDWORD(v27) = v136;
        v147 = v136;
        v162 = v136;
        v50 = 192;
      }
      if ( HIDWORD(v27) )
      {
LABEL_94:
        v54 = 0;
        v55 = 1;
        if ( !memcmp((unsigned int)(v152 + 3), (unsigned int)EventTracingProvGuid, 16) && *v144 == 18 )
        {
          v139 |= 0x10u;
          v54 = v152 + 10;
          v55 = 0;
        }
        LODWORD(v27) = EtwpGetStackExtendedHeaderItem(v165, a5, v50, &v162, v55, v54);
        HIDWORD(v27) = v162;
        v147 = v162;
        v56 = v162 && v50 == 256;
        v57 = (v146 ^ (2 * v56)) & 2 ^ v146;
        v41 = v139;
      }
      else
      {
        v57 = v146;
      }
      v146 = v57 | 1;
      v137 = v57 | 1;
      v31 = v154;
    }
    v32 = v180;
    if ( HIDWORD(v27) )
    {
      v139 = v41 | 4;
      v31 += (unsigned __int16)*(_WORD *)HIDWORD(v27);
      v154 = v31;
      v148 = v31;
    }
LABEL_108:
    v172 = *(unsigned __int16 *)(v34 + 94);
    v192[1] = v172;
    v58 = (int *)&v196[3 * v23];
    v59 = 0;
    v60 = v170;
    v61 = v160;
    while ( v59 < a11 )
    {
      if ( v176 )
        v62 = *(unsigned __int8 *)(v60 + 12);
      else
        v62 = 0;
      if ( v62 )
      {
        if ( v62 == 1 )
        {
          v63 = *(_DWORD *)(v60 + 8) + v32;
          v32 = (unsigned __int16)v63;
          v186 = v63;
          v178 = ++v61;
        }
      }
      else
      {
        v31 += *(_DWORD *)(v60 + 8);
        v148 = v31;
      }
      ++v59;
      v60 += 16;
    }
    v160 = v61;
    v180 = v32;
    v154 = v31;
    v64 = v61 == 0;
    v65 = v153;
    v66 = v172;
    if ( !v64 )
    {
      v31 += (v32 + 15) & 0xFFFFFFF8;
      v154 = v31;
      v148 = v31;
    }
    if ( v164 )
    {
      v31 += (v164 + 15) & 0xFFFFFFF8;
      v154 = v31;
      v148 = v31;
    }
    v58[5] = v31;
    if ( v158 >= 2 )
    {
      if ( v66 >= 0x40 )
      {
        v67 = 1;
        v155 = 1;
        v166 = 1;
      }
      else
      {
        v67 = WmipLoggerContext[v66];
        v155 = v67;
        v166 = v67;
      }
    }
    else
    {
      LODWORD(v27) = ExAcquireRundownProtectionCacheAwareEx(EtwpLoggerRundown[v66], 1);
      if ( (_DWORD)v27 )
      {
        v67 = v66 >= 0x40 ? 1 : WmipLoggerContext[v66];
        v166 = v67;
        v155 = v67;
        v65 = 1;
        v153 = 1;
      }
      else
      {
        v67 = v155;
      }
    }
    if ( (v67 & 1) != 0 )
      break;
    v71 = EtwpReserveTraceBuffer(v67, v31, v195, v194, 0);
    v72 = v71;
    v192[8] = v71;
    if ( !v71 )
    {
      if ( v31 <= 0xFFF8 )
      {
        if ( v31 <= *(_DWORD *)(v67 + 8) )
          v73 = -1073741801;
        else
          v73 = v191;
      }
      else
      {
        v73 = -1073741675;
      }
      LODWORD(v27) = EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, ETW_EVENT_LOST_EVENT);
      v69 = v152;
      v70 = v144;
      if ( (_DWORD)v27 )
        LODWORD(v27) = EtwpTraceLostEvent(v152 + 3, v144, v67 + 92, v73);
      if ( v149 >= 0 && (*(_DWORD *)(v67 + 12) & 0x8000000) == 0 )
      {
        v149 = v73;
        v189 = v73;
      }
      if ( v153 )
        LODWORD(v27) = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v66], 1);
      if ( v73 == -1073741675 )
      {
        v22 = -1073741675;
        v149 = -1073741675;
        v23 = v197;
        v30 = v140;
        goto LABEL_232;
      }
      goto LABEL_154;
    }
    *v58 = v67;
    v58[1] = v71;
    v74 = v58 + 2;
    v75 = v195[1];
    v76 = v195[2];
    *v74 = v195[0];
    v74[1] = v75;
    v74[2] = v76;
    v23 = ++v197;
    *(_DWORD *)v71 = *(_DWORD *)(v155 + 20) | v31;
    *(_WORD *)(v71 + 4) = v185;
    *(_WORD *)(v71 + 6) = v190;
    v77 = v152[4];
    v78 = v152[5];
    v79 = v152[6];
    *(_DWORD *)(v71 + 24) = v152[3];
    *(_DWORD *)(v71 + 28) = v77;
    *(_DWORD *)(v71 + 32) = v78;
    *(_DWORD *)(v71 + 36) = v79;
    v80 = *((_DWORD *)v144 + 1);
    v81 = *((_DWORD *)v144 + 2);
    v82 = *((_DWORD *)v144 + 3);
    *(_DWORD *)(v71 + 40) = *(_DWORD *)v144;
    *(_DWORD *)(v71 + 44) = v80;
    *(_DWORD *)(v71 + 48) = v81;
    *(_DWORD *)(v71 + 52) = v82;
    v83 = (_DWORD *)(v71 + 64);
    if ( a9 )
    {
      v84 = a9[1];
      v85 = a9[2];
      v86 = a9[3];
      *v83 = *a9;
      *(_DWORD *)(v71 + 68) = v84;
      *(_DWORD *)(v71 + 72) = v85;
      *(_DWORD *)(v71 + 76) = v86;
    }
    else
    {
      *v83 = 0;
      *(_DWORD *)(v71 + 68) = 0;
      *(_DWORD *)(v71 + 72) = 0;
      *(_DWORD *)(v71 + 76) = 0;
    }
    *(_DWORD *)(v71 + 16) = v194[0];
    *(_DWORD *)(v71 + 20) = v194[1];
    v87 = v171;
    *(_DWORD *)(v72 + 8) = v171[220];
    *(_DWORD *)(v72 + 12) = v87[219];
    *(_DWORD *)(v72 + 56) = v87[101];
    *(_DWORD *)(v72 + 60) = v87[112];
    v88 = v139;
    if ( !v139 )
      goto LABEL_196;
    if ( (v139 & 8) != 0 )
    {
      v143 = (unsigned __int16 *)(v72 + 80);
      *(_WORD *)(v72 + 80) = 24;
      *(_WORD *)(v72 + 82) = 1;
      *(_WORD *)(v72 + 86) = 16;
      *(_WORD *)(v72 + 84) = 0;
      v89 = a10[1];
      v90 = a10[2];
      v91 = a10[3];
      *(_DWORD *)(v72 + 88) = *a10;
      *(_DWORD *)(v72 + 92) = v89;
      *(_DWORD *)(v72 + 96) = v90;
      *(_DWORD *)(v72 + 100) = v91;
      *(_WORD *)(v72 + 4) |= 1u;
      v92 = 104;
      v142 = 104;
      v145 = 104;
      v150 = v143;
    }
    else
    {
      v92 = v142;
    }
    if ( (v88 & 2) != 0 )
    {
      v93 = v92 + v72;
      memmove(v92 + v72, (int)v151, *v151);
      *(_WORD *)(v72 + 4) |= 1u;
      v92 += *v151;
      v142 = v92;
      v145 = v92;
      if ( v143 )
        v143[2] |= 1u;
      v143 = (unsigned __int16 *)v93;
      v150 = (unsigned __int16 *)v93;
      v88 = v139;
    }
    if ( (v88 & 1) != 0 )
    {
      v94 = v92 + v72;
      *(_WORD *)(v92 + v72) = 16;
      *(_WORD *)(v94 + 2) = 3;
      *(_WORD *)(v94 + 6) = 4;
      *(_WORD *)(v94 + 4) = 0;
      v95 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
      if ( v95 == -1 )
        v95 = 0;
      *(_DWORD *)(v94 + 8) = v95;
      *(_WORD *)(v72 + 4) |= 1u;
      v92 += 16;
      v142 = v92;
      v145 = v92;
      if ( v143 )
        v143[2] |= 1u;
      v96 = v94;
      v143 = (unsigned __int16 *)v94;
      v150 = (unsigned __int16 *)v94;
      v88 = v139;
    }
    else
    {
      v96 = (int)v143;
    }
    if ( (v88 & 0x20) != 0 )
    {
      v97 = v92 + v72;
      *(_WORD *)(v92 + v72) = 16;
      *(_WORD *)(v97 + 2) = 13;
      *(_WORD *)(v97 + 6) = 8;
      *(_WORD *)(v97 + 4) = 0;
      *(_QWORD *)(v97 + 8) = EtwpGetProcessStartKey(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
      *(_WORD *)(v72 + 4) |= 1u;
      v92 += 16;
      v142 = v92;
      v145 = v92;
      if ( v143 )
        v143[2] |= 1u;
      v96 = v97;
      v143 = (unsigned __int16 *)v97;
      v150 = (unsigned __int16 *)v97;
      v88 = v139;
    }
    if ( (v88 & 0x40) != 0 )
    {
      v98 = v92 + v72;
      *(_WORD *)(v92 + v72) = 16;
      *(_WORD *)(v98 + 2) = 10;
      *(_WORD *)(v98 + 6) = 8;
      *(_WORD *)(v98 + 4) = 0;
      if ( (v146 & 4) != 0 )
        goto LABEL_182;
      EtwpCreateEventKey(&v168);
      v146 = (unsigned __int8)v146 | 4;
      v137 = v146;
      v99 = v188;
      v88 = v139;
      if ( v188 )
      {
        v159 = v168;
        *v188 = v168;
        v161 = v169;
        v99[1] = v169;
        v96 = (int)v143;
LABEL_182:
        v100 = v161;
        v101 = v159;
      }
      else
      {
        v100 = v169;
        v161 = v169;
        v101 = v168;
        v159 = v168;
        v96 = (int)v143;
      }
      *(_DWORD *)(v98 + 8) = v101;
      *(_DWORD *)(v98 + 12) = v100;
      *(_WORD *)(v72 + 4) |= 1u;
      v92 += 16;
      v142 = v92;
      v145 = v92;
      if ( v96 )
        *(_WORD *)(v96 + 4) |= 1u;
      v143 = (unsigned __int16 *)v98;
      v150 = (unsigned __int16 *)v98;
    }
    if ( (v88 & 4) != 0 )
    {
      v102 = v92 + v72;
      memmove(v92 + v72, (int)v147, *(unsigned __int16 *)v147);
      if ( !*(_QWORD *)(v92 + v72 + 8) || (v139 & 0x10) != 0 )
        goto LABEL_193;
      v103 = ExAllocatePoolWithTag(512, 48, 1098347589);
      v104 = v103;
      if ( v103 )
      {
        KeInitializeApc(v103, v171);
        if ( KeInsertQueueApc(v104, *(_DWORD *)(v102 + 8), *(_DWORD *)(v102 + 12), 0) )
        {
LABEL_193:
          *(_WORD *)(v72 + 4) |= 1u;
          v105 = v142 + *(unsigned __int16 *)v147;
          v142 = v105;
          v145 = v105;
          if ( v143 )
            v143[2] |= 1u;
          v143 = (unsigned __int16 *)v102;
          v150 = (unsigned __int16 *)v102;
          goto LABEL_197;
        }
        ExFreePoolWithTag(v104, 0);
      }
      *(_DWORD *)(v102 + 8) = 0;
      *(_DWORD *)(v102 + 12) = 0;
      goto LABEL_193;
    }
LABEL_196:
    v105 = v142;
LABEL_197:
    v106 = (int)v175;
    if ( v175 )
    {
      v107 = (unsigned __int16 *)(v105 + v72);
      v153 = v105 + v72;
      v108 = v164;
      v109 = (v164 + 15) & 0xFFF8;
      *v107 = v109;
      v107[1] = 12;
      v107[3] = v108;
      v107[2] = 0;
      v110 = (unsigned __int16)(v109 - v108 - 8);
      LOWORD(v139) = v109 - v108 - 8;
      memmove(v105 + v72 + 8, v106, v108);
      memset((_BYTE *)(v164 + v105 + v72 + 8), 0, v110);
      v31 = v154;
      v111 = v142;
      v112 = (int)v143;
      v113 = v180;
      *(_WORD *)(v72 + 4) |= 1u;
      v105 = v111 + *v107;
      v142 = v105;
      v145 = v105;
      if ( v112 )
        *(_WORD *)(v112 + 4) |= 1u;
      v143 = v107;
    }
    else
    {
      v113 = v180;
    }
    if ( v160 )
    {
      v114 = (_WORD *)(v105 + v72);
      v115 = (v113 + 15) & 0xFFF8;
      *(_WORD *)(v105 + v72) = v115;
      v114[1] = 11;
      v114[3] = v113;
      v114[2] = 0;
      v163 = v105 + v72 + 8;
      v173 = v163;
      v174 = v163 + v113;
      v182 = v163 + v113;
      memset((_BYTE *)(v163 + v113), 0, (unsigned __int16)(v115 - v113 - 8));
      *(_WORD *)(v72 + 4) |= 1u;
      v105 = v142 + *(unsigned __int16 *)(v105 + v72);
      v142 = v105;
      v145 = v105;
      if ( v143 )
        v143[2] |= 1u;
    }
    for ( i = 0; ; ++i )
    {
      v150 = (unsigned __int16 *)i;
      if ( i >= a11 )
        break;
      v117 = v170 + 16 * i;
      v118 = *(_DWORD *)(v117 + 8);
      v153 = v118;
      v119 = *(_DWORD **)v117;
      v181 = *(_DWORD *)(v117 + 4);
      if ( v176 )
        v120 = *(unsigned __int8 *)(v117 + 12);
      else
        v120 = 0;
      if ( v120 )
      {
        if ( v120 == 1 )
        {
          if ( !v163 || v118 + v163 > v174 || !v160 )
            KeBugCheckEx(285, 5, v105);
          memmove(v163, (int)v119, v118);
          v163 += v118;
          v173 = v163;
          v178 = --v160;
        }
        else if ( v120 == 3 && v118 == 8 )
        {
          *(_DWORD *)(v72 + 16) = *v119;
          *(_DWORD *)(v72 + 20) = v119[1];
        }
      }
      else
      {
        v121 = v105 + v72;
        v180 = v105 + v72;
        v122 = v105 + v118;
        v142 = v122;
        v145 = v122;
        if ( v122 > v31 )
          KeBugCheckEx(285, 5, v122);
        memmove(v121, (int)v119, v118);
      }
      v105 = v142;
    }
    if ( (!KdDebuggerNotPresent && !KdPitchDebugger || KdEventLoggingPresent) && (*(_DWORD *)(v155 + 12) & 0x80000) != 0 )
      EtwpSendTraceEvent();
    LODWORD(v27) = v177;
    v30 = v140;
    if ( v177 )
    {
      v123 = v177[1] | (1 << (v172 - 32));
      *v177 |= 1 << v172;
      *(_DWORD *)(v27 + 4) = v123;
      goto LABEL_21;
    }
  }
  if ( v65 )
    LODWORD(v27) = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v66], 1);
  if ( v66 != 3 )
  {
LABEL_154:
    v23 = v197;
    goto LABEL_21;
  }
  PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, v192);
  v68 = *(unsigned __int8 *)(v192[0] + 393);
  LODWORD(v27) = PspDereferenceMonitorContextServerSilo(v192[0] - 48);
  v23 = v197;
  v30 = v140;
  v69 = v152;
  v70 = v144;
  if ( v68 )
  {
    v22 = -1073741058;
    v149 = -1073741058;
  }
  else
  {
    v22 = -1073741816;
    v149 = -1073741816;
  }
LABEL_232:
  if ( (v146 & 2) != 0 )
  {
    LODWORD(v27) = RtlpInterlockedPushEntrySList(&EtwpStackLookAsideList, (_DWORD *)v147 - 1);
    v30 = v140;
  }
  if ( v22 < 0 )
  {
    LODWORD(v27) = EtwpFailLogging(
                     *((unsigned __int8 *)v70 + 4),
                     HIDWORD(v27),
                     *((_DWORD *)v70 + 2),
                     *((_DWORD *)v70 + 3),
                     v69,
                     v196,
                     v30,
                     v22,
                     v70,
                     v158 < 2);
  }
  else
  {
    for ( j = 0; ; j = v157 + 1 )
    {
      v157 = j;
      if ( j >= v23 )
        break;
      v125 = &v196[3 * j];
      v126 = *((_DWORD *)v125 + 2);
      v127 = (_DWORD *)*((_DWORD *)v125 + 3);
      __pld(v127);
      HIDWORD(v27) = *v127;
      if ( (*v127 ^ v126) >= 7 )
      {
LABEL_243:
        __dmb(0xBu);
        v128 = (unsigned int *)(v126 + 12);
        do
          v129 = __ldrex(v128);
        while ( __strex(v129 - 1, v128) );
        __dmb(0xBu);
      }
      else
      {
        while ( 1 )
        {
          __dmb(0xBu);
          do
            LODWORD(v27) = __ldrex(v127);
          while ( (_DWORD)v27 == HIDWORD(v27) && __strex(HIDWORD(v27) + 1, v127) );
          if ( (_DWORD)v27 == HIDWORD(v27) )
            break;
          HIDWORD(v27) = v27;
          if ( ((unsigned int)v27 ^ v126) >= 7 )
            goto LABEL_243;
        }
      }
      if ( v158 < 2 )
        LODWORD(v27) = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[**(_DWORD **)v125], 1);
    }
    v22 = v149;
  }
  if ( v179 )
  {
    v130 = v165;
    v131 = *(_WORD *)(v165 + 308) + 1;
    *(_WORD *)(v165 + 308) = v131;
    if ( !v131 && *(_DWORD *)(v130 + 100) != v130 + 100 && !*(_WORD *)(v130 + 310) )
      KiCheckForKernelApcDelivery(v27);
  }
  v132 = v151;
  if ( v151 )
  {
    v133 = (unsigned int)KeGetPcr();
    v134 = *(_DWORD *)((v133 & 0xFFFFF000) + 0xB40);
    ++*(_DWORD *)(v134 + 20);
    if ( *(unsigned __int16 *)(v134 + 4) < (unsigned int)*(unsigned __int16 *)(v134 + 8)
      || (++*(_DWORD *)(v134 + 24),
          v134 = *(_DWORD *)((v133 & 0xFFFFF000) + 0xB44),
          ++*(_DWORD *)(v134 + 20),
          *(unsigned __int16 *)(v134 + 4) < (unsigned int)*(unsigned __int16 *)(v134 + 8)) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v134, v132);
    }
    else
    {
      ++*(_DWORD *)(v134 + 24);
      (*(void (**)(void))(v134 + 44))();
    }
    v22 = v149;
  }
  return v22;
}
