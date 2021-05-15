// VerifierKeTryToAcquireSpinLockAtDpcLevel 
 
int __fastcall VerifierKeTryToAcquireSpinLockAtDpcLevel(int a1)
{
  unsigned int v1; // r4
  int v2; // r3
  unsigned int v3; // r0
  int v4; // r5
  unsigned int vars4; // [sp+14h] [bp+4h]

  v1 = a1;
  v2 = dword_620D88 + 1;
  __dmb(0xBu);
  dword_620D88 = v2;
  if ( (MmVerifierData & 0x1000) != 0 )
    a1 = ViTargetIncrementCounter(vars4, 76, (int)&MmVerifierData, MmVerifierData);
  if ( v1 < MmHighestUserAddress || v1 + 4 < v1 )
    a1 = VerifierBugCheckIfAppropriate(196, 224, v1, 4, 0);
  v3 = KeGetCurrentIrql(a1);
  if ( v3 < 2 )
    VerifierBugCheckIfAppropriate(196, 64, v3, v1, 0);
  v4 = pXdvKeTryToAcquireSpinLockAtDpcLevel(v1);
  if ( v4 )
    VfDeadlockAcquireResource(v1, 5, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1);
  return v4;
}
