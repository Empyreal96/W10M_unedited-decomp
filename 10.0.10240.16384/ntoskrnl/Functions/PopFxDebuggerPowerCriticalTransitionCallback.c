// PopFxDebuggerPowerCriticalTransitionCallback 
 
int __fastcall PopFxDebuggerPowerCriticalTransitionCallback(int a1, int a2, int a3)
{
  int result; // r0

  if ( PopAutomaticDebuggerTransitions )
    PopFxBugCheck(1566, 0, 0, 0);
  if ( a3 )
  {
    KdCallPowerHandlers(1);
    result = KdPowerTransition(-2147483647);
  }
  else
  {
    KdPowerTransition(-2147483644);
    result = KdCallPowerHandlers(4);
  }
  return result;
}
