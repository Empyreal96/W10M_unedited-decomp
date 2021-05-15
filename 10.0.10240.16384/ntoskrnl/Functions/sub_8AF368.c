// sub_8AF368 
 
int __fastcall sub_8AF368(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  int v6; // r4
  int *v7; // r2
  _DWORD *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  __int64 *v12; // r1
  int v13; // r0
  int *v14; // r3
  unsigned int j; // r1
  unsigned int v16; // r0
  int v17; // r4
  int *v18; // r1
  int v19; // r0
  int v20; // r3
  unsigned int k; // r1
  unsigned int v22; // r3
  int v23; // r0
  int v24; // r5
  unsigned int v25; // r6
  int *v26; // r2
  unsigned int v27; // r3
  unsigned int v28; // r3
  unsigned int v29; // r6
  int v30; // r0
  unsigned int v31; // r4
  unsigned int v32; // r5
  int *v33; // r3
  unsigned int l; // r0
  unsigned int v35; // r1
  int v36; // r4
  _DWORD *v37; // r9
  int v38; // r10
  int *v39; // r3
  unsigned int m; // r0
  unsigned int v41; // r1
  int v42; // r4
  _DWORD *v43; // lr
  int v44; // r8
  unsigned int n; // r1
  unsigned int v46; // r3
  int v47; // r0
  _DWORD *v48; // r4
  int v49; // r6
  int v50; // r8
  int v51; // r0
  unsigned int v52; // r5
  unsigned int v53; // r1
  unsigned int v54; // r3
  unsigned int v55; // r2
  int v56; // r0
  unsigned int v57; // r3
  unsigned int v58; // r2
  unsigned int v59; // r3
  _DWORD *v60; // r0
  unsigned int v61; // r2
  unsigned int v62; // r3
  unsigned int v64; // r0
  unsigned int v65; // r1
  int v66; // [sp+0h] [bp-70h] BYREF
  int v67; // [sp+10h] [bp-60h]
  __int64 v68; // [sp+14h] [bp-5Ch]
  int v69; // [sp+1Ch] [bp-54h]
  unsigned int v70; // [sp+20h] [bp-50h]
  int v71; // [sp+24h] [bp-4Ch]
  unsigned int v72; // [sp+28h] [bp-48h]
  int v73; // [sp+2Ch] [bp-44h]
  unsigned int v74; // [sp+30h] [bp-40h] BYREF
  int v75; // [sp+34h] [bp-3Ch]
  unsigned int v76; // [sp+38h] [bp-38h]
  __int64 v77; // [sp+40h] [bp-30h]
  __int64 v78; // [sp+48h] [bp-28h] BYREF

  v72 = 0;
  v75 = a2;
  if ( !a2 || !a4 )
    return -1073741811;
  v7 = (int *)a1[2];
  if ( v7 && *a1 > 3 )
  {
    v8 = (_DWORD *)a1[2];
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_17;
      v8 = (_DWORD *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_17;
    }
    v12 = (__int64 *)(v8 + 1);
    v13 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_17:
      v6 = -1073741675;
      v68 = v77;
    }
    else
    {
      v6 = 0;
      if ( !v13 )
        v12 = 0;
      if ( v13 != 8 )
        return -1073741789;
      v68 = *v12;
    }
  }
  else
  {
    v6 = -1073741811;
    v68 = v77;
  }
  if ( v6 < 0 )
    return v6;
  if ( !v7 || *a1 <= 4 )
  {
    v6 = -1073741811;
LABEL_32:
    v20 = v69;
    goto LABEL_33;
  }
  v14 = v7;
  for ( j = 0; j < 4; ++j )
  {
    v16 = (unsigned int)(v14 + 1);
    v17 = *v14;
    if ( v14 + 1 < v14 )
      goto LABEL_31;
    v14 = (int *)(v17 + v16);
    if ( v17 + v16 < v16 )
      goto LABEL_31;
  }
  v18 = v14 + 1;
  v19 = *v14;
  if ( v14 + 1 < v14 )
  {
LABEL_31:
    v6 = -1073741675;
    goto LABEL_32;
  }
  v6 = 0;
  if ( !v19 )
    v18 = 0;
  if ( v19 != 4 )
    return -1073741789;
  v20 = *v18;
LABEL_33:
  v67 = v20;
  if ( v6 < 0 )
    return v6;
  if ( !v7 || *a1 <= 5 )
  {
    v6 = -1073741811;
LABEL_52:
    v27 = v70;
    v24 = v71;
    goto LABEL_53;
  }
  for ( k = 0; k < 5; ++k )
  {
    v22 = (unsigned int)(v7 + 1);
    v23 = *v7;
    if ( v7 + 1 < v7 )
      goto LABEL_51;
    v7 = (int *)(v23 + v22);
    if ( v23 + v22 < v22 )
      goto LABEL_51;
  }
  v24 = (int)(v7 + 1);
  v25 = *v7;
  if ( v7 + 1 < v7 )
  {
LABEL_51:
    v6 = -1073741675;
    goto LABEL_52;
  }
  v6 = 0;
  if ( !v25
    || (v25 & 1) != 0
    || *(_WORD *)(v24 + 2 * (v25 >> 1) - 2)
    || StringCbLengthW(v24, v25, &v74) < 0
    || v74 + 2 != v25 )
  {
    return -1073741762;
  }
  v27 = v74 >> 1;
LABEL_53:
  if ( v6 < 0 )
    return v6;
  v28 = v27 + 1;
  v29 = 2 * v28;
  if ( !(2 * v28) )
    return -1073741762;
  v30 = ExAllocatePoolWithTag(1, 2 * v28, 542329939);
  v31 = v30;
  if ( !v30 )
    return -1073741801;
  memmove(v30, v24, v29);
  v72 = v31;
  v26 = (int *)a1[2];
  if ( !v26 )
    goto LABEL_45;
  v32 = *a1;
  if ( *a1 <= 6 )
    goto LABEL_45;
  v33 = (int *)a1[2];
  for ( l = 0; l < 6; ++l )
  {
    v35 = (unsigned int)(v33 + 1);
    v36 = *v33;
    if ( v33 + 1 < v33 )
      goto LABEL_125;
    v33 = (int *)(v36 + v35);
    if ( v36 + v35 < v35 )
      goto LABEL_125;
  }
  v37 = v33 + 1;
  v38 = *v33;
  if ( v33 + 1 < v33 )
    goto LABEL_125;
  if ( !v38 )
    v37 = 0;
  if ( v32 <= 7 )
    goto LABEL_45;
  v39 = (int *)a1[2];
  for ( m = 0; m < 7; ++m )
  {
    v41 = (unsigned int)(v39 + 1);
    v42 = *v39;
    if ( v39 + 1 < v39 )
      goto LABEL_125;
    v39 = (int *)(v42 + v41);
    if ( v42 + v41 < v41 )
      goto LABEL_125;
  }
  v43 = v39 + 1;
  v44 = *v39;
  if ( v39 + 1 < v39 )
    goto LABEL_125;
  if ( !v44 )
    v43 = 0;
  if ( v32 <= 8 )
  {
LABEL_45:
    v6 = -1073741811;
    goto LABEL_126;
  }
  for ( n = 0; n < 8; ++n )
  {
    v46 = (unsigned int)(v26 + 1);
    v47 = *v26;
    if ( v26 + 1 < v26 )
      goto LABEL_125;
    v26 = (int *)(v47 + v46);
    if ( v47 + v46 < v46 )
      goto LABEL_125;
  }
  v48 = v26 + 1;
  v49 = *v26;
  if ( v26 + 1 < v26 )
    goto LABEL_125;
  if ( !v49 )
    v48 = 0;
  if ( off_9204A4 )
    v50 = off_9204A4(v67, v72, v37, v38, v43, v44, v48, v49);
  else
    v50 = -1073741637;
  v6 = v50;
  if ( v50 < 0 )
    goto LABEL_126;
  v51 = RtlUIntAdd(4u, 4, &v74);
  v6 = v51;
  if ( v51 < 0 )
    v52 = v76;
  else
    v52 = v74;
  if ( v51 < 0 || (v6 = RtlUIntAdd(4u, 8, &v74), v6 < 0) )
  {
    v53 = v75;
  }
  else
  {
    v53 = v52 + v74;
    if ( v52 + v74 < v52 )
      goto LABEL_125;
    v6 = 0;
  }
  if ( v6 < 0 )
    goto LABEL_126;
  if ( v53 >= 0xFFFFFFF8 )
    goto LABEL_125;
  v54 = (v53 + 15) & 0xFFFFFFF8;
  if ( v54 >= v53 + 8 )
  {
    v55 = v54 + 8;
    if ( v54 + 8 < v54 )
      goto LABEL_107;
    v6 = 0;
  }
  else
  {
    v6 = -1073741675;
    v55 = v75;
  }
  if ( v6 < 0 )
    goto LABEL_126;
  v56 = *(_DWORD *)(v75 + 8);
  v57 = v55 + 4;
  if ( v55 < 0xFFFFFFFC )
  {
    v58 = v55 + 8;
    if ( v57 + 4 >= v57 )
    {
      v59 = v58 + v56;
      if ( v58 + v56 >= v58 && v59 + 4 >= v59 && v59 + 4 + *(_DWORD *)(v75 + 16) >= v59 + 4 )
      {
        v6 = 0;
        goto LABEL_108;
      }
    }
  }
LABEL_107:
  v6 = -1073741675;
LABEL_108:
  if ( v6 < 0 )
    goto LABEL_126;
  a4[1] = v53;
  if ( !v53 )
  {
    v6 = -1073741762;
    goto LABEL_126;
  }
  v60 = (_DWORD *)ExAllocatePoolWithTag(1, v53, 542329939);
  if ( !v60 )
  {
    v6 = -1073741801;
    goto LABEL_126;
  }
  a4[2] = (unsigned int)v60;
  *a4 = 0;
  v73 = v50 | 0x10000000;
  if ( &v66 == (int *)-44 )
  {
    v6 = -1073741811;
  }
  else
  {
    if ( v60 + 1 < v60 )
      goto LABEL_125;
    v6 = 0;
    if ( v60 + 2 > (_DWORD *)((char *)v60 + a4[1]) )
      goto LABEL_116;
    *v60 = 4;
    v60[1] = v73;
    ++*a4;
  }
  if ( v6 < 0 )
    goto LABEL_126;
  v78 = v68;
  if ( !&v78 )
    goto LABEL_45;
  v61 = a4[2];
  if ( v61 )
  {
    v64 = 0;
    v65 = a4[2];
    if ( *a4 )
    {
      while ( *(_DWORD *)v65 < 0xFFFFFFFC && *(_DWORD *)v65 + 4 + v65 >= v65 )
      {
        ++v64;
        v65 += *(_DWORD *)v65 + 4;
        if ( v64 >= *a4 )
          goto LABEL_133;
      }
    }
    else
    {
LABEL_133:
      if ( v65 + 4 >= v65 )
      {
        v6 = 0;
        if ( v65 + 12 > v61 + a4[1] )
        {
LABEL_116:
          v6 = -1073741789;
          goto LABEL_126;
        }
        *(_DWORD *)v65 = 8;
        *(_QWORD *)(v65 + 4) = v78;
        ++*a4;
        goto LABEL_126;
      }
    }
  }
  else
  {
    v62 = a4[1];
    if ( v62 + 12 >= v62 )
    {
      a4[1] = v62 + 12;
      ++*a4;
      v6 = 0;
      goto LABEL_126;
    }
    a4[1] = -1;
  }
LABEL_125:
  v6 = -1073741675;
LABEL_126:
  if ( v72 )
    ExFreePoolWithTag(v72);
  return v6;
}
