// CcSetPrivateWriteFile 
 
int __fastcall CcSetPrivateWriteFile(int a1)
{
  int v2; // r3
  int v3; // r6
  int v4; // r0
  int v5; // r3
  int v7; // r5
  int v8; // r0

  FsRtlAcquireFileExclusive();
  v2 = *(_DWORD *)(a1 + 20);
  if ( v2 && (v3 = *(_DWORD *)(v2 + 4)) != 0 )
  {
    CcUnmapVacbArray(v3, 0, 0, 0, 1);
    CcFlushCachePriv(*(_DWORD *)(a1 + 20), 0, 0);
    v4 = KeAcquireQueuedSpinLock(5);
    v5 = *(_DWORD *)(v3 + 96);
    if ( (v5 & 0x20) != 0 || (v5 & 0x4000) != 0 )
      return sub_529D54(v4);
    KeReleaseQueuedSpinLock(5, v4);
    v7 = MmDisableModifiedWriteOfSection(*(_DWORD *)(a1 + 20));
    if ( v7 )
    {
      v8 = KeAcquireQueuedSpinLock(5);
      *(_DWORD *)(v3 + 96) |= 0x2002u;
      KeReleaseQueuedSpinLock(5, v8);
    }
    FsRtlReleaseFile(a1);
  }
  else
  {
    FsRtlReleaseFile(a1);
    v7 = 0;
  }
  return v7;
}
