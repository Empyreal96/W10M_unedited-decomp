// KdDisableDebuggerWithLock 
 
int KdDisableDebuggerWithLock()
{
  int v0; // r5
  int v1; // r0
  int v2; // r9
  unsigned int v3; // r2
  int v4; // r2
  int v5; // r1
  int v6; // r1
  int vars4; // [sp+24h] [bp+4h]

  if ( !KdPitchDebugger )
  {
    if ( KdBlockEnable )
      return -1073741790;
    v1 = KfRaiseIrql(2);
    v2 = v1;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      v1 = KiAcquireSpinLockInstrumented((int)&KdDebuggerLock);
    }
    else
    {
      do
        v3 = __ldrex((unsigned int *)&KdDebuggerLock);
      while ( __strex(1u, (unsigned int *)&KdDebuggerLock) );
      __dmb(0xBu);
      if ( v3 )
        v1 = KxWaitForSpinLockAndAcquire((unsigned int *)&KdDebuggerLock);
    }
    v4 = KdDisableCount;
    if ( !KdDisableCount )
    {
      KdPreviouslyEnabled = KdDebuggerEnabled;
      if ( KdDebuggerEnabled )
      {
        v0 = KdpAllowDisable(v1);
        if ( v0 < 0 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(&KdDebuggerLock, vars4);
          }
          else
          {
            __dmb(0xBu);
            KdDebuggerLock = 0;
          }
LABEL_22:
          KfLowerIrql(v2);
          return v0;
        }
        if ( v5 )
        {
          KdpSuspendAllBreakpoints();
          MEMORY[0xFFFF92D4] = 0;
          KdDebuggerNotPresent = 1;
          KdDebuggerEnabled = 0;
          KiDebugRoutine = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))KdpStub;
          KdPowerTransition(4, v6);
          v4 = KdDisableCount;
        }
      }
    }
    KdDisableCount = v4 + 1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&KdDebuggerLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      KdDebuggerLock = 0;
    }
    v0 = 0;
    goto LABEL_22;
  }
  return -1073740972;
}
