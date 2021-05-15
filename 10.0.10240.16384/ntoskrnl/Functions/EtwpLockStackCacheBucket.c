// EtwpLockStackCacheBucket 
 
int __fastcall EtwpLockStackCacheBucket(int a1)
{
  int v2; // r5
  unsigned int *v3; // r0
  unsigned int v4; // r2

  v2 = KfRaiseIrql(2);
  v3 = (unsigned int *)(a1 + 8);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v3);
  }
  else
  {
    do
      v4 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire(v3);
  }
  return v2;
}
