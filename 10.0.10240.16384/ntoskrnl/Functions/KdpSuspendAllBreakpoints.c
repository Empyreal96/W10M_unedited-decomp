// KdpSuspendAllBreakpoints 
 
BOOL KdpSuspendAllBreakpoints()
{
  int *v0; // r4
  int v1; // r5
  int v2; // r6
  int v3; // r3
  BOOL result; // r0

  v0 = KdpBreakpointTable;
  v1 = 0;
  v2 = 32;
  BreakpointsSuspended = 1;
  do
  {
    v3 = v0[6];
    if ( (v3 & 1) != 0 && (v3 & 4) == 0 )
    {
      v0[6] = v3 | 4;
      result = KdpLowWriteContent(v1);
    }
    ++v1;
    v0 += 8;
    --v2;
  }
  while ( v2 );
  return result;
}
