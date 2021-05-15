// Normalization__CanCombineWithStartFirstPair 
 
int __fastcall Normalization__CanCombineWithStartFirstPair(_DWORD *a1, int *a2, int *a3, int a4, int a5)
{
  int v9; // r0
  int v10; // r3

  if ( !*a2 )
  {
    if ( !*a3 )
      *a3 = Normalization__GetFirstDecomposedCharPlane0(a1, a4);
    v9 = Normalization__GetSecondDecomposedCharPlane0(a1, a4);
    *a2 = Normalization__CanCombinableCharactersCombine(a1, *a3, v9, v10);
  }
  return Normalization__CanCombinableCharactersCombine(a1, *a2, a5, a4);
}
