// VfZwPulseEvent 
 
int __fastcall VfZwPulseEvent(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwPulseEvent(a1, a2);
}
