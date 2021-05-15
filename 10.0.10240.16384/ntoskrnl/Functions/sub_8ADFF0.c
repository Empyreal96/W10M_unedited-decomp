// sub_8ADFF0 
 
int __fastcall sub_8ADFF0(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  int v6; // r4
  unsigned int *v7; // r2
  int *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  int *v12; // r1
  int v13; // r0
  int v14; // r9
  int v15; // r10
  unsigned int j; // r1
  unsigned int v17; // r3
  unsigned int v18; // r0
  int v19; // r5
  unsigned int v20; // r6
  int *v21; // r3
  unsigned int v22; // r3
  unsigned int v23; // r3
  unsigned int v24; // r6
  int v25; // r0
  unsigned int v26; // r4
  unsigned int v27; // r5
  int *v28; // r2
  unsigned int k; // r1
  unsigned int v30; // r0
  int v31; // r4
  _DWORD *v32; // lr
  int v33; // r8
  unsigned int l; // r0
  unsigned int v35; // r2
  int v36; // r1
  _DWORD *v37; // r4
  int v38; // r5
  int v39; // r8
  int v40; // r0
  unsigned int v41; // r5
  unsigned int v42; // r1
  unsigned int v43; // r3
  unsigned int v44; // r2
  int v45; // r0
  unsigned int v46; // r3
  unsigned int v47; // r2
  unsigned int v48; // r3
  _DWORD *v49; // r0
  unsigned int v50; // r2
  unsigned int v51; // r3
  unsigned int v53; // r0
  _DWORD *v54; // r1
  int v55[4]; // [sp+0h] [bp-58h] BYREF
  unsigned int v56; // [sp+10h] [bp-48h]
  int v57; // [sp+14h] [bp-44h]
  unsigned int v58; // [sp+18h] [bp-40h] BYREF
  int v59; // [sp+1Ch] [bp-3Ch]
  unsigned int v60; // [sp+20h] [bp-38h]
  int v61; // [sp+28h] [bp-30h]
  int v62; // [sp+2Ch] [bp-2Ch]
  int v63; // [sp+30h] [bp-28h] BYREF
  int v64; // [sp+34h] [bp-24h]

  v56 = 0;
  v59 = a2;
  if ( !a2 || !a4 )
    return -1073741811;
  v7 = (unsigned int *)a1[2];
  if ( !v7 || *a1 <= 3 )
  {
    v6 = -1073741811;
LABEL_18:
    v15 = v61;
    v14 = v62;
    goto LABEL_19;
  }
  v8 = (int *)a1[2];
  for ( i = 0; i < 3; ++i )
  {
    v10 = (unsigned int)(v8 + 1);
    v11 = *v8;
    if ( v8 + 1 < v8 )
      goto LABEL_17;
    v8 = (int *)(v11 + v10);
    if ( v11 + v10 < v10 )
      goto LABEL_17;
  }
  v12 = v8 + 1;
  v13 = *v8;
  if ( v8 + 1 < v8 )
  {
LABEL_17:
    v6 = -1073741675;
    goto LABEL_18;
  }
  v6 = 0;
  if ( !v13 )
    v12 = 0;
  if ( v13 != 8 )
    return -1073741789;
  v14 = v12[1];
  v15 = *v12;
LABEL_19:
  if ( v6 < 0 )
    return v6;
  if ( !v7 || *a1 <= 4 )
  {
    v6 = -1073741811;
LABEL_38:
    v22 = v55[2];
    v19 = v55[3];
    goto LABEL_39;
  }
  for ( j = 0; j < 4; ++j )
  {
    v17 = (unsigned int)(v7 + 1);
    v18 = *v7;
    if ( v7 + 1 < v7 )
      goto LABEL_37;
    v7 = (unsigned int *)(v18 + v17);
    if ( v18 + v17 < v17 )
      goto LABEL_37;
  }
  v19 = (int)(v7 + 1);
  v20 = *v7;
  if ( v7 + 1 < v7 )
  {
LABEL_37:
    v6 = -1073741675;
    goto LABEL_38;
  }
  v6 = 0;
  if ( !v20
    || (v20 & 1) != 0
    || *(_WORD *)(v19 + 2 * (v20 >> 1) - 2)
    || StringCbLengthW(v19, v20, &v58) < 0
    || v58 + 2 != v20 )
  {
    return -1073741762;
  }
  v22 = v58 >> 1;
LABEL_39:
  if ( v6 < 0 )
    return v6;
  v23 = v22 + 1;
  v24 = 2 * v23;
  if ( !(2 * v23) )
    return -1073741762;
  v25 = ExAllocatePoolWithTag(1, 2 * v23, 542329939);
  v26 = v25;
  if ( !v25 )
    return -1073741801;
  memmove(v25, v19, v24);
  v56 = v26;
  v21 = (int *)a1[2];
  if ( !v21 )
    goto LABEL_31;
  v27 = *a1;
  if ( *a1 <= 5 )
    goto LABEL_31;
  v28 = (int *)a1[2];
  for ( k = 0; k < 5; ++k )
  {
    v30 = (unsigned int)(v28 + 1);
    v31 = *v28;
    if ( v28 + 1 < v28 )
      goto LABEL_103;
    v28 = (int *)(v31 + v30);
    if ( v31 + v30 < v30 )
      goto LABEL_103;
  }
  v32 = v28 + 1;
  v33 = *v28;
  if ( v28 + 1 < v28 )
    goto LABEL_103;
  if ( !v33 )
    v32 = 0;
  if ( v27 <= 6 )
  {
LABEL_31:
    v6 = -1073741811;
    goto LABEL_104;
  }
  for ( l = 0; l < 6; ++l )
  {
    v35 = (unsigned int)(v21 + 1);
    v36 = *v21;
    if ( v21 + 1 < v21 )
      goto LABEL_103;
    v21 = (int *)(v36 + v35);
    if ( v36 + v35 < v35 )
      goto LABEL_103;
  }
  v37 = v21 + 1;
  v38 = *v21;
  if ( v21 + 1 < v21 )
    goto LABEL_103;
  if ( !v38 )
    v37 = 0;
  if ( off_92048C )
    v39 = off_92048C(v56, v32, v33, v37, v38);
  else
    v39 = -1073741637;
  v6 = v39;
  if ( v39 < 0 )
    goto LABEL_104;
  v40 = RtlUIntAdd(4u, 4, &v58);
  v6 = v40;
  if ( v40 < 0 )
    v41 = v60;
  else
    v41 = v58;
  if ( v40 < 0 || (v6 = RtlUIntAdd(4u, 8, &v58), v6 < 0) )
  {
    v42 = v59;
  }
  else
  {
    v42 = v41 + v58;
    if ( v41 + v58 < v41 )
      goto LABEL_103;
    v6 = 0;
  }
  if ( v6 < 0 )
    goto LABEL_104;
  if ( v42 >= 0xFFFFFFF8 )
    goto LABEL_103;
  v43 = (v42 + 15) & 0xFFFFFFF8;
  if ( v43 >= v42 + 8 )
  {
    v44 = v43 + 8;
    if ( v43 + 8 < v43 )
      goto LABEL_85;
    v6 = 0;
  }
  else
  {
    v6 = -1073741675;
    v44 = v59;
  }
  if ( v6 < 0 )
    goto LABEL_104;
  v45 = *(_DWORD *)(v59 + 8);
  v46 = v44 + 4;
  if ( v44 < 0xFFFFFFFC )
  {
    v47 = v44 + 8;
    if ( v46 + 4 >= v46 )
    {
      v48 = v47 + v45;
      if ( v47 + v45 >= v47 && v48 + 4 >= v48 && v48 + 4 + *(_DWORD *)(v59 + 16) >= v48 + 4 )
      {
        v6 = 0;
        goto LABEL_86;
      }
    }
  }
LABEL_85:
  v6 = -1073741675;
LABEL_86:
  if ( v6 < 0 )
    goto LABEL_104;
  a4[1] = v42;
  if ( !v42 )
  {
    v6 = -1073741762;
    goto LABEL_104;
  }
  v49 = (_DWORD *)ExAllocatePoolWithTag(1, v42, 542329939);
  if ( !v49 )
  {
    v6 = -1073741801;
    goto LABEL_104;
  }
  a4[2] = (unsigned int)v49;
  *a4 = 0;
  v57 = v39 | 0x10000000;
  if ( v55 == (int *)-20 )
  {
    v6 = -1073741811;
  }
  else
  {
    if ( v49 + 1 < v49 )
      goto LABEL_103;
    v6 = 0;
    if ( v49 + 2 > (_DWORD *)((char *)v49 + a4[1]) )
      goto LABEL_94;
    *v49 = 4;
    v49[1] = v57;
    ++*a4;
  }
  if ( v6 < 0 )
    goto LABEL_104;
  v63 = v15;
  v64 = v14;
  if ( !&v63 )
    goto LABEL_31;
  v50 = a4[2];
  if ( v50 )
  {
    v53 = 0;
    v54 = (_DWORD *)a4[2];
    if ( *a4 )
    {
      while ( *v54 < 0xFFFFFFFC && (_DWORD *)((char *)v54 + *v54 + 4) >= v54 )
      {
        ++v53;
        v54 = (_DWORD *)((char *)v54 + *v54 + 4);
        if ( v53 >= *a4 )
          goto LABEL_111;
      }
    }
    else
    {
LABEL_111:
      if ( v54 + 1 >= v54 )
      {
        v6 = 0;
        if ( (unsigned int)(v54 + 3) > v50 + a4[1] )
        {
LABEL_94:
          v6 = -1073741789;
          goto LABEL_104;
        }
        *v54 = 8;
        v54[1] = v63;
        v54[2] = v64;
        ++*a4;
        goto LABEL_104;
      }
    }
  }
  else
  {
    v51 = a4[1];
    if ( v51 + 12 >= v51 )
    {
      a4[1] = v51 + 12;
      ++*a4;
      v6 = 0;
      goto LABEL_104;
    }
    a4[1] = -1;
  }
LABEL_103:
  v6 = -1073741675;
LABEL_104:
  if ( v56 )
    ExFreePoolWithTag(v56);
  return v6;
}
