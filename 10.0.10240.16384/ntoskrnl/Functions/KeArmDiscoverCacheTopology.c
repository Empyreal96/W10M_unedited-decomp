// KeArmDiscoverCacheTopology 
 
void KeArmDiscoverCacheTopology()
{
  int v0; // r3

  if ( !InitSafeBootMode )
  {
    if ( (unsigned __int8)KdDebuggerNotPresent | (unsigned __int8)KdPitchDebugger )
      v0 = -1;
    else
      v0 = 17;
    if ( !(v0 + ((unsigned __int8)KdDebuggerNotPresent | (unsigned __int8)KdPitchDebugger)) )
      __brkdiv0();
    __dmb(0xBu);
  }
}
