// VfZwSetEvent 
 
int __fastcall VfZwSetEvent(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwSetEvent(a1, a2);
}
