// VerifierKeAcquireQueuedSpinLock 
 
int __fastcall VerifierKeAcquireQueuedSpinLock(int a1)
{
  int v2; // r3
  int v3; // r5
  int v4; // r4
  int vars4; // [sp+Ch] [bp+4h]

  v2 = dword_620D88 + 1;
  __dmb(0xBu);
  dword_620D88 = v2;
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetIncrementCounter(vars4);
  v3 = ViKeRaiseIrqlSanityChecks(2, 0);
  v4 = pXdvKeAcquireQueuedSpinLock(a1);
  if ( v3 )
    *(_WORD *)(v3 + 6) = KeGetCurrentProcessorNumberEx(0);
  return v4;
}
