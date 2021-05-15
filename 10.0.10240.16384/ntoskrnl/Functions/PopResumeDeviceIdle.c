// PopResumeDeviceIdle 
 
__int64 PopResumeDeviceIdle()
{
  int v0; // r5
  unsigned int v1; // r2
  int vars4; // [sp+14h] [bp+4h]

  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PopDopeGlobalLock);
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&PopDopeGlobalLock);
    while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
    __dmb(0xBu);
    if ( v1 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
  }
  byte_64B140 = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopDopeGlobalLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PopDopeGlobalLock = 0;
  }
  return KfLowerIrql(v0);
}
