// IsHangulT 
 
BOOL __fastcall IsHangulT(int a1)
{
  return (unsigned int)(a1 - 4520) <= 0x1A;
}
