// EtwpWriteUserEvent 
 
int __fastcall EtwpWriteUserEvent(_DWORD *a1, int a2, int a3, int a4, char a5, int a6, char a7, int a8, _DWORD *a9, unsigned __int8 a10, __int64 a11, unsigned int a12, int a13, _DWORD *a14, int a15, unsigned __int8 a16, unsigned __int16 *a17, _DWORD *a18)
{
  char v18; // r4
  int v19; // r5
  unsigned int v20; // r2
  int v21; // r8
  unsigned int v22; // r9
  int v23; // r2
  int v24; // r1
  int v25; // r0
  unsigned int v26; // r2
  unsigned int v27; // r1
  unsigned int v28; // r5
  int v29; // lr
  _DWORD *v30; // r4
  int v31; // r1
  int v32; // r3
  unsigned int v33; // r10
  int v34; // r2
  int v35; // r1
  int v36; // r2
  int v38; // r2
  unsigned int v39; // r3
  int v40; // r2
  int v41; // r3
  int v42; // r2
  int v43; // r3
  int v44; // r0
  int v45; // r2
  char *v46; // r3
  char *v47; // r1
  int v48; // r2
  int v49; // r2
  int v50; // r2
  int v51; // r1
  int *v52; // r4
  unsigned int v53; // r3
  unsigned int v54; // r2
  unsigned int v55; // r0
  unsigned int v56; // r3
  unsigned int v57; // r1
  int v58; // r3
  int v59; // r3
  unsigned int v60; // r2
  int v61; // r9
  int v62; // r3
  int v63; // r0
  int v64; // r4
  _DWORD *v65; // r4
  int v66; // r2
  int v67; // r3
  unsigned int v68; // r8
  unsigned int *v69; // lr
  _DWORD *v70; // r10
  unsigned int v71; // r1
  unsigned int v72; // r2
  unsigned int v73; // r3
  unsigned int v74; // r1
  unsigned int v75; // r2
  unsigned int v76; // r3
  unsigned int v77; // r1
  unsigned int v78; // r2
  unsigned int v79; // r3
  unsigned int v80; // r1
  unsigned int v81; // r2
  unsigned int v82; // r3
  unsigned int v83; // r1
  unsigned int v84; // r2
  unsigned int v85; // r3
  unsigned int v86; // r1
  unsigned int v87; // r2
  unsigned int v88; // r3
  int v89; // r5
  char v90; // r2
  int v91; // r10
  int v92; // lr
  __int16 v93; // r2
  int v94; // r1
  int v95; // r2
  int v96; // r3
  int v97; // r4
  int v98; // r4
  __int16 v99; // r3
  int v100; // r5
  __int16 v101; // r2
  int v102; // r1
  int v103; // r2
  int v104; // r4
  __int16 v105; // r3
  unsigned __int8 v106; // r5
  _DWORD *v107; // r3
  int v108; // r3
  int v109; // r5
  int v110; // r5
  int v111; // lr
  unsigned __int16 *v112; // lr
  unsigned __int16 v113; // r5
  unsigned __int16 v114; // r4
  unsigned __int16 v115; // r2
  unsigned __int16 *v116; // r0
  unsigned __int16 *v117; // r5
  int v118; // lr
  unsigned __int16 v119; // r4
  unsigned __int16 v120; // r2
  unsigned int i; // r4
  int v122; // r2
  unsigned int v123; // r1
  __int64 *v124; // r5
  int v125; // r3
  int v126; // r0
  unsigned int v127; // r1
  int v128; // lr
  _DWORD *v129; // r4
  int v130; // r3
  int v131; // r1
  int v132; // r4
  unsigned int j; // r3
  _QWORD *v134; // r6
  unsigned int v135; // r4
  _DWORD *v136; // r5
  unsigned int v137; // r0
  unsigned int v138; // r1
  unsigned int *v139; // r2
  unsigned int v140; // r1
  unsigned int v141; // r1
  __int16 v142; // r3
  char v144[456]; // [sp+18h] [bp-748h] BYREF
  char v145; // [sp+1F8h] [bp-568h] BYREF
  unsigned int v146; // [sp+4F0h] [bp-270h]
  int v147; // [sp+4F4h] [bp-26Ch]
  unsigned __int8 v148; // [sp+508h] [bp-258h]
  int v149; // [sp+50Ch] [bp-254h]
  int v150; // [sp+510h] [bp-250h]
  int v151; // [sp+514h] [bp-24Ch]
  unsigned int v152; // [sp+518h] [bp-248h]
  unsigned __int16 *v153; // [sp+51Ch] [bp-244h]
  unsigned int v154; // [sp+520h] [bp-240h]
  char *v155; // [sp+524h] [bp-23Ch]
  int v156; // [sp+528h] [bp-238h]
  unsigned int v157; // [sp+52Ch] [bp-234h]
  unsigned __int16 v158; // [sp+530h] [bp-230h]
  unsigned int v159; // [sp+534h] [bp-22Ch] BYREF
  char *v160; // [sp+538h] [bp-228h] BYREF
  int v161; // [sp+53Ch] [bp-224h]
  unsigned int v162; // [sp+540h] [bp-220h]
  int v163; // [sp+544h] [bp-21Ch]
  int v164; // [sp+548h] [bp-218h]
  int v165; // [sp+54Ch] [bp-214h]
  unsigned int v166; // [sp+550h] [bp-210h]
  int v167; // [sp+558h] [bp-208h] BYREF
  int v168; // [sp+55Ch] [bp-204h]
  _BYTE *v169; // [sp+560h] [bp-200h]
  int v170; // [sp+564h] [bp-1FCh]
  int v171; // [sp+568h] [bp-1F8h]
  unsigned __int16 *v172; // [sp+56Ch] [bp-1F4h]
  int v173; // [sp+570h] [bp-1F0h]
  int v174; // [sp+574h] [bp-1ECh]
  int v175; // [sp+578h] [bp-1E8h]
  unsigned __int16 *v176; // [sp+57Ch] [bp-1E4h]
  _DWORD *v177; // [sp+580h] [bp-1E0h]
  char v178; // [sp+584h] [bp-1DCh]
  int v179; // [sp+588h] [bp-1D8h]
  unsigned int v180; // [sp+58Ch] [bp-1D4h]
  __int16 v181; // [sp+590h] [bp-1D0h]
  _BYTE *v182; // [sp+594h] [bp-1CCh]
  int v183; // [sp+598h] [bp-1C8h]
  _DWORD *v184; // [sp+59Ch] [bp-1C4h]
  char *v185; // [sp+5A0h] [bp-1C0h]
  unsigned __int16 *v186; // [sp+5A4h] [bp-1BCh]
  int v187; // [sp+5A8h] [bp-1B8h]
  _DWORD *v188; // [sp+5ACh] [bp-1B4h]
  __int64 v189; // [sp+5B0h] [bp-1B0h] BYREF
  int v190; // [sp+5B8h] [bp-1A8h]
  unsigned int v191; // [sp+5BCh] [bp-1A4h]
  int v192; // [sp+5C0h] [bp-1A0h]
  int *v193; // [sp+5C8h] [bp-198h]
  int v194; // [sp+5CCh] [bp-194h]
  int v195; // [sp+5D0h] [bp-190h]
  int v196; // [sp+5D4h] [bp-18Ch]
  _DWORD *v197; // [sp+5D8h] [bp-188h]
  _DWORD *v198; // [sp+5DCh] [bp-184h]
  char *v199; // [sp+5E0h] [bp-180h]
  unsigned __int16 *v200; // [sp+5E4h] [bp-17Ch]
  int v201; // [sp+5E8h] [bp-178h] BYREF
  _DWORD v202[2]; // [sp+5ECh] [bp-174h] BYREF
  int v203[2]; // [sp+5F4h] [bp-16Ch] BYREF
  _DWORD v204[4]; // [sp+5FCh] [bp-164h] BYREF
  _DWORD v205[3]; // [sp+60Ch] [bp-154h] BYREF
  unsigned int v206; // [sp+618h] [bp-148h] BYREF
  int v207; // [sp+61Ch] [bp-144h]
  int v208; // [sp+620h] [bp-140h]
  _QWORD v209[24]; // [sp+628h] [bp-138h] BYREF
  unsigned int v210; // [sp+6E8h] [bp-78h]
  _WORD _6F0[58]; // [sp+6F0h] [bp-70h] BYREF
  _DWORD *varg_r0; // [sp+768h] [bp+8h]
  int varg_r1; // [sp+76Ch] [bp+Ch]
  int varg_r2; // [sp+770h] [bp+10h]
  int varg_r3; // [sp+774h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v195 = a3;
  varg_r2 = a3;
  v18 = a2;
  v188 = a1;
  v202[1] = a1;
  v173 = a8;
  v204[3] = a8;
  v183 = a13;
  v203[1] = a13;
  v184 = a14;
  v205[1] = a14;
  v177 = (_DWORD *)a15;
  v186 = a17;
  v197 = a18;
  v204[1] = a18;
  v19 = 0;
  v149 = 0;
  v170 = 0;
  v20 = 0;
  v155 = 0;
  v160 = 0;
  v185 = 0;
  v199 = 0;
  v180 = 0;
  v181 = 0;
  v163 = 0;
  v167 = 0;
  v165 = 0;
  v168 = 0;
  if ( a13 )
  {
    if ( a12 )
      goto LABEL_6;
    return -1073741811;
  }
  if ( a12 )
    return -1073741811;
LABEL_6:
  if ( a12 > 0x80 )
    return -1073741811;
  if ( a15 )
  {
    v198 = (_DWORD *)a15;
  }
  else
  {
    v177 = a1;
    v198 = a1;
  }
  v166 = 0;
  _6F0[0] = 0;
  LOBYTE(v21) = 0;
  v156 = 0;
  v148 = 0;
  v22 = 0;
  v210 = 0;
  if ( a18 )
  {
    v23 = *a18;
    v24 = a18[1];
    if ( *(_QWORD *)a18 )
    {
      v163 = *a18;
      v167 = v23;
      v165 = v24;
      v168 = v24;
      LOBYTE(v21) = 16;
      v156 = 16;
      v148 = 16;
    }
    v20 = 0;
  }
  if ( v186 )
  {
    v20 = *v186;
    v180 = v20;
    v181 = v20;
  }
  if ( v20 )
  {
    v200 = v186;
  }
  else
  {
    v186 = 0;
    v200 = 0;
  }
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v175 = v25;
  v204[2] = v25;
  --*(_WORD *)(v25 + 308);
  v26 = (unsigned __int8)(~a5 & v18);
  v157 = v26;
  v187 = -2147483643;
  v192 = a16;
  v191 = a10;
  while ( 1 )
  {
    while ( 1 )
    {
      v27 = __clz(__rbit(v26));
      v179 = v27;
      if ( 1 == (unsigned __int8)(v27 >> 5) )
        goto LABEL_237;
      v174 = 1;
      v190 = 1;
      v206 = 0;
      v207 = 0;
      v208 = 0;
      v28 = 80;
      v152 = 80;
      v154 = 80;
      v153 = 0;
      v178 = 0;
      v29 = 0;
      v164 = 0;
      v158 = 0;
      v161 = 0;
      v171 = 0;
      v172 = 0;
      v176 = 0;
      v169 = 0;
      v182 = 0;
      v26 &= (unsigned __int8)(v26 - 1);
      v157 = (unsigned __int8)v26;
      LOBYTE(varg_r1) = v26;
      v25 = (int)v177;
      v30 = &v177[8 * v27];
      if ( !v184 || (v26 = v157, !(v184[1] & (1 << (*((_WORD *)v30 + 47) - 32)) | (1 << *((_WORD *)v30 + 47)) & *v184)) )
      {
        if ( v30[22] && (v191 <= *((unsigned __int8 *)v30 + 92) || !*((_BYTE *)v30 + 92)) )
        {
          if ( (v30[24] & 0x40) == 0 || a11 )
          {
            v25 = HIDWORD(a11);
            v26 = v157;
            if ( (a11 & *((_QWORD *)v30 + 13)) == 0 )
              goto LABEL_20;
            v31 = v30[29];
            v25 = HIDWORD(a11) & v31;
            v26 = v157;
            if ( ((unsigned int)a11 & v30[28]) != v30[28] )
              goto LABEL_20;
            v26 = v157;
            if ( v25 != v31 )
              goto LABEL_20;
            v25 = (int)v177;
          }
          v32 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v33 = v183;
          if ( (a7 & 2) == 0 && (*(_DWORD *)(v32 + 736) & 0x400) == 0 )
            break;
          if ( (v30[24] & 0x200) == 0 )
            break;
        }
      }
LABEL_20:
      v19 = v149;
    }
    v34 = *(_DWORD *)(v25 + 344);
    v35 = v179;
    if ( v34 )
    {
      v36 = *(_DWORD *)(v34 + 36 * v179);
      v28 = v152;
      if ( (v36 & 0x80000200) == -2147483136 || (v36 & 0x80000100) == -2147483392 )
      {
        v147 = v183;
        v146 = a12;
        v25 = EtwpApplyEventIdPayloadFilterOnUserEvent(v25, v179);
        v26 = v157;
        if ( v25 )
        {
          v35 = v179;
          v25 = (int)v177;
          v29 = v164;
          goto LABEL_44;
        }
        goto LABEL_20;
      }
    }
LABEL_44:
    v151 = 0;
    v150 = 0;
    if ( a9 )
    {
      v28 = 104;
      v152 = 104;
      v154 = 104;
      v151 = 8;
      v150 = 8;
    }
    v38 = v30[24];
    if ( (v38 & 0xFFFFFF9F) != 0 )
    {
      if ( (v38 & 1) != 0 )
      {
        if ( (v21 & 2) != 0 )
        {
          v39 = v166;
        }
        else
        {
          EtwpGetSidExtendedHeaderItem(_6F0);
          v21 = (unsigned __int8)v21 | 2;
          v156 = v21;
          v148 = v21;
          v39 = _6F0[0];
          v166 = _6F0[0];
          v35 = v179;
          v25 = (int)v177;
        }
        v40 = v151 | 2;
        v151 = v40;
        v150 = v40;
        v28 += v39;
        v152 = v28;
        v154 = v28;
      }
      else
      {
        v40 = v151;
      }
      v41 = v30[24];
      if ( (v41 & 2) != 0 )
      {
        v40 |= 1u;
        v151 = v40;
        v150 = v40;
        v28 += 16;
        v152 = v28;
        v154 = v28;
      }
      if ( (v41 & 0x80) != 0 )
      {
        v40 |= 0x20u;
        v151 = v40;
        v150 = v40;
        v28 += 16;
        v152 = v28;
        v154 = v28;
      }
      v33 = v183;
      if ( (v41 & 0x100) != 0 )
      {
        v151 = v40 | 0x40;
        v150 = v40 | 0x40;
        v28 += 16;
        v152 = v28;
        v154 = v28;
      }
      if ( (v41 & 4) != 0
        && ((v42 = *(_DWORD *)(v25 + 344)) == 0 || (*(_DWORD *)(v42 + 36 * v35) & 0x80001000) != -2147479552 ? (v43 = 0) : (v43 = 1),
            !v43 || EtwpApplyStackWalkFilterOnUserEvent(v173, v25, v35)) )
      {
        if ( (v21 & 1) != 0 )
        {
          v47 = v155;
        }
        else
        {
          v44 = RtlpInterlockedPopEntrySList(&EtwpStackLookAsideList);
          if ( v44 )
            v46 = (char *)(v44 + 4);
          else
            v46 = 0;
          v155 = v46;
          v160 = v46;
          if ( v46 )
          {
            EtwpGetStackExtendedHeaderItem(v175, 0, 256, (int)&v160, 0, 0);
            v47 = v160;
            v155 = v160;
            LOBYTE(v21) = (v21 ^ (8 * (v160 != 0))) & 8 ^ v21;
          }
          else
          {
            if ( RtlpGetStackLimits((int)v202, (int)v205, v45, 0) )
            {
              v48 = v202[0];
            }
            else
            {
              v48 = 0;
              v202[0] = 0;
              v205[0] = 0;
            }
            if ( (unsigned int)v205 - v48 <= 0x5E0 )
            {
              v47 = v155;
            }
            else
            {
              v160 = &v145;
              EtwpGetStackExtendedHeaderItem(v175, 0, 192, (int)&v160, 0, 0);
              v47 = v160;
              v155 = v160;
            }
          }
          v21 = (unsigned __int8)v21 | 1;
          v156 = v21;
          v148 = v21;
        }
        v49 = v151;
        if ( v47 )
        {
          v25 = 4;
          v49 = v151 | 4;
          v151 = v49;
          v150 = v49;
          v28 += *(unsigned __int16 *)v47;
          v152 = v28;
          v154 = v28;
LABEL_84:
          if ( (v30[24] & 8) != 0 )
          {
            if ( (v21 & 4) == 0 )
            {
              if ( RtlpGetStackLimits((int)&v201, (int)v204, v49, (unsigned __int8)v21) )
              {
                v50 = v201;
              }
              else
              {
                v50 = 0;
                v201 = 0;
                v204[0] = 0;
              }
              if ( (unsigned int)v204 - v50 > 0x1DA )
              {
                v185 = v144;
                v199 = v144;
                EtwpGetPsmKeyExtendedHeaderItem(v144);
              }
              v21 = (unsigned __int8)v21 | 4;
              v156 = v21;
              v148 = v21;
              v49 = v151;
            }
            v25 = (int)v185;
            if ( v185 )
            {
              v151 = v49 | 0x10;
              v150 = v49 | 0x10;
              v28 += *(unsigned __int16 *)v185;
              v152 = v28;
              v154 = v28;
            }
          }
          v29 = v164;
          goto LABEL_95;
        }
      }
      else
      {
        v49 = v151;
      }
      v25 = 4;
      goto LABEL_84;
    }
LABEL_95:
    v51 = *((unsigned __int16 *)v30 + 47);
    v162 = v51;
    v196 = v51;
    v52 = (int *)&v209[3 * v22];
    v193 = v52;
    if ( a12 )
      break;
LABEL_120:
    if ( v161 )
    {
      v28 += (v29 + 15) & 0xFFFFFFF8;
      v152 = v28;
      v154 = v28;
    }
    if ( v180 )
    {
      v28 += (v180 + 15) & 0xFFFFFFF8;
      v152 = v28;
      v154 = v28;
    }
    v52[5] = v28;
    v25 = ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v51], 1);
    v60 = v162;
    if ( v25 )
    {
      if ( v162 >= 0x40 )
        v61 = 1;
      else
        v61 = WmipLoggerContext[v162];
      v190 = v61;
      v174 = v61;
      v62 = 1;
    }
    else
    {
      v62 = (int)v153;
      v61 = v174;
    }
    if ( (v61 & 1) != 0 )
    {
      if ( v62 )
      {
        v25 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v162], 1);
        v60 = v162;
      }
      if ( v60 == 3 )
      {
        PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, v203);
        if ( *(_BYTE *)(v203[0] + 393) )
          v19 = -1073741058;
        else
          v19 = -1073741816;
        v149 = v19;
        v25 = PsDereferenceMonitorContextServerSilo(v203[0]);
        v22 = v210;
        goto LABEL_237;
      }
      v19 = v149;
LABEL_154:
      v22 = v210;
      v26 = v157;
    }
    else
    {
      if ( !PsEqualCurrentServerSilo(*(_DWORD *)(v61 + 652)) )
      {
        v25 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v162], 1);
        v19 = -1073741816;
        v149 = -1073741816;
        v22 = v210;
        goto LABEL_237;
      }
      v63 = EtwpReserveTraceBuffer((_DWORD *)v61, v28, &v206, &v189, 0);
      v150 = v63;
      v196 = v63;
      if ( !v63 )
      {
        if ( v28 <= 0xFFF8 )
        {
          if ( v28 <= *(_DWORD *)(v61 + 8) )
            v64 = -1073741801;
          else
            v64 = v187;
        }
        else
        {
          v64 = -1073741675;
        }
        if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_LOST_EVENT) )
          EtwpTraceLostEvent((unsigned int)(v188 + 3), (__int16 *)(v173 + 40), (unsigned __int16 *)(v61 + 92), v64);
        v19 = v149;
        if ( v149 >= 0 && (*(_DWORD *)(v61 + 12) & 0x8000000) == 0 )
        {
          v19 = v64;
          v149 = v64;
          v170 = v64;
        }
        v25 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v162], 1);
        if ( v64 == -1073741675 )
        {
          v19 = -1073741675;
          v149 = -1073741675;
          v22 = v210;
          goto LABEL_237;
        }
        goto LABEL_154;
      }
      *v52 = v61;
      v52[1] = v63;
      v65 = v52 + 2;
      v66 = v207;
      v67 = v208;
      *v65 = v206;
      v65[1] = v66;
      v65[2] = v67;
      v22 = ++v210;
      v68 = 80;
      v159 = 80;
      v153 = 0;
      v69 = (unsigned int *)v150;
      v70 = (_DWORD *)v173;
      v71 = *(_DWORD *)(v173 + 4);
      v72 = *(_DWORD *)(v173 + 8);
      v73 = *(_DWORD *)(v173 + 12);
      *(_DWORD *)v150 = *(_DWORD *)v173;
      v69[1] = v71;
      v69[2] = v72;
      v69[3] = v73;
      v74 = v70[5];
      v75 = v70[6];
      v76 = v70[7];
      v69[4] = v70[4];
      v69[5] = v74;
      v69[6] = v75;
      v69[7] = v76;
      v77 = v70[9];
      v78 = v70[10];
      v79 = v70[11];
      v69[8] = v70[8];
      v69[9] = v77;
      v69[10] = v78;
      v69[11] = v79;
      v80 = v70[13];
      v81 = v70[14];
      v82 = v70[15];
      v69[12] = v70[12];
      v69[13] = v80;
      v69[14] = v81;
      v69[15] = v82;
      v83 = v70[17];
      v84 = v70[18];
      v85 = v70[19];
      v69[16] = v70[16];
      v69[17] = v83;
      v69[18] = v84;
      v69[19] = v85;
      v86 = v188[4];
      v87 = v188[5];
      v88 = v188[6];
      v69[6] = v188[3];
      v69[7] = v86;
      v69[8] = v87;
      v69[9] = v88;
      v89 = (int)v69;
      *v69 = *(_DWORD *)(v174 + 4 * v195 + 20) | v152;
      v90 = v151;
      v91 = v183;
      v92 = (int)v153;
      if ( !v151 )
        goto LABEL_188;
      if ( (v151 & 8) != 0 )
      {
        v92 = v89 + 80;
        v153 = (unsigned __int16 *)(v89 + 80);
        *(_WORD *)(v89 + 80) = 24;
        *(_WORD *)(v89 + 82) = 1;
        *(_WORD *)(v89 + 86) = 16;
        v93 = *(_WORD *)(v89 + 84) & 0xFFFE;
        *(_WORD *)(v89 + 84) = v93;
        *(_WORD *)(v89 + 84) = v93 & 1;
        v94 = a9[1];
        v95 = a9[2];
        v96 = a9[3];
        *(_DWORD *)(v89 + 88) = *a9;
        *(_DWORD *)(v89 + 92) = v94;
        *(_DWORD *)(v89 + 96) = v95;
        *(_DWORD *)(v89 + 100) = v96;
        *(_WORD *)(v89 + 4) |= 1u;
        v68 = 104;
        v159 = 104;
        v90 = v151;
      }
      if ( (v90 & 2) != 0 )
      {
        v97 = v68 + v89;
        memmove(v68 + v89, (int)_6F0, v166);
        *(_WORD *)(v89 + 4) |= 1u;
        v68 += v166;
        v159 = v68;
        if ( v153 )
          v153[2] |= 1u;
        v92 = v97;
        v153 = (unsigned __int16 *)v97;
        v90 = v151;
      }
      if ( (v90 & 1) != 0 )
      {
        v98 = v68 + v89;
        *(_WORD *)(v68 + v89) = 16;
        *(_WORD *)(v98 + 2) = 3;
        *(_WORD *)(v98 + 6) = 4;
        v99 = *(_WORD *)(v68 + v89 + 4) & 0xFFFE;
        *(_WORD *)(v98 + 4) = v99;
        *(_WORD *)(v98 + 4) = v99 & 1;
        *(_DWORD *)(v98 + 8) = PsGetCurrentProcessSessionId();
        *(_WORD *)(v89 + 4) |= 1u;
        v68 += 16;
        v159 = v68;
        if ( v153 )
          v153[2] |= 1u;
        v92 = v98;
        v153 = (unsigned __int16 *)v98;
        v90 = v151;
      }
      if ( (v90 & 0x20) != 0 )
      {
        v100 = v89 + v68;
        *(_WORD *)v100 = 16;
        *(_WORD *)(v100 + 2) = 13;
        *(_WORD *)(v100 + 6) = 8;
        v101 = *(_WORD *)(v100 + 4) & 0xFFFE;
        *(_WORD *)(v100 + 4) = v101;
        *(_WORD *)(v100 + 4) = v101 & 1;
        v102 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v103 = *(_DWORD *)(v102 + 820) | (MEMORY[0xFFFF92C4] << 16);
        *(_DWORD *)(v100 + 8) = *(_DWORD *)(v102 + 816);
        *(_DWORD *)(v100 + 12) = v103;
        *(_WORD *)(v150 + 4) |= 1u;
        v68 += 16;
        v159 = v68;
        if ( v92 )
          *(_WORD *)(v92 + 4) |= 1u;
        v92 = v100;
        v153 = (unsigned __int16 *)v100;
        v89 = v150;
        v90 = v151;
      }
      if ( (v90 & 0x40) == 0 )
      {
        v104 = (int)v153;
        goto LABEL_180;
      }
      v104 = v68 + v89;
      *(_WORD *)(v68 + v89) = 16;
      *(_WORD *)(v104 + 2) = 10;
      *(_WORD *)(v104 + 6) = 8;
      v105 = *(_WORD *)(v68 + v89 + 4) & 0xFFFE;
      *(_WORD *)(v104 + 4) = v105;
      *(_WORD *)(v104 + 4) = v105 & 1;
      v106 = v156;
      if ( (v156 & 0x10) != 0 )
        goto LABEL_175;
      EtwpCreateEventKey(&v167);
      v156 = v106 | 0x10;
      v148 = v106 | 0x10;
      v107 = v197;
      v92 = (int)v153;
      if ( v197 )
      {
        v163 = v167;
        *v197 = v167;
        v165 = v168;
        v107[1] = v168;
        v90 = v151;
LABEL_175:
        v108 = v163;
        goto LABEL_176;
      }
      v165 = v168;
      v108 = v167;
      v163 = v167;
      v90 = v151;
LABEL_176:
      *(_DWORD *)(v104 + 8) = v108;
      *(_DWORD *)(v104 + 12) = v165;
      v89 = v150;
      *(_WORD *)(v150 + 4) |= 1u;
      v68 += 16;
      v159 = v68;
      if ( v92 )
        *(_WORD *)(v92 + 4) |= 1u;
      v153 = (unsigned __int16 *)v104;
LABEL_180:
      if ( (v90 & 4) != 0 )
      {
        v109 = v89 + v68;
        memmove(v109, (int)v155, *(unsigned __int16 *)v155);
        *(_WORD *)(v150 + 4) |= 1u;
        v68 += *(unsigned __int16 *)v155;
        v159 = v68;
        if ( v104 )
          *(_WORD *)(v104 + 4) |= 1u;
        v104 = v109;
        v153 = (unsigned __int16 *)v109;
        v89 = v150;
        v90 = v151;
      }
      if ( (v90 & 0x10) != 0 )
      {
        v110 = v89 + v68;
        memmove(v110, (int)v185, *(unsigned __int16 *)v185);
        v111 = v150;
        *(_WORD *)(v150 + 4) |= 1u;
        v68 += *(unsigned __int16 *)v185;
        v159 = v68;
        if ( v104 )
          *(_WORD *)(v104 + 4) |= 1u;
        v153 = (unsigned __int16 *)v110;
        goto LABEL_189;
      }
LABEL_188:
      v111 = v150;
LABEL_189:
      if ( v186 )
      {
        v112 = (unsigned __int16 *)(v111 + v68);
        v193 = (int *)v112;
        v113 = v180;
        v114 = (v180 + 15) & 0xFFF8;
        *v112 = v114;
        v112[1] = 12;
        v112[3] = v113;
        v115 = v112[2] & 0xFFFE;
        v112[2] = v115;
        v112[2] = v115 & 1;
        memmove((int)(v112 + 4), (int)v186, v180);
        memset((_BYTE *)v112 + v180 + 8, 0, (unsigned __int16)(v114 - v113 - 8));
        v111 = v150;
        *(_WORD *)(v150 + 4) |= 1u;
        v116 = (unsigned __int16 *)v193;
        v68 += *(unsigned __int16 *)v193;
        v159 = v68;
        if ( v153 )
          v153[2] |= 1u;
        v153 = v116;
      }
      if ( v161 )
      {
        v117 = (unsigned __int16 *)(v68 + v111);
        v118 = v164;
        v119 = (v164 + 15) & 0xFFF8;
        *v117 = v119;
        v117[1] = 11;
        v117[3] = v118;
        v120 = v117[2] & 0xFFFE;
        v117[2] = v120;
        v117[2] = v120 & 1;
        v172 = v117 + 4;
        v176 = v117 + 4;
        v169 = (char *)v117 + v118 + 8;
        v182 = v169;
        memset(v169, 0, (unsigned __int16)(v119 - v118 - 8));
        v111 = v150;
        *(_WORD *)(v150 + 4) |= 1u;
        v68 += *v117;
        v159 = v68;
        if ( v153 )
          v153[2] |= 1u;
      }
      for ( i = 0; i < a12; ++i )
      {
        v122 = v91 + 16 * i;
        v123 = *(_DWORD *)(v122 + 8);
        v124 = *(__int64 **)v122;
        v194 = *(_DWORD *)(v122 + 4);
        if ( v192 )
        {
          v125 = *(unsigned __int8 *)(v122 + 12);
          __dmb(0xBu);
          v149 = v170;
          v155 = v160;
          v165 = v168;
          v163 = v167;
          v166 = _6F0[0];
          v156 = v148;
          v22 = v210;
          v152 = v154;
          v161 = v171;
          v172 = v176;
          v169 = v182;
          v68 = v159;
        }
        else
        {
          v125 = 0;
        }
        if ( v125 )
        {
          if ( v125 == 1 )
          {
            v126 = (int)v172;
            if ( !v172 || (v193 = (int *)((char *)v172 + v123), (char *)v172 + v123 > v169) || !v161 )
            {
              v19 = -1073741820;
              v149 = -1073741820;
              v170 = -1073741820;
              *(_DWORD *)v111 = *(_DWORD *)(v174 + 24) | v152;
              *(_QWORD *)(v111 + 16) = v189;
              LOBYTE(v21) = v156;
              v25 = v175;
              goto LABEL_237;
            }
            if ( v123 && ((unsigned int)v124 + v123 > MmUserProbeAddress || (__int64 *)((char *)v124 + v123) < v124) )
              *(_BYTE *)MmUserProbeAddress = 0;
            memmove(v126, (int)v124, v123);
            v172 = (unsigned __int16 *)v193;
            v176 = (unsigned __int16 *)v193;
            v171 = --v161;
          }
          else if ( v125 == 3 && v123 == 8 )
          {
            if ( (unsigned int)(v124 + 1) > MmUserProbeAddress || v124 + 1 < v124 )
              *(_BYTE *)MmUserProbeAddress = 0;
            v189 = *v124;
          }
        }
        else
        {
          v193 = (int *)(v68 + v111);
          if ( RtlULongAdd(v68, v123, &v159) || (v68 = v159, v159 > v152) )
          {
            v19 = -1073741820;
            v149 = -1073741820;
            v170 = -1073741820;
            v128 = v150;
            *(_DWORD *)v150 = *(_DWORD *)(v174 + 24) | v152;
            *(_QWORD *)(v128 + 16) = v189;
            LOBYTE(v21) = v156;
            v25 = v175;
            goto LABEL_237;
          }
          if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A)
            && v127
            && ((unsigned int)v124 + v127 > MmUserProbeAddress || (__int64 *)((char *)v124 + v127) < v124) )
          {
            *(_BYTE *)MmUserProbeAddress = 0;
          }
          memmove((int)v193, (int)v124, v127);
        }
        v111 = v150;
      }
      v129 = v184;
      if ( v184 )
      {
        v130 = v184[1] | (1 << (v162 - 32));
        *v184 |= 1 << v162;
        v129[1] = v130;
      }
      v131 = HIDWORD(v189);
      LOBYTE(v21) = v156;
      v19 = v149;
      v25 = v175;
      v132 = v174;
      *(_DWORD *)(v111 + 16) = v189;
      *(_DWORD *)(v111 + 20) = v131;
      *(_DWORD *)(v111 + 56) = *(_DWORD *)(v25 + 404);
      *(_DWORD *)(v111 + 60) = *(_DWORD *)(v25 + 448);
      *(_DWORD *)(v111 + 8) = *(_DWORD *)(v25 + 880);
      *(_DWORD *)(v111 + 12) = *(_DWORD *)(v25 + 876);
      if ( !KdDebuggerNotPresent && !KdPitchDebugger || (v26 = v157, KdEventLoggingPresent) )
      {
        v26 = v157;
        if ( (*(_DWORD *)(v132 + 12) & 0x80000) != 0 )
        {
          v25 = EtwpSendTraceEvent(v132, (int)&v206);
          v26 = v157;
        }
      }
    }
  }
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) && 16 * a12 )
  {
    if ( (v33 & 7) != 0 )
      ExRaiseDatatypeMisalignment(v25);
    v53 = 16 * a12 + v33;
    if ( v53 > MmUserProbeAddress || v53 < v33 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v54 = 0;
  while ( 2 )
  {
    if ( v54 >= a12 )
    {
      v51 = v162;
      goto LABEL_120;
    }
    v55 = v28;
    v56 = v33 + 16 * v54;
    v57 = *(_DWORD *)(v56 + 8);
    v169 = (_BYTE *)v57;
    __dmb(0xBu);
    if ( v57 > 0xFFFF )
    {
      v149 = v187;
      v170 = v187;
      v155 = v160;
      v25 = v168;
      v165 = v168;
      v163 = v167;
      v166 = _6F0[0];
      LOBYTE(v21) = v148;
      v156 = v148;
      v22 = v210;
      v152 = v154;
      v164 = v158;
      v161 = v171;
      v172 = v176;
      v169 = v182;
      goto LABEL_236;
    }
    if ( v192 )
    {
      v58 = *(unsigned __int8 *)(v56 + 12);
      __dmb(0xBu);
      v57 = (unsigned int)v169;
    }
    else
    {
      v58 = 0;
    }
    if ( v58 )
    {
      if ( v58 == 1 )
      {
        v29 = (unsigned __int16)(v158 + v57);
        v158 += v57;
        v59 = ++v171;
        v28 = v154;
        goto LABEL_116;
      }
      v28 = v154;
    }
    else
    {
      v28 = v57 + v154;
      v154 += v57;
    }
    v59 = v171;
    v29 = v158;
LABEL_116:
    v152 = v28;
    v164 = v29;
    v161 = v59;
    if ( v28 >= v55 )
    {
      ++v54;
      v149 = v170;
      v155 = v160;
      v165 = v168;
      v163 = v167;
      v166 = _6F0[0];
      LOBYTE(v21) = v148;
      v156 = v148;
      v172 = v176;
      v169 = v182;
      continue;
    }
    break;
  }
  v149 = v187;
  v170 = v187;
  v155 = v160;
  v25 = v168;
  v165 = v168;
  v163 = v167;
  v166 = _6F0[0];
  LOBYTE(v21) = v148;
  v156 = v148;
  v22 = v210;
  v172 = v176;
  v169 = v182;
LABEL_236:
  v19 = v149;
LABEL_237:
  if ( (v21 & 8) != 0 )
    v25 = RtlpInterlockedPushEntrySList(&EtwpStackLookAsideList, (_DWORD *)v155 - 1);
  if ( v19 < 0 )
  {
    v25 = EtwpFailLogging(v191, (int)v209, a11, HIDWORD(a11), (int)v188, (int)v209, v157, v19, v173 + 40, 1);
  }
  else
  {
    for ( j = 0; ; j = v179 + 1 )
    {
      v179 = j;
      if ( j >= v22 )
        break;
      v134 = &v209[3 * j];
      v135 = *((_DWORD *)v134 + 2);
      v136 = (_DWORD *)*((_DWORD *)v134 + 3);
      __pld(v136);
      v137 = *v136;
      if ( (*v136 ^ v135) >= 7 )
      {
LABEL_248:
        __dmb(0xBu);
        v139 = (unsigned int *)(v135 + 12);
        do
          v140 = __ldrex(v139);
        while ( __strex(v140 - 1, v139) );
        __dmb(0xBu);
      }
      else
      {
        while ( 1 )
        {
          __dmb(0xBu);
          do
            v138 = __ldrex(v136);
          while ( v138 == v137 && __strex(v137 + 1, v136) );
          if ( v138 == v137 )
            break;
          v137 = v138;
          if ( (v138 ^ v135) >= 7 )
            goto LABEL_248;
        }
      }
      v25 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[**(_DWORD **)v134], 1);
    }
    v19 = v149;
  }
  v141 = v175;
  v142 = *(_WORD *)(v175 + 308) + 1;
  *(_WORD *)(v175 + 308) = v142;
  if ( !v142 && *(_DWORD *)(v141 + 100) != v141 + 100 && !*(_WORD *)(v141 + 310) )
    KiCheckForKernelApcDelivery(v25);
  return v19;
}
