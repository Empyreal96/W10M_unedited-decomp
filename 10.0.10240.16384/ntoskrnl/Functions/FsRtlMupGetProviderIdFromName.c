// FsRtlMupGetProviderIdFromName 
 
int FsRtlMupGetProviderIdFromName()
{
  int result; // r0

  if ( pFsRtlpMupCalls )
    result = (*((int (**)(void))pFsRtlpMupCalls + 1))();
  else
    result = -1073741637;
  return result;
}
