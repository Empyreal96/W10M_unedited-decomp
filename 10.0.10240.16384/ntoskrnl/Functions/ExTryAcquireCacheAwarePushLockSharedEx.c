// ExTryAcquireCacheAwarePushLockSharedEx 
 
unsigned int *__fastcall ExTryAcquireCacheAwarePushLockSharedEx(unsigned int a1, int a2)
{
  char v2; // r4
  unsigned int *v4; // r6
  int v5; // r4
  unsigned int v6; // r2
  BOOL v7; // r5

  v2 = a2;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    KeBugCheck2(338, a2, a1, 0, 0, 0);
  v4 = *(unsigned int **)(a1 + 4 * (KeGetCurrentProcessorNumberEx(0) & 0x1F));
  if ( (v2 & 2) != 0 )
    v5 = 0;
  else
    v5 = KeAbPreAcquire(a1, 0, 1);
  do
    v6 = __ldrex(v4);
  while ( !v6 && __strex(0x11u, v4) );
  __dmb(0xBu);
  v7 = !v6 || ExfTryAcquirePushLockShared(v4);
  if ( v5 )
  {
    if ( v7 )
      *(_BYTE *)(v5 + 14) |= 1u;
    else
      KeAbPostReleaseEx(a1, v5);
  }
  if ( !v7 )
    v4 = 0;
  return v4;
}
