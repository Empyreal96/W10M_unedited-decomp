// VerifierPortKeAcquireSpinLockNoXdv 
 
int __fastcall VerifierPortKeAcquireSpinLockNoXdv(unsigned int *a1, _BYTE *a2, unsigned int a3)
{
  int v5; // r3
  int v6; // r4
  int result; // r0
  char v8; // r7
  unsigned int v9; // r2

  v5 = dword_620D88 + 1;
  __dmb(0xBu);
  dword_620D88 = v5;
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetIncrementCounter(a3, 76, a3, MmVerifierData);
  if ( (unsigned int)a1 < MmHighestUserAddress || a1 + 1 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, (int)a1, 4, 0);
  v6 = ViKeRaiseIrqlSanityChecks(2, 0);
  result = KfRaiseIrql(2);
  v8 = result;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    result = KiAcquireSpinLockInstrumented((int)a1);
  }
  else
  {
    do
      v9 = __ldrex(a1);
    while ( __strex(1u, a1) );
    __dmb(0xBu);
    if ( v9 )
      result = KxWaitForSpinLockAndAcquire(a1);
  }
  *a2 = v8;
  if ( v6 )
  {
    result = KeGetCurrentProcessorNumberEx(0);
    *(_WORD *)(v6 + 6) = result;
  }
  return result;
}
