// ViAllocateFromContiguousMemory 
 
int __fastcall ViAllocateFromContiguousMemory(_DWORD *a1, unsigned int a2)
{
  int v3; // r6
  unsigned int *v5; // r4
  int v6; // r9
  unsigned int v7; // r2
  int v8; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = 0;
  if ( !a1 || !a1[47] )
    return 0;
  v5 = a1 + 50;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v5);
  }
  else
  {
    do
      v7 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire(v5);
  }
  v8 = RtlFindClearBitsAndSet(a1 + 52, 1u, a2);
  if ( v8 != -1 )
    v3 = *(_DWORD *)(a1[47] + 4 * v8);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v5, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  KfLowerIrql(v6);
  return v3;
}
