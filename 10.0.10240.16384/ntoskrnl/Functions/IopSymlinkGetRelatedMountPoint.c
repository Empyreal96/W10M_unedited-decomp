// IopSymlinkGetRelatedMountPoint 
 
unsigned __int16 *__fastcall IopSymlinkGetRelatedMountPoint(unsigned __int16 *result, unsigned int a2)
{
  if ( result )
  {
    if ( (result[1] & 1) != 0 && *result <= a2 )
    {
      result = (unsigned __int16 *)sub_7FA09C();
    }
    else if ( (result[1] & 1) == 0 )
    {
      result = 0;
    }
  }
  return result;
}
