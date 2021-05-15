// FsRtlAcquireFileExclusive 
 
int __fastcall FsRtlAcquireFileExclusive(int a1, int a2, int a3, int a4, int a5)
{
  return FsRtlAcquireFileExclusiveCommon(a1, 0, 0, 0, a5);
}
