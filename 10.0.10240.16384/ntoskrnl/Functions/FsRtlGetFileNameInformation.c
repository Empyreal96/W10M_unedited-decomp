// FsRtlGetFileNameInformation 
 
int FsRtlGetFileNameInformation()
{
  int result; // r0

  if ( FltMgrCallbacks )
    result = (*(int (**)(void))(FltMgrCallbacks + 8))();
  else
    result = -1073741637;
  return result;
}
