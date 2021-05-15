// MiExtendWorkingSetSwapPagefile 
 
int __fastcall MiExtendWorkingSetSwapPagefile(int a1, int a2, unsigned int a3)
{
  int result; // r0

  if ( MiIssuePageExtendRequest(a1, (a2 + 0x7FFF) & 0xFFFF8000, a3, 0) )
    result = 0;
  else
    result = -1073741671;
  return result;
}
