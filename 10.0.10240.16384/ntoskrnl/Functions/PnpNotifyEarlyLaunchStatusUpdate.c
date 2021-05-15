// PnpNotifyEarlyLaunchStatusUpdate 
 
int PnpNotifyEarlyLaunchStatusUpdate()
{
  int result; // r0

  result = PnpEarlyLaunchHasCallbacksRegistered();
  if ( result )
    result = sub_9689D8();
  return result;
}
