// CcBoostLowPriorityWorkerThread 
 
unsigned int __fastcall CcBoostLowPriorityWorkerThread(int a1)
{
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  _DWORD *v5; // r1
  int v6; // r2
  unsigned int v7; // r1

  if ( a1 && !*(_DWORD *)(a1 + 4) )
    sub_528B24();
  v2 = KeAbPreAcquire((unsigned int)&CcLowPriorityWorkerThreadLock, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&CcLowPriorityWorkerThreadLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&CcLowPriorityWorkerThreadLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CcLowPriorityWorkerThreadLock, v2, (unsigned int)&CcLowPriorityWorkerThreadLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  if ( CcLowPriWorkerThread )
  {
    v5 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v6 = (v5[240] >> 9) & 7;
    if ( (*(_DWORD *)(v5[84] + 192) & 0x100000) != 0 )
      v6 = 0;
    if ( v6 < 2 && v5 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v5[250] )
      v6 = 2;
    if ( v6 > 0 && (!a1 || a1 == CcLowPriSharedCacheMap) )
    {
      IoBoostThreadIoPriority(CcLowPriWorkerThread, 2, 0);
      CcLowPriOldCpuPriority = KeSetPriorityThread(CcLowPriWorkerThread, 13);
      if ( !*(_DWORD *)(CcLowPriSharedCacheMap + 4) )
        KeBugCheckEx(52, 1321, -1073740768);
      if ( (*(_DWORD *)(CcLowPriSharedCacheMap + 96) & 0x20000000) == 0 )
      {
        PsBoostThreadIoEx(CcLowPriWorkerThread, 0, 0);
        CcUpdateSharedCacheMapFlag(CcLowPriSharedCacheMap, 0x20000000, 1);
      }
    }
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&CcLowPriorityWorkerThreadLock);
  while ( __strex(v7 - 1, (unsigned int *)&CcLowPriorityWorkerThreadLock) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&CcLowPriorityWorkerThreadLock);
  return KeAbPostRelease((unsigned int)&CcLowPriorityWorkerThreadLock);
}
