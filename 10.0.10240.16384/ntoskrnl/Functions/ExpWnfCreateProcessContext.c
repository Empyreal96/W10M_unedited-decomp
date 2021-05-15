// ExpWnfCreateProcessContext 
 
int __fastcall ExpWnfCreateProcessContext(int a1, _DWORD *a2)
{
  _BYTE *v4; // r0
  unsigned int v5; // r5
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  void ***v10; // r0
  unsigned int v11; // r1
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r3

  v4 = (_BYTE *)ExAllocatePoolWithTag(1, 68, 543583831);
  v5 = (unsigned int)v4;
  if ( !v4 )
    return sub_7E8F50();
  memset(v4, 0, 68);
  *(_WORD *)v5 = 2310;
  *(_WORD *)(v5 + 2) = 68;
  *(_DWORD *)(v5 + 28) = 0;
  *(_DWORD *)(v5 + 40) = 0;
  *(_DWORD *)(v5 + 52) = 0;
  *(_DWORD *)(v5 + 32) = v5 + 32;
  *(_DWORD *)(v5 + 36) = v5 + 32;
  *(_DWORD *)(v5 + 44) = v5 + 44;
  *(_DWORD *)(v5 + 48) = v5 + 44;
  *(_DWORD *)(v5 + 56) = v5 + 56;
  *(_DWORD *)(v5 + 60) = v5 + 56;
  *(_DWORD *)(v5 + 64) = 0;
  *(_DWORD *)(v5 + 4) = a1;
  v7 = KeAbPreAcquire((unsigned int)&ExpWnfProcessesListLock, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned __int8 *)&ExpWnfProcessesListLock);
  while ( __strex(v9 | 1, (unsigned __int8 *)&ExpWnfProcessesListLock) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpWnfProcessesListLock, v7, (unsigned int)&ExpWnfProcessesListLock);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = (void ***)off_9203E0;
  *(_DWORD *)(v5 + 8) = &ExpWnfProcessesListHead;
  *(_DWORD *)(v5 + 12) = v10;
  if ( *v10 != &ExpWnfProcessesListHead )
    __fastfail(3u);
  *v10 = (void **)(v5 + 8);
  off_9203E0 = (void **)(v5 + 8);
  __dmb(0xBu);
  do
    v11 = __ldrex(&ExpWnfProcessesListLock);
  while ( __strex(v11 - 1, &ExpWnfProcessesListLock) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock(&ExpWnfProcessesListLock);
  KeAbPostRelease((unsigned int)&ExpWnfProcessesListLock);
  __dmb(0xBu);
  v12 = (unsigned int *)(a1 + 724);
  do
    v13 = __ldrex(v12);
  while ( !v13 && __strex(v5, v12) );
  __dmb(0xBu);
  if ( v13 )
    ExpWnfDeleteProcessContext(v5, 1);
  v14 = *(_DWORD *)(a1 + 724);
  __dmb(0xBu);
  *a2 = v14;
  return 0;
}
