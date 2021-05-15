// PsThawProcess 
 
int __fastcall PsThawProcess(int a1, int a2, int a3, int a4)
{
  int v6; // r10
  unsigned int v7; // r6
  unsigned __int8 *v8; // r8
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r2
  __int64 v12; // kr00_8
  unsigned int v13; // lr
  unsigned int v14; // r5
  unsigned __int64 v15; // kr08_8
  unsigned int v16; // r1
  int v17; // r0
  __int16 v18; // r3
  int result; // r0
  int v20; // [sp+0h] [bp-28h] BYREF
  int v21; // [sp+4h] [bp-24h]
  int v22; // [sp+8h] [bp-20h]
  int vars8; // [sp+30h] [bp+8h]
  int varsC; // [sp+34h] [bp+Ch]

  varsC = a2;
  v20 = a2;
  v21 = a3;
  v22 = a4;
  LOBYTE(varsC) = a2;
  vars8 = a1;
  v6 = ((*(_DWORD *)(a1 + 100) >> 3) & 1) + *(_DWORD *)(a1 + 148);
  v21 = v6;
  if ( a2 )
  {
    if ( *(_DWORD *)(a1 + 284) && (*(_DWORD *)(a1 + 192) & 8) == 0 )
    {
      v20 = PsGetProcessSessionIdEx(a1);
      PsInvokeWin32Callout(23, a1, 1, &v20);
    }
    v20 = 0;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    v8 = (unsigned __int8 *)(a1 + 168);
    v9 = KeAbPreAcquire(a1 + 168, 0, 0);
    v10 = v9;
    do
      v11 = __ldrex(v8);
    while ( __strex(v11 | 1, v8) );
    __dmb(0xBu);
    if ( (v11 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 168), v9, a1 + 168);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    if ( *(_QWORD *)(a1 + 768) )
    {
      do
      {
        v12 = MEMORY[0xFFFF93B0];
        while ( 1 )
        {
          v13 = MEMORY[0xFFFF900C];
          __dmb(0xBu);
          v20 = MEMORY[0xFFFF9008];
          __dmb(0xBu);
          if ( v13 == MEMORY[0xFFFF9010] )
            break;
          __dmb(0xAu);
          __yield();
        }
      }
      while ( v12 != MEMORY[0xFFFF93B0] );
      v15 = __PAIR64__(v13, v20) - v12 - *(_QWORD *)(a1 + 768);
      v20 = HIDWORD(v15);
      v14 = v15;
      *(_DWORD *)(a1 + 768) = 0;
      *(_DWORD *)(a1 + 772) = 0;
      *(_QWORD *)(a1 + 840) += v15;
    }
    else
    {
      v14 = 0;
    }
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)v8);
    while ( __strex(v16 - 1, (unsigned int *)v8) );
    if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a1 + 168));
    v17 = KeAbPostRelease(a1 + 168);
    v18 = *(_WORD *)(v7 + 308) + 1;
    *(_WORD *)(v7 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
      KiCheckForKernelApcDelivery(v17);
    *(_QWORD *)PspFreezeTimeBiasAddress += __PAIR64__(v20, v14);
  }
  result = KeThawProcess(a1, a2);
  if ( a2 )
  {
    result = PsSetProcessTelemetryAppState(a1, 2);
    if ( (dword_682608 & 2) != 0 )
    {
      if ( v6 )
        result = EtwTraceFreezeThawProcess(a1, 0);
    }
  }
  return result;
}
