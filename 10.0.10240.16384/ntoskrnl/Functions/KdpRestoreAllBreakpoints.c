// KdpRestoreAllBreakpoints 
 
int KdpRestoreAllBreakpoints()
{
  int *v0; // r5
  unsigned int i; // r4
  int result; // r0

  v0 = KdpBreakpointTable;
  BreakpointsSuspended = 0;
  for ( i = 0; i < 0x20; ++i )
  {
    if ( (v0[6] & 5) == 5 )
    {
      v0[6] &= 0xFFFFFFFB;
      result = KdpLowRestoreBreakpoint(i);
    }
    v0 += 8;
  }
  return result;
}
