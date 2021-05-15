// SeAccessCheckByType 
 
int SeAccessCheckByType(int a1, int a2, int a3, ...)
{
  int v3; // r9
  int v5; // r5
  _DWORD *v6; // r6
  int v7; // r8
  int v8; // r0
  int *v9; // r2
  int *v10; // r2
  int *v11; // r2
  unsigned int v12; // r1
  int *v13; // r2
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r4
  int v19; // r10
  int v20; // r0
  int v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r2
  int v26; // r5
  int v27; // r0
  int *v28; // r0
  int v29; // r3
  int v30; // r10
  int *v31; // r0
  int *v32; // lr
  unsigned int v33; // r3
  unsigned int v34; // r2
  int v35; // r0
  int v36; // r2
  unsigned int v37; // r3
  int v38; // r3
  unsigned int v39; // r2
  int v40; // r1
  _DWORD *v41; // r3
  int v42; // r3
  int v43; // r0
  unsigned int v44; // r1
  int v45; // r5
  int v46; // r3
  int *v47; // r0
  int *v48; // r5
  unsigned int v49; // r2
  int v50; // r0
  unsigned int v51; // r1
  __int16 v52; // r3
  int v53; // r3
  int v54; // r3
  int v55; // r0
  int v56; // r0
  _DWORD *v57; // r1
  int v58; // r6
  int v59; // r1
  int v60; // r3
  int v61; // r1
  int v62; // r3
  int *v63; // r0
  unsigned int v64; // r2
  int *v65; // r4
  unsigned int v66; // lr
  int v67; // r0
  unsigned int v68; // r1
  __int16 v69; // r3
  int *v70; // r0
  int v71; // r1
  int v72; // r0
  unsigned int v73; // r1
  __int16 v74; // r3
  int *v75; // r10
  int v76; // r5
  int *v77; // r1
  int v78; // r3
  unsigned int v79; // r6
  int v80; // r0
  int v81; // r0
  unsigned int v82; // r1
  __int16 v83; // r3
  unsigned int *v84; // r3
  int v85; // r5
  unsigned int v86; // r2
  unsigned int v87; // r1
  int v88; // r0
  int v89; // r8
  int v90; // lr
  _DWORD *v91; // r3
  int v92; // lr
  int v93; // r5
  int v94; // r1
  int v95; // r0
  int v96; // r0
  int v97; // r1
  _DWORD *v98; // r3
  int v99; // lr
  int v100; // r5
  int v101; // r0
  int v102; // r3
  int v103; // r1
  int v104; // r1
  int v105; // r0
  int v106; // r1
  int *v107; // r5
  int v108; // r0
  unsigned int v109; // r1
  __int16 v110; // r3
  int v111; // r0
  unsigned int v112; // r1
  __int16 v113; // r3
  int v114; // r0
  unsigned int v115; // r1
  __int16 v116; // r3
  int v117; // r0
  unsigned int v118; // r1
  __int16 v119; // r3
  unsigned int v120; // r3
  int *v121; // r0
  unsigned int v122; // r2
  unsigned int v123; // r1
  int v124; // r3
  unsigned int v125; // r0
  int v126; // r2
  int *v127; // lr
  int v128; // r2
  int *v129; // r5
  char *v130; // r4
  int v131; // r3
  int v132; // lr
  unsigned int v133; // r0
  int *v134; // r5
  int *v135; // r2
  int v136; // r3
  int *v137; // r5
  int *v138; // r0
  int v139; // r3
  unsigned int v140; // r2
  int v141; // r1
  int v142; // r1
  int v143; // r0
  __int16 v144; // r2
  int v145; // r4
  int v147; // [sp+28h] [bp-178h]
  unsigned __int8 v148; // [sp+40h] [bp-160h] BYREF
  unsigned __int8 v149; // [sp+41h] [bp-15Fh]
  int *v150; // [sp+44h] [bp-15Ch]
  char v151; // [sp+48h] [bp-158h]
  char v152; // [sp+49h] [bp-157h]
  int v153; // [sp+4Ch] [bp-154h]
  int v154; // [sp+50h] [bp-150h]
  int v155; // [sp+54h] [bp-14Ch]
  int v156; // [sp+58h] [bp-148h]
  _DWORD *v157; // [sp+5Ch] [bp-144h]
  int v158; // [sp+60h] [bp-140h]
  int v159; // [sp+64h] [bp-13Ch] BYREF
  int v160; // [sp+68h] [bp-138h]
  int v161; // [sp+6Ch] [bp-134h] BYREF
  int v162; // [sp+70h] [bp-130h] BYREF
  int v163; // [sp+74h] [bp-12Ch] BYREF
  _DWORD *v164; // [sp+78h] [bp-128h] BYREF
  char v165; // [sp+7Ch] [bp-124h]
  int *v166; // [sp+80h] [bp-120h]
  _DWORD *v167; // [sp+84h] [bp-11Ch] BYREF
  int v168; // [sp+88h] [bp-118h]
  int v169; // [sp+8Ch] [bp-114h]
  int v170; // [sp+90h] [bp-110h]
  int v171; // [sp+94h] [bp-10Ch] BYREF
  unsigned int v172; // [sp+98h] [bp-108h]
  int v173; // [sp+9Ch] [bp-104h] BYREF
  char v174; // [sp+A0h] [bp-100h]
  int v175; // [sp+A4h] [bp-FCh]
  int v176; // [sp+A8h] [bp-F8h]
  unsigned int *v177; // [sp+ACh] [bp-F4h]
  int *v178; // [sp+B0h] [bp-F0h]
  int v179; // [sp+B4h] [bp-ECh]
  int v180; // [sp+B8h] [bp-E8h]
  char v181; // [sp+BCh] [bp-E4h]
  int v182; // [sp+C0h] [bp-E0h]
  unsigned int v183; // [sp+C4h] [bp-DCh] BYREF
  _BYTE *v184; // [sp+C8h] [bp-D8h]
  int *v185; // [sp+CCh] [bp-D4h]
  unsigned int v186; // [sp+D0h] [bp-D0h]
  int v187; // [sp+D4h] [bp-CCh]
  _DWORD *v188; // [sp+D8h] [bp-C8h]
  int v189; // [sp+DCh] [bp-C4h] BYREF
  int v190; // [sp+E0h] [bp-C0h]
  int *v191; // [sp+E4h] [bp-BCh]
  int v192; // [sp+E8h] [bp-B8h]
  unsigned int *v193; // [sp+ECh] [bp-B4h]
  int v194; // [sp+F0h] [bp-B0h]
  int *v195; // [sp+F4h] [bp-ACh] BYREF
  int v196; // [sp+F8h] [bp-A8h]
  unsigned int v197; // [sp+FCh] [bp-A4h] BYREF
  unsigned int v198; // [sp+100h] [bp-A0h]
  int v199; // [sp+104h] [bp-9Ch]
  int v200; // [sp+108h] [bp-98h]
  int v201; // [sp+10Ch] [bp-94h] BYREF
  unsigned int v202; // [sp+110h] [bp-90h]
  _DWORD v203[3]; // [sp+118h] [bp-88h] BYREF
  int v204; // [sp+124h] [bp-7Ch]
  int v205; // [sp+128h] [bp-78h]
  _BYTE v206[8]; // [sp+130h] [bp-70h] BYREF
  int v207; // [sp+138h] [bp-68h]
  _BYTE v208[8]; // [sp+140h] [bp-60h] BYREF
  _DWORD v209[3]; // [sp+148h] [bp-58h] BYREF
  unsigned int v210; // [sp+154h] [bp-4Ch]
  _DWORD v211[4]; // [sp+158h] [bp-48h] BYREF
  _BYTE v212[8]; // [sp+168h] [bp-38h] BYREF
  char v213; // [sp+170h] [bp-30h] BYREF
  _BYTE v214[19]; // [sp+171h] [bp-2Fh] BYREF
  int varg_r3; // [sp+1B4h] [bp+14h] BYREF
  va_list varg_r3a; // [sp+1B4h] [bp+14h]
  int v217; // [sp+1B8h] [bp+18h]
  unsigned int v218; // [sp+1BCh] [bp+1Ch]
  _DWORD *v219; // [sp+1C0h] [bp+20h]
  _DWORD *v220; // [sp+1C4h] [bp+24h]
  int *v221; // [sp+1C8h] [bp+28h]
  int *v222; // [sp+1CCh] [bp+2Ch]
  int *v223; // [sp+1D0h] [bp+30h]
  int v224; // [sp+1D4h] [bp+34h]
  va_list va1; // [sp+1D8h] [bp+38h] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v217 = va_arg(va1, _DWORD);
  v218 = va_arg(va1, _DWORD);
  v219 = va_arg(va1, _DWORD *);
  v220 = va_arg(va1, _DWORD *);
  v221 = va_arg(va1, int *);
  v222 = va_arg(va1, int *);
  v223 = va_arg(va1, int *);
  v224 = va_arg(va1, _DWORD);
  v3 = varg_r3;
  v189 = a2;
  v199 = a1;
  v166 = 0;
  v185 = 0;
  v177 = 0;
  v184 = 0;
  v193 = 0;
  v200 = 0;
  v5 = 0;
  v6 = 0;
  v167 = 0;
  v7 = 0;
  v171 = 0;
  v168 = 0;
  v170 = 0;
  v158 = 0;
  v162 = 0;
  v192 = 0;
  v196 = 0;
  v180 = 0;
  v163 = 0;
  v191 = 0;
  v183 = 0;
  v197 = 0;
  v202 = 0;
  v209[0] = 0;
  v209[1] = 0;
  v209[2] = 0;
  v210 = 0;
  v182 = 0;
  v165 = 0;
  v156 = 0;
  v161 = 0;
  v203[0] = 0;
  v203[1] = 0;
  v203[2] = 0;
  v204 = 0;
  v205 = 0;
  v190 = 0;
  v198 = 0;
  v213 = 0;
  memset(v214, 0, sizeof(v214));
  v157 = 0;
  v164 = 0;
  v176 = 0;
  v151 = 0;
  v194 = 0;
  v181 = 0;
  v187 = 0;
  v174 = 0;
  v169 = 0;
  v173 = 0;
  v160 = 0;
  v148 = 0;
  v154 = 0;
  v149 = 0;
  v155 = 0;
  v159 = 0;
  v201 = -1;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v175 = v8;
  v152 = v8;
  if ( !v8 )
  {
    *v223 = 0;
    *v222 = v3;
    return v5;
  }
  v153 = (unsigned __int8)v224;
  if ( (_BYTE)v224 )
  {
    v172 = v218;
    if ( !v218 || v218 >= (unsigned int)-MmSystemRangeStart >> 3 )
    {
      v5 = -1073741811;
      v179 = -1073741811;
      v150 = v223;
      v178 = v222;
      v195 = v221;
      v188 = v220;
      goto LABEL_23;
    }
    v150 = v223;
    ProbeForWrite(v223, 4 * v218, 4);
    v178 = v222;
    ProbeForWrite(v222, 4 * v218, 4);
  }
  else
  {
    v150 = v223;
    v9 = v223;
    if ( (unsigned int)v223 >= MmUserProbeAddress )
      v9 = (int *)MmUserProbeAddress;
    *v9 = *v9;
    v178 = v222;
    v10 = v222;
    if ( (unsigned int)v222 >= MmUserProbeAddress )
      v10 = (int *)MmUserProbeAddress;
    *v10 = *v10;
    v172 = v218;
  }
  v195 = v221;
  v11 = v221;
  if ( (unsigned int)v221 >= MmUserProbeAddress )
    v11 = (int *)MmUserProbeAddress;
  v197 = *v11;
  v12 = v197;
  v202 = v197;
  v13 = v221;
  if ( (unsigned int)v221 >= MmUserProbeAddress )
    v13 = (int *)MmUserProbeAddress;
  *v13 = *v13;
  v188 = v220;
  v14 = ProbeForWrite(v220, v12, 4);
  if ( v220 && v197 >= 0x14 )
    *v220 = 0;
  if ( ((unsigned __int8)v219 & 3) != 0 )
    ExRaiseDatatypeMisalignment(v14);
  v15 = v219[1];
  v16 = v219[2];
  v17 = v219[3];
  v211[0] = *v219;
  v211[1] = v15;
  v211[2] = v16;
  v211[3] = v17;
  LOBYTE(v8) = v175;
LABEL_23:
  if ( v5 < 0 )
    return v5;
  if ( (v3 & 0xF0000000) != 0 )
  {
    v5 = -1073741594;
    v18 = v180;
LABEL_327:
    v30 = v153;
LABEL_328:
    v35 = v154;
    goto LABEL_329;
  }
  v5 = SepReferenceTokenByHandle(a3, 8, v8, &v167, &v148, &v159);
  if ( v5 < 0 )
  {
    v6 = 0;
    v18 = v180;
LABEL_326:
    v160 = v148;
    v155 = v159;
    goto LABEL_327;
  }
  if ( a3 == -4 || a3 == -5 || a3 == -6 )
  {
    v6 = v167;
  }
  else
  {
    v6 = v167;
    if ( v167[42] != 2 )
    {
      v5 = -1073741732;
      v18 = v180;
      goto LABEL_326;
    }
    if ( (int)v167[43] < 1 )
    {
      v5 = -1073741659;
      v18 = v180;
      goto LABEL_326;
    }
  }
  v19 = v175;
  v5 = SeCaptureObjectTypeList(v217, v172, v175, &v163);
  if ( v5 < 0 || (v20 = SeCaptureSecurityDescriptor(v199, v19, 1, 0, &v171), v5 = v20, v7 = v171, v20 < 0) )
  {
LABEL_325:
    v18 = v163;
    goto LABEL_326;
  }
  if ( !v171 )
    goto LABEL_324;
  if ( (*(_WORD *)(v171 + 2) & 0x8000) != 0 )
  {
    v21 = *(_DWORD *)(v171 + 4);
    if ( !v21 )
      goto LABEL_324;
    v22 = v21 + v171;
  }
  else
  {
    v22 = *(_DWORD *)(v171 + 4);
  }
  if ( !v22 )
    goto LABEL_324;
  if ( (*(_WORD *)(v171 + 2) & 0x8000) != 0 )
  {
    v23 = *(_DWORD *)(v171 + 8);
    if ( v23 )
    {
      v24 = v23 + v171;
      goto LABEL_48;
    }
LABEL_324:
    v5 = -1073741703;
    goto LABEL_325;
  }
  v24 = *(_DWORD *)(v171 + 8);
LABEL_48:
  if ( !v24 )
    goto LABEL_324;
  v160 = v148;
  v155 = v159;
  if ( v148 )
    v25 = v159;
  else
    v25 = v6[160];
  v5 = SepTrustLevelCheck(v20, v171, 0, (int)v6, v25, 1, &v201);
  if ( v5 < 0 )
    goto LABEL_97;
  v26 = SepTrustToDiscretionary(&v201, v3);
  if ( v26 < 0 )
  {
    v154 = 1;
    v149 = 1;
    v29 = v182;
LABEL_69:
    v28 = v191;
    goto LABEL_70;
  }
  v5 = SepMandatoryIntegrityCheck(v211, v7, 0, v6, 1, v209);
  if ( v5 < 0 )
  {
LABEL_97:
    v18 = v163;
    goto LABEL_327;
  }
  v182 = 0;
  v165 = 0;
  v27 = SepMandatoryToDiscretionary(v209, v3);
  v26 = v27;
  if ( (v27 < 0 || (v3 & 0x2000000) != 0) && (v6[44] & 0x4000) != 0 && v210 <= 0x2000 )
  {
    v29 = 1;
    v182 = 1;
    v165 = 1;
  }
  else
  {
    v29 = v182;
  }
  if ( v27 < 0 && !v29 )
    goto LABEL_69;
  v26 = SePrivilegePolicyCheck((int *)varg_r3a, &v162, 0, (int)v6, (int **)&v183, v175);
  v3 = varg_r3;
  v158 = v162;
  if ( varg_r3 )
  {
    v28 = (int *)v183;
    v191 = (int *)v183;
    goto LABEL_68;
  }
  v28 = (int *)v183;
  v191 = (int *)v183;
  if ( !v162 )
  {
LABEL_68:
    v29 = v182;
    goto LABEL_70;
  }
  v187 = 1;
  v174 = 1;
  v29 = v182;
LABEL_70:
  if ( v26 < 0 && !v29 )
  {
    v30 = v153;
    v31 = v178;
    v32 = v150;
    if ( v153 )
    {
      v33 = 0;
      v186 = 0;
      v34 = v172;
      while ( v33 < v34 )
      {
        v32[v33] = v26;
        v31[v33++] = 0;
        v186 = v33;
      }
    }
    else
    {
      *v150 = v26;
      *v31 = 0;
    }
    v5 = 0;
    v179 = 0;
    v35 = v154;
    v18 = v163;
    goto LABEL_330;
  }
  if ( v28 )
  {
    v36 = *v28;
    if ( *v28 )
      v37 = 12 * (v36 - 1) + 20;
    else
      v37 = 8;
    if ( v37 > v197 )
    {
      if ( v36 )
        v38 = 12 * (v36 - 1) + 20;
      else
        v38 = 8;
      *v195 = v38;
      v5 = -1073741789;
      v179 = -1073741789;
      v30 = v153;
      ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v28);
      v18 = v163;
      goto LABEL_328;
    }
    if ( v36 )
      v39 = 12 * (v36 - 1) + 20;
    else
      v39 = 8;
    memmove((int)v188, (int)v28, v39);
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v191);
    v40 = v175;
  }
  else
  {
    if ( v197 < 0x14 )
    {
      *v195 = 20;
      v5 = -1073741789;
      v179 = -1073741789;
      v30 = v153;
      v35 = v154;
      v32 = v150;
      v18 = v163;
      goto LABEL_330;
    }
    v41 = v188;
    *v188 = 0;
    v41[1] = 0;
    v40 = v175;
  }
  if ( v189 )
  {
    v5 = SeCaptureSid(v189, v40);
    if ( v5 < 0 )
    {
      v168 = 0;
      goto LABEL_97;
    }
    v168 = v170;
  }
  SeCaptureSubjectContext(v206);
  v42 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v42 & 0xFFFFFFC0) + 0x134);
  ExAcquireResourceSharedLite(v6[12], 1);
  v43 = SepTokenIsOwner(v6, v7);
  v45 = v43;
  v200 = v43;
  if ( !(_BYTE)SepAllowAccessUponLogoff && (v6[44] & 0x20) == 0 )
  {
    v46 = v6[48];
    if ( v46 )
    {
      if ( (*(_DWORD *)(v46 + 24) & 0x20) != 0 )
      {
        v30 = v153;
        v47 = v178;
        v48 = v150;
        if ( v153 )
        {
          v49 = 0;
          v186 = 0;
          v44 = v172;
          while ( v49 < v44 )
          {
            v48[v49] = -1073741790;
            v47[v49++] = 0;
            v186 = v49;
          }
        }
        else
        {
          *v150 = -1073741790;
          *v47 = 0;
        }
        v5 = 0;
        v179 = 0;
        v50 = ExReleaseResourceLite(v6[12], v44);
        v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v52 = *(_WORD *)(v51 + 0x134) + 1;
        *(_WORD *)(v51 + 308) = v52;
        if ( !v52 && *(_DWORD *)(v51 + 100) != v51 + 100 && !*(_WORD *)(v51 + 310) )
          KiCheckForKernelApcDelivery(v50);
        SeReleaseSubjectContext(v206);
        v18 = v163;
        goto LABEL_328;
      }
    }
  }
  v53 = (unsigned __int8)SepRmEnforceCap;
  __dmb(0xBu);
  v7 = v171;
  if ( !v53 )
    goto LABEL_130;
  if ( (*(_WORD *)(v171 + 2) & 0x10) != 0 && (unsigned int)KeGetCurrentIrql(v43) < 2 )
  {
    if ( (*(_WORD *)(v7 + 2) & 0x10) != 0 )
    {
      if ( (*(_WORD *)(v7 + 2) & 0x8000) != 0 )
      {
        v54 = *(_DWORD *)(v7 + 12);
        if ( !v54 )
        {
          v190 = 0;
          goto LABEL_130;
        }
        v55 = v54 + v7;
      }
      else
      {
        v55 = *(_DWORD *)(v7 + 12);
      }
      v190 = v55;
      if ( v55 )
      {
        v56 = SepGetScopedPolicySid();
        if ( v56 )
        {
          if ( SepRmReferenceFindCap(v56, &v164) >= 0 )
          {
            v57 = v164;
          }
          else
          {
            v57 = SepRmDefaultCap;
            v164 = SepRmDefaultCap;
          }
          v58 = 1;
          v176 = 1;
          v151 = 1;
          goto LABEL_131;
        }
      }
    }
    else
    {
      v190 = 0;
    }
LABEL_130:
    v58 = v176;
    v57 = v164;
LABEL_131:
    v157 = v57;
    goto LABEL_132;
  }
  v157 = v164;
  v58 = v176;
LABEL_132:
  v3 = varg_r3;
  if ( (varg_r3 & 0x2060000) != 0
    && v45
    && ((*(_WORD *)(v7 + 2) & 4) != 0 ? ((*(_WORD *)(v7 + 2) & 0x8000) == 0 ? (v59 = *(_DWORD *)(v7 + 16)) : (v60 = *(_DWORD *)(v7 + 16)) != 0 ? (v59 = v60 + v7) : (v59 = 0)) : (v59 = 0),
        !RtlpOwnerAcesPresent(0, v59)) )
  {
    if ( (v3 & 0x2000000) != 0 )
    {
      v61 = v162 | 0x60000;
      v192 = 393216;
    }
    else
    {
      v192 = v3 & 0x60000;
      v61 = v3 & 0x60000 | v162;
    }
    v162 = v61;
    v3 &= 0xFFF9FFFF;
    varg_r3 = v3;
  }
  else
  {
    v61 = v162;
  }
  v158 = v61;
  if ( v3 || v58 && !v187 )
  {
    v6 = v167;
    v62 = v192;
  }
  else
  {
    v6 = v167;
    if ( (v167[44] & 0x2000) != 0 || (v62 = v192) == 0 )
    {
      v30 = v153;
      v63 = v178;
      if ( v153 )
      {
        v64 = 0;
        v186 = 0;
        v65 = v150;
        v66 = v172;
        while ( v64 < v66 )
        {
          if ( v61 )
          {
            v65[v64] = 0;
            v63[v64] = v61;
          }
          else
          {
            v65[v64] = -1073741790;
            v63[v64] = 0;
          }
          v186 = ++v64;
        }
      }
      else if ( v61 )
      {
        *v150 = 0;
        *v63 = v61;
      }
      else
      {
        *v150 = -1073741790;
        *v63 = 0;
      }
      v5 = 0;
      v179 = 0;
      v67 = ExReleaseResourceLite(v6[12], v61);
      v68 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v69 = *(_WORD *)(v68 + 0x134) + 1;
      *(_WORD *)(v68 + 308) = v69;
      if ( !v69 && *(_DWORD *)(v68 + 100) != v68 + 100 && !*(_WORD *)(v68 + 310) )
        KiCheckForKernelApcDelivery(v67);
      SeReleaseSubjectContext(v206);
      v168 = v170;
      v18 = v163;
      v156 = v161;
      v169 = v173;
      v160 = v148;
      v35 = v149;
      v155 = v159;
      goto LABEL_329;
    }
  }
  v30 = v153;
  if ( v153 )
  {
    v70 = (int *)ExAllocatePoolWithTag(1, 8 * v172, 1632068947);
    v166 = v70;
    v185 = v70;
    if ( !v70 )
    {
      v72 = ExReleaseResourceLite(v6[12], v71);
      v73 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v74 = *(_WORD *)(v73 + 0x134) + 1;
      *(_WORD *)(v73 + 308) = v74;
      if ( !v74 && *(_DWORD *)(v73 + 100) != v73 + 100 && !*(_WORD *)(v73 + 310) )
        KiCheckForKernelApcDelivery(v72);
      SeReleaseSubjectContext(v206);
      v5 = -1073741670;
      v168 = v170;
      v18 = v163;
      v156 = v161;
      v169 = v173;
      v160 = v148;
      v35 = v149;
      v155 = v159;
      goto LABEL_329;
    }
    v75 = &v70[v172];
    v62 = v192;
  }
  else
  {
    v70 = (int *)v212;
    v166 = (int *)v212;
    v185 = (int *)v212;
    v75 = (int *)&v195;
  }
  v203[0] = v62;
  v147 = v45;
  v76 = v153;
  SepAccessCheck(v7, v170, v207, v6, v3, v163, v172, v211, v158, v175, v70, 0, v75, v153, v147, v203, &v161, 0, 0);
  v78 = (unsigned __int8)SepRmEnforceCap;
  __dmb(0xBu);
  if ( !v78 || *v75 < 0 || !v176 )
  {
    v3 = varg_r3;
    v6 = v167;
    v168 = v170;
    v158 = v162;
    v180 = v163;
    v156 = v161;
    v157 = v164;
    v169 = v173;
    goto LABEL_269;
  }
  v79 = v172;
  if ( v76 )
  {
    v80 = ExAllocatePoolWithTag(1, 8 * v172, 1632068947);
    v177 = (unsigned int *)v80;
    v184 = (_BYTE *)v80;
    if ( !v80 )
    {
      v6 = v167;
      v81 = ExReleaseResourceLite(v167[12], 0);
      v82 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v83 = *(_WORD *)(v82 + 0x134) + 1;
      *(_WORD *)(v82 + 308) = v83;
      if ( !v83 && *(_DWORD *)(v82 + 100) != v82 + 100 && !*(_WORD *)(v82 + 310) )
        KiCheckForKernelApcDelivery(v81);
      SeReleaseSubjectContext(v206);
      v5 = -1073741670;
      v3 = varg_r3;
      v7 = v171;
      v168 = v170;
      v158 = v162;
      v18 = v163;
      v156 = v161;
      v157 = v164;
      v169 = v173;
      v160 = v148;
      v35 = v149;
      v155 = v159;
      v30 = v153;
      goto LABEL_329;
    }
    v84 = (unsigned int *)(v80 + 4 * v79);
  }
  else
  {
    v177 = (unsigned int *)v208;
    v184 = v208;
    v84 = &v197;
  }
  v193 = v84;
  v85 = *v75;
  v188 = (_DWORD *)*v75;
  v86 = *v166;
  v183 = *v166;
  v199 = 0;
  if ( v79 )
  {
    v180 = v163;
    v5 = SepCopyObjectTypeList(v163, v79, &v173);
    if ( v5 < 0 )
    {
      v3 = varg_r3;
      v6 = v167;
      v7 = v171;
      v168 = v170;
      v158 = v162;
      v156 = v161;
      v157 = v164;
      v169 = v173;
      v160 = v148;
      v35 = v149;
      v155 = v159;
      v18 = v180;
      v30 = v153;
LABEL_329:
      v32 = v150;
      goto LABEL_330;
    }
    v85 = (int)v188;
    v86 = v183;
  }
  else
  {
    v180 = v163;
  }
  v87 = 0;
  v157 = v164;
  v88 = (int)v164;
  v3 = varg_r3;
  v6 = v167;
  v168 = v170;
  v158 = v162;
  v156 = v161;
  v169 = v173;
  v89 = v200;
  v90 = v161;
  while ( 1 )
  {
    v196 = v88;
    v198 = v87;
    if ( v87 >= v157[8] )
      goto LABEL_267;
    v187 = *(_DWORD *)(v88 + 36);
    if ( !*(_DWORD *)(v187 + 12) )
      break;
    if ( !v90 )
    {
      if ( AuthzBasepInitializeResourceClaimsFromSacl(v190, (int)&v161) < 0 )
        v199 = 1;
      v156 = v161;
    }
    v91 = (_DWORD *)v6[159];
    v92 = v91 ? v91[75] : 0;
    v93 = v91 ? v91[73] : 0;
    v94 = v91 ? v91[74] : 0;
    v95 = v91 ? v91[72] : 0;
    v96 = AuthzBasepEvaluateAceCondition(
            (int)v6,
            v6[119],
            v156,
            v95,
            v94,
            v93,
            v92,
            *(_DWORD **)(v187 + 12),
            *(_DWORD *)(v187 + 8),
            1u,
            0,
            &v189);
    v5 = v96;
    if ( v189 == 1 )
      break;
    if ( v96 < 0 )
    {
      v111 = ExReleaseResourceLite(v6[12], v97);
      v112 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v113 = *(_WORD *)(v112 + 0x134) + 1;
      *(_WORD *)(v112 + 308) = v113;
      if ( !v113 && *(_DWORD *)(v112 + 100) != v112 + 100 && !*(_WORD *)(v112 + 310) )
        KiCheckForKernelApcDelivery(v111);
      goto LABEL_266;
    }
    if ( SeTokenIsRestricted((int)v6) )
    {
      v98 = (_DWORD *)v6[159];
      v99 = v98 ? v98[75] : 0;
      v100 = v98 ? v98[73] : 0;
      v101 = v98 ? v98[74] : 0;
      v102 = v98 ? v98[72] : 0;
      v5 = AuthzBasepEvaluateAceCondition(
             (int)v6,
             v6[119],
             v156,
             v102,
             v101,
             v100,
             v99,
             *(_DWORD **)(v187 + 12),
             *(_DWORD *)(v187 + 8),
             1u,
             1u,
             &v189);
      if ( v5 < 0 )
      {
        v108 = ExReleaseResourceLite(v6[12], v103);
        v109 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v110 = *(_WORD *)(v109 + 0x134) + 1;
        *(_WORD *)(v109 + 308) = v110;
        if ( !v110 && *(_DWORD *)(v109 + 100) != v109 + 100 && !*(_WORD *)(v109 + 310) )
          KiCheckForKernelApcDelivery(v108);
        goto LABEL_266;
      }
    }
    if ( v199 || v189 == 1 )
      break;
    v85 = (int)v188;
    v86 = v183;
    v90 = v156;
LABEL_250:
    v87 = v198 + 1;
    v88 = v196 + 4;
  }
  v5 = SepBuildCapeSecurityDescriptor(&v213, *(_DWORD *)(v187 + 16), v190);
  if ( v5 < 0 )
  {
    v114 = ExReleaseResourceLite(v6[12], v104);
    v115 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v116 = *(_WORD *)(v115 + 0x134) + 1;
    *(_WORD *)(v115 + 308) = v116;
    if ( !v116 && *(_DWORD *)(v115 + 100) != v115 + 100 && !*(_WORD *)(v115 + 310) )
      KiCheckForKernelApcDelivery(v114);
LABEL_266:
    SeReleaseSubjectContext(v206);
    v7 = v171;
    v160 = v148;
    v35 = v149;
    v155 = v159;
    v18 = v180;
    v30 = v153;
    goto LABEL_329;
  }
  if ( (*(_DWORD *)(v187 + 24) & 1) != 0 )
  {
    if ( (v3 & 0x2000000) == 0 )
    {
      v106 = v158 | v3;
      v105 = 0;
      goto LABEL_239;
    }
    v105 = 0;
  }
  else
  {
    v105 = v158;
  }
  v106 = v3;
LABEL_239:
  v107 = (int *)v193;
  SepAccessCheck(&v213, v168, v207, v6, v106, v169, v172, v211, v105, v175, v177, 0, v193, v153, v89, v203, &v161, 0, 0);
  if ( v194 )
    v86 = v183 & *v177;
  else
    v86 = *v177;
  v183 = v86;
  if ( v86 )
    v85 = *v107;
  else
    v85 = -1073741790;
  v188 = (_DWORD *)v85;
  v194 = 1;
  if ( v169 )
  {
    SepMergeObjectTypeListAccesses(v180, v169, v172);
    v86 = v183;
  }
  if ( v85 >= 0 )
  {
    v90 = v161;
    v156 = v161;
    goto LABEL_250;
  }
  v156 = v161;
LABEL_267:
  *v75 = v85;
  v77 = v166;
  *v166 &= v86;
LABEL_269:
  v117 = ExReleaseResourceLite(v6[12], v77);
  v118 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v119 = *(_WORD *)(v118 + 0x134) + 1;
  *(_WORD *)(v118 + 308) = v119;
  if ( !v119 && *(_DWORD *)(v118 + 100) != v118 + 100 && !*(_WORD *)(v118 + 310) )
    KiCheckForKernelApcDelivery(v117);
  SeReleaseSubjectContext(v206);
  if ( (v3 & 0x2000000) == 0 )
  {
    if ( !v182 || *(_WORD *)((char *)&v205 + 1) )
      goto LABEL_288;
    v30 = v153;
    v121 = v178;
    v32 = v150;
    if ( v153 )
    {
      v122 = 0;
      v186 = 0;
      v123 = v172;
      while ( v122 < v123 )
      {
        v32[v122] = -1073741790;
        v121[v122++] = 0;
        v186 = v122;
      }
    }
    else
    {
      *v150 = -1073741790;
      *v121 = 0;
    }
    v5 = 0;
    v179 = 0;
    v18 = v180;
    v7 = v171;
    v160 = v148;
    v35 = v149;
    v155 = v159;
    goto LABEL_330;
  }
  if ( !v182 || !*(_WORD *)((char *)&v205 + 1) )
  {
    if ( v153 )
      v120 = v172;
    else
      v120 = 0;
    SepConstrainByMandatory((int)v209, v3, v166, (int)v75, 0, v120);
  }
LABEL_288:
  if ( (v3 & 0x2000000) == 0 )
  {
    v154 = v149;
    v124 = v153;
LABEL_307:
    v127 = v166;
    goto LABEL_308;
  }
  v124 = v153;
  if ( v153 )
    v125 = v172;
  else
    v125 = 0;
  v154 = 0;
  v149 = 0;
  v126 = v201;
  if ( v201 == -1 )
    goto LABEL_307;
  if ( v125 )
  {
    v129 = v75;
    v130 = (char *)((char *)v166 - (char *)v75);
    do
    {
      v131 = *(int *)((char *)v129 + (_DWORD)v130);
      v132 = v131 & v126;
      if ( (v131 & v126) != v131 )
      {
        v154 = 1;
        v149 = 1;
        *(int *)((char *)v129 + (_DWORD)v130) = v132;
        if ( v132 )
          *v129 = 0;
        else
          *v129 = -1073741790;
      }
      ++v129;
      --v125;
    }
    while ( v125 );
    v124 = v153;
    v127 = v166;
  }
  else
  {
    v127 = v166;
    v128 = v201 & *v166;
    if ( v128 == *v166 )
    {
      v124 = v153;
    }
    else
    {
      v154 = 1;
      v149 = 1;
      *v166 = v128;
      v124 = v153;
      if ( v128 )
        *v75 = 0;
      else
        *v75 = -1073741790;
    }
  }
LABEL_308:
  if ( v124 )
  {
    v133 = 0;
    v186 = 0;
    v134 = v178;
    while ( v133 < v172 )
    {
      v135 = v150;
      v150[v133] = v75[v133];
      v134[v133] = v127[v133];
      v136 = (unsigned __int8)SepRmEnforceCap;
      __dmb(0xBu);
      if ( v136 && v194 && v135[v133] >= 0 )
      {
        v135[v133] = v193[v133];
        v134[v133] &= v177[v133];
      }
      v133 = ++v186;
      v3 = varg_r3;
      v6 = v167;
      v168 = v170;
      v158 = v162;
      v180 = v163;
      v156 = v161;
      v157 = v164;
      v169 = v173;
      v154 = v149;
    }
    v18 = v180;
    v35 = v154;
LABEL_322:
    v32 = v150;
  }
  else
  {
    v137 = v150;
    *v150 = *v75;
    v138 = v178;
    *v178 = *v127;
    v139 = (unsigned __int8)SepRmEnforceCap;
    __dmb(0xBu);
    if ( !v139 || !v194 || (v32 = v137, *v137 < 0) )
    {
      v3 = varg_r3;
      v6 = v167;
      v168 = v170;
      v158 = v162;
      v18 = v163;
      v156 = v161;
      v157 = v164;
      v169 = v173;
      v35 = v149;
      goto LABEL_322;
    }
    *v137 = *v193;
    *v138 &= *v177;
    v3 = varg_r3;
    v6 = v167;
    v168 = v170;
    v158 = v162;
    v18 = v163;
    v156 = v161;
    v157 = v164;
    v169 = v173;
    v35 = v149;
  }
  v5 = 0;
  v179 = 0;
  v30 = v153;
  v7 = v171;
  v160 = v148;
  v155 = v159;
LABEL_330:
  if ( v7 && v6 && (v35 || !v204 && (v6[44] & 0x4000) != 0 && v5 >= 0 && (*v32 < 0 || HIBYTE(v205))) )
  {
    v140 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v140 + 308);
    ExAcquireResourceSharedLite(v6[12], 1);
    if ( !v160 )
      v155 = v6[160];
    SeLogAccessFailure((int)v6, v141, v158 | v3, v155);
    ExReleaseResourceLite(v6[12], v142);
    v143 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v144 = *(_WORD *)(v143 + 0x134);
    *(_WORD *)(v143 + 308) = v144 + 1;
    if ( v144 == -1 && *(_DWORD *)(v143 + 100) != v143 + 100 && !*(_WORD *)(v143 + 310) )
      KiCheckForKernelApcDelivery(v143);
  }
  if ( v30 )
  {
    if ( v166 )
      ExFreePoolWithTag(v166, 0);
    if ( v177 )
      ExFreePoolWithTag(v177, 0);
  }
  if ( v6 )
    ObfDereferenceObject(v6);
  if ( v18 )
    SeFreeCapturedObjectTypeList(v18);
  v145 = v175;
  if ( v168 )
    SeReleaseSid(v168, v175, 1);
  if ( v7 )
    SeReleaseSecurityDescriptor(v7, v145, 0);
  if ( v176 )
    SepRmDereferenceCap(v157);
  if ( v169 )
    ExFreePoolWithTag(v169, 0);
  SepFreeResourceInfo(v156);
  return v5;
}
