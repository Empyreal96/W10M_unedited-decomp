// FsRtlIsMobileOS 
 
BOOL FsRtlIsMobileOS()
{
  return TmCurrentTransaction() == -1073741637;
}
