// SepCreateLogonSessionTrack 
 
int SepCreateLogonSessionTrack()
{
  int result; // r0

  if ( ExAllocatePoolWithTag(1, 92, 1934386515) )
    result = sub_7EA214();
  else
    result = -1073741670;
  return result;
}
