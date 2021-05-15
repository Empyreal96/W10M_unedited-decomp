// FsRtlMupGetProviderInfoFromFileObject 
 
int FsRtlMupGetProviderInfoFromFileObject()
{
  int result; // r0

  if ( pFsRtlpMupCalls )
    result = (*(int (**)(void))pFsRtlpMupCalls)();
  else
    result = -1073741637;
  return result;
}
