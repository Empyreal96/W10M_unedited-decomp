// CcApplyLowIoPriorityToThread 
 
int __fastcall CcApplyLowIoPriorityToThread(int result, int a2)
{
  int v3; // r4
  int v4; // r1
  int v5; // r0
  unsigned int v6; // r2
  unsigned int *v7; // r6
  unsigned int v8; // r0
  unsigned int v9; // r7
  unsigned int v10; // r1
  unsigned int v11; // r1
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  unsigned int *v15; // r0
  int v16; // r8
  unsigned int v17; // r5
  unsigned int v18; // r9
  unsigned int v19; // r1
  unsigned int v20; // r1
  int v21; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !*(_DWORD *)(a2 + 4) )
    KeBugCheckEx(52, 1152, -1073740768);
  if ( result )
  {
    result = CcIsWriteBehindThreadpoolAtLowPriority();
    if ( result && !CcLowPriWorkerThread && !*(_DWORD *)(v4 + 364) && (*(_DWORD *)(a2 + 96) & 0x10000) == 0 )
    {
      v5 = KeAbPreAcquire((unsigned int)&CcLowPriorityWorkerThreadLock, 0, 0);
      do
        v6 = __ldrex((unsigned __int8 *)&CcLowPriorityWorkerThreadLock);
      while ( __strex(v6 | 1, (unsigned __int8 *)&CcLowPriorityWorkerThreadLock) );
      __dmb(0xBu);
      if ( (v6 & 1) != 0 )
        return sub_53D25C(v5);
      if ( v5 )
        *(_BYTE *)(v5 + 14) |= 1u;
      v7 = (unsigned int *)(v3 + 960);
      CcLowPriWorkerThread = v3;
      CcLowPriSharedCacheMap = a2;
      v8 = *(_DWORD *)(v3 + 960);
      __dmb(0xBu);
      do
      {
        v9 = v8;
        __dmb(0xBu);
        do
          v10 = __ldrex(v7);
        while ( v10 == v8 && __strex(v8 & 0xFFFFF1FF, v7) );
        v8 = v10;
        __dmb(0xBu);
      }
      while ( v10 != v9 );
      if ( (dword_682604 & 0x2000) != 0 )
        EtwTracePriority(v3, 1332, (v9 >> 9) & 7, 0, 0);
      if ( ((v9 >> 9) & 7) != 0 )
        KeAbProcessBaseIoPriorityChange(v3, (v9 >> 9) & 7, 0);
      CcLowPriOldIoPriority = (v9 >> 9) & 7;
      __dmb(0xBu);
      do
        v11 = __ldrex((unsigned int *)&CcLowPriorityWorkerThreadLock);
      while ( __strex(v11 - 1, (unsigned int *)&CcLowPriorityWorkerThreadLock) );
      if ( (v11 & 2) == 0 || (v11 & 4) != 0 )
        return KeAbPostRelease((unsigned int)&CcLowPriorityWorkerThreadLock);
LABEL_54:
      ExfTryToWakePushLock(&CcLowPriorityWorkerThreadLock);
      return KeAbPostRelease((unsigned int)&CcLowPriorityWorkerThreadLock);
    }
  }
  else if ( CcLowPriWorkerThread == v3 )
  {
    v12 = KeAbPreAcquire((unsigned int)&CcLowPriorityWorkerThreadLock, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex((unsigned __int8 *)&CcLowPriorityWorkerThreadLock);
    while ( __strex(v14 | 1, (unsigned __int8 *)&CcLowPriorityWorkerThreadLock) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CcLowPriorityWorkerThreadLock, v12, &CcLowPriorityWorkerThreadLock);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v15 = (unsigned int *)(v3 + 960);
    v16 = CcLowPriOldIoPriority;
    v17 = *(_DWORD *)(v3 + 960);
    __dmb(0xBu);
    do
    {
      v18 = v17;
      __dmb(0xBu);
      do
        v19 = __ldrex(v15);
      while ( v19 == v17 && __strex(v17 & 0xFFFFF1FF | (v16 << 9), v15) );
      v17 = v19;
      __dmb(0xBu);
    }
    while ( v19 != v18 );
    if ( (dword_682604 & 0x2000) != 0 )
      EtwTracePriority(v3, 1332, (v18 >> 9) & 7, v16, 0);
    if ( v16 != ((v18 >> 9) & 7) )
      KeAbProcessBaseIoPriorityChange(v3, (v18 >> 9) & 7, v16);
    if ( CcLowPriOldCpuPriority != 32 )
    {
      v21 = __mrc(15, 0, 13, 0, 3);
      KeSetPriorityThread(v21 & 0xFFFFFFC0, CcLowPriOldCpuPriority);
    }
    if ( (*(_DWORD *)(a2 + 96) & 0x20000000) != 0 )
    {
      PsBoostThreadIoEx(v3, 1, 0);
      CcUpdateSharedCacheMapFlag(a2, 0x20000000, 0);
    }
    CcLowPriWorkerThread = 0;
    CcLowPriSharedCacheMap = 0;
    CcLowPriOldIoPriority = 5;
    CcLowPriOldCpuPriority = 32;
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)&CcLowPriorityWorkerThreadLock);
    while ( __strex(v20 - 1, (unsigned int *)&CcLowPriorityWorkerThreadLock) );
    if ( (v20 & 2) == 0 || (v20 & 4) != 0 )
      return KeAbPostRelease((unsigned int)&CcLowPriorityWorkerThreadLock);
    goto LABEL_54;
  }
  return result;
}
