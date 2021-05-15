// PopReadyParentSleep 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopReadyParentSleep(__int64 *a1, int a2, int a3)
{
  int v3; // r4
  int v5; // r3
  __int64 v6; // kr00_8
  int v7; // r1 OVERLAPPED
  __int64 **v8; // r2 OVERLAPPED

  v3 = 0;
  v5 = *((_DWORD *)a1 + 12) - 1;
  *((_DWORD *)a1 + 12) = v5;
  if ( !v5 )
  {
    v6 = *a1;
    if ( *(__int64 **)(*(_DWORD *)a1 + 4) != a1 || *(__int64 **)HIDWORD(v6) != a1 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v6) = v6;
    *(_DWORD *)(v6 + 4) = HIDWORD(v6);
    v7 = a2 + 40 * *((unsigned __int8 *)a1 + 28) + 24;
    v8 = *(__int64 ***)(v7 + 4);
    *a1 = *(_QWORD *)&v7;
    if ( *v8 != (__int64 *)v7 )
      __fastfail(3u);
    *v8 = a1;
    *(_DWORD *)(v7 + 4) = a1;
    if ( *((unsigned __int8 *)a1 + 28) == a3 )
      v3 = 1;
  }
  return v3;
}
