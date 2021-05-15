// PnpSerializeBoot 
 
int PnpSerializeBoot()
{
  int result; // r0

  result = -1073741823;
  if ( PnPBootDriversInitialized )
    result = KeWaitForSingleObject((unsigned int)&PnpSystemDeviceEnumerationComplete, 0, 0, 0, 0);
  return result;
}
