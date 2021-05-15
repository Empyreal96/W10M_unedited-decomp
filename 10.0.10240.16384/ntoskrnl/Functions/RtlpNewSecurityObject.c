// RtlpNewSecurityObject 
 
int __fastcall RtlpNewSecurityObject(int a1, int a2, int *a3, int a4, int a5, unsigned __int8 a6, int a7, int *a8, int a9, int a10)
{
  unsigned __int16 *v10; // r1
  unsigned __int16 *v11; // r7
  int v12; // r10
  int result; // r0
  __int16 v14; // r3
  int v15; // r3
  _DWORD *v16; // r0
  _DWORD *v17; // r1
  int v18; // r4
  int v19; // r8
  int v20; // r6
  int v21; // r5
  int v22; // r9
  int *v23; // r0
  int v24; // r1
  int v25; // r2
  int *v26; // r3
  int v27; // r7
  int v28; // r0
  int v29; // r10
  int v30; // r3
  int v31; // r3
  int v32; // r3
  int v33; // lr
  int v34; // r0
  int v35; // r3
  unsigned int v36; // r2
  unsigned __int16 *v37; // r8
  int v38; // r8
  unsigned int v39; // r2
  int *v40; // r9
  int v41; // r0
  unsigned int v42; // r1
  __int16 v43; // r3
  __int16 v44; // r2
  unsigned __int16 *v45; // r3
  int v46; // r6
  int v47; // lr
  int v48; // r3
  int v49; // r3
  int v50; // lr
  int v51; // r7
  int v52; // r6
  int v53; // r5
  int v54; // r4
  int v55; // r0
  int v56; // r0
  int v57; // r4
  int v58; // r1
  __int16 v59; // r2
  int v60; // r6
  int v61; // r3
  __int16 v62; // r3
  int v63; // lr
  int v64; // r7
  int v65; // r5
  int v66; // r4
  int v67; // r0
  int v68; // r3
  int v69; // r5
  int v70; // r0
  int v71; // r8
  __int16 v72; // r2
  unsigned __int8 *v73; // r6
  int v74; // r7
  int v75; // r0
  unsigned __int8 *v76; // r0
  int v77; // r2
  unsigned __int8 *v78; // r4
  int v79; // r9
  int v80; // r6
  int v81; // r7
  int v82; // r3
  int v83; // r2
  int v84; // r2
  char *v85; // r2
  int v86; // r2
  int v87; // r0
  int v88; // r3
  unsigned __int8 *v89; // r5
  int v90; // r0
  __int16 v91; // r6
  int v92; // r2
  int v93; // r8
  int v94; // r4
  int v95; // r1
  int v96; // r2
  unsigned __int8 *v97; // r0
  unsigned __int16 *v98; // r1
  __int16 v99; // r0
  int v100; // r5
  int v101; // r4
  int v102; // r0
  int v103; // r5
  __int16 v104; // r2
  int v105; // r6
  int v106; // r5
  int v107; // r4
  BOOL v108; // r3
  char v109; // lr
  unsigned int v110; // r7
  unsigned int v111; // r8
  unsigned int v112; // r6
  unsigned int v113; // r9
  unsigned int v114; // r2
  int v115; // r10
  unsigned int v116; // r5
  _BYTE *v117; // r0
  _BYTE *v118; // r4
  __int16 v119; // r2
  int v120; // r4
  int v121; // r0
  unsigned int v122; // r1
  unsigned int v123; // r3
  int v124; // r0
  unsigned int v125; // r3
  int v126; // r4
  unsigned __int8 *v127; // r7
  unsigned int v128; // r6
  int v129; // r8
  unsigned int v130; // r9
  int v131; // r0
  unsigned __int8 *v132; // r0
  __int16 v133; // r3
  int v134; // r0
  int v135; // r1
  int v136; // r2
  int v137; // r3
  int v138; // r3
  int v139; // r1
  int v140; // r3
  int v141; // r3
  int v142; // r3
  int v143; // r3
  int v144; // r3
  int v145; // r3
  int v146; // r3
  unsigned int v147; // r2
  int v148; // r0
  unsigned int v149; // r1
  int v150; // r3
  unsigned int v151; // r2
  int v152; // r3
  int v153; // r3
  int v154; // r3
  int v155; // r3
  int v156; // r0
  int v157; // r1
  int v158; // r2
  int v159; // r3
  int v160; // r3
  int v161; // r0
  int v162; // r3
  unsigned __int16 *v163; // r3
  int v164; // r3
  int v165; // r3
  int v166; // r3
  int v167; // r0
  int v168; // r3
  unsigned __int8 *v169; // r0
  int v170; // r6
  int v171; // r5
  __int16 v172; // r3
  int v173; // r5
  int v174; // r4
  int v175; // r0
  int v176; // r1
  int *v177; // r7
  int v178; // r4
  int *v179; // r7
  int v180; // r4
  int v181; // r0
  int v182; // [sp+38h] [bp-200h] BYREF
  unsigned __int8 *v183; // [sp+3Ch] [bp-1FCh] BYREF
  unsigned int v184; // [sp+40h] [bp-1F8h]
  char v185[4]; // [sp+44h] [bp-1F4h] BYREF
  int v186; // [sp+48h] [bp-1F0h]
  unsigned __int8 v187; // [sp+4Ch] [bp-1ECh] BYREF
  char v188[3]; // [sp+4Dh] [bp-1EBh] BYREF
  int v189; // [sp+50h] [bp-1E8h]
  unsigned __int16 *v190; // [sp+54h] [bp-1E4h]
  int v191; // [sp+58h] [bp-1E0h]
  int v192; // [sp+5Ch] [bp-1DCh] BYREF
  int v193; // [sp+60h] [bp-1D8h]
  int v194; // [sp+64h] [bp-1D4h]
  char v195[4]; // [sp+68h] [bp-1D0h] BYREF
  int *v196; // [sp+6Ch] [bp-1CCh]
  int v197; // [sp+70h] [bp-1C8h]
  unsigned __int8 *v198; // [sp+74h] [bp-1C4h]
  int v199; // [sp+78h] [bp-1C0h]
  unsigned __int16 *v200; // [sp+7Ch] [bp-1BCh]
  int v201; // [sp+80h] [bp-1B8h]
  int v202; // [sp+84h] [bp-1B4h] BYREF
  char v203[4]; // [sp+88h] [bp-1B0h] BYREF
  int v204; // [sp+8Ch] [bp-1ACh]
  char v205[4]; // [sp+90h] [bp-1A8h] BYREF
  int v206; // [sp+94h] [bp-1A4h] BYREF
  unsigned int v207; // [sp+98h] [bp-1A0h] BYREF
  int v208; // [sp+9Ch] [bp-19Ch]
  int v209; // [sp+A0h] [bp-198h]
  unsigned __int16 *v210; // [sp+A4h] [bp-194h]
  int v211; // [sp+A8h] [bp-190h]
  unsigned __int16 *v212; // [sp+ACh] [bp-18Ch]
  unsigned __int16 *v213; // [sp+B0h] [bp-188h]
  int v214; // [sp+B4h] [bp-184h]
  unsigned int v215; // [sp+B8h] [bp-180h] BYREF
  unsigned __int8 *v216; // [sp+BCh] [bp-17Ch]
  int v217; // [sp+C0h] [bp-178h]
  int v218; // [sp+C4h] [bp-174h] BYREF
  int v219; // [sp+C8h] [bp-170h]
  int v220; // [sp+CCh] [bp-16Ch]
  int v221; // [sp+D0h] [bp-168h]
  int v222; // [sp+D4h] [bp-164h]
  unsigned __int8 *v223; // [sp+D8h] [bp-160h] BYREF
  int v224; // [sp+DCh] [bp-15Ch]
  char *v225; // [sp+E0h] [bp-158h]
  int v226; // [sp+E4h] [bp-154h]
  int v227; // [sp+E8h] [bp-150h]
  int v228; // [sp+ECh] [bp-14Ch]
  unsigned __int8 *v229; // [sp+F0h] [bp-148h] BYREF
  int v230; // [sp+F4h] [bp-144h] BYREF
  int v231; // [sp+F8h] [bp-140h]
  int v232; // [sp+FCh] [bp-13Ch]
  int v233; // [sp+100h] [bp-138h] BYREF
  int v234; // [sp+104h] [bp-134h]
  BOOL v235; // [sp+108h] [bp-130h]
  int *v236; // [sp+10Ch] [bp-12Ch]
  int v237; // [sp+128h] [bp-110h] BYREF
  int v238; // [sp+12Ch] [bp-10Ch]
  __int64 v239; // [sp+130h] [bp-108h]
  int v240; // [sp+138h] [bp-100h]
  char v241[2]; // [sp+140h] [bp-F8h] BYREF
  __int16 v242; // [sp+142h] [bp-F6h]
  __int16 v243; // [sp+144h] [bp-F4h]
  __int16 v244; // [sp+146h] [bp-F2h]
  char v245[120]; // [sp+1C0h] [bp-78h] BYREF

  v214 = a4;
  v201 = a1;
  v199 = a9;
  v222 = a10;
  v189 = 0;
  v202 = 0;
  v198 = 0;
  v183 = 0;
  v184 = 0;
  v217 = 0;
  v227 = 0;
  v234 = 0;
  v215 = 0;
  v207 = 0;
  v219 = 0;
  v220 = 0;
  v205[0] = 0;
  v230 = 0;
  v231 = 0;
  v224 = 0;
  v188[0] = 0;
  v212 = 0;
  v200 = 0;
  v204 = 0;
  v186 = 0x8000;
  v216 = 0;
  v213 = 0;
  v225 = v241;
  v236 = a3;
  v194 = a2;
  v10 = 0;
  v11 = 0;
  v196 = a8;
  v197 = 0;
  v210 = 0;
  v211 = 0;
  v223 = 0;
  v228 = 0;
  v229 = 0;
  v208 = 0;
  v209 = 0;
  v233 = 0;
  v187 = 0;
  v203[0] = 0;
  v185[0] = 0;
  v12 = 0;
  v206 = 0;
  v182 = 0;
  v195[0] = 1;
  v221 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !v194 )
    return sub_7FAABC();
  v218 = 1;
  v14 = *(_WORD *)(v194 + 2);
  v191 = (v14 & 0x80) != 0;
  v235 = (v14 & 0x40) != 0;
  if ( a8 || (v14 & 0x80) != 0 )
  {
    v15 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v15 & 0xFFFFFFC0) + 0x134);
    ExAcquireResourceSharedLite(*(_DWORD *)(a8[2] + 48), 1);
    if ( !*a8
      || (v151 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
          --*(_WORD *)(v151 + 308),
          ExAcquireResourceSharedLite(*(_DWORD *)(*a8 + 48), 1),
          (v16 = (_DWORD *)*a8) == 0) )
    {
      v16 = (_DWORD *)a8[2];
    }
    v17 = (_DWORD *)a8[2];
    v18 = v16[39];
    v19 = *(_DWORD *)(v16[37] + 8 * v16[36]);
    v20 = v16[41];
    v21 = v17[39];
    v22 = *(_DWORD *)(v17[37] + 8 * v17[36]);
    v23 = (int *)SepLocateTokenIntegrity((int)v16);
    if ( v23 )
    {
      v27 = *v23;
    }
    else
    {
      v26 = &SepDefaultMandatorySid;
      v27 = SepDefaultMandatorySid;
    }
    v28 = SepLocateTokenTrustLevel(v196, v24, v25, (int)v26);
    v29 = v28;
    if ( v28 )
      v30 = 4 * (*(unsigned __int8 *)(v28 + 1) + 2);
    else
      v30 = 0;
    v208 = v30;
    if ( v18 )
      v31 = 4 * (*(unsigned __int8 *)(v18 + 1) + 2);
    else
      v31 = 0;
    v210 = (unsigned __int16 *)v31;
    if ( v21 )
      v32 = 4 * (*(unsigned __int8 *)(v21 + 1) + 2);
    else
      v32 = 0;
    v209 = v32;
    if ( v20 )
      v33 = *(unsigned __int16 *)(v20 + 2);
    else
      v33 = 0;
    v34 = ExAllocatePoolWithTag(
            1,
            (int)&v210[2 * *(unsigned __int8 *)(v27 + 1)
                     + 12
                     + 2 * *(unsigned __int8 *)(v22 + 1)
                     + 2 * *(unsigned __int8 *)(v19 + 1)]
          + v209
          + v33
          + v208,
            1683187027);
    v209 = v34;
    if ( !v34 )
    {
      SeUnlockSubjectContext(v196);
      return -1073741670;
    }
    v35 = *(unsigned __int8 *)(v19 + 1);
    v192 = v34;
    memmove(v34, v19, 4 * (v35 + 2));
    v36 = 4 * (*(unsigned __int8 *)(v27 + 1) + 2);
    v212 = (unsigned __int16 *)(v209 + 4 * (*(unsigned __int8 *)(v19 + 1) + 2));
    memmove((int)v212, v27, v36);
    v37 = &v212[2 * *(unsigned __int8 *)(v27 + 1) + 4];
    v200 = v37;
    if ( v29 )
    {
      v147 = 4 * (*(unsigned __int8 *)(v29 + 1) + 2);
      v210 = v37;
      memmove((int)v37, v29, v147);
      v37 += 2 * *(unsigned __int8 *)(v29 + 1) + 4;
      v200 = v37;
    }
    else
    {
      v210 = 0;
    }
    if ( v18 )
    {
      v11 = v37;
      memmove((int)v37, v18, 4 * (*(unsigned __int8 *)(v18 + 1) + 2));
      v37 += 2 * *(unsigned __int8 *)(v18 + 1) + 4;
      v200 = v37;
    }
    else
    {
      v11 = 0;
    }
    memmove((int)v37, v22, 4 * (*(unsigned __int8 *)(v22 + 1) + 2));
    v38 = (int)&v37[2 * *(unsigned __int8 *)(v22 + 1) + 4];
    v208 = v38;
    if ( v21 )
    {
      v39 = 4 * (*(unsigned __int8 *)(v21 + 1) + 2);
      v204 = v38;
      memmove(v38, v21, v39);
      v38 += 4 * (*(unsigned __int8 *)(v21 + 1) + 2);
      v208 = v38;
    }
    else
    {
      v204 = 0;
    }
    if ( v20 )
      memmove(v38, v20, *(unsigned __int16 *)(v20 + 2));
    else
      v208 = 0;
    v40 = v196;
    v41 = ExReleaseResourceLite(*(_DWORD *)(v196[2] + 48));
    v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v43 = *(_WORD *)(v42 + 0x134) + 1;
    *(_WORD *)(v42 + 308) = v43;
    if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
      KiCheckForKernelApcDelivery(v41);
    if ( *v40 )
    {
      v148 = ExReleaseResourceLite(*(_DWORD *)(*v40 + 48));
      v149 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v150 = (__int16)(*(_WORD *)(v149 + 0x134) + 1);
      *(_WORD *)(v149 + 308) = v150;
      if ( !v150 && *(_DWORD *)(v149 + 100) != v149 + 100 && !*(_WORD *)(v149 + 310) )
        KiCheckForKernelApcDelivery(v148);
    }
    v10 = (unsigned __int16 *)v192;
    v12 = 0;
  }
  v44 = *(_WORD *)(v194 + 2);
  if ( (v44 & 0x8000) != 0 )
  {
    v140 = *(_DWORD *)(v194 + 4);
    if ( !v140 )
      goto LABEL_32;
    v45 = (unsigned __int16 *)(v140 + v194);
  }
  else
  {
    v45 = *(unsigned __int16 **)(v194 + 4);
  }
  v190 = v45;
  if ( v45 )
  {
    v47 = v201;
    v220 = 1;
    goto LABEL_278;
  }
LABEL_32:
  if ( (a7 & 0x20) != 0 )
  {
    v47 = v201;
    if ( !v201 )
    {
      v57 = -1073741734;
      goto LABEL_332;
    }
    if ( (*(_WORD *)(v201 + 2) & 0x8000) != 0 )
    {
      v162 = *(_DWORD *)(v201 + 4);
      if ( !v162 )
      {
LABEL_357:
        v57 = -1073741734;
        goto LABEL_332;
      }
      v163 = (unsigned __int16 *)(v162 + v201);
    }
    else
    {
      v163 = *(unsigned __int16 **)(v201 + 4);
    }
    v220 = 1;
    v190 = v163;
    if ( !v163 )
      goto LABEL_357;
LABEL_278:
    v46 = v191;
    goto LABEL_37;
  }
  v46 = v191;
  if ( v191 )
    v10 = v200;
  v190 = v10;
  if ( !v10 )
  {
    v57 = -1073741700;
    goto LABEL_332;
  }
  v47 = v201;
LABEL_37:
  if ( (v44 & 0x8000) != 0 )
  {
    v141 = *(_DWORD *)(v194 + 8);
    if ( !v141 )
      goto LABEL_40;
    v48 = v141 + v194;
  }
  else
  {
    v48 = *(_DWORD *)(v194 + 8);
  }
  v193 = v48;
  if ( v48 )
    goto LABEL_44;
LABEL_40:
  if ( (a7 & 0x40) != 0 )
  {
    if ( !v47 )
    {
      v57 = -1073741733;
      goto LABEL_332;
    }
    if ( (*(_WORD *)(v47 + 2) & 0x8000) != 0 )
    {
      v164 = *(_DWORD *)(v47 + 8);
      if ( !v164 )
        goto LABEL_331;
      v49 = v164 + v47;
    }
    else
    {
      v49 = *(_DWORD *)(v47 + 8);
    }
  }
  else if ( v46 )
  {
    v49 = v204;
  }
  else
  {
    v49 = (int)v11;
  }
  v193 = v49;
  if ( !v49 )
  {
LABEL_331:
    v57 = -1073741733;
LABEL_332:
    v128 = 0;
    v127 = 0;
    goto LABEL_333;
  }
LABEL_44:
  v232 = a7 & 4;
  if ( (v44 & 0x10) != 0 )
    v50 = 4;
  else
    v50 = 0;
  if ( (v44 & 0x20) != 0 )
    v51 = 8;
  else
    v51 = 0;
  if ( (v44 & 0x800) != 0 )
    v52 = 1024;
  else
    v52 = 0;
  if ( (v44 & 0x2000) != 0 )
    v53 = 4096;
  else
    v53 = 0;
  if ( (v44 & 0x10) != 0 )
  {
    if ( (v44 & 0x8000) != 0 )
    {
      v153 = *(_DWORD *)(v194 + 12);
      if ( v153 )
        v54 = v194 + v153;
      else
        v54 = 0;
    }
    else
    {
      v54 = *(_DWORD *)(v194 + 12);
    }
  }
  else
  {
    v54 = 0;
  }
  if ( !v201 || (*(_WORD *)(v201 + 2) & 0x10) == 0 )
    goto LABEL_55;
  if ( (*(_WORD *)(v201 + 2) & 0x8000) != 0 )
  {
    v143 = *(_DWORD *)(v201 + 12);
    if ( v143 )
    {
      v55 = v201 + v143;
      goto LABEL_56;
    }
LABEL_55:
    v55 = 0;
    goto LABEL_56;
  }
  v55 = *(_DWORD *)(v201 + 12);
LABEL_56:
  v56 = RtlpInheritAcl(
          v55,
          v54,
          v53 | v52 | v51 | v50,
          a6,
          (a7 & 2) != 0,
          (a7 & 4) != 0,
          v190,
          v193,
          v200,
          v204,
          v199,
          2,
          v214,
          a5,
          &v202,
          &v187,
          &v192);
  v57 = v56;
  v226 = -2147483637;
  if ( v56 >= 0 )
  {
    v217 = 1;
    if ( (v192 & 4) != 0 )
      v156 = 16;
    else
      v156 = 0;
    if ( (v192 & 8) != 0 )
      v157 = 32;
    else
      v157 = 0;
    v60 = 1024;
    if ( (v192 & 0x400) != 0 )
      v158 = 2048;
    else
      v158 = 0;
    if ( (v192 & 0x1000) != 0 )
      v159 = 0x2000;
    else
      v159 = 0;
    v186 = v159 | v158 | v157 | v156 | 0x8010;
    v58 = v194;
    v189 = v202;
    goto LABEL_62;
  }
  if ( v56 != -2147483637 )
  {
    v189 = v202;
    goto LABEL_479;
  }
  if ( (a7 & 2) != 0 )
    v186 = 34816;
  v58 = v194;
  v59 = *(_WORD *)(v194 + 2);
  if ( (v59 & 0x30) != 48 )
  {
    v189 = v202;
    v60 = 1024;
LABEL_62:
    v61 = v187;
    goto LABEL_63;
  }
  if ( (v59 & 0x10) != 0 )
  {
    if ( (*(_WORD *)(v194 + 2) & 0x8000) != 0 )
    {
      v165 = *(_DWORD *)(v194 + 12);
      if ( v165 )
        v189 = v165 + v194;
      else
        v189 = 0;
    }
    else
    {
      v189 = *(_DWORD *)(v194 + 12);
    }
  }
  else
  {
    v189 = 0;
  }
  v60 = 1024;
  v186 |= v59 & 0x2000 | 0x10;
  v61 = 1;
LABEL_63:
  v202 = v61;
  v62 = *(_WORD *)(v58 + 2);
  if ( (v62 & 0x10) != 0 )
    v63 = 4;
  else
    v63 = 0;
  if ( (v62 & 0x20) != 0 )
    v64 = 8;
  else
    v64 = 0;
  if ( (*(_WORD *)(v58 + 2) & 0x800) == 0 )
    v60 = 0;
  if ( (*(_WORD *)(v58 + 2) & 0x2000) != 0 )
    v65 = 4096;
  else
    v65 = 0;
  if ( (v62 & 0x10) != 0 )
  {
    if ( (*(_WORD *)(v58 + 2) & 0x8000) != 0 )
    {
      v154 = *(_DWORD *)(v58 + 12);
      if ( v154 )
        v66 = v154 + v58;
      else
        v66 = 0;
    }
    else
    {
      v66 = *(_DWORD *)(v58 + 12);
    }
  }
  else
  {
    v66 = 0;
  }
  if ( !v201 || (*(_WORD *)(v201 + 2) & 0x10) == 0 )
    goto LABEL_74;
  if ( (*(_WORD *)(v201 + 2) & 0x8000) != 0 )
  {
    v144 = *(_DWORD *)(v201 + 12);
    if ( v144 )
    {
      v67 = v201 + v144;
      goto LABEL_75;
    }
LABEL_74:
    v67 = 0;
    goto LABEL_75;
  }
  v67 = *(_DWORD *)(v201 + 12);
LABEL_75:
  v68 = v65 | v60;
  v69 = a6;
  v70 = RtlpInheritAcl(
          v67,
          v66,
          (v68 | v64 | v63) & 0xFFFFEFFF,
          a6,
          (a7 & 2) != 0,
          v232 != 0,
          v190,
          v193,
          v200,
          v204,
          v199,
          2,
          v214,
          a5,
          &v183,
          v203,
          &v206);
  v57 = v70;
  v206 = v70;
  if ( v70 >= 0 )
  {
    v71 = v194;
    v227 = 1;
    goto LABEL_78;
  }
  if ( v70 != -2147483637 )
  {
    v198 = v183;
LABEL_479:
    v12 = 0;
    goto LABEL_332;
  }
  v71 = v194;
  v72 = *(_WORD *)(v194 + 2);
  if ( (v72 & 0x30) == 48 )
  {
    if ( (v72 & 0x10) != 0 )
    {
      if ( (*(_WORD *)(v194 + 2) & 0x8000) != 0 )
      {
        v166 = *(_DWORD *)(v194 + 12);
        if ( v166 )
          v73 = (unsigned __int8 *)(v166 + v194);
        else
          v73 = 0;
      }
      else
      {
        v73 = *(unsigned __int8 **)(v194 + 12);
      }
    }
    else
    {
      v73 = 0;
    }
    goto LABEL_79;
  }
LABEL_78:
  v73 = v183;
LABEL_79:
  v74 = (int)v210;
  v183 = 0;
  v198 = v73;
  do
  {
    if ( (*(_WORD *)(v71 + 2) & 0x10) != 0 )
    {
      if ( (*(_WORD *)(v71 + 2) & 0x8000) != 0 )
      {
        v152 = *(_DWORD *)(v71 + 12);
        if ( v152 )
          v75 = v152 + v71;
        else
          v75 = 0;
      }
      else
      {
        v75 = *(_DWORD *)(v71 + 12);
      }
    }
    else
    {
      v75 = 0;
    }
    v76 = RtlFindAceByType(v75, 20, (unsigned int *)&v183);
    v78 = v76;
    if ( v76 && v76 != (unsigned __int8 *)-8 && !RtlpValidTrustSubjectContext(v74, (int)(v76 + 8), v77, &v206) )
    {
      v57 = -1073741790;
      goto LABEL_479;
    }
    ++v183;
  }
  while ( v78 );
  v79 = 2048;
  if ( (a7 & 0x800) == 0 )
  {
LABEL_85:
    v183 = v73;
    v80 = v193;
    v81 = 0x2000;
    goto LABEL_86;
  }
  v183 = 0;
  while ( 1 )
  {
    if ( (*(_WORD *)(v71 + 2) & 0x10) != 0 )
    {
      if ( (*(_WORD *)(v71 + 2) & 0x8000) != 0 )
      {
        v168 = *(_DWORD *)(v71 + 12);
        v167 = v168 ? v168 + v71 : 0;
      }
      else
      {
        v167 = *(_DWORD *)(v71 + 12);
      }
    }
    else
    {
      v167 = 0;
    }
    v169 = RtlFindAceByType(v167, 20, (unsigned int *)&v183);
    ++v183;
    if ( !v169 )
      break;
    if ( (v169[1] & 8) == 0 )
    {
      v170 = v169[1];
      v171 = *((_DWORD *)v169 + 1);
      v74 = (int)(v169 + 8);
      if ( !v222 || (*(_DWORD *)(v222 + 4) & v171) != v171 || v169 == (unsigned __int8 *)-8 )
      {
        v57 = -1073741811;
        goto LABEL_479;
      }
      goto LABEL_414;
    }
  }
  if ( !v74 )
    goto LABEL_85;
  if ( !v222 )
  {
    v57 = -1073741811;
    goto LABEL_479;
  }
  v171 = *(_DWORD *)(v222 + 4);
  v170 = 0;
LABEL_414:
  v57 = RtlCreateAcl((int)v245, 0x58u, 2);
  if ( v57 < 0 )
    goto LABEL_479;
  v57 = RtlAddProcessTrustLabelAce(v245, 2, v170, v74, 20, v171);
  if ( v57 < 0 )
    goto LABEL_479;
  v172 = *(_WORD *)(v71 + 2);
  if ( (v172 & 0x10) != 0 )
    v173 = 4;
  else
    v173 = 0;
  if ( (v172 & 0x20) != 0 )
    v174 = 8;
  else
    v174 = 0;
  if ( (*(_WORD *)(v71 + 2) & 0x800) != 0 )
    v175 = 1024;
  else
    v175 = 0;
  v81 = 0x2000;
  if ( (*(_WORD *)(v71 + 2) & 0x2000) != 0 )
    v176 = 4096;
  else
    v176 = 0;
  v80 = v193;
  v57 = RtlpComputeMergedAcl(v198, (v176 | v175 | v174 | v173) & 0xFFFFEFFF, v245, 4, v190, v193, v199, 2, &v223, &v192);
  if ( v57 < 0 )
  {
    v127 = v223;
    v12 = 0;
    v128 = 0;
    goto LABEL_333;
  }
  v228 = 1;
  v69 = a6;
  v183 = v223;
LABEL_86:
  if ( (a7 & 0x100) != 0 )
  {
    v82 = 1;
    v197 = 1;
  }
  else
  {
    v82 = 0;
  }
  if ( (a7 & 0x200) != 0 )
  {
    v82 |= 2u;
    v197 = v82;
  }
  if ( (a7 & 0x400) != 0 )
  {
    v82 |= 4u;
    v197 = v82;
  }
  if ( v82 )
    goto LABEL_93;
  if ( (*(_WORD *)(v71 + 2) & 0x10) != 0 )
  {
    if ( (*(_WORD *)(v71 + 2) & 0x8000) != 0 )
    {
      v155 = *(_DWORD *)(v71 + 12);
      if ( v155 )
        v131 = v155 + v71;
      else
        v131 = 0;
    }
    else
    {
      v131 = *(_DWORD *)(v71 + 12);
    }
  }
  else
  {
    v131 = 0;
  }
  v132 = RtlFindAceByType(v131, 17, 0);
  v216 = v132;
  if ( !v132 )
  {
    v82 = v197;
LABEL_93:
    LOBYTE(v83) = 0;
    goto LABEL_94;
  }
  v213 = (unsigned __int16 *)(v132 + 8);
  v82 = *((_DWORD *)v132 + 1);
  v83 = v132[1];
  v197 = v82;
  v211 = v83;
  if ( v83 == 8 || (v83 & 0x10) != 0 )
  {
    v82 = 0;
    LOBYTE(v83) = 0;
    v211 = 0;
    v216 = 0;
    v213 = 0;
    v197 = 0;
  }
LABEL_94:
  if ( (v83 & 8) != 0 )
  {
    if ( *(_DWORD *)RtlSubAuthoritySid((int)v212, 0) < 0x2000u )
    {
      v57 = -1073740730;
LABEL_436:
      v127 = v183;
      v12 = 0;
      v128 = 0;
      goto LABEL_333;
    }
    v82 = v197;
  }
  if ( (v82 || v212 && *(_DWORD *)RtlSubAuthoritySid((int)v212, 0) < 0x2000u) && !v216 )
  {
    if ( !v196 )
    {
      v57 = -1073741700;
      v127 = v183;
      v12 = 0;
      v128 = 0;
      goto LABEL_333;
    }
    v213 = v212;
    v84 = 0;
  }
  else
  {
    v84 = v211;
  }
  if ( v213 )
  {
    v241[0] = 2;
    v241[1] = 0;
    v242 = 128;
    v243 = 0;
    v244 = 0;
    v57 = RtlAddMandatoryAce(v241, v213, v84, v213);
    if ( v57 < 0 )
      goto LABEL_451;
    v85 = v241;
  }
  else
  {
    v85 = 0;
    v225 = 0;
  }
  if ( (a7 & 0x700) != 0 )
  {
    v86 = 4;
  }
  else if ( !v85 || v216 )
  {
    v133 = *(_WORD *)(v71 + 2);
    if ( (v133 & 0x10) != 0 )
      v134 = 4;
    else
      v134 = 0;
    if ( (v133 & 0x20) != 0 )
      v135 = 8;
    else
      v135 = 0;
    if ( (*(_WORD *)(v71 + 2) & 0x800) != 0 )
      v136 = 1024;
    else
      v136 = 0;
    if ( (*(_WORD *)(v71 + 2) & 0x2000) != 0 )
      v137 = 4096;
    else
      v137 = 0;
    v86 = v137 | v136 | v135 | v134;
  }
  else
  {
    v86 = 0;
  }
  if ( !v201 || (*(_WORD *)(v201 + 2) & 0x10) == 0 )
    goto LABEL_105;
  if ( (*(_WORD *)(v201 + 2) & 0x8000) != 0 )
  {
    v145 = *(_DWORD *)(v201 + 12);
    if ( v145 )
    {
      v87 = v201 + v145;
      goto LABEL_106;
    }
LABEL_105:
    v87 = 0;
    goto LABEL_106;
  }
  v87 = *(_DWORD *)(v201 + 12);
LABEL_106:
  v88 = v69;
  v89 = (unsigned __int8 *)v225;
  v90 = RtlpInheritAcl(v87, v225, v86, v88, 1, 0, v190, v80, v200, v204, v199, 3, v214, a5, &v229, v205, &v192);
  v57 = v90;
  if ( v90 == v226 )
  {
    v91 = 0;
    v192 = 0;
  }
  else
  {
    if ( v90 < 0 )
      goto LABEL_451;
    v89 = v229;
    v91 = v192;
  }
  v57 = RtlpCombineAcls(v189, v89, v198, v198, v183, (unsigned int *)&v230, &v233);
  if ( (v186 & 0x2000) != 0 )
    v92 = 0x40000000;
  else
    v92 = 0;
  v93 = v92 | v233;
  if ( v89 && v89 != (unsigned __int8 *)v225 )
    ExFreePoolWithTag((unsigned int)v89);
  if ( v57 < 0 )
    goto LABEL_436;
  v94 = v230;
  if ( v230 )
  {
    if ( v217 && v189 )
      ExFreePoolWithTag(v189);
    v234 = 1;
    v189 = v94;
    if ( (v91 & 4) != 0 )
      v95 = 16;
    else
      v95 = 0;
    if ( (v91 & 8) != 0 )
      v96 = 32;
    else
      v96 = 0;
    if ( (v91 & 0x400) == 0 )
      v79 = 0;
    if ( (v91 & 0x1000) == 0 )
      v81 = 0;
    v186 |= v81 | v79 | v96 | v95 | 0x10;
  }
  else
  {
    v94 = v189;
  }
  if ( (a7 & 8) != 0 )
    goto LABEL_134;
  v97 = RtlFindAceByType(v94, 17, 0);
  v98 = (unsigned __int16 *)(v97 ? v97 + 8 : v213);
  if ( !v98 )
    goto LABEL_134;
  if ( v196 )
  {
    v57 = RtlSidDominates(v212, v98, v195);
    if ( v57 < 0 )
      goto LABEL_451;
    if ( !v195[0] )
      v231 = 1;
LABEL_134:
    v99 = *(_WORD *)(v194 + 2);
    if ( (v99 & 4) != 0 )
    {
      if ( (*(_WORD *)(v194 + 2) & 0x8000) != 0 )
      {
        v142 = *(_DWORD *)(v194 + 16);
        if ( v142 )
          v100 = v142 + v194;
        else
          v100 = 0;
      }
      else
      {
        v100 = *(_DWORD *)(v194 + 16);
      }
    }
    else
    {
      v100 = 0;
    }
    if ( v201 && (*(_WORD *)(v201 + 2) & 4) != 0 )
    {
      if ( (*(_WORD *)(v201 + 2) & 0x8000) == 0 )
      {
        v101 = *(_DWORD *)(v201 + 16);
LABEL_138:
        v102 = RtlpInheritAcl(
                 v101,
                 v100,
                 v99 & 0x140C,
                 a6,
                 (a7 & 1) != 0,
                 v232 != 0,
                 v190,
                 v193,
                 v200,
                 v204,
                 v199,
                 1,
                 v214,
                 a5,
                 &v215,
                 v185,
                 &v192);
        v57 = v102;
        if ( v102 >= 0 )
        {
          v219 = 1;
          v184 = v215;
          v186 |= v192 & 0x1408 | 4;
        }
        else
        {
          if ( v102 != v226 )
          {
            v128 = v215;
            v127 = v183;
            v12 = 0;
            goto LABEL_333;
          }
          v103 = v186;
          if ( (a7 & 1) != 0 )
          {
            v103 = v186 | 0x400;
            v186 |= 0x400u;
          }
          v104 = *(_WORD *)(v194 + 2);
          if ( (v104 & 0xC) == 12 )
          {
            if ( (v104 & 4) != 0 )
            {
              if ( (*(_WORD *)(v194 + 2) & 0x8000) != 0 )
              {
                v160 = *(_DWORD *)(v194 + 16);
                if ( v160 )
                  v161 = v160 + v194;
                else
                  v161 = 0;
              }
              else
              {
                v161 = *(_DWORD *)(v194 + 16);
              }
            }
            else
            {
              v161 = 0;
            }
            v186 = v104 & 0x1000 | v103 | 4;
            v184 = v161;
            v105 = 1;
            goto LABEL_146;
          }
          if ( v208 )
          {
            v186 = v103 | 4;
            v184 = v208;
          }
          else
          {
            v184 = v215;
          }
        }
        v105 = (unsigned __int8)v185[0];
LABEL_146:
        if ( (a7 & 0x1000) != 0 || !v218 || !v196 || !v201 )
          goto LABEL_148;
        v218 = 0;
        v206 = 0;
        v57 = RtlpNewSecurityObject(v201, 0, &v182, v214, a5, a6, a7 | 1, v196, v199, v222);
        if ( v57 >= 0 )
        {
          v106 = v182;
          if ( (*(_WORD *)(v182 + 2) & 4) != 0 )
          {
            if ( (*(_WORD *)(v182 + 2) & 0x8000) != 0 )
            {
              v138 = *(_DWORD *)(v182 + 16);
              if ( v138 )
                v139 = v138 + v182;
              else
                v139 = 0;
            }
            else
            {
              v139 = *(_DWORD *)(v182 + 16);
            }
          }
          else
          {
            v139 = 0;
          }
          if ( !RtlpOwnerAcesPresent(16, v139) )
          {
LABEL_149:
            v107 = v184;
            if ( (a7 & 1) != 0 && !v184 )
              v186 |= 0x1000u;
            v108 = !v93 || (v93 & 0xB0) != v93;
            v109 = v221;
            if ( v221 == 1 )
            {
              if ( v202 && v108 && (a7 & 8) == 0 )
              {
                v177 = v196;
                if ( !v196 )
                {
                  v57 = -1073741700;
                  v127 = v183;
                  v128 = v184;
                  v12 = 0;
                  goto LABEL_334;
                }
                v237 = 1;
                v238 = 1;
                v239 = SeSecurityPrivilege;
                v240 = 0;
                v178 = SePrivilegeCheck(&v237, v196, v221);
                SePrivilegedServiceAuditAlarm(0, v177, (int)&v237, v178);
                v106 = v182;
                if ( !v178 )
                {
                  v57 = -1073741727;
                  v127 = v183;
                  v128 = v184;
                  v12 = 0;
                  goto LABEL_334;
                }
                v107 = v184;
                v109 = v221;
              }
              if ( v231 && (a7 & 8) == 0 )
              {
                v179 = v196;
                if ( !v196 )
                {
                  v57 = -1073741700;
                  v127 = v183;
                  v128 = v184;
                  v12 = 0;
                  goto LABEL_334;
                }
                v237 = 1;
                v238 = 1;
                v239 = SeRelabelPrivilege;
                v240 = 0;
                v180 = SePrivilegeCheck(&v237, v196, v109);
                SePrivilegedServiceAuditAlarm(0, v179, (int)&v237, v180);
                if ( !v180 )
                {
                  v57 = -1073741727;
                  v127 = v183;
                  v128 = v184;
                  v12 = 0;
                  goto LABEL_333;
                }
                v107 = v184;
              }
              if ( v220 && (a7 & 0x10) == 0 && !SepValidOwnerSubjectContext((int **)v196, v190, v191) )
              {
                v57 = -1073741734;
                v127 = v183;
                v128 = v184;
                v12 = 0;
                goto LABEL_333;
              }
              if ( v105 && v191 )
              {
                v181 = RtlpCreateServerAcl(v107, v235, v200, &v207, v188);
                v57 = v181;
                if ( v181 < 0 )
                {
                  v130 = v207;
                  v129 = (unsigned __int8)v188[0];
                  v106 = v182;
                  v127 = v183;
                  v128 = v184;
                  v12 = 0;
                  goto LABEL_189;
                }
                if ( v219 && v184 )
                  ExFreePoolWithTag(v184);
                v107 = v207;
                v184 = v207;
                v224 = (unsigned __int8)v188[0];
              }
            }
            v110 = 4 * (*((unsigned __int8 *)v190 + 1) + 2);
            v111 = (v110 + 3) & 0xFFFFFFFC;
            if ( v193 )
            {
              v112 = 4 * (*(unsigned __int8 *)(v193 + 1) + 2);
              v113 = (v112 + 3) & 0xFFFFFFFC;
            }
            else
            {
              v112 = 0;
              v113 = 0;
            }
            v206 = v186 & 0x10;
            if ( (v186 & 0x10) != 0 && v189 )
              v114 = (*(unsigned __int16 *)(v189 + 2) + 3) & 0xFFFFFFFC;
            else
              v114 = 0;
            v207 = v114;
            v115 = v186 & 4;
            if ( (v186 & 4) != 0 && v107 )
              v116 = (*(unsigned __int16 *)(v107 + 2) + 3) & 0xFFFFFFFC;
            else
              v116 = 0;
            v117 = (_BYTE *)ExAllocatePoolWithTag(1, v116 + v114 + v113 + v111 + 20, 1683187027);
            v118 = v117;
            v191 = (int)v117;
            if ( v117 )
            {
              memset(v117, 0, 20);
              v119 = v186;
              *v118 = 1;
              *((_WORD *)v118 + 1) |= v119;
              v120 = (int)(v118 + 20);
              if ( v206 )
              {
                if ( v189 )
                {
                  memmove(v120, v189, *(unsigned __int16 *)(v189 + 2));
                  if ( !v217 )
                    RtlpApplyAclToObject(v120, v199);
                  v121 = v189;
                  *(_DWORD *)(v191 + 12) = v120 - v191;
                  v122 = *(unsigned __int16 *)(v121 + 2);
                  v123 = v207;
                  if ( v207 > v122 )
                  {
                    memset((_BYTE *)(v122 + v120), 0, v207 - v122);
                    v123 = v207;
                  }
                  v120 += v123;
                }
                else
                {
                  *(_DWORD *)(v191 + 12) = 0;
                }
              }
              if ( v115 )
              {
                if ( v184 )
                {
                  memmove(v120, v184, *(unsigned __int16 *)(v184 + 2));
                  if ( !v219 )
                    RtlpApplyAclToObject(v120, v199);
                  v12 = v191;
                  v124 = v184;
                  *(_DWORD *)(v191 + 16) = v120 - v191;
                  v125 = *(unsigned __int16 *)(v124 + 2);
                  if ( v116 > v125 )
                    memset((_BYTE *)(v125 + v120), 0, v116 - v125);
                  v120 += v116;
                }
                else
                {
                  v12 = v191;
                  *(_DWORD *)(v191 + 16) = 0;
                }
              }
              else
              {
                v12 = v191;
              }
              memmove(v120, (int)v190, v110);
              if ( v111 > v110 )
                memset((_BYTE *)(v120 + v110), 0, v111 - v110);
              *(_DWORD *)(v12 + 4) = v120 - v12;
              v126 = v120 + v111;
              if ( v193 )
              {
                memmove(v126, v193, v112);
                if ( v113 > v112 )
                  memset((_BYTE *)(v126 + v112), 0, v113 - v112);
                *(_DWORD *)(v12 + 8) = v126 - v12;
              }
              v106 = v182;
              v127 = v183;
              v128 = v184;
              v129 = v224;
              v57 = 0;
            }
            else
            {
              v57 = -1073741670;
              v106 = v182;
              v127 = v183;
              v12 = 0;
              v128 = v184;
              v129 = v224;
            }
            goto LABEL_188;
          }
          if ( !SeAccessCheck(v106, (int)v196, 0, 0x40000, 0, 0, v199, v221, (int)&v218, (int)&v206) )
          {
            v57 = -1073741790;
            goto LABEL_451;
          }
LABEL_148:
          v106 = v182;
          goto LABEL_149;
        }
LABEL_451:
        v127 = v183;
        v128 = v184;
        v12 = 0;
        goto LABEL_333;
      }
      v146 = *(_DWORD *)(v201 + 16);
      if ( v146 )
      {
        v101 = v146 + v201;
        goto LABEL_138;
      }
    }
    v101 = 0;
    goto LABEL_138;
  }
  v57 = -1073741700;
  v127 = v183;
  v12 = 0;
  v128 = 0;
LABEL_333:
  v106 = v182;
LABEL_334:
  v129 = 0;
LABEL_188:
  v130 = 0;
LABEL_189:
  if ( v106 )
    ExFreePoolWithTag(v106);
  if ( v129 && v130 )
    ExFreePoolWithTag(v130);
  if ( v209 )
    ExFreePoolWithTag(v209);
  if ( (v217 || v234) && v189 )
    ExFreePoolWithTag(v189);
  if ( v227 && v198 )
    ExFreePoolWithTag((unsigned int)v198);
  if ( v127 && v228 )
    ExFreePoolWithTag((unsigned int)v127);
  if ( v219 )
  {
    if ( v128 )
      ExFreePoolWithTag(v128);
  }
  result = v57;
  *v236 = v12;
  return result;
}
