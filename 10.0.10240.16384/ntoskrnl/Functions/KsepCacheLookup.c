// KsepCacheLookup 
 
_DWORD *__fastcall KsepCacheLookup(int a1, int a2)
{
  unsigned int v4; // r6
  unsigned int v5; // r0
  _DWORD *v6; // r3
  _DWORD *v7; // r5
  _DWORD *v9; // r2
  __int64 v10; // r0
  _DWORD *v11; // r0
  unsigned int v12; // r0

  v4 = (*(int (__fastcall **)(int))(a1 + 52))(a2);
  v5 = *(_DWORD *)(a1 + 8);
  if ( !v5 )
    __brkdiv0();
  v6 = (_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * (v4 % v5));
  v7 = (_DWORD *)*v6;
  while ( 1 )
  {
    if ( v7 == v6 )
    {
      ++*(_DWORD *)(a1 + 32);
      return 0;
    }
    if ( v4 == *(v7 - 1) && (*(int (__fastcall **)(int, _DWORD *))(a1 + 48))(a2, v7 - 1) )
      break;
    v12 = *(_DWORD *)(a1 + 8);
    v7 = (_DWORD *)*v7;
    if ( !v12 )
      __brkdiv0();
    v6 = (_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * (v4 % v12));
  }
  v9 = v7 + 2;
  v10 = *((_QWORD *)v7 + 1);
  if ( *(_DWORD **)(v10 + 4) != v7 + 2 || *(_DWORD **)HIDWORD(v10) != v9 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v10) = v10;
  *(_DWORD *)(v10 + 4) = HIDWORD(v10);
  v11 = *(_DWORD **)(a1 + 24);
  *v9 = a1 + 20;
  v7[3] = v11;
  if ( *v11 != a1 + 20 )
    sub_7EF590();
  *v11 = v9;
  *(_DWORD *)(a1 + 24) = v9;
  ++*(_DWORD *)(a1 + 28);
  return v7 - 1;
}
