// FsRtlAllocateResource 
 
int FsRtlAllocateResource()
{
  int v0; // r2

  v0 = 7 * (FsRtlPagingIoResourceSelector++ & 0xF);
  return FsRtlPagingIoResources + 8 * v0;
}
