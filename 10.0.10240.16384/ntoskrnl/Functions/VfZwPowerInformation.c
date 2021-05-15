// VfZwPowerInformation 
 
int __fastcall VfZwPowerInformation(int a1, int a2, int a3, int a4)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a2);
    ViZwCheckVirtualAddress(a4);
  }
  return pXdvZwPowerInformation(a1, a2, a3, a4);
}
