// IsHangulLV 
 
BOOL __fastcall IsHangulLV(int a1)
{
  int v1; // r1

  return IsHangulS(a1, a1) && !((v1 - 44032) % 28);
}
