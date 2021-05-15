// EtwpSendDbgId 
 
unsigned int *__fastcall EtwpSendDbgId(_DWORD *a1)
{
  unsigned int *result; // r0
  unsigned int v3; // r3
  unsigned int v4; // r1
  unsigned __int8 *v5; // r5
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r7
  unsigned int *v11; // r4
  int v12; // r0
  unsigned int v13; // r1

  result = a1 + 153;
  v3 = *result;
  __dmb(0xBu);
  if ( (v3 & 0x800) != 0 )
  {
    __dmb(0xBu);
    do
      v4 = __ldrex(result);
    while ( __strex(v4 & 0xFFFFF7FF, result) );
    __dmb(0xBu);
    if ( (v4 & 0x800) != 0 )
    {
      v5 = (unsigned __int8 *)(a1 + 126);
      v6 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
      v7 = v6;
      do
        v8 = __ldrex(v5);
      while ( __strex(v8 | 1, v5) );
      __dmb(0xBu);
      if ( (v8 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(a1 + 126, v6, (unsigned int)(a1 + 126));
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      v9 = EtwpGetMaxDebugIdBufferSize((int)a1);
      v10 = v9;
      if ( v9 )
      {
        v12 = ExAllocatePoolWithTag(512, v9, 1651995717);
        v11 = (unsigned int *)v12;
        if ( v12 )
        {
          EtwpInitializeProviderInfoBuffer(a1, v12, v10);
          EtwpAddDebugInfoEvents((int)a1, (int)v11, v10, 0, 0);
        }
      }
      else
      {
        v11 = 0;
      }
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)v5);
      while ( __strex(v13 - 1, (unsigned int *)v5) );
      if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
        ExfTryToWakePushLock(a1 + 126);
      result = (unsigned int *)KeAbPostRelease((unsigned int)(a1 + 126));
      if ( v11 )
      {
        EtwpSendBufferToDebugger(v11);
        result = (unsigned int *)ExFreePoolWithTag((unsigned int)v11);
      }
    }
  }
  return result;
}
