// RtlpSetSecurityObject 
 
int __fastcall RtlpSetSecurityObject(int a1, int a2, int a3, int a4, char a5, int a6, _DWORD *a7)
{
  __int16 v8; // r0
  int v9; // r6
  unsigned int v11; // r5
  unsigned __int8 *v12; // lr
  int v13; // r3
  __int16 v14; // r2
  int v15; // r1
  int v16; // r10
  int v17; // r2
  int v18; // r1
  char v19; // r9
  int v20; // r2
  unsigned __int16 *v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r8
  _DWORD *v26; // lr
  int v27; // r1
  __int16 v28; // r10
  int v29; // r2
  int v30; // r6
  unsigned int v31; // r10
  int v32; // r3
  unsigned int v33; // r9
  unsigned int v34; // r7
  unsigned int v35; // r8
  _BYTE *v36; // r0
  _BYTE *v37; // r4
  int v38; // r5
  int v39; // r1
  __int16 v40; // r2
  unsigned int v41; // r3
  char v42; // r3
  int v43; // r7
  unsigned int v44; // r3
  int v45; // r5
  unsigned int v46; // r6
  int v47; // r6
  unsigned int v48; // r9
  unsigned int v49; // r4
  unsigned __int8 *v50; // r7
  unsigned __int8 *v51; // r8
  int v53; // r3
  unsigned int v54; // r3
  unsigned __int16 *v55; // r10
  unsigned __int8 *v56; // r0
  int v57; // r1
  int v58; // r2
  int v59; // r3
  unsigned __int8 *v60; // r9
  unsigned __int16 *v61; // r3
  char v62; // lr
  unsigned __int8 *v63; // r2
  int v64; // r1
  unsigned __int8 *v65; // lr
  __int16 v66; // r2
  int v67; // r9
  int v68; // r3
  int v69; // r3
  int v70; // r2
  __int16 v71; // r1
  int v72; // r3
  int v73; // r3
  __int16 v74; // r2
  int v75; // r1
  int v76; // r2
  int v77; // r3
  unsigned __int8 *v78; // r0
  int v79; // r1
  int v80; // r2
  unsigned __int8 *v81; // r9
  int v82; // r3
  int v83; // r0
  __int16 v84; // r3
  int v85; // r2
  int v86; // r2
  int v87; // lr
  __int16 v88; // r3
  int v89; // r6
  int v90; // r0
  int v91; // r2
  __int16 v92; // r0
  __int16 v93; // r1
  __int16 v94; // r2
  __int16 v95; // r3
  __int16 v96; // r3
  int v97; // r2
  int v98; // r2
  int v99; // r1
  int v100; // lr
  __int16 v101; // r3
  int v102; // r6
  int v103; // r0
  int v104; // r2
  __int16 v105; // r0
  __int16 v106; // r1
  __int16 v107; // r2
  __int16 v108; // r3
  __int16 v109; // r3
  int v110; // r2
  int v111; // r2
  int v112; // r1
  int v113; // lr
  __int16 v114; // r3
  int v115; // r6
  int v116; // r0
  int v117; // r2
  __int16 v118; // r0
  __int16 v119; // r1
  __int16 v120; // r2
  __int16 v121; // r3
  __int16 v122; // r2
  __int16 v123; // r3
  int v124; // r2
  int v125; // r2
  int v126; // r10
  int v127; // lr
  __int16 v128; // r3
  int v129; // r6
  int v130; // r0
  int v131; // r1
  int v132; // r2
  __int16 v133; // r0
  __int16 v134; // r1
  __int16 v135; // r2
  __int16 v136; // r3
  __int16 v137; // r2
  __int16 v138; // r4
  int v139; // r2
  int v140; // r3
  int v141; // r3
  __int16 v142; // r1
  int v143; // r0
  int v144; // r0
  int v145; // r0
  unsigned int i; // r3
  int v147; // r0
  int v148; // r3
  int v149; // r0
  __int16 v150; // [sp+18h] [bp-100h]
  unsigned __int8 *v151; // [sp+1Ch] [bp-FCh]
  int v152; // [sp+1Ch] [bp-FCh]
  unsigned int v153; // [sp+20h] [bp-F8h] BYREF
  unsigned __int8 *v154; // [sp+24h] [bp-F4h]
  unsigned int v155; // [sp+28h] [bp-F0h] BYREF
  char v156[4]; // [sp+2Ch] [bp-ECh] BYREF
  unsigned int v157; // [sp+30h] [bp-E8h]
  unsigned __int16 *v158; // [sp+34h] [bp-E4h]
  int v159; // [sp+38h] [bp-E0h]
  unsigned __int8 *v160; // [sp+3Ch] [bp-DCh]
  unsigned __int8 *v161; // [sp+40h] [bp-D8h]
  int v162; // [sp+44h] [bp-D4h]
  int v163; // [sp+48h] [bp-D0h] BYREF
  int v164; // [sp+4Ch] [bp-CCh]
  char v165[4]; // [sp+50h] [bp-C8h] BYREF
  int v166; // [sp+54h] [bp-C4h] BYREF
  int v167; // [sp+58h] [bp-C0h] BYREF
  int v168; // [sp+60h] [bp-B8h] BYREF
  char v169; // [sp+64h] [bp-B4h]
  char v170; // [sp+65h] [bp-B3h]
  unsigned int v171; // [sp+68h] [bp-B0h] BYREF
  int v172; // [sp+6Ch] [bp-ACh]
  unsigned int v173; // [sp+70h] [bp-A8h] BYREF
  unsigned __int8 *v174; // [sp+74h] [bp-A4h] BYREF
  int v175; // [sp+78h] [bp-A0h] BYREF
  int v176; // [sp+7Ch] [bp-9Ch] BYREF
  unsigned int v177; // [sp+80h] [bp-98h]
  unsigned int v178; // [sp+84h] [bp-94h]
  int *v179[4]; // [sp+88h] [bp-90h] BYREF
  unsigned int v180; // [sp+98h] [bp-80h] BYREF
  unsigned int v181; // [sp+9Ch] [bp-7Ch] BYREF
  BOOL v182; // [sp+A0h] [bp-78h]
  int v183; // [sp+A4h] [bp-74h]
  int v184; // [sp+A8h] [bp-70h]
  unsigned int v185; // [sp+ACh] [bp-6Ch]
  int v186; // [sp+B0h] [bp-68h]
  int v187; // [sp+B4h] [bp-64h]
  int v188; // [sp+B8h] [bp-60h]
  int v189; // [sp+BCh] [bp-5Ch]
  int v190; // [sp+C0h] [bp-58h]
  int v191; // [sp+C4h] [bp-54h]
  unsigned __int16 v192[4]; // [sp+C8h] [bp-50h] BYREF
  int v193; // [sp+D0h] [bp-48h]

  v8 = *(_WORD *)(a3 + 2);
  v9 = a4;
  v11 = 0;
  v163 = 0;
  v164 = a4;
  v159 = a3;
  v160 = 0;
  v188 = 0;
  v189 = 0;
  v190 = 0;
  v191 = 0;
  v176 = 0;
  v177 = 0;
  v156[0] = 0;
  v183 = 0;
  v184 = 0;
  v186 = 0;
  v187 = 0;
  v185 = 0;
  v180 = 0;
  v181 = 0;
  v173 = 0;
  v174 = 0;
  v161 = 0;
  v162 = 0;
  v166 = 0;
  v167 = 0;
  v157 = 0;
  v155 = 0;
  v182 = 0;
  v168 = 0;
  v150 = 0x8000;
  if ( (v8 & 0x10) != 0 )
  {
    if ( (v8 & 0x8000) != 0 )
    {
      v68 = *(_DWORD *)(a3 + 12);
      if ( !v68 )
        return sub_7FB874();
      v12 = (unsigned __int8 *)(a3 + v68);
    }
    else
    {
      v12 = *(unsigned __int8 **)(a3 + 12);
    }
  }
  else
  {
    v12 = 0;
  }
  v13 = *(_DWORD *)v9;
  v151 = v12;
  v14 = *(_WORD *)(*(_DWORD *)v9 + 2);
  if ( (v14 & 0x10) != 0 )
  {
    if ( (*(_WORD *)(*(_DWORD *)v9 + 2) & 0x8000) != 0 )
    {
      v15 = *(_DWORD *)(v13 + 12);
      if ( v15 )
        v16 = v15 + v13;
      else
        v16 = 0;
    }
    else
    {
      v16 = *(_DWORD *)(v13 + 12);
    }
  }
  else
  {
    v16 = 0;
  }
  v154 = (unsigned __int8 *)v16;
  if ( (v14 & 0x8000) == 0 )
    return -1073741593;
  v175 = (v8 & 0x80) != 0;
  v178 = (v8 & 0x40) != 0;
  v17 = a2 & 0x80;
  v18 = 2048;
  if ( (a2 & 0x10000) != 0 )
  {
    LOBYTE(a2) = -1;
    if ( !v17 )
      LOBYTE(a2) = 127;
    if ( !v16 && !v12 )
    {
      LOBYTE(a2) = a2 & 7;
      if ( (v8 & 0x10) != 0 )
      {
        LOBYTE(a2) = a2 | 8;
      }
      else if ( (v8 & 0x800) != 0 )
      {
        v168 = 1;
      }
    }
  }
  v19 = a5;
  if ( (a2 & 1) != 0 )
  {
    v182 = (a2 & 4) == 0;
    if ( (v8 & 0x8000) != 0 )
    {
      v72 = *(_DWORD *)(a3 + 4);
      if ( v72 )
        v21 = (unsigned __int16 *)(v72 + a3);
      else
        v21 = 0;
    }
    else
    {
      v21 = *(unsigned __int16 **)(a3 + 4);
    }
    v190 = 1;
    v158 = v21;
    if ( (a5 & 8) == 0 )
    {
      SeCaptureSubjectContext(v179, 2048, 1, (int)v21);
      if ( !SepValidOwnerSubjectContext(v179, v158, v175) )
      {
        SeReleaseSubjectContext((int)v179);
        return -1073741734;
      }
      SeReleaseSubjectContext((int)v179);
      v21 = v158;
    }
  }
  else
  {
    v20 = *(_DWORD *)(v13 + 4);
    if ( !v20 )
      return -1073741734;
    v21 = (unsigned __int16 *)(v13 + v20);
    v158 = v21;
    if ( !v21 )
      return -1073741734;
  }
  if ( !RtlValidSid(v21, v18) )
    return -1073741734;
  if ( (a2 & 2) != 0 )
  {
    if ( (*(_WORD *)(a3 + 2) & 0x8000) != 0 )
    {
      v73 = *(_DWORD *)(a3 + 8);
      if ( v73 )
        v25 = a3 + v73;
      else
        v25 = 0;
    }
    else
    {
      v25 = *(_DWORD *)(a3 + 8);
    }
    v188 = 1;
  }
  else
  {
    v23 = *(_DWORD *)v9;
    if ( (*(_WORD *)(*(_DWORD *)v9 + 2) & 0x8000) != 0 )
    {
      v24 = *(_DWORD *)(v23 + 8);
      if ( !v24 )
        return -1073741733;
      v25 = v24 + v23;
    }
    else
    {
      v25 = *(_DWORD *)(v23 + 8);
    }
  }
  v172 = v25;
  if ( !v25 || !RtlValidSid(v25, v22) )
    return -1073741733;
  v26 = a7;
  v27 = 1024;
  if ( (a2 & 0xF8) == 0 )
  {
    v11 = v16;
    v28 = 0x8000;
    v152 = v11;
    goto LABEL_21;
  }
  v54 = a2 & 0x10;
  v171 = v54;
  if ( (a2 & 0x10) != 0 )
  {
    v153 = 0;
    v55 = 0;
    do
    {
      v56 = RtlFindAceByType((int)v151, 17, &v153);
      v60 = v56;
      if ( v56 )
      {
        v55 = (unsigned __int16 *)(v56 + 8);
        v155 = v56[1];
        v59 = *((_DWORD *)v56 + 1) & 0xFFFFFFF8;
        if ( v59 )
          return -1073740730;
      }
      SeCaptureSubjectContext(v179, v57, v58, v59);
      if ( !SepValidLabelSubjectContext(v179, v55, (unsigned __int16 *)v155, v61) )
      {
        SeReleaseSubjectContext((int)v179);
        return -1073740730;
      }
      SeReleaseSubjectContext((int)v179);
      v54 = ++v153;
    }
    while ( v60 );
    v27 = 1024;
  }
  if ( (a2 & 0x80) != 0 )
  {
    SeCaptureSubjectContext(v179, 1024, 16, v54);
    if ( !SepLocateTokenTrustLevel((int *)v179, v75, v76, v77) )
    {
LABEL_177:
      SeReleaseSubjectContext((int)v179);
      return -1073741790;
    }
    v153 = 0;
    while ( 1 )
    {
      v78 = RtlFindAceByType((int)v151, 20, &v153);
      v81 = v78;
      if ( v78 )
      {
        v82 = *((_DWORD *)v78 + 1);
        if ( (v82 & 0xFF000000) != 0 )
        {
          v47 = -1073740730;
          SeReleaseSubjectContext((int)v179);
          return v47;
        }
        v83 = SepLocateTokenTrustLevel((int *)v179, v79, v80, v82);
        if ( !v83 || RtlSidDominatesForTrust(v83, (int)(v81 + 8), v165) < 0 || !v165[0] )
          goto LABEL_177;
      }
      ++v153;
      if ( !v81 )
      {
        SeReleaseSubjectContext((int)v179);
        v27 = 1024;
        break;
      }
    }
  }
  v62 = a5;
  if ( (a2 & 8) != 0 )
  {
    if ( (a5 & 2) != 0 )
    {
      v84 = *(_WORD *)(v159 + 2);
      if ( (v84 & 0x10) != 0 )
        v85 = 4;
      else
        v85 = 0;
      v157 = v85;
      if ( (v84 & 0x20) != 0 )
        v86 = 8;
      else
        v86 = 0;
      v162 = v86;
      if ( (v84 & 0x800) != 0 )
        v155 = 1024;
      else
        v155 = 0;
      if ( (v84 & 0x2000) != 0 )
        v87 = 4096;
      else
        v87 = 0;
      v88 = *(_WORD *)(*(_DWORD *)v9 + 2);
      if ( (v88 & 0x10) != 0 )
        v89 = 4;
      else
        v89 = 0;
      if ( (v88 & 0x20) != 0 )
        v90 = 8;
      else
        v90 = 0;
      if ( (v88 & 0x800) == 0 )
        v27 = 0;
      if ( (v88 & 0x2000) != 0 )
        v91 = 4096;
      else
        v91 = 0;
      v47 = RtlpComputeMergedAcl(
              v154,
              v91 | v27 | v90 | v89,
              v151,
              v155 | v87 | v162 | v157,
              v158,
              v25,
              a7,
              2,
              &v163,
              &v153);
      if ( v47 < 0 )
      {
        v162 = v163;
        v49 = 0;
        v50 = 0;
        v51 = 0;
        v48 = 0;
        goto LABEL_65;
      }
      v189 = 1;
      if ( (v153 & 4) != 0 )
        v92 = 16;
      else
        v92 = 0;
      if ( (v153 & 8) != 0 )
        v93 = 32;
      else
        v93 = 0;
      if ( (v153 & 0x400) != 0 )
        v94 = 2048;
      else
        v94 = 0;
      if ( (v153 & 0x1000) != 0 )
        v95 = 0x2000;
      else
        v95 = 0;
      v150 = v95 | v94 | v93 | v92 | 0x8010;
      v9 = v164;
      v62 = a5;
      v162 = v163;
    }
    else
    {
      v162 = (int)v151;
      v71 = *(_WORD *)(v159 + 2);
      v150 = v71 & 0x2000 | 0x8010;
      if ( (v71 & 0xA00) == 2560 )
      {
        v150 = v71 & 0x2000 | 0x8810;
        v63 = v154;
        goto LABEL_90;
      }
    }
    v63 = v154;
  }
  else
  {
    v63 = v154;
    v162 = (int)v154;
  }
LABEL_90:
  if ( (a2 & 0x20) != 0 )
  {
    if ( (v62 & 2) != 0 )
    {
      v96 = *(_WORD *)(v159 + 2);
      if ( (v96 & 0x10) != 0 )
        v97 = 4;
      else
        v97 = 0;
      v157 = v97;
      if ( (v96 & 0x20) != 0 )
        v98 = 8;
      else
        v98 = 0;
      v99 = 1024;
      v163 = v98;
      if ( (v96 & 0x800) != 0 )
        v155 = 1024;
      else
        v155 = 0;
      if ( (v96 & 0x2000) != 0 )
        v100 = 4096;
      else
        v100 = 0;
      v101 = *(_WORD *)(*(_DWORD *)v9 + 2);
      if ( (v101 & 0x10) != 0 )
        v102 = 4;
      else
        v102 = 0;
      if ( (v101 & 0x20) != 0 )
        v103 = 8;
      else
        v103 = 0;
      if ( (v101 & 0x800) == 0 )
        v99 = 0;
      if ( (v101 & 0x2000) != 0 )
        v104 = 4096;
      else
        v104 = 0;
      v47 = RtlpComputeMergedAcl(
              v154,
              (v104 | v99 | v103 | v102) & 0xFFFFEFFF,
              v151,
              (v155 | v100 | v163 | v157) & 0xFFFFEFFF,
              v158,
              v25,
              a7,
              2,
              &v166,
              &v153);
      if ( v47 < 0 )
      {
        v49 = 0;
        v50 = 0;
        v51 = (unsigned __int8 *)v166;
        v48 = 0;
        goto LABEL_65;
      }
      v187 = 1;
      if ( (v153 & 4) != 0 )
        v105 = 16;
      else
        v105 = 0;
      if ( (v153 & 8) != 0 )
        v106 = 32;
      else
        v106 = 0;
      if ( (v153 & 0x400) != 0 )
        v107 = 2048;
      else
        v107 = 0;
      if ( (v153 & 0x1000) != 0 )
        v108 = 0x2000;
      else
        v108 = 0;
      v150 |= v108 | v107 | v106 | v105 | 0x10;
      v9 = v164;
      v62 = a5;
      v64 = v159;
      v160 = (unsigned __int8 *)v166;
    }
    else
    {
      v64 = v159;
      v74 = *(_WORD *)(v159 + 2);
      v160 = v151;
      v150 |= v74 & 0x2000 | 0x10;
      if ( (v74 & 0xA00) == 2560 )
        v150 |= 0x800u;
    }
    v63 = v154;
  }
  else
  {
    v64 = v159;
    v160 = v63;
  }
  if ( (a2 & 0x40) != 0 )
  {
    if ( (v62 & 2) != 0 )
    {
      v109 = *(_WORD *)(v64 + 2);
      if ( (v109 & 0x10) != 0 )
        v110 = 4;
      else
        v110 = 0;
      v163 = v110;
      if ( (v109 & 0x20) != 0 )
        v111 = 8;
      else
        v111 = 0;
      v166 = v111;
      v112 = 1024;
      if ( (v109 & 0x800) != 0 )
        v155 = 1024;
      else
        v155 = 0;
      if ( (v109 & 0x2000) != 0 )
        v113 = 4096;
      else
        v113 = 0;
      v114 = *(_WORD *)(*(_DWORD *)v9 + 2);
      if ( (v114 & 0x10) != 0 )
        v115 = 4;
      else
        v115 = 0;
      if ( (v114 & 0x20) != 0 )
        v116 = 8;
      else
        v116 = 0;
      if ( (v114 & 0x800) == 0 )
        v112 = 0;
      if ( (v114 & 0x2000) != 0 )
        v117 = 4096;
      else
        v117 = 0;
      v47 = RtlpComputeMergedAcl(
              v154,
              (v117 | v112 | v116 | v115) & 0xFFFFEFFF,
              v151,
              (v155 | v113 | v166 | v163) & 0xFFFFEFFF,
              v158,
              v25,
              a7,
              2,
              &v167,
              &v153);
      if ( v47 < 0 )
      {
        v49 = 0;
        v50 = (unsigned __int8 *)v167;
        v48 = 0;
        goto LABEL_64;
      }
      v191 = 1;
      if ( (v153 & 4) != 0 )
        v118 = 16;
      else
        v118 = 0;
      if ( (v153 & 8) != 0 )
        v119 = 32;
      else
        v119 = 0;
      if ( (v153 & 0x400) != 0 )
        v120 = 2048;
      else
        v120 = 0;
      if ( (v153 & 0x1000) != 0 )
        v121 = 0x2000;
      else
        v121 = 0;
      v150 |= v121 | v120 | v119 | v118 | 0x10;
      v9 = v164;
      v62 = a5;
      v64 = v159;
      v161 = (unsigned __int8 *)v167;
    }
    else
    {
      v122 = *(_WORD *)(v64 + 2);
      v161 = v151;
      v150 |= v122 & 0x2000 | 0x10;
      if ( (v122 & 0xA00) == 2560 )
        v150 |= 0x800u;
    }
    v63 = v154;
  }
  else
  {
    v161 = v63;
  }
  if ( (a2 & 0x80) != 0 )
  {
    if ( (v62 & 2) != 0 )
    {
      v123 = *(_WORD *)(v64 + 2);
      if ( (v123 & 0x10) != 0 )
        v124 = 4;
      else
        v124 = 0;
      v167 = v124;
      if ( (v123 & 0x20) != 0 )
        v125 = 8;
      else
        v125 = 0;
      v155 = v125;
      if ( (v123 & 0x800) != 0 )
        v126 = 1024;
      else
        v126 = 0;
      if ( (v123 & 0x2000) != 0 )
        v127 = 4096;
      else
        v127 = 0;
      v128 = *(_WORD *)(*(_DWORD *)v9 + 2);
      if ( (v128 & 0x10) != 0 )
        v129 = 4;
      else
        v129 = 0;
      if ( (v128 & 0x20) != 0 )
        v130 = 8;
      else
        v130 = 0;
      if ( (v128 & 0x800) != 0 )
        v131 = 1024;
      else
        v131 = 0;
      if ( (v128 & 0x2000) != 0 )
        v132 = 4096;
      else
        v132 = 0;
      v47 = RtlpComputeMergedAcl(
              v154,
              (v132 | v131 | v130 | v129) & 0xFFFFEFFF,
              v151,
              (v127 | v126 | v155 | v167) & 0xFFFFEFFF,
              v158,
              v25,
              a7,
              2,
              &v174,
              &v153);
      if ( v47 < 0 )
      {
        v49 = (unsigned int)v174;
        v48 = 0;
        goto LABEL_63;
      }
      v184 = 1;
      if ( (v153 & 4) != 0 )
        v133 = 16;
      else
        v133 = 0;
      if ( (v153 & 8) != 0 )
        v134 = 32;
      else
        v134 = 0;
      if ( (v153 & 0x400) != 0 )
        v135 = 2048;
      else
        v135 = 0;
      if ( (v153 & 0x1000) != 0 )
        v136 = 0x2000;
      else
        v136 = 0;
      v65 = v174;
      v28 = v136 | v135 | v134 | v133 | v150 | 0x10;
      v64 = v159;
      v150 = v28;
      v157 = (unsigned int)v174;
    }
    else
    {
      v137 = *(_WORD *)(v64 + 2);
      v65 = v151;
      v28 = v137 & 0x2000 | v150 | 0x10;
      v157 = (unsigned int)v151;
      v150 = v28;
      if ( (v137 & 0xA00) == 2560 )
      {
        v28 |= 0x800u;
        v150 = v28;
      }
    }
    v63 = v154;
  }
  else
  {
    v28 = v150;
    v65 = v63;
    v157 = (unsigned int)v63;
  }
  if ( v171 )
  {
    v66 = *(_WORD *)(v64 + 2);
    v28 |= v66 & 0x2000 | 0x10;
    v150 = v28;
    if ( (v66 & 0xA00) == 2560 )
    {
      v28 |= 0x800u;
      v150 = v28;
    }
  }
  else
  {
    v151 = v63;
  }
  v67 = v162;
  v47 = RtlpCombineAcls(v162, v151, v160, v161, v65, &v173, 0);
  if ( v47 < 0 )
    goto LABEL_375;
  v11 = v173;
  v152 = v173;
  if ( !v67 && v173 && !*(_WORD *)(v173 + 4) )
  {
    ExFreePoolWithTag(v173);
    v11 = 0;
    v152 = 0;
  }
  v9 = v164;
  v19 = a5;
  v26 = a7;
  v186 = 1;
  v27 = 1024;
LABEL_21:
  if ( (a2 & 4) == 0 )
  {
    v69 = *(_DWORD *)v9;
    if ( (*(_WORD *)(*(_DWORD *)v9 + 2) & 4) != 0 )
    {
      if ( (*(_WORD *)(*(_DWORD *)v9 + 2) & 0x8000) != 0 )
      {
        v70 = *(_DWORD *)(v69 + 16);
        if ( v70 )
          v30 = v70 + v69;
        else
          v30 = 0;
      }
      else
      {
        v30 = *(_DWORD *)(v69 + 16);
      }
    }
    else
    {
      v30 = 0;
    }
    goto LABEL_29;
  }
  if ( (v19 & 1) == 0 )
  {
    v29 = *(unsigned __int16 *)(v159 + 2);
    if ( (v29 & 4) != 0 )
    {
      if ( (v29 & 0x8000) != 0 )
      {
        v53 = *(_DWORD *)(v159 + 16);
        if ( v53 )
          v30 = v159 + v53;
        else
          v30 = 0;
      }
      else
      {
        v30 = *(_DWORD *)(v159 + 16);
      }
    }
    else
    {
      v30 = 0;
    }
    v150 = v29 & 0x1000 | v28 | 4;
    if ( (v29 & 0x500) == 1280 )
      v150 = v29 & 0x1000 | v28 | 0x404;
LABEL_28:
    if ( v175 )
    {
      SeCaptureSubjectContext(v179, v27, v29, v175);
      SepGetDefaultsSubjectContext(v179, &v174, &v173, &v171, &v175, &v176, &v155, &v180);
      v47 = RtlpCreateServerAcl(v30, v178, v171, &v181, v156);
      SeReleaseSubjectContext((int)v179);
      if ( v47 < 0 )
      {
        v48 = v181;
        v176 = (unsigned __int8)v156[0];
LABEL_60:
        if ( v183 )
          ExFreePoolWithTag(v185);
        goto LABEL_62;
      }
      v177 = v181;
      v30 = v181;
      v176 = (unsigned __int8)v156[0];
    }
LABEL_29:
    v31 = 4 * (*((unsigned __int8 *)v158 + 1) + 2);
    v32 = 4 * (*(unsigned __int8 *)(v25 + 1) + 2);
    v33 = (v31 + 3) & 0xFFFFFFFC;
    v178 = (v32 + 3) & 0xFFFFFFFC;
    v171 = v32;
    if ( v11 )
      v34 = (*(unsigned __int16 *)(v11 + 2) + 3) & 0xFFFFFFFC;
    else
      v34 = 0;
    if ( v30 )
      v35 = (*(unsigned __int16 *)(v30 + 2) + 3) & 0xFFFFFFFC;
    else
      v35 = 0;
    v36 = (_BYTE *)ExAllocatePoolWithTag(a6, v35 + v34 + ((v32 + 3) & 0xFFFFFFFC) + v33 + 20, 1683187027);
    v37 = v36;
    if ( !v36 )
    {
      v47 = -1073741801;
      goto LABEL_59;
    }
    memset(v36, 0, 20);
    *v37 = 1;
    v38 = (int)(v37 + 20);
    if ( v168 )
      v150 |= 0x800u;
    v39 = v159;
    v40 = v150 | *((_WORD *)v37 + 1);
    *((_WORD *)v37 + 1) = v40;
    if ( (*(_WORD *)(v39 + 2) & 0x4000) != 0 )
    {
      v37[1] = *(_BYTE *)(v39 + 1);
      *((_WORD *)v37 + 1) = v40 | 0x4000;
    }
    if ( v152 )
    {
      memmove((int)(v37 + 20), v152, *(unsigned __int16 *)(v152 + 2));
      RtlpApplyAclToObject((int)(v37 + 20), a7);
      *((_DWORD *)v37 + 3) = 20;
      v41 = *(unsigned __int16 *)(v152 + 2);
      if ( v34 > v41 )
        memset((_BYTE *)(v41 + v38), 0, v34 - v41);
      v38 += v34;
    }
    else
    {
      *((_DWORD *)v37 + 3) = 0;
    }
    v42 = v150;
    v43 = v164;
    if ( (v150 & 0x10) == 0 )
    {
      *((_WORD *)v37 + 1) |= *(_WORD *)(*(_DWORD *)v164 + 2) & 0x2830;
      v42 = v150;
    }
    if ( v30 )
    {
      memmove(v38, v30, *(unsigned __int16 *)(v30 + 2));
      RtlpApplyAclToObject(v38, a7);
      *((_DWORD *)v37 + 4) = v38 - (_DWORD)v37;
      v44 = *(unsigned __int16 *)(v30 + 2);
      if ( v35 > v44 )
        memset((_BYTE *)(v44 + v38), 0, v35 - v44);
      v42 = v150;
      v38 += v35;
    }
    else
    {
      *((_DWORD *)v37 + 4) = 0;
    }
    if ( (v42 & 4) == 0 )
    {
      *((_WORD *)v37 + 1) |= *(_WORD *)(*(_DWORD *)v43 + 2) & 0x140C;
      if ( v182 )
      {
        v168 = 0;
        v169 = 0;
        v170 = 3;
        v145 = RtlInitializeSid((int)v192, (int)&v168, 1u);
        v47 = v145;
        if ( v145 < 0 )
        {
LABEL_58:
          v11 = v152;
LABEL_59:
          v48 = v177;
          goto LABEL_60;
        }
        v193 = 4;
        for ( i = 0; ; i = v153 + 1 )
        {
          v153 = i;
          if ( (*((_WORD *)v37 + 1) & 4) != 0 )
          {
            if ( (*((_WORD *)v37 + 1) & 0x8000) != 0 )
            {
              v148 = *((_DWORD *)v37 + 4);
              v147 = (int)(v148 ? &v37[v148] : 0);
            }
            else
            {
              v147 = *((_DWORD *)v37 + 4);
            }
          }
          else
          {
            v147 = 0;
          }
          v149 = RtlFindAceBySid(v147, v192, &v153);
          if ( !v149 )
            break;
          *(_BYTE *)(v149 + 1) = *(_BYTE *)(v149 + 1) & 0xF4 | 8;
        }
        v43 = v164;
      }
    }
    memmove(v38, (int)v158, v31);
    if ( v31 < v33 )
      memset((_BYTE *)(v38 + v31), 0, v33 - v31);
    *((_DWORD *)v37 + 1) = v38 - (_DWORD)v37;
    v45 = v38 + v33;
    if ( !v190 )
      *((_WORD *)v37 + 1) |= *(_WORD *)(*(_DWORD *)v43 + 2) & 1;
    v46 = v171;
    memmove(v45, v172, v171);
    if ( v46 < v178 )
      memset((_BYTE *)(v45 + v46), 0, v178 - v46);
    *((_DWORD *)v37 + 2) = v45 - (_DWORD)v37;
    if ( !v188 )
      *((_WORD *)v37 + 1) |= *(_WORD *)(*(_DWORD *)v43 + 2) & 2;
    *(_DWORD *)v43 = v37;
    v47 = 0;
    goto LABEL_58;
  }
  v138 = *(_WORD *)(v159 + 2);
  if ( (v138 & 4) != 0 )
  {
    if ( (*(_WORD *)(v159 + 2) & 0x8000) != 0 )
    {
      v140 = *(_DWORD *)(v159 + 16);
      if ( v140 )
        v139 = v159 + v140;
      else
        v139 = 0;
    }
    else
    {
      v139 = *(_DWORD *)(v159 + 16);
    }
  }
  else
  {
    v139 = 0;
  }
  v141 = *(_DWORD *)v9;
  v142 = *(_WORD *)(*(_DWORD *)v9 + 2);
  if ( (v142 & 4) != 0 )
  {
    if ( (*(_WORD *)(*(_DWORD *)v9 + 2) & 0x8000) != 0 )
    {
      v144 = *(_DWORD *)(v141 + 16);
      if ( v144 )
        v143 = v144 + v141;
      else
        v143 = 0;
    }
    else
    {
      v143 = *(_DWORD *)(v141 + 16);
    }
  }
  else
  {
    v143 = 0;
  }
  v47 = RtlpComputeMergedAcl(v143, v142 & 0x140C, v139, v138 & 0x140C, v158, v25, v26, 1, &v180, &v153);
  if ( v47 >= 0 )
  {
    v183 = 1;
    v29 = 5128;
    v185 = v180;
    v30 = v180;
    v150 = v153 & 0x1408 | v28 | 4;
    goto LABEL_28;
  }
LABEL_375:
  v48 = 0;
LABEL_62:
  v49 = v157;
LABEL_63:
  v50 = v161;
LABEL_64:
  v51 = v160;
LABEL_65:
  if ( v162 && v189 )
    ExFreePoolWithTag(v162);
  if ( v51 && v187 )
    ExFreePoolWithTag((unsigned int)v51);
  if ( v50 && v191 )
    ExFreePoolWithTag((unsigned int)v50);
  if ( v49 && v184 )
    ExFreePoolWithTag(v49);
  if ( v11 && v186 )
    ExFreePoolWithTag(v11);
  if ( v176 )
    ExFreePoolWithTag(v48);
  return v47;
}
