// AlpcRegisterLogRoutine 
 
// local variable allocation has failed, the output may be wrong!
int AlpcRegisterLogRoutine()
{
  int v0; // r4
  int v1; // r4
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  void **v5; // r1 OVERLAPPED
  int *(__fastcall **i)(int *, int); // r0
  void ***v7; // r2 OVERLAPPED
  unsigned int v8; // r1

  v0 = ExAllocatePoolWithTag(1, 12, 1665952833);
  if ( !v0 )
    return -1073741670;
  *(_DWORD *)(v0 + 8) = EtwpTraceALPC;
  v2 = KeAbPreAcquire((unsigned int)&AlpcpLogLock, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&AlpcpLogLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&AlpcpLogLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&AlpcpLogLock, v2, (unsigned int)&AlpcpLogLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = &AlpcpLogCallbackListHead;
  for ( i = (int *(__fastcall **)(int *, int))AlpcpLogCallbackListHead;
        i != (int *(__fastcall **)(int *, int))&AlpcpLogCallbackListHead;
        i = (int *(__fastcall **)(int *, int))*i )
  {
    if ( i[2] == EtwpTraceALPC )
    {
      ExFreePoolWithTag(v0);
      v1 = -1073740008;
      goto LABEL_17;
    }
  }
  v7 = (void ***)off_6182D8;
  *(_QWORD *)v0 = *(_QWORD *)&v5;
  if ( *v7 != &AlpcpLogCallbackListHead )
    __fastfail(3u);
  *v7 = (void **)v0;
  off_6182D8 = (void **)v0;
  AlpcpLogEnabled = 1;
  v1 = 0;
LABEL_17:
  __dmb(0xBu);
  do
    v8 = __ldrex(&AlpcpLogLock);
  while ( __strex(v8 - 1, &AlpcpLogLock) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock(&AlpcpLogLock);
  KeAbPostRelease((unsigned int)&AlpcpLogLock);
  return v1;
}
