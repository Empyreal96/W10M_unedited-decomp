// LZNT1FindMatchStandard 
 
unsigned int __fastcall LZNT1FindMatchStandard(unsigned __int8 *a1, unsigned int *a2)
{
  unsigned int v2; // r9
  unsigned int v4; // r8
  unsigned int *v5; // r10
  unsigned int v6; // r1
  int v7; // r0
  unsigned int v8; // r7
  unsigned int v9; // r2
  unsigned int *v10; // lr
  __int64 v11; // kr00_8
  unsigned __int8 *v12; // r1
  int v13; // r2
  int v14; // t1
  unsigned int result; // r0
  unsigned __int8 *v16; // r1
  int v17; // r2
  int v18; // t1
  unsigned int v19; // [sp+0h] [bp-30h]
  unsigned int v20; // [sp+4h] [bp-2Ch]
  unsigned int v22; // [sp+Ch] [bp-24h]

  v2 = a2[2];
  v19 = *a2;
  v4 = *a1;
  v5 = a2;
  v20 = a2[1];
  v6 = a1[1];
  v7 = a1[2];
  v8 = 0;
  v22 = v6;
  v9 = v19;
  v10 = &v5[2 * ((unsigned __int16)(-24993 * (v7 ^ (16 * (v6 ^ (16 * v4))))) >> 4)];
  v11 = *((_QWORD *)v10 + 2);
  if ( (unsigned int)v11 >= v19
    && (unsigned int)v11 < (unsigned int)a1
    && *(unsigned __int8 *)v11 == v4
    && *(unsigned __int8 *)(v11 + 1) == v6
    && *(unsigned __int8 *)(v11 + 2) == v7 )
  {
    v8 = 3;
    if ( v2 > 3 )
    {
      v12 = a1 + 3;
      do
      {
        if ( (unsigned int)v12 >= v20 )
          break;
        v13 = v12[(_DWORD)v11 - (_DWORD)a1];
        v14 = *v12++;
        if ( v14 != v13 )
          break;
        ++v8;
      }
      while ( v8 < v2 );
      v5 = a2;
      v6 = v22;
      v9 = v19;
    }
  }
  if ( HIDWORD(v11) < v9
    || HIDWORD(v11) >= (unsigned int)a1
    || __PAIR64__(*(unsigned __int8 *)(HIDWORD(v11) + 1), (unsigned __int8)*(_BYTE *)HIDWORD(v11)) != __PAIR64__(v6, v4)
    || *(unsigned __int8 *)(HIDWORD(v11) + 2) != v7 )
  {
    goto LABEL_24;
  }
  result = 3;
  if ( v2 > 3 )
  {
    v16 = a1 + 3;
    do
    {
      if ( (unsigned int)v16 >= v20 )
        break;
      v17 = v16[HIDWORD(v11) - (_DWORD)a1];
      v18 = *v16++;
      if ( v18 != v17 )
        break;
      ++result;
    }
    while ( result < v2 );
    v5 = a2;
  }
  if ( v8 < result )
  {
    v10[4] = (unsigned int)a1;
    v10[5] = v11;
    v5[3] = HIDWORD(v11);
  }
  else
  {
LABEL_24:
    v10[4] = (unsigned int)a1;
    v10[5] = v11;
    v5[3] = v11;
    result = v8;
  }
  return result;
}
