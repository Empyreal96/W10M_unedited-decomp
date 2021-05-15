// KdpCopyCodeStream 
 
int __fastcall KdpCopyCodeStream(unsigned int a1, unsigned int a2, int a3, unsigned int a4, char a5)
{
  int result; // r0

  result = KdpCopyMemoryChunks(a1, a2, a3, a4, a4, a5, 0);
  if ( result >= 0 )
    return 0;
  KdpOweBreakpoint = 1;
  if ( (a5 & 5) == 5 )
  {
    result = KdpCopyMemoryChunks(a1, a2, a3, a4, a4, a5 | 0x40, 0);
    if ( result >= 0 )
      result = 259;
  }
  return result;
}
