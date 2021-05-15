// VfZwSetBootEntryOrder 
 
int __fastcall VfZwSetBootEntryOrder(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a1);
  return pXdvZwSetBootEntryOrder(a1, a2);
}
