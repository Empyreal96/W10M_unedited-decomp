// PspGetRateControlJobFlag 
 
int __fastcall PspGetRateControlJobFlag(int a1, int a2)
{
  int result; // r0

  if ( a1 )
  {
    if ( a2 )
      result = 0x10000000;
    else
      result = 0x8000000;
  }
  else if ( a2 )
  {
    result = 0x4000000;
  }
  else
  {
    result = 0x2000000;
  }
  return result;
}
