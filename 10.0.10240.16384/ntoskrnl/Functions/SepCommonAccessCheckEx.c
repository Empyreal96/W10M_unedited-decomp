// SepCommonAccessCheckEx 
 
BOOL __fastcall SepCommonAccessCheckEx(int a1, int a2, int a3, int a4, _DWORD *a5, char a6, unsigned __int8 a7)
{
  int v7; // r4
  _DWORD *v8; // r5
  int *v10; // r7
  int v11; // r8
  int *v12; // r2
  _DWORD *v13; // r0
  _DWORD *v14; // r1
  _DWORD *v15; // r3
  _DWORD *v16; // r3
  _DWORD *v17; // r2
  unsigned int v18; // r9
  int v19; // r3
  int v20; // r2
  _DWORD *v21; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r2
  int v26; // r2
  int v27; // r6
  int v28; // r0
  int v29; // r10
  int v30; // r9
  int *v31; // r6
  int v32; // r1
  int v33; // r2
  int v34; // r3
  int v35; // r1
  int v36; // r0
  _DWORD *v37; // r2
  int v38; // r1
  _DWORD *v39; // r8
  int v40; // r1
  BOOL v41; // r9
  int v42; // r2
  BOOL v43; // r6
  int v44; // r3
  int v45; // r0
  int *v46; // r6
  _DWORD *v47; // r2
  int v48; // r4
  int v49; // r1
  int v50; // r3
  int v51; // r3
  int v52; // r2
  int v53; // r3
  int v54; // r2
  int v55; // r3
  int v56; // r0
  int v57; // r6
  int v58; // r3
  int v59; // r1
  int v60; // r2
  int v61; // r3
  int v62; // r2
  int v63; // r3
  int v64; // r0
  _DWORD *v65; // r2
  int v66; // r1
  int v67; // r3
  unsigned __int8 v68; // r9
  unsigned int v69; // r8
  int v70; // r1
  int v71; // r2
  int v72; // r0
  int *v73; // r3
  int v74; // r1
  _DWORD *v75; // r2
  int v76; // r3
  _DWORD *v77; // r9
  int v78; // r6
  int v79; // r8
  int **v80; // r3
  int *v81; // r1
  int v82; // r0
  int v83; // r4
  _BYTE *v84; // r0
  int v85; // r1
  int v86; // r0
  int v87; // r0
  int v88; // r10
  _DWORD *v89; // lr
  int v90; // r9
  int v91; // r3
  int v92; // r0
  _DWORD *v93; // r3
  int v94; // lr
  int v95; // r0
  int v96; // r1
  int v97; // r3
  int v98; // r0
  int v99; // r9
  int v100; // r8
  _DWORD *v101; // r8
  _DWORD *v102; // r3
  int v103; // lr
  int v104; // r0
  int v105; // r1
  int v106; // r3
  int v107; // r2
  unsigned int v108; // r8
  int v109; // r9
  int v110; // r10
  int v111; // r1
  int v112; // r0
  _DWORD *v113; // r3
  unsigned int v114; // r0
  int v115; // r2
  int v116; // lr
  int v117; // r3
  int v118; // r10
  int v119; // r8
  int v120; // r9
  int v121; // r2
  int *v122; // r1
  int v123; // r9
  unsigned __int8 *v124; // r1
  unsigned int v125; // r8
  unsigned int v126; // r9
  int v127; // r1
  int *v128; // r1
  unsigned int v129; // r2
  int v130; // r8
  int v131; // r3
  int v132; // r8
  _DWORD *v133; // r2
  bool v134; // cf
  int v135; // r0
  int v136; // r9
  int v137; // r9
  unsigned int v138; // r8
  unsigned int v139; // r7
  int v140; // r10
  int v141; // lr
  int v142; // r0
  int v143; // r2
  int *v144; // r1
  int v145; // r0
  int v146; // r2
  int *v147; // r1
  int v148; // r6
  int v149; // lr
  int v150; // r8
  _DWORD *v151; // r0
  int v152; // r3
  int v153; // lr
  int v154; // lr
  int v155; // lr
  __int64 v156; // kr08_8
  int v157; // r8
  int v158; // r1
  int v159; // lr
  _DWORD *v160; // r8
  int v161; // r0
  int v162; // r0
  int v163; // [sp+24h] [bp-2D4h]
  int v164; // [sp+28h] [bp-2D0h]
  int v165; // [sp+28h] [bp-2D0h]
  int v166; // [sp+48h] [bp-2B0h] BYREF
  char v167[4]; // [sp+4Ch] [bp-2ACh] BYREF
  int v168; // [sp+50h] [bp-2A8h]
  int v169; // [sp+54h] [bp-2A4h]
  _DWORD *v170; // [sp+58h] [bp-2A0h] BYREF
  char v171; // [sp+5Ch] [bp-29Ch] BYREF
  char v172[3]; // [sp+5Dh] [bp-29Bh] BYREF
  int v173; // [sp+60h] [bp-298h]
  int v174; // [sp+64h] [bp-294h]
  int v175; // [sp+68h] [bp-290h]
  int v176; // [sp+6Ch] [bp-28Ch]
  _DWORD *v177; // [sp+70h] [bp-288h]
  unsigned int v178; // [sp+74h] [bp-284h]
  int *v179; // [sp+78h] [bp-280h]
  int v180; // [sp+7Ch] [bp-27Ch]
  int v181; // [sp+80h] [bp-278h]
  int v182; // [sp+84h] [bp-274h] BYREF
  int v183; // [sp+88h] [bp-270h]
  _DWORD *v184; // [sp+8Ch] [bp-26Ch]
  int v185; // [sp+90h] [bp-268h]
  int v186; // [sp+94h] [bp-264h]
  int v187; // [sp+98h] [bp-260h]
  int v188; // [sp+9Ch] [bp-25Ch]
  int v189; // [sp+A0h] [bp-258h] BYREF
  unsigned int v190; // [sp+A4h] [bp-254h] BYREF
  int v191; // [sp+A8h] [bp-250h] BYREF
  int v192; // [sp+ACh] [bp-24Ch]
  char v193[8]; // [sp+B0h] [bp-248h] BYREF
  int v194; // [sp+B8h] [bp-240h] BYREF
  int v195; // [sp+BCh] [bp-23Ch]
  int v196; // [sp+C0h] [bp-238h]
  unsigned int v197; // [sp+C4h] [bp-234h]
  int v198; // [sp+C8h] [bp-230h]
  _DWORD *v199; // [sp+CCh] [bp-22Ch]
  int v200; // [sp+D0h] [bp-228h] BYREF
  BOOL v201; // [sp+D4h] [bp-224h]
  int *v202; // [sp+D8h] [bp-220h]
  int v203[5]; // [sp+E0h] [bp-218h] BYREF
  int v204; // [sp+F4h] [bp-204h] BYREF
  char v205; // [sp+F8h] [bp-200h] BYREF
  char v206[19]; // [sp+F9h] [bp-1FFh] BYREF
  char v207; // [sp+110h] [bp-1E8h] BYREF
  char v208[19]; // [sp+111h] [bp-1E7h] BYREF
  int v209[12]; // [sp+128h] [bp-1D0h] BYREF
  int v210; // [sp+158h] [bp-1A0h] BYREF
  char v211[124]; // [sp+15Ch] [bp-19Ch] BYREF
  int v212; // [sp+1D8h] [bp-120h] BYREF
  char v213[124]; // [sp+1DCh] [bp-11Ch] BYREF
  int v214; // [sp+258h] [bp-A0h] BYREF
  char v215[124]; // [sp+25Ch] [bp-9Ch] BYREF

  v7 = a4;
  v8 = (_DWORD *)a3;
  v10 = (int *)a1;
  v194 = 0;
  v195 = 0;
  v196 = 0;
  v197 = 0;
  v176 = 0;
  v205 = 0;
  v185 = a4;
  v199 = (_DWORD *)a3;
  v169 = a2;
  v202 = (int *)a1;
  memset(v206, 0, sizeof(v206));
  v207 = 0;
  memset(v208, 0, sizeof(v208));
  v170 = 0;
  v174 = 0;
  v166 = 0;
  v210 = 0;
  memset(v211, 0, sizeof(v211));
  v212 = 0;
  memset(v213, 0, sizeof(v213));
  v214 = 0;
  memset(v215, 0, sizeof(v215));
  v11 = -1;
  v182 = -1;
  v192 = 0;
  if ( !v7 )
    return 0;
  if ( *(_DWORD *)v7 != 24 )
    return 0;
  v12 = *(int **)(v7 + 12);
  if ( !v12 )
    return 0;
  if ( !v10 )
    goto LABEL_40;
  if ( !v8 )
    goto LABEL_40;
  if ( *v8 != 32 )
    goto LABEL_40;
  v13 = *(_DWORD **)(v7 + 8);
  if ( !v13 )
    goto LABEL_40;
  v14 = (_DWORD *)v8[1];
  if ( v14 )
  {
    if ( *v14 != 12 || (v14[1] & 0xFFFFFFFC) != 0 )
      goto LABEL_40;
  }
  if ( a5 && *a5 != 56 )
    goto LABEL_40;
  *v13 = 0;
  v15 = *(_DWORD **)(v7 + 12);
  v200 = -1073741790;
  *v15 = -1073741790;
  v190 = 0;
  v16 = *(_DWORD **)(v7 + 20);
  if ( v16 )
    *v16 = 0;
  v17 = *(_DWORD **)(v7 + 16);
  v18 = v8[2] & ~v8[3] & 0xFDFFFFFF;
  v19 = 1;
  v168 = v18;
  if ( v17 )
  {
    while ( v19 )
    {
      if ( (v19 & v18) != 0 )
        *v17 = 0;
      ++v17;
      v19 *= 2;
    }
  }
  if ( !a6 )
  {
    v20 = v8[2];
    if ( (v20 & 0x2000000) != 0 )
    {
      **(_DWORD **)(v7 + 8) = *(_DWORD *)(v8[5] + 12);
      **(_DWORD **)(v7 + 8) |= v8[2] & 0xFDFFFFFF;
      **(_DWORD **)(v7 + 8) |= v8[3];
    }
    else
    {
      **(_DWORD **)(v7 + 8) = v20 | v8[3];
    }
    v21 = *(_DWORD **)(v7 + 12);
LABEL_25:
    *v21 = 0;
    return 1;
  }
  v23 = v8[1];
  if ( !v23 || !*(_DWORD *)(v23 + 8) )
  {
LABEL_34:
    **(_DWORD **)(v7 + 12) = -1073741790;
    return 0;
  }
  if ( *v10 && v10[1] < 2 )
  {
    v12 = *(int **)(v7 + 12);
    v24 = -1073741659;
LABEL_41:
    *v12 = v24;
    return 0;
  }
  if ( !v8[2] )
  {
    v25 = v8[3];
    if ( v25 )
    {
      **(_DWORD **)(v7 + 8) = v25;
      **(_DWORD **)(v7 + 12) = 0;
      v21 = *(_DWORD **)(v7 + 20);
      if ( !v21 )
        return 1;
      goto LABEL_25;
    }
    goto LABEL_34;
  }
  v26 = *(_DWORD *)(v7 + 4);
  if ( v26 != 1 && v26 != v8[6] )
  {
    v12 = *(int **)(v7 + 12);
LABEL_40:
    v24 = -1073741811;
    goto LABEL_41;
  }
  if ( !a2 )
    SeLockSubjectContext(v10);
  v171 = 0;
  v172[0] = 0;
  v27 = 0;
  v28 = SepGetProcessTrustLabelAce(*(_DWORD *)(v8[1] + 8));
  if ( !v28 || (v29 = *(_DWORD *)(v28 + 4), v183 = v28 + 8, v28 == -8) )
  {
    v11 = -1;
    v182 = -1;
    goto LABEL_57;
  }
  if ( !*v10 )
    goto LABEL_50;
  v30 = *(_DWORD *)(*v10 + 640);
  v27 = RtlSidDominatesForTrust(*(_DWORD *)(v10[2] + 640), v30, v172);
  if ( v27 < 0 )
  {
LABEL_56:
    v18 = v168;
    goto LABEL_57;
  }
  if ( !v172[0] )
LABEL_50:
    v30 = *(_DWORD *)(v10[2] + 640);
  v27 = RtlSidDominatesForTrust(v30, v183, &v171);
  if ( v27 < 0 )
    goto LABEL_56;
  v18 = v168;
  if ( v171 )
  {
    v11 = -1;
    v182 = -1;
  }
  else
  {
    v11 = v29 | 0x1000000;
    v182 = v29 | 0x1000000;
  }
LABEL_57:
  **(_DWORD **)(v7 + 12) = v27;
  v31 = *(int **)(v7 + 12);
  if ( *v31 < 0 )
    goto LABEL_58;
  *v31 = SepTrustToDiscretionary(&v182, v8[2]);
  v34 = **(_DWORD **)(v7 + 12);
  if ( v34 < 0 )
  {
    v35 = SepLocateTokenTrustLevel(v10, v32, v33, v34);
    v36 = *v10;
    if ( !*v10 )
      v36 = v10[2];
    SeLogAccessFailure(v36, v35, v8[3], v35);
    if ( !v169 )
      SeUnlockSubjectContext(v10);
    v37 = *(_DWORD **)(v7 + 16);
    v38 = 1;
    if ( v37 )
    {
      while ( v38 )
      {
        if ( (v38 & v18 & ~v11) != 0 && !*v37 )
          *v37 = 9437184;
        ++v37;
        v38 *= 2;
      }
    }
    return 0;
  }
  v39 = (_DWORD *)*v10;
  v177 = v39;
  if ( !v39 )
  {
    v39 = (_DWORD *)v10[2];
    v177 = v39;
  }
  v40 = v8[1];
  v41 = (*(_DWORD *)(v40 + 4) & 1) != 0;
  v42 = (*(_DWORD *)(v40 + 4) & 2) != 0;
  v43 = (*(_DWORD *)(v40 + 4) & 2) != 0 && (v39[44] & 0x2000) != 0;
  v201 = v43;
  if ( !(_BYTE)SepAllowAccessUponLogoff && (v39[44] & 0x20) == 0 )
  {
    v44 = v39[48];
    if ( v44 )
    {
      if ( (*(_DWORD *)(v44 + 24) & 0x20) != 0 )
      {
        **(_DWORD **)(v7 + 8) = 0;
        **(_DWORD **)(v7 + 12) = -1073741790;
        goto LABEL_58;
      }
    }
  }
  v45 = 0;
  v186 = 0;
  if ( !v43 )
  {
    **(_DWORD **)(v7 + 12) = SepMandatoryIntegrityCheck((_DWORD *)v8[5], *(_DWORD *)(v40 + 8), v42, v39, 0, (int)&v194);
    v46 = *(int **)(v7 + 12);
    if ( *v46 < 0 )
    {
LABEL_58:
      if ( !v169 )
        SeUnlockSubjectContext(v10);
      return 0;
    }
    v45 = SepMandatoryToDiscretionary(&v194, v8[2]);
    *v46 = v45;
    if ( **(int **)(v7 + 12) >= 0 )
    {
      if ( (v8[2] & 0x2000000) != 0 && (v39[44] & 0x4000) != 0 && v197 <= 0x2000 )
        v186 = 1;
    }
    else
    {
      if ( (v39[44] & 0x4000) == 0 || v197 > 0x2000 )
      {
        if ( !v169 )
          SeUnlockSubjectContext(v10);
        v47 = *(_DWORD **)(v7 + 16);
        v48 = v168 & ~v194;
        v49 = 1;
        if ( v47 )
        {
          while ( v49 )
          {
            if ( (v49 & v48) != 0 && !*v47 )
              *v47 = 3145728;
            ++v47;
            v49 *= 2;
          }
        }
        return 0;
      }
      v186 = 1;
    }
  }
  v50 = (unsigned __int8)SepRmEnforceCap;
  __dmb(0xBu);
  if ( !v50 || (*(_WORD *)(*(_DWORD *)(v8[1] + 8) + 2) & 0x10) == 0 || (unsigned int)KeGetCurrentIrql(v45) >= 2 )
    goto LABEL_105;
  v51 = *(_DWORD *)(v8[1] + 8);
  if ( (*(_WORD *)(v51 + 2) & 0x10) == 0 )
    goto LABEL_104;
  if ( (*(_WORD *)(v51 + 2) & 0x8000) != 0 )
  {
    v54 = *(_DWORD *)(v51 + 12);
    if ( !v54 )
    {
LABEL_104:
      v176 = 0;
LABEL_105:
      v52 = 0;
      goto LABEL_106;
    }
    v55 = v51 + v54;
  }
  else
  {
    v55 = *(_DWORD *)(v51 + 12);
  }
  v176 = v55;
  if ( !v55 )
    goto LABEL_105;
  v56 = SepGetScopedPolicySid(v55);
  if ( !v56 )
    goto LABEL_105;
  if ( SepRmReferenceFindCap(v56, &v170) < 0 )
    v170 = SepRmDefaultCap;
  v52 = 1;
  v174 = 1;
LABEL_106:
  if ( !v41 || (v8[2] & 0x2060000) != 0 || v52 )
    v53 = SepTokenIsOwner((int)v177, *(_DWORD *)(v8[1] + 8));
  else
    v53 = 0;
  v57 = v8[2];
  v173 = v53;
  if ( !v53 || (v57 & 0x2060000) == 0 )
    goto LABEL_144;
  if ( v41 )
    goto LABEL_130;
  v58 = *(_DWORD *)(v8[1] + 8);
  if ( (*(_WORD *)(v58 + 2) & 4) == 0 )
    goto LABEL_124;
  if ( (*(_WORD *)(v58 + 2) & 0x8000) != 0 )
  {
    v60 = *(_DWORD *)(v58 + 16);
    if ( !v60 )
    {
LABEL_124:
      v59 = 0;
      goto LABEL_129;
    }
    v59 = v58 + v60;
  }
  else
  {
    v59 = *(_DWORD *)(v58 + 16);
  }
LABEL_129:
  if ( RtlpOwnerAcesPresent(0, v59) )
  {
LABEL_144:
    v67 = v174;
LABEL_145:
    v68 = v173;
    goto LABEL_146;
  }
LABEL_130:
  v61 = v8[3];
  v62 = v57 & 0x2000000;
  if ( (v57 & 0x2000000) != 0 )
  {
    v63 = v61 | 0x60000;
    v57 = 393216;
  }
  else
  {
    v57 &= 0x60000u;
    v63 = v61 | v57;
  }
  v8[3] = v63;
  if ( v62 )
    v64 = 393216;
  else
    v64 = v168 & 0x60000;
  v65 = *(_DWORD **)(v7 + 16);
  v66 = 1;
  if ( v65 )
  {
    while ( v66 )
    {
      if ( (v66 & v64) != 0 && !*v65 )
        *v65 = 0x400000;
      ++v65;
      v66 *= 2;
    }
  }
  v8[2] &= 0xFFF9FFFF;
  v67 = v174;
  if ( v174 )
    goto LABEL_145;
  v68 = 0;
  v173 = 0;
LABEL_146:
  v69 = v8[2];
  if ( !v69 && !v67 && ((v177[44] & 0x2000) != 0 || !v57) )
  {
    if ( !v169 )
      SeUnlockSubjectContext(v10);
    **(_DWORD **)(v7 + 8) = v8[3];
    **(_DWORD **)(v7 + 12) = 0;
    return 1;
  }
  memset(v203, 0, sizeof(v203));
  v70 = v8[1];
  v71 = v10[2];
  v72 = *(_DWORD *)(v70 + 8);
  v163 = *(_DWORD *)(v7 + 16);
  v73 = *(int **)(v7 + 12);
  v203[0] = v57;
  v183 = SepAccessCheckEx(
           v72,
           v70,
           v71,
           *v10,
           v69,
           0,
           0,
           (_DWORD *)v8[5],
           v8[3],
           a6,
           *(unsigned int **)(v7 + 8),
           *(_DWORD **)(v7 + 20),
           v73,
           v163,
           v164,
           v68,
           a7,
           (int)v203,
           (int)&v166,
           v167);
  v76 = (unsigned __int8)SepRmEnforceCap;
  __dmb(0xBu);
  v77 = v170;
  if ( !v76 || (v188 = **(_DWORD **)(v7 + 12), v188 < 0) || !v174 )
  {
    v88 = v166;
    v148 = (unsigned __int8)v167[0];
    goto LABEL_293;
  }
  v78 = 0;
  v168 = **(_DWORD **)(v7 + 8);
  v79 = v168;
  v175 = v168;
  v198 = 0;
  v181 = 0;
  v80 = *(int ***)(v7 + 20);
  if ( v80 )
  {
    v81 = *v80;
    if ( *v80 )
    {
      v82 = *v81;
      if ( *v81 )
      {
        v83 = 0;
        v178 = HIDWORD(SeSecurityPrivilege);
        v184 = (_DWORD *)HIDWORD(SeTakeOwnershipPrivilege);
        do
        {
          if ( v81[4] < 0 )
          {
            if ( *((_QWORD *)v81 + 1) == SeSecurityPrivilege )
            {
              v83 |= 0x1000000u;
            }
            else if ( *((_QWORD *)v81 + 1) == SeTakeOwnershipPrivilege || *((_QWORD *)v81 + 1) == SeRelabelPrivilege )
            {
              v83 |= 0x80000u;
            }
          }
          v81 += 3;
          --v82;
        }
        while ( v82 );
        v78 = 0;
        v8 = v199;
        v10 = v202;
        v77 = v170;
        v79 = v175;
        v181 = v83;
        v7 = v185;
      }
    }
  }
  v185 = v168;
  v178 = SepAdtAuditThisEventWithContext(129, 1, 1, v10);
  if ( v178 )
  {
    v84 = (_BYTE *)ExAllocatePoolWithTag(512, 8 * v77[8]);
    v78 = (int)v84;
    if ( !v84 )
    {
      if ( !v169 )
        SeUnlockSubjectContext(v10);
      v86 = v77[4];
      if ( v86 )
        SepRmDereferenceCapTable(v86, v85);
      v87 = v166;
      **(_DWORD **)(v7 + 8) = 0;
      **(_DWORD **)(v7 + 12) = -1073741801;
      SepFreeResourceInfo(v87);
      return 0;
    }
    memset(v84, 0, 8 * v77[8]);
  }
  v187 = 0;
  v88 = v166;
  if ( !v77[8] )
  {
    v133 = v170;
LABEL_261:
    v136 = v168;
    if ( v178 && v79 != v168 )
    {
      v137 = v168 & (v79 ^ v168);
      v189 = (v79 ^ v168) & v79;
      v138 = 0;
      v178 = v133[8];
      if ( v178 )
      {
        v139 = v189;
        v140 = v78;
        do
        {
          if ( !v139 && !v137 )
            break;
          if ( *(_BYTE *)(v140 + 4) )
          {
            v141 = *(_DWORD *)v140;
            v142 = (v137 ^ *(_DWORD *)v140) & v137;
            if ( v142 )
            {
              v143 = 1;
              v144 = &v212;
              while ( v143 )
              {
                if ( (v143 & v142) != 0 && !*v144 )
                  *v144 = (v138 | 0xFFFFFF80) << 24;
                ++v144;
                v143 *= 2;
              }
            }
            v137 &= ~v142;
            v145 = v139 & v141;
            if ( (v139 & v141) != 0 )
            {
              v146 = 1;
              v147 = &v212;
              while ( v146 )
              {
                if ( (v146 & v145) != 0 && !*v147 )
                  *v147 = (v138 | 0xFFFFFF80) << 24;
                ++v147;
                v146 *= 2;
              }
            }
            v139 &= ~v145;
            AuthzBasepMergeAccessReasons(&v210, &v212, -16777216);
          }
          ++v138;
          v140 += 8;
        }
        while ( v138 < v178 );
        v8 = v199;
        v10 = v202;
        v88 = v166;
      }
      v136 = v168;
    }
    if ( v78 )
      ExFreePoolWithTag(v78);
    **(_DWORD **)(v7 + 12) = v188;
    **(_DWORD **)(v7 + 8) &= v136;
    if ( **(int **)(v7 + 12) >= 0 )
      v148 = (unsigned __int8)v167[0];
    else
      v148 = 0;
    AuthzBasepMergeAccessReasons(*(_DWORD *)(v7 + 16), &v210, 0);
    AuthzBasepMergeAccessReasons(*(_DWORD *)(v7 + 16), &v210, -16777216);
    v77 = v170;
LABEL_293:
    if ( v201 || (v149 = v8[2], (v149 & 0x2000000) == 0) )
    {
      if ( v186 )
      {
        if ( !BYTE2(v203[4]) && !BYTE1(v203[4]) )
        {
          v148 = 0;
          v74 = 1;
          **(_DWORD **)(v7 + 12) = -1073741790;
          **(_DWORD **)(v7 + 8) = 0;
          v75 = *(_DWORD **)(v7 + 16);
          v154 = **(_DWORD **)(v7 + 8);
          if ( v75 )
          {
            while ( v74 )
            {
              if ( (v74 & ~v154) != 0 && !*v75 )
                *v75 = 3145728;
              ++v75;
              v74 *= 2;
            }
          }
        }
      }
LABEL_325:
      v155 = v8[2];
      if ( (v155 & 0x2000000) == 0 )
      {
LABEL_341:
        v160 = v177;
        if ( v177 && (v192 || !v203[3] && (v177[44] & 0x4000) != 0 && (**(int **)(v7 + 12) < 0 || HIBYTE(v203[4]))) )
        {
          v161 = SepLocateTokenTrustLevel(v10, v74, (int)v75, **(_DWORD **)(v7 + 12));
          SeLogAccessFailure((int)v160, v8[3], *(_DWORD *)(v8[1] + 8), v161);
        }
        if ( v174 )
        {
          v162 = v77[4];
          if ( v162 )
            SepRmDereferenceCapTable(v162, v74);
        }
        if ( !v169 )
          SeUnlockSubjectContext(v10);
        SepFreeResourceInfo(v88);
        return v183 && v148;
      }
      v156 = *(_QWORD *)(v7 + 8);
      v157 = *(_DWORD *)v156;
      v192 = 0;
      if ( v182 != -1 )
      {
        v158 = v182 & v157;
        if ( (v182 & v157) != v157 )
        {
          v192 = 1;
          *(_DWORD *)v156 = v158;
          if ( (v155 & 0x2000000) != 0 )
          {
            if ( !v158 )
            {
              *(_DWORD *)HIDWORD(v156) = -1073741790;
LABEL_331:
              v148 = 0;
              goto LABEL_332;
            }
            *(_DWORD *)HIDWORD(v156) = 0;
          }
          else
          {
            *(_DWORD *)HIDWORD(v156) = -1073741790;
            if ( !*(_DWORD *)v156 )
              goto LABEL_331;
          }
          v148 = 1;
        }
      }
LABEL_332:
      v75 = *(_DWORD **)(v7 + 16);
      v74 = 1;
      v159 = v157 & ~**(_DWORD **)(v7 + 8);
      if ( v75 )
      {
        while ( v74 )
        {
          if ( (v74 & v159) != 0 && !*v75 )
            *v75 = 9437184;
          ++v75;
          v74 *= 2;
        }
      }
      goto LABEL_341;
    }
    v74 = *(_DWORD *)(v7 + 8);
    v150 = *(_DWORD *)v74;
    if ( v186 && (BYTE2(v203[4]) || BYTE1(v203[4])) )
      goto LABEL_325;
    v151 = *(_DWORD **)(v7 + 12);
    if ( v196 && (!BYTE1(v195) || !(_BYTE)v195 || !BYTE2(v195)) )
    {
      v152 = v194 & *(_DWORD *)v74;
      if ( v152 != *(_DWORD *)v74 )
      {
        *(_DWORD *)v74 = v152;
        if ( (v149 & 0x2000000) != 0 )
        {
          if ( !v152 )
          {
            *v151 = -1073741790;
LABEL_306:
            v148 = 0;
            goto LABEL_307;
          }
          *v151 = 0;
        }
        else
        {
          *v151 = -1073741790;
          if ( !*(_DWORD *)v74 )
            goto LABEL_306;
        }
        v148 = 1;
      }
    }
LABEL_307:
    v75 = *(_DWORD **)(v7 + 16);
    v74 = 1;
    v153 = v150 & ~**(_DWORD **)(v7 + 8);
    if ( v75 )
    {
      while ( v74 )
      {
        if ( (v74 & v153) != 0 && !*v75 )
          *v75 = 3145728;
        ++v75;
        v74 *= 2;
      }
    }
    goto LABEL_325;
  }
  v179 = (int *)v78;
  v89 = v77;
  v184 = v77;
  while ( 1 )
  {
    v90 = v89[9];
    v91 = *(_DWORD *)(v90 + 12);
    v180 = v90;
    if ( !v91 )
      goto LABEL_214;
    if ( !v88 )
    {
      v92 = AuthzBasepInitializeResourceClaimsFromSacl(v176, (int)&v166);
      v88 = v166;
      if ( v92 < 0 )
        v198 = 1;
    }
    v93 = (_DWORD *)v177[159];
    v94 = v93 ? v93[75] : 0;
    v95 = v93 ? v93[73] : 0;
    v96 = v93 ? v93[74] : 0;
    v97 = v93 ? v93[72] : 0;
    v98 = AuthzBasepEvaluateAceCondition(
            (int)v177,
            v177[119],
            v88,
            v97,
            v96,
            v95,
            v94,
            *(_DWORD **)(v90 + 12),
            *(_DWORD *)(v90 + 8),
            1u,
            0,
            &v191);
    v99 = v191;
    v100 = v98;
    if ( v191 != 1 )
      break;
LABEL_213:
    v90 = v180;
LABEL_214:
    v100 = SepBuildCapeSecurityDescriptor((int)&v205, *(unsigned __int8 **)(v90 + 16), v176, v91);
    if ( v100 < 0 )
      goto LABEL_248;
    if ( (*(_DWORD *)(v90 + 24) & 1) != 0 )
    {
      v107 = v8[2];
      v108 = 0;
      if ( (v107 & 0x2000000) != 0 )
        v109 = v107 | 0x2000000;
      else
        v109 = v8[3] | v107 | 0x2000000;
    }
    else
    {
      v108 = v8[3];
      v109 = v8[2] | 0x2000000;
    }
    memset(v209, 0, 44);
    v110 = v173;
    v112 = SepAccessCheckEx(
             (int)&v205,
             v111,
             v10[2],
             *v10,
             v109,
             v209,
             1,
             (_DWORD *)v8[5],
             v108,
             a6,
             &v190,
             0,
             &v200,
             (int)&v214,
             v165,
             v173,
             a7,
             (int)v203,
             (int)&v166,
             v167);
    v113 = *(_DWORD **)(v7 + 8);
    v183 = v112;
    v114 = (*v113 | v108) & v190;
    v190 = v114;
    v115 = v181 | v209[7];
    if ( v110 )
      v115 |= v114 & 0x60000;
    v116 = v115 & ~v209[8];
    v168 &= v114;
    if ( v168 )
      v117 = v200;
    else
      v117 = -1073741790;
    v118 = v185;
    v188 = v117;
    v119 = (v116 ^ v185) & v185;
    if ( v119 )
    {
      v120 = v187;
      v121 = 1;
      v122 = &v210;
      while ( v121 )
      {
        if ( (v121 & v119) != 0 && !*v122 )
          *v122 = v120 | 0x50000;
        ++v122;
        v121 *= 2;
      }
      v185 = v118 & v116;
    }
    if ( !v178 )
    {
      v88 = v166;
LABEL_244:
      v79 = v175;
      v128 = v179;
      goto LABEL_245;
    }
    v123 = v180;
    v124 = *(unsigned __int8 **)(v180 + 20);
    if ( v124 )
    {
      v100 = SepBuildCapeSecurityDescriptor((int)&v207, v124, v176, v178);
      if ( v100 < 0 )
      {
        if ( !v169 )
          SeUnlockSubjectContext(v10);
        if ( v170[4] )
          ((void (*)(void))SepRmDereferenceCapTable)();
        v135 = v166;
        goto LABEL_253;
      }
      v125 = v8[2];
      if ( (*(_DWORD *)(v123 + 24) & 0x100) != 0 )
      {
        v126 = 0;
        if ( (v125 & 0x2000000) == 0 )
          v125 |= v8[3];
      }
      else
      {
        v126 = v8[3];
      }
      memset(v209, 0, 44);
      SepAccessCheckEx(
        (int)&v207,
        v127,
        v10[2],
        *v10,
        v125,
        0,
        0,
        (_DWORD *)v8[5],
        v126,
        a6,
        (unsigned int *)&v189,
        0,
        &v204,
        (int)&v214,
        v165,
        v173,
        a7,
        (int)v203,
        (int)&v166,
        v193);
      v128 = v179;
      v129 = v189;
      v130 = v175;
      *((_BYTE *)v179 + 4) = 1;
      v79 = v130 & v129;
      v131 = v181 | v129;
    }
    else
    {
      v128 = v179;
      v132 = v175;
      *((_BYTE *)v179 + 4) = 1;
      v79 = v132 & v114;
      v131 = v181 | v114;
    }
    v88 = v166;
    *v128 = v131;
    v175 = v79;
LABEL_245:
    v133 = v170;
    v89 = v184 + 1;
    v134 = (unsigned int)++v187 >= v170[8];
    ++v184;
    v179 = v128 + 2;
    if ( v134 )
      goto LABEL_261;
  }
  if ( v98 < 0 )
    goto LABEL_248;
  v101 = v177;
  if ( !SeTokenIsRestricted((int)v177) )
  {
LABEL_211:
    v91 = v198;
    if ( !v198 && v99 != 1 )
      goto LABEL_244;
    goto LABEL_213;
  }
  v102 = (_DWORD *)v101[159];
  if ( v102 )
    v103 = v102[75];
  else
    v103 = 0;
  if ( v102 )
    v104 = v102[73];
  else
    v104 = 0;
  if ( v102 )
    v105 = v102[74];
  else
    v105 = 0;
  if ( v102 )
    v106 = v102[72];
  else
    v106 = 0;
  v100 = AuthzBasepEvaluateAceCondition(
           (int)v101,
           v101[119],
           v88,
           v106,
           v105,
           v104,
           v103,
           *(_DWORD **)(v180 + 12),
           *(_DWORD *)(v180 + 8),
           1u,
           1u,
           &v191);
  if ( v100 >= 0 )
  {
    v99 = v191;
    goto LABEL_211;
  }
LABEL_248:
  if ( !v169 )
    SeUnlockSubjectContext(v10);
  if ( v170[4] )
    ((void (*)(void))SepRmDereferenceCapTable)();
  v135 = v88;
LABEL_253:
  **(_DWORD **)(v7 + 8) = 0;
  **(_DWORD **)(v7 + 12) = v100;
  SepFreeResourceInfo(v135);
  if ( v78 )
    ExFreePoolWithTag(v78);
  return 0;
}
