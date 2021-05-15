// VfZwResetEvent 
 
int __fastcall VfZwResetEvent(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwResetEvent(a1, a2);
}
