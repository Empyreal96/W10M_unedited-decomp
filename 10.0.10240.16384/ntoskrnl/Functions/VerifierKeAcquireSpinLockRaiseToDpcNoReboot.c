// VerifierKeAcquireSpinLockRaiseToDpcNoReboot 
 
int __fastcall VerifierKeAcquireSpinLockRaiseToDpcNoReboot(unsigned int a1)
{
  int v2; // r5
  int v3; // r4

  if ( a1 < MmHighestUserAddress || a1 + 4 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 4, 0);
  v2 = ViKeRaiseIrqlSanityChecks(2, (MmVerifierData & 0x20000) != 0);
  v3 = pXdvKeAcquireSpinLockRaiseToDpc(a1);
  if ( v2 )
    *(_WORD *)(v2 + 6) = KeGetCurrentProcessorNumberEx(0);
  return v3;
}
