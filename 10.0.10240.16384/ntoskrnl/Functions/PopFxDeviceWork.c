// PopFxDeviceWork 
 
int __fastcall PopFxDeviceWork(_DWORD *a1)
{
  unsigned int *v2; // r4
  unsigned int *v3; // r7
  int v4; // r8
  unsigned int v5; // r2
  unsigned int v6; // r2
  unsigned int v7; // r2
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = a1 + 46;
  v3 = a1 + 43;
  do
  {
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v2);
    }
    else
    {
      do
        v5 = __ldrex(v2);
      while ( __strex(1u, v2) );
      __dmb(0xBu);
      if ( v5 )
        KxWaitForSpinLockAndAcquire(v2);
    }
    PopFxDeliverDevicePowerRequired(a1, 0);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v2, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v2 = 0;
    }
    KfLowerIrql(v4);
    __dmb(0xBu);
    do
    {
      v6 = __ldrex(v3);
      v7 = v6 - 1;
    }
    while ( __strex(v7, v3) );
    __dmb(0xBu);
  }
  while ( v7 );
  return PopFxReleaseDevice(a1);
}
