// VfZwDuplicateToken 
 
int __fastcall VfZwDuplicateToken(int a1, int a2, int a3, int a4, int a5, int a6)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckObjectAttributes(a3);
    ViZwCheckVirtualAddress(a6);
  }
  return pXdvZwDuplicateToken(a1, a2, a3, a4);
}
