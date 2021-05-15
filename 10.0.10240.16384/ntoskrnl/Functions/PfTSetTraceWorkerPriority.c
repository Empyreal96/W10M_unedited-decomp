// PfTSetTraceWorkerPriority 
 
int __fastcall PfTSetTraceWorkerPriority(unsigned int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r5
  unsigned int v7; // r1
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  if ( a1 > 0x1F )
    return 32;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PfTGlobals, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&PfTGlobals);
  while ( __strex(v5 | 1, (unsigned __int8 *)&PfTGlobals) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PfTGlobals, v3, (unsigned int)&PfTGlobals);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( dword_643940 )
    v6 = KeSetPriorityThread(dword_643940, a1);
  else
    v6 = 33;
  __dmb(0xBu);
  do
    v7 = __ldrex(&PfTGlobals);
  while ( __strex(v7 - 1, &PfTGlobals) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock(&PfTGlobals);
  v8 = KeAbPostRelease((unsigned int)&PfTGlobals);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v6;
}
