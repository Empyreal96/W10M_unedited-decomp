// WdipSemInitialize 
 
int WdipSemInitialize()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2
  int result; // r0
  unsigned int v4; // r2
  unsigned int v5; // r1
  __int16 v6; // r3
  int v7; // r1
  unsigned int v8; // r0

  WdipSemInitializeGlobalState();
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&WdipSemPushLock, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&WdipSemPushLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&WdipSemPushLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_7D0D20(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  WdipSemCleanStart();
  __pld(&WdipSemPushLock);
  v7 = WdipSemPushLock;
  if ( (WdipSemPushLock & 0xFFFFFFF0) <= 0x10 )
    v8 = 0;
  else
    v8 = WdipSemPushLock - 16;
  if ( (WdipSemPushLock & 2) != 0 )
    goto LABEL_19;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&WdipSemPushLock);
  while ( v4 == v7 && __strex(v8, (unsigned int *)&WdipSemPushLock) );
  if ( v4 != v7 )
LABEL_19:
    ExfReleasePushLock(&WdipSemPushLock, v7);
  result = KeAbPostRelease((unsigned int)&WdipSemPushLock);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_WORD *)(v5 + 0x134) + 1;
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
