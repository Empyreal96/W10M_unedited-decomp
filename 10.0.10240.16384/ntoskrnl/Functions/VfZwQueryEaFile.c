// VfZwQueryEaFile 
 
int __fastcall VfZwQueryEaFile(int a1, int a2, int a3, int a4, unsigned __int8 a5, int a6, int a7, int a8, unsigned __int8 a9)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a6);
    ViZwCheckVirtualAddress(a8);
  }
  return pXdvZwQueryEaFile(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
