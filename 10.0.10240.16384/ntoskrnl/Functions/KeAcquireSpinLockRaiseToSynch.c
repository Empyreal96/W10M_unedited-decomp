// KeAcquireSpinLockRaiseToSynch 
 
int __fastcall KeAcquireSpinLockRaiseToSynch(unsigned int *a1)
{
  int v2; // r5
  unsigned int v3; // r2

  v2 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)a1);
  }
  else
  {
    do
      v3 = __ldrex(a1);
    while ( __strex(1u, a1) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire(a1);
  }
  return v2;
}
