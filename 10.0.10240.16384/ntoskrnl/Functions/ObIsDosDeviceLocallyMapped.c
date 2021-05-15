// ObIsDosDeviceLocallyMapped 
 
int __fastcall ObIsDosDeviceLocallyMapped(int a1)
{
  int result; // r0

  if ( a1 )
    result = sub_81B674();
  else
    result = -1073741811;
  return result;
}
