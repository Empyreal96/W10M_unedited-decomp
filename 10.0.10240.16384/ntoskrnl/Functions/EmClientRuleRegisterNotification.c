// EmClientRuleRegisterNotification 
 
int __fastcall EmClientRuleRegisterNotification(int a1)
{
  int result; // r0

  if ( a1 )
    result = EmpClientRuleRegisterNotification();
  else
    result = -1073741811;
  return result;
}
