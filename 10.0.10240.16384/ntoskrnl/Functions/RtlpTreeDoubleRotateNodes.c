// RtlpTreeDoubleRotateNodes 
 
int __fastcall RtlpTreeDoubleRotateNodes(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  int result; // r0
  int v6; // r4
  int v7; // r6
  unsigned int v8; // r2
  int v9; // r2

  result = *(_DWORD *)a3;
  if ( !a4 )
    result = *(_DWORD *)(a3 + 4);
  if ( (*(_DWORD *)(result + 8) & 0xFFFFFFFC) != a3 )
    sub_50AB1C();
  v6 = a4 ^ 1;
  if ( *(_DWORD *)(a3 + 4 * (a4 ^ 1)) != result )
    __fastfail(0x1Du);
  if ( *(_DWORD *)(a2 + 4 * a4) != a3 || (*(_DWORD *)(a3 + 8) & 0xFFFFFFFC) != a2 )
    __fastfail(0x1Du);
  *(_DWORD *)(a2 + 4 * a4) = result;
  *(_DWORD *)(result + 8) = *(_DWORD *)(result + 8) & 3 | a2;
  v7 = *(_DWORD *)(result + 4 * a4);
  if ( v7 )
  {
    if ( (*(_DWORD *)(v7 + 8) & 0xFFFFFFFC) != result )
      __fastfail(0x1Du);
    *(_DWORD *)(v7 + 8) = *(_DWORD *)(v7 + 8) & 3 | a3;
  }
  *(_DWORD *)(a3 + 4 * v6) = v7;
  *(_DWORD *)(result + 4 * a4) = a3;
  *(_DWORD *)(a3 + 8) = *(_DWORD *)(a3 + 8) & 3 | result;
  if ( (*(_DWORD *)(result + 8) & 0xFFFFFFFC) != a2 )
    __fastfail(0x1Du);
  if ( *(_DWORD *)(a2 + 4 * a4) != result )
    __fastfail(0x1Du);
  v8 = *(_DWORD *)(a2 + 8) & 0xFFFFFFFC;
  if ( v8 )
  {
    if ( *(_DWORD *)(v8 + 4) == a2 )
    {
      *(_DWORD *)(v8 + 4) = result;
    }
    else
    {
      if ( *(_DWORD *)v8 != a2 )
        __fastfail(0x1Du);
      *(_DWORD *)v8 = result;
    }
  }
  else
  {
    if ( *a1 != a2 )
      __fastfail(0x1Du);
    *a1 = result;
  }
  *(_DWORD *)(result + 8) = *(_DWORD *)(result + 8) & 3 | v8;
  v9 = *(_DWORD *)(result + 4 * v6);
  if ( v9 )
  {
    if ( (*(_DWORD *)(v9 + 8) & 0xFFFFFFFC) != result )
      __fastfail(0x1Du);
    *(_DWORD *)(v9 + 8) = *(_DWORD *)(v9 + 8) & 3 | a2;
  }
  *(_DWORD *)(a2 + 4 * a4) = v9;
  *(_DWORD *)(result + 4 * v6) = a2;
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a2 + 8) & 3 | result;
  return result;
}
