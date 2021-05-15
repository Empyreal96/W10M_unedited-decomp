// TxtpGetCacheEntry 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall TxtpGetCacheEntry(_DWORD *a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r7
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED
  _DWORD *v8; // r2

  v3 = (_DWORD *)*a1;
  v4 = 0;
  while ( v3 != a1 )
  {
    if ( *((unsigned __int16 *)v3 + 4) == a2 && v3[3] == *a3 && v3[4] == a3[1] && v3[5] == a3[2] && v3[6] == a3[3] )
    {
      *(_QWORD *)&v6 = *(_QWORD *)v3;
      v4 = v3;
      if ( *(_DWORD **)(*v3 + 4) != v3 || (_DWORD *)*v7 != v3 )
        __fastfail(3u);
      *v7 = v6;
      *(_DWORD *)(v6 + 4) = v7;
      v8 = (_DWORD *)*a1;
      *v3 = *a1;
      v3[1] = a1;
      if ( (_DWORD *)v8[1] != a1 )
        __fastfail(3u);
      v8[1] = v3;
      *a1 = v3;
      return v4;
    }
    v3 = (_DWORD *)*v3;
  }
  return v4;
}
