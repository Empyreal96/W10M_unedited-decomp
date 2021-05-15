// VfZwOpenEnlistment 
 
int __fastcall VfZwOpenEnlistment(int a1, int a2, int a3, int a4, int a5)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckObjectAttributes(a5);
  }
  return pXdvZwOpenEnlistment(a1, a2, a3, a4);
}
