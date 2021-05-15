// RawVerifyVolume 
 
int __fastcall RawVerifyVolume(int a1, int a2)
{
  int v4; // r0
  int v5; // r6
  int v6; // r5
  unsigned __int8 *v7; // r4
  int v8; // r5
  int v9; // r8
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r1

  v4 = KeAcquireQueuedSpinLock(9);
  v5 = *(_DWORD *)(a1 + 8);
  v6 = 0;
  if ( (*(_WORD *)(v5 + 4) & 1) != 0 )
  {
    ++*(_DWORD *)(v5 + 20);
    v6 = 1;
  }
  KeReleaseQueuedSpinLock(9, v4);
  if ( v6 )
  {
    ExWaitForRundownProtectionReleaseCacheAware(*(_DWORD **)(a2 + 156));
    v7 = (unsigned __int8 *)(a2 + 160);
    v8 = KeAbPreAcquire(a2 + 160, 0, 0);
    v9 = KfRaiseIrql(1);
    do
      v10 = __ldrex(v7);
    while ( __strex(v10 & 0xFE, v7) );
    __dmb(0xBu);
    if ( (v10 & 1) == 0 )
      ExpAcquireFastMutexContended(a2 + 160, v8);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    *(_DWORD *)(a2 + 164) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a2 + 188) = v9;
    v11 = KeAcquireQueuedSpinLock(9);
    --*(_DWORD *)(v5 + 20);
    KeReleaseQueuedSpinLock(9, v11);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 140) + 12) + 28) &= 0xFFFFFFFD;
    if ( !RawInitiateDeleteVolume(a2, 1, 0) )
    {
      v12 = *(_DWORD *)(a2 + 188);
      *(_DWORD *)(a2 + 164) = 0;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)v7);
      while ( !v13 && __strex(1u, (unsigned int *)v7) );
      if ( v13 )
        ExpReleaseFastMutexContended((unsigned int *)(a2 + 160), v13);
      KfLowerIrql((unsigned __int8)v12);
      KeAbPostRelease(a2 + 160);
    }
  }
  return -1073741806;
}
