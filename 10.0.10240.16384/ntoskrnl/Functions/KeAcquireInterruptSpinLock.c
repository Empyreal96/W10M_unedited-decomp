// KeAcquireInterruptSpinLock 
 
int __fastcall KeAcquireInterruptSpinLock(int a1)
{
  int v2; // r0
  int v3; // r5
  unsigned int *v4; // r0
  unsigned int v5; // r2

  v2 = *(unsigned __int8 *)(a1 + 49);
  if ( !v2 )
    sub_5235CC();
  v3 = KfRaiseIrql(v2);
  v4 = *(unsigned int **)(a1 + 36);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v4);
  }
  else
  {
    do
      v5 = __ldrex(v4);
    while ( __strex(1u, v4) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire(v4);
  }
  return v3;
}
