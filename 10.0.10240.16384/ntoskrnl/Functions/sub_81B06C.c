// sub_81B06C 
 
void __fastcall sub_81B06C(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x7B97FA);
}
