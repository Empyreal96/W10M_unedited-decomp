// ExReleaseCacheAwarePushLockExclusive 
 
unsigned int __fastcall ExReleaseCacheAwarePushLockExclusive(unsigned int **a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r5
  unsigned int **v3; // r6
  unsigned int *v4; // r0
  unsigned int *v5; // t1
  unsigned int v6; // r1

  v1 = (unsigned int)a1;
  v2 = (unsigned int)(a1 + 32);
  v3 = a1;
  if ( a1 < a1 + 32 )
  {
    do
    {
      v5 = *v3++;
      v4 = v5;
      __dmb(0xBu);
      do
        v6 = __ldrex(v4);
      while ( __strex(v6 - 1, v4) );
      if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
        ExfTryToWakePushLock(v4);
    }
    while ( (unsigned int)v3 < v2 );
  }
  return KeAbPostRelease(v1);
}
