// WdipSemUpdate 
 
int WdipSemUpdate()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r5
  unsigned int v3; // r2
  int v4; // r6
  int v5; // r1
  unsigned int v6; // r5
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  if ( !WdipSemInitialized )
    WdipSemInitializeGlobalState();
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&WdipSemPushLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&WdipSemPushLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&WdipSemPushLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&WdipSemPushLock, v1, (unsigned int)&WdipSemPushLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  if ( WdipSemEnabled )
    WdipSemShutdown();
  v4 = WdipSemCleanStart();
  __pld(&WdipSemPushLock);
  v5 = WdipSemPushLock;
  v6 = WdipSemPushLock - 16;
  if ( (WdipSemPushLock & 0xFFFFFFF0) <= 0x10 )
    v6 = 0;
  if ( (WdipSemPushLock & 2) != 0 )
    goto LABEL_18;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&WdipSemPushLock);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&WdipSemPushLock) );
  if ( v7 != v5 )
LABEL_18:
    ExfReleasePushLock(&WdipSemPushLock, v5);
  v8 = KeAbPostRelease((unsigned int)&WdipSemPushLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v4;
}
