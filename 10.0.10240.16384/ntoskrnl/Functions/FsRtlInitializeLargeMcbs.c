// FsRtlInitializeLargeMcbs 
 
int FsRtlInitializeLargeMcbs()
{
  ExInitializePagedLookasideList((int)&FsRtlFirstMappingLookasideList, 0, 0, 0, 120, 1835619142, 4);
  return ExInitializeNPagedLookasideList((int)&FsRtlFastMutexLookasideList, 0, 0, 512);
}
