// AlpcpUnregisterCompletionListDatabase 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall AlpcpUnregisterCompletionListDatabase(int a1)
{
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  unsigned int v7; // r1

  v2 = KeAbPreAcquire((unsigned int)&AlpcpCompletionListDatabase, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&AlpcpCompletionListDatabase);
  while ( __strex(v4 | 1, (unsigned __int8 *)&AlpcpCompletionListDatabase) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&AlpcpCompletionListDatabase, v2, (unsigned int)&AlpcpCompletionListDatabase);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  *(_QWORD *)&v5 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v6 != a1 )
    __fastfail(3u);
  *v6 = v5;
  *(_DWORD *)(v5 + 4) = v6;
  --dword_6212A4;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&AlpcpCompletionListDatabase);
  while ( __strex(v7 - 1, (unsigned int *)&AlpcpCompletionListDatabase) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&AlpcpCompletionListDatabase);
  return KeAbPostRelease((unsigned int)&AlpcpCompletionListDatabase);
}
