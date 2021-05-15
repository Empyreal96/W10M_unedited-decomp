// IoGetBootDiskInformationLite 
 
int IoGetBootDiskInformationLite()
{
  int result; // r0

  if ( (unsigned int)InitializationPhase >= 2 )
    result = -1073741431;
  else
    result = IopGetBootDiskInformationLite();
  return result;
}
