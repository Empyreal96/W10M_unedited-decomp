// ObpStopRuntimeStackTrace 
 
int ObpStopRuntimeStackTrace()
{
  unsigned int v0; // r7
  unsigned int v1; // r2
  int v2; // r0
  int v3; // r4
  unsigned int v4; // r2
  int v5; // r4
  unsigned int v6; // r1
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r3
  unsigned int v10; // r1
  int *v11; // r2
  void *v12; // r2
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r3
  unsigned int v17; // r8
  unsigned int v18; // r9
  int v19; // r0
  _DWORD *v20; // r10
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r4
  __int16 v24; // r3

  v0 = 0;
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 310);
  v2 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v2, (unsigned int)&ObpStackTraceLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = ObpTraceFlags;
  if ( (ObpTraceFlags & 2) != 0 )
  {
    if ( (ObpTraceFlags & 0x10) != 0 )
      memset(ObpRuntimeTracePoolTags, 0, sizeof(ObpRuntimeTracePoolTags));
    if ( (ObpTraceFlags & 0x20) != 0 )
    {
      v0 = dword_61FDE4;
      RtlInitUnicodeStringEx((int)&ObpRuntimeTraceProcessName, 0);
      v5 = ObpTraceFlags;
    }
    ObpRuntimeTraceFlags = 0;
    v10 = v5 & 0xFFFFFF8C | ObpRegTraceFlags;
    ObpTraceFlags = v10;
    if ( (v10 & 1) != 0 )
    {
      if ( (v10 & 0x10) != 0 )
        v11 = &ObpRegTracePoolTags;
      else
        v11 = 0;
      ObpTracePoolTags = (int)v11;
      if ( (v10 & 0x20) != 0 )
        v12 = &ObpRegTraceProcessName;
      else
        v12 = 0;
      ObpTraceProcessName = (int)v12;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&ObpStackTraceLock);
      while ( __strex(v13 - 1, (unsigned int *)&ObpStackTraceLock) );
      if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
      v14 = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = (__int16)(*(_WORD *)(v15 + 0x136) + 1);
      *(_WORD *)(v15 + 310) = v16;
      if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 )
        KiCheckForKernelApcDelivery(v14);
    }
    else
    {
      ObpTraceFlags = v10 & 0xFFFFFF8C;
      ObpTracePoolTags = 0;
      ObpTraceProcessName = 0;
      v17 = ObpStackTable;
      v18 = ObpObjectTable;
      ObpStackSequence = 0;
      ObpNumTracedObjects = 0;
      v19 = RtlpInterlockedFlushSList((unsigned __int64 *)&ObpWorkItemFreeList);
      ObpStackTable = 0;
      ObpObjectTable = 0;
      v20 = (_DWORD *)v19;
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)&ObpStackTraceLock);
      while ( __strex(v21 - 1, (unsigned int *)&ObpStackTraceLock) );
      if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
      v22 = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
      v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v24 = *(_WORD *)(v23 + 0x136) + 1;
      *(_WORD *)(v23 + 310) = v24;
      if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 )
        KiCheckForKernelApcDelivery(v22);
      ObpDestroyStackAndObjectTables(v17, v18, v20);
    }
    if ( v0 )
      ExFreePoolWithTag(v0);
  }
  else
  {
    __dmb(0xBu);
    do
      v6 = __ldrex((unsigned int *)&ObpStackTraceLock);
    while ( __strex(v6 - 1, (unsigned int *)&ObpStackTraceLock) );
    if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
    v7 = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = (__int16)(*(_WORD *)(v8 + 0x136) + 1);
    *(_WORD *)(v8 + 310) = v9;
    if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 )
      KiCheckForKernelApcDelivery(v7);
  }
  return 0;
}
