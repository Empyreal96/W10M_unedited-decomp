// VfZwOpenTransaction 
 
int __fastcall VfZwOpenTransaction(int a1, int a2, int a3, int a4)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckVirtualAddress(a4);
    ViZwCheckObjectAttributes(a3);
  }
  return pXdvZwOpenTransaction(a1, a2, a3, a4);
}
