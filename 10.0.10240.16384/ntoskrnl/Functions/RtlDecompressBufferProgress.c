// RtlDecompressBufferProgress 
 
int __fastcall RtlDecompressBufferProgress(char a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  if ( a1 == 3 )
    return RtlDecompressBufferXpressLzProgress(a2, a3, a4, a5, a6, a8, a9);
  if ( a1 == 4 )
    return RtlDecompressBufferXpressHuffProgress(a2, a3, a4, a5, a6, a7, a8, a9);
  return -1073741217;
}
