// VfZwAlpcCreateSecurityContext 
 
int __fastcall VfZwAlpcCreateSecurityContext(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a3);
  return pXdvZwAlpcCreateSecurityContext(a1, a2, a3);
}
