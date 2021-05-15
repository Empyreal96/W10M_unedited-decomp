// PnpEarlyLaunchHasCallbacksRegistered 
 
BOOL PnpEarlyLaunchHasCallbacksRegistered()
{
  return PnpBootDriverCallbackObject != 0;
}
