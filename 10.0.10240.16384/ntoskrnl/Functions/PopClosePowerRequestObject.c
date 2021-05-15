// PopClosePowerRequestObject 
 
int __fastcall PopClosePowerRequestObject(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a4 == 1 )
    result = PopPowerRequestCleanUp(a2, a2, a3, 1);
  return result;
}
