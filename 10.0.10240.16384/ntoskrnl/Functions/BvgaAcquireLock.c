// BvgaAcquireLock 
 
unsigned int __fastcall BvgaAcquireLock(int a1)
{
  unsigned int result; // r0
  char v2; // r5
  unsigned int v3; // r2

  result = KeGetCurrentIrql(a1);
  v2 = result;
  if ( result <= 2 )
  {
    while ( BootDriverLock )
    {
      __dmb(0xAu);
      __yield();
    }
    result = KfRaiseIrql(2);
    v2 = result;
  }
  if ( (dword_682604 & 0x210000) != 0 )
  {
    result = KiAcquireSpinLockInstrumented((int)&BootDriverLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&BootDriverLock);
    while ( __strex(1u, (unsigned int *)&BootDriverLock) );
    __dmb(0xBu);
    if ( v3 )
      result = KxWaitForSpinLockAndAcquire((unsigned int *)&BootDriverLock);
  }
  BvgaOldIrql = v2;
  return result;
}
