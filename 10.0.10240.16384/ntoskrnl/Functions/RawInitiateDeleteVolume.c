// RawInitiateDeleteVolume 
 
int __fastcall RawInitiateDeleteVolume(int a1, int a2, int a3)
{
  int v6; // r8
  int v7; // r0
  int v8; // r5
  int v10; // r1
  int v11; // r6
  int v12; // r8
  unsigned int v13; // r2
  __int64 v14; // r0
  unsigned __int8 v15; // r6
  unsigned int v16; // r1
  unsigned int *v17; // r5
  int v18; // r6
  unsigned int v19; // r1
  int v20; // r2
  int v21; // r6
  int v22; // r9
  unsigned int v23; // r2
  int *v24; // r2
  __int64 v25; // r0
  int **v26; // r0
  unsigned __int8 v27; // r4
  unsigned int v28; // r1
  int v29; // r1
  int v30; // r6
  int v31; // r8
  unsigned int v32; // r2
  __int64 v33; // r0
  unsigned __int8 v34; // r6
  unsigned int v35; // r1

  v6 = 0;
  if ( (*(_DWORD *)(a1 + 72) & 4) == 0 )
  {
    v7 = KeAcquireQueuedSpinLock(9);
    v8 = v7;
    if ( !a2 && *(_DWORD *)(a1 + 76) + *(_DWORD *)(*(_DWORD *)(a1 + 140) + 20) != a3 )
      return sub_519534();
    v10 = *(_DWORD *)(a1 + 140);
    if ( *(_DWORD *)(a1 + 80) + *(_DWORD *)(v10 + 20) )
    {
      memset(*(_BYTE **)(a1 + 144), 0, 88);
      **(_WORD **)(a1 + 144) = 10;
      *(_WORD *)(*(_DWORD *)(a1 + 144) + 2) = 88;
      *(_DWORD *)(*(_DWORD *)(a1 + 144) + 12) = *(_DWORD *)(*(_DWORD *)(a1 + 140) + 12);
      *(_DWORD *)(*(_DWORD *)(a1 + 144) + 8) = 0;
      *(_WORD *)(*(_DWORD *)(a1 + 144) + 4) = *(_WORD *)(*(_DWORD *)(a1 + 140) + 4) & 8;
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 140) + 12) + 36) = *(_DWORD *)(a1 + 144);
      v20 = *(_DWORD *)(a1 + 140);
      *(_DWORD *)(a1 + 144) = 0;
      *(_WORD *)(v20 + 4) |= 4u;
      *(_DWORD *)(a1 + 72) |= 8u;
      KeReleaseQueuedSpinLock(9, v8);
      v21 = KeAbPreAcquire((unsigned int)&RawGlobalLock, 0, 0);
      v22 = KfRaiseIrql(1);
      do
        v23 = __ldrex((unsigned __int8 *)&RawGlobalLock);
      while ( __strex(v23 & 0xFE, (unsigned __int8 *)&RawGlobalLock) );
      __dmb(0xBu);
      if ( (v23 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&RawGlobalLock, v21);
      if ( v21 )
        *(_BYTE *)(v21 + 14) |= 1u;
      dword_61D964 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v24 = (int *)(a1 + 128);
      dword_61D97C = v22;
      v25 = *(_QWORD *)(a1 + 128);
      if ( *(_DWORD *)(v25 + 4) != a1 + 128 || *(int **)HIDWORD(v25) != v24 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v25) = v25;
      *(_DWORD *)(v25 + 4) = HIDWORD(v25);
      *(_DWORD *)(a1 + 72) |= 6u;
      v26 = (int **)dword_61D98C;
      *v24 = (int)&RawDismountedQueue;
      *(_DWORD *)(a1 + 132) = v26;
      if ( *v26 != &RawDismountedQueue )
        __fastfail(3u);
      *v26 = v24;
      dword_61D964 = 0;
      v27 = dword_61D97C;
      dword_61D98C = (int)v24;
      __dmb(0xBu);
      do
        v28 = __ldrex((unsigned int *)&RawGlobalLock);
      while ( !v28 && __strex(1u, (unsigned int *)&RawGlobalLock) );
      if ( v28 )
        ExpReleaseFastMutexContended((unsigned int *)&RawGlobalLock, v28);
      KfLowerIrql(v27);
      KeAbPostRelease((unsigned int)&RawGlobalLock);
      return v6;
    }
    *(_WORD *)(v10 + 4) &= 0xFFFEu;
    *(_DWORD *)(*(_DWORD *)(a1 + 140) + 8) = 0;
    KeReleaseQueuedSpinLock(9, v7);
    v11 = KeAbPreAcquire((unsigned int)&RawGlobalLock, 0, 0);
    v12 = KfRaiseIrql(1);
    do
      v13 = __ldrex((unsigned __int8 *)&RawGlobalLock);
    while ( __strex(v13 & 0xFE, (unsigned __int8 *)&RawGlobalLock) );
    __dmb(0xBu);
    if ( (v13 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&RawGlobalLock, v11);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    dword_61D964 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_61D97C = v12;
    v14 = *(_QWORD *)(a1 + 128);
    if ( *(_DWORD *)(v14 + 4) != a1 + 128 || *(_DWORD *)HIDWORD(v14) != a1 + 128 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v14) = v14;
    *(_DWORD *)(v14 + 4) = HIDWORD(v14);
    dword_61D964 = 0;
    v15 = dword_61D97C;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&RawGlobalLock);
    while ( !v16 && __strex(1u, (unsigned int *)&RawGlobalLock) );
    if ( v16 )
      ExpReleaseFastMutexContended((unsigned int *)&RawGlobalLock, v16);
    KfLowerIrql(v15);
    KeAbPostRelease((unsigned int)&RawGlobalLock);
    v17 = (unsigned int *)(a1 + 160);
    *(_DWORD *)(a1 + 72) |= 2u;
    v18 = *(_DWORD *)(a1 + 188);
    *(_DWORD *)(a1 + 164) = 0;
    __dmb(0xBu);
    do
      v19 = __ldrex(v17);
    while ( !v19 && __strex(1u, v17) );
    goto LABEL_22;
  }
  if ( !*(_DWORD *)(a1 + 80) )
  {
    v29 = KeAcquireQueuedSpinLock(9);
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 140) + 20) )
      JUMPOUT(0x519536);
    KeReleaseQueuedSpinLock(9, v29);
    v30 = KeAbPreAcquire((unsigned int)&RawGlobalLock, 0, 0);
    v31 = KfRaiseIrql(1);
    do
      v32 = __ldrex((unsigned __int8 *)&RawGlobalLock);
    while ( __strex(v32 & 0xFE, (unsigned __int8 *)&RawGlobalLock) );
    __dmb(0xBu);
    if ( (v32 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&RawGlobalLock, v30);
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    dword_61D964 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_61D97C = v31;
    v33 = *(_QWORD *)(a1 + 128);
    if ( *(_DWORD *)(v33 + 4) != a1 + 128 || *(_DWORD *)HIDWORD(v33) != a1 + 128 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v33) = v33;
    *(_DWORD *)(v33 + 4) = HIDWORD(v33);
    dword_61D964 = 0;
    v34 = dword_61D97C;
    __dmb(0xBu);
    do
      v35 = __ldrex((unsigned int *)&RawGlobalLock);
    while ( !v35 && __strex(1u, (unsigned int *)&RawGlobalLock) );
    if ( v35 )
      ExpReleaseFastMutexContended((unsigned int *)&RawGlobalLock, v35);
    KfLowerIrql(v34);
    KeAbPostRelease((unsigned int)&RawGlobalLock);
    v17 = (unsigned int *)(a1 + 160);
    v18 = *(_DWORD *)(a1 + 188);
    *(_DWORD *)(a1 + 164) = 0;
    __dmb(0xBu);
    do
      v19 = __ldrex(v17);
    while ( !v19 && __strex(1u, v17) );
LABEL_22:
    if ( v19 )
      ExpReleaseFastMutexContended(v17, v19);
    KfLowerIrql((unsigned __int8)v18);
    KeAbPostRelease((unsigned int)v17);
    RawCleanupVcb(a1);
    RawDeleteVcb(a1);
    v6 = 1;
  }
  return v6;
}
