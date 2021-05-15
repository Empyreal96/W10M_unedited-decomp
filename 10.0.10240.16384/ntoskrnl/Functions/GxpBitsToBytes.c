// GxpBitsToBytes 
 
unsigned int __fastcall GxpBitsToBytes(int a1)
{
  return ((a1 + 7) & 0xFFFFFFF8) >> 3;
}
