// IoSetDeviceInterfacePropertyData 
 
int __fastcall IoSetDeviceInterfacePropertyData(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int result; // r0

  if ( a7 )
    result = PnpSetDeviceInterfacePropertyData();
  else
    result = sub_815AC0();
  return result;
}
