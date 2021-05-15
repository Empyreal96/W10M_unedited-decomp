// NormBuffer__SetLastStart 
 
int __fastcall NormBuffer__SetLastStart(int result, int a2, char a3, char a4, char a5)
{
  int v5; // r4

  v5 = *(_DWORD *)(result + 44);
  *(_BYTE *)(result + 53) = a4;
  *(_WORD *)(v5 - 2) = a2;
  *(_DWORD *)(result + 48) = a2;
  *(_BYTE *)(result + 52) = a3;
  if ( a5 )
  {
    *(_DWORD *)(result + 56) = 0;
    *(_DWORD *)(result + 60) = 0;
  }
  return result;
}
