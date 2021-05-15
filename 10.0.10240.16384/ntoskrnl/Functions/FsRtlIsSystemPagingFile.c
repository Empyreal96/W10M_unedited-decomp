// FsRtlIsSystemPagingFile 
 
int __fastcall FsRtlIsSystemPagingFile(int a1)
{
  return MmIsFileObjectAPagingFile(a1);
}
