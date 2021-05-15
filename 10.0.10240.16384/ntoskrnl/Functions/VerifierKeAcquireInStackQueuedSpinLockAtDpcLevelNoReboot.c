// VerifierKeAcquireInStackQueuedSpinLockAtDpcLevelNoReboot 
 
int __fastcall VerifierKeAcquireInStackQueuedSpinLockAtDpcLevelNoReboot(int a1, unsigned int a2)
{
  unsigned int v3; // r5
  int v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r0
  unsigned int vars4; // [sp+1Ch] [bp+4h]

  v3 = a1;
  v4 = dword_620D88 + 1;
  __dmb(0xBu);
  dword_620D88 = v4;
  if ( (MmVerifierData & 0x1000) != 0 )
    a1 = ViTargetIncrementCounter(vars4, 76, (int)&MmVerifierData, MmVerifierData);
  v5 = MmHighestUserAddress;
  if ( v3 < MmHighestUserAddress || v3 + 4 < v3 )
  {
    a1 = VerifierBugCheckIfAppropriate(196, 224, v3, 4, 0);
    v5 = MmHighestUserAddress;
  }
  if ( a2 < v5 || a2 + 12 < a2 )
    a1 = VerifierBugCheckIfAppropriate(196, 224, a2, 12, 0);
  v6 = KeGetCurrentIrql(a1);
  if ( v6 < 2 )
    VerifierBugCheckIfAppropriate(196, 64, v6, a2, 0);
  return pXdvKeAcquireInStackQueuedSpinLockAtDpcLevel(v3, a2);
}
