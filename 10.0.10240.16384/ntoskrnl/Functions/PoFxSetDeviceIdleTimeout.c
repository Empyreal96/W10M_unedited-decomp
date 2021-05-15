// PoFxSetDeviceIdleTimeout 
 
int __fastcall PoFxSetDeviceIdleTimeout(unsigned int *a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int *v8; // r4
  int v9; // r8
  unsigned int v10; // r2

  if ( a4 > 0x3FFFFFFF )
    return sub_5263AC();
  v8 = a1 + 46;
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 46);
  }
  else
  {
    do
      v10 = __ldrex(v8);
    while ( __strex(1u, v8) );
    __dmb(0xBu);
    if ( v10 )
      KxWaitForSpinLockAndAcquire(a1 + 46);
  }
  a1[68] = a3;
  a1[69] = a4;
  PopFxUpdateDeviceIdleTimer(a1);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 + 46);
  }
  else
  {
    __dmb(0xBu);
    *v8 = 0;
  }
  return KfLowerIrql(v9);
}
