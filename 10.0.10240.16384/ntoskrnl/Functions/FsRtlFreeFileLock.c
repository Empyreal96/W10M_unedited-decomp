// FsRtlFreeFileLock 
 
int __fastcall FsRtlFreeFileLock(int a1)
{
  FsRtlUninitializeFileLock();
  return ExFreeToPagedLookasideList(&FsRtlFileLockLookasideList, a1);
}
