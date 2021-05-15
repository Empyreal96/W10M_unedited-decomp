// VfZwCancelTimer 
 
int __fastcall VfZwCancelTimer(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwCancelTimer(a1, a2);
}
