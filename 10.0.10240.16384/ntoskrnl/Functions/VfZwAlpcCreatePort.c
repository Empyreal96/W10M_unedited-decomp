// VfZwAlpcCreatePort 
 
int __fastcall VfZwAlpcCreatePort(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckVirtualAddress(a3);
    ViZwCheckObjectAttributes(a2);
  }
  return pXdvZwAlpcCreatePort(a1, a2, a3);
}
