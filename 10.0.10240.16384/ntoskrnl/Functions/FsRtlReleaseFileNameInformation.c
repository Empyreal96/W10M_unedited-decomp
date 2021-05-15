// FsRtlReleaseFileNameInformation 
 
int FsRtlReleaseFileNameInformation()
{
  return (*(int (**)(void))(FltMgrCallbacks + 12))();
}
