// VerifierKeReleaseInStackQueuedSpinLockForDpc 
 
int __fastcall VerifierKeReleaseInStackQueuedSpinLockForDpc(int a1)
{
  int v2; // r1
  int v3; // r0
  unsigned int v4; // r0

  v2 = *(_DWORD *)(a1 + 4);
  __dmb(0xBu);
  v3 = VfDeadlockReleaseResource(v2 & 0xFFFFFFFC, 6, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v4 = KeGetCurrentIrql(v3);
  if ( v4 < 2 )
    VerifierBugCheckIfAppropriate(196, 50, v4, a1, 0);
  return pXdvKeReleaseInStackQueuedSpinLockForDpc(a1);
}
