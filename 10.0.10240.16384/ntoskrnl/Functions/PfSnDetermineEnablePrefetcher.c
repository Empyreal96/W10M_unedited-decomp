// PfSnDetermineEnablePrefetcher 
 
int PfSnDetermineEnablePrefetcher()
{
  int result; // r0

  if ( InitSafeBootMode )
    result = sub_81AED4();
  return result;
}
