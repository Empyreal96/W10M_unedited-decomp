// PiQueryRemovableDeviceOverride 
 
int PiQueryRemovableDeviceOverride()
{
  int result; // r0

  if ( PnpDeviceOverrideHashList )
    result = sub_7C96B8();
  else
    result = -1073741772;
  return result;
}
