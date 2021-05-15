// ExReleaseCacheAwarePushLockExclusiveEx 
 
unsigned int *__fastcall ExReleaseCacheAwarePushLockExclusiveEx(unsigned int *result, int a2)
{
  char v2; // r5
  unsigned int v3; // r4
  unsigned int *v4; // r6
  unsigned int *v5; // r7
  unsigned int *v6; // t1
  unsigned int v7; // r1

  v2 = a2;
  v3 = (unsigned int)result;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    KeBugCheck2(338, a2, (unsigned int)result, 0, 0, 0);
  v4 = result + 32;
  v5 = result;
  while ( v5 < v4 )
  {
    v6 = (unsigned int *)*v5++;
    result = v6;
    __dmb(0xBu);
    do
      v7 = __ldrex(result);
    while ( __strex(v7 - 1, result) );
    if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
      result = ExfTryToWakePushLock(result);
  }
  if ( (v2 & 2) == 0 )
    result = (unsigned int *)KeAbPostRelease(v3);
  return result;
}
