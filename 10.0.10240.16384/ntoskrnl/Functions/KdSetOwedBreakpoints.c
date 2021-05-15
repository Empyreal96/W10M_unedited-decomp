// KdSetOwedBreakpoints 
 
int KdSetOwedBreakpoints()
{
  int result; // r0

  if ( !KdPitchDebugger )
  {
    if ( KdpOweBreakpoint )
      result = KdpSetOwedBreakpoints();
  }
  return result;
}
