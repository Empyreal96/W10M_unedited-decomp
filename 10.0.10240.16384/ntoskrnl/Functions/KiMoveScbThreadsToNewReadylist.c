// KiMoveScbThreadsToNewReadylist 
 
int __fastcall KiMoveScbThreadsToNewReadylist(int result, int a2, int a3, _DWORD *a4)
{
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r6
  unsigned int v8; // r3
  _DWORD *v9; // r8
  _DWORD *v10; // r9
  _DWORD *v11; // r2
  int v12; // r3
  __int64 v13; // kr00_8
  _DWORD *v14; // r9
  _DWORD *v15; // r10
  int v16; // [sp+0h] [bp-28h]
  unsigned int v17; // [sp+4h] [bp-24h]

  v4 = *(unsigned __int16 *)(result + 94);
  v5 = 0;
  v6 = 0;
  v16 = result;
  if ( a2 )
    return sub_52BEB8();
  if ( a3 )
  {
    v5 = a3 + 2048;
    *(_DWORD *)(a3 + 1932) |= v4;
  }
  else if ( a4 )
  {
    v6 = 1;
  }
  for ( ; v4; v9[1] = v9 )
  {
    v8 = __clz(v4);
    v4 ^= 1 << (31 - v8);
    v9 = (_DWORD *)(result + 8 * (31 - v8) + 100);
    v17 = 31 - v8;
    v10 = (_DWORD *)*v9;
    do
    {
      v11 = v10 - 36;
      v12 = *(v10 - 17);
      v10[170] = 0;
      *(v10 - 17) = v12 & 0xFFFFDFFF;
      v10 = (_DWORD *)*v10;
      if ( v6 )
      {
        *((_BYTE *)v11 + 132) = 7;
        v11[36] = *a4;
        *a4 = v11 + 36;
      }
    }
    while ( v10 != v9 );
    result = v16;
    if ( !v6 )
    {
      v13 = *(_QWORD *)v9;
      if ( *(_DWORD **)(*v9 + 4) != v9 || *(_DWORD **)HIDWORD(v13) != v9 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v13) = v13;
      *(_DWORD *)(v13 + 4) = HIDWORD(v13);
      v14 = (_DWORD *)(v5 + 8 * v17);
      v15 = (_DWORD *)v14[1];
      if ( *(_DWORD **)(*v14 + 4) != v14 || (_DWORD *)*v15 != v14 )
        __fastfail(3u);
      if ( *(_DWORD *)(*(_DWORD *)v13 + 4) != (_DWORD)v13 || **(_DWORD **)(v13 + 4) != (_DWORD)v13 )
        __fastfail(3u);
      *v15 = v13;
      *(_DWORD *)(HIDWORD(v13) + 4) = *(_DWORD *)(v13 + 4);
      **(_DWORD **)(v13 + 4) = HIDWORD(v13);
      *(_DWORD *)(v13 + 4) = v15;
    }
    *v9 = v9;
  }
  *(_WORD *)(result + 94) = 0;
  return result;
}
