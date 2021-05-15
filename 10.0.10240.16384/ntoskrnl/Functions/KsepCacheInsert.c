// KsepCacheInsert 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall KsepCacheInsert(int a1, unsigned int *a2)
{
  unsigned int v4; // r7
  unsigned int v5; // r0
  unsigned int v6; // r0
  _QWORD *v7; // r5
  int v8; // r0
  int v9; // r1
  int *v10; // r2 OVERLAPPED
  int v11; // r1 OVERLAPPED
  _DWORD *result; // r0
  _DWORD *v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // r3
  __int64 *v16; // r2
  __int64 v17; // r0
  __int64 v18; // kr00_8

  v4 = (*(int (__fastcall **)(unsigned int *))(a1 + 52))(a2);
  v5 = *(_DWORD *)(a1 + 8);
  if ( !v5 )
    __brkdiv0();
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * (v4 % v5)) != *(_DWORD *)(a1 + 12) + 8 * (v4 % v5) )
    ++*(_DWORD *)(a1 + 36);
  *a2 = v4;
  v6 = *(_DWORD *)(a1 + 8);
  v7 = a2 + 1;
  if ( !v6 )
    __brkdiv0();
  v9 = v4 % v6;
  v8 = v4 / v6;
  v10 = (int *)(*(_DWORD *)(a1 + 12) + 8 * v9);
  v11 = *v10;
  *v7 = *(_QWORD *)&v11;
  if ( *(int **)(v11 + 4) != v10 )
    sub_7EF538(v8);
  *(_DWORD *)(v11 + 4) = v7;
  *v10 = (int)v7;
  result = *(_DWORD **)(a1 + 24);
  v13 = a2 + 3;
  a2[3] = a1 + 20;
  a2[4] = (unsigned int)result;
  if ( *result != a1 + 20 )
    __fastfail(3u);
  *result = v13;
  *(_DWORD *)(a1 + 24) = v13;
  ++*(_DWORD *)(a1 + 40);
  v14 = *(_DWORD *)(a1 + 4) + 1;
  v15 = *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 4) = v14;
  if ( v14 > v15 )
  {
    v16 = *(__int64 **)(a1 + 20);
    v17 = *v16;
    if ( *(__int64 **)(*(_DWORD *)v16 + 4) != v16 || *(__int64 **)HIDWORD(v17) != v16 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v17) = v17;
    *(_DWORD *)(v17 + 4) = HIDWORD(v17);
    v18 = *(v16 - 1);
    if ( *(__int64 **)(v18 + 4) != v16 - 1 || *(__int64 **)HIDWORD(v18) != v16 - 1 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v18) = v18;
    *(_DWORD *)(v18 + 4) = HIDWORD(v18);
    --*(_DWORD *)(a1 + 4);
    ++*(_DWORD *)(a1 + 44);
    result = (_DWORD *)(*(int (__fastcall **)(int))(a1 + 56))((int)v16 - 12);
  }
  return result;
}
