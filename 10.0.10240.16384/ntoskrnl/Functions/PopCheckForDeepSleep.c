// PopCheckForDeepSleep 
 
int PopCheckForDeepSleep()
{
  int result; // r0

  if ( PopDeepSleepEnabled() )
    result = sub_5299B4();
  else
    result = 0;
  return result;
}
