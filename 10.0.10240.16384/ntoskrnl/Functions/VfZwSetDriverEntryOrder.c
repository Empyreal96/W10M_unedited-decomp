// VfZwSetDriverEntryOrder 
 
int __fastcall VfZwSetDriverEntryOrder(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a1);
  return pXdvZwSetDriverEntryOrder(a1, a2);
}
