// PfSnVolumeCheckIsSdBus 
 
int PfSnVolumeCheckIsSdBus()
{
  BOOL v0; // r5
  int v1; // r0
  char v3; // [sp+48h] [bp-18h]

  v0 = 0;
  ZwResetEvent();
  v1 = ZwDeviceIoControlFile();
  if ( v1 == 259 )
    return sub_7E98C8();
  if ( v1 >= 0 )
    v0 = v3 == 12;
  return v0;
}
