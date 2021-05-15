// CmpBuildRegMultiSz 
 
int __fastcall CmpBuildRegMultiSz(int result, int a2, _DWORD *a3, int a4, unsigned int a5)
{
  int v6; // r7
  int v7; // r4

  v6 = result;
  if ( a5 )
  {
    v7 = *a3 + result;
    result = memmove(v7, a4, a5);
    *a3 = v7 + a5 - v6 + 2;
    *(_WORD *)(v7 + a5) = 0;
  }
  return result;
}
