// PopCheckForWork 
 
void PopCheckForWork()
{
  unsigned int v0; // r2
  int v1; // r7
  unsigned int v2; // r2

  if ( (PopWorkerStatus & PopWorkerPending) != 0 )
  {
    v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( PopPolicyLockThread != v0 )
    {
      v1 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        sub_529D14();
      }
      else
      {
        do
          v2 = __ldrex((unsigned int *)&PopWorkerSpinLock);
        while ( __strex(1u, (unsigned int *)&PopWorkerSpinLock) );
        __dmb(0xBu);
        if ( v2 )
          KxWaitForSpinLockAndAcquire(&PopWorkerSpinLock);
        if ( PopWorkerStatus < 0 )
        {
          PopWorkerStatus &= 0x7FFFFFFFu;
          ExQueueWorkItem(&PopPolicyWorker, 1);
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(&PopWorkerSpinLock);
        }
        else
        {
          __dmb(0xBu);
          PopWorkerSpinLock = 0;
        }
        KfLowerIrql(v1);
      }
    }
  }
}
