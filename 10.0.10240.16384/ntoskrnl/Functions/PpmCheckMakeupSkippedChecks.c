// PpmCheckMakeupSkippedChecks 
 
int PpmCheckMakeupSkippedChecks()
{
  int result; // r0

  if ( PpmCheckMakeupCount )
    result = sub_540710();
  else
    result = 1;
  return result;
}
