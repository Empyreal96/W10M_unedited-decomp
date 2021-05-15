// VfZwAddDriverEntry 
 
int __fastcall VfZwAddDriverEntry(int a1, int a2)
{
  if ( ViZwShouldCheck() )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckVirtualAddress(a2);
  }
  return pXdvZwAddDriverEntry(a1, a2);
}
