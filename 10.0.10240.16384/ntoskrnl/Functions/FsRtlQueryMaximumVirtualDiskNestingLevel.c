// FsRtlQueryMaximumVirtualDiskNestingLevel 
 
int FsRtlQueryMaximumVirtualDiskNestingLevel()
{
  int result; // r0

  result = FsRtlVirtualDiskMaxTreeDepth;
  if ( FsRtlVirtualDiskMaxTreeDepth == -1 )
  {
    result = FsRtlpGetMaxVirtualDiskNestingLevel();
    FsRtlVirtualDiskMaxTreeDepth = result;
  }
  return result;
}
