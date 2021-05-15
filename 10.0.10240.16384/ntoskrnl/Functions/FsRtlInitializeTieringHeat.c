// FsRtlInitializeTieringHeat 
 
int FsRtlInitializeTieringHeat()
{
  FsRtlTieringHeatData = (int)&FsRtlTieringHeatData;
  *(_DWORD *)algn_631E04 = &FsRtlTieringHeatData;
  return ExInitializeResourceLite((int)&algn_631E04[4]);
}
