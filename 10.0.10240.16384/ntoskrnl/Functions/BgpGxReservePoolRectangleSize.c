// BgpGxReservePoolRectangleSize 
 
unsigned int __fastcall BgpGxReservePoolRectangleSize(int a1, int a2, int a3)
{
  return ((BgpGxRectangleSize(a1, a2, a3) + 15) & 0xFFFFFFF0) + 16;
}
