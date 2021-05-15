// sub_8199D8 
 
void __fastcall sub_8199D8(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x7B5AFC);
}
