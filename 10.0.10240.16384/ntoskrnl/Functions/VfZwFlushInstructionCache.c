// VfZwFlushInstructionCache 
 
int __fastcall VfZwFlushInstructionCache(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwFlushInstructionCache(a1, a2, a3);
}
