// IoRequestDeviceEject 
 
int __fastcall IoRequestDeviceEject(int a1)
{
  return IoRequestDeviceEjectEx(a1, 0, 0, 0);
}
