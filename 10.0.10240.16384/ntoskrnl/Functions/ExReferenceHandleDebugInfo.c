// ExReferenceHandleDebugInfo 
 
unsigned int *__fastcall ExReferenceHandleDebugInfo(int a1)
{
  unsigned int v2; // r5
  unsigned __int8 *v3; // r6
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  unsigned int *v7; // r4
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r0
  __int16 v11; // r3

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
  v7 = *(unsigned int **)(a1 + 60);
  if ( v7 )
  {
    __dmb(0xBu);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 + 1, v7) );
    __dmb(0xBu);
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)v3);
  while ( __strex(v9 - 1, (unsigned int *)v3) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  v10 = KeAbPostRelease((unsigned int)v3);
  v11 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v7;
}
