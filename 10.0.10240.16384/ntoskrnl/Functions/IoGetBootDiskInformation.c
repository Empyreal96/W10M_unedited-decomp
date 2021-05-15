// IoGetBootDiskInformation 
 
int IoGetBootDiskInformation()
{
  int result; // r0

  if ( (unsigned int)InitializationPhase < 2 )
    result = IopGetBootDiskInformation();
  else
    result = -1073741431;
  return result;
}
