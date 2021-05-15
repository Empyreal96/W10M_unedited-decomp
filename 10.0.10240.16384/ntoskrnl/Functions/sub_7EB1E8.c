// sub_7EB1E8 
 
void __fastcall sub_7EB1E8(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x707D7C);
}
