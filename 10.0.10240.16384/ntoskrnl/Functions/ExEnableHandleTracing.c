// ExEnableHandleTracing 
 
int __fastcall ExEnableHandleTracing(int a1, int a2)
{
  int v2; // r4
  int v4; // r8
  unsigned int v5; // r1
  int v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r1
  unsigned int v9; // kr00_4
  int v10; // r6
  int v11; // r7
  unsigned int v12; // r0
  _BYTE *v13; // r0
  _DWORD *v14; // r6
  int v15; // r2
  unsigned int v16; // r4
  unsigned int v17; // r7
  unsigned __int8 *v18; // r8
  int v19; // r0
  int v20; // r4
  unsigned int v21; // r2
  unsigned int *v22; // r4
  unsigned int v23; // r1
  int v24; // r0
  __int16 v25; // r3

  v2 = a2;
  if ( a2 )
  {
    if ( (unsigned int)a2 >= 0x80 )
    {
      if ( a2 < 0 || a2 > 0x20000 )
        v2 = 0x20000;
    }
    else
    {
      v2 = 128;
    }
    while ( ((v2 - 1) & v2) != 0 )
      v2 = ((v2 - 1) | v2) + 1;
  }
  else
  {
    v2 = 4096;
  }
  v4 = 80 * v2;
  __dmb(0xBu);
  do
    v5 = __ldrex(&ExpTotalTraceBuffers);
  while ( __strex(v5 + v2, &ExpTotalTraceBuffers) );
  __dmb(0xBu);
  v6 = MmGetMaximumNonPagedPoolInBytes();
  v9 = v7;
  v8 = 80 * v7;
  if ( !is_mul_ok(0x50u, v9) || v8 > (unsigned int)(5 * v6) >> 4 )
  {
    v10 = -1073741670;
LABEL_17:
    __dmb(0xBu);
    do
      v12 = __ldrex(&ExpTotalTraceBuffers);
    while ( __strex(v12 - v2, &ExpTotalTraceBuffers) );
    __dmb(0xBu);
    return v10;
  }
  v11 = *(_DWORD *)(a1 + 12);
  if ( v11 )
  {
    v10 = PsChargeProcessNonPagedPoolQuota(*(_DWORD *)(a1 + 12), v4 + 48);
    if ( v10 < 0 )
      goto LABEL_17;
  }
  v13 = (_BYTE *)ExAllocatePoolWithTag(512, v4 + 48, 1685348943);
  v14 = v13;
  if ( !v13 )
  {
    __dmb(0xBu);
    v15 = -v2;
    do
      v16 = __ldrex(&ExpTotalTraceBuffers);
    while ( __strex(v16 + v15, &ExpTotalTraceBuffers) );
    __dmb(0xBu);
    if ( v11 )
      PsReturnProcessNonPagedPoolQuota(v11, v4 + 48);
    return -1073741670;
  }
  memset(v13, 0, v4 + 48);
  *v14 = 1;
  v14[1] = v2;
  v14[3] = 1;
  v14[4] = 0;
  v14[5] = 0;
  KeInitializeEvent((int)(v14 + 6), 1, 0);
  if ( v11 )
    *(_BYTE *)(a1 + 28) |= 1u;
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v17 + 308);
  v18 = (unsigned __int8 *)(a1 + 36);
  v19 = KeAbPreAcquire(a1 + 36, 0, 0);
  v20 = v19;
  do
    v21 = __ldrex(v18);
  while ( __strex(v21 | 1, v18) );
  __dmb(0xBu);
  if ( (v21 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 36), v19, a1 + 36);
  if ( v20 )
    *(_BYTE *)(v20 + 14) |= 1u;
  v22 = *(unsigned int **)(a1 + 60);
  *(_DWORD *)(a1 + 60) = v14;
  if ( !v22 )
  {
    if ( (*(_BYTE *)(a1 + 28) & 2) == 0 )
      goto LABEL_39;
    goto LABEL_38;
  }
  if ( (v22[2] & 8) != 0 )
LABEL_38:
    v14[2] = 8;
LABEL_39:
  *(_BYTE *)(a1 + 28) |= 2u;
  __dmb(0xBu);
  do
    v23 = __ldrex((unsigned int *)v18);
  while ( __strex(v23 - 1, (unsigned int *)v18) );
  if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 36));
  v24 = KeAbPostRelease(a1 + 36);
  v25 = *(_WORD *)(v17 + 308) + 1;
  *(_WORD *)(v17 + 308) = v25;
  if ( !v25 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v24);
  if ( v22 )
    ExDereferenceHandleDebugInfo(a1, v22);
  return 0;
}
