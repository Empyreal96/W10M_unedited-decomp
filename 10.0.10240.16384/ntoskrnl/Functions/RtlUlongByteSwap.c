// RtlUlongByteSwap 
 
unsigned int __fastcall RtlUlongByteSwap(unsigned int a1)
{
  return ((a1 & 0xFF0000 | HIWORD(a1)) >> 8) | ((a1 & 0xFF00 | (a1 << 16)) << 8);
}
