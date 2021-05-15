// RaspGetCacheEntry 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall RaspGetCacheEntry(_DWORD *result, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  _DWORD *v6; // r5
  _DWORD *v7; // r6
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  _DWORD *v10; // r2

  v6 = (_DWORD *)*result;
  v7 = 0;
  if ( (_DWORD *)*result != result )
  {
    while ( *((unsigned __int16 *)v6 + 22) != a2 || v6[6] != a3 || v6[5] != a4 || v6[3] != a5 )
    {
      v6 = (_DWORD *)*v6;
      if ( v6 == result )
        goto LABEL_13;
    }
    *(_QWORD *)&v8 = *(_QWORD *)v6;
    v7 = v6;
    if ( *(_DWORD **)(*v6 + 4) != v6 || (_DWORD *)*v9 != v6 )
      __fastfail(3u);
    *v9 = v8;
    *(_DWORD *)(v8 + 4) = v9;
    v10 = (_DWORD *)*result;
    *v6 = *result;
    v6[1] = result;
    if ( (_DWORD *)v10[1] != result )
      sub_50A9A8();
    v10[1] = v6;
    *result = v6;
  }
LABEL_13:
  *a6 = v7;
  return result;
}
