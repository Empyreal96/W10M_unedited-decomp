// PsFreezeProcess 
 
int __fastcall PsFreezeProcess(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  unsigned int v8; // r6
  unsigned __int8 *v9; // r7
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  __int64 v13; // kr00_8
  unsigned int v14; // lr
  unsigned int v15; // r1
  int v16; // r0
  __int16 v17; // r3
  int v18[8]; // [sp+0h] [bp-20h] BYREF

  v18[0] = a4;
  if ( (*(_DWORD *)(a1 + 192) & 8) != 0 )
    JUMPOUT(0x7E693E);
  v6 = KeFreezeProcess(a1, a2);
  if ( (*(_DWORD *)(a1 + 192) & 8) != 0 )
    return sub_7E6938(v6);
  if ( a2 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = (unsigned __int8 *)(a1 + 168);
    v10 = KeAbPreAcquire(a1 + 168, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v9);
    while ( __strex(v12 | 1, v9) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 168), v10, a1 + 168);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    do
    {
      v13 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v14 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v18[0] = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v14 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v13 != MEMORY[0xFFFF93B0] );
    *(_QWORD *)(a1 + 768) = __PAIR64__(v14, v18[0]) - v13;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)v9);
    while ( __strex(v15 - 1, (unsigned int *)v9) );
    if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a1 + 168));
    v16 = KeAbPostRelease(a1 + 168);
    v17 = *(_WORD *)(v8 + 308) + 1;
    *(_WORD *)(v8 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(v16);
    if ( *(_DWORD *)(a1 + 284) )
    {
      v18[0] = PsGetProcessSessionIdEx(a1);
      PsInvokeWin32Callout(22, a1, 1, v18);
    }
    if ( (dword_682608 & 2) != 0 )
      EtwTraceFreezeThawProcess(a1, 1);
    PsSetProcessTelemetryAppState(a1, 1);
  }
  return 1;
}
