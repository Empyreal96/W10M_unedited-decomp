// sub_6947E4 
 
void __fastcall sub_6947E4(int a1, int a2)
{
  if ( !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x691B0C);
}
