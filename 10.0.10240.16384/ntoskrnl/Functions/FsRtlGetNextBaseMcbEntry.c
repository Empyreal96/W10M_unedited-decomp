// FsRtlGetNextBaseMcbEntry 
 
int __fastcall FsRtlGetNextBaseMcbEntry(int a1, unsigned int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v6; // r4
  int result; // r0
  int v10; // r4
  int v11; // r2
  int v12; // r3
  int v13; // r3
  int v14; // r2

  v6 = *(_DWORD *)(a1 + 4);
  result = 0;
  if ( a2 < v6 )
  {
    if ( a2 )
      v10 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * a2 - 8);
    else
      v10 = 0;
    v11 = -1;
    *a3 = v10;
    if ( v10 == -1 )
      v12 = -1;
    else
      v12 = 0;
    a3[1] = v12;
    v13 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * a2 + 4);
    if ( v13 != -1 )
      v11 = 0;
    *a4 = v13;
    a4[1] = v11;
    if ( a2 )
      v14 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * a2 - 8);
    else
      v14 = 0;
    *a5 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * a2) - v14;
    a5[1] = 0;
    result = 1;
  }
  return result;
}
