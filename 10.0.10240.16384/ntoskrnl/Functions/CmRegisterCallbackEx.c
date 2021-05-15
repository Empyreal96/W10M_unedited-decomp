// CmRegisterCallbackEx 
 
int __fastcall CmRegisterCallbackEx(int a1, int a2, int a3, int a4, int a5, int a6)
{
  if ( !a3 )
    return -1073741583;
  if ( a6 )
    return -1073741580;
  return CmpRegisterCallbackInternal(a1, a4, a2, 0);
}
