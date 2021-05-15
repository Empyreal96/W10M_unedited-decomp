// KdCallPowerHandlers 
 
int __fastcall KdCallPowerHandlers(int a1)
{
  int v2; // r5
  int v3; // r10
  unsigned int v4; // r2
  int v5; // r6
  int vars4; // [sp+24h] [bp+4h]

  if ( !KdpPowerListHead )
    return 0;
  v3 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&KdpPowerSpinLock);
  }
  else
  {
    do
      v4 = __ldrex((unsigned int *)&KdpPowerSpinLock);
    while ( __strex(1u, (unsigned int *)&KdpPowerSpinLock) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&KdpPowerSpinLock);
  }
  v5 = KdpPowerListHead;
  v2 = 0;
  while ( (int *)v5 != &KdpPowerListHead )
  {
    v2 = (*(int (__fastcall **)(int, _DWORD))(v5 + 8))(a1, *(_DWORD *)(v5 + 12));
    if ( v2 < 0 )
      break;
    v5 = *(_DWORD *)v5;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KdpPowerSpinLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KdpPowerSpinLock = 0;
  }
  KfLowerIrql(v3);
  return v2;
}
