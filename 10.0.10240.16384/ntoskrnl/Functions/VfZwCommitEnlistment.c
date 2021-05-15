// VfZwCommitEnlistment 
 
int __fastcall VfZwCommitEnlistment(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwCommitEnlistment(a1, a2);
}
