// PopBatteryReadTag 
 
int __fastcall PopBatteryReadTag(int *a1)
{
  int v2; // r5

  a1[30] = 0;
  PopPrepareIoctl(a1[7], 2703424, 0, (int)(a1 + 30), 4, 4);
  v2 = IoSynchronousCallDriver(a1[6], a1[7]);
  if ( v2 >= 0 )
  {
    v2 = 0;
    a1[15] = a1[30];
    a1[14] = 1;
    KeSetEvent((int)(a1 + 10), 0, 0);
  }
  return v2;
}
