// PopReleaseAwaymodeLock 
 
int PopReleaseAwaymodeLock()
{
  unsigned int v0; // r2
  int v1; // r1
  unsigned int v2; // r0
  unsigned int v3; // r2
  int result; // r0
  unsigned int v5; // r1
  __int16 v6; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( PopAwaymodeLockExclusiveThread == v0 )
    PopAwaymodeLockExclusiveThread = 0;
  __pld(&PopAwaymodeLock);
  v1 = PopAwaymodeLock;
  v2 = PopAwaymodeLock - 16;
  if ( (PopAwaymodeLock & 0xFFFFFFF0) <= 0x10 )
    v2 = 0;
  if ( (PopAwaymodeLock & 2) != 0 )
    goto LABEL_10;
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&PopAwaymodeLock);
  while ( v3 == v1 && __strex(v2, (unsigned int *)&PopAwaymodeLock) );
  if ( v3 != v1 )
LABEL_10:
    ExfReleasePushLock(&PopAwaymodeLock, v1);
  result = KeAbPostRelease((unsigned int)&PopAwaymodeLock);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_WORD *)(v5 + 0x134) + 1;
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
