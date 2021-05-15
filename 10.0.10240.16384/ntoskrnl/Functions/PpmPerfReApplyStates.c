// PpmPerfReApplyStates 
 
int PpmPerfReApplyStates()
{
  int v0; // r3
  int *v1; // r1
  int v2; // r4

  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v1 = (int *)PpmPerfDomainHead;
  if ( (int *)PpmPerfDomainHead != &PpmPerfDomainHead )
  {
    v2 = dword_61749C;
    do
    {
      v0 = 1 << *(_DWORD *)(v1[2] + 20);
      v2 |= v0;
      dword_61749C = v2;
      v1 = (int *)*v1;
    }
    while ( v1 != &PpmPerfDomainHead );
  }
  PpmUpdateProcessorPolicy((unsigned __int16 *)&PpmAllowedActions, (int)v1, (int)&PpmPerfDomainHead, v0);
  return PpmCheckApplyPerfConstraints(1);
}
