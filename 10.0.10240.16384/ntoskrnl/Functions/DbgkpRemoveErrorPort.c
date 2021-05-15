// DbgkpRemoveErrorPort 
 
int __fastcall DbgkpRemoveErrorPort(int result, char *a2)
{
  int v3; // r5
  unsigned __int8 *v4; // r3
  unsigned int v5; // r4
  int v6; // r8
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r2
  unsigned int v10; // r0
  __int16 v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r2

  v3 = result;
  __dmb(0xBu);
  v4 = (unsigned __int8 *)(a2 + 4);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 1, v4) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
  {
    v6 = 0;
    --*(_WORD *)(result + 308);
    v7 = KeAbPreAcquire((unsigned int)&DbgkpErrorPortLock, 0, 0);
    do
      v8 = __ldrex((unsigned __int8 *)&DbgkpErrorPortLock);
    while ( __strex(v8 | 1, (unsigned __int8 *)&DbgkpErrorPortLock) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
    {
      result = sub_7EA7B0(v7);
    }
    else
    {
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      if ( DbgkpErrorPort == a2 )
      {
        DbgkpErrorProcess = 0;
        DbgkpErrorPort = 0;
        v6 = 1;
        __dmb(0xBu);
        do
          v9 = __ldrex((unsigned __int8 *)0xFFFF92F0);
        while ( __strex(v9 & 0xFE, (unsigned __int8 *)0xFFFF92F0) );
        __dmb(0xBu);
      }
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&DbgkpErrorPortLock);
      while ( __strex(v10 - 1, (unsigned int *)&DbgkpErrorPortLock) );
      if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&DbgkpErrorPortLock);
      result = KeAbPostRelease((unsigned int)&DbgkpErrorPortLock);
      v11 = *(_WORD *)(v3 + 308) + 1;
      *(_WORD *)(v3 + 308) = v11;
      if ( !v11 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
        result = KiCheckForKernelApcDelivery(result);
      if ( v6 )
      {
        __dmb(0xBu);
        do
        {
          v12 = __ldrex((unsigned int *)a2);
          v13 = v12 - 1;
        }
        while ( __strex(v13, (unsigned int *)a2) );
        __dmb(0xBu);
        if ( !v13 )
          DbgkpDeleteErrorPort((unsigned int)a2);
        result = KeResetEvent(DbgkErrorPortRegisteredEvent);
      }
    }
  }
  return result;
}
