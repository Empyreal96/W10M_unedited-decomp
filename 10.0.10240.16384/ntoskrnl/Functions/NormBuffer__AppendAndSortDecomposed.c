// NormBuffer__AppendAndSortDecomposed 
 
int __fastcall NormBuffer__AppendAndSortDecomposed(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  Normalization__GetCharacterInfo(a1[17], a2, v7, (char *)v7 + 1);
  NormBuffer__SortBeforeSameClass(a1, LOBYTE(v7[0]));
  if ( a1[16] == a1[5] )
    result = NormBuffer__AppendEx(a1, a2, LOBYTE(v7[0]), BYTE1(v7[0]));
  else
    result = NormBuffer__Insert(a1, a2);
  return result;
}
