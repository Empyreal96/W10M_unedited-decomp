// SepSidInToken 
 
int __fastcall SepSidInToken(int a1, int a2, int a3, int a4, char a5)
{
  int v5; // r0

  if ( a5 )
    v5 = a1 + 340;
  else
    v5 = a1 + 204;
  return SepSidInTokenSidHash(v5, a2, a3, a4);
}
