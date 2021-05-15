// CcClearPrivateWriteFile 
 
int __fastcall CcClearPrivateWriteFile(int a1)
{
  int v2; // r3
  int v3; // r5
  int v4; // r0
  int v5; // r2

  FsRtlAcquireFileExclusive();
  v2 = *(_DWORD *)(a1 + 20);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    if ( v3 )
    {
      v4 = KeAcquireQueuedSpinLock(5);
      v5 = *(_DWORD *)(v3 + 96);
      if ( (v5 & 0x2000) == 0 )
        return sub_523B38(v4, v4);
      *(_DWORD *)(v3 + 96) = v5 & 0xFFFFDFFD;
      KeReleaseQueuedSpinLock(5, v4);
      MmEnableModifiedWriteOfSection(*(_DWORD *)(a1 + 20));
    }
  }
  return FsRtlReleaseFile(a1);
}
