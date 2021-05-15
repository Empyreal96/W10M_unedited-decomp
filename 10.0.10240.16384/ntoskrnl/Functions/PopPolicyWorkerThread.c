// PopPolicyWorkerThread 
 
int __fastcall PopPolicyWorkerThread(int a1)
{
  int v2; // r5
  unsigned int v4; // r2
  int v5; // r2
  int v6; // r1
  int v7; // r7
  int i; // r3
  int v9; // r0
  int (__fastcall *v10)(int); // r3
  unsigned int v11; // r2
  unsigned int v12; // [sp+4h] [bp-24h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_529314();
  do
    v4 = __ldrex((unsigned int *)&PopWorkerSpinLock);
  while ( __strex(1u, (unsigned int *)&PopWorkerSpinLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire(&PopWorkerSpinLock);
  v5 = PopWorkerPending;
  v6 = PopWorkerStatus | a1;
  v7 = 0;
  PopWorkerStatus = v6;
  for ( i = PopWorkerPending & v6; (PopWorkerPending & v6) != 0; i = PopWorkerPending & v6 )
  {
    v12 = __clz(__rbit(i));
    PopWorkerPending = v5 & ~(1 << v12);
    PopWorkerStatus = v6 & ~(1 << v12);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PopWorkerSpinLock);
    }
    else
    {
      __dmb(0xBu);
      PopWorkerSpinLock = 0;
    }
    v9 = KfLowerIrql(v2);
    v10 = (int (__fastcall *)(int))*(&PopWorkerTypes + v12);
    if ( v10 )
      v7 |= v10(v9);
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(&PopWorkerSpinLock);
    }
    else
    {
      do
        v11 = __ldrex((unsigned int *)&PopWorkerSpinLock);
      while ( __strex(1u, (unsigned int *)&PopWorkerSpinLock) );
      __dmb(0xBu);
      if ( v11 )
        KxWaitForSpinLockAndAcquire(&PopWorkerSpinLock);
    }
    v6 = PopWorkerStatus | (1 << v12);
    v5 = PopWorkerPending;
    PopWorkerStatus = v6;
  }
  PopWorkerPending = v5 | v7;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopWorkerSpinLock);
  }
  else
  {
    __dmb(0xBu);
    PopWorkerSpinLock = 0;
  }
  return KfLowerIrql(v2);
}
