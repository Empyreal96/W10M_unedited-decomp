// VfZwOpenKey 
 
int __fastcall VfZwOpenKey(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckObjectAttributes(a3);
  }
  return pXdvZwOpenKey(a1, a2, a3);
}
