// PopPdcCsDeviceNotification 
 
int PopPdcCsDeviceNotification()
{
  int result; // r0

  if ( PopPlatformAoAc )
    result = sub_7F104C();
  else
    result = 0;
  return result;
}
