// VfIsVerificationEnabled 
 
int VfIsVerificationEnabled()
{
  int result; // r0

  if ( ViDdiInitialized )
    result = sub_555CA8();
  else
    result = 0;
  return result;
}
