// NormBuffer__LastStartBasePair 
 
int __fastcall NormBuffer__LastStartBasePair(_DWORD *a1)
{
  int v2; // r4
  int v3; // r0

  if ( !a1[15] )
  {
    v2 = Normalization__GetSecondDecomposedCharPlane0(a1[17], a1[12]);
    v3 = NormBuffer__LastStartBase(a1);
    a1[15] = Normalization__CanCombinableCharactersCombine(a1[17], v3, v2);
  }
  return a1[15];
}
