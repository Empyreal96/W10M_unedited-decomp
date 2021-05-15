// KdpSysReadBusData 
 
int __fastcall KdpSysReadBusData(int a1, int a2, int a3, int a4, int a5, int a6, int *a7)
{
  int v7; // r0
  int result; // r0

  if ( a1 == 4 )
    v7 = off_6179C0(a2, a3, a5);
  else
    v7 = HalGetBusDataByOffset(a1, a2, a3, a5);
  *a7 = v7;
  if ( v7 == a6 )
    result = 0;
  else
    result = -1073741823;
  return result;
}
