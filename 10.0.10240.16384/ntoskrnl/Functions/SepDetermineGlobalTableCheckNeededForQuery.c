// SepDetermineGlobalTableCheckNeededForQuery 
 
int SepDetermineGlobalTableCheckNeededForQuery()
{
  int result; // r0

  if ( (SepSingletonGlobal[3] & 1) != 0 )
    result = sub_7C5410();
  else
    result = 0;
  return result;
}
