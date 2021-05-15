// RawCheckForDeleteVolume 
 
int __fastcall RawCheckForDeleteVolume(int a1)
{
  int v2; // r5
  int v3; // r1
  __int64 v4; // r0
  unsigned int *v5; // r5
  int v6; // r6
  unsigned int v7; // r1

  v2 = 0;
  if ( !*(_DWORD *)(a1 + 80) )
  {
    v3 = KeAcquireQueuedSpinLock(9);
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 140) + 20) )
    {
      KeReleaseQueuedSpinLock(9, v3);
    }
    else
    {
      KeReleaseQueuedSpinLock(9, v3);
      v4 = *(_QWORD *)(a1 + 128);
      if ( *(_DWORD *)(v4 + 4) != a1 + 128 || *(_DWORD *)HIDWORD(v4) != a1 + 128 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v4) = v4;
      v5 = (unsigned int *)(a1 + 160);
      *(_DWORD *)(v4 + 4) = HIDWORD(v4);
      v6 = *(_DWORD *)(a1 + 188);
      *(_DWORD *)(a1 + 164) = 0;
      __dmb(0xBu);
      do
        v7 = __ldrex(v5);
      while ( !v7 && __strex(1u, v5) );
      if ( v7 )
        ExpReleaseFastMutexContended((unsigned int *)(a1 + 160), v7);
      KfLowerIrql((unsigned __int8)v6);
      KeAbPostRelease(a1 + 160);
      RawCleanupVcb(a1);
      RawDeleteVcb(a1);
      v2 = 1;
    }
  }
  return v2;
}
