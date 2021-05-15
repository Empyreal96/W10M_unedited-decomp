// VerifierKeReleaseSpinLockFromDpcLevelNoReboot 
 
int __fastcall VerifierKeReleaseSpinLockFromDpcLevelNoReboot(unsigned int a1)
{
  int v1; // r4
  unsigned int v2; // r0

  v1 = a1;
  if ( a1 < MmHighestUserAddress || a1 + 4 < a1 )
    a1 = VerifierBugCheckIfAppropriate(196, 224, a1, 4, 0);
  v2 = KeGetCurrentIrql(a1);
  if ( v2 < 2 )
    VerifierBugCheckIfAppropriate(196, 65, v2, v1, 0);
  return pXdvKeReleaseSpinLockFromDpcLevel(v1);
}
