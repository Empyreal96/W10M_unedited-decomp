// DbgkFlushErrorPort 
 
int __fastcall DbgkFlushErrorPort(int result)
{
  int v1; // r8
  unsigned int v2; // r6
  unsigned int *v3; // r5
  int v4; // r0
  unsigned int v5; // r2
  unsigned int v6; // r2
  unsigned int v7; // r2
  __int16 v8; // r3
  unsigned int v9; // r2
  unsigned int v10; // r2

  v1 = result;
  if ( result == DbgkpErrorProcess )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v3 = 0;
    --*(_WORD *)(v2 + 308);
    v4 = KeAbPreAcquire((unsigned int)&DbgkpErrorPortLock, 0, 0);
    do
      v5 = __ldrex((unsigned int *)&DbgkpErrorPortLock);
    while ( !v5 && __strex(0x11u, (unsigned int *)&DbgkpErrorPortLock) );
    __dmb(0xBu);
    if ( v5 )
    {
      result = sub_7EA798(v4, 17);
    }
    else
    {
      if ( v4 )
        *(_BYTE *)(v4 + 14) |= 1u;
      if ( v1 == DbgkpErrorProcess )
      {
        v3 = (unsigned int *)DbgkpErrorPort;
        __dmb(0xBu);
        do
          v6 = __ldrex(v3);
        while ( __strex(v6 + 1, v3) );
        __dmb(0xBu);
      }
      __dmb(0xBu);
      do
        v7 = __ldrex((unsigned int *)&DbgkpErrorPortLock);
      while ( v7 == 17 && __strex(0, (unsigned int *)&DbgkpErrorPortLock) );
      if ( v7 != 17 )
        ExfReleasePushLockShared(&DbgkpErrorPortLock);
      result = KeAbPostRelease((unsigned int)&DbgkpErrorPortLock);
      v8 = *(_WORD *)(v2 + 308) + 1;
      *(_WORD *)(v2 + 308) = v8;
      if ( !v8 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
        result = KiCheckForKernelApcDelivery(result);
      if ( v3 )
      {
        result = DbgkpRemoveErrorPort(v2, v3);
        __dmb(0xBu);
        do
        {
          v9 = __ldrex(v3);
          v10 = v9 - 1;
        }
        while ( __strex(v10, v3) );
        __dmb(0xBu);
        if ( !v10 )
          result = DbgkpDeleteErrorPort(v3);
      }
    }
  }
  return result;
}
