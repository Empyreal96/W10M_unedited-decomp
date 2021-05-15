// WdipSemMergeEvents 
 
int __fastcall WdipSemMergeEvents(int result, int a2)
{
  unsigned int v3; // r3
  int v4; // r2
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int v9; // r2

  if ( result && a2 )
  {
    v3 = *(unsigned __int8 *)(result + 18);
    if ( v3 <= *(unsigned __int8 *)(a2 + 18) )
      LOBYTE(v3) = *(_BYTE *)(a2 + 18);
    v4 = *(_DWORD *)(result + 24);
    *(_BYTE *)(result + 18) = v3;
    v5 = v4 | *(_DWORD *)(a2 + 24);
    v6 = *(_DWORD *)(result + 28);
    v7 = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(result + 24) = v5;
    v8 = v7 | v6;
    v9 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 28) = v8;
    *(_DWORD *)(result + 36) = *(_DWORD *)(a2 + 36) | v9;
  }
  return result;
}
