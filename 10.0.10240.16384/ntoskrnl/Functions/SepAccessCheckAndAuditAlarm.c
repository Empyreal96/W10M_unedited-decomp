// SepAccessCheckAndAuditAlarm 
 
int SepAccessCheckAndAuditAlarm(int a1, ...)
{
  _DWORD *v1; // r9
  int v2; // r5
  unsigned int v3; // r8
  unsigned int v4; // r10
  int v5; // r6
  int v6; // r4
  int v7; // r0
  int *v8; // r10
  int *v9; // r2
  _DWORD *v10; // r2
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r0
  int v15; // r1
  int *v16; // r9
  unsigned int v17; // r4
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r3
  _BYTE *v22; // r2
  char v23; // r2
  int v24; // r0
  int v25; // r0
  int v26; // r3
  int v27; // r1
  int v28; // r0
  int v29; // r8
  unsigned int v30; // r9
  int *v31; // r0
  unsigned int v32; // r2
  int *v33; // r1
  int v34; // r3
  int v35; // r0
  int v36; // r1
  int v37; // r3
  int v38; // r3
  int v39; // r0
  unsigned __int8 *v40; // r0
  _DWORD *v41; // r1
  int v42; // r0
  int v43; // r3
  int v44; // r1
  int *v45; // r0
  unsigned int v46; // lr
  unsigned int v47; // r2
  int *v48; // r1
  unsigned int v49; // r5
  int *v50; // r0
  int *v51; // r5
  int v52; // r3
  int v53; // r4
  unsigned int *v54; // r0
  int *v55; // r3
  unsigned int v56; // r2
  int v57; // r0
  unsigned int v58; // lr
  int v59; // r1
  int v60; // r6
  int v61; // r1
  int v62; // r0
  int v63; // lr
  _DWORD *v64; // r3
  int v65; // r6
  int v66; // r5
  int v67; // r0
  int v68; // r3
  int v69; // r0
  int v70; // r6
  _DWORD *v71; // r3
  int v72; // r6
  int v73; // r5
  int v74; // r0
  int v75; // r3
  int v76; // r3
  int v77; // r6
  unsigned int v78; // r3
  int v79; // lr
  int v80; // r3
  unsigned int v81; // r3
  int *v82; // r2
  int v83; // r2
  int *v84; // r2
  int *v85; // lr
  unsigned int v86; // r2
  int v87; // r1
  int v88; // r2
  int v89; // r3
  int v90; // r0
  int v91; // r1
  int v92; // r0
  unsigned int v93; // r1
  __int16 v94; // r3
  int v95; // r10
  int v96; // r0
  int v97; // r1
  int *v98; // r5
  __int16 v99; // r3
  int v100; // r1
  int v101; // r2
  int v102; // r0
  int v103; // r3
  int v104; // r10
  int *v105; // r5
  int *v106; // r2
  int v107; // r1
  int v108; // r3
  BOOL v109; // r3
  BOOL v110; // r2
  int *v111; // r1
  unsigned int v112; // r2
  char v113; // r5
  unsigned int v114; // r2
  int *v115; // r1
  int *v116; // r0
  int v117; // r3
  va_list v118; // r2
  int v119; // r10
  int *v120; // r1
  int v121; // r3
  va_list v122; // r2
  int *v123; // r4
  int v124; // r2
  unsigned int v125; // r2
  int v126; // r1
  _DWORD *v127; // r0
  int v128; // r3
  unsigned int v129; // r1
  _DWORD *v130; // r0
  int v131; // r3
  _DWORD *v132; // r1
  int v133; // r3
  int v134; // r9
  int v135; // r1
  int v137; // [sp+8h] [bp-1E8h]
  int v138; // [sp+Ch] [bp-1E4h]
  int v139; // [sp+10h] [bp-1E0h]
  int v140; // [sp+14h] [bp-1DCh]
  int v141; // [sp+20h] [bp-1D0h]
  bool v142; // [sp+40h] [bp-1B0h] BYREF
  bool v143; // [sp+41h] [bp-1AFh] BYREF
  char v144[2]; // [sp+42h] [bp-1AEh] BYREF
  int v145; // [sp+44h] [bp-1ACh]
  unsigned int v146; // [sp+48h] [bp-1A8h] BYREF
  unsigned int v147; // [sp+4Ch] [bp-1A4h]
  int *v148; // [sp+50h] [bp-1A0h]
  char v149; // [sp+54h] [bp-19Ch]
  _DWORD *v150; // [sp+58h] [bp-198h]
  int v151; // [sp+5Ch] [bp-194h]
  int v152; // [sp+60h] [bp-190h]
  unsigned int v153; // [sp+64h] [bp-18Ch]
  unsigned int v154; // [sp+68h] [bp-188h]
  int v155; // [sp+6Ch] [bp-184h]
  unsigned __int16 v156; // [sp+70h] [bp-180h] BYREF
  _DWORD *v157; // [sp+74h] [bp-17Ch] BYREF
  int v158; // [sp+78h] [bp-178h] BYREF
  int *v159; // [sp+7Ch] [bp-174h] BYREF
  int v160; // [sp+80h] [bp-170h] BYREF
  _DWORD *v161; // [sp+84h] [bp-16Ch]
  unsigned int v162; // [sp+88h] [bp-168h] BYREF
  _DWORD *v163; // [sp+8Ch] [bp-164h] BYREF
  char v164[4]; // [sp+90h] [bp-160h] BYREF
  int *v165; // [sp+94h] [bp-15Ch]
  int v166; // [sp+98h] [bp-158h]
  unsigned __int8 v167; // [sp+9Ch] [bp-154h] BYREF
  char v168; // [sp+9Dh] [bp-153h]
  char v169; // [sp+9Eh] [bp-152h]
  int v170; // [sp+A0h] [bp-150h]
  int v171; // [sp+A4h] [bp-14Ch]
  unsigned int v172; // [sp+A8h] [bp-148h] BYREF
  _DWORD *v173; // [sp+ACh] [bp-144h]
  unsigned int v174; // [sp+B0h] [bp-140h]
  int v175; // [sp+B4h] [bp-13Ch]
  int v176; // [sp+B8h] [bp-138h]
  int *v177; // [sp+BCh] [bp-134h]
  _DWORD *v178; // [sp+C0h] [bp-130h] BYREF
  int v179; // [sp+C4h] [bp-12Ch] BYREF
  char v180; // [sp+C8h] [bp-128h]
  char v181; // [sp+C9h] [bp-127h]
  char v182; // [sp+CAh] [bp-126h]
  int *v183[2]; // [sp+D0h] [bp-120h] BYREF
  int *v184; // [sp+D8h] [bp-118h]
  int v185; // [sp+E0h] [bp-110h] BYREF
  int v186; // [sp+E4h] [bp-10Ch]
  int v187; // [sp+E8h] [bp-108h] BYREF
  unsigned int *v188; // [sp+ECh] [bp-104h]
  int v189; // [sp+F0h] [bp-100h]
  char v190; // [sp+F4h] [bp-FCh]
  int v191; // [sp+F8h] [bp-F8h]
  char v192; // [sp+FCh] [bp-F4h]
  char v193; // [sp+FDh] [bp-F3h]
  char v194; // [sp+FEh] [bp-F2h]
  char v195[2]; // [sp+FFh] [bp-F1h] BYREF
  char v196[3]; // [sp+101h] [bp-EFh] BYREF
  int v197; // [sp+104h] [bp-ECh]
  int v198; // [sp+108h] [bp-E8h] BYREF
  int *v199; // [sp+10Ch] [bp-E4h]
  BOOL v200; // [sp+110h] [bp-E0h]
  int v201; // [sp+114h] [bp-DCh]
  int *v202; // [sp+118h] [bp-D8h]
  int *v203; // [sp+11Ch] [bp-D4h]
  int v204; // [sp+120h] [bp-D0h]
  _DWORD *v205; // [sp+124h] [bp-CCh]
  int v206; // [sp+128h] [bp-C8h]
  int v207; // [sp+12Ch] [bp-C4h]
  BOOL v208; // [sp+130h] [bp-C0h]
  int v209; // [sp+134h] [bp-BCh]
  int v210; // [sp+138h] [bp-B8h]
  int v211; // [sp+13Ch] [bp-B4h] BYREF
  int v212; // [sp+140h] [bp-B0h]
  int v213; // [sp+144h] [bp-ACh]
  int v214; // [sp+148h] [bp-A8h]
  int *v215; // [sp+14Ch] [bp-A4h]
  int v216; // [sp+150h] [bp-A0h]
  int v217; // [sp+154h] [bp-9Ch]
  int v218; // [sp+158h] [bp-98h]
  int *v219; // [sp+15Ch] [bp-94h]
  unsigned int v220; // [sp+160h] [bp-90h]
  int v221; // [sp+164h] [bp-8Ch]
  int *v222; // [sp+168h] [bp-88h]
  int v223; // [sp+16Ch] [bp-84h] BYREF
  int v224; // [sp+170h] [bp-80h] BYREF
  int v225; // [sp+174h] [bp-7Ch]
  int v226; // [sp+178h] [bp-78h] BYREF
  int v227; // [sp+17Ch] [bp-74h]
  _BYTE *v228; // [sp+180h] [bp-70h]
  _DWORD v229[3]; // [sp+188h] [bp-68h] BYREF
  int v230; // [sp+194h] [bp-5Ch]
  int v231; // [sp+198h] [bp-58h]
  _DWORD v232[3]; // [sp+1A0h] [bp-50h] BYREF
  unsigned int v233; // [sp+1ACh] [bp-44h]
  _DWORD v234[4]; // [sp+1B0h] [bp-40h] BYREF
  char v235; // [sp+1C0h] [bp-30h] BYREF
  _BYTE v236[19]; // [sp+1C1h] [bp-2Fh] BYREF
  int varg_r1; // [sp+1FCh] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+1FCh] [bp+Ch]
  _DWORD *varg_r2; // [sp+200h] [bp+10h]
  int varg_r3; // [sp+204h] [bp+14h]
  int v241; // [sp+208h] [bp+18h]
  int v242; // [sp+20Ch] [bp+1Ch]
  int v243; // [sp+210h] [bp+20h]
  unsigned int v244; // [sp+214h] [bp+24h] BYREF
  va_list va1; // [sp+214h] [bp+24h]
  int v246; // [sp+218h] [bp+28h]
  int v247; // [sp+21Ch] [bp+2Ch]
  unsigned int v248; // [sp+220h] [bp+30h]
  unsigned int v249; // [sp+224h] [bp+34h]
  int v250; // [sp+228h] [bp+38h]
  _DWORD *v251; // [sp+22Ch] [bp+3Ch]
  int *v252; // [sp+230h] [bp+40h]
  _BYTE *v253; // [sp+234h] [bp+44h]
  int v254; // [sp+238h] [bp+48h]
  va_list va2; // [sp+23Ch] [bp+4Ch] BYREF

  va_start(va2, a1);
  va_start(va1, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(va1, _DWORD);
  varg_r2 = va_arg(va1, _DWORD *);
  varg_r3 = va_arg(va1, _DWORD);
  v241 = va_arg(va1, _DWORD);
  v242 = va_arg(va1, _DWORD);
  v243 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v244 = va_arg(va2, _DWORD);
  v246 = va_arg(va2, _DWORD);
  v247 = va_arg(va2, _DWORD);
  v248 = va_arg(va2, _DWORD);
  v249 = va_arg(va2, _DWORD);
  v250 = va_arg(va2, _DWORD);
  v251 = va_arg(va2, _DWORD *);
  v252 = va_arg(va2, int *);
  v253 = va_arg(va2, _BYTE *);
  v254 = va_arg(va2, _DWORD);
  v227 = varg_r3;
  v1 = varg_r2;
  v225 = a1;
  v2 = 0;
  v187 = 0;
  v165 = 0;
  v199 = 0;
  v210 = 0;
  v149 = 0;
  v185 = -1073741823;
  v188 = 0;
  v219 = 0;
  v203 = 0;
  v224 = 0;
  v209 = 0;
  v190 = 0;
  v3 = 0;
  v145 = 0;
  v160 = 0;
  v4 = 0;
  v147 = 0;
  v162 = 0;
  v154 = 0;
  v172 = 0;
  v5 = 0;
  v179 = 0;
  v155 = 0;
  v171 = 0;
  v150 = 0;
  v157 = 0;
  v174 = 0;
  v146 = 0;
  v148 = 0;
  v159 = 0;
  v208 = 0;
  v142 = 0;
  v200 = 0;
  v143 = 0;
  v221 = 0;
  v181 = 0;
  v214 = 0;
  v192 = 0;
  v206 = 0;
  v194 = 0;
  v196[0] = 1;
  v195[0] = 0;
  v152 = 0;
  v176 = 0;
  v215 = 0;
  v222 = 0;
  v217 = 0;
  v169 = 0;
  v232[0] = 0;
  v232[1] = 0;
  v232[2] = 0;
  v233 = 0;
  v204 = 0;
  v218 = 0;
  v235 = 0;
  memset(v236, 0, sizeof(v236));
  v161 = 0;
  v163 = 0;
  v212 = 0;
  v168 = 0;
  v207 = 0;
  v193 = 0;
  v186 = 0;
  v195[1] = 0;
  v216 = 0;
  v180 = 0;
  v189 = 999;
  v156 = 999;
  v229[0] = 0;
  v229[1] = 0;
  v229[2] = 0;
  v230 = 0;
  v231 = 0;
  v201 = 0;
  v167 = 0;
  v175 = 0;
  v220 = 0;
  v151 = 0;
  v158 = 0;
  v177 = 0;
  v164[0] = 0;
  v197 = 0;
  v144[0] = 0;
  v173 = 0;
  v178 = 0;
  v223 = -1;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v191 = v6;
  v182 = v6;
  v7 = SeCaptureSubjectContext(v183);
  if ( v246 )
  {
    if ( v246 != 1 )
    {
      v2 = -1073741811;
      goto LABEL_353;
    }
    v213 = 7;
    v211 = 7;
  }
  else
  {
    v7 = 2;
    v213 = 2;
    v211 = 2;
  }
  v8 = v183[0];
  if ( !v1 )
  {
    if ( !v183[0] )
    {
      v2 = -1073741732;
      v4 = 0;
LABEL_353:
      v16 = 0;
      v15 = 0;
      goto LABEL_354;
    }
    if ( (int)v183[1] < 1 )
    {
      v2 = -1073741659;
      v4 = 0;
      goto LABEL_353;
    }
  }
  v170 = (unsigned __int8)v254;
  if ( (_BYTE)v254 )
  {
    v153 = v249;
    if ( !v249 )
    {
      v2 = -1073741811;
      v166 = -1073741811;
      v202 = v252;
      v205 = v251;
      goto LABEL_24;
    }
    if ( v249 > 0x1000 )
    {
      v2 = -1073741811;
      v166 = -1073741811;
      v202 = v252;
      v205 = v251;
      goto LABEL_24;
    }
    v202 = v252;
    ProbeForWrite(v252, 4 * v249, 4);
    v205 = v251;
    v7 = ProbeForWrite(v251, 4 * v249, 4);
  }
  else
  {
    v202 = v252;
    v9 = v252;
    if ( (unsigned int)v252 >= MmUserProbeAddress )
      v9 = (int *)MmUserProbeAddress;
    *v9 = *v9;
    v205 = v251;
    v10 = v251;
    if ( (unsigned int)v251 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
    v153 = v249;
  }
  if ( (v250 & 3) != 0 )
    ExRaiseDatatypeMisalignment(v7);
  v11 = *(_DWORD *)(v250 + 4);
  v12 = *(_DWORD *)(v250 + 8);
  v13 = *(_DWORD *)(v250 + 12);
  v234[0] = *(_DWORD *)v250;
  v234[1] = v11;
  v234[2] = v12;
  v234[3] = v13;
  v6 = v191;
LABEL_24:
  if ( v2 < 0 )
    goto LABEL_36;
  if ( !v1 )
  {
LABEL_30:
    if ( !v8 )
      v8 = v184;
    v198 = (int)v8;
    if ( SeCheckAuditPrivilege(v183, v6) )
    {
LABEL_37:
      v17 = v244;
      if ( (v244 & 0xF0000000) != 0 )
      {
        v2 = -1073741594;
        v3 = v145;
        v4 = v147;
        v16 = v148;
        v15 = v152;
        goto LABEL_354;
      }
      v2 = SeCaptureSecurityDescriptor(v242, v191, 1, 0, &v179);
      if ( v2 < 0 )
      {
        v5 = 0;
        v3 = v145;
        v4 = v147;
        v16 = v148;
        v15 = v152;
        goto LABEL_354;
      }
      v5 = v179;
      if ( !v179 )
        goto LABEL_42;
      if ( (*(_WORD *)(v179 + 2) & 0x8000) != 0 )
      {
        v18 = *(_DWORD *)(v179 + 4);
        if ( !v18 )
          goto LABEL_42;
        v19 = v18 + v179;
      }
      else
      {
        v19 = *(_DWORD *)(v179 + 4);
      }
      if ( v19 )
      {
        if ( (*(_WORD *)(v179 + 2) & 0x8000) != 0 )
        {
          v20 = *(_DWORD *)(v179 + 8);
          if ( !v20 )
            goto LABEL_42;
          v21 = v20 + v179;
        }
        else
        {
          v21 = *(_DWORD *)(v179 + 8);
        }
        if ( v21 )
        {
          v228 = v253;
          v22 = v253;
          if ( (unsigned int)v253 >= MmUserProbeAddress )
            v22 = (_BYTE *)MmUserProbeAddress;
          *v22 = *v22;
          v2 = SepProbeAndCaptureString_U(v225, &v160);
          v166 = v2;
          if ( v2 >= 0 )
          {
            v2 = SepProbeAndCaptureString_U(v227, &v162);
            v166 = v2;
            if ( v2 >= 0 )
            {
              v2 = SepProbeAndCaptureString_U(v241, &v172);
              v166 = v2;
              v154 = v172;
            }
            v147 = v162;
          }
          v23 = v191;
          v15 = v152;
          if ( v2 < 0 )
          {
            v3 = v160;
            v4 = v147;
            v16 = v148;
            goto LABEL_354;
          }
          if ( v243 )
          {
            v2 = SeCaptureSid(v243, v191);
            if ( v2 < 0 )
            {
              v155 = 0;
              v3 = v160;
              v4 = v147;
              v16 = v148;
              v15 = v152;
              goto LABEL_354;
            }
            v155 = v171;
            v23 = v191;
          }
          v24 = SeCaptureObjectTypeList(v248, v153, v23, (int *)&v157);
          v2 = v24;
          if ( v24 >= 0 )
          {
            v2 = SepTrustLevelCheck(v24, v5, (int)v183, 0, 0, 1, &v223);
            if ( v2 >= 0 )
            {
              v2 = SepTrustToDiscretionary(&v223, v17);
              v166 = v2;
              if ( v2 < 0 )
              {
                v197 = 1;
                v144[0] = 1;
                goto LABEL_82;
              }
              v2 = SepMandatoryIntegrityCheck(v234, v5, 0, v8, 1, (int)v232);
              if ( v2 >= 0 )
              {
                v25 = SepMandatoryToDiscretionary(v232, v17);
                v2 = v25;
                v166 = v25;
                if ( (v25 < 0 || (v17 & 0x2000000) != 0) && (v8[44] & 0x4000) != 0 && v233 <= 0x2000 )
                {
                  v26 = 1;
                  v201 = 1;
                }
                else
                {
                  v26 = v201;
                }
                if ( v25 >= 0 || v26 )
                {
                  v2 = SePrivilegePolicyCheck((unsigned int *)va1, &v146, (int *)v183, 0, &v159, v191);
                  v166 = v2;
                  v17 = v244;
                  v174 = v146;
                  if ( !v244 )
                  {
                    if ( !v146 )
                    {
                      v148 = v159;
                      goto LABEL_82;
                    }
                    v177 = (int *)1;
                  }
                  v148 = v159;
                }
LABEL_82:
                SeLockSubjectContext(v183);
                if ( v2 < 0 && !v201 )
                {
                  v27 = 0;
                  v146 = 0;
                  v28 = 1;
                  v145 = 1;
                  v29 = v2;
                  v185 = v2;
                  if ( v170 )
                  {
                    v30 = v153;
                    v31 = (int *)ExAllocatePoolWithTag(1, 8 * v153, 1632068947);
                    v165 = v31;
                    v199 = v31;
                    if ( !v31 )
                    {
                      SeUnlockSubjectContext(v183);
                      v2 = -1073741670;
                      v3 = v160;
                      v150 = v157;
                      v4 = v147;
                      v16 = v148;
                      v15 = v152;
                      goto LABEL_354;
                    }
                    v210 = 1;
                    v149 = 1;
                    v177 = &v31[v30];
                    v32 = 0;
                    v33 = v177;
                    while ( v32 < v30 )
                    {
                      v33[-v30] = v187;
                      *v33++ = v2;
                      ++v32;
                    }
                    v150 = v157;
                    v27 = 0;
                    v28 = 1;
                    v34 = v197;
                  }
                  else
                  {
                    v165 = &v187;
                    v199 = &v187;
                    v177 = &v185;
                    v150 = v157;
                    v34 = v197;
                  }
                  goto LABEL_240;
                }
                v35 = SepTokenIsOwner((int)v8, v5);
                v36 = v35;
                v186 = v35;
                v37 = (unsigned __int8)SepRmEnforceCap;
                __dmb(0xBu);
                v5 = v179;
                if ( !v37 )
                  goto LABEL_110;
                if ( (*(_WORD *)(v179 + 2) & 0x10) != 0 )
                {
                  if ( (unsigned int)KeGetCurrentIrql(v35) < 2 )
                  {
                    if ( (*(_WORD *)(v5 + 2) & 0x10) != 0 )
                    {
                      if ( (*(_WORD *)(v5 + 2) & 0x8000) != 0 )
                      {
                        v38 = *(_DWORD *)(v5 + 12);
                        if ( !v38 )
                        {
                          v204 = 0;
                          goto LABEL_110;
                        }
                        v39 = v38 + v5;
                      }
                      else
                      {
                        v39 = *(_DWORD *)(v5 + 12);
                      }
                      v204 = v39;
                      if ( v39 )
                      {
                        v40 = SepGetScopedPolicySid(v39);
                        if ( v40 )
                        {
                          if ( SepRmReferenceFindCap((unsigned __int16 *)v40, (int *)&v163) >= 0 )
                          {
                            v41 = v163;
                          }
                          else
                          {
                            v41 = SepRmDefaultCap;
                            v163 = SepRmDefaultCap;
                          }
                          v2 = 0;
                          v166 = 0;
                          v212 = 1;
                          v168 = 1;
                          goto LABEL_111;
                        }
                      }
                    }
                    else
                    {
                      v204 = 0;
                    }
LABEL_110:
                    v2 = v166;
                    v41 = v163;
LABEL_111:
                    v161 = v41;
                    v36 = v186;
                    goto LABEL_112;
                  }
                  v36 = v186;
                }
                v2 = v166;
                v161 = v163;
LABEL_112:
                v17 = v244;
                if ( (v244 & 0x2060000) != 0
                  && v36
                  && ((*(_WORD *)(v5 + 2) & 4) != 0 ? ((*(_WORD *)(v5 + 2) & 0x8000) == 0 ? (v42 = *(_DWORD *)(v5 + 16)) : (v43 = *(_DWORD *)(v5 + 16)) != 0 ? (v42 = v43 + v5) : (v42 = 0)) : (v42 = 0),
                      !RtlOwnerAcesPresent(v42)) )
                {
                  if ( (v17 & 0x2000000) != 0 )
                  {
                    v44 = v146 | 0x60000;
                    v175 = 393216;
                  }
                  else
                  {
                    v175 = v17 & 0x60000;
                    v44 = v17 & 0x60000 | v146;
                  }
                  v146 = v44;
                  v17 &= 0xFFF9FFFF;
                  v244 = v17;
                }
                else
                {
                  v44 = v146;
                }
                v174 = v44;
                if ( !v17 && (!v212 || v177) && ((v8[44] & 0x2000) != 0 || !v175) )
                {
                  v187 = v44;
                  if ( v44 )
                  {
                    v27 = 1;
                    v28 = 0;
                    v29 = 0;
                  }
                  else
                  {
                    v27 = 0;
                    v28 = 1;
                    v29 = -1073741790;
                  }
                  v185 = v29;
                  v145 = v28;
                  v146 = v27;
                  if ( !v170 )
                  {
                    v165 = &v187;
                    v199 = &v187;
                    v177 = &v185;
                    v147 = v162;
                    v154 = v172;
                    v155 = v171;
                    v150 = v157;
                    v148 = v159;
                    v208 = v142;
                    v200 = v143;
                    v152 = v176;
                    v189 = v156;
                    v151 = v158;
                    v173 = v178;
                    goto LABEL_239;
                  }
                  v45 = (int *)ExAllocatePoolWithTag(1, 8 * v153, 1632068947);
                  v165 = v45;
                  v199 = v45;
                  if ( v45 )
                  {
                    v210 = 1;
                    v149 = 1;
                    v46 = v153;
                    v177 = &v45[v153];
                    v47 = 0;
                    v48 = v177;
                    while ( v47 < v46 )
                    {
                      v48[-v46] = v187;
                      *v48++ = v29;
                      ++v47;
                    }
                    v147 = v162;
                    v154 = v172;
                    v155 = v171;
                    v150 = v157;
                    v148 = v159;
                    v208 = v142;
                    v200 = v143;
                    v152 = v176;
                    v189 = v156;
                    v151 = v158;
                    v173 = v178;
                    v27 = v146;
                    v28 = v145;
                    goto LABEL_239;
                  }
                  goto LABEL_137;
                }
                if ( v170 )
                {
                  v49 = v153;
                  v50 = (int *)ExAllocatePoolWithTag(1, 8 * v153, 1632068947);
                  v165 = v50;
                  v199 = v50;
                  if ( !v50 )
                  {
LABEL_137:
                    v2 = -1073741670;
                    SeUnlockSubjectContext(v183);
                    v154 = v172;
LABEL_138:
                    v155 = v171;
                    v15 = v176;
                    v16 = v159;
                    v150 = v157;
                    v4 = v162;
                    v3 = v160;
                    v151 = v158;
                    v173 = v178;
                    goto LABEL_354;
                  }
                  v210 = 1;
                  v149 = 1;
                  v51 = &v50[v49];
                }
                else
                {
                  v50 = &v187;
                  v165 = &v187;
                  v199 = &v187;
                  v51 = &v185;
                }
                v177 = v51;
                v229[0] = v175;
                SepAccessCheck(
                  v5,
                  v171,
                  v184,
                  v8,
                  v17,
                  v157,
                  v153,
                  v234,
                  v174,
                  v191,
                  (unsigned int *)v50,
                  0,
                  v51,
                  v170,
                  v186,
                  (int)v229,
                  &v158,
                  v164,
                  (char *)&v167);
                v52 = (unsigned __int8)SepRmEnforceCap;
                __dmb(0xBu);
                if ( !v52 || *v51 < 0 || !v212 )
                {
                  v17 = v244;
                  v2 = v166;
                  v155 = v171;
                  v150 = v157;
                  v174 = v146;
                  v161 = v163;
                  v151 = v158;
                  v173 = v178;
                  v146 = (unsigned __int8)v164[0];
                  v145 = v167;
                  goto LABEL_218;
                }
                v53 = v153;
                if ( v170 )
                {
                  v54 = (unsigned int *)ExAllocatePoolWithTag(1, 8 * v153, 1632068947);
                  v188 = v54;
                  v219 = (int *)v54;
                  if ( !v54 )
                  {
                    SeUnlockSubjectContext(v183);
                    SeReleaseSubjectContext((int)v183);
                    v2 = -1073741670;
                    v154 = v172;
                    v5 = v179;
                    v161 = v163;
                    goto LABEL_138;
                  }
                  v55 = (int *)&v54[v53];
                }
                else
                {
                  v188 = (unsigned int *)&v226;
                  v219 = &v226;
                  v55 = &v224;
                }
                v203 = v55;
                v150 = v157;
                if ( v53 )
                {
                  v2 = SepCopyObjectTypeList((int)v157, v53, (int *)&v178);
                  if ( v2 < 0 )
                  {
                    v3 = v160;
                    v4 = v162;
                    v154 = v172;
                    v5 = v179;
                    v155 = v171;
                    v16 = v159;
                    v15 = v176;
                    v161 = v163;
                    v151 = v158;
                    v173 = v178;
                    goto LABEL_354;
                  }
                }
                else
                {
                  v2 = v166;
                }
                v198 = 0;
                v56 = 0;
                v161 = v163;
                v57 = (int)v163;
                v17 = v244;
                v155 = v171;
                v58 = v146;
                v174 = v146;
                v151 = v158;
                v173 = v178;
                v59 = v226;
                v197 = v226;
                v60 = v158;
                while ( 1 )
                {
                  v218 = v57;
                  v220 = v56;
                  if ( v56 >= v161[8] )
                    break;
                  v61 = *(_DWORD *)(v57 + 36);
                  v175 = v61;
                  if ( *(_DWORD *)(v61 + 12) )
                  {
                    if ( v60 )
                    {
                      v63 = v151;
                    }
                    else
                    {
                      v62 = AuthzBasepInitializeResourceClaimsFromSacl(v204, (int)&v158);
                      v63 = v158;
                      v61 = v175;
                      v151 = v158;
                      if ( v62 < 0 )
                        v198 = 1;
                    }
                    v64 = (_DWORD *)v8[159];
                    if ( v64 )
                      v65 = v64[75];
                    else
                      v65 = 0;
                    if ( v64 )
                      v66 = v64[73];
                    else
                      v66 = 0;
                    if ( v64 )
                      v67 = v64[74];
                    else
                      v67 = 0;
                    if ( v64 )
                      v68 = v64[72];
                    else
                      v68 = 0;
                    v69 = AuthzBasepEvaluateAceCondition(
                            (int)v8,
                            v8[119],
                            v63,
                            v68,
                            v67,
                            v66,
                            v65,
                            *(_DWORD **)(v61 + 12),
                            *(_DWORD *)(v61 + 8),
                            1u,
                            0,
                            &v211);
                    v2 = v69;
                    v70 = v211;
                    if ( v211 != 1 )
                    {
                      if ( v69 < 0 )
                        goto LABEL_214;
                      if ( SeTokenIsRestricted((int)v8) )
                      {
                        v71 = (_DWORD *)v8[159];
                        if ( v71 )
                          v72 = v71[75];
                        else
                          v72 = 0;
                        if ( v71 )
                          v73 = v71[73];
                        else
                          v73 = 0;
                        if ( v71 )
                          v74 = v71[74];
                        else
                          v74 = 0;
                        if ( v71 )
                          v75 = v71[72];
                        else
                          v75 = 0;
                        v2 = AuthzBasepEvaluateAceCondition(
                               (int)v8,
                               v8[119],
                               v151,
                               v75,
                               v74,
                               v73,
                               v72,
                               *(_DWORD **)(v175 + 12),
                               *(_DWORD *)(v175 + 8),
                               1u,
                               1u,
                               &v211);
                        if ( v2 < 0 )
                        {
LABEL_214:
                          v3 = v160;
                          v4 = v162;
                          v154 = v172;
                          v5 = v179;
                          v16 = v159;
                          v15 = v176;
                          goto LABEL_354;
                        }
                        v70 = v211;
                      }
                      if ( !v198 && v70 != 1 )
                      {
                        v59 = v197;
                        v60 = v151;
                        goto LABEL_213;
                      }
                    }
                    v61 = v175;
                    v58 = v174;
                  }
                  v76 = *(_DWORD *)(v61 + 24);
                  if ( (v76 & 1) == 0 )
                  {
                    v175 = v58;
                    goto LABEL_204;
                  }
                  if ( (v17 & 0x2000000) != 0 )
                  {
                    v76 = 0;
                    v175 = 0;
LABEL_204:
                    v77 = v17;
                    goto LABEL_205;
                  }
                  v77 = v58 | v17;
                  v76 = 0;
                  v175 = 0;
LABEL_205:
                  v2 = SepBuildCapeSecurityDescriptor((int)&v235, *(unsigned __int8 **)(v61 + 16), v204, v76);
                  if ( v2 < 0 )
                    goto LABEL_214;
                  SepAccessCheck(
                    (int)&v235,
                    v155,
                    v184,
                    v183[0],
                    v77,
                    v173,
                    v153,
                    v234,
                    v175,
                    v191,
                    v188,
                    0,
                    v203,
                    v170,
                    v186,
                    (int)v229,
                    &v158,
                    v196,
                    v195);
                  if ( v207 )
                    v59 = v197 & *v188;
                  else
                    v59 = *v188;
                  v197 = v59;
                  if ( v173 )
                  {
                    SepMergeObjectTypeListAccesses((int)v150, (int)v173, v153);
                    v59 = v197;
                  }
                  v207 = 1;
                  v60 = v158;
                  v151 = v158;
LABEL_213:
                  v56 = v220 + 1;
                  v57 = v218 + 4;
                  v58 = v174;
                }
                v146 = (unsigned __int8)v196[0];
                v145 = (unsigned __int8)v195[0];
                *v188 &= v59;
                if ( !v59 )
                {
                  *v203 = -1073741790;
                  v146 = 0;
                  v145 = 1;
                }
LABEL_218:
                if ( (v17 & 0x2000000) != 0 )
                {
                  if ( !v201 || !*(_WORD *)((char *)&v231 + 1) )
                  {
                    if ( v170 )
                      v78 = v153;
                    else
                      v78 = 0;
                    SepConstrainByMandatory((int)v232, v17, v165, (int)v177, 0, v78);
                  }
LABEL_231:
                  v28 = v145;
                  v27 = v146;
                  v29 = v185;
LABEL_232:
                  v80 = v170;
                }
                else
                {
                  if ( !v201 || *(_WORD *)((char *)&v231 + 1) )
                    goto LABEL_231;
                  v27 = 0;
                  v146 = 0;
                  v28 = 1;
                  v145 = 1;
                  v79 = 0;
                  v187 = 0;
                  v29 = -1073741790;
                  v185 = -1073741790;
                  v80 = v170;
                  if ( v170 )
                  {
                    v81 = 0;
                    v82 = v177;
                    while ( 1 )
                    {
                      v27 = v146;
                      v198 = v81;
                      v28 = v145;
                      if ( v81 >= v153 )
                        break;
                      *(int *)((char *)v82 + (char *)v165 - (char *)v177) = v79;
                      *v82++ = v29;
                      v81 = v198 + 1;
                      v79 = v187;
                      v29 = v185;
                    }
                    goto LABEL_232;
                  }
                }
                if ( (v17 & 0x2000000) != 0 )
                {
                  if ( v80 )
                    v83 = v153;
                  else
                    v83 = 0;
                  SepConstrainByTrust(&v223, v17, (int)v165, (int)v177, 0, v83, v144);
                  v29 = v185;
                  v27 = v146;
                  v28 = v145;
                }
                v147 = v162;
                v154 = v172;
                v148 = v159;
                v208 = v142;
                v200 = v143;
                v152 = v176;
                v189 = v156;
                v5 = v179;
LABEL_239:
                v34 = (unsigned __int8)v144[0];
LABEL_240:
                v84 = v184;
                v85 = v183[0];
                if ( v8 && (v34 || !v230 && (v8[44] & 0x4000) != 0 && v2 >= 0 && (v29 < 0 || HIBYTE(v231))) )
                {
                  v86 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                  --*(_WORD *)(v86 + 308);
                  ExAcquireResourceSharedLite(v8[12], 1);
                  v90 = SepLocateTokenTrustLevel((int *)v183, v87, v88, v89);
                  SeLogAccessFailure((int)v8, v91, v174 | v17, v90);
                  v92 = ExReleaseResourceLite(v8[12]);
                  v93 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                  v94 = *(_WORD *)(v93 + 0x134) + 1;
                  *(_WORD *)(v93 + 308) = v94;
                  if ( !v94 && *(_DWORD *)(v93 + 100) != v93 + 100 && !*(_WORD *)(v93 + 310) )
                    KiCheckForKernelApcDelivery(v92);
                  v84 = v184;
                  v85 = v183[0];
                  v28 = v145;
                  v27 = v146;
                }
                if ( v221 )
                  goto LABEL_321;
                if ( v213 == 2 )
                {
                  v95 = v147;
                  if ( v27 )
                  {
                    v214 = SepAdtAuditObjectAccessWithContext(0, v147, v27, 0, v183, 0, &v156);
                    v189 = v156;
                    v84 = v184;
                    v85 = v183[0];
                    v28 = v145;
                  }
                  if ( v28 )
                  {
                    v96 = SepAdtAuditObjectAccessWithContext(0, v95, 0, v28, v183, 0, &v156);
                    v206 = v96;
                    v189 = v156;
                    v84 = v184;
                    v85 = v183[0];
LABEL_264:
                    v97 = v214;
                    if ( v214 || v96 )
                    {
                      if ( v85 )
                        v98 = v85;
                      else
                        v98 = v84;
                      v99 = *(_WORD *)(v5 + 2);
                      if ( (v99 & 0x10) != 0 )
                      {
                        if ( (*(_WORD *)(v5 + 2) & 0x8000) != 0 )
                        {
                          v101 = *(_DWORD *)(v5 + 12);
                          if ( v101 )
                            v100 = v101 + v5;
                          else
                            v100 = 0;
                        }
                        else
                        {
                          v100 = *(_DWORD *)(v5 + 12);
                        }
                      }
                      else
                      {
                        v100 = 0;
                      }
                      if ( (v99 & 0x10) != 0 )
                      {
                        if ( (*(_WORD *)(v5 + 2) & 0x8000) != 0 )
                        {
                          v103 = *(_DWORD *)(v5 + 12);
                          if ( v103 )
                            v102 = v103 + v5;
                          else
                            v102 = 0;
                        }
                        else
                        {
                          v102 = *(_DWORD *)(v5 + 12);
                        }
                      }
                      else
                      {
                        v102 = 0;
                      }
                      v104 = (int)v177;
                      SepExamineSaclEx(
                        v102,
                        v100,
                        v98,
                        v174 | v17,
                        v150,
                        v153,
                        v170,
                        v177,
                        v165,
                        v155,
                        v186,
                        &v142,
                        &v143);
                      v105 = v184;
                      if ( v183[0] )
                        v106 = v183[0];
                      else
                        v106 = v184;
                      if ( (*(_WORD *)(v5 + 2) & 0x10) != 0 )
                      {
                        if ( (*(_WORD *)(v5 + 2) & 0x8000) != 0 )
                        {
                          v108 = *(_DWORD *)(v5 + 12);
                          if ( v108 )
                            v107 = v108 + v5;
                          else
                            v107 = 0;
                        }
                        else
                        {
                          v107 = *(_DWORD *)(v5 + 12);
                        }
                      }
                      else
                      {
                        v107 = 0;
                      }
                      v138 = v104;
                      v95 = v147;
                      SepExamineGlobalSaclEx(
                        v147,
                        v107,
                        (int)v106,
                        v174 | v17,
                        (int)v150,
                        v153,
                        v170,
                        v138,
                        (int)v165,
                        v155,
                        v186,
                        &v142,
                        &v143);
                      v109 = v142;
                      v110 = v143;
                      v200 = v143;
                      v85 = v183[0];
                      v97 = v214;
                      v96 = v206;
                    }
                    else
                    {
                      v105 = v184;
                      v109 = v208;
                      v110 = v200;
                    }
                    if ( v109 || v110 )
                    {
                      v114 = v146;
                      if ( v146 )
                      {
                        v209 = 1;
                        v114 = v146;
                      }
                      if ( v109 && v97 )
                      {
                        v115 = v165;
                        if ( v170 )
                          v116 = v165;
                        else
                          v116 = 0;
                        v117 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
                        if ( v114 )
                          va_copy(v118, varg_r1a);
                        else
                          v118 = 0;
                        v141 = *(_DWORD *)(v117 + 176);
                        v140 = *v115;
                        v139 = *v115;
                        v119 = v160;
                        v145 = v160;
                        SepAdtOpenObjectAuditAlarm(
                          v189,
                          v160,
                          v118,
                          v147,
                          v154,
                          v5,
                          v85,
                          v105,
                          v139,
                          v140,
                          v148,
                          1,
                          v141,
                          v213,
                          v150,
                          v153,
                          v116,
                          0,
                          0);
                        v114 = v146;
                        v85 = v183[0];
                        v96 = v206;
                      }
                      else
                      {
                        v119 = v160;
                        v145 = v160;
                      }
                      if ( v200 && v96 )
                      {
                        if ( v170 )
                          v120 = v165;
                        else
                          v120 = 0;
                        v121 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
                        if ( v114 )
                          va_copy(v122, varg_r1a);
                        else
                          v122 = 0;
                        SepAdtOpenObjectAuditAlarm(
                          v189,
                          v119,
                          v122,
                          v147,
                          v154,
                          v5,
                          v85,
                          v105,
                          v17,
                          v17,
                          v148,
                          0,
                          *(_DWORD *)(v121 + 176),
                          v213,
                          v150,
                          v153,
                          v120,
                          0,
                          0);
                      }
                    }
                    else
                    {
                      v111 = v148;
                      if ( v148 )
                      {
                        v112 = v146;
                        if ( v146 )
                        {
                          v137 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176);
                          v145 = v160;
                          SepAdtPrivilegeObjectAuditAlarm(
                            v160,
                            v95,
                            v154,
                            (int *)varg_r1a,
                            v85,
                            v105,
                            v137,
                            v17,
                            v111,
                            v112);
                          v113 = 0;
                          goto LABEL_323;
                        }
                      }
LABEL_321:
                      v145 = v160;
                    }
                    v113 = v209;
LABEL_323:
                    SeUnlockSubjectContext(v183);
                    v123 = v202;
                    if ( v170 )
                    {
                      v124 = (int)v177;
                      v4 = v147;
                      if ( !v177 )
                      {
                        v125 = 0;
                        v126 = v187;
                        while ( 1 )
                        {
                          if ( v125 >= v153 )
                          {
                            v3 = v145;
                            goto LABEL_347;
                          }
                          v123[v125] = v29;
                          v127 = v205;
                          v205[v125] = v126;
                          v128 = (unsigned __int8)SepRmEnforceCap;
                          __dmb(0xBu);
                          if ( v128 && v207 )
                          {
                            v29 = v185;
                            if ( v185 >= 0 )
                            {
                              v123[v125] = v185;
                              v126 = v187;
                              v127[v125] &= v187;
                              goto LABEL_333;
                            }
                          }
                          else
                          {
                            v29 = v185;
                          }
                          v126 = v187;
LABEL_333:
                          ++v125;
                          v145 = v160;
                          v4 = v162;
                          v154 = v172;
                          v5 = v179;
                          v155 = v171;
                          v150 = v157;
                          v148 = v159;
                          v152 = v176;
                          v161 = v163;
                          v151 = v158;
                          v173 = v178;
                        }
                      }
                      v129 = 0;
                      v3 = v145;
                      while ( v129 < v153 )
                      {
                        v123[v129] = *(_DWORD *)(v124 + 4 * v129);
                        v130 = v205;
                        v205[v129] = v165[v129];
                        v131 = (unsigned __int8)SepRmEnforceCap;
                        __dmb(0xBu);
                        if ( v131 && v207 && *(int *)(v124 + 4 * v129) >= 0 )
                        {
                          v123[v129] = v203[v129];
                          v130[v129] &= v188[v129];
                          v124 = (int)v177;
                        }
                        ++v129;
                        v3 = v160;
                        v4 = v162;
                        v154 = v172;
                        v5 = v179;
                        v155 = v171;
                        v150 = v157;
                        v148 = v159;
                        v152 = v176;
                        v161 = v163;
                        v151 = v158;
                        v173 = v178;
                      }
LABEL_347:
                      v16 = v148;
                    }
                    else
                    {
                      *v202 = v29;
                      v132 = v205;
                      *v205 = v187;
                      v133 = (unsigned __int8)SepRmEnforceCap;
                      __dmb(0xBu);
                      if ( !v133 || !v207 || v185 < 0 )
                      {
                        v3 = v160;
                        v4 = v162;
                        v154 = v172;
                        v5 = v179;
                        v155 = v171;
                        v150 = v157;
                        v16 = v159;
                        v15 = v176;
                        v161 = v163;
                        v151 = v158;
                        v173 = v178;
LABEL_349:
                        *v228 = v113;
                        v2 = 0;
                        v166 = 0;
                        goto LABEL_354;
                      }
                      *v123 = *v203;
                      *v132 &= *v188;
                      v3 = v160;
                      v4 = v162;
                      v154 = v172;
                      v5 = v179;
                      v155 = v171;
                      v150 = v157;
                      v16 = v159;
                      v152 = v176;
                      v161 = v163;
                      v151 = v158;
                      v173 = v178;
                    }
                    v15 = v152;
                    goto LABEL_349;
                  }
                }
                else
                {
                  if ( v27 )
                  {
                    v189 = 150;
                    v214 = SepAdtAuditThisEventWithContext(150, v27, 0, v183);
                    v84 = v184;
                    v85 = v183[0];
                    v28 = v145;
                  }
                  if ( v28 )
                  {
                    v189 = 150;
                    v96 = SepAdtAuditThisEventWithContext(150, 0, v28, v183);
                    v206 = v96;
                    v84 = v184;
                    v85 = v183[0];
                    v95 = v147;
                    goto LABEL_264;
                  }
                  v95 = v147;
                }
                v96 = v206;
                goto LABEL_264;
              }
            }
          }
          v3 = v160;
          v150 = v157;
          v4 = v147;
          v16 = v148;
          v15 = v152;
          goto LABEL_354;
        }
      }
LABEL_42:
      v2 = -1073741703;
      v3 = v145;
      v4 = v147;
      v16 = v148;
      v15 = v152;
      goto LABEL_354;
    }
    if ( (v247 & 1) != 0 )
    {
      v221 = 1;
      v181 = 1;
      goto LABEL_37;
    }
    v2 = -1073741727;
LABEL_36:
    v3 = v145;
    v4 = v147;
    v16 = v148;
    v15 = v152;
    goto LABEL_354;
  }
  v14 = ObReferenceObjectByHandle(*v1, 8, SeTokenObjectType, v6, &v198);
  v2 = v14;
  v152 = v198;
  v176 = v198;
  if ( v14 >= 0 )
  {
    v215 = v8;
    v222 = v8;
    v8 = (int *)v198;
    v183[0] = (int *)v198;
    v217 = 1;
    v169 = 1;
    goto LABEL_30;
  }
  v15 = 0;
  v3 = v145;
  v4 = v147;
  v16 = v148;
  if ( v14 != -1073741816 )
    v216 = 1;
LABEL_354:
  if ( v217 )
  {
    ObfDereferenceObject(v15);
    v183[0] = v215;
  }
  if ( v16 )
    ExFreePoolWithTag((unsigned int)v16);
  SeReleaseSubjectContext((int)v183);
  v134 = v191;
  SeReleaseSecurityDescriptor(v5, v191, 0);
  if ( v3 )
    RtlpSysVolFree(v3);
  if ( v4 )
    RtlpSysVolFree(v4);
  if ( v154 )
    RtlpSysVolFree(v154);
  if ( v155 )
    SeReleaseSid(v155, v134, 1);
  if ( v150 )
    SeFreeCapturedObjectTypeList((int)v150);
  if ( v210 )
  {
    if ( v165 )
      ExFreePoolWithTag((unsigned int)v165);
    if ( v188 )
      ExFreePoolWithTag((unsigned int)v188);
  }
  if ( v212 )
    SepRmDereferenceCap((int)v161, v135);
  if ( v173 )
    ExFreePoolWithTag((unsigned int)v173);
  SepFreeResourceInfo(v151);
  if ( v2 == -1073741670 || v216 )
    SepAuditFailed(v2);
  return v2;
}
