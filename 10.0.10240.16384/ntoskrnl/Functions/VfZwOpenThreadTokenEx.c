// VfZwOpenThreadTokenEx 
 
int __fastcall VfZwOpenThreadTokenEx(int a1, int a2, int a3, int a4, int a5)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a5);
  return pXdvZwOpenThreadTokenEx(a1, a2, a3, a4);
}
