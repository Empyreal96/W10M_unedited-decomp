// NormBuffer__ReplaceLastStartBasePair 
 
int __fastcall NormBuffer__ReplaceLastStartBasePair(_DWORD *a1, int a2, int a3, int a4)
{
  int v8; // r8
  int v9; // r2
  int v10; // r3
  int result; // r0

  v8 = Normalization__GetThirdAndLastDecomposedCharPlane0(a1[17], a1[12]);
  NormBuffer__SetLastStart(a1, a2, a3, a4, 1);
  if ( v8 )
    result = NormBuffer__AppendAndSortDecomposed(a1, v8, v9, v10);
  else
    result = 1;
  return result;
}
