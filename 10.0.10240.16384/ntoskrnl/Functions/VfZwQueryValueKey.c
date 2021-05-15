// VfZwQueryValueKey 
 
int __fastcall VfZwQueryValueKey(int a1, int a2, int a3, int a4, int a5, int a6)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckUnicodeString(a2);
    ViZwCheckVirtualAddress(a4);
    ViZwCheckVirtualAddress(a6);
  }
  return pXdvZwQueryValueKey(a1, a2, a3, a4);
}
