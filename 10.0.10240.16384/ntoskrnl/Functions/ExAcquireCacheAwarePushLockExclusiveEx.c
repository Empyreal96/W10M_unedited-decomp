// ExAcquireCacheAwarePushLockExclusiveEx 
 
unsigned __int8 **__fastcall ExAcquireCacheAwarePushLockExclusiveEx(unsigned __int8 **a1, char a2)
{
  int v3; // r4
  unsigned __int8 **result; // r0

  if ( (a2 & 2) != 0 )
    v3 = 0;
  else
    v3 = KeAbPreAcquire((unsigned int)a1, 0, 0);
  result = ExfAcquireCacheAwarePushLockExclusiveEx(a1, v3, (unsigned int)a1);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  return result;
}
