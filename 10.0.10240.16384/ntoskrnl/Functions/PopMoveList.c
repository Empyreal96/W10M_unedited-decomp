// PopMoveList 
 
int __fastcall PopMoveList(int result, _DWORD *a2)
{
  _DWORD *v2; // r2
  __int64 v3; // kr00_8
  _DWORD *v4; // r4

  while ( 1 )
  {
    v2 = (_DWORD *)*a2;
    if ( (_DWORD *)*a2 == a2 )
      break;
    v3 = *(_QWORD *)v2;
    if ( (_DWORD *)v2[1] != a2 || *(_DWORD **)(v3 + 4) != v2 )
      __fastfail(3u);
    *a2 = v3;
    *(_DWORD *)(v3 + 4) = a2;
    v4 = *(_DWORD **)(result + 4);
    *v2 = result;
    v2[1] = v4;
    if ( *v4 != result )
      __fastfail(3u);
    *v4 = v2;
    *(_DWORD *)(result + 4) = v2;
  }
  return result;
}
