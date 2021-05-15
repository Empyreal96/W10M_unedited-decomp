// sub_7C5C74 
 
void __fastcall sub_7C5C74(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6C607E);
}
