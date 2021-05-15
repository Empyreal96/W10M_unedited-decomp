// VfZwDuplicateObject 
 
int __fastcall VfZwDuplicateObject(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a4);
  return pXdvZwDuplicateObject(a1, a2, a3, a4, a5, a6, a7);
}
