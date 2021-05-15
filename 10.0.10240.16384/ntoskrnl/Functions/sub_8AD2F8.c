// sub_8AD2F8 
 
int __fastcall sub_8AD2F8(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int *v4; // r2
  int v6; // r4
  unsigned int i; // r3
  unsigned int v8; // r1
  int v9; // r0
  int *v10; // r3
  int v11; // r1
  int v12; // r9
  int v13; // r10
  int v14; // r8
  int v15; // r0
  unsigned int v16; // r6
  unsigned int v17; // r1
  unsigned int v18; // r3
  unsigned int v19; // r2
  int v20; // r0
  unsigned int v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r3
  int v24; // r0
  unsigned int v25; // r2
  unsigned int v26; // r3
  unsigned int v28; // r0
  _DWORD *v29; // r1
  unsigned int v30; // r2
  unsigned int v31; // r3
  unsigned int v32; // r0
  _DWORD *v33; // r1
  int v34; // [sp+0h] [bp-40h] BYREF
  unsigned int v35; // [sp+4h] [bp-3Ch] BYREF
  int v36; // [sp+8h] [bp-38h]
  unsigned int v37; // [sp+Ch] [bp-34h]
  int v38; // [sp+10h] [bp-30h]
  int v39; // [sp+14h] [bp-2Ch]
  int v40; // [sp+18h] [bp-28h] BYREF
  int v41; // [sp+1Ch] [bp-24h]

  v4 = (int *)a1[2];
  v36 = a2;
  if ( v4 && *a1 > 3u )
  {
    for ( i = 0; i < 3; ++i )
    {
      v8 = (unsigned int)(v4 + 1);
      v9 = *v4;
      if ( v4 + 1 < v4 )
        goto LABEL_14;
      v4 = (int *)(v9 + v8);
      if ( v9 + v8 < v8 )
        goto LABEL_14;
    }
    v10 = v4 + 1;
    v11 = *v4;
    if ( v4 + 1 < v4 )
    {
LABEL_14:
      v6 = -1073741675;
      goto LABEL_15;
    }
    v6 = 0;
    if ( !v11 )
      v10 = 0;
    if ( v11 == 8 )
    {
      v12 = v10[1];
      v13 = *v10;
      goto LABEL_16;
    }
    return -1073741789;
  }
  v6 = -1073741811;
LABEL_15:
  v13 = v38;
  v12 = v39;
LABEL_16:
  if ( v6 < 0 )
    return v6;
  v14 = off_920468 ? off_920468() : -1073741637;
  v6 = v14;
  if ( v14 < 0 )
    return v6;
  v15 = RtlUIntAdd(4u, 4, &v35);
  v6 = v15;
  if ( v15 < 0 )
    v16 = v37;
  else
    v16 = v35;
  if ( v15 < 0 || (v6 = RtlUIntAdd(4u, 8, &v35), v6 < 0) )
  {
    v17 = v36;
  }
  else
  {
    v17 = v16 + v35;
    if ( v16 + v35 < v16 )
      return -1073741675;
    v6 = 0;
  }
  if ( v6 < 0 )
    return v6;
  if ( v17 >= 0xFFFFFFF8 )
    return -1073741675;
  v18 = (v17 + 15) & 0xFFFFFFF8;
  if ( v18 >= v17 + 8 )
  {
    v19 = v18 + 8;
    if ( v18 + 8 < v18 )
      goto LABEL_42;
    v6 = 0;
  }
  else
  {
    v6 = -1073741675;
    v19 = v36;
  }
  if ( v6 < 0 )
    return v6;
  v20 = *(_DWORD *)(v36 + 8);
  v21 = v19 + 4;
  if ( v19 < 0xFFFFFFFC )
  {
    v22 = v19 + 8;
    if ( v21 + 4 >= v21 )
    {
      v23 = v22 + v20;
      if ( v22 + v20 >= v22 && v23 + 4 >= v23 && v23 + 4 + *(_DWORD *)(v36 + 16) >= v23 + 4 )
      {
        v6 = 0;
        goto LABEL_43;
      }
    }
  }
LABEL_42:
  v6 = -1073741675;
LABEL_43:
  if ( v6 < 0 )
    return v6;
  if ( !a4 )
    return -1073741811;
  v6 = 0;
  a4[1] = v17;
  if ( v17 )
  {
    v24 = ExAllocatePoolWithTag(1, v17, 542329939);
    if ( v24 )
    {
      a4[2] = v24;
      *a4 = 0;
    }
    else
    {
      v6 = -1073741801;
    }
  }
  else
  {
    v6 = -1073741762;
  }
  if ( v6 >= 0 )
  {
    v34 = v14 | 0x10000000;
    if ( &v34 )
    {
      v25 = a4[2];
      if ( !v25 )
      {
        v26 = a4[1];
        if ( v26 + 8 < v26 )
        {
LABEL_56:
          a4[1] = -1;
          return -1073741675;
        }
        a4[1] = v26 + 8;
        ++*a4;
        goto LABEL_69;
      }
      v28 = 0;
      v29 = (_DWORD *)a4[2];
      if ( *a4 )
      {
        while ( *v29 < 0xFFFFFFFC )
        {
          if ( (_DWORD *)((char *)v29 + *v29 + 4) < v29 )
            return -1073741675;
          ++v28;
          v29 = (_DWORD *)((char *)v29 + *v29 + 4);
          if ( v28 >= *a4 )
            goto LABEL_63;
        }
        v6 = -1073741675;
      }
      else
      {
LABEL_63:
        if ( v29 + 1 < v29 )
          return -1073741675;
        v6 = 0;
        if ( (unsigned int)(v29 + 2) > v25 + a4[1] )
          return -1073741789;
        *v29 = 4;
        v29[1] = v34;
        ++*a4;
      }
    }
    else
    {
      v6 = -1073741811;
    }
    if ( v6 < 0 )
      return v6;
LABEL_69:
    v40 = v13;
    v41 = v12;
    if ( !&v40 )
      return -1073741811;
    v30 = a4[2];
    if ( !v30 )
    {
      v31 = a4[1];
      if ( v31 + 12 >= v31 )
      {
        a4[1] = v31 + 12;
        ++*a4;
        return 0;
      }
      goto LABEL_56;
    }
    v32 = 0;
    v33 = (_DWORD *)a4[2];
    if ( *a4 )
    {
      while ( *v33 < 0xFFFFFFFC && (_DWORD *)((char *)v33 + *v33 + 4) >= v33 )
      {
        ++v32;
        v33 = (_DWORD *)((char *)v33 + *v33 + 4);
        if ( v32 >= *a4 )
          goto LABEL_77;
      }
    }
    else
    {
LABEL_77:
      if ( v33 + 1 >= v33 )
      {
        v6 = 0;
        if ( (unsigned int)(v33 + 3) <= v30 + a4[1] )
        {
          *v33 = 8;
          v33[1] = v40;
          v33[2] = v41;
          ++*a4;
          return v6;
        }
        return -1073741789;
      }
    }
    return -1073741675;
  }
  return v6;
}
