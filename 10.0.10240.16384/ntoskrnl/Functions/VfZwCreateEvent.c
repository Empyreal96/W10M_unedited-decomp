// VfZwCreateEvent 
 
int __fastcall VfZwCreateEvent(int a1, int a2, int a3, int a4)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckObjectAttributes(a3);
  }
  return pXdvZwCreateEvent(a1, a2, a3, a4);
}
