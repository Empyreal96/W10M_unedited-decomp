// sub_7EB3F4 
 
void __fastcall sub_7EB3F4(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x764E8E);
}
