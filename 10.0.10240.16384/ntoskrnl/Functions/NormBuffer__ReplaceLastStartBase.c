// NormBuffer__ReplaceLastStartBase 
 
int __fastcall NormBuffer__ReplaceLastStartBase(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r2
  int v7; // r3
  int v9; // [sp+8h] [bp-10h] BYREF
  int v10[3]; // [sp+Ch] [bp-Ch] BYREF

  v9 = a3;
  v10[0] = a4;
  v5 = a1[12];
  NormBuffer__SetLastStart(a1, a2, a3, a4, 1);
  Normalization__GetSecondAndThirdDecomposedCharPlane0(a1[17], v5, v10, &v9);
  if ( v9 && !NormBuffer__AppendAndSortDecomposed(a1, v9, v6, v7) )
    return 0;
  if ( v10[0] )
    return NormBuffer__AppendAndSortDecomposed(a1, v10[0], v6, v7);
  return 1;
}
