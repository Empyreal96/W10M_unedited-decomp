// sub_7E9D40 
 
void __fastcall sub_7E9D40(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x703F1C);
}
