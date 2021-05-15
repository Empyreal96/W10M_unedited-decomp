// NormBuffer__LastStartBase 
 
int __fastcall NormBuffer__LastStartBase(_DWORD *a1)
{
  if ( !a1[14] )
    a1[14] = Normalization__GetFirstDecomposedCharPlane0(a1[17], a1[12]);
  return a1[14];
}
