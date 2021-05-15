// PiUEventMovePendingEventToSynchronousQueue 
 
_DWORD *__fastcall PiUEventMovePendingEventToSynchronousQueue(int a1, _DWORD *a2)
{
  __int64 v2; // kr00_8
  int v3; // r2
  _DWORD *result; // r0

  v2 = *(_QWORD *)a2;
  if ( *(_DWORD **)(*a2 + 4) != a2 || *(_DWORD **)HIDWORD(v2) != a2 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v2) = v2;
  *(_DWORD *)(v2 + 4) = HIDWORD(v2);
  v3 = a1 + 56;
  --*(_DWORD *)(a1 + 72);
  result = *(_DWORD **)(a1 + 60);
  *a2 = v3;
  a2[1] = result;
  if ( *result != v3 )
    __fastfail(3u);
  *result = a2;
  *(_DWORD *)(v3 + 4) = a2;
  return result;
}
