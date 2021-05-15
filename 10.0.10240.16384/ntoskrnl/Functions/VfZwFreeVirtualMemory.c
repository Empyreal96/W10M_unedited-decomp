// VfZwFreeVirtualMemory 
 
int __fastcall VfZwFreeVirtualMemory(int a1, int a2, int a3, int a4)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a2);
    ViZwCheckVirtualAddress(a3);
  }
  return pXdvZwFreeVirtualMemory(a1, a2, a3, a4);
}
