// SeRegisterLogonSessionTerminatedRoutine 
 
int __fastcall SeRegisterLogonSessionTerminatedRoutine(int a1)
{
  if ( !a1 )
    return -1073741811;
  if ( ExAllocatePoolWithTag(257, 8, 1397122387) )
    return sub_81C640();
  return -1073741670;
}
