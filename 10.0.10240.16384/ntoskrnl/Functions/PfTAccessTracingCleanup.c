// PfTAccessTracingCleanup 
 
int __fastcall PfTAccessTracingCleanup(int a1, int a2, int a3)
{
  int v5; // r7
  unsigned __int8 *v6; // r5
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD *v16; // r4
  int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r1
  int result; // r0
  unsigned int v21; // r1
  __int16 v22; // r3

  v5 = a3 == 4;
  v6 = (unsigned __int8 *)(a1 + 12);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire(a1 + 12, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v6);
  while ( __strex(v10 | 1, v6) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 12), v8, a1 + 12);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *(_DWORD *)(a1 + 8) |= a3;
  v11 = MmGetDefaultPagePriority();
  MmSetAccessLogging(0, v11);
  dword_643B5C = 0;
  do
    v12 = __ldrex((unsigned int *)&dword_643B48);
  while ( !v12 && __strex(1u, (unsigned int *)&dword_643B48) );
  __dmb(0xBu);
  if ( v12 && v12 != 1 )
    ExfWaitForRundownProtectionRelease((unsigned int *)&dword_643B48, v12);
  v16 = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)&unk_643B60);
  while ( v16 )
  {
    v17 = (int)v16;
    v16 = (_DWORD *)*v16;
    MmFreeAccessPfnBuffer(v17, v5);
  }
  MmEnablePeriodicAccessClearing(0, v13, v14, v15);
  dword_643B5C = 0;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&dword_643B48);
  while ( __strex(0, (unsigned int *)&dword_643B48) );
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)v6);
  while ( __strex(v19 - 1, (unsigned int *)v6) );
  if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 12));
  result = KeAbPostRelease(a1 + 12);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
