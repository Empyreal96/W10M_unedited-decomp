// ObEnableEtwReferenceTrace 
 
int ObEnableEtwReferenceTrace()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r1
  int result; // r0
  unsigned int v6; // r1
  __int16 v7; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 310);
  v1 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v1, (unsigned int)&ObpStackTraceLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  ObpTraceFlags |= 4u;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&ObpStackTraceLock);
  while ( __strex(v4 - 1, (unsigned int *)&ObpStackTraceLock) );
  if ( (v4 & 2) != 0 && (v4 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
  result = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x136) + 1;
  *(_WORD *)(v6 + 310) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
