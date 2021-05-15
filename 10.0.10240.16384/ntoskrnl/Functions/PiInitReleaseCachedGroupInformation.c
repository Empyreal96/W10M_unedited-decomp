// PiInitReleaseCachedGroupInformation 
 
int PiInitReleaseCachedGroupInformation()
{
  int result; // r0

  result = PiInitGroupOrderTable;
  if ( PiInitGroupOrderTable )
  {
    result = PnpFreeUnicodeStringList(PiInitGroupOrderTable, (unsigned __int16)PiInitGroupOrderTableCount);
    PiInitGroupOrderTable = 0;
    PiInitGroupOrderTableCount = 0;
  }
  return result;
}
