// KiRemoveThreadFromScbQueue 
 
unsigned int __fastcall KiRemoveThreadFromScbQueue(unsigned int result, int a2, _DWORD *a3, char a4)
{
  int v4; // r6
  _DWORD *v6; // r1
  unsigned int v8; // r9
  int v9; // r4
  char v10; // r3
  int v11; // r3
  unsigned int v12; // r7
  __int64 v13; // r0
  __int64 v14; // kr00_8
  int v15; // r3
  int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v19; // r3
  int v20; // r3
  unsigned int v21; // r3
  _DWORD *i; // r3

  v4 = a3[36];
  v6 = (_DWORD *)a3[37];
  v8 = result;
  if ( *(_DWORD **)(v4 + 4) != a3 + 36 || (_DWORD *)*v6 != a3 + 36 )
    __fastfail(3u);
  *v6 = v4;
  *(_DWORD *)(v4 + 4) = v6;
  if ( v6 != (_DWORD *)v4 )
    goto LABEL_11;
  v9 = (unsigned __int16)(*(_WORD *)(a2 + 94) ^ (1 << a4));
  v10 = *(_BYTE *)(a2 + 92);
  *(_WORD *)(a2 + 94) = v9;
  if ( (v10 & 2) != 0 || (v10 & 1) == 0 )
    goto LABEL_11;
  if ( !v9 && !*(_DWORD *)(a2 + 228) )
  {
    do
    {
      v11 = *(_DWORD *)(a2 + 236);
      if ( v11 )
        v12 = v11 + 228;
      else
        v12 = v8 + 1976;
      v13 = KeQueryInterruptTime(result);
      v15 = *(_DWORD *)(a2 + 56);
      v14 = v13 - *(_QWORD *)(a2 + 64);
      v16 = *(_DWORD *)(a2 + 60);
      *(_DWORD *)(a2 + 56) = v15 + v14;
      *(_BYTE *)(a2 + 92) &= 0xFEu;
      *(_DWORD *)(a2 + 60) = HIDWORD(v14) + __CFADD__(v15, (_DWORD)v14) + v16;
      result = RtlRbRemoveNode(v12, a2 + 80);
      a2 = *(_DWORD *)(a2 + 236);
    }
    while ( a2 && (*(_BYTE *)(a2 + 92) & 1) != 0 && !*(_DWORD *)(a2 + 228) && !*(_WORD *)(a2 + 94) );
LABEL_11:
    a3[19] &= 0xFFFFDFFF;
    a3[206] = 0;
    return result;
  }
  v17 = a2 + 80;
  v18 = *(_DWORD *)(a2 + 84);
  if ( v18 )
  {
    for ( i = *(_DWORD **)v18; i; i = (_DWORD *)*i )
      v18 = (unsigned int)i;
  }
  else
  {
    v19 = *(_DWORD *)(a2 + 88);
    while ( 1 )
    {
      v18 = v19 & 0xFFFFFFFC;
      if ( (v19 & 0xFFFFFFFC) == 0 || *(_DWORD *)v18 == v17 )
        break;
      v19 = *(_DWORD *)(v18 + 8);
      v17 = v18;
    }
  }
  if ( !v18 )
    goto LABEL_11;
  v20 = *(_DWORD *)(a2 + 96) - *(_DWORD *)(v18 + 16);
  if ( v20 )
  {
LABEL_27:
    if ( v20 > 0 )
      JUMPOUT(0x51C378);
    goto LABEL_11;
  }
  if ( v9 )
  {
    result = 31 - __clz(*(unsigned __int16 *)(a2 + 94));
    v21 = 0;
    if ( *(_WORD *)(v18 + 14) )
      v21 = 31 - __clz(*(unsigned __int16 *)(v18 + 14));
    v20 = v21 - result;
    goto LABEL_27;
  }
  return sub_51C360();
}
