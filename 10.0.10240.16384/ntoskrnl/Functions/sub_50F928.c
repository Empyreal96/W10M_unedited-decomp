// sub_50F928 
 
void sub_50F928()
{
  int v0; // r5
  int v1; // r9
  unsigned int *v2; // r4
  unsigned int v3; // r2

  v2 = (unsigned int *)(KiGlobalSecondaryIDT + 28 * (*(_DWORD *)(v0 + 44) - 4096));
  KfRaiseIrql(12);
  if ( (*(_DWORD *)(v1 + 4) & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v2);
  }
  else
  {
    do
      v3 = __ldrex(v2);
    while ( __strex(1u, v2) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire(v2);
  }
  JUMPOUT(0x425CA6);
}
