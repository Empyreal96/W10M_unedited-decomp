// PopEnableExecutionRequiredPowerRequests 
 
int PopEnableExecutionRequiredPowerRequests()
{
  int *i; // r4
  int result; // r0

  for ( i = (int *)PopPowerRequestObjectList; i != &PopPowerRequestObjectList; i = (int *)*i )
  {
    if ( i[9] )
      return sub_7EB3DC();
  }
  return result;
}
