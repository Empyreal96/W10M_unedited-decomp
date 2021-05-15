// VfZwQueryDefaultLocale 
 
int __fastcall VfZwQueryDefaultLocale(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwQueryDefaultLocale(a1, a2);
}
