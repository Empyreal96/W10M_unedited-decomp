// PfTAccessTracingStart 
 
int __fastcall PfTAccessTracingStart(int a1, int a2, int a3)
{
  unsigned __int8 *v6; // r5
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r4
  bool v11; // zf
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r1
  int result; // r0
  unsigned int v18; // r1
  __int16 v19; // r3

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
    ExfAcquirePushLockExclusiveEx(v6, v8, (unsigned int)v6);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = (*(_DWORD *)(a1 + 8) & ~a3) == 0;
  *(_DWORD *)(a1 + 8) &= ~a3;
  if ( v11 )
  {
    *(_DWORD *)(a2 + 28) = 256;
    v12 = MmGetDefaultPagePriority();
    MmSetAccessLogging(1, v12);
    MmEnablePeriodicAccessClearing(1, v13, v14, v15);
  }
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)v6);
  while ( __strex(v16 - 1, (unsigned int *)v6) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v6);
  result = KeAbPostRelease((unsigned int)v6);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
