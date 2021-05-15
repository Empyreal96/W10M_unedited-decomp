// FsRtlLookupLastBaseMcbEntryAndIndex 
 
int __fastcall FsRtlLookupLastBaseMcbEntryAndIndex(int a1, _DWORD *a2, int *a3, _DWORD *a4)
{
  int v5; // r6
  int result; // r0
  int v7; // r5
  int v10; // r3
  int v11; // r4
  int v12; // r2
  int v13; // r3
  int v14; // r2

  v5 = *(_DWORD *)(a1 + 4);
  result = 0;
  v7 = -1;
  if ( v5 )
  {
    v11 = *(_DWORD *)(a1 + 12) + 8 * v5;
    v12 = *(_DWORD *)(v11 - 4);
    if ( v12 == -1 )
    {
      v14 = -1;
    }
    else
    {
      if ( v5 == 1 )
        v13 = 0;
      else
        v13 = *(_DWORD *)(v11 - 16);
      v14 = *(_DWORD *)(v11 - 8) + v12 - v13 - 1;
    }
    *a3 = v14;
    *a2 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * *(_DWORD *)(a1 + 4) - 8) - 1;
    *a4 = *(_DWORD *)(a1 + 4) - 1;
    result = 1;
  }
  if ( *a2 == -1 )
    v10 = -1;
  else
    v10 = 0;
  a2[1] = v10;
  if ( *a3 != -1 )
    v7 = 0;
  a3[1] = v7;
  return result;
}
