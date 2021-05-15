// PoClearPowerRequest 
 
int __fastcall PoClearPowerRequest(int a1, int a2)
{
  int result; // r0

  if ( a2 == 1 )
    result = PoClearPowerRequestInternal(a1, 1);
  else
    result = sub_5296A4();
  return result;
}
