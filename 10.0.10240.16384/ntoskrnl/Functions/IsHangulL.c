// IsHangulL 
 
BOOL __fastcall IsHangulL(int a1)
{
  return (unsigned int)(a1 - 4352) <= 0x12;
}
