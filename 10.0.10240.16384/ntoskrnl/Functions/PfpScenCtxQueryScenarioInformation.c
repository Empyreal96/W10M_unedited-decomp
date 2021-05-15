// PfpScenCtxQueryScenarioInformation 
 
int __fastcall PfpScenCtxQueryScenarioInformation(unsigned int a1, _DWORD *a2)
{
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r2
  unsigned int v8; // r1
  int result; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire(a1, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v7 | 1, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)a1, v5, a1);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  a2[1] = *(_DWORD *)(a1 + 28);
  a2[3] = *(_DWORD *)(a1 + 32);
  if ( *(_DWORD *)(a1 + 28) == 3 )
    a2[5] = *(_DWORD *)(a1 + 36);
  KeResetEvent(*(_DWORD *)(a1 + 40));
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)a1);
  while ( __strex(v8 - 1, (unsigned int *)a1) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a1);
  result = KeAbPostRelease(a1);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
