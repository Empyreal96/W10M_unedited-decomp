// VfZwSetBootOptions 
 
int __fastcall VfZwSetBootOptions(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a1);
  return pXdvZwSetBootOptions(a1, a2);
}
