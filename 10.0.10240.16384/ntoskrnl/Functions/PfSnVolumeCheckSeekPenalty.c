// PfSnVolumeCheckSeekPenalty 
 
int PfSnVolumeCheckSeekPenalty()
{
  int v0; // r5
  int v1; // r0

  v0 = 1;
  ZwResetEvent();
  v1 = ZwDeviceIoControlFile();
  if ( v1 == 259 )
    return sub_7E9698();
  if ( v1 >= 0 )
    v0 = 0;
  return v0;
}
