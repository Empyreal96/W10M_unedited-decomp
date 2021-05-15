// FsRtlInsertPerStreamContext 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlInsertPerStreamContext(int a1, _QWORD *a2)
{
  unsigned __int8 *v4; // r7
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  unsigned int v9; // r7
  int v10; // r5
  int v11; // r9
  unsigned int v12; // r2
  _DWORD *v13; // r2 OVERLAPPED
  int v14; // r1 OVERLAPPED
  int *v15; // r4
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int *v22; // r4
  unsigned int v23; // r5
  unsigned int v24; // r1

  if ( !a1 || (*(_BYTE *)(a1 + 6) & 2) == 0 )
    return -1073741808;
  if ( (*(_BYTE *)(a1 + 7) & 0xF0u) < 0x10 )
  {
    v9 = *(_DWORD *)(a1 + 40);
    v10 = KeAbPreAcquire(v9, 0, 0);
    v11 = KfRaiseIrql(1);
    do
      v12 = __ldrex((unsigned __int8 *)v9);
    while ( __strex(v12 & 0xFE, (unsigned __int8 *)v9) );
    __dmb(0xBu);
    if ( (v12 & 1) == 0 )
      ExpAcquireFastMutexContended(v9, v10);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    *(_DWORD *)(v9 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v9 + 28) = v11;
  }
  else
  {
    v4 = (unsigned __int8 *)(a1 + 52);
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    v6 = KeAbPreAcquire(a1 + 52, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex(v4);
    while ( __strex(v8 | 1, v4) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v4, v6, (unsigned int)v4);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
  }
  v13 = (_DWORD *)(a1 + 44);
  v14 = *(_DWORD *)(a1 + 44);
  *a2 = *(_QWORD *)&v14;
  if ( *(_DWORD *)(v14 + 4) != a1 + 44 )
    __fastfail(3u);
  *(_DWORD *)(v14 + 4) = a2;
  *v13 = a2;
  if ( (*(_BYTE *)(a1 + 7) & 0xF0u) < 0x10 )
  {
    v22 = *(unsigned int **)(a1 + 40);
    v23 = v22[7];
    v22[1] = 0;
    __dmb(0xBu);
    do
      v24 = __ldrex(v22);
    while ( !v24 && __strex(1u, v22) );
    if ( v24 )
      ExpReleaseFastMutexContended(v22, v24);
    KfLowerIrql((unsigned __int8)v23);
    KeAbPostRelease((unsigned int)v22);
  }
  else
  {
    v15 = (int *)(a1 + 52);
    __pld(v15);
    v16 = *v15;
    v17 = *v15 - 16;
    if ( (*v15 & 0xFFFFFFF0) <= 0x10 )
      v17 = 0;
    if ( (v16 & 2) != 0 )
      goto LABEL_27;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v15);
    while ( v18 == v16 && __strex(v17, (unsigned int *)v15) );
    if ( v18 != v16 )
LABEL_27:
      ExfReleasePushLock(v15, v16);
    v19 = KeAbPostRelease((unsigned int)v15);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = *(_WORD *)(v20 + 0x134) + 1;
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
  }
  return 0;
}
