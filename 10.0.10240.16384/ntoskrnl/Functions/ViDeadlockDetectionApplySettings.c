// ViDeadlockDetectionApplySettings 
 
unsigned int __fastcall ViDeadlockDetectionApplySettings(int a1)
{
  unsigned int v1; // r4

  if ( (MmVerifierData & 0x20) == 0 )
    return ViDeadlockEmptyDatabase();
  v1 = ViRaiseIrqlToDpcLevel(a1);
  ViDeadlockDetectionLock(1);
  __dmb(0xBu);
  ViDeadlockDetectionEnabled = 1;
  ViDeadlockDetectionUnlock(1);
  return ViLowerIrql(v1);
}
