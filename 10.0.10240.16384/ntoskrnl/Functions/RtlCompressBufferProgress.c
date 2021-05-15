// RtlCompressBufferProgress 
 
int __fastcall RtlCompressBufferProgress(__int16 a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r4

  v9 = a1 & 0xFF00;
  if ( (unsigned __int8)a1 == 3 )
  {
    if ( (a1 & 0xFF00) == 0 )
      return RtlCompressBufferXpressLzStandard(a2, a3, a4, 0x10000, a6, (a7 + 3) & 0xFFFFFFFC, a8, a9, 4096);
    if ( v9 == 256 )
      return RtlCompressBufferXpressLzMax(a2, a3, a4, 0x10000, a6, (a7 + 3) & 0xFFFFFFFC, a8, a9, 4096);
  }
  else if ( (unsigned __int8)a1 == 4 )
  {
    if ( (a1 & 0xFF00) == 0 )
      return RtlCompressBufferXpressHuffStandard(a2, a3, a4, 0x10000, a6, (a7 + 3) & 0xFFFFFFFC, a8, a9, 4096);
    if ( v9 == 256 )
      return RtlCompressBufferXpressHuffMax(a2, a3, a4, 0x10000, a6, (a7 + 3) & 0xFFFFFFFC, a8, a9, 4096);
  }
  return -1073741217;
}
