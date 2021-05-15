// FsRtlTruncateMcb 
 
unsigned int __fastcall FsRtlTruncateMcb(unsigned int *a1, unsigned int a2)
{
  return FsRtlTruncateLargeMcb(a1, a2, a2, 0);
}
