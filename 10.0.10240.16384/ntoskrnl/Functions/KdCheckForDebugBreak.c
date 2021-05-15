// KdCheckForDebugBreak 
 
int __fastcall KdCheckForDebugBreak(int result, int a2)
{
  if ( !KdPitchDebugger && KdDebuggerEnabled || KdEventLoggingEnabled )
  {
    result = KdPollBreakIn(result, a2);
    if ( result )
      DbgBreakPointWithStatus();
  }
  return result;
}
