// ObpFreeWorkItemBlock 
 
int __fastcall ObpFreeWorkItemBlock(_DWORD *a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r1
  int result; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 310);
  v3 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v3, (unsigned int)&ObpStackTraceLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( (ObpTraceFlags & 0x73) != 0 && (unsigned __int16)word_61FE3C < 0x1F4u )
    RtlpInterlockedPushEntrySList((unsigned __int64 *)&ObpWorkItemFreeList, a1);
  else
    ExFreePoolWithTag((unsigned int)a1);
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&ObpStackTraceLock);
  while ( __strex(v6 - 1, (unsigned int *)&ObpStackTraceLock) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
  result = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x136) + 1;
  *(_WORD *)(v8 + 310) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
