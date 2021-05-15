// VfZwQueryInstallUILanguage 
 
int __fastcall VfZwQueryInstallUILanguage(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a1);
  return pXdvZwQueryInstallUILanguage(a1);
}
