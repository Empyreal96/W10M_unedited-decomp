// IoGetSymlinkSupportInformation 
 
int __fastcall IoGetSymlinkSupportInformation(bool *a1, unsigned int a2)
{
  char v2; // r3

  v2 = IopSymlinkEnabledTypes;
  if ( a2 < 4 )
    return -1073741811;
  *a1 = (IopSymlinkEnabledTypes & 1) != 0;
  a1[1] = (v2 & 2) != 0;
  a1[3] = (v2 & 8) != 0;
  a1[2] = (v2 & 4) != 0;
  return 0;
}
