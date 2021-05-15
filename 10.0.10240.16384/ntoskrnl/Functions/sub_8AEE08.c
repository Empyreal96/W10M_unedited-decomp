// sub_8AEE08 
 
int __fastcall sub_8AEE08(unsigned int *a1, int a2, int a3, unsigned int *a4)
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
  unsigned int v17; // r5
  int *v18; // r3
  unsigned int j; // r1
  unsigned int v20; // r0
  int v21; // r6
  _DWORD *v22; // r6
  int v23; // r7
  unsigned int k; // r3
  unsigned int v25; // r1
  int v26; // r0
  int *v27; // r3
  int v28; // r1
  int v29; // r2
  int v30; // r7
  unsigned int v31; // r5
  unsigned int v32; // r1
  unsigned int v33; // r3
  unsigned int v34; // r2
  unsigned int v35; // r3
  int v36; // r0
  unsigned int v37; // r2
  unsigned int v38; // r3
  unsigned int v39; // r0
  _DWORD *v40; // r1
  unsigned int v41; // r2
  unsigned int v42; // r3
  unsigned int v43; // r0
  _DWORD *v44; // r1
  int v45; // [sp+0h] [bp-40h] BYREF
  int v46; // [sp+4h] [bp-3Ch]
  int v47[4]; // [sp+8h] [bp-38h] BYREF
  int v48; // [sp+18h] [bp-28h] BYREF
  int v49; // [sp+1Ch] [bp-24h]

  if ( !a2 || !a4 )
    return -1073741811;
  v8 = (int *)a1[2];
  if ( !v8 || *a1 <= 3 )
  {
    result = -1073741811;
LABEL_18:
    v16 = v47[2];
    v15 = v47[3];
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
  if ( !v8 )
    return -1073741811;
  v17 = *a1;
  if ( *a1 <= 4 )
    return -1073741811;
  v18 = (int *)a1[2];
  for ( j = 0; j < 4; ++j )
  {
    v20 = (unsigned int)(v18 + 1);
    v21 = *v18;
    if ( v18 + 1 < v18 )
      return -1073741675;
    v18 = (int *)(v21 + v20);
    if ( v21 + v20 < v20 )
      return -1073741675;
  }
  v22 = v18 + 1;
  v23 = *v18;
  if ( v18 + 1 < v18 )
    return -1073741675;
  if ( !v23 )
    v22 = 0;
  if ( v17 > 5 )
  {
    for ( k = 0; k < 5; ++k )
    {
      v25 = (unsigned int)(v8 + 1);
      v26 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_40;
      v8 = (int *)(v26 + v25);
      if ( v26 + v25 < v25 )
        goto LABEL_40;
    }
    v27 = v8 + 1;
    v28 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_40:
      result = -1073741675;
      goto LABEL_41;
    }
    result = 0;
    if ( !v28 )
      v27 = 0;
    if ( v28 == 4 )
    {
      v29 = *v27;
      goto LABEL_42;
    }
    return -1073741789;
  }
  result = -1073741811;
LABEL_41:
  v29 = v45;
LABEL_42:
  if ( result < 0 )
    return result;
  if ( off_9204AC )
    v30 = off_9204AC(v22, v23, v29);
  else
    v30 = -1073700223;
  result = RtlUIntAdd(4u, 4, v47);
  if ( result < 0 )
    v31 = v47[1];
  else
    v31 = v47[0];
  if ( result < 0 || (result = RtlUIntAdd(4u, 8, v47), result < 0) )
  {
    v32 = v47[0];
  }
  else
  {
    v32 = v31 + v47[0];
    if ( v31 + v47[0] < v31 )
      return -1073741675;
    result = 0;
  }
  if ( result < 0 )
    return result;
  if ( v32 >= 0xFFFFFFF8 )
    return -1073741675;
  v33 = (v32 + 15) & 0xFFFFFFF8;
  if ( v33 >= v32 + 8 )
  {
    v34 = v33 + 8;
    if ( v33 + 8 < v33 )
      goto LABEL_67;
    result = 0;
  }
  else
  {
    result = -1073741675;
    v34 = v47[0];
  }
  if ( result < 0 )
    return result;
  v35 = v34 + 4;
  v36 = *(_DWORD *)(a2 + 8);
  if ( v34 < 0xFFFFFFFC )
  {
    v37 = v34 + 8;
    if ( v35 + 4 >= v35 )
    {
      v38 = v37 + v36;
      if ( v37 + v36 >= v37 && v38 + 4 >= v38 && v38 + 4 + *(_DWORD *)(a2 + 16) >= v38 + 4 )
      {
        result = 0;
        goto LABEL_68;
      }
    }
  }
LABEL_67:
  result = -1073741675;
LABEL_68:
  if ( result < 0 )
    return result;
  a4[1] = v32;
  if ( !v32 )
    return -1073741762;
  v39 = ExAllocatePoolWithTag(1, v32, 542329939);
  v40 = (_DWORD *)v39;
  if ( !v39 )
    return -1073741801;
  a4[2] = v39;
  *a4 = 0;
  v46 = v30 | 0x10000000;
  if ( &v45 == (int *)-4 )
  {
    result = -1073741811;
  }
  else
  {
    if ( v39 + 4 < v39 )
      return -1073741675;
    result = 0;
    if ( v40 + 2 > (_DWORD *)((char *)v40 + a4[1]) )
      return -1073741789;
    *v40 = 4;
    v40[1] = v46;
    ++*a4;
  }
  if ( result < 0 )
    return result;
  v48 = v16;
  v49 = v15;
  if ( !&v48 )
    return -1073741811;
  v41 = a4[2];
  if ( !v41 )
  {
    v42 = a4[1];
    if ( v42 + 12 >= v42 )
    {
      a4[1] = v42 + 12;
      ++*a4;
      return 0;
    }
    a4[1] = -1;
    return -1073741675;
  }
  v43 = 0;
  v44 = (_DWORD *)a4[2];
  if ( *a4 )
  {
    while ( *v44 < 0xFFFFFFFC && (_DWORD *)((char *)v44 + *v44 + 4) >= v44 )
    {
      ++v43;
      v44 = (_DWORD *)((char *)v44 + *v44 + 4);
      if ( v43 >= *a4 )
        goto LABEL_90;
    }
    return -1073741675;
  }
LABEL_90:
  if ( v44 + 1 < v44 )
    return -1073741675;
  result = 0;
  if ( (unsigned int)(v44 + 3) > v41 + a4[1] )
    return -1073741789;
  *v44 = 8;
  v44[1] = v48;
  v44[2] = v49;
  ++*a4;
  return result;
}
