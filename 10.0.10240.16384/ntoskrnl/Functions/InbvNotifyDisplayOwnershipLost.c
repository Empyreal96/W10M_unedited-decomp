// InbvNotifyDisplayOwnershipLost 
 
int InbvNotifyDisplayOwnershipLost()
{
  int result; // r0

  if ( dword_6328F4 )
  {
    if ( *(_DWORD *)dword_6328F4 )
      result = (*(int (**)(void))dword_6328F4)();
  }
  return result;
}
