// VfZwSetTimer 
 
int __fastcall VfZwSetTimer(int a1, int a2, int a3, int a4, unsigned __int8 a5, int a6, int a7)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a2);
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a4);
    ViZwCheckVirtualAddress(a7);
  }
  return pXdvZwSetTimer(a1, a2, a3, a4, a5, a6, a7);
}
