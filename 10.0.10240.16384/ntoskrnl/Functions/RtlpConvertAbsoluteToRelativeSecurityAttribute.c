// RtlpConvertAbsoluteToRelativeSecurityAttribute 
 
int __fastcall RtlpConvertAbsoluteToRelativeSecurityAttribute(int a1, int a2, int a3)
{
  int *v3; // r10
  unsigned int v5; // r3
  unsigned int v7; // r7
  int v8; // r5
  unsigned int v9; // r8
  unsigned int v10; // r2
  unsigned int v11; // r4
  int v12; // r3
  unsigned int v13; // r1
  int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r8
  int *v17; // r10
  int v18; // t1
  unsigned int v19; // r2
  unsigned int v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r3
  unsigned int v24; // r7
  int v25; // r4
  int v26; // r3
  unsigned int v27; // r7
  _DWORD *v28; // r10
  unsigned int v29; // r4
  int v30; // r8
  unsigned int v31; // r7
  int *v32; // r3
  unsigned int v33; // r2
  int v34; // r3
  unsigned int i; // r8
  unsigned int v36; // r4
  unsigned int v37; // r1
  int v38; // r0
  _DWORD *v39; // r2
  unsigned int v41; // [sp+0h] [bp-30h] BYREF
  unsigned int v42; // [sp+4h] [bp-2Ch] BYREF
  int *v43; // [sp+8h] [bp-28h]
  unsigned int v44; // [sp+Ch] [bp-24h]

  v3 = (int *)a3;
  v43 = (int *)a3;
  v5 = 0;
  v41 = 0;
  v42 = 0;
  if ( !a1 || !a3 )
    return -1073741811;
  v7 = *(_DWORD *)(a1 + 12);
  if ( v7 )
  {
    v8 = RtlULongLongToULong(4 * (v7 - 1), (unsigned __int64)(v7 - 1) >> 30, &v42);
    if ( v8 < 0 )
      return v8;
    v5 = v42;
  }
  v9 = v5 + 20;
  if ( v5 >= 0xFFFFFFEC )
    return -1073741675;
  v8 = RtlStringCbLengthW(*(_DWORD *)a1, 0xFFFFu, &v41);
  if ( v8 < 0 )
    return v8;
  v10 = v41 + 2;
  v44 = v41 + 2;
  if ( v41 + 2 < v41 )
    return -1073741675;
  v11 = v10 + v9;
  if ( v10 + v9 < v9 )
    return -1073741675;
  v12 = *(unsigned __int16 *)(a1 + 4);
  if ( !*(_WORD *)(a1 + 4) )
    goto LABEL_29;
  if ( *(unsigned __int16 *)(a1 + 4) <= 2u )
  {
LABEL_32:
    v8 = RtlULongLongToULong(8 * v7, (unsigned __int64)v7 >> 29, &v42);
    if ( v8 < 0 )
      return v8;
    if ( v42 + v11 >= v11 )
    {
      v11 += v42;
      goto LABEL_29;
    }
    return -1073741675;
  }
  if ( v12 != 3 )
  {
    if ( v12 == 5 )
    {
LABEL_16:
      v13 = 0;
      if ( v7 )
      {
        v14 = *(_DWORD *)(a1 + 16);
        while ( 1 )
        {
          v15 = *(_DWORD *)(v14 + 4) + v11;
          if ( v15 < v11 )
            return -1073741675;
          v11 = v15 + 4;
          if ( v15 + 4 < v15 )
            return -1073741675;
          ++v13;
          v14 += 8;
          if ( v13 >= v7 )
            goto LABEL_29;
        }
      }
      goto LABEL_29;
    }
    if ( v12 != 6 )
    {
      if ( v12 != 16 )
        goto LABEL_29;
      goto LABEL_16;
    }
    goto LABEL_32;
  }
  v16 = 0;
  if ( v7 )
  {
    v17 = *(int **)(a1 + 16);
    while ( 1 )
    {
      v18 = *v17++;
      v8 = RtlStringCbLengthW(v18, 0xFFFFu, &v41);
      if ( v8 < 0 )
        return v8;
      v19 = v41 + 2;
      if ( v41 + 2 < v41 || v19 + v11 < v11 )
        return -1073741675;
      ++v16;
      v11 += v19;
      if ( v16 >= v7 )
      {
        v3 = v43;
        break;
      }
    }
  }
LABEL_29:
  v20 = v11 + 3;
  if ( v11 + 3 < v11 )
    return -1073741675;
  v21 = v20 & 0xFFFFFFFC;
  v8 = 0;
  if ( *v3 < (v20 & 0xFFFFFFFC) )
  {
    v8 = -1073741789;
    *v3 = v21;
    return v8;
  }
  if ( !a2 )
    return -1073741811;
  *v3 = v21;
  memset((_BYTE *)a2, 0, v21);
  *(_WORD *)(a2 + 4) = *(_WORD *)(a1 + 4);
  *(_WORD *)(a2 + 6) = *(_WORD *)(a1 + 6);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 12);
  v22 = *(_DWORD *)(a1 + 12);
  v23 = v22 ? v22 - 1 : 0;
  v24 = v44;
  v25 = 4 * (v23 + 5);
  *(_DWORD *)a2 = v25;
  memmove(v25 + a2, *(_DWORD *)a1, v24);
  v26 = *(unsigned __int16 *)(a1 + 4);
  v27 = v24 + v25;
  v28 = (_DWORD *)(v27 + a2);
  if ( !*(_WORD *)(a1 + 4) )
    return -1073741811;
  if ( *(unsigned __int16 *)(a1 + 4) <= 2u )
    goto LABEL_55;
  if ( v26 != 3 )
  {
    if ( v26 == 5 )
      goto LABEL_45;
    if ( v26 != 6 )
    {
      if ( v26 == 16 )
      {
LABEL_45:
        v29 = 0;
        if ( *(_DWORD *)(a1 + 12) )
        {
          v30 = a2;
          do
          {
            *(_DWORD *)(v30 + 16) = v27;
            v31 = v27 + 4;
            *v28 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 8 * v29 + 4);
            v32 = (int *)(*(_DWORD *)(a1 + 16) + 8 * v29);
            v33 = v32[1];
            if ( v33 )
              memmove(v31 + a2, *v32, v33);
            v30 += 4;
            v34 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 8 * v29++ + 4);
            v27 = v31 + v34;
            v28 = (_DWORD *)(v27 + a2);
          }
          while ( v29 < *(_DWORD *)(a1 + 12) );
        }
        return v8;
      }
      return -1073741811;
    }
LABEL_55:
    v37 = 0;
    if ( *(_DWORD *)(a1 + 12) )
    {
      v38 = a2;
      do
      {
        *(_DWORD *)(v38 + 16) = v27;
        v27 += 8;
        v38 += 4;
        v39 = (_DWORD *)(*(_DWORD *)(a1 + 16) + 8 * v37++);
        *v28 = *v39;
        v28[1] = v39[1];
        v28 = (_DWORD *)(v27 + a2);
      }
      while ( v37 < *(_DWORD *)(a1 + 12) );
    }
    return v8;
  }
  for ( i = 0; i < *(_DWORD *)(a1 + 12); v28 = (_DWORD *)(v27 + a2) )
  {
    *(_DWORD *)(a2 + 4 * i + 16) = v27;
    v44 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 4 * i);
    v8 = RtlStringCbLengthW(v44, 0xFFFFu, &v41);
    if ( v8 < 0 )
      break;
    v36 = v41 + 2;
    memmove((int)v28, v44, v41 + 2);
    v27 += v36;
    ++i;
  }
  return v8;
}
