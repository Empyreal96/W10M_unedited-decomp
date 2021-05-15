// AlpcUnregisterLogRoutine 
 
// local variable allocation has failed, the output may be wrong!
int AlpcUnregisterLogRoutine()
{
  int v0; // r6
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  void **v4; // r1
  int *(__fastcall **v5)(int *, int); // r0
  char v6; // r2
  _DWORD *v7; // r1 OVERLAPPED
  void **v8; // r2 OVERLAPPED
  unsigned int v9; // r1

  v0 = -1073741275;
  v1 = KeAbPreAcquire((unsigned int)&AlpcpLogLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&AlpcpLogLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&AlpcpLogLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&AlpcpLogLock, v1, (unsigned int)&AlpcpLogLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v4 = (void **)AlpcpLogCallbackListHead;
  v5 = (int *(__fastcall **)(int *, int))AlpcpLogCallbackListHead;
  if ( AlpcpLogCallbackListHead == &AlpcpLogCallbackListHead )
    goto LABEL_16;
  while ( v5[2] != EtwpTraceALPC )
  {
    v5 = (int *(__fastcall **)(int *, int))*v5;
    if ( v5 == (int *(__fastcall **)(int *, int))&AlpcpLogCallbackListHead )
      goto LABEL_10;
  }
  *(_QWORD *)&v7 = *(_QWORD *)v5;
  if ( *((int *(__fastcall ***)(int *, int))*v5 + 1) != v5 || *v8 != v5 )
    __fastfail(3u);
  *v8 = v7;
  v7[1] = v8;
  ExFreePoolWithTag((unsigned int)v5);
  v4 = (void **)AlpcpLogCallbackListHead;
  v0 = 0;
LABEL_10:
  if ( v4 == &AlpcpLogCallbackListHead )
LABEL_16:
    v6 = 0;
  else
    v6 = 1;
  AlpcpLogEnabled = v6;
  __dmb(0xBu);
  do
    v9 = __ldrex(&AlpcpLogLock);
  while ( __strex(v9 - 1, &AlpcpLogLock) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock(&AlpcpLogLock);
  KeAbPostRelease((unsigned int)&AlpcpLogLock);
  return v0;
}
