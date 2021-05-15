// MiInsertPageFileInList 
 
int __fastcall MiInsertPageFileInList(int a1)
{
  int v1; // r6
  int v2; // r10
  int v3; // r2
  int v4; // r0
  _DWORD *v5; // r1
  int v6; // r7
  unsigned int v7; // r4
  unsigned __int8 *v8; // r5
  int v9; // r0
  int v10; // r8
  unsigned int v11; // r2
  unsigned int v12; // r8
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r3
  __int16 v17; // r0
  unsigned int v18; // r1
  int v19; // r0
  int v20; // r3
  unsigned int v21; // r1
  int v22; // r0
  __int16 v23; // r3
  int v24; // [sp+8h] [bp-20h]

  v1 = a1;
  v2 = *(_DWORD *)a1;
  v3 = a1;
  v24 = *(_DWORD *)(a1 + 4);
  *(_BYTE *)(a1 + 98) |= 1u;
  v4 = 2;
  do
  {
    v5 = *(_DWORD **)(v3 + 36);
    if ( v5 )
      *v5 = -1719109871;
    v3 += 4;
    --v4;
  }
  while ( v4 );
  v6 = *(_DWORD *)(v1 + 128);
  if ( (__int16 *)v6 != MiSystemPartition )
    return sub_7BF7FC();
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 310);
  v8 = (unsigned __int8 *)(v6 + 604);
  v9 = KeAbPreAcquire(v6 + 604, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( __strex(v11 | 1, v8) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v6 + 604), v9, v6 + 604);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = *(_DWORD *)(v6 + 3596);
  __dmb(0xBu);
  if ( v12 >= 2 )
  {
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)v8);
    while ( __strex(v13 - 1, (unsigned int *)v8) );
LABEL_15:
    if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v6 + 604));
    v14 = KeAbPostRelease(v6 + 604);
    v15 = (__int16)(*(_WORD *)(v7 + 310) + 1);
    *(_WORD *)(v7 + 310) = v15;
    if ( !v15 && *(_DWORD *)(v7 + 100) != v7 + 100 )
      KiCheckForKernelApcDelivery(v14);
    return -1073741673;
  }
  v17 = *(_WORD *)(v1 + 96) & 0xFFF0 | v12 & 0xF;
  *(_WORD *)(v1 + 96) = v17;
  if ( (v17 & 0x10) != 0 || (v17 & 0x40) != 0 )
  {
    if ( (*(_WORD *)(v1 + 96) & 0x10) != 0 && MiNumberWsSwapPagefiles(v6) )
    {
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)v8);
      while ( __strex(v13 - 1, (unsigned int *)v8) );
      goto LABEL_15;
    }
    MiUpdatePageFileList(v1, 1);
    __dmb(0xBu);
    *(_DWORD *)(v6 + 4 * (v12 + 900)) = v1;
    __dmb(0xBu);
    *(_DWORD *)(v6 + 3596) = v12 + 1;
    goto LABEL_22;
  }
  if ( MiIncreaseCommitLimits((_DWORD *)v6, v2, v24, 0, v1) )
  {
    if ( (*(_WORD *)(v1 + 96) & 0x20) == 0 && !*(_DWORD *)(v6 + 600) )
    {
      __dmb(0xBu);
      *(_DWORD *)(v6 + 600) = 1;
    }
LABEL_22:
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v8);
    while ( __strex(v18 - 1, (unsigned int *)v8) );
    if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v6 + 604));
    v19 = KeAbPostRelease(v6 + 604);
    v20 = (__int16)(*(_WORD *)(v7 + 310) + 1);
    *(_WORD *)(v7 + 310) = v20;
    if ( !v20 && *(_DWORD *)(v7 + 100) != v7 + 100 )
      KiCheckForKernelApcDelivery(v19);
    MiUpdateReserveClusterInfo(v6, 0);
    KeSetEvent(v6 + 520, 0, 0);
    return 0;
  }
  __dmb(0xBu);
  do
    v21 = __ldrex((unsigned int *)v8);
  while ( __strex(v21 - 1, (unsigned int *)v8) );
  if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v6 + 604));
  v22 = KeAbPostRelease(v6 + 604);
  v23 = *(_WORD *)(v7 + 310) + 1;
  *(_WORD *)(v7 + 310) = v23;
  if ( !v23 && *(_DWORD *)(v7 + 100) != v7 + 100 )
    KiCheckForKernelApcDelivery(v22);
  return -1073741583;
}
