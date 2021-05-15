// VerifierKeAcquireSpinLockAtDpcLevel 
 
int __fastcall VerifierKeAcquireSpinLockAtDpcLevel(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r3
  unsigned int v5; // r0
  unsigned int vars4; // [sp+1Ch] [bp+4h]

  v3 = a1;
  v4 = dword_620D88 + 1;
  __dmb(0xBu);
  dword_620D88 = v4;
  if ( (MmVerifierData & 0x1000) != 0 )
    a1 = ViTargetIncrementCounter(vars4, 76, a3, MmVerifierData);
  if ( v3 < MmHighestUserAddress || v3 + 4 < v3 )
    a1 = VerifierBugCheckIfAppropriate(196, 224, v3, 4, 0);
  if ( (MmVerifierData & 0x20000) == 0 )
  {
    v5 = KeGetCurrentIrql(a1);
    if ( v5 < 2 )
      VerifierBugCheckIfAppropriate(196, 64, v5, v3, 0);
  }
  pXdvKeAcquireSpinLockAtDpcLevel(v3);
  return VfDeadlockAcquireResource(v3, 5, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
}
