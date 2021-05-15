// SeShouldCheckForAccessRightsFromParent 
 
int __fastcall SeShouldCheckForAccessRightsFromParent(int a1, int a2)
{
  int result; // r0

  if ( SepGetProcessTrustLabelAce(a2) )
    result = sub_7DC6A4();
  else
    result = 1;
  return result;
}
