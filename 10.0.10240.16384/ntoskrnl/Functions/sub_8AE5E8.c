// sub_8AE5E8 
 
int __fastcall sub_8AE5E8(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  int *v4; // r2
  int v7; // r9
  int v8; // r4
  int *v9; // r3
  unsigned int i; // r1
  unsigned int v11; // r0
  int v12; // r4
  _DWORD *v13; // r1
  int v14; // r0
  unsigned int v15; // r10
  __int64 v16; // kr00_8
  int *v17; // r3
  unsigned int j; // r1
  unsigned int v19; // r0
  int v20; // r4
  int *v21; // r1
  int v22; // r0
  unsigned int k; // r1
  unsigned int v24; // r3
  int v25; // r0
  int v26; // r6
  unsigned int v27; // r7
  _DWORD *v28; // r2
  unsigned int v29; // r3
  unsigned int v30; // r3
  unsigned int v31; // r4
  int v32; // r0
  unsigned int v33; // r6
  int *v34; // r3
  unsigned int l; // r0
  unsigned int v36; // r1
  int v37; // r4
  int v38; // lr
  _DWORD *v39; // r10
  int *v40; // r3
  unsigned int m; // r0
  unsigned int v42; // r1
  int v43; // r4
  _DWORD *v44; // r7
  int v45; // r9
  unsigned int n; // r1
  unsigned int v47; // r3
  int v48; // r0
  unsigned int *v49; // r3
  int v50; // r1
  unsigned int v51; // r8
  int v52; // r4
  int v53; // r0
  int v55; // r3
  _DWORD *v56; // r2
  int v57; // r9
  int v58; // r0
  unsigned int v59; // r6
  unsigned int v60; // r3
  unsigned int v61; // r6
  unsigned int v62; // r7
  unsigned int v63; // r1
  unsigned int v64; // r3
  unsigned int v65; // r2
  int v66; // r0
  unsigned int v67; // r3
  unsigned int v68; // r2
  unsigned int v69; // r3
  int v70; // r6
  int v71; // r0
  unsigned int v72; // r2
  unsigned int v73; // r3
  unsigned int v74; // r0
  _DWORD *v75; // r1
  int v76; // r3
  unsigned int v77; // r2
  unsigned int v78; // r3
  unsigned int v79; // r0
  _DWORD *v80; // r1
  unsigned int v81; // r2
  unsigned int v82; // r3
  unsigned int v83; // r2
  unsigned int v84; // r3
  unsigned int v85; // r2
  unsigned int v86; // r0
  unsigned int *v87; // r1
  unsigned int v88; // r0
  _DWORD *v89; // r1
  int v90; // r3
  int v91; // [sp+0h] [bp-88h] BYREF
  int v92; // [sp+18h] [bp-70h]
  unsigned int v93; // [sp+1Ch] [bp-6Ch] BYREF
  int v94; // [sp+20h] [bp-68h] BYREF
  int v95; // [sp+24h] [bp-64h] BYREF
  int v96; // [sp+28h] [bp-60h]
  int v97; // [sp+2Ch] [bp-5Ch]
  int v98; // [sp+30h] [bp-58h]
  int v99; // [sp+34h] [bp-54h]
  unsigned int v100; // [sp+38h] [bp-50h]
  int v101; // [sp+40h] [bp-48h]
  int v102; // [sp+44h] [bp-44h]
  unsigned int v103; // [sp+48h] [bp-40h]
  unsigned int v104; // [sp+4Ch] [bp-3Ch]
  int v105; // [sp+50h] [bp-38h]
  int v106; // [sp+54h] [bp-34h]
  int v107; // [sp+58h] [bp-30h] BYREF
  int v108; // [sp+5Ch] [bp-2Ch]
  int v109; // [sp+60h] [bp-28h]
  int v110; // [sp+64h] [bp-24h]
  unsigned int v111; // [sp+68h] [bp-20h]

  v4 = (int *)a1[2];
  v105 = a2;
  v108 = 0;
  v7 = 0;
  v92 = 0;
  v98 = 0;
  v94 = 0;
  if ( v4 && *a1 > 3 )
  {
    v9 = v4;
    for ( i = 0; i < 3; ++i )
    {
      v11 = (unsigned int)(v9 + 1);
      v12 = *v9;
      if ( v9 + 1 < v9 )
        goto LABEL_15;
      v9 = (int *)(v12 + v11);
      if ( v12 + v11 < v11 )
        goto LABEL_15;
    }
    v13 = v9 + 1;
    v14 = *v9;
    if ( v9 + 1 < v9 )
    {
LABEL_15:
      v8 = -1073741675;
      v96 = v102;
      v97 = v101;
    }
    else
    {
      v8 = 0;
      if ( !v14 )
        v13 = 0;
      if ( v14 != 8 )
        goto LABEL_12;
      v16 = *(_QWORD *)v13;
      v96 = v13[1];
      v97 = v16;
    }
  }
  else
  {
    v8 = -1073741811;
    v96 = v102;
    v97 = v101;
  }
  if ( v8 < 0 )
    goto LABEL_13;
  if ( v4 && *a1 > 4 )
  {
    v17 = v4;
    for ( j = 0; j < 4; ++j )
    {
      v19 = (unsigned int)(v17 + 1);
      v20 = *v17;
      if ( v17 + 1 < v17 )
        goto LABEL_29;
      v17 = (int *)(v20 + v19);
      if ( v20 + v19 < v19 )
        goto LABEL_29;
    }
    v21 = v17 + 1;
    v22 = *v17;
    if ( v17 + 1 < v17 )
    {
LABEL_29:
      v8 = -1073741675;
    }
    else
    {
      v8 = 0;
      if ( !v22 )
        v21 = 0;
      if ( v22 != 4 )
      {
LABEL_12:
        v8 = -1073741789;
LABEL_13:
        v15 = v104;
        goto LABEL_91;
      }
      v108 = *v21;
    }
  }
  else
  {
    v8 = -1073741811;
  }
  if ( v8 < 0 )
    goto LABEL_13;
  if ( !v4 || *a1 <= 5 )
  {
    v8 = -1073741811;
LABEL_50:
    v26 = v99;
    v29 = v100;
    goto LABEL_51;
  }
  for ( k = 0; k < 5; ++k )
  {
    v24 = (unsigned int)(v4 + 1);
    v25 = *v4;
    if ( v4 + 1 < v4 )
      goto LABEL_49;
    v4 = (int *)(v25 + v24);
    if ( v25 + v24 < v24 )
      goto LABEL_49;
  }
  v26 = (int)(v4 + 1);
  v27 = *v4;
  if ( v4 + 1 < v4 )
  {
LABEL_49:
    v8 = -1073741675;
    goto LABEL_50;
  }
  v8 = 0;
  if ( !v27
    || (v27 & 1) != 0
    || *(_WORD *)(v26 + 2 * (v27 >> 1) - 2)
    || StringCbLengthW(v26, v27, &v93) < 0
    || v93 + 2 != v27 )
  {
LABEL_40:
    v8 = -1073741762;
    goto LABEL_13;
  }
  v29 = v93 >> 1;
LABEL_51:
  if ( v8 < 0 )
    goto LABEL_13;
  v30 = v29 + 1;
  v31 = 2 * v30;
  if ( !(2 * v30) )
    goto LABEL_40;
  v32 = ExAllocatePoolWithTag(1, 2 * v30, 542329939);
  v93 = v32;
  if ( !v32 )
  {
    v8 = -1073741801;
    v98 = v94;
    goto LABEL_13;
  }
  memmove(v32, v26, v31);
  v98 = v94;
  v28 = (_DWORD *)a1[2];
  if ( !v28 )
    goto LABEL_42;
  v33 = *a1;
  if ( *a1 <= 6 )
    goto LABEL_42;
  v34 = (int *)a1[2];
  for ( l = 0; l < 6; ++l )
  {
    v36 = (unsigned int)(v34 + 1);
    v37 = *v34;
    if ( v34 + 1 < v34 )
      goto LABEL_207;
    v34 = (int *)(v37 + v36);
    if ( v37 + v36 < v36 )
      goto LABEL_207;
  }
  v38 = *v34;
  v39 = v34 + 1;
  v95 = *v34;
  if ( v34 + 1 < v34 )
  {
LABEL_207:
    v8 = -1073741675;
    goto LABEL_43;
  }
  if ( !v38 )
    v39 = 0;
  if ( v33 <= 7 )
  {
LABEL_42:
    v8 = -1073741811;
LABEL_43:
    v15 = v93;
    goto LABEL_91;
  }
  v40 = v28;
  for ( m = 0; m < 7; ++m )
  {
    v42 = (unsigned int)(v40 + 1);
    v43 = *v40;
    if ( v40 + 1 < v40 )
      goto LABEL_207;
    v40 = (int *)(v43 + v42);
    if ( v43 + v42 < v42 )
      goto LABEL_207;
  }
  v44 = v40 + 1;
  v45 = *v40;
  if ( v40 + 1 < v40 )
  {
    v8 = -1073741675;
LABEL_206:
    v15 = v93;
    v7 = 0;
    goto LABEL_91;
  }
  if ( !v45 )
    v44 = 0;
  if ( v33 > 8 )
  {
    for ( n = 0; n < 8; ++n )
    {
      v47 = (unsigned int)(v28 + 1);
      v48 = *v28;
      if ( v28 + 1 < v28 )
        goto LABEL_84;
      v28 = (_DWORD *)(v48 + v47);
      if ( v48 + v47 < v47 )
        goto LABEL_84;
    }
    v49 = v28 + 1;
    v50 = *v28;
    if ( v28 + 1 < v28 )
    {
LABEL_84:
      v8 = -1073741675;
      goto LABEL_85;
    }
    v8 = 0;
    if ( !v50 )
      v49 = 0;
    if ( v50 != 4 )
    {
      v8 = -1073741789;
      goto LABEL_206;
    }
    v51 = *v49;
  }
  else
  {
    v8 = -1073741811;
LABEL_85:
    v51 = v103;
  }
  if ( v8 < 0 )
    goto LABEL_206;
  if ( v51 )
  {
    v52 = 0;
    v53 = ExAllocatePoolWithTag(1, v51, 542329939);
    v92 = v53;
    if ( !v53 )
    {
      v8 = -1073741801;
      v15 = v93;
LABEL_90:
      v7 = v92;
      goto LABEL_91;
    }
    v38 = v95;
    v98 = v94;
  }
  else
  {
    v52 = 1;
    v53 = 0;
  }
  if ( off_920484 )
  {
    if ( v52 )
      v55 = 0;
    else
      v55 = v53;
    v56 = v39;
    v15 = v93;
    v57 = off_920484(v108, v93, v56, v38, v44, v45, v55, v51, &v94);
    v98 = v94;
  }
  else
  {
    v57 = -1073741637;
    v15 = v93;
  }
  v58 = RtlUIntAdd(4u, 4, &v95);
  v8 = v58;
  if ( v58 < 0 )
    v59 = v111;
  else
    v59 = v95;
  if ( v58 < 0 )
    goto LABEL_116;
  v8 = RtlUIntAdd(4u, 8, &v95);
  if ( v8 < 0 )
    goto LABEL_116;
  v60 = v95 + v59;
  if ( v95 + v59 < v59 )
    goto LABEL_145;
  v61 = v51 + 4;
  if ( v51 >= 0xFFFFFFFC )
  {
    v8 = -1073741675;
LABEL_116:
    v63 = v95;
    goto LABEL_117;
  }
  v62 = v61 + v60;
  if ( v61 + v60 < v60 )
    goto LABEL_145;
  v8 = RtlUIntAdd(4u, 4, &v95);
  if ( v8 < 0 )
    goto LABEL_116;
  v63 = v95 + v62;
  if ( v95 + v62 < v62 )
    goto LABEL_145;
  v8 = 0;
LABEL_117:
  if ( v8 < 0 )
    goto LABEL_90;
  if ( v63 >= 0xFFFFFFF8 )
  {
LABEL_145:
    v8 = -1073741675;
    goto LABEL_90;
  }
  v64 = (v63 + 15) & 0xFFFFFFF8;
  if ( v64 >= v63 + 8 )
  {
    v65 = v64 + 8;
    if ( v64 + 8 < v64 )
      goto LABEL_130;
    v8 = 0;
  }
  else
  {
    v8 = -1073741675;
    v65 = v105;
  }
  if ( v8 < 0 )
    goto LABEL_90;
  v66 = *(_DWORD *)(v105 + 8);
  v67 = v65 + 4;
  if ( v65 < 0xFFFFFFFC )
  {
    v68 = v65 + 8;
    if ( v67 + 4 >= v67 )
    {
      v69 = v68 + v66;
      if ( v68 + v66 >= v68 && v69 + 4 >= v69 && v69 + 4 + *(_DWORD *)(v105 + 16) >= v69 + 4 )
      {
        v8 = 0;
        goto LABEL_131;
      }
    }
  }
LABEL_130:
  v8 = -1073741675;
LABEL_131:
  if ( v8 < 0 )
    goto LABEL_90;
  if ( !a4 )
  {
    v8 = -1073741811;
    goto LABEL_90;
  }
  v8 = 0;
  a4[1] = v63;
  if ( v63 )
  {
    v71 = ExAllocatePoolWithTag(1, v63, 542329939);
    v70 = v94;
    if ( v71 )
    {
      a4[2] = v71;
      *a4 = 0;
    }
    else
    {
      v8 = -1073741801;
    }
  }
  else
  {
    v8 = -1073741762;
    v70 = v98;
  }
  if ( v8 < 0 )
    goto LABEL_90;
  v106 = v57 | 0x10000000;
  if ( &v91 == (int *)-84 )
  {
    v8 = -1073741811;
LABEL_156:
    if ( v8 < 0 )
      goto LABEL_90;
    goto LABEL_157;
  }
  v72 = a4[2];
  if ( v72 )
  {
    v74 = 0;
    v75 = (_DWORD *)a4[2];
    if ( *a4 )
    {
      while ( *v75 < 0xFFFFFFFC )
      {
        if ( (_DWORD *)((char *)v75 + *v75 + 4) < v75 )
          goto LABEL_145;
        ++v74;
        v75 = (_DWORD *)((char *)v75 + *v75 + 4);
        if ( v74 >= *a4 )
          goto LABEL_150;
      }
      v8 = -1073741675;
    }
    else
    {
LABEL_150:
      if ( v75 + 1 < v75 )
        goto LABEL_145;
      v8 = 0;
      if ( (unsigned int)(v75 + 2) > v72 + a4[1] )
        goto LABEL_152;
      v76 = v106;
      *v75 = 4;
      v75[1] = v76;
      v70 = v94;
      ++*a4;
    }
    goto LABEL_156;
  }
  v73 = a4[1];
  if ( v73 + 8 < v73 )
  {
LABEL_144:
    a4[1] = -1;
    goto LABEL_145;
  }
  a4[1] = v73 + 8;
  ++*a4;
LABEL_157:
  v109 = v97;
  v110 = v96;
  if ( &v91 == (int *)-96 )
  {
    v8 = -1073741811;
    goto LABEL_170;
  }
  v77 = a4[2];
  if ( !v77 )
  {
    v78 = a4[1];
    if ( v78 + 12 >= v78 )
    {
      a4[1] = v78 + 12;
      ++*a4;
      goto LABEL_171;
    }
    goto LABEL_144;
  }
  v79 = 0;
  v80 = (_DWORD *)a4[2];
  if ( !*a4 )
  {
LABEL_165:
    if ( v80 + 1 < v80 )
      goto LABEL_145;
    v8 = 0;
    if ( (unsigned int)(v80 + 3) <= v77 + a4[1] )
    {
      *v80 = 8;
      v80[1] = v109;
      v80[2] = v110;
      v70 = v94;
      ++*a4;
      goto LABEL_170;
    }
LABEL_152:
    v8 = -1073741789;
    goto LABEL_90;
  }
  while ( *v80 < 0xFFFFFFFC )
  {
    if ( (_DWORD *)((char *)v80 + *v80 + 4) < v80 )
      goto LABEL_145;
    ++v79;
    v80 = (_DWORD *)((char *)v80 + *v80 + 4);
    if ( v79 >= *a4 )
      goto LABEL_165;
  }
  v8 = -1073741675;
LABEL_170:
  if ( v8 < 0 )
    goto LABEL_90;
LABEL_171:
  v7 = v92;
  if ( v92 )
  {
    if ( !v51 )
      goto LABEL_173;
  }
  else if ( v51 )
  {
LABEL_173:
    v8 = -1073741811;
    goto LABEL_174;
  }
  v83 = a4[2];
  if ( v83 )
  {
    v86 = 0;
    v87 = (unsigned int *)a4[2];
    if ( !*a4 )
    {
LABEL_191:
      if ( v87 + 1 < v87 )
        goto LABEL_185;
      v8 = 0;
      if ( (unsigned int)v87 + v51 + 4 > v83 + a4[1] )
        goto LABEL_193;
      *v87 = v51;
      if ( v7 )
        memmove((int)(v87 + 1), v7, v51);
      v70 = v94;
      ++*a4;
      goto LABEL_174;
    }
    while ( *v87 < 0xFFFFFFFC )
    {
      if ( (unsigned int *)((char *)v87 + *v87 + 4) < v87 )
        goto LABEL_185;
      ++v86;
      v87 = (unsigned int *)((char *)v87 + *v87 + 4);
      if ( v86 >= *a4 )
        goto LABEL_191;
    }
  }
  else if ( v51 < 0xFFFFFFFC )
  {
    v84 = a4[1];
    v85 = v51 + 4 + v84;
    if ( v85 < v84 )
    {
LABEL_184:
      a4[1] = -1;
      goto LABEL_185;
    }
    a4[1] = v85;
    ++*a4;
    goto LABEL_175;
  }
  v8 = -1073741675;
LABEL_174:
  if ( v8 < 0 )
    goto LABEL_91;
LABEL_175:
  v107 = v70;
  if ( &v107 )
  {
    v81 = a4[2];
    if ( !v81 )
    {
      v82 = a4[1];
      if ( v82 + 8 >= v82 )
      {
        a4[1] = v82 + 8;
        ++*a4;
        v8 = 0;
        goto LABEL_91;
      }
      goto LABEL_184;
    }
    v88 = 0;
    v89 = (_DWORD *)a4[2];
    if ( *a4 )
    {
      while ( *v89 < 0xFFFFFFFC && (_DWORD *)((char *)v89 + *v89 + 4) >= v89 )
      {
        ++v88;
        v89 = (_DWORD *)((char *)v89 + *v89 + 4);
        if ( v88 >= *a4 )
          goto LABEL_201;
      }
      goto LABEL_185;
    }
LABEL_201:
    if ( v89 + 1 < v89 )
    {
LABEL_185:
      v8 = -1073741675;
      goto LABEL_91;
    }
    v8 = 0;
    if ( (unsigned int)(v89 + 2) <= v81 + a4[1] )
    {
      v90 = v107;
      *v89 = 4;
      v89[1] = v90;
      ++*a4;
      goto LABEL_91;
    }
LABEL_193:
    v8 = -1073741789;
    goto LABEL_91;
  }
  v8 = -1073741811;
LABEL_91:
  if ( v15 )
    ExFreePoolWithTag(v15);
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v8;
}
