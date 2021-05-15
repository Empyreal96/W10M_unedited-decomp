// ObpValidateDesiredAccess 
 
int __fastcall ObpValidateDesiredAccess(int a1)
{
  int result; // r0

  if ( (a1 & 0xCE00000) != 0 )
    result = -1073741790;
  else
    result = 0;
  return result;
}
