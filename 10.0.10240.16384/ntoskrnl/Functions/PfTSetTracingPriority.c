// PfTSetTracingPriority 
 
int __fastcall PfTSetTracingPriority(int a1)
{
  unsigned int v2; // r2
  int v3; // r5
  unsigned int v4; // r1
  unsigned int v5; // r0
  int result; // r0
  unsigned int v7; // r1
  __int16 v8; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)algn_64390C, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)algn_64390C);
  while ( __strex(v4 | 1, (unsigned __int8 *)algn_64390C) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(algn_64390C, v3, (unsigned int)algn_64390C);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  MmSetAccessLogging(dword_643908 == 0, a1);
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)algn_64390C);
  while ( __strex(v5 - 1, (unsigned int *)algn_64390C) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)algn_64390C);
  result = KeAbPostRelease((unsigned int)algn_64390C);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
