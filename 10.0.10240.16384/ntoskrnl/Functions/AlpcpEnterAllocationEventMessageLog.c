// AlpcpEnterAllocationEventMessageLog 
 
unsigned int __fastcall AlpcpEnterAllocationEventMessageLog(int a1)
{
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  int *v5; // r0
  int **v6; // r1
  int *v7; // r1
  int v8; // r2
  int **v9; // r0
  unsigned int v10; // r1

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
  v5 = (int *)AlpcpAllocateMessageLog();
  if ( v5 )
  {
    v5[4] = a1;
    v5[5] = *(_DWORD *)(a1 + 136);
    v5[6] = 1;
    v6 = (int **)dword_6212BC;
    *v5 = (int)&AlpcpMessageLogListHead;
    v5[1] = (int)v6;
    if ( *v6 != &AlpcpMessageLogListHead )
      __fastfail(3u);
    *v6 = v5;
    dword_6212BC = (int)v5;
    v7 = v5 + 2;
    v8 = AlpcpMessageLogLookupTable + 8 * (((unsigned int)v5[5] >> 2) & 0x3FF);
    v9 = *(int ***)(v8 + 4);
    *v7 = v8;
    v7[1] = (int)v9;
    if ( *v9 != (int *)v8 )
      __fastfail(3u);
    *v9 = v7;
    *(_DWORD *)(v8 + 4) = v7;
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&AlpcpMessageLogLock);
  while ( __strex(v10 - 1, (unsigned int *)&AlpcpMessageLogLock) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&AlpcpMessageLogLock);
  return KeAbPostRelease((unsigned int)&AlpcpMessageLogLock);
}
