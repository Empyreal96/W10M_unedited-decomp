// PipMoveListEntries 
 
_DWORD *__fastcall PipMoveListEntries(_DWORD *result, int a2)
{
  _DWORD *v2; // r2
  _DWORD *v3; // r4
  __int64 v4; // kr00_8

  v2 = *(_DWORD **)a2;
  if ( *(_DWORD *)a2 != a2 )
  {
    v3 = *(_DWORD **)(a2 + 4);
    if ( v2[1] != a2 || *v3 != a2 )
      __fastfail(3u);
    *v3 = v2;
    v2[1] = v3;
    *(_DWORD *)a2 = a2;
    *(_DWORD *)(a2 + 4) = a2;
    v4 = *(_QWORD *)result;
    if ( *(_DWORD **)(*result + 4) != result || *(_DWORD **)HIDWORD(v4) != result )
      __fastfail(3u);
    if ( *(_DWORD **)(*v2 + 4) != v2 || *(_DWORD **)v2[1] != v2 )
      sub_550B98();
    *(_DWORD *)HIDWORD(v4) = v2;
    result[1] = v2[1];
    *(_DWORD *)v2[1] = result;
    v2[1] = HIDWORD(v4);
  }
  return result;
}
