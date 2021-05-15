// PopAcquireUmpoPushLock 
 
int __fastcall PopAcquireUmpoPushLock(int a1)
{
  unsigned int v1; // r2
  int result; // r0
  int v3; // r4
  unsigned int v4; // r2

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  if ( a1 )
    return sub_7F3078(&PopUmpoPushLock);
  result = KeAbPreAcquire((unsigned int)&PopUmpoPushLock, 0, 0);
  v3 = result;
  do
    v4 = __ldrex((unsigned int *)&PopUmpoPushLock);
  while ( !v4 && __strex(0x11u, (unsigned int *)&PopUmpoPushLock) );
  __dmb(0xBu);
  if ( v4 )
    result = ExfAcquirePushLockSharedEx(&PopUmpoPushLock, result, (unsigned int)&PopUmpoPushLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  return result;
}
