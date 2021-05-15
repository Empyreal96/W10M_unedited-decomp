// SepTrustLevelCheck 
 
int __fastcall SepTrustLevelCheck(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  if ( SepGetProcessTrustLabelAce(a2) )
    return sub_51D798();
  *a7 = -1;
  return 0;
}
