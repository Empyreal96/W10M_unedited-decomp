// RtlCompressBufferXpressLz 
 
int __fastcall RtlCompressBufferXpressLz(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  if ( !a1 )
    return RtlCompressBufferXpressLzStandard(a2, a3, a4, a5, a7, (a8 + 3) & 0xFFFFFFFC, 0, 0, a3);
  if ( a1 == 256 )
    return RtlCompressBufferXpressLzMax(a2, a3, a4, a5, a7, (a8 + 3) & 0xFFFFFFFC, 0, 0, a3);
  return -1073741637;
}
