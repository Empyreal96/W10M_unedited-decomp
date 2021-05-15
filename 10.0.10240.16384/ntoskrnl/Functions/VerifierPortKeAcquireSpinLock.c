// VerifierPortKeAcquireSpinLock 
 
int __fastcall VerifierPortKeAcquireSpinLock(unsigned int a1, _BYTE *a2, unsigned int a3)
{
  int v5; // r3
  int v6; // r4
  int result; // r0

  v5 = dword_620D88 + 1;
  __dmb(0xBu);
  dword_620D88 = v5;
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetIncrementCounter(a3, 76, a3, MmVerifierData);
  if ( a1 < MmHighestUserAddress || a1 + 4 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 4, 0);
  v6 = ViKeRaiseIrqlSanityChecks(2, 0);
  result = pXdvKeAcquireSpinLockRaiseToDpc(a1);
  *a2 = result;
  if ( v6 )
  {
    result = KeGetCurrentProcessorNumberEx(0);
    *(_WORD *)(v6 + 6) = result;
  }
  return result;
}
