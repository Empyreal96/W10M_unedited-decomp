// PopBatteryQueryEstimatedTime 
 
int __fastcall PopBatteryQueryEstimatedTime(int *a1, int a2)
{
  int v3; // r3
  int v4; // r0
  int result; // r0
  int v6[6]; // [sp+8h] [bp-18h] BYREF

  v3 = a1[15];
  v4 = a1[7];
  v6[2] = a2;
  v6[0] = v3;
  v6[1] = 3;
  PopPrepareIoctl(v4, 2703428, 0, v6, 12, 4);
  if ( IoSynchronousCallDriver(a1[6], a1[7]) < 0 )
    result = -1;
  else
    result = v6[0];
  return result;
}
