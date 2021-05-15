// WdipTimeoutCheckRoutine 
 
int WdipTimeoutCheckRoutine()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  unsigned int *v4; // r6
  int v5; // r4
  unsigned int v6; // r4
  int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2
  __int64 v10; // r0
  __int16 v11; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&WdipSemPushLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned int *)&WdipSemPushLock);
  while ( !v3 && __strex(0x11u, (unsigned int *)&WdipSemPushLock) );
  __dmb(0xBu);
  if ( v3 )
    ExfAcquirePushLockSharedEx(&WdipSemPushLock, v1, (unsigned int)&WdipSemPushLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  WdipSemSqmLogInflightLimitExceededDataPoints();
  if ( WdipSemTimeoutEnabled )
  {
    v4 = WdipSemMarkNextTimedOutInstanceForDeletion((unsigned int *)&WdipSemEnabledInstanceTable);
    while ( v4 )
    {
      WdipSemDisableContextProviders((int)v4, 1);
      v5 = (int)v4;
      v4 = WdipSemMarkNextTimedOutInstanceForDeletion(v4);
      WdipSemLogTimeoutInformation(*(_DWORD *)(v5 + 24), *(unsigned __int16 *)(*(_DWORD *)(v5 + 24) + 16), v5 + 8);
      WdipSemDeleteTransitionalInstance(v5);
    }
  }
  v6 = WdipSemTimeoutValue / 0xAu;
  __pld(&WdipSemPushLock);
  v7 = WdipSemPushLock;
  v8 = WdipSemPushLock - 16;
  if ( (WdipSemPushLock & 0xFFFFFFF0) <= 0x10 )
    v8 = 0;
  if ( (WdipSemPushLock & 2) != 0 )
    goto LABEL_19;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&WdipSemPushLock);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&WdipSemPushLock) );
  if ( v9 != v7 )
LABEL_19:
    ExfReleasePushLock(&WdipSemPushLock, v7);
  KeAbPostRelease((unsigned int)&WdipSemPushLock);
  LODWORD(v10) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 )
  {
    HIDWORD(v10) = v10 + 100;
    if ( *(_DWORD *)(v10 + 100) != (_DWORD)v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(v10);
  }
  LODWORD(v10) = WdipTimeoutTimer;
  return KeSetCoalescableTimer(v10, *(_QWORD *)WdipSemOneSecond * v6, 0, 0x3E8u, (int)&WdipTimeoutDpc);
}
