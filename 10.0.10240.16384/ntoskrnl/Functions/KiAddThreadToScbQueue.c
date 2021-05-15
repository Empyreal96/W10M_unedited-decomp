// KiAddThreadToScbQueue 
 
int __fastcall KiAddThreadToScbQueue(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r7
  __int64 v8; // r0
  _QWORD *v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r3
  int v17; // r4
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int i; // r3

  v4 = a2;
  v5 = *(char *)(a3 + 123);
  if ( !*(_DWORD *)(a2 + 96) )
  {
    do
    {
      v20 = *(_DWORD *)(v4 + 236);
      if ( !v20 )
        break;
      v4 = *(_DWORD *)(v4 + 236);
    }
    while ( !*(_DWORD *)(v20 + 96) );
  }
  HIDWORD(v8) = v4 + 8 * v5 + 100;
  v9 = (_QWORD *)(a3 + 144);
  if ( a4 )
  {
    LODWORD(v8) = *(_DWORD *)HIDWORD(v8);
    *v9 = v8;
    if ( *(_DWORD *)(v8 + 4) != HIDWORD(v8) )
      sub_52BF40();
    *(_DWORD *)(v8 + 4) = v9;
    *(_DWORD *)HIDWORD(v8) = v9;
  }
  else
  {
    LODWORD(v8) = *(_DWORD *)(v4 + 8 * v5 + 104);
    *(_DWORD *)v9 = HIDWORD(v8);
    *(_DWORD *)(a3 + 148) = v8;
    if ( *(_DWORD *)v8 != HIDWORD(v8) )
      __fastfail(3u);
    *(_DWORD *)v8 = v9;
    *(_DWORD *)(v4 + 8 * v5 + 104) = v9;
  }
  v10 = *(_DWORD *)(a3 + 76);
  *(_DWORD *)(a3 + 824) = v4;
  *(_DWORD *)(a3 + 76) = v10 | 0x2000;
  *(_WORD *)(v4 + 94) |= 1 << v5;
  while ( (*(_BYTE *)(v4 + 92) & 2) == 0 )
  {
    if ( (*(_BYTE *)(v4 + 92) & 1) != 0 )
    {
      v12 = v4 + 80;
      HIDWORD(v8) = *(_DWORD *)(v4 + 80);
      if ( HIDWORD(v8) )
      {
        for ( i = *(_DWORD *)(HIDWORD(v8) + 4); i; i = *(_DWORD *)(i + 4) )
          HIDWORD(v8) = i;
      }
      else
      {
        v13 = *(_DWORD *)(v4 + 88);
        while ( 1 )
        {
          HIDWORD(v8) = v13 & 0xFFFFFFFC;
          if ( (v13 & 0xFFFFFFFC) == 0 || *(_DWORD *)(HIDWORD(v8) + 4) == v12 )
            break;
          v13 = *(_DWORD *)(HIDWORD(v8) + 8);
          v12 = HIDWORD(v8);
        }
      }
      if ( !HIDWORD(v8) )
        goto LABEL_11;
      v14 = *(_DWORD *)(v4 + 96);
      v15 = v14 - *(_DWORD *)(HIDWORD(v8) + 16);
      if ( v15 )
        goto LABEL_22;
      if ( *(_WORD *)(v4 + 94) )
      {
        LODWORD(v8) = 31 - __clz(*(unsigned __int16 *)(v4 + 94));
        v16 = 0;
        if ( *(_WORD *)(HIDWORD(v8) + 14) )
          v16 = 31 - __clz(*(unsigned __int16 *)(HIDWORD(v8) + 14));
        v15 = v16 - v8;
        goto LABEL_22;
      }
      if ( v14 )
      {
        v15 = 1;
LABEL_22:
        if ( v15 >= 0 )
          goto LABEL_11;
      }
      else
      {
        LODWORD(v8) = *(_DWORD *)v4;
        if ( *(_QWORD *)v4 > *(_QWORD *)(HIDWORD(v8) - 80) )
          goto LABEL_11;
      }
      v17 = v4;
      do
      {
        v18 = *(_DWORD *)(v17 + 236);
        if ( v18 )
          v19 = v18 + 228;
        else
          v19 = a1 + 1976;
        *(_BYTE *)(v17 + 92) &= 0xFEu;
        RtlRbRemoveNode(v19, v17 + 80);
        v17 = *(_DWORD *)(v17 + 236);
      }
      while ( v17 && (*(_BYTE *)(v17 + 92) & 1) != 0 && !*(_DWORD *)(v17 + 228) && !*(_WORD *)(v17 + 94) );
      v11 = 0;
      goto LABEL_10;
    }
    v11 = 1;
LABEL_10:
    LODWORD(v8) = KiInsertSchedulingGroupQueue(a1, v4, v11);
LABEL_11:
    v4 = *(_DWORD *)(v4 + 236);
    if ( !v4 )
      return v8;
  }
  return v8;
}
