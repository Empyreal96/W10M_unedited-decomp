// RtlCaptureStackBackTrace 
 
int __fastcall RtlCaptureStackBackTrace(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r5
  unsigned int v6; // r4
  unsigned int v7; // r0

  v4 = a2;
  if ( a2 > 0xFFFF )
    v4 = 0xFFFF;
  if ( a1 > 0xFE )
    return 0;
  v6 = a1 + 1;
  v7 = RtlWalkFrameChain(a3, a1 + 1 + v4, (a1 + 1) << 8);
  if ( v7 <= v6 )
    return 0;
  if ( a4 )
    return sub_5483A4();
  return (unsigned __int16)(v7 - v6);
}
