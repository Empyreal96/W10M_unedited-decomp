// CcGetBcbListHeadLargeOffset 
 
_DWORD *__fastcall CcGetBcbListHeadLargeOffset(_DWORD *a1, int a2, unsigned int a3, int a4, char a5)
{
  int v6; // r6
  unsigned int v7; // r5
  int v8; // r2
  unsigned int v10; // r3
  char v11; // r4
  int v13; // r9
  __int64 v14; // r0
  int v15; // r3
  char v17; // r4
  __int64 v18; // r0
  int v19; // r5
  int v20; // r2
  int v21; // t1
  int v22; // t1
  int v23; // [sp+0h] [bp-68h]
  _DWORD v24[24]; // [sp+8h] [bp-60h]

  v6 = a1[16];
  v7 = a1[7];
  v8 = 0;
  v10 = a1[6];
  v11 = 25;
  v13 = 0;
  do
  {
    v11 += 7;
    ++v8;
    LODWORD(v14) = 1 << v11;
    HIDWORD(v14) = 1 << (v11 - 32);
  }
  while ( __SPAIR64__(v7, v10) > v14 );
  v15 = 1 << (v11 - 32);
  if ( a4 >= v15 && (a4 > v15 || a3 >= 1 << v11) )
    return a1 + 4;
  v17 = v11 - 7;
  do
  {
    v23 = v8 - 1;
    v18 = __SPAIR64__(a4, a3) >> v17;
    v19 = *(_DWORD *)(v6 + 4 * (__SPAIR64__(a4, a3) >> v17));
    if ( v19 )
      goto LABEL_25;
    v20 = v8 - 1;
    while ( a5 )
    {
      if ( (_DWORD)v18 != 127 )
      {
        HIDWORD(v18) = v6 + 4 * v18;
        do
        {
          if ( (_DWORD)v18 == 127 )
            break;
          v21 = *(_DWORD *)(HIDWORD(v18) + 4);
          HIDWORD(v18) += 4;
          LODWORD(v18) = v18 + 1;
        }
        while ( !v21 );
        v19 = *(_DWORD *)(v6 + 4 * v18);
        if ( v19 )
        {
          a3 = 0;
          a4 = 0;
          goto LABEL_25;
        }
      }
LABEL_22:
      if ( !v13 )
        return a1 + 4;
      LODWORD(v18) = v24[--v13];
      ++v20;
      v6 = v24[v13 + 8];
      v23 = v20;
    }
    if ( !(_DWORD)v18 )
      goto LABEL_22;
    HIDWORD(v18) = v6 + 4 * v18;
    do
    {
      if ( !(_DWORD)v18 )
        break;
      v22 = *(_DWORD *)(HIDWORD(v18) - 4);
      HIDWORD(v18) -= 4;
      LODWORD(v18) = v18 - 1;
    }
    while ( !v22 );
    v19 = *(_DWORD *)(v6 + 4 * v18);
    if ( !v19 )
      goto LABEL_22;
    a3 = -1;
    a4 = 0x7FFFFFFF;
LABEL_25:
    v24[v13] = v18;
    v24[v13 + 8] = v6;
    a4 &= (__PAIR64__(1 << (v17 - 32), 1 << v17) - 1) >> 32;
    v8 = v23;
    a3 &= (1 << v17) - 1;
    v17 -= 7;
    ++v13;
    v6 = v19;
  }
  while ( v23 );
  return (_DWORD *)(v19 + 4 * (((__SPAIR64__(a4, a3) >> v17) & 0xFFFFFFFE) + 128));
}
