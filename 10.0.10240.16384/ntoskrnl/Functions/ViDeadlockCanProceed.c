// ViDeadlockCanProceed 
 
BOOL __fastcall ViDeadlockCanProceed(int *a1, int a2)
{
  int v4; // r3
  BOOL result; // r0
  int v6; // r0
  int v7; // r3

  v4 = ViDeadlockDetectionEnabled;
  __dmb(0xBu);
  result = v4
        && (unsigned int)KeNumberProcessors_0 <= 4
        && (unsigned int)KeGetCurrentIrql(a1) <= 2
        && KeAreInterruptsEnabled()
        && ViDeadlockGlobals
        && ((v6 = ViDeadlockCheckStackLimits(), v7 = ViDeadlockVerifyOnlySpinlocks, __dmb(0xBu), !v7)
         || !a2
         || a2 == 7
         || a2 == 5
         || a2 == 6)
        && a1 != &ViDeadlockDatabaseLock
        && !ViDeadlockDetectionIsLockedAlready(v6);
  return result;
}
