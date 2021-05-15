// IoEnableIoQos 
 
int IoEnableIoQos()
{
  int result; // r0

  result = ZwLoadDriver();
  if ( result == -1073741554 )
    result = 0;
  return result;
}
