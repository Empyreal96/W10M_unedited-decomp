// VfZwQueryDriverEntryOrder 
 
int __fastcall VfZwQueryDriverEntryOrder(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckVirtualAddress(a2);
  }
  return pXdvZwQueryDriverEntryOrder(a1, a2);
}
