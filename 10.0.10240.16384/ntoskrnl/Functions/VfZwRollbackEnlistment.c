// VfZwRollbackEnlistment 
 
int __fastcall VfZwRollbackEnlistment(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwRollbackEnlistment(a1, a2);
}
