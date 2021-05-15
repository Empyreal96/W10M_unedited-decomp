// SeTokenFromAccessInformation 
 
int __fastcall SeTokenFromAccessInformation(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  int result; // r0

  if ( a3 < 0x298 )
  {
    result = -1073741789;
    *a4 = 664;
  }
  else
  {
    SepTokenFromAccessInformation();
    result = 0;
  }
  return result;
}
