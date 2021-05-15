// PpmReapplyPerfPolicy 
 
void __fastcall PpmReapplyPerfPolicy(int *a1)
{
  int *i; // r0
  int v3; // r2
  int v4; // r4
  int v5; // r6
  int v6; // r3
  int v7; // r0
  int v8; // r0

  i = (int *)PpmUpdateProcessorPolicy();
  if ( (*a1 & 0x20) != 0 )
  {
    v6 = *a1 | 0xE;
    v7 = ExPageLockHandle;
    *a1 = v6;
    v8 = MiLockPagableImageSection(v7, 1, v3, v6);
    PopInitializeHeteroProcessors(v8);
    i = (int *)MmUnlockPagableImageSection(ExPageLockHandle);
  }
  if ( (*a1 & 2) != 0 )
  {
    for ( i = (int *)PpmPerfDomainHead; i != &PpmPerfDomainHead; i = *(int **)PpmPerfCalculateMinMaxStates((int)i) )
      ;
  }
  if ( (*a1 & 4) != 0 )
    PpmParkApplyPolicy();
  if ( (*a1 & 0x10) != 0 )
    i = (int *)PpmPerfResizeHistoryAll();
  if ( (*a1 & 8) != 0 )
    i = (int *)PpmCheckReInit(i);
  v4 = 1;
  v5 = 0;
  if ( (*a1 & 2) != 0 )
  {
    v4 = 0;
    v5 = 1;
    PpmPerfUpdateDomains(i);
  }
  if ( (*a1 & 4) != 0 )
  {
    if ( v5 )
      PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
    v4 = 0;
    if ( (*a1 & 0x20) != 0 )
    {
      PpmCheckInitProcessors(1);
      return;
    }
    PpmCheckApplyParkConstraints();
  }
  if ( v4 )
    PpmReleaseLock(&PpmPerfPolicyLock);
}
