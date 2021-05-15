// NormBuffer__AppendEx 
 
int __fastcall NormBuffer__AppendEx(int a1, int a2, char a3, char a4)
{
  int v9; // r3

  if ( !NormBuffer__Append(a1, a2) )
    return 0;
  v9 = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 32) = a2;
  *(_BYTE *)(a1 + 40) = a3;
  *(_DWORD *)(a1 + 36) = v9 - 2;
  *(_BYTE *)(a1 + 41) = a4;
  return 1;
}
