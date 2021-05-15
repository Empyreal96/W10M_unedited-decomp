// VfZwPrePrepareEnlistment 
 
int __fastcall VfZwPrePrepareEnlistment(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwPrePrepareEnlistment(a1, a2);
}
