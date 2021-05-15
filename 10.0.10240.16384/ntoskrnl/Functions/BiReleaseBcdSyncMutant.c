// BiReleaseBcdSyncMutant 
 
int __fastcall BiReleaseBcdSyncMutant(int result)
{
  if ( !result )
  {
    result = BcdMutantHandle;
    if ( BcdMutantHandle != -1 )
      result = ZwReleaseMutant();
  }
  return result;
}
