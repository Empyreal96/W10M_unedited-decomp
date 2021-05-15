// KiDisconnectSecondaryInterrupt 
 
int __fastcall KiDisconnectSecondaryInterrupt(int a1, int a2)
{
  int v4; // r6
  unsigned int *v5; // r4
  int v6; // r3
  int v7; // r9
  unsigned int v8; // r2
  unsigned int v9; // r3
  int v10; // r5
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int vars4; // [sp+2Ch] [bp+4h]

  v4 = 0;
  v5 = (unsigned int *)(KiGlobalSecondaryIDT + 28 * (*(_DWORD *)(a1 + 44) - 4096));
  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  KeWaitForSingleObject((unsigned int)(v5 + 1), 0, 0, 0, 0);
  v7 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v5);
  }
  else
  {
    do
      v8 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire(v5);
  }
  if ( *(_BYTE *)(a1 + 51) )
  {
    v9 = v5[6];
    if ( v9 == a1 && *(_DWORD *)(v9 + 4) == v9 + 4 )
      v4 = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v5, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  KfLowerIrql(v7);
  if ( v4 )
    HalDisableInterrupt(a2);
  v10 = KiDisconnectInterruptCommon(1, a1, a2);
  v11 = KeSetEvent((int)(v5 + 1), 0, 0);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  return v10;
}
