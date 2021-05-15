// AlpcpEnterFreeEventMessageLog 
 
unsigned int __fastcall AlpcpEnterFreeEventMessageLog(int a1)
{
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r1

  v2 = KeAbPreAcquire((unsigned int)&AlpcpMessageLogLock, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&AlpcpMessageLogLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&AlpcpMessageLogLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&AlpcpMessageLogLock, v2, (unsigned int)&AlpcpMessageLogLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = AlpcpLocateMessageLog(*(_DWORD *)(a1 + 136));
  if ( v5 )
  {
    *(_DWORD *)(v5 + 24) = 0;
    *(_DWORD *)(v5 + 16) = 0;
  }
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&AlpcpMessageLogLock);
  while ( __strex(v6 - 1, (unsigned int *)&AlpcpMessageLogLock) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&AlpcpMessageLogLock);
  return KeAbPostRelease((unsigned int)&AlpcpMessageLogLock);
}
