// IsHangulS 
 
BOOL __fastcall IsHangulS(int a1)
{
  return (unsigned int)(a1 - 44032) <= 0x2BA3;
}
