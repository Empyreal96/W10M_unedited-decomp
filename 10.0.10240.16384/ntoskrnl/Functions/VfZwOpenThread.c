// VfZwOpenThread 
 
int __fastcall VfZwOpenThread(int a1, int a2, int a3, int a4)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckObjectAttributes(a3);
    ViZwCheckVirtualAddress(a4);
  }
  return pXdvZwOpenThread(a1, a2, a3, a4);
}
