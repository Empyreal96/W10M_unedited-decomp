// EmProviderRegister 
 
int __fastcall EmProviderRegister(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a1 )
    result = EmpProviderRegister(a1, a2, a3, a4);
  else
    result = -1073741811;
  return result;
}
