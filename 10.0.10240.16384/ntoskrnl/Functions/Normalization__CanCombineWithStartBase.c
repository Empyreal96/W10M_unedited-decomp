// Normalization__CanCombineWithStartBase 
 
int __fastcall Normalization__CanCombineWithStartBase(_DWORD *a1, int *a2, int a3, int a4)
{
  if ( !*a2 )
    *a2 = Normalization__GetFirstDecomposedCharPlane0(a1, a3);
  return Normalization__CanCombinableCharactersCombine(a1, *a2, a4, a4);
}
