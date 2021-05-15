// VfZwQueryLicenseValue 
 
int __fastcall VfZwQueryLicenseValue(int a1, int a2, int a3, int a4, int a5)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a2);
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a5);
    ViZwCheckUnicodeString(a1);
  }
  return pXdvZwQueryLicenseValue(a1, a2, a3, a4);
}
