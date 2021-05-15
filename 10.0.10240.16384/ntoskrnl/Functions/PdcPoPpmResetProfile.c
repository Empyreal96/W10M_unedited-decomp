// PdcPoPpmResetProfile 
 
int __fastcall PdcPoPpmResetProfile(int result, int a2)
{
  int v3; // r4

  v3 = result;
  if ( (PpmProfileStatus & 2) == 0 )
  {
    PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
    if ( a2 )
      PpmEnableProfile(v3);
    else
      PpmDisableProfile(v3);
    result = PpmReleaseLock(&PpmPerfPolicyLock);
  }
  return result;
}
