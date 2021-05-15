// ExDisableHandleTracing 
 
int __fastcall ExDisableHandleTracing(int a1)
{
  unsigned int v2; // r7
  unsigned __int8 *v3; // r6
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int v7; // r4
  unsigned int v8; // r1
  int result; // r0
  __int16 v10; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(a1 + 36);
  v4 = KeAbPreAcquire(a1 + 36, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( __strex(v6 | 1, v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = *(_DWORD *)(a1 + 60);
  *(_DWORD *)(a1 + 60) = 0;
  if ( v7 && (*(_DWORD *)(v7 + 8) & 8) == 0 )
    *(_BYTE *)(a1 + 28) &= 0xFDu;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v3);
  while ( __strex(v8 - 1, (unsigned int *)v3) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  result = KeAbPostRelease((unsigned int)v3);
  v10 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v7 )
    result = ExDereferenceHandleDebugInfo(a1, v7);
  return result;
}
