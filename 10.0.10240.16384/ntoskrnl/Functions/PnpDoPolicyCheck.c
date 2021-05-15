// PnpDoPolicyCheck 
 
int __fastcall PnpDoPolicyCheck(int a1, int a2)
{
  int result; // r0

  if ( PnpEarlyLaunchHasCallbacksRegistered(a1, a2, a1) )
    result = sub_969070();
  else
    result = 1;
  return result;
}
