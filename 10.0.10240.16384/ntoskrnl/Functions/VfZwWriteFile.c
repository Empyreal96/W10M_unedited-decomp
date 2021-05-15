// VfZwWriteFile 
 
int __fastcall VfZwWriteFile(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a4);
    ViZwCheckVirtualAddress(a5);
    ViZwCheckVirtualAddress(a6);
    ViZwCheckVirtualAddress(a8);
    ViZwCheckVirtualAddress(a9);
    ViZwCheckApcRequirement();
  }
  return pXdvZwWriteFile(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
