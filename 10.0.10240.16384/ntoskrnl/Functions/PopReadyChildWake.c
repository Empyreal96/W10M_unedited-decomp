// PopReadyChildWake 
 
int __fastcall PopReadyChildWake(__int64 *a1, int a2, int a3)
{
  int v3; // r5
  unsigned int v5; // r4
  unsigned int v6; // r3
  __int64 v7; // kr00_8
  int v8; // r2
  __int64 **v9; // r1

  v3 = 0;
  v5 = *((_DWORD *)a1 + 14) + 1;
  v6 = *((_DWORD *)a1 + 13);
  *((_DWORD *)a1 + 14) = v5;
  if ( v5 >= v6 )
  {
    v7 = *a1;
    if ( *(__int64 **)(*(_DWORD *)a1 + 4) != a1 || *(__int64 **)HIDWORD(v7) != a1 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v7) = v7;
    *(_DWORD *)(v7 + 4) = HIDWORD(v7);
    v8 = a2 + 40 * *((unsigned __int8 *)a1 + 28) + 32;
    v9 = *(__int64 ***)(a2 + 40 * *((unsigned __int8 *)a1 + 28) + 36);
    *(_DWORD *)a1 = v8;
    *((_DWORD *)a1 + 1) = v9;
    if ( *v9 != (__int64 *)v8 )
      __fastfail(3u);
    *v9 = a1;
    *(_DWORD *)(v8 + 4) = a1;
    if ( *((unsigned __int8 *)a1 + 28) == a3 )
      v3 = 1;
  }
  return v3;
}
