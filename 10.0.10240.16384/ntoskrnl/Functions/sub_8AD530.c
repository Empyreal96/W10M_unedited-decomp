// sub_8AD530 
 
int __fastcall sub_8AD530(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  int v5; // r4
  int *v6; // r2
  int *v7; // r3
  unsigned int i; // r1
  unsigned int v9; // r4
  int v10; // r6
  _DWORD *v11; // r1
  int v12; // r6
  __int64 v13; // kr00_8
  unsigned int v14; // r4
  int *v15; // r3
  unsigned int j; // r1
  unsigned int v17; // r0
  int v18; // r6
  int v19; // r1
  _DWORD *v20; // r9
  int *v21; // r3
  unsigned int k; // r1
  unsigned int v23; // r0
  int v24; // r6
  _DWORD *v25; // r8
  int v26; // r10
  unsigned int l; // r1
  unsigned int v28; // r3
  int v29; // r0
  _DWORD *v30; // r6
  int v31; // r7
  int v32; // r8
  int v33; // r4
  unsigned int v34; // r7
  unsigned int v35; // r6
  unsigned int v36; // r1
  unsigned int v37; // r3
  unsigned int v38; // r2
  int v39; // r0
  unsigned int v40; // r3
  unsigned int v41; // r2
  unsigned int v42; // r3
  _DWORD *v43; // r0
  unsigned int v44; // r2
  unsigned int v45; // r3
  unsigned int v47; // r0
  _DWORD *v48; // r1
  unsigned int v49; // r2
  unsigned int v50; // r3
  unsigned int v51; // r0
  _DWORD *v52; // r1
  int v53; // [sp+0h] [bp-80h] BYREF
  int v54; // [sp+10h] [bp-70h] BYREF
  int v55; // [sp+14h] [bp-6Ch]
  int v56; // [sp+18h] [bp-68h]
  int v57; // [sp+20h] [bp-60h]
  int v58; // [sp+24h] [bp-5Ch]
  int v59; // [sp+28h] [bp-58h]
  int v60; // [sp+2Ch] [bp-54h]
  int v61; // [sp+30h] [bp-50h]
  int v62; // [sp+34h] [bp-4Ch]
  int v63; // [sp+38h] [bp-48h]
  char v64[64]; // [sp+40h] [bp-40h] BYREF

  v59 = a2;
  if ( !a1 || !a2 || !a4 )
    return -1073741811;
  v6 = (int *)a1[2];
  if ( v6 && *a1 > 3 )
  {
    v7 = (int *)a1[2];
    for ( i = 0; i < 3; ++i )
    {
      v9 = (unsigned int)(v7 + 1);
      v10 = *v7;
      if ( v7 + 1 < v7 )
        goto LABEL_18;
      v7 = (int *)(v10 + v9);
      if ( v10 + v9 < v9 )
        goto LABEL_18;
    }
    v11 = v7 + 1;
    v12 = *v7;
    if ( v7 + 1 < v7 )
    {
LABEL_18:
      v5 = -1073741675;
      v55 = v58;
      v56 = v57;
    }
    else
    {
      v5 = 0;
      if ( !v12 )
        v11 = 0;
      if ( v12 != 8 )
        return -1073741789;
      v13 = *(_QWORD *)v11;
      v55 = v11[1];
      v56 = v13;
    }
  }
  else
  {
    v5 = -1073741811;
    v55 = v58;
    v56 = v57;
  }
  if ( v5 < 0 )
    return v5;
  if ( !v6 )
    return -1073741811;
  v14 = *a1;
  if ( *a1 <= 4 )
    return -1073741811;
  v15 = v6;
  for ( j = 0; j < 4; ++j )
  {
    v17 = (unsigned int)(v15 + 1);
    v18 = *v15;
    if ( v15 + 1 < v15 )
      return -1073741675;
    v15 = (int *)(v18 + v17);
    if ( v18 + v17 < v17 )
      return -1073741675;
  }
  v19 = *v15;
  v20 = v15 + 1;
  v54 = *v15;
  if ( v15 + 1 < v15 )
    return -1073741675;
  if ( !v19 )
    v20 = 0;
  if ( v14 <= 5 )
    return -1073741811;
  v21 = v6;
  for ( k = 0; k < 5; ++k )
  {
    v23 = (unsigned int)(v21 + 1);
    v24 = *v21;
    if ( v21 + 1 < v21 )
      return -1073741675;
    v21 = (int *)(v24 + v23);
    if ( v24 + v23 < v23 )
      return -1073741675;
  }
  v25 = v21 + 1;
  v26 = *v21;
  if ( v21 + 1 < v21 )
    return -1073741675;
  if ( !v26 )
    v25 = 0;
  if ( v14 <= 6 )
    return -1073741811;
  for ( l = 0; l < 6; ++l )
  {
    v28 = (unsigned int)(v6 + 1);
    v29 = *v6;
    if ( v6 + 1 < v6 )
      return -1073741675;
    v6 = (int *)(v29 + v28);
    if ( v29 + v28 < v28 )
      return -1073741675;
  }
  v30 = v6 + 1;
  v31 = *v6;
  if ( v6 + 1 < v6 )
    return -1073741675;
  if ( !v31 )
    v30 = 0;
  if ( off_920494 )
    v32 = off_920494(v20, v54, v25, v26, v30, v31, v64, 32);
  else
    v32 = -1073741637;
  v5 = v32;
  if ( v32 >= 0 )
  {
    if ( RtlUIntAdd(4u, 4, &v54) < 0 )
      v33 = v63;
    else
      v33 = v54;
    v34 = v33;
    if ( RtlUIntAdd(4u, 8, &v54) >= 0 )
      v33 = v54;
    v35 = v33 + v34;
    if ( v33 + v34 < v34 )
      return -1073741675;
    if ( RtlUIntAdd(4u, 32, &v54) >= 0 )
      v33 = v54;
    v36 = v33 + v35;
    if ( v33 + v35 < v35 || v36 >= 0xFFFFFFF8 )
      return -1073741675;
    v37 = (v36 + 15) & 0xFFFFFFF8;
    if ( v37 >= v36 + 8 )
    {
      v38 = v37 + 8;
      if ( v37 + 8 < v37 )
        goto LABEL_70;
      v5 = 0;
    }
    else
    {
      v5 = -1073741675;
      v38 = v59;
    }
    if ( v5 < 0 )
      return v5;
    v39 = *(_DWORD *)(v59 + 8);
    v40 = v38 + 4;
    if ( v38 < 0xFFFFFFFC )
    {
      v41 = v38 + 8;
      if ( v40 + 4 >= v40 )
      {
        v42 = v41 + v39;
        if ( v41 + v39 >= v41 && v42 + 4 >= v42 && v42 + 4 + *(_DWORD *)(v59 + 16) >= v42 + 4 )
        {
          v5 = 0;
          goto LABEL_71;
        }
      }
    }
LABEL_70:
    v5 = -1073741675;
LABEL_71:
    if ( v5 < 0 )
      return v5;
    a4[1] = v36;
    if ( !v36 )
      return -1073741762;
    v43 = (_DWORD *)ExAllocatePoolWithTag(1, v36, 542329939);
    if ( !v43 )
      return -1073741801;
    a4[2] = (unsigned int)v43;
    *a4 = 0;
    v60 = v32 | 0x10000000;
    if ( &v53 == (int *)-44 )
    {
      v5 = -1073741811;
    }
    else
    {
      if ( v43 + 1 < v43 )
        return -1073741675;
      v5 = 0;
      if ( v43 + 2 > (_DWORD *)((char *)v43 + a4[1]) )
        return -1073741789;
      *v43 = 4;
      v43[1] = v60;
      ++*a4;
    }
    if ( v5 < 0 )
      return v5;
    v61 = v56;
    v62 = v55;
    if ( &v53 == (int *)-48 )
    {
      v5 = -1073741811;
    }
    else
    {
      v44 = a4[2];
      if ( !v44 )
      {
        v45 = a4[1];
        if ( v45 + 12 < v45 )
          goto LABEL_86;
        a4[1] = v45 + 12;
        ++*a4;
LABEL_99:
        if ( v64 )
        {
          v49 = a4[2];
          if ( !v49 )
          {
            v50 = a4[1];
            if ( v50 + 36 >= v50 )
            {
              a4[1] = v50 + 36;
              ++*a4;
              return 0;
            }
LABEL_86:
            a4[1] = -1;
            return -1073741675;
          }
          v51 = 0;
          v52 = (_DWORD *)a4[2];
          if ( *a4 )
          {
            while ( *v52 < 0xFFFFFFFC && (_DWORD *)((char *)v52 + *v52 + 4) >= v52 )
            {
              ++v51;
              v52 = (_DWORD *)((char *)v52 + *v52 + 4);
              if ( v51 >= *a4 )
                goto LABEL_107;
            }
          }
          else
          {
LABEL_107:
            if ( v52 + 1 >= v52 )
            {
              v5 = 0;
              if ( (unsigned int)(v52 + 9) <= v49 + a4[1] )
              {
                *v52 = 32;
                memmove((int)(v52 + 1), (int)v64, 0x20u);
                ++*a4;
                return v5;
              }
              return -1073741789;
            }
          }
          return -1073741675;
        }
        return -1073741811;
      }
      v47 = 0;
      v48 = (_DWORD *)a4[2];
      if ( *a4 )
      {
        while ( *v48 < 0xFFFFFFFC )
        {
          if ( (_DWORD *)((char *)v48 + *v48 + 4) < v48 )
            return -1073741675;
          ++v47;
          v48 = (_DWORD *)((char *)v48 + *v48 + 4);
          if ( v47 >= *a4 )
            goto LABEL_93;
        }
        v5 = -1073741675;
      }
      else
      {
LABEL_93:
        if ( v48 + 1 < v48 )
          return -1073741675;
        v5 = 0;
        if ( (unsigned int)(v48 + 3) > v44 + a4[1] )
          return -1073741789;
        *v48 = 8;
        v48[1] = v61;
        v48[2] = v62;
        ++*a4;
      }
    }
    if ( v5 < 0 )
      return v5;
    goto LABEL_99;
  }
  return v5;
}
