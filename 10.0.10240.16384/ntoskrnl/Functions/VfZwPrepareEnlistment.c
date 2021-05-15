// VfZwPrepareEnlistment 
 
int __fastcall VfZwPrepareEnlistment(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwPrepareEnlistment(a1, a2);
}
