// VfZwAdjustPrivilegesToken 
 
int __fastcall VfZwAdjustPrivilegesToken(int a1, int a2, int a3, int a4, int a5, int a6)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a5);
    ViZwCheckVirtualAddress(a6);
  }
  return pXdvZwAdjustPrivilegesToken(a1, a2, a3, a4);
}
