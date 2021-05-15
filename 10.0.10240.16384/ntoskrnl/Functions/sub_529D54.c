// sub_529D54 
 
void __fastcall sub_529D54(int a1)
{
  int v1; // r4
  int v2; // r0

  KeReleaseQueuedSpinLock(5, a1);
  v2 = FsRtlReleaseFile(v1);
  CcWaitForCurrentLazyWriterActivity(v2);
  FsRtlAcquireFileExclusive(v1);
  JUMPOUT(0x46834A);
}
