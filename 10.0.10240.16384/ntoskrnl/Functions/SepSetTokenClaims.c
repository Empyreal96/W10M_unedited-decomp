// SepSetTokenClaims 
 
int __fastcall SepSetTokenClaims(int a1, int a2, int a3, int a4)
{
  if ( a2 || a3 || a4 )
    return sub_7DBB08();
  *(_DWORD *)(a1 + 636) = 0;
  return 0;
}
