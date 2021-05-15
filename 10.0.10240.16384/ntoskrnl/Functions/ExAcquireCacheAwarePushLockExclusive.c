// ExAcquireCacheAwarePushLockExclusive 
 
int __fastcall ExAcquireCacheAwarePushLockExclusive(unsigned int a1)
{
  int v2; // r5
  int result; // r0

  v2 = KeAbPreAcquire(a1, 0, 0);
  result = ExfAcquireCacheAwarePushLockExclusiveEx(a1, v2, a1);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  return result;
}
