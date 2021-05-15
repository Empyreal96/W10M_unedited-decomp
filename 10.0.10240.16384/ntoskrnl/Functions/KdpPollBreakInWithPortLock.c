// KdpPollBreakInWithPortLock 
 
int KdpPollBreakInWithPortLock()
{
  int v0; // r4

  v0 = 0;
  if ( KdDebuggerEnabled )
  {
    if ( byte_62F974 )
      return sub_51BCB4();
    if ( !KdReceivePacket_0(8, 0, 0) )
      v0 = 1;
  }
  return v0;
}
