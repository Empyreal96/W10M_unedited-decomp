// PoDiagCaptureUsermodeStack 
 
int PoDiagCaptureUsermodeStack()
{
  unsigned int *v0; // r0
  unsigned int *v1; // r4
  unsigned int v2; // r0

  v0 = (unsigned int *)ExAllocatePoolWithTag(1, 132, 1346721364);
  v1 = v0;
  if ( v0 )
  {
    memset(v0, 0, 132);
    v2 = RtlWalkFrameChain((int)(v1 + 1), 32, 1u);
    if ( !v2 )
      return sub_7E8BE0();
    *v1 = v2;
  }
  return (int)v1;
}
