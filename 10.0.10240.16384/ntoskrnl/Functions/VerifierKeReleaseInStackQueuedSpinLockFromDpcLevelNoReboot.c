// VerifierKeReleaseInStackQueuedSpinLockFromDpcLevelNoReboot 
 
int __fastcall VerifierKeReleaseInStackQueuedSpinLockFromDpcLevelNoReboot(int a1)
{
  unsigned int v2; // r0

  v2 = KeGetCurrentIrql(a1);
  if ( v2 < 2 )
    VerifierBugCheckIfAppropriate(196, 50, v2, a1, 0);
  return pXdvKeReleaseInStackQueuedSpinLockFromDpcLevel(a1);
}
