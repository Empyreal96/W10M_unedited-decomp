// PfIoPowerEventNotify 
 
int __fastcall PfIoPowerEventNotify(int result, int a2, char a3)
{
  if ( result == 18 )
    result = PfPowerActionNotify(5, a3, 0);
  return result;
}
