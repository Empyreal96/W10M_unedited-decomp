// BgpGxRectangleSize 
 
unsigned int __fastcall BgpGxRectangleSize(int a1, int a2, int a3)
{
  return ((unsigned int)(a1 * a2 * a3 + 7) >> 3) + 64;
}
