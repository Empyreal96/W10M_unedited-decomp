// PpmPerfLatencySensitivityHintWorker 
 
int PpmPerfLatencySensitivityHintWorker()
{
  int *v0; // r1
  int v1; // r0

  PpmPerfLatencyBoostQueued = 0;
  PpmAcquireLock(&PpmPerfPolicyLock);
  v0 = (int *)PpmPerfDomainHead;
  if ( (int *)PpmPerfDomainHead != &PpmPerfDomainHead )
  {
    v1 = dword_61749C;
    do
    {
      v1 |= 1 << *(_DWORD *)(v0[2] + 20);
      dword_61749C = v1;
      v0 = (int *)*v0;
    }
    while ( v0 != &PpmPerfDomainHead );
  }
  return PpmCheckCustomRun(3);
}
