// sub_8AFF30 
 
int __fastcall sub_8AFF30(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int result; // r0
  int *v8; // r2
  int *v9; // r3
  unsigned int i; // r1
  unsigned int v11; // r0
  int v12; // r5
  int *v13; // r1
  int v14; // r5
  int v15; // r8
  int v16; // r9
  unsigned int j; // r3
  unsigned int v18; // r1
  int v19; // r0
  int v20; // r7
  unsigned int v21; // r5
  unsigned int v22; // r1
  unsigned int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r3
  int v26; // r0
  unsigned int v27; // r2
  unsigned int v28; // r3
  unsigned int v29; // r0
  _DWORD *v30; // r1
  unsigned int v31; // r2
  unsigned int v32; // r3
  unsigned int v33; // r0
  _DWORD *v34; // r1
  int v35; // [sp+0h] [bp-40h] BYREF
  int v36[5]; // [sp+4h] [bp-3Ch] BYREF
  int v37; // [sp+18h] [bp-28h] BYREF
  int v38; // [sp+1Ch] [bp-24h]

  if ( !a2 || !a4 )
    return -1073741811;
  v8 = (int *)a1[2];
  if ( !v8 || *a1 <= 3u )
  {
    result = -1073741811;
LABEL_18:
    v16 = v36[3];
    v15 = v36[4];
    goto LABEL_19;
  }
  v9 = (int *)a1[2];
  for ( i = 0; i < 3; ++i )
  {
    v11 = (unsigned int)(v9 + 1);
    v12 = *v9;
    if ( v9 + 1 < v9 )
      goto LABEL_17;
    v9 = (int *)(v12 + v11);
    if ( v12 + v11 < v11 )
      goto LABEL_17;
  }
  v13 = v9 + 1;
  v14 = *v9;
  if ( v9 + 1 < v9 )
  {
LABEL_17:
    result = -1073741675;
    goto LABEL_18;
  }
  result = 0;
  if ( !v14 )
    v13 = 0;
  if ( v14 != 8 )
    return -1073741789;
  v15 = v13[1];
  v16 = *v13;
LABEL_19:
  if ( result < 0 )
    return result;
  if ( !v8 || *a1 <= 4u )
    return -1073741811;
  for ( j = 0; j < 4; ++j )
  {
    v18 = (unsigned int)(v8 + 1);
    v19 = *v8;
    if ( v8 + 1 < v8 )
      return -1073741675;
    v8 = (int *)(v19 + v18);
    if ( v19 + v18 < v18 )
      return -1073741675;
  }
  if ( v8 + 1 < v8 )
    return -1073741675;
  if ( off_920464 )
    v20 = off_920464();
  else
    v20 = -1073741637;
  result = RtlUIntAdd(4u, 4, v36);
  if ( result < 0 )
    v21 = v36[1];
  else
    v21 = v36[0];
  if ( result < 0 || (result = RtlUIntAdd(4u, 8, v36), result < 0) )
  {
    v22 = v36[0];
  }
  else
  {
    v22 = v21 + v36[0];
    if ( v21 + v36[0] < v21 )
      return -1073741675;
    result = 0;
  }
  if ( result < 0 )
    return result;
  if ( v22 >= 0xFFFFFFF8 )
    return -1073741675;
  v23 = (v22 + 15) & 0xFFFFFFF8;
  if ( v23 >= v22 + 8 )
  {
    v24 = v23 + 8;
    if ( v23 + 8 < v23 )
      goto LABEL_51;
    result = 0;
  }
  else
  {
    result = -1073741675;
    v24 = v36[0];
  }
  if ( result < 0 )
    return result;
  v25 = v24 + 4;
  v26 = *(_DWORD *)(a2 + 8);
  if ( v24 < 0xFFFFFFFC )
  {
    v27 = v24 + 8;
    if ( v25 + 4 >= v25 )
    {
      v28 = v27 + v26;
      if ( v27 + v26 >= v27 && v28 + 4 >= v28 && v28 + 4 + *(_DWORD *)(a2 + 16) >= v28 + 4 )
      {
        result = 0;
        goto LABEL_52;
      }
    }
  }
LABEL_51:
  result = -1073741675;
LABEL_52:
  if ( result < 0 )
    return result;
  a4[1] = v22;
  if ( !v22 )
    return -1073741762;
  v29 = ExAllocatePoolWithTag(1, v22, 542329939);
  v30 = (_DWORD *)v29;
  if ( !v29 )
    return -1073741801;
  a4[2] = v29;
  *a4 = 0;
  v35 = v20 | 0x10000000;
  if ( &v35 )
  {
    if ( v29 + 4 < v29 )
      return -1073741675;
    result = 0;
    if ( v30 + 2 > (_DWORD *)((char *)v30 + a4[1]) )
      return -1073741789;
    *v30 = 4;
    v30[1] = v35;
    ++*a4;
  }
  else
  {
    result = -1073741811;
  }
  if ( result < 0 )
    return result;
  v37 = v16;
  v38 = v15;
  if ( !&v37 )
    return -1073741811;
  v31 = a4[2];
  if ( !v31 )
  {
    v32 = a4[1];
    if ( v32 + 12 >= v32 )
    {
      a4[1] = v32 + 12;
      ++*a4;
      return 0;
    }
    a4[1] = -1;
    return -1073741675;
  }
  v33 = 0;
  v34 = (_DWORD *)a4[2];
  if ( *a4 )
  {
    while ( *v34 < 0xFFFFFFFC && (_DWORD *)((char *)v34 + *v34 + 4) >= v34 )
    {
      ++v33;
      v34 = (_DWORD *)((char *)v34 + *v34 + 4);
      if ( v33 >= *a4 )
        goto LABEL_74;
    }
    return -1073741675;
  }
LABEL_74:
  if ( v34 + 1 < v34 )
    return -1073741675;
  result = 0;
  if ( (unsigned int)(v34 + 3) > v31 + a4[1] )
    return -1073741789;
  *v34 = 8;
  v34[1] = v37;
  v34[2] = v38;
  ++*a4;
  return result;
}
