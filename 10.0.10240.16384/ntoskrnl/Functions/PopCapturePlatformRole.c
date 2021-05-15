// PopCapturePlatformRole 
 
int PopCapturePlatformRole()
{
  int result; // r0

  result = PopPlatformRole;
  if ( !PopPlatformRole )
    result = sub_81C414();
  return result;
}
