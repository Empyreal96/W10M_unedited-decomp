// MmCommitSessionMappedView 
 
int __fastcall MmCommitSessionMappedView(unsigned int a1, __int64 a2)
{
  unsigned int v4; // r7
  int v5; // r1
  unsigned int v6; // r1
  unsigned int v7; // r1
  unsigned int v8; // r4
  int v9; // r2
  int result; // r0
  int v11; // r7
  unsigned int v12; // r6
  unsigned int v13; // r9
  unsigned __int8 *v14; // r8
  int v15; // r0
  int v16; // r5
  unsigned int v17; // r2
  _DWORD *v18; // r5
  int v19; // r0
  unsigned int v20; // r0
  unsigned int *v21; // r5
  unsigned int v22; // r1
  int v23; // r0
  __int16 v24; // r3
  int v25; // r1
  unsigned int v26; // r2
  int v27; // r3
  unsigned int *v28; // r0
  unsigned int *v29; // r5
  unsigned int *v30; // r5
  unsigned int v31; // r1
  int v32; // r0
  __int16 v33; // r3
  unsigned int *v34; // r2
  unsigned int v35; // r0
  unsigned int v36; // r1
  unsigned int v37; // r3
  unsigned int v38; // r3
  int v39; // r0
  unsigned int *v40; // r5
  int v41; // r6
  unsigned int v42; // r1
  int v43; // r0
  __int16 v44; // r3
  __int64 v45; // [sp+8h] [bp-20h] BYREF

  v45 = a2;
  v4 = dword_63389C;
  if ( a1 < dword_63389C
    || *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(a1)) != 1
    && *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(a1)) != 11 )
  {
    return -1073741585;
  }
  v6 = v5 + a1;
  if ( v6 <= a1
    || v6 < v4
    || *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v6)) != 1
    && *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v7)) != 11 )
  {
    return -1073741584;
  }
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_DWORD *)(v8 + 0x74);
  if ( (*(_DWORD *)(v9 + 192) & 0x10000) == 0 )
    return -1073741799;
  v11 = *(_DWORD *)(v9 + 324);
  v12 = a1 & 0xFFFFF000;
  v13 = ((int)((((v7 - 1) >> 10) & 0x3FFFFC) - ((v12 >> 10) & 0x3FFFFC)) >> 2) + 1;
  --*(_WORD *)(v8 + 310);
  v14 = *(unsigned __int8 **)(v11 + 3204);
  v15 = KeAbPreAcquire((unsigned int)v14, 0, 0);
  v16 = v15;
  do
    v17 = __ldrex(v14);
  while ( __strex(v17 | 1, v14) );
  __dmb(0xBu);
  if ( (v17 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v14, v15, (unsigned int)v14);
  if ( v16 )
    *(_BYTE *)(v16 + 14) |= 1u;
  v18 = *(_DWORD **)(v11 + 3208);
  if ( !v18 )
    goto LABEL_61;
  do
  {
    v19 = MiSystemViewCompareVa(v12, (int)v18);
    if ( v19 >= 0 )
    {
      if ( v19 <= 0 )
        break;
      v18 = (_DWORD *)v18[1];
    }
    else
    {
      v18 = (_DWORD *)*v18;
    }
  }
  while ( v18 );
  if ( !v18 )
LABEL_61:
    KeBugCheckEx(215, v12, 2, 0, 0);
  v20 = v18[8] & 0xFFFFFFF8;
  if ( *(_DWORD *)(v20 + 32) )
  {
    v21 = *(unsigned int **)(v11 + 3204);
    __dmb(0xBu);
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 - 1, v21) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock(v21);
    v23 = KeAbPostRelease((unsigned int)v21);
    v24 = *(_WORD *)(v8 + 310) + 1;
    *(_WORD *)(v8 + 310) = v24;
    if ( !v24 && *(_DWORD *)(v8 + 100) != v8 + 100 )
      KiCheckForKernelApcDelivery(v23);
    return -1073741791;
  }
  v25 = v18[5];
  v26 = v12 - (v18[12] & 0xFFFFF000);
  v27 = v18[4];
  LODWORD(v45) = v27 + (v26 >> 12);
  HIDWORD(v45) = __CFADD__(v27, v26 >> 12) + v25;
  v28 = MiLocatePagefileSubsection((unsigned int *)(v20 + 80), (int)&v45);
  v29 = v28;
  if ( !v28 )
  {
    v30 = *(unsigned int **)(v11 + 3204);
    __dmb(0xBu);
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 - 1, v30) );
LABEL_36:
    if ( (v31 & 2) != 0 && (v31 & 4) == 0 )
      ExfTryToWakePushLock(v30);
    v32 = KeAbPostRelease((unsigned int)v30);
    v33 = *(_WORD *)(v8 + 310) + 1;
    *(_WORD *)(v8 + 310) = v33;
    if ( !v33 && *(_DWORD *)(v8 + 100) != v8 + 100 )
      KiCheckForKernelApcDelivery(v32);
    return -1073741584;
  }
  v34 = v28;
  v35 = (v45 + (unsigned __int64)v13) >> 32;
  v36 = v45 + v13;
  v37 = v29[7];
  if ( !v35 )
    goto LABEL_46;
  do
  {
    do
    {
      v38 = v34[7];
      v34 = (unsigned int *)v34[2];
      v35 = (__PAIR64__(v35, v36) - v38) >> 32;
      v36 -= v38;
      if ( !v34 )
      {
        v30 = *(unsigned int **)(v11 + 3204);
        __dmb(0xBu);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 - 1, v30) );
        goto LABEL_36;
      }
      v37 = v34[7];
    }
    while ( v35 );
LABEL_46:
    ;
  }
  while ( v36 >= v37 );
  v39 = MiChargeSegmentCommit((int **)v29, (int *)(v29[1] + 4 * v45), v13, 0);
  v40 = *(unsigned int **)(v11 + 3204);
  v41 = v39;
  __dmb(0xBu);
  do
    v42 = __ldrex(v40);
  while ( __strex(v42 - 1, v40) );
  if ( (v42 & 2) != 0 && (v42 & 4) == 0 )
    ExfTryToWakePushLock(v40);
  v43 = KeAbPostRelease((unsigned int)v40);
  v44 = *(_WORD *)(v8 + 310) + 1;
  *(_WORD *)(v8 + 310) = v44;
  if ( !v44 && *(_DWORD *)(v8 + 100) != v8 + 100 )
    KiCheckForKernelApcDelivery(v43);
  if ( v41 )
    result = 0;
  else
    result = -1073741523;
  return result;
}
