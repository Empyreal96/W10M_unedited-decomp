// PnpNotifyEarlyLaunchImageLoad 
 
int __fastcall PnpNotifyEarlyLaunchImageLoad(int a1, int a2)
{
  int result; // r0

  result = PnpEarlyLaunchHasCallbacksRegistered(a1, a2, a1);
  if ( result )
    result = sub_969044();
  return result;
}
