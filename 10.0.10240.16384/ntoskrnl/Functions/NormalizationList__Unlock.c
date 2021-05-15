// NormalizationList__Unlock 
 
int NormalizationList__Unlock()
{
  unsigned int v0; // r1
  int result; // r0
  unsigned int v2; // r1
  __int16 v3; // r3

  __dmb(0xBu);
  do
    v0 = __ldrex((unsigned int *)NormalizationListLock);
  while ( __strex(v0 - 1, (unsigned int *)NormalizationListLock) );
  if ( (v0 & 2) != 0 && (v0 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)NormalizationListLock);
  result = KeAbPostRelease((unsigned int)NormalizationListLock);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_WORD *)(v2 + 0x134) + 1;
  *(_WORD *)(v2 + 308) = v3;
  if ( !v3 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
