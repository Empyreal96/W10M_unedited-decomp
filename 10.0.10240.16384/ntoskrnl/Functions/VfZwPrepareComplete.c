// VfZwPrepareComplete 
 
int __fastcall VfZwPrepareComplete(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwPrepareComplete(a1, a2);
}
