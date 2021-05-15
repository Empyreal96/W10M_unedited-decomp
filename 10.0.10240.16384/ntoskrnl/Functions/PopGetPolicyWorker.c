// PopGetPolicyWorker 
 
int __fastcall PopGetPolicyWorker(int a1)
{
  int v2; // r5
  unsigned int v4; // r2

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_529D34();
  do
    v4 = __ldrex((unsigned int *)&PopWorkerSpinLock);
  while ( __strex(1u, (unsigned int *)&PopWorkerSpinLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire(&PopWorkerSpinLock);
  PopWorkerPending |= a1;
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
