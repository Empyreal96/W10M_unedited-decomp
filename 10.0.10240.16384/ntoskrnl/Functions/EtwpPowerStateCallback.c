// EtwpPowerStateCallback 
 
int __fastcall EtwpPowerStateCallback(int a1, int a2)
{
  int result; // r0

  if ( a2 == 3 )
    result = sub_81C5DC();
  return result;
}
