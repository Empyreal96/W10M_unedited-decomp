// VfZwOpenProcessToken 
 
int __fastcall VfZwOpenProcessToken(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a3);
  return pXdvZwOpenProcessToken(a1, a2, a3);
}
