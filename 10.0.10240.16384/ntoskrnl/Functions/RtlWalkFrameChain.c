// RtlWalkFrameChain 
 
unsigned int __fastcall RtlWalkFrameChain(int a1, int a2, unsigned int a3)
{
  unsigned int v5; // r5
  int v6; // r4
  unsigned int result; // r0

  if ( (a3 & 0xFFFF00FC) != 0 )
    return 0;
  v5 = a3 >> 8;
  v6 = a3 & 3;
  if ( a3 >> 8 > 0xFE || a2 == -1 || !MmCanThreadFault() && (v6 & 1) != 0 )
    return 0;
  if ( !RtlEnoughStackSpaceForStackCapture() )
    return 0;
  result = RtlpWalkFrameChain(a1, a2 + 1, v6, v5 + 1);
  if ( result )
    --result;
  return result;
}
