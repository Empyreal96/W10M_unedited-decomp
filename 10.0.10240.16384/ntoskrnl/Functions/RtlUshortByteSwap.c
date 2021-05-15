// RtlUshortByteSwap 
 
int __fastcall RtlUshortByteSwap(unsigned int a1)
{
  return (unsigned __int16)((_WORD)a1 << 8) | (a1 >> 8);
}
