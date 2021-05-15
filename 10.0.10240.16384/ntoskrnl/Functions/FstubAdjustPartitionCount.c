// FstubAdjustPartitionCount 
 
unsigned int __fastcall FstubAdjustPartitionCount(unsigned int a1, int *a2)
{
  int v2; // r3
  unsigned int result; // r0

  v2 = *a2;
  if ( (unsigned int)*a2 <= 0x80 )
    v2 = 128;
  if ( !a1 )
    __brkdiv0();
  result = (a1 + (v2 << 7) - 1) / a1;
  *a2 = (result * a1) >> 7;
  return result;
}
