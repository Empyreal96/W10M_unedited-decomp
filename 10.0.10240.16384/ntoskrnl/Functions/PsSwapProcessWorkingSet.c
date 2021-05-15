// PsSwapProcessWorkingSet 
 
int __fastcall PsSwapProcessWorkingSet(int a1, int a2)
{
  unsigned int v4; // r6
  int v5; // r5
  unsigned int *v6; // r7
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  int v10; // r4
  unsigned int v11; // lr
  unsigned int *v12; // r8
  unsigned int v13; // r5
  unsigned int v14; // r0
  unsigned int v15; // r1
  unsigned int v16; // r2
  int v17; // r0
  int v18; // r4
  __int16 v19; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = 0;
  --*(_WORD *)(v4 + 308);
  v6 = (unsigned int *)(a1 + 168);
  v7 = KeAbPreAcquire(a1 + 168, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v6);
  while ( !v9 && __strex(0x11u, v6) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(v6, v7, (unsigned int)v6);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  if ( v10 )
  {
    ExAcquireResourceSharedLite(v10 + 32, 1);
    v5 = 0;
    if ( *(_DWORD *)(v10 + 416) )
      v5 = 2;
    if ( *(_DWORD *)(v10 + 408) )
      v5 |= 1u;
  }
  if ( a2 )
    v11 = v5 | 2;
  else
    v11 = v5 & 0xFFFFFFFD;
  v12 = (unsigned int *)(a1 + 188);
  v13 = *(_DWORD *)(a1 + 188);
  __dmb(0xBu);
  do
  {
    v14 = v13;
    __dmb(0xBu);
    do
      v15 = __ldrex(v12);
    while ( v15 == v13 && __strex(v13 & 0xCFFFFFFF | (v11 << 28), v12) );
    v13 = v15;
    __dmb(0xBu);
  }
  while ( v15 != v14 );
  if ( v10 )
    ExReleaseResourceLite(v10 + 32);
  __dmb(0xBu);
  do
    v16 = __ldrex(v6);
  while ( v16 == 17 && __strex(0, v6) );
  if ( v16 != 17 )
    ExfReleasePushLockShared(v6);
  KeAbPostRelease((unsigned int)v6);
  v17 = PspChangeProcessExecutionState(a1);
  v18 = v17;
  v19 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v18;
}
