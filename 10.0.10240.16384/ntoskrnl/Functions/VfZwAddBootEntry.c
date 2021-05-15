// VfZwAddBootEntry 
 
int __fastcall VfZwAddBootEntry(int a1, int a2)
{
  if ( ViZwShouldCheck() )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckVirtualAddress(a2);
  }
  return pXdvZwAddBootEntry(a1, a2);
}
