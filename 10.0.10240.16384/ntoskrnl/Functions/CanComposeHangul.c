// CanComposeHangul 
 
BOOL __fastcall CanComposeHangul(int a1, int a2)
{
  int v3; // r1
  int v4; // r2

  return IsHangulL(a1, a2, a1) && IsHangulV(v3) || IsHangulLV(v4) && IsHangulT(a2);
}
