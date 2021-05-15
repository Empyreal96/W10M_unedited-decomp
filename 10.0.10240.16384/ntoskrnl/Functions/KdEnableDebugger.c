// KdEnableDebugger 
 
int KdEnableDebugger()
{
  BOOL v0; // r5
  int result; // r0
  int v2; // r2
  void **v3; // r1
  int v4; // t1
  char v5; // r3

  v0 = KeEnableWatchdogTimeout == 0;
  KeEnableWatchdogTimeout = 0;
  result = KdEnableDebuggerWithLock(1);
  if ( v0 )
  {
    v5 = 0;
  }
  else
  {
    if ( !KeEnableWatchdogTimeout )
    {
      v2 = KeNumberProcessors_0;
      if ( KeNumberProcessors_0 )
      {
        v3 = &KiProcessorBlock;
        do
        {
          v4 = (int)*v3++;
          --v2;
          *(_DWORD *)(v4 + 1856) = 0;
          *(_DWORD *)(v4 + 2332) = 0;
        }
        while ( v2 );
      }
    }
    v5 = 1;
  }
  KeEnableWatchdogTimeout = v5;
  return result;
}
