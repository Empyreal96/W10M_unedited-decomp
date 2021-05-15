// RtlpSparseBitmapCtxFindRunsFromRange 
 
int __fastcall RtlpSparseBitmapCtxFindRunsFromRange(_DWORD *a1, int a2, unsigned int a3, int a4, int a5, int a6, unsigned int a7, int a8, unsigned int a9)
{
  int v11; // r6
  __int64 v12; // kr00_8
  unsigned int v13; // r7
  unsigned int v14; // r1
  unsigned int v15; // r4
  _DWORD *v16; // r0
  int i; // r3
  unsigned int v18; // r1
  __int64 v19; // kr08_8
  unsigned int v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r3
  int *v23; // r5
  int j; // r3
  unsigned int v25; // r1
  unsigned int v26; // r3
  unsigned int v27; // r2
  int v28; // r3
  unsigned int v29; // r7
  int v30; // r4
  int v31; // r2
  int v35; // [sp+8h] [bp-28h]
  int v36; // [sp+Ch] [bp-24h]

  v35 = a1[8] * a6;
  v36 = a5 + 16 * a4;
  v11 = a5;
  do
  {
    v12 = *(_QWORD *)(a8 + 4);
    if ( a7 < (unsigned int)v12 )
      v13 = a7;
    else
      v13 = 0;
    v14 = v12 - 1;
    while ( 1 )
    {
      if ( v14 - v13 == -1 )
        goto LABEL_7;
      v16 = (_DWORD *)(HIDWORD(v12) + 4 * (v13 >> 5));
      for ( i = ~*v16 | ((1 << (v13 & 0x1F)) - 1); i == -1; i = ~*v16 )
      {
        if ( (unsigned int)++v16 > HIDWORD(v12) + 4 * (v14 >> 5) )
          goto LABEL_7;
      }
      v15 = __clz(__rbit(~i)) + 32 * (((int)v16 - HIDWORD(v12)) >> 2);
      if ( v15 > v14 )
      {
LABEL_7:
        v15 = -1;
      }
      else if ( v15 != -1 )
      {
        break;
      }
      if ( !v13 )
        break;
      v18 = a7 + 1;
      if ( a7 + 1 > (unsigned int)v12 )
        v18 = *(_DWORD *)(a8 + 4);
      v14 = v18 - 1;
      v13 = 0;
    }
    if ( v15 < a7 || v15 == -1 )
      break;
    *(_QWORD *)v11 = (unsigned int)v35 + (unsigned __int64)v15;
    if ( a9 )
    {
      v27 = a1[11];
      v28 = v27 ? a1[10] + a8 : 0;
      v29 = v28 + v27 * v15;
      memmove(a9, v29, v27);
      a7 = v15 + 1;
      for ( *(_DWORD *)(v11 + 8) = 1; a7 != a1[8]; *(_DWORD *)(v11 + 8) = v30 + 1 )
      {
        v30 = *(_DWORD *)(v11 + 8);
        if ( v30 == a3 )
          break;
        if ( ((*(int *)(*(_DWORD *)(a8 + 8) + 4 * (a7 >> 5)) >> (a7 & 0x1F)) & 1) == 0 )
          break;
        v31 = a1[11];
        v29 += v31;
        if ( memcmp(a9, v29, v31) )
          break;
        ++a7;
      }
      a9 += a1[11];
    }
    else
    {
      v19 = *(_QWORD *)(a8 + 4);
      v20 = v15 < (unsigned int)v19 ? v15 : 0;
      v21 = v19 - 1;
      while ( 1 )
      {
        if ( v21 - v20 == -1 )
          goto LABEL_26;
        v23 = (int *)(HIDWORD(v19) + 4 * (v20 >> 5));
        for ( j = *v23 | ((1 << (v20 & 0x1F)) - 1); j == -1; j = *v23 )
        {
          if ( (unsigned int)++v23 > HIDWORD(v19) + 4 * (v21 >> 5) )
            goto LABEL_26;
        }
        v22 = __clz(__rbit(~j)) + 32 * (((int)v23 - HIDWORD(v19)) >> 2);
        if ( v22 > v21 )
        {
LABEL_26:
          v22 = -1;
        }
        else if ( v22 != -1 )
        {
          break;
        }
        if ( !v20 )
          break;
        v25 = v15 + 1;
        if ( v15 + 1 > (unsigned int)v19 )
          v25 = *(_DWORD *)(a8 + 4);
        v21 = v25 - 1;
        v20 = 0;
      }
      if ( v22 < v15 || v22 == -1 )
        v22 = a1[8];
      v26 = v22 - v15;
      *(_DWORD *)(v11 + 8) = v26;
      if ( v26 >= a3 )
        v26 = a3;
      *(_DWORD *)(v11 + 8) = v26;
      a7 = v26 + v15;
    }
    v11 += 16;
    if ( a7 == a1[8] )
      break;
  }
  while ( v11 != v36 );
  return (v11 - a5) >> 4;
}
