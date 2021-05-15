// KdEnableDebuggerWithLock 
 
int __fastcall KdEnableDebuggerWithLock(int a1, int a2)
{
  int v3; // r8
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = 0;
  if ( KdPitchDebugger )
    return -1073740972;
  if ( KdBlockEnable )
    return -1073741790;
  if ( a1 )
  {
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&KdDebuggerLock);
    }
    else
    {
      a2 = 1;
      do
        v5 = __ldrex((unsigned int *)&KdDebuggerLock);
      while ( __strex(1u, (unsigned int *)&KdDebuggerLock) );
      __dmb(0xBu);
      if ( v5 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&KdDebuggerLock);
    }
  }
  if ( KdDisableCount )
  {
    if ( !--KdDisableCount && KdPreviouslyEnabled )
    {
      if ( a1 )
      {
        v6 = KdPowerTransition(1, a2);
        KiDebugRoutine = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))KdpTrap;
        KdDebuggerEnabled = 1;
        MEMORY[0xFFFF92D4] = 1;
        KdpRestoreAllBreakpoints(v6);
      }
      else
      {
        PoHiberInProgress = 1;
        v7 = KdInitSystem(0, 0);
        KdpRestoreAllBreakpoints(v7);
        PoHiberInProgress = 0;
      }
    }
    if ( a1 )
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
      KfLowerIrql(v3);
    }
    return 0;
  }
  if ( !a1 )
  {
    KdInitSystem(0, 0);
    return 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KdDebuggerLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KdDebuggerLock = 0;
  }
  KfLowerIrql(v3);
  return -1073741811;
}
