// sub_8AF074 
 
int __fastcall sub_8AF074(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int *v4; // r6
  int v7; // r4
  int *v8; // r3
  unsigned int i; // r2
  unsigned int v10; // r1
  int v11; // r0
  int *v12; // r2
  int v13; // r1
  int v14; // r9
  int v15; // r10
  int *v16; // r3
  unsigned int j; // r2
  unsigned int v18; // r1
  int v19; // r0
  int *v20; // r2
  int v21; // r1
  int v22; // r7
  unsigned int k; // r3
  unsigned int v24; // r2
  int v25; // r1
  int v26; // r0
  int v27; // r8
  int v28; // r0
  unsigned int v29; // r6
  unsigned int v30; // r1
  unsigned int v31; // r3
  unsigned int v32; // r2
  int v33; // r0
  unsigned int v34; // r3
  unsigned int v35; // r2
  unsigned int v36; // r3
  int v37; // r0
  unsigned int v38; // r2
  unsigned int v39; // r3
  unsigned int v41; // r0
  _DWORD *v42; // r1
  unsigned int v43; // r2
  unsigned int v44; // r3
  unsigned int v45; // r0
  _DWORD *v46; // r1
  int v47; // [sp+0h] [bp-48h] BYREF
  int v48; // [sp+8h] [bp-40h]
  unsigned int v49; // [sp+Ch] [bp-3Ch] BYREF
  int v50; // [sp+10h] [bp-38h]
  unsigned int v51; // [sp+14h] [bp-34h]
  int v52; // [sp+18h] [bp-30h]
  int v53; // [sp+1Ch] [bp-2Ch]
  int v54; // [sp+20h] [bp-28h] BYREF
  int v55; // [sp+24h] [bp-24h]

  v4 = (int *)a1[2];
  v50 = a2;
  if ( v4 && *a1 > 3u )
  {
    v8 = v4;
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_14;
      v8 = (int *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_14;
    }
    v12 = v8 + 1;
    v13 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_14:
      v7 = -1073741675;
      goto LABEL_15;
    }
    v7 = 0;
    if ( !v13 )
      v12 = 0;
    if ( v13 == 8 )
    {
      v14 = v12[1];
      v15 = *v12;
      goto LABEL_16;
    }
    return -1073741789;
  }
  v7 = -1073741811;
LABEL_15:
  v15 = v52;
  v14 = v53;
LABEL_16:
  if ( v7 < 0 )
    return v7;
  if ( v4 && *a1 > 4u )
  {
    v16 = v4;
    for ( j = 0; j < 4; ++j )
    {
      v18 = (unsigned int)(v16 + 1);
      v19 = *v16;
      if ( v16 + 1 < v16 )
        goto LABEL_29;
      v16 = (int *)(v19 + v18);
      if ( v19 + v18 < v18 )
        goto LABEL_29;
    }
    v20 = v16 + 1;
    v21 = *v16;
    if ( v16 + 1 < v16 )
    {
LABEL_29:
      v7 = -1073741675;
      goto LABEL_30;
    }
    v7 = 0;
    if ( !v21 )
      v20 = 0;
    if ( v21 == 4 )
    {
      v22 = *v20;
      goto LABEL_31;
    }
    return -1073741789;
  }
  v7 = -1073741811;
LABEL_30:
  v22 = v47;
LABEL_31:
  if ( v7 < 0 )
    return v7;
  if ( v4 && *a1 > 5u )
  {
    for ( k = 0; k < 5; ++k )
    {
      v24 = (unsigned int)(v4 + 1);
      v25 = *v4;
      if ( v4 + 1 < v4 )
        goto LABEL_42;
      v4 = (int *)(v25 + v24);
      if ( v25 + v24 < v24 )
        goto LABEL_42;
    }
    if ( v4 + 1 < v4 )
    {
LABEL_42:
      v7 = -1073741675;
      goto LABEL_43;
    }
    v7 = 0;
    if ( *v4 != 4 )
      return -1073741789;
  }
  else
  {
    v7 = -1073741811;
  }
LABEL_43:
  if ( v7 < 0 )
    return v7;
  dword_920444 = (int)ExIsAppLicensed;
  dword_920448 = (int)ExIsAppLicensedProduct;
  dword_920450 = (int)sub_447E24;
  dword_920454 = (int)ExQueryFastCacheDevLicense;
  dword_92044C = (int)ExIsWindowsToGo;
  dword_920458 = (int)sub_8AA39C;
  v26 = v22 ? ClipSpInitialize_0() : ClipSpUninitialize_0();
  v27 = v26;
  v7 = v26;
  if ( v26 < 0 )
    return v7;
  v28 = RtlUIntAdd(4u, 4, &v49);
  v7 = v28;
  if ( v28 < 0 )
    v29 = v51;
  else
    v29 = v49;
  if ( v28 < 0 || (v7 = RtlUIntAdd(4u, 8, &v49), v7 < 0) )
  {
    v30 = v50;
  }
  else
  {
    v30 = v29 + v49;
    if ( v29 + v49 < v29 )
      return -1073741675;
    v7 = 0;
  }
  if ( v7 < 0 )
    return v7;
  if ( v30 >= 0xFFFFFFF8 )
    return -1073741675;
  v31 = (v30 + 15) & 0xFFFFFFF8;
  if ( v31 >= v30 + 8 )
  {
    v32 = v31 + 8;
    if ( v31 + 8 < v31 )
      goto LABEL_69;
    v7 = 0;
  }
  else
  {
    v7 = -1073741675;
    v32 = v50;
  }
  if ( v7 < 0 )
    return v7;
  v33 = *(_DWORD *)(v50 + 8);
  v34 = v32 + 4;
  if ( v32 < 0xFFFFFFFC )
  {
    v35 = v32 + 8;
    if ( v34 + 4 >= v34 )
    {
      v36 = v35 + v33;
      if ( v35 + v33 >= v35 && v36 + 4 >= v36 && v36 + 4 + *(_DWORD *)(v50 + 16) >= v36 + 4 )
      {
        v7 = 0;
        goto LABEL_70;
      }
    }
  }
LABEL_69:
  v7 = -1073741675;
LABEL_70:
  if ( v7 < 0 )
    return v7;
  if ( !a4 )
    return -1073741811;
  v7 = 0;
  a4[1] = v30;
  if ( v30 )
  {
    v37 = ExAllocatePoolWithTag(1, v30, 542329939);
    if ( v37 )
    {
      a4[2] = v37;
      *a4 = 0;
    }
    else
    {
      v7 = -1073741801;
    }
  }
  else
  {
    v7 = -1073741762;
  }
  if ( v7 >= 0 )
  {
    v48 = v27 | 0x10000000;
    if ( &v47 == (int *)-8 )
    {
      v7 = -1073741811;
    }
    else
    {
      v38 = a4[2];
      if ( !v38 )
      {
        v39 = a4[1];
        if ( v39 + 8 < v39 )
        {
LABEL_83:
          a4[1] = -1;
          return -1073741675;
        }
        a4[1] = v39 + 8;
        ++*a4;
        goto LABEL_96;
      }
      v41 = 0;
      v42 = (_DWORD *)a4[2];
      if ( *a4 )
      {
        while ( *v42 < 0xFFFFFFFC )
        {
          if ( (_DWORD *)((char *)v42 + *v42 + 4) < v42 )
            return -1073741675;
          ++v41;
          v42 = (_DWORD *)((char *)v42 + *v42 + 4);
          if ( v41 >= *a4 )
            goto LABEL_90;
        }
        v7 = -1073741675;
      }
      else
      {
LABEL_90:
        if ( v42 + 1 < v42 )
          return -1073741675;
        v7 = 0;
        if ( (unsigned int)(v42 + 2) > v38 + a4[1] )
          return -1073741789;
        *v42 = 4;
        v42[1] = v48;
        ++*a4;
      }
    }
    if ( v7 < 0 )
      return v7;
LABEL_96:
    v54 = v15;
    v55 = v14;
    if ( !&v54 )
      return -1073741811;
    v43 = a4[2];
    if ( !v43 )
    {
      v44 = a4[1];
      if ( v44 + 12 >= v44 )
      {
        a4[1] = v44 + 12;
        ++*a4;
        return 0;
      }
      goto LABEL_83;
    }
    v45 = 0;
    v46 = (_DWORD *)a4[2];
    if ( *a4 )
    {
      while ( *v46 < 0xFFFFFFFC && (_DWORD *)((char *)v46 + *v46 + 4) >= v46 )
      {
        ++v45;
        v46 = (_DWORD *)((char *)v46 + *v46 + 4);
        if ( v45 >= *a4 )
          goto LABEL_104;
      }
    }
    else
    {
LABEL_104:
      if ( v46 + 1 >= v46 )
      {
        v7 = 0;
        if ( (unsigned int)(v46 + 3) <= v43 + a4[1] )
        {
          *v46 = 8;
          v46[1] = v54;
          v46[2] = v55;
          ++*a4;
          return v7;
        }
        return -1073741789;
      }
    }
    return -1073741675;
  }
  return v7;
}
