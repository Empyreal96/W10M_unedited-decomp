// VfZwWaitForSingleObject 
 
int __fastcall VfZwWaitForSingleObject(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a3);
  return pXdvZwWaitForSingleObject(a1, a2, a3);
}
