// CcChangeBackingFileObject 
 
int __fastcall CcChangeBackingFileObject(int a1, int a2)
{
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r1
  int v10; // r5
  int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r7
  unsigned int v14; // r1
  unsigned int v15; // r1

  v4 = KeAbPreAcquire((unsigned int)&CcChangeSharedCacheMapFileLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)&CcChangeSharedCacheMapFileLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&CcChangeSharedCacheMapFileLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CcChangeSharedCacheMapFileLock, v4, (unsigned int)&CcChangeSharedCacheMapFileLock);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = KeAcquireQueuedSpinLock(5);
  v8 = v7;
  if ( a1 && *(_DWORD *)(a1 + 20) != *(_DWORD *)(a2 + 20) )
  {
    KeReleaseQueuedSpinLock(5, v7);
    __dmb(0xBu);
    do
      v9 = __ldrex(&CcChangeSharedCacheMapFileLock);
    while ( __strex(v9 - 1, &CcChangeSharedCacheMapFileLock) );
    if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
      ExfTryToWakePushLock(&CcChangeSharedCacheMapFileLock);
    v10 = -1073741584;
LABEL_30:
    KeAbPostRelease((unsigned int)&CcChangeSharedCacheMapFileLock);
    return v10;
  }
  v11 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4);
  if ( (*(_DWORD *)(v11 + 96) & 0x100000) != 0 )
  {
    KeReleaseQueuedSpinLock(5, v7);
    __dmb(0xBu);
    do
      v12 = __ldrex(&CcChangeSharedCacheMapFileLock);
    while ( __strex(v12 - 1, &CcChangeSharedCacheMapFileLock) );
    if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
      ExfTryToWakePushLock(&CcChangeSharedCacheMapFileLock);
    v10 = -1073741637;
    goto LABEL_30;
  }
  v13 = *(_DWORD *)(v11 + 68) & 0xFFFFFFF8;
  if ( a1 && v13 != a1 )
  {
    KeReleaseQueuedSpinLock(5, v7);
    __dmb(0xBu);
    do
      v14 = __ldrex(&CcChangeSharedCacheMapFileLock);
    while ( __strex(v14 - 1, &CcChangeSharedCacheMapFileLock) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock(&CcChangeSharedCacheMapFileLock);
    v10 = 0;
    goto LABEL_30;
  }
  ObFastReplaceObject((unsigned int *)(v11 + 68), a2);
  KeReleaseQueuedSpinLock(5, v8);
  __dmb(0xBu);
  do
    v15 = __ldrex(&CcChangeSharedCacheMapFileLock);
  while ( __strex(v15 - 1, &CcChangeSharedCacheMapFileLock) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock(&CcChangeSharedCacheMapFileLock);
  KeAbPostRelease((unsigned int)&CcChangeSharedCacheMapFileLock);
  ObfReferenceObjectWithTag(a2);
  ObDereferenceObjectDeferDeleteWithTag(v13);
  return 0;
}
