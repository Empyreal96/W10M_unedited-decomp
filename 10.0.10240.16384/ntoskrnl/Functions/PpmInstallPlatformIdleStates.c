// PpmInstallPlatformIdleStates 
 
int PpmInstallPlatformIdleStates()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
    JUMPOUT(0x811FAC);
  return sub_811FA0(v1);
}
