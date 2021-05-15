// FsRtlLookupLastBaseMcbEntry 
 
int __fastcall FsRtlLookupLastBaseMcbEntry(int a1, _DWORD *a2, int *a3)
{
  int v4; // r4
  int result; // r0
  int v7; // r5
  int v8; // r0
  int v9; // r3
  int v10; // r2
  int v11; // r3

  v4 = *(_DWORD *)(a1 + 4);
  result = 0;
  if ( v4 )
  {
    v7 = *(_DWORD *)(a1 + 12) + 8 * v4;
    v8 = *(_DWORD *)(v7 - 4);
    v9 = -1;
    if ( v8 != -1 )
    {
      if ( v4 == 1 )
        v10 = 0;
      else
        v10 = *(_DWORD *)(v7 - 16);
      v9 = *(_DWORD *)(v7 - 8) - v10 + v8 - 1;
    }
    *a3 = v9;
    a3[1] = 0;
    v11 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * *(_DWORD *)(a1 + 4) - 8);
    a2[1] = 0;
    *a2 = v11 - 1;
    result = 1;
  }
  return result;
}
