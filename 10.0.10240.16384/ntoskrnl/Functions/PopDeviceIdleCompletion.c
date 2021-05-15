// PopDeviceIdleCompletion 
 
__int64 __fastcall PopDeviceIdleCompletion(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  unsigned int v5; // r2
  int vars4; // [sp+14h] [bp+4h]

  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PopDopeGlobalLock);
  }
  else
  {
    do
      v5 = __ldrex((unsigned int *)&PopDopeGlobalLock);
    while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
  }
  if ( !--dword_64B13C && PopDeviceIdleSync )
  {
    KeSetEvent(PopDeviceIdleSync, 0, 0);
    PopDeviceIdleSync = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopDopeGlobalLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PopDopeGlobalLock = 0;
  }
  return KfLowerIrql(v4);
}
