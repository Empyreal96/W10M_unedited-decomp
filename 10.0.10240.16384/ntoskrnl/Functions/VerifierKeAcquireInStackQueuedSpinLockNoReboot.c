// VerifierKeAcquireInStackQueuedSpinLockNoReboot 
 
int __fastcall VerifierKeAcquireInStackQueuedSpinLockNoReboot(unsigned int a1, unsigned int a2)
{
  int v4; // r3
  unsigned int v5; // r2
  int v6; // r6
  int result; // r0
  unsigned int vars4; // [sp+1Ch] [bp+4h]

  v4 = dword_620D88 + 1;
  __dmb(0xBu);
  dword_620D88 = v4;
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetIncrementCounter(vars4, 76, (int)&MmVerifierData, MmVerifierData);
  v5 = MmHighestUserAddress;
  if ( a1 < MmHighestUserAddress || a1 + 4 < a1 )
  {
    VerifierBugCheckIfAppropriate(196, 224, a1, 4, 0);
    v5 = MmHighestUserAddress;
  }
  if ( a2 < v5 || a2 + 12 < a2 )
    VerifierBugCheckIfAppropriate(196, 224, a2, 12, 0);
  v6 = ViKeRaiseIrqlSanityChecks(2, 0);
  result = pXdvKeAcquireInStackQueuedSpinLock(a1, a2);
  if ( v6 )
  {
    result = KeGetCurrentProcessorNumberEx(0);
    *(_WORD *)(v6 + 6) = result;
  }
  return result;
}
