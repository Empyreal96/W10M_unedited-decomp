// VfZwSetSystemInformation 
 
int __fastcall VfZwSetSystemInformation(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwSetSystemInformation(a1, a2, a3);
}
