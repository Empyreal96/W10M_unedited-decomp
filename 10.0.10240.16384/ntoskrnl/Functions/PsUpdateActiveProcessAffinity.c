// PsUpdateActiveProcessAffinity 
 
int PsUpdateActiveProcessAffinity()
{
  unsigned int v0; // r4
  int v1; // r0
  int v2; // r5
  unsigned int v3; // r2
  int i; // r0
  int *v5; // r0
  int *v6; // r5
  unsigned int v7; // r1
  int result; // r0
  __int16 v9; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PspAffinityUpdateLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&PspAffinityUpdateLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&PspAffinityUpdateLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PspAffinityUpdateLock, v1, (unsigned int)&PspAffinityUpdateLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  if ( (dword_6182F0 & dword_681D78[0]) != dword_681D78[0] )
  {
    PspLastUpdateAffinityMask = *(_DWORD *)&KeActiveProcessors;
    unk_6182EC = dword_681D74;
    dword_6182F0 = dword_681D78[0];
    for ( i = 0; ; i = (int)v6 )
    {
      v5 = PsGetNextProcess(i);
      v6 = v5;
      if ( !v5 )
        break;
      PspUpdateSingleProcessAffinity(v0, v5, &KeActiveProcessors);
    }
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PspAffinityUpdateLock);
  while ( __strex(v7 - 1, (unsigned int *)&PspAffinityUpdateLock) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PspAffinityUpdateLock);
  result = KeAbPostRelease((unsigned int)&PspAffinityUpdateLock);
  v9 = *(_WORD *)(v0 + 308) + 1;
  *(_WORD *)(v0 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v0 + 100) != v0 + 100 && !*(_WORD *)(v0 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
