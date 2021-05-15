// ExNotifyPlatformBinaryExecuted 
 
int ExNotifyPlatformBinaryExecuted()
{
  unsigned int v0; // r6
  int v1; // r0
  unsigned int v2; // r1
  int result; // r0
  unsigned int v4; // r5
  unsigned int v5; // r0
  __int16 v6; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&ExpPlatformBinaryLock, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&ExpPlatformBinaryLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&ExpPlatformBinaryLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_81025C(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v4 = ExpPlatformBinaryTableInformation;
  ExpPlatformBinaryTableInformation = -1;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&ExpPlatformBinaryLock);
  while ( __strex(v5 - 1, (unsigned int *)&ExpPlatformBinaryLock) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExpPlatformBinaryLock);
  result = KeAbPostRelease((unsigned int)&ExpPlatformBinaryLock);
  v6 = *(_WORD *)(v0 + 308) + 1;
  *(_WORD *)(v0 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v0 + 100) != v0 + 100 && !*(_WORD *)(v0 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v4 )
    result = ExFreePoolWithTag(v4);
  return result;
}
